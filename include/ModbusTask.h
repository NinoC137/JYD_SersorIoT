#ifndef __MODBUSTASK_H
#define  __MODBUSTASK_H

// Include the header for the ModbusClient RTU style
#include "ModbusClientRTU.h"
#include "CRC16.h"

// Create a ModbusRTU client instance
// In my case the RS485 module had auto halfduplex, so no parameter with the DE/RE pin is required!
extern ModbusClientRTU MB;

void Modbus_Init();

void Modbus_getRegisterValue(uint16_t startAddress, uint16_t dataLength);
void Modbus_configSingleRegister(uint16_t registerAddress, uint16_t value_Hex);

#endif // !__MODBUSTASK_H