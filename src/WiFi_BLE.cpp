#include "WiFi_BLE.h"
#include "cmd_Parse.h"
#include "wifiFix.h"
#include "GUI_Driver.h"
WiFiClient* wifi = new WiFiClientFixed();

char WiFiStatus_str[2][30] = {
    "WiFi_Connect",
    "WiFi_notConnect"};

WiFiClient client; // ESP32设置为客户端, TCP连接服务器
const IPAddress serverIP(192, 168, 1, 1);
uint16_t serverPort = 8888;

String readTCP;

BLEUUID ServiceUUID("ab1ad444-6724-11e9-a923-1681be663d3e");                                                                                         // 服务的UUID
BLECharacteristic RX_Characteristics("ab1ad980-6724-11e9-a923-1681be663d3e", BLECharacteristic::PROPERTY_WRITE);                                     // 接收字符串的特征值
BLEDescriptor RX_Descriptor(BLEUUID((uint16_t)0x2901));                                                                                              // 接收字符串描述符
BLECharacteristic TX_Characteristics("ab1adb06-6724-11e9-a923-1681be663d3e", BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY); // 发送字符串的特征值
BLEDescriptor TX_Descriptor(BLEUUID((uint16_t)0x2902));                                                                                              // 发送字符串描述符

std::string value;
char *BLE_json_root;
char *WiFi_json_root;
int cJsonParseEnd;
int CRC_CHECKED = 0;

// WiFi信息存储对象, 存储3个WiFi信息
WiFiData WiFi_Data;
// HTTP访问域名对象
HTTPClient http;
// 心跳包对象,存储心跳包在线时间与发送计数
HeartBeatPacket HeartBeat;
// 事件日志包, 存储各类信息
ProjectDataPacket ProjectData;
// CRC+MD5校验信息
//  char md5CRC[32] = {0};
//  MD5Builder md5Check;

//-----------网络时间获取-----------//
const char *ntpServer = "pool.ntp.org"; // 网络时间服务器
// 时区设置函数，东八区（UTC/GMT+8:00）写成8*3600
int my_timezone = 8;
long gmtOffset_sec = my_timezone * 3600;
const int daylightOffset_sec = 0; // 夏令时填写3600，否则填0
struct tm timeinfo;

void MyServerCallbacks::onConnect(BLEServer *pServer) // 开始连接函数
{
    ProjectData.blestatus = true;
}
void MyServerCallbacks::onDisconnect(BLEServer *pServer) // 断开连接函数
{
    ProjectData.blestatus = false;
    pServer->getAdvertising()->start();
}
void MyCallbacks::onWrite(BLECharacteristic *pCharacteristic) // 写方法
{
    value = pCharacteristic->getValue(); // 接收值
    if (value.empty())
    {
    }
}

void WiFi_BLE_setUp()
{
    WiFi_Data.WiFi_store[0].SSID = (char *)STA_SSID;
    WiFi_Data.WiFi_store[0].PassWord = (char *)STA_PASS;

    vTaskDelay(1000);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WiFi_Data.WiFi_store[0].SSID, WiFi_Data.WiFi_store[0].PassWord);

    static int counter;
    while (WiFi.status() != WL_CONNECTED && counter < 5)
    {
        vTaskDelay(100);
        WiFi.begin(WiFi_Data.WiFi_store[0].SSID, WiFi_Data.WiFi_store[0].PassWord);
        counter++;
    }

    WiFi_Data.WiFi_store[0].ipv4 = WiFi.localIP();
    WiFi_Data.WiFi_store[0].MacAddress = WiFi.macAddress().c_str();
    WiFi_Data.WiFi_store[0].devID = WiFi_Data.WiFi_store[0].MacAddress;

    size_t pos = WiFi_Data.WiFi_store[0].devID.find(":");
    while (pos != std::string::npos)
    {
        WiFi_Data.WiFi_store[0].devID.erase(pos, 1);
        pos = WiFi_Data.WiFi_store[0].devID.find(":");
        static int counter;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        ProjectData.wifistatus = 0;
    }
    else
    {
        ProjectData.wifistatus = 1;
    }

    // 生成初始CRC值
    //  sprintf(md5CRC, "%ssecret", WiFi_Data.WiFi_store[0].devID);
    //  md5Check.begin();
    //  md5Check.add((uint8_t *)md5CRC, strlen(md5CRC));
    //  md5Check.calculate();
    //  char key_crc[64] = {0};
    //  md5Check.getChars(key_crc);
    //  ProjectData.old_CRC = std::string(key_crc);
    // ProjectData.old_CRC = "123456";

    Serial.print("IPv4 address:");
    Serial.println(WiFi.localIP());
    Serial.print("Mac:");
    Serial.printf("%s\r\n", WiFi_Data.WiFi_store[0].MacAddress.c_str());
    Serial.print("devID:");
    Serial.printf("%s\r\n", WiFi_Data.WiFi_store[0].devID.c_str());

    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    BLEDevice::init(bleServer);                     // 初始化BLE客户端设备
    BLEServer *pServer = BLEDevice::createServer(); // BLEServer指针，创建Server
    BLEDevice::setMTU(256);
    BLEService *pService = pServer->createService(ServiceUUID); // BLEService指针，创建Service

    pServer->setCallbacks(new MyServerCallbacks()); // 设置连接和断开调用类

    pService->addCharacteristic(&RX_Characteristics);
    RX_Descriptor.setValue("BLE Recieve Handle");
    RX_Characteristics.addDescriptor(new BLE2902());

    pService->addCharacteristic(&TX_Characteristics);
    TX_Descriptor.setValue("BLE Transmit Handle");
    TX_Characteristics.addDescriptor(new BLE2902());

    RX_Characteristics.setCallbacks(new MyCallbacks()); // 设置回调函数
    TX_Characteristics.setCallbacks(new MyCallbacks()); // 设置回调函数

    RX_Characteristics.setValue("BLE Recieve init");  // 发送信息
    TX_Characteristics.setValue("BLE Transmit init"); // 发送信息

    pService->start();
    pServer->getAdvertising()->start();
}

