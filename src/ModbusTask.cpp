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

// Define an onData handler function to receive the regular responses
// Arguments are Modbus server ID, the function code requested, the message data and length of it, 
// plus a user-supplied token to identify the causing request
void handleData(ModbusMessage response, uint32_t token) 
{
  Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  for (auto& byte : response) {
    Serial.printf("%02X ", byte);
  }
  Serial.println("");
}

// Define an onError handler function to receive error responses
// Arguments are the error code returned and a user-supplied token to identify the causing request
void handleError(Error error, uint32_t token) 
{
  // ModbusError wraps the error code and provides a readable error message for it
  ModbusError me(error);
  Serial.printf("Error response: %02X - %s\n", (int)me, (const char *)me);
}

void Modbus_Init(){
// Set up Serial2 connected to Modbus RTU
// (Fill in your data here!)
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
}

void Modbus_getAllRegisterValue(){
    static uint32_t Token = 0;
// Create request for
// (Fill in your data here!)
// - server ID = 1
// - function code = 0x03 (read holding register)
// - address to read = word 0
// - data words to read = 2
// - token to match the response with the request.
//
// If something is missing or wrong with the call parameters, we will immediately get an error code 
// and the request will not be issued

    uint16_t wData[] = {0x0000, 0x0007};
    uint16_t finalData[3];

    finalData[0] = wData[0];
    finalData[1] = wData[1];
    calculateCRC16(wData, sizeof(wData)/sizeof(wData[0]), &finalData[2]);

    Error err = MB.addRequest(Token++, 1, READ_HOLD_REGISTER, (uint16_t)0x0000, 3, 6, finalData);
    if (err!=SUCCESS) {
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

    //show up on Serial log
    for (int i = 0; i < 4; i++) {
        Serial.printf("%02X", wData[i]);
    }
    Serial.println("");
}