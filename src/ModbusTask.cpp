#include "ModbusTask.h"

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
  Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  for (auto& byte : response) {
    Serial.printf("%02X ", byte);
  }
  Serial.println("");
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
  Serial2.begin(9600, SERIAL_8N1, GPIO_NUM_17, GPIO_NUM_16);
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
// Create request for
// (Fill in your data here!)
// - server ID = 1
// - function code = 0x03 (read holding register)
// - address to read = word 0
// - data words to read = 3
// - token to match the response with the request.
//
// If something is missing or wrong with the call parameters, we will immediately get an error code 
// and the request will not be issued

    uint16_t crcValue[4];
    crcValue[0] = 0x0103;
    crcValue[1] = startAddress;
    crcValue[2] = dataLength;
    calculateCRC16(crcValue, 3, &crcValue[3]);

    ModbusMessage msg;
    msg.setMessage(1, READ_HOLD_REGISTER, startAddress, dataLength);
    msg.add(crcValue[3]);
    // printMsg(msg);

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