#include "ModbusTask.h"

JYD_OriginalData_t JYD_OriginalData;
extern uint8_t states, parseState; // 来自main.cpp中modbus线程

// Create a ModbusRTU client instance
ModbusClientRTU MB;

CRC16 crc(CRC16_MODBUS_POLYNOME,
          CRC16_MODBUS_INITIAL,
          CRC16_MODBUS_XOR_OUT,
          CRC16_MODBUS_REV_IN,
          CRC16_MODBUS_REV_OUT);

static inline void calculateCRC16(const uint16_t *data, size_t length, uint16_t *result)
{
  for (int i = 0; i < length; i++)
  {
    crc.add((data[i] & 0xFF00) >> 8);
    crc.add((uint8_t)(data[i] & 0x00FF));
  }
  uint16_t crc_tmp = crc.calc();
  // 将CRC的高低位互换
  crc_tmp = (((crc_tmp) & 0x00FF) << 8 | ((crc_tmp) & 0xFF00) >> 8);
  *result = crc_tmp;
  crc.restart();
}

static inline uint16_t combineUint8ToUint16(uint8_t highByte, uint8_t lowByte)
{
  uint16_t result;
  // 将高位字节左移8位，低位字节不需要移动
  result = ((uint16_t)highByte << 8) | lowByte;
  return result;
}

static void printMsg(ModbusMessage msg)
{
  Serial.printf("Message size: %d\n", msg.size());
  for (auto &byte : msg)
  {
    Serial.printf("%02X ", byte);
  }

  Serial.printf("\n------------Hex format----------------\n");
  for (auto &byte : msg)
  {
    Serial.write(byte);
  }
  Serial.printf("\n--------------------------------------\n");

  if (msg.getError() != SUCCESS)
  {
    Serial.printf("Is an error message: %02d - %s\n", msg.getError(), (const char *)ModbusError(msg.getError()));
  }
  Serial.println("\n");
}

static void sendMsg(ModbusMessage msg)
{
  for (auto &byte : msg)
  {
    Serial2.write(byte);
  }
}

