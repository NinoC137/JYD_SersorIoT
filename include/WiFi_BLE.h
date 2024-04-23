#ifndef _WIFI_BLE_H
#define _WIFI_BLE_H

#define DEBUG 1

#include <sstream>

#include "WiFi.h"
#include "HTTPClient.h"

#include "cJSON.h"
// #include "MD5Builder.h"

#include <BLEDevice.h>
#include <BLE2902.h>

#define bleServer "JYD_SensorIoT"
#define STA_SSID "GDUT-HUAWEI"
#define STA_PASS "AlwaysBe1@"

typedef enum {
  cmd0,
  cmd1,
  cmd2,
  cmd3,
  cmd4,
  cmd5,
  cmd6,
  cmd7,
  cmd8,
  cmd9,
  cmd10,
  cmd11,
  cmd12,
  cmd13,
  cmd14,
  cmd15,
  cmd16,
  cmd17,
  cmd18,
  cmd19,
  cmd20,
  cmd21
}currentWiFicmd;

extern currentWiFicmd currentWiFiCMD;

class WiFiData{
public:
  struct WiFiIndex
  {
    int idx;
    char* SSID;
    char* PassWord;
    char* devType = (char*)"esp32";
    IPAddress ipv4;
    std::string MacAddress;
    std::string devID;
  };

  std::string serverip = "192.168.5.8";
  int serverport = 3001;

  WiFiIndex WiFi_store[3];
};
  
class HeartBeatPacket{  //心跳包
public:
  long keepAliveTime = 100;
  long keepLiveCnt;
};

class ProjectDataPacket{
public:
  bool blestatus;
  bool wifistatus;
  std::string time;

  uint32_t freeHeap;
  float heapUsage;
  int8_t WiFi_dB;
  int runTime;  //单位为秒

  std::string device_ID;

  std::string old_CRC;
};

class MyServerCallbacks : public BLEServerCallbacks // 创建连接和断开调用类
{
public:
  void onConnect(BLEServer *pServer); // 开始连接函数
  void onDisconnect(BLEServer *pServer); // 断开连接函数
};

class MyCallbacks : public BLECharacteristicCallbacks
{
public:
  void onWrite(BLECharacteristic *pCharacteristic);
};

extern std::string value;

extern char WiFiStatus_str[2][30];

extern WiFiData WiFi_Data;
extern WiFiClient client;
extern HTTPClient http;
extern String readTCP;

extern HeartBeatPacket HeartBeat;
extern ProjectDataPacket ProjectData;

extern int my_timezone;
extern long gmtOffset_sec;
extern struct tm timeinfo;

extern std::string value;
extern int cJsonParseEnd;
extern int CRC_CHECKED;

extern BLEUUID ServiceUUID;
extern BLECharacteristic RX_Characteristics;
extern BLEDescriptor RX_Descriptor;
extern BLECharacteristic TX_Characteristics;
extern BLEDescriptor TX_Descriptor;

void WiFi_BLE_setUp();  //在WiFi开启之后调用此函数
void BLEHandler();
void WiFiHandler();
void ProjectDataUpdate();
void HeartBeatUpdate();

void updateLocalTime();

#endif // !_WIFI_BLE_H