#include <Arduino.h>
#include "FreeRTOS.h"
#include "WiFi_BLE.h"
#include "my_MPU6050.h"
#include "GUI_Driver.h"
#include "ModbusTask.h"


char serial1_Buffer[256];

void IoTTaskThread(void *argument);
TaskHandle_t IoTTaskHandle;

void SensorTaskThread(void *argument);
TaskHandle_t SensorTaskHandle;

void GUITaskThread(void *argument);
TaskHandle_t GUITaskHandle;

void ModBusThread(void *argument);
TaskHandle_t ModBusHandle;

static void SystemData_GUI();

void setup()
{
  Serial.begin(115200);

  xTaskCreatePinnedToCore(IoTTaskThread, "IoTTask", 1024*6, NULL, 2, &IoTTaskHandle, 1);

  xTaskCreatePinnedToCore(ModBusThread, "ModBusTask", 1024*4, NULL, 2, &ModBusHandle, 0);

  xTaskCreatePinnedToCore(SensorTaskThread, "SensorTask", 1024*4, NULL, 2, &IoTTaskHandle, 0);

  xTaskCreatePinnedToCore(GUITaskThread, "GUITask", 4096, NULL, 1, &IoTTaskHandle, 0);

}

void SensorTaskThread(void *argument){
  MPU6050_setup();
  for(;;){
    MPU6050_getData();
    MPU6050_SendJSONPack();
    vTaskDelay(300);
  }
}

void ModBusThread(void *argument){
  Modbus_Init();
  Modbus_configSingleRegister(163, 3);  //配置波特率为9600(默认配置)
  Modbus_getRegisterValue(0, 7);
  for(;;){
    // Modbus_getRegisterValue(0, 3);
    vTaskDelay(100);
  } 
}

void GUITaskThread(void *argument){
  GUI_setup();
  std::string GUI_logString = std::string(serial1_Buffer);
  for(;;){
    // SystemData_GUI();
    MPU6050_GUILog();
    GUI_logPrint(GUI_logString);
    vTaskDelay(500);
  }
}

void IoTTaskThread(void *argument){
  std::stringstream urlStream;
  urlStream << "http://" << WiFi_Data.serverip << ":" << WiFi_Data.serverport << "/cmd/connect";
  Serial.printf("Try to connect %s\r\n", urlStream.str().c_str());

  WiFi_BLE_setUp();
  configTime(gmtOffset_sec, 0, "pool.ntp.org");

  for(;;){
    BLEHandler();
    WiFiHandler();
    ProjectDataUpdate();
    vTaskDelay(100);
  }
}

void SystemData_GUI(){
  GUI_sysPrint(0, 16, "                                                      ");
  GUI_sysPrint(0, 16, "WiFi Status: %s", WiFiStatus_str[ProjectData.wifistatus]);
  GUI_sysPrint(0, 32, "                                                      ");
  GUI_sysPrint(0, 32, "ipv4 address: %s", WiFi.localIP().toString().c_str());

  GUI_sysPrint(0, 102, "%04d-%02d-%02d %02d:%02d:%02d", timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday,
                timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  GUI_sysPrint(0, 128, "last update date: %s", __DATE__);
}

void loop()
{
  delay(500);
}