void handleData(ModbusMessage response, uint32_t token)
{
  // uint8_t *responseData = (uint8_t *)malloc(512);
  const uint8_t *responseData;
  uint16_t i = 0;
  // Serial.printf("Response: serverID=%d, FC=%d, Token=%08X, length=%d:\n", response.getServerID(), response.getFunctionCode(), token, response.size());
  // for (auto &byte : response)
  // {
  //   // Serial.printf("%02x", byte);
  //   responseData[i] = byte;
  //   i++;
  // }

  responseData = response.data();

  if (response.getServerID() == 0x01 && response.getFunctionCode() == 0x03) // 数据[0] [1] [2]都是接收包头, 不属于传感器值
  { 
    // Serial.printf("-----start parse--------\r\n");
    switch (parseState) // 根据当前处在哪个states,来进行对应数据的解析
    {
    case 0:
      /* 处理 states = 0 的情况 */
      JYD_OriginalData.x_speed = combineUint8ToUint16(responseData[3], responseData[4]);
      JYD_OriginalData.y_speed = combineUint8ToUint16(responseData[5], responseData[6]);
      JYD_OriginalData.z_speed = combineUint8ToUint16(responseData[7], responseData[8]);
      JYD_OriginalData.temp = combineUint8ToUint16(responseData[9], responseData[10]);
      JYD_OriginalData.x_acc = combineUint8ToUint16(responseData[11], responseData[12]);
      JYD_OriginalData.y_acc = combineUint8ToUint16(responseData[13], responseData[14]);
      JYD_OriginalData.z_acc = combineUint8ToUint16(responseData[15], responseData[16]);
      JYD_OriginalData.x_speedmax = combineUint8ToUint16(responseData[17], responseData[18]);
      JYD_OriginalData.x_speedkrt = combineUint8ToUint16(responseData[19], responseData[20]);
      JYD_OriginalData.x_accmax = combineUint8ToUint16(responseData[21], responseData[22]);
      JYD_OriginalData.x_acckrt = combineUint8ToUint16(responseData[23], responseData[24]);
      JYD_OriginalData.y_speedmax = combineUint8ToUint16(responseData[25], responseData[26]);
      JYD_OriginalData.y_speedkrt = combineUint8ToUint16(responseData[27], responseData[28]);
      JYD_OriginalData.y_accmax = combineUint8ToUint16(responseData[29], responseData[30]);
      JYD_OriginalData.y_acckrt = combineUint8ToUint16(responseData[31], responseData[32]);
      JYD_OriginalData.z_speedmax = combineUint8ToUint16(responseData[33], responseData[34]);
      JYD_OriginalData.z_speedkrt = combineUint8ToUint16(responseData[35], responseData[36]);
      JYD_OriginalData.z_accmax = combineUint8ToUint16(responseData[37], responseData[38]);
      JYD_OriginalData.z_acckrt = combineUint8ToUint16(responseData[39], responseData[40]);
      JYD_OriginalData.x_dispeek = combineUint8ToUint16(responseData[41], responseData[42]);
      JYD_OriginalData.y_dispeek = combineUint8ToUint16(responseData[43], responseData[44]);
      JYD_OriginalData.z_dispeek = combineUint8ToUint16(responseData[45], responseData[46]);
      JYD_OriginalData.fft_count = combineUint8ToUint16(responseData[47], responseData[48]);
      JYD_OriginalData.xSpeed_channalID = combineUint8ToUint16(responseData[49], responseData[50]);
      JYD_OriginalData.xSpeed_rotate_speed = combineUint8ToUint16(responseData[51], responseData[52]);
      JYD_OriginalData.xAcc_inside_eigenvalue = combineUint8ToUint16(responseData[53], responseData[54]);
      JYD_OriginalData.xAcc_outside_eigenvalue = combineUint8ToUint16(responseData[55], responseData[56]);
      JYD_OriginalData.xAcc_roll_eigenvalue = combineUint8ToUint16(responseData[57], responseData[58]);
      JYD_OriginalData.xAcc_shell_eigenvalue = combineUint8ToUint16(responseData[59], responseData[60]);
      JYD_OriginalData.xAcc_point_1 = combineUint8ToUint16(responseData[61], responseData[62]);
      JYD_OriginalData.xAcc_point_2 = combineUint8ToUint16(responseData[63], responseData[64]);
      JYD_OriginalData.xAcc_point_3 = combineUint8ToUint16(responseData[65], responseData[66]);
      JYD_OriginalData.xAcc_point_4 = combineUint8ToUint16(responseData[67], responseData[68]);
      JYD_OriginalData.xAcc_point_5 = combineUint8ToUint16(responseData[69], responseData[70]);
      JYD_OriginalData.xAcc_point_6 = combineUint8ToUint16(responseData[71], responseData[72]);
      JYD_OriginalData.xAcc_point_7 = combineUint8ToUint16(responseData[73], responseData[74]);
      JYD_OriginalData.xAcc_point_8 = combineUint8ToUint16(responseData[75], responseData[76]);
      JYD_OriginalData.xAcc_band_1 = combineUint8ToUint16(responseData[77], responseData[78]);
      JYD_OriginalData.xAcc_band_2 = combineUint8ToUint16(responseData[79], responseData[80]);
      JYD_OriginalData.xAcc_band_3 = combineUint8ToUint16(responseData[81], responseData[82]);
      JYD_OriginalData.xAcc_band_4 = combineUint8ToUint16(responseData[83], responseData[84]);
      JYD_OriginalData.xAcc_band_5 = combineUint8ToUint16(responseData[85], responseData[86]);
      JYD_OriginalData.xAcc_maxpower_order = combineUint8ToUint16(responseData[87], responseData[88]);
      JYD_OriginalData.xAcc_total_power = combineUint8ToUint16(responseData[89], responseData[90]);
      JYD_OriginalData.xSpeed_paddle_eigenvalue_1 = combineUint8ToUint16(responseData[91], responseData[92]);
      JYD_OriginalData.xSpeed_paddle_eigenvalue_2 = combineUint8ToUint16(responseData[93], responseData[94]);
      JYD_OriginalData.xSpeed_paddle_eigenvalue_3 = combineUint8ToUint16(responseData[95], responseData[96]);
      JYD_OriginalData.xSpeed_paddle_eigenvalue_4 = combineUint8ToUint16(responseData[97], responseData[98]);
      JYD_OriginalData.xSpeed_point_1 = combineUint8ToUint16(responseData[99], responseData[100]);
      JYD_OriginalData.xSpeed_point_2 = combineUint8ToUint16(responseData[101], responseData[102]);
      JYD_OriginalData.xSpeed_point_3 = combineUint8ToUint16(responseData[103], responseData[104]);
      JYD_OriginalData.xSpeed_point_4 = combineUint8ToUint16(responseData[105], responseData[106]);
      JYD_OriginalData.xSpeed_point_5 = combineUint8ToUint16(responseData[107], responseData[108]);
      JYD_OriginalData.xSpeed_point_6 = combineUint8ToUint16(responseData[109], responseData[110]);
      JYD_OriginalData.xSpeed_point_7 = combineUint8ToUint16(responseData[111], responseData[112]);
      JYD_OriginalData.xSpeed_point_8 = combineUint8ToUint16(responseData[113], responseData[114]);
      JYD_OriginalData.xSpeed_band_1 = combineUint8ToUint16(responseData[115], responseData[116]);
      JYD_OriginalData.xSpeed_band_2 = combineUint8ToUint16(responseData[117], responseData[118]);
      JYD_OriginalData.xSpeed_band_3 = combineUint8ToUint16(responseData[119], responseData[120]);
      JYD_OriginalData.xSpeed_band_4 = combineUint8ToUint16(responseData[121], responseData[122]);
      JYD_OriginalData.xSpeed_band_5 = combineUint8ToUint16(responseData[123], responseData[124]);
      JYD_OriginalData.xSpeed_maxpower_order = combineUint8ToUint16(responseData[125], responseData[126]);
      JYD_OriginalData.xSpeed_total_power = combineUint8ToUint16(responseData[127], responseData[128]);
      JYD_OriginalData.ySpeed_channalID = combineUint8ToUint16(responseData[129], responseData[130]);
      JYD_OriginalData.ySpeed_rotate_speed = combineUint8ToUint16(responseData[131], responseData[132]);
      JYD_OriginalData.yAcc_inside_eigenvalue = combineUint8ToUint16(responseData[133], responseData[134]);
      JYD_OriginalData.yAcc_outside_eigenvalue = combineUint8ToUint16(responseData[135], responseData[136]);
      JYD_OriginalData.yAcc_roll_eigenvalue = combineUint8ToUint16(responseData[137], responseData[138]);
      JYD_OriginalData.yAcc_shell_eigenvalue = combineUint8ToUint16(responseData[139], responseData[140]);
      JYD_OriginalData.yAcc_point_1 = combineUint8ToUint16(responseData[141], responseData[142]);
      JYD_OriginalData.yAcc_point_2 = combineUint8ToUint16(responseData[143], responseData[144]);
      JYD_OriginalData.yAcc_point_3 = combineUint8ToUint16(responseData[145], responseData[146]);
      JYD_OriginalData.yAcc_point_4 = combineUint8ToUint16(responseData[147], responseData[148]);
      JYD_OriginalData.yAcc_point_5 = combineUint8ToUint16(responseData[149], responseData[150]);
      JYD_OriginalData.yAcc_point_6 = combineUint8ToUint16(responseData[151], responseData[152]);
      JYD_OriginalData.yAcc_point_7 = combineUint8ToUint16(responseData[153], responseData[154]);
      JYD_OriginalData.yAcc_point_8 = combineUint8ToUint16(responseData[155], responseData[156]);
      JYD_OriginalData.yAcc_band_1 = combineUint8ToUint16(responseData[157], responseData[158]);
      JYD_OriginalData.yAcc_band_2 = combineUint8ToUint16(responseData[159], responseData[160]);
      JYD_OriginalData.yAcc_band_3 = combineUint8ToUint16(responseData[161], responseData[162]);
      JYD_OriginalData.yAcc_band_4 = combineUint8ToUint16(responseData[163], responseData[164]);
      JYD_OriginalData.yAcc_band_5 = combineUint8ToUint16(responseData[165], responseData[166]);
      JYD_OriginalData.yAcc_maxpower_order = combineUint8ToUint16(responseData[167], responseData[168]);
      JYD_OriginalData.yAcc_total_power = combineUint8ToUint16(responseData[169], responseData[170]);
      JYD_OriginalData.yAcc_paddle_eigenvalue_1 = combineUint8ToUint16(responseData[171], responseData[172]);
      JYD_OriginalData.yAcc_paddle_eigenvalue_2 = combineUint8ToUint16(responseData[173], responseData[174]);
      JYD_OriginalData.yAcc_paddle_eigenvalue_3 = combineUint8ToUint16(responseData[175], responseData[176]);
      JYD_OriginalData.yAcc_paddle_eigenvalue_4 = combineUint8ToUint16(responseData[177], responseData[178]);
      JYD_OriginalData.ySpeed_point_1 = combineUint8ToUint16(responseData[179], responseData[180]);
      JYD_OriginalData.ySpeed_point_2 = combineUint8ToUint16(responseData[181], responseData[182]);
      JYD_OriginalData.ySpeed_point_3 = combineUint8ToUint16(responseData[183], responseData[184]);
      JYD_OriginalData.ySpeed_point_4 = combineUint8ToUint16(responseData[185], responseData[186]);
      JYD_OriginalData.ySpeed_point_5 = combineUint8ToUint16(responseData[187], responseData[188]);
      JYD_OriginalData.ySpeed_point_6 = combineUint8ToUint16(responseData[189], responseData[190]);
      JYD_OriginalData.ySpeed_point_7 = combineUint8ToUint16(responseData[191], responseData[192]);
      JYD_OriginalData.ySpeed_point_8 = combineUint8ToUint16(responseData[193], responseData[194]);
      JYD_OriginalData.ySpeed_band_1 = combineUint8ToUint16(responseData[195], responseData[196]);
      JYD_OriginalData.ySpeed_band_2 = combineUint8ToUint16(responseData[197], responseData[198]);
      JYD_OriginalData.ySpeed_band_3 = combineUint8ToUint16(responseData[199], responseData[200]);
      JYD_OriginalData.ySpeed_band_4 = combineUint8ToUint16(responseData[201], responseData[202]);
      JYD_OriginalData.ySpeed_band_5 = combineUint8ToUint16(responseData[203], responseData[204]);
      JYD_OriginalData.ySpeed_maxpower_order = combineUint8ToUint16(responseData[205], responseData[206]);
      JYD_OriginalData.ySpeed_total_power = combineUint8ToUint16(responseData[207], responseData[208]);
      JYD_OriginalData.zSpeed_channalID = combineUint8ToUint16(responseData[209], responseData[210]);
      JYD_OriginalData.zSpeed_rotate_speed = combineUint8ToUint16(responseData[211], responseData[212]);
      JYD_OriginalData.zAcc_inside_eigenvalue = combineUint8ToUint16(responseData[213], responseData[214]);
      JYD_OriginalData.zAcc_outside_eigenvalue = combineUint8ToUint16(responseData[215], responseData[216]);
      JYD_OriginalData.zAcc_roll_eigenvalue = combineUint8ToUint16(responseData[217], responseData[218]);
      JYD_OriginalData.zAcc_shell_eigenvalue = combineUint8ToUint16(responseData[219], responseData[220]);
      JYD_OriginalData.zAcc_point_1 = combineUint8ToUint16(responseData[221], responseData[222]);
      JYD_OriginalData.zAcc_point_2 = combineUint8ToUint16(responseData[223], responseData[224]);
      JYD_OriginalData.zAcc_point_3 = combineUint8ToUint16(responseData[225], responseData[226]);
      JYD_OriginalData.zAcc_point_4 = combineUint8ToUint16(responseData[227], responseData[228]);
      JYD_OriginalData.zAcc_point_5 = combineUint8ToUint16(responseData[229], responseData[230]);
      JYD_OriginalData.zAcc_point_6 = combineUint8ToUint16(responseData[231], responseData[232]);
      JYD_OriginalData.zAcc_point_7 = combineUint8ToUint16(responseData[233], responseData[234]);
      JYD_OriginalData.zAcc_point_8 = combineUint8ToUint16(responseData[235], responseData[236]); // 117寄存器
      break;
    case 1:
      JYD_OriginalData.zAcc_band_1 = combineUint8ToUint16(responseData[3], responseData[4]);
      JYD_OriginalData.zAcc_band_2 = combineUint8ToUint16(responseData[5], responseData[6]);
      JYD_OriginalData.zAcc_band_3 = combineUint8ToUint16(responseData[7], responseData[8]);
      JYD_OriginalData.zAcc_band_4 = combineUint8ToUint16(responseData[9], responseData[10]);
      JYD_OriginalData.zAcc_band_5 = combineUint8ToUint16(responseData[11], responseData[12]);
      JYD_OriginalData.zAcc_maxpower_order = combineUint8ToUint16(responseData[13], responseData[14]);
      JYD_OriginalData.zAcc_total_power = combineUint8ToUint16(responseData[15], responseData[16]);
      JYD_OriginalData.zAcc_paddle_eigenvalue_1 = combineUint8ToUint16(responseData[17], responseData[18]);
      JYD_OriginalData.zAcc_paddle_eigenvalue_2 = combineUint8ToUint16(responseData[19], responseData[20]);
      JYD_OriginalData.zAcc_paddle_eigenvalue_3 = combineUint8ToUint16(responseData[21], responseData[22]);
      JYD_OriginalData.zAcc_paddle_eigenvalue_4 = combineUint8ToUint16(responseData[23], responseData[24]);
      JYD_OriginalData.zSpeed_point_1 = combineUint8ToUint16(responseData[25], responseData[26]);
      JYD_OriginalData.zSpeed_point_2 = combineUint8ToUint16(responseData[27], responseData[28]);
      JYD_OriginalData.zSpeed_point_3 = combineUint8ToUint16(responseData[29], responseData[30]);
      JYD_OriginalData.zSpeed_point_4 = combineUint8ToUint16(responseData[31], responseData[32]);
      JYD_OriginalData.zSpeed_point_5 = combineUint8ToUint16(responseData[33], responseData[34]);
      JYD_OriginalData.zSpeed_point_6 = combineUint8ToUint16(responseData[35], responseData[36]);
      JYD_OriginalData.zSpeed_point_7 = combineUint8ToUint16(responseData[37], responseData[38]);
      JYD_OriginalData.zSpeed_point_8 = combineUint8ToUint16(responseData[39], responseData[40]);
      JYD_OriginalData.zSpeed_band_1 = combineUint8ToUint16(responseData[41], responseData[42]);
      JYD_OriginalData.zSpeed_band_2 = combineUint8ToUint16(responseData[43], responseData[44]);
      JYD_OriginalData.zSpeed_band_3 = combineUint8ToUint16(responseData[45], responseData[46]);
      JYD_OriginalData.zSpeed_band_4 = combineUint8ToUint16(responseData[47], responseData[48]);
      JYD_OriginalData.zSpeed_band_5 = combineUint8ToUint16(responseData[49], responseData[50]);
      JYD_OriginalData.zSpeed_maxpower_order = combineUint8ToUint16(responseData[51], responseData[52]);
      JYD_OriginalData.zSpeed_total_power = combineUint8ToUint16(responseData[53], responseData[54]);
      JYD_OriginalData.channalx_status = combineUint8ToUint16(responseData[55], responseData[56]);
      JYD_OriginalData.channaly_status = combineUint8ToUint16(responseData[57], responseData[58]);
      JYD_OriginalData.channalz_status = combineUint8ToUint16(responseData[59], responseData[60]);
      JYD_OriginalData.temp_status = combineUint8ToUint16(responseData[61], responseData[62]);
      JYD_OriginalData.x_warning = combineUint8ToUint16(responseData[63], responseData[64]);
      JYD_OriginalData.y_warning = combineUint8ToUint16(responseData[65], responseData[66]);
      JYD_OriginalData.z_warning = combineUint8ToUint16(responseData[67], responseData[68]);
      JYD_OriginalData.version = combineUint8ToUint16(responseData[69], responseData[70]);
      JYD_OriginalData.license = combineUint8ToUint16(responseData[71], responseData[72]);
      JYD_OriginalData.BPFI = combineUint8ToUint16(responseData[73], responseData[74]);
      JYD_OriginalData.BPFO = combineUint8ToUint16(responseData[75], responseData[76]);
      JYD_OriginalData.BSF = combineUint8ToUint16(responseData[77], responseData[78]);
      JYD_OriginalData.FTF = combineUint8ToUint16(responseData[79], responseData[80]);
      break;
    case 2:
      /* 处理 states = 2 的情况 */
      JYD_OriginalData.measue_speed = combineUint8ToUint16(responseData[3], responseData[4]);
      JYD_OriginalData.proportion = combineUint8ToUint16(responseData[5], responseData[6]);
      JYD_OriginalData.point1_gain = combineUint8ToUint16(responseData[7], responseData[8]);
      JYD_OriginalData.point2_gain = combineUint8ToUint16(responseData[9], responseData[10]);
      JYD_OriginalData.point3_gain = combineUint8ToUint16(responseData[11], responseData[12]);
      JYD_OriginalData.point4_gain = combineUint8ToUint16(responseData[13], responseData[14]);
      JYD_OriginalData.point5_gain = combineUint8ToUint16(responseData[15], responseData[16]);
      JYD_OriginalData.point6_gain = combineUint8ToUint16(responseData[17], responseData[18]);
      JYD_OriginalData.point7_gain = combineUint8ToUint16(responseData[19], responseData[20]);
      JYD_OriginalData.point8_gain = combineUint8ToUint16(responseData[21], responseData[22]);
      JYD_OriginalData.band1_startgain = combineUint8ToUint16(responseData[23], responseData[24]);
      JYD_OriginalData.band1_endgain = combineUint8ToUint16(responseData[25], responseData[26]);
      JYD_OriginalData.band2_startgain = combineUint8ToUint16(responseData[27], responseData[28]);
      JYD_OriginalData.band2_endgain = combineUint8ToUint16(responseData[29], responseData[30]);
      JYD_OriginalData.band3_startgain = combineUint8ToUint16(responseData[31], responseData[32]);
      JYD_OriginalData.band3_endgain = combineUint8ToUint16(responseData[33], responseData[34]);
      JYD_OriginalData.band4_startgain = combineUint8ToUint16(responseData[35], responseData[36]);
      JYD_OriginalData.band4_endgain = combineUint8ToUint16(responseData[37], responseData[38]);
      JYD_OriginalData.band5_startgain = combineUint8ToUint16(responseData[39], responseData[40]);
      JYD_OriginalData.band5_endgain = combineUint8ToUint16(responseData[41], responseData[42]);
      JYD_OriginalData.rollerNumber = combineUint8ToUint16(responseData[43], responseData[44]);
      JYD_OriginalData.rollerSize = combineUint8ToUint16(responseData[45], responseData[46]);
      JYD_OriginalData.bearingSize = combineUint8ToUint16(responseData[47], responseData[48]);
      JYD_OriginalData.alphaAngular = combineUint8ToUint16(responseData[49], responseData[50]);
      JYD_OriginalData.teethNumber = combineUint8ToUint16(responseData[51], responseData[52]);
      JYD_OriginalData.mode = combineUint8ToUint16(responseData[53], responseData[54]);
      JYD_OriginalData.target = combineUint8ToUint16(responseData[55], responseData[56]);
      JYD_OriginalData.x_accWarning = combineUint8ToUint16(responseData[57], responseData[58]);
      JYD_OriginalData.x_accError = combineUint8ToUint16(responseData[59], responseData[60]);
      JYD_OriginalData.y_accWarning = combineUint8ToUint16(responseData[61], responseData[62]);
      JYD_OriginalData.y_accError = combineUint8ToUint16(responseData[63], responseData[64]);
      JYD_OriginalData.z_accWarning = combineUint8ToUint16(responseData[65], responseData[66]);
      JYD_OriginalData.z_accError = combineUint8ToUint16(responseData[67], responseData[68]);
      JYD_OriginalData.x_speedWarning = combineUint8ToUint16(responseData[69], responseData[70]);
      JYD_OriginalData.x_speedError = combineUint8ToUint16(responseData[71], responseData[72]);
      JYD_OriginalData.y_speedWarning = combineUint8ToUint16(responseData[73], responseData[74]);
      JYD_OriginalData.y_accWarning = combineUint8ToUint16(responseData[75], responseData[76]);
      JYD_OriginalData.z_speedWarning = combineUint8ToUint16(responseData[77], responseData[78]);
      JYD_OriginalData.z_speedError = combineUint8ToUint16(responseData[79], responseData[80]);
      JYD_OriginalData.tempWarning = combineUint8ToUint16(responseData[81], responseData[82]);
      JYD_OriginalData.tempError = combineUint8ToUint16(responseData[83], responseData[84]);
      JYD_OriginalData.x_distanceWarning = combineUint8ToUint16(responseData[85], responseData[86]);
      JYD_OriginalData.x_distanceError = combineUint8ToUint16(responseData[87], responseData[88]);
      JYD_OriginalData.y_distanceWarning = combineUint8ToUint16(responseData[89], responseData[90]);
      JYD_OriginalData.y_distanceError = combineUint8ToUint16(responseData[91], responseData[92]);
      JYD_OriginalData.z_distanceWarning = combineUint8ToUint16(responseData[93], responseData[94]);
      JYD_OriginalData.z_distanceError = combineUint8ToUint16(responseData[95], responseData[96]);
      JYD_OriginalData.hpf_limit = combineUint8ToUint16(responseData[97], responseData[98]);
      JYD_OriginalData.lpf_limit = combineUint8ToUint16(responseData[99], responseData[100]);
      JYD_OriginalData.calcPeriod = combineUint8ToUint16(responseData[101], responseData[102]);
      break;
    }
  }
  // free(responseData);
}

void handleError(Error error, uint32_t token)
{
  // ModbusError wraps the error code and provides a readable error message for it
  ModbusError me(error);
  Serial.printf("Error response: %02X - %s\n", (int)me, (const char *)me);
}

void Modbus_Init()
{
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

void Modbus_getRegisterValue(uint16_t startAddress, uint16_t dataLength)
{
  static uint32_t Token = 0;
  // uint16_t crcValue[4];
  // crcValue[0] = 0x0103;
  // crcValue[1] = startAddress;
  // crcValue[2] = dataLength;
  // calculateCRC16(crcValue, 3, &crcValue[3]);

  ModbusMessage msg;
  msg.setMessage(1, READ_HOLD_REGISTER, startAddress, dataLength);
  // msg.add(crcValue[3]);
  //  printMsg(msg);
  //  sendMsg(msg);

  Error err = MB.addRequest(msg, Token++);

  if (err != SUCCESS)
  {
    ModbusError e(err);
    Serial.printf("Error creating request: %02X - %s\n", (int)e, (const char *)e);
  }
}

void Modbus_configSingleRegister(uint16_t registerAddress, uint16_t value_Hex)
{
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