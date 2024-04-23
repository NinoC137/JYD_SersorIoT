#include <Arduino.h>
#include "FreeRTOS.h"
#include "WiFi_BLE.h"
#include "GUI_Driver.h"
#include "ModbusTask.h"

char serial1_Buffer[256];

void IoTTaskThread(void *argument);
TaskHandle_t IoTTaskHandle;

void GUITaskThread(void *argument);
TaskHandle_t GUITaskHandle;

void ModBusThread(void *argument);
TaskHandle_t ModBusHandle;

void systemTicksThread(void *argument);
TaskHandle_t systemTicksHandle;

static void SystemData_GUI();

void setup()
{
  Serial.begin(115200);

  pinMode(10, INPUT_PULLUP);  //BLE开关
  pinMode(6, INPUT_PULLUP);   //屏幕切换开关

  GUI_setup();
  
  xTaskCreatePinnedToCore(IoTTaskThread, "IoTTask", 1024*6, NULL, 2, &IoTTaskHandle, 1);

  xTaskCreatePinnedToCore(ModBusThread, "ModBusTask", 1024*4, NULL, 2, &ModBusHandle, 0);

  xTaskCreatePinnedToCore(GUITaskThread, "GUITask", 4096, NULL, 1, &GUITaskHandle, 0);

  // xTaskCreatePinnedToCore(systemTicksThread, "TicksTask", 1024, NULL, 2, &systemTicksHandle, 0);
}

uint8_t parseState = 0, states = 0;
void ModBusThread(void *argument){
  Modbus_Init();
  Modbus_configSingleRegister(163, 3);  //配置波特率为9600(默认配置)
  for(;;){
    switch(states){
      case 0: Modbus_getRegisterValue(0, 119); parseState = 0; states = 1; break;  //读0~119寄存器 
      case 1: Modbus_getRegisterValue(120, 38); parseState = 1; states = 2; break;  //读120~157寄存器
      case 2: Modbus_getRegisterValue(161, 57); parseState = 2; states = 0; break; //读161~217寄存器 
      default: states = 0; break;
    }
    vTaskDelay(270);
  } 
}

void GUITaskThread(void *argument){
  uint8_t screenFreshCounter = 0;
  for(;;){
    screenFreshCounter++;
    if(screenFreshCounter >= 30){
      GUI_sysInfoUpdate();
    }
    lv_timer_handler();
    vTaskDelay(3);
  }
}

void IoTTaskThread(void *argument){
  const TickType_t xDelay = 50 / portTICK_PERIOD_MS;

  std::stringstream urlStream;
  uint8_t updateCounter;
  urlStream << "http://" << WiFi_Data.serverip << ":" << WiFi_Data.serverport << "/cmd/connect";
  Serial.printf("Try to connect %s\r\n", urlStream.str().c_str());

  WiFi_BLE_setUp();
  configTime(gmtOffset_sec, 0, "pool.ntp.org");

  for(;;){
    BLEHandler();
    if(ProjectData.wifistatus == 0){
      WiFiHandler();
    }

    ProjectDataUpdate();

    vTaskDelay(xDelay);
  }
}

void SystemData_GUI(){
  // GUI_sysPrint(0, 16, "                                                      ");
  // GUI_sysPrint(0, 16, "WiFi Status: %s", WiFiStatus_str[ProjectData.wifistatus]);
  // GUI_sysPrint(0, 32, "                                                      ");
  // GUI_sysPrint(0, 32, "ipv4 address: %s", WiFi.localIP().toString().c_str());
  // GUI_sysPrint(0, 102, "%04d-%02d-%02d %02d:%02d:%02d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
  //               timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  GUI_sysPrint(0, 128, "last update date: %s", __DATE__);
}

static void keyValueRead(uint8_t* BLE_key, uint8_t* screen_key){
  *BLE_key = (uint8_t)digitalRead(10);
  *screen_key = (uint8_t)digitalRead(6);
}