void BLEHandler()
{
    // 蓝牙信息处理部分  --  注意手机发送端的MTU应设置为256(反正不要是默认的23字节,json包发不过去也读不回来)
    if (value.length() > 0)
    {
        BLE_json_root = (char *)value.data();
        // Serial.printf("json string: %s\r\n value: %s\r\n", json_string, value.c_str());
        cJSON *root = cJSON_Parse(BLE_json_root);
        if (root == NULL)
        {
            Serial.printf("Error before: [%s]\n", cJSON_GetErrorPtr());
        }
        cJSON *cmd = cJSON_GetObjectItem(root, "cmd");

        switch (cmd->valueint)
        {
            case 1: ble_cmd1(root); break;
            case 2: ble_cmd2(root); break;
            case 3: ble_cmd3(root); break;
            case 4: ble_cmd4(root); break;
            case 5: ble_cmd5(root); break;
            case 6: ble_cmd6(root); break;
            case 7: ble_cmd7(root); break;
            case 8: ble_cmd8(root); break;
            case 9: ble_cmd9(root); break;
            case 10: ble_cmd10(root); break;
            case 11: ble_cmd11(root); break;
            case 12: ble_cmd12(root); break;
            case 13: ble_cmd13(root); break;
            case 14: ble_cmd14(root); break;
            case 15: ble_cmd15(root); break;
            case 16: ble_cmd16(root); break;
            case 17: ble_cmd17(root); break;
            case 18: ble_cmd18(root); break;
            case 19: ble_cmd19(root); break;
            case 20: ble_cmd20(root); break;
            case 21: ble_cmd21(root); break;
            case 22: ble_cmd22(root); break;
        default:
            Serial.printf("error cmd!\r\n");
            TX_Characteristics.setValue("received cmd: ERROR!");
            TX_Characteristics.notify();
            break;
        }
        cJSON_Delete(root);
        value.clear();
    }
}

void WiFiHandler()
{
    std::stringstream urlStream;
    urlStream << "http://" << WiFi_Data.serverip << ":" << WiFi_Data.serverport << "/cmd/connect";
    // Serial.printf("Try to connect %s\r\n", urlStream.str().c_str());
    http.begin(*wifi, urlStream.str().c_str()); // 连接服务器对应域名
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.GET();
    if (httpCode > 0)
    {
        if (httpCode == HTTP_CODE_OK) // HTTP请求无异常
        {
            String *payload = new String(1024);
            *payload = http.getString();
            Serial.printf("get %s\r\n", payload->c_str());
            WiFi_json_root = (char *)payload->c_str(); // 读取get到的json串
            
            cJSON *root = cJSON_Parse(WiFi_json_root);
            if (root == NULL)
            {
                Serial.printf("Error before: [%s]\n", cJSON_GetErrorPtr());
            }
            cJSON *cmd = cJSON_GetObjectItem(root, "cmd");

            switch (cmd->valueint)
            {
            case 1:
                cmd1(root);
                break;
            default:
                Serial.printf("error cmd!\r\n");
                std::string post_Payload("something error.");
                http.POST(post_Payload.c_str());
                break;
            }

            cJSON_Delete(root);
            delete (payload);
        }
        else
        {
            Serial.printf("http Error.\r\n");
        }
    }
    http.end();
}

void ProjectDataUpdate()
{
    HeartBeatUpdate();
    updateLocalTime();
    static int cnt_dataupdate;

    Serial.printf("Dev IPv4:%s\r\n", WiFi.localIP().toString().c_str());
    if(WiFi.status() == WL_CONNECTED){
       ProjectData.wifistatus = 0; 
    }else{
       ProjectData.wifistatus = 1; 
    }

    if (ProjectData.runTime >= ProjectData.worktime)
    {
        ProjectData.switchStatus = 0;
    }

    if (ProjectData.switchStatus == 1)
    {
        cnt_dataupdate++;
        if (cnt_dataupdate >= 200) // 延时5ms的话, 计数200次为+1秒
        {
            ProjectData.runTime += 1;
            cnt_dataupdate = 0;
        }
    }
}

void HeartBeatUpdate()
{
    static int cnt_heartbeat;
    char heartbeat_str[20];
    if (HeartBeat.keepAliveTime != 0)
    {
        cnt_heartbeat++;
        if (cnt_heartbeat >= HeartBeat.keepAliveTime * 200) // 5ms cnt+1 所以keepAliveTime * 200放缩后对应毫秒级的单位
        {
            HeartBeat.keepLiveCnt++;

            cnt_heartbeat = 0;
        }
    }
}

void updateLocalTime()
{
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    if (!getLocalTime(&timeinfo))
    {
        ProjectData.time = std::string("Failed to obtain time");
        return;
    }
    else
    {
        char time_str[64];
        sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
                timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
        ProjectData.time = std::string(time_str);
    }
}