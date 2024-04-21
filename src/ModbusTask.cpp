#include "ModbusTask.h"

JYD_OriginalData_t JYD_OriginalData;
extern uint8_t states; //来自main.cpp中modbus线程

// Create a ModbusRTU client instance
ModbusClientRTU MB;

CRC16 crc(CRC16_MODBUS_POLYNOME,
          CRC16_MODBUS_INITIAL,
          CRC16_MODBUS_XOR_OUT,
          CRC16_MODBUS_REV_IN,
          CRC16_MODBUS_REV_OUT);

static inline void calculateCRC16(const uint16_t *data, size_t length, uint16_t *result) {
    for (int i = 0; i < length; i++){
        crc.add((data[i] & 0xFF00) >> 8);
        crc.add((uint8_t)(data[i] & 0x00FF));
    }
    uint16_t crc_tmp = crc.calc();
    //将CRC的高低位互换
    crc_tmp = (((crc_tmp) & 0x00FF) << 8 | ((crc_tmp) & 0xFF00) >> 8);
    *result = crc_tmp;
    crc.restart();
}

static inline uint16_t combineUint8ToUint16(uint8_t highByte, uint8_t lowByte) {
    uint16_t result;
    // 将高位字节左移8位，低位字节不需要移动
    result = ((uint16_t)highByte << 8) | lowByte;
    return result;
}

static void printMsg(ModbusMessage msg) {
  Serial.printf("Message size: %d\n", msg.size());
  for (auto& byte : msg) {
    Serial.printf("%02X ", byte);
  }

  Serial.printf("\n------------Hex format----------------\n");
  for (auto& byte : msg) {
    Serial.write(byte);
  }
  Serial.printf("\n--------------------------------------\n");

  if (msg.getError() != SUCCESS) {
    Serial.printf("Is an error message: %02d - %s\n", msg.getError(), (const char *)ModbusError(msg.getError()));
  }
  Serial.println("\n");
}

static void sendMsg(ModbusMessage msg){
  for (auto& byte : msg) {
    Serial2.write(byte);
  }
}

void handleData(ModbusMessage response, uint32_t token) 
{
  uint8_t *responseData = new uint8_t(256);
  uint16_t i = 0;
  // Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  for (auto& byte : response) {
    // Serial.printf("%02X ", byte);
    i++;
    responseData[i] = byte; //将数据转存到缓冲区
  }

  if(responseData[0] == 0x01 && responseData[1] == 0x03){ //如果包头为数据接收包头 [0] [1] [2]都是包头, 不属于传感器值
        switch (states) //根据当前处在哪个states,来进行对应数据的解析
    {
        case 0:
            /* 处理 states = 0 的情况 */
            JYD_OriginalData.x_speed = combineUint8ToUint16(responseData[3], responseData[4]);
            JYD_OriginalData.y_speed = combineUint8ToUint16(responseData[5], responseData[6]);
            JYD_OriginalData.z_speed = combineUint8ToUint16(responseData[7], responseData[8]);
            break;
        case 1:
            /* 处理 states = 1 的情况 */
            break;
    }
  }
  delete(responseData);
}

void handleError(Error error, uint32_t token) 
{
  // ModbusError wraps the error code and provides a readable error message for it
  ModbusError me(error);
  Serial.printf("Error response: %02X - %s\n", (int)me, (const char *)me);
}

void Modbus_Init(){
// Set up Serial2 connected to Modbus RTU
  RTUutils::prepareHardwareSerial(Serial2);
  Serial2.begin(9600);
  Serial2.setPins(GPIO_NUM_41, GPIO_NUM_40);
// Set up ModbusRTU client.
// - provide onData handler function
  MB.onDataHandler(&handleData);
// - provide onError handler function
  MB.onErrorHandler(&handleError);
// Set message timeout to 2000ms
  MB.setTimeout(2000);
// Start ModbusRTU background task
  MB.begin(Serial2);
  MB.useModbusRTU();
}

void Modbus_getRegisterValue(uint16_t startAddress, uint16_t dataLength){
    static uint32_t Token = 0;
    // uint16_t crcValue[4];
    // crcValue[0] = 0x0103;
    // crcValue[1] = startAddress;
    // crcValue[2] = dataLength;
    // calculateCRC16(crcValue, 3, &crcValue[3]);

    ModbusMessage msg;
    msg.setMessage(1, READ_HOLD_REGISTER, startAddress, dataLength);
    //msg.add(crcValue[3]);
    // printMsg(msg);
    // sendMsg(msg);

    Error err = MB.addRequest(msg, Token++);
    
    if (err != SUCCESS) {
        ModbusError e(err);
        Serial.printf("Error creating request: %02X - %s\n", (int)e, (const char *)e);
    }
}

void Modbus_configSingleRegister(uint16_t registerAddress, uint16_t value_Hex){
    uint16_t wData[4];

    wData[0] = 0x0106;
    wData[1] = registerAddress;
    wData[2] = value_Hex;
    calculateCRC16(wData, 3, &wData[3]);

    ModbusMessage msg;
    msg.add(wData[0], wData[1], wData[2], wData[3]);
    
    // printMsg(msg);
    sendMsg(msg);
}