uint8_t dataLogMode = 0;
extern BLEServer *pServer;
extern BLEService *pService;
void loop()
{
  const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
  uint8_t BLE_key, screen_key;
  keyValueRead(&BLE_key, &screen_key);

  if(dataLogMode == 1){
    Serial.printf("---------------JYD Original Data-----------------\r\n");

    Serial.printf("x_speed: %u\n", JYD_OriginalData.x_speed);
    Serial.printf("x_acc: %u\n", JYD_OriginalData.x_acc);
    Serial.printf("z_speed: %u\n", JYD_OriginalData.z_speed);
    Serial.printf("temp: %d\n", JYD_OriginalData.temp);
    // 中间省略部分
    Serial.printf("xSpeed_point_1: %u\n", JYD_OriginalData.xSpeed_point_1);
    Serial.printf("xSpeed_point_2: %u\n", JYD_OriginalData.xSpeed_point_2);
    // 中间省略部分
    Serial.printf("xSpeed_paddle_eigenvalue_1: %u\n", JYD_OriginalData.xSpeed_paddle_eigenvalue_1);
    Serial.printf("xSpeed_paddle_eigenvalue_2: %u\n", JYD_OriginalData.xSpeed_paddle_eigenvalue_2);
    // 中间省略部分
    Serial.printf("xAcc_point_1: %u\n", JYD_OriginalData.xAcc_point_1);
    Serial.printf("xAcc_point_2: %u\n", JYD_OriginalData.xAcc_point_2);
    // 中间省略部分
    Serial.printf("yAcc_inside_eigenvalue: %u\n", JYD_OriginalData.yAcc_inside_eigenvalue);
    Serial.printf("yAcc_outside_eigenvalue: %u\n", JYD_OriginalData.yAcc_outside_eigenvalue);
    // 中间省略部分
    Serial.printf("ySpeed_channalID: %u\n", JYD_OriginalData.ySpeed_channalID);
    Serial.printf("ySpeed_rotate_speed: %u\n", JYD_OriginalData.ySpeed_rotate_speed);
    // 中间省略部分
    Serial.printf("ySpeed_band_8: %u\n", JYD_OriginalData.ySpeed_band_8);
    Serial.printf("ySpeed_maxpower_order: %u\n", JYD_OriginalData.ySpeed_maxpower_order);
    Serial.printf("ySpeed_total_power: %u\n", JYD_OriginalData.ySpeed_total_power);
    // 中间省略部分
    Serial.printf("yAcc_point_1: %u\n", JYD_OriginalData.yAcc_point_1);
    Serial.printf("yAcc_point_2: %u\n", JYD_OriginalData.yAcc_point_2);
    // 中间省略部分
    Serial.printf("zSpeed_point_1: %u\n", JYD_OriginalData.zSpeed_point_1);
    Serial.printf("zSpeed_point_2: %u\n", JYD_OriginalData.zSpeed_point_2);
    // 中间省略部分
    Serial.printf("zAcc_point_1: %u\n", JYD_OriginalData.zAcc_point_1);
    Serial.printf("zAcc_point_2: %u\n", JYD_OriginalData.zAcc_point_2);
    // 中间省略部分
    Serial.printf("hpf_limit: %u\n", JYD_OriginalData.hpf_limit);
    Serial.printf("lpf_limit: %u\n", JYD_OriginalData.lpf_limit);
    Serial.printf("calcPeriod: %u\n", JYD_OriginalData.calcPeriod);

    Serial.printf("-----------------------------------------\r\n");
  }

  if(WiFi.status() != WL_CONNECTED){
    WiFi.begin(WiFi_Data.WiFi_store[0].SSID, WiFi_Data.WiFi_store[0].PassWord);
  }else{
    WiFi_Data.WiFi_store[0].ipv4 = WiFi.localIP();
  }

  ProjectData.freeHeap = ESP.getFreeHeap(); 
  ProjectData.heapUsage = ((float)ProjectData.freeHeap / (float)ESP.getHeapSize()) * 100.0f;
  ProjectData.WiFi_dB = (float)WiFi.RSSI() * 100;

  vTaskDelay(xDelay);
}

void systemTicksThread(void *argument){
  const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
  ProjectDataUpdate();
  vTaskDelay(xDelay);
}