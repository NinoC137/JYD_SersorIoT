#ifndef __MODBUSTASK_H
#define  __MODBUSTASK_H

// Include the header for the ModbusClient RTU style
#include "ModbusClientRTU.h"
#include "CRC16.h"

#include "WiFi_BLE.h"

typedef struct{
    uint16_t x_speed;   //100x
    uint16_t y_speed;   //100x
    uint16_t z_speed;   //100x
    int16_t temp;      //100x
    uint16_t x_acc;     //100x
    uint16_t y_acc;     //100x
    uint16_t z_acc;     //100x
    uint16_t x_speedmax; //100x
    uint16_t x_speedkrt; //100x
    uint16_t x_accmax; //100x
    uint16_t x_acckrt; //100x
    uint16_t y_speedmax; //100x
    uint16_t y_speedkrt; //100x
    uint16_t y_accmax; //100x
    uint16_t y_acckrt; //100x
    uint16_t z_speedmax; //100x
    uint16_t z_speedkrt; //100x
    uint16_t z_accmax; //100x
    uint16_t z_acckrt; //100x
    uint16_t x_dispeek; //1x
    uint16_t y_dispeek; //1x
    uint16_t z_dispeek; //1x
    uint16_t fft_count; //1x
    uint16_t xSpeed_channalID;
    uint16_t xSpeed_rotate_speed; //100x
    uint16_t xAcc_inside_eigenvalue; //100x
    uint16_t xAcc_outside_eigenvalue; //100x 
    uint16_t xAcc_roll_eigenvalue; //100x
    uint16_t xAcc_shell_eigenvalue; //100x
    uint16_t xSpeed_point_1; //100x 
    uint16_t xSpeed_point_2; //100x
    uint16_t xSpeed_point_3; //100x
    uint16_t xSpeed_point_4; //100x
    uint16_t xSpeed_point_5; //100x
    uint16_t xSpeed_point_6; //100x
    uint16_t xSpeed_point_7; //100x
    uint16_t xSpeed_point_8; //100x
    uint16_t xSpeed_band_1; //100x
    uint16_t xSpeed_band_2; //100x
    uint16_t xSpeed_band_3; //100x
    uint16_t xSpeed_band_4; //100x
    uint16_t xSpeed_band_5; //100x
    uint16_t xSpeed_band_6; //100x
    uint16_t xSpeed_band_7; //100x
    uint16_t xSpeed_band_8; //100x
    uint16_t xSpeed_maxpower_order; //10x
    uint16_t xSpeed_total_power; //100x
    uint16_t xSpeed_paddle_eigenvalue_1; //100x,44
    uint16_t xSpeed_paddle_eigenvalue_2; //100x,45
    uint16_t xSpeed_paddle_eigenvalue_3; //100x,46
    uint16_t xSpeed_paddle_eigenvalue_4; //100x,47
    uint16_t xAcc_point_1; //100x
    uint16_t xAcc_point_2; //100x
    uint16_t xAcc_point_3; //100x
    uint16_t xAcc_point_4; //100x
    uint16_t xAcc_point_5; //100x
    uint16_t xAcc_point_6; //100x
    uint16_t xAcc_point_7; //100x
    uint16_t xAcc_point_8; //100x
    uint16_t xAcc_band_1; //100x
    uint16_t xAcc_band_2; //100x
    uint16_t xAcc_band_3; //100x
    uint16_t xAcc_band_4; //100x
    uint16_t xAcc_band_5; //100x
    uint16_t xAcc_band_6; //100x
    uint16_t xAcc_band_7; //100x
    uint16_t xAcc_band_8; //100x
    uint16_t xAcc_maxpower_order; //10x
    uint16_t xAcc_total_power; //100x
    uint16_t ySpeed_channalID;
    uint16_t ySpeed_rotate_speed; //100x
    uint16_t yAcc_inside_eigenvalue; //100x
    uint16_t yAcc_outside_eigenvalue; //100x
    uint16_t yAcc_roll_eigenvalue; //100x
    uint16_t yAcc_shell_eigenvalue; //100x
    uint16_t ySpeed_point_1; //100x
    uint16_t ySpeed_point_2; //100x
    uint16_t ySpeed_point_3; //100x
    uint16_t ySpeed_point_4; //100x
    uint16_t ySpeed_point_5; //100x
    uint16_t ySpeed_point_6; //100x
    uint16_t ySpeed_point_7; //100x
    uint16_t ySpeed_point_8; //100x
    uint16_t ySpeed_band_1; //100x
    uint16_t ySpeed_band_2; //100x
    uint16_t ySpeed_band_3; //100x
    uint16_t ySpeed_band_4; //100x
    uint16_t ySpeed_band_5; //100x
    uint16_t ySpeed_band_6; //100x
    uint16_t ySpeed_band_7; //100x
    uint16_t ySpeed_band_8; //100x
    uint16_t ySpeed_maxpower_order; //10x
    uint16_t ySpeed_total_power; //100x
    uint16_t yAcc_paddle_eigenvalue_1; //100x
    uint16_t yAcc_paddle_eigenvalue_2; //100x
    uint16_t yAcc_paddle_eigenvalue_3; //100x
    uint16_t yAcc_paddle_eigenvalue_4; //100x
    uint16_t yAcc_point_1; //100x
    uint16_t yAcc_point_2; //100x
    uint16_t yAcc_point_3; //100x
    uint16_t yAcc_point_4; //100x
    uint16_t yAcc_point_5; //100x
    uint16_t yAcc_point_6; //100x
    uint16_t yAcc_point_7; //100x
    uint16_t yAcc_point_8; //100x
    uint16_t yAcc_band_1; //100x
    uint16_t yAcc_band_2; //100x
    uint16_t yAcc_band_3; //100x
    uint16_t yAcc_band_4; //100x
    uint16_t yAcc_band_5; //100x
    uint16_t yAcc_band_6; //100x
    uint16_t yAcc_band_7; //100x
    uint16_t yAcc_band_8; //100x
    uint16_t yAcc_maxpower_order; //10x
    uint16_t yAcc_total_power; //100x
    uint16_t zSpeed_channalID;
    uint16_t zSpeed_rotate_speed; //100x
    uint16_t zAcc_inside_eigenvalue; //100x
    uint16_t zAcc_outside_eigenvalue; //100x
    uint16_t zAcc_roll_eigenvalue; //100x
    uint16_t zAcc_shell_eigenvalue; //100x
    uint16_t zSpeed_point_1; //100x
    uint16_t zSpeed_point_2; //100x
    uint16_t zSpeed_point_3; //100x
    uint16_t zSpeed_point_4; //100x
    uint16_t zSpeed_point_5; //100x
    uint16_t zSpeed_point_6; //100x
    uint16_t zSpeed_point_7; //100x
    uint16_t zSpeed_point_8; //100x
    uint16_t zSpeed_band_1; //100x
    uint16_t zSpeed_band_2; //100x
    uint16_t zSpeed_band_3; //100x
    uint16_t zSpeed_band_4; //100x
    uint16_t zSpeed_band_5; //100x
    uint16_t zSpeed_band_6; //100x
    uint16_t zSpeed_band_7; //100x
    uint16_t zSpeed_band_8; //100x
    uint16_t zSpeed_maxpower_order; //10x
    uint16_t zSpeed_total_power; //100x
    uint16_t zAcc_paddle_eigenvalue_1; //100x
    uint16_t zAcc_paddle_eigenvalue_2; //100x
    uint16_t zAcc_paddle_eigenvalue_3; //100x
    uint16_t zAcc_paddle_eigenvalue_4; //100x
    uint16_t zAcc_point_1; //100x
    uint16_t zAcc_point_2; //100x
    uint16_t zAcc_point_3; //100x
    uint16_t zAcc_point_4; //100x
    uint16_t zAcc_point_5; //100x
    uint16_t zAcc_point_6; //100x
    uint16_t zAcc_point_7; //100x
    uint16_t zAcc_point_8; //100x
    uint16_t zAcc_band_1; //100x
    uint16_t zAcc_band_2; //100x
    uint16_t zAcc_band_3; //100x
    uint16_t zAcc_band_4; //100x
    uint16_t zAcc_band_5; //100x
    uint16_t zAcc_band_6; //100x
    uint16_t zAcc_band_7; //100x
    uint16_t zAcc_band_8; //100x
    uint16_t zAcc_maxpower_order; //10x
    uint16_t zAcc_total_power; //100x
    uint16_t channalx_status;
    uint16_t channaly_status;
    uint16_t channalz_status;
    uint16_t temp_status;
    uint16_t x_warning;
    uint16_t y_warning;
    uint16_t z_warning;
    uint16_t version;
    uint16_t license;
    uint16_t BPFI; //100x
    uint16_t BPFO; //100x
    uint16_t BSF;  //100x
    uint16_t FTF;  //100x
    uint16_t measue_speed; //寄存器168: 100x
    uint16_t proportion;   //100x
    uint16_t point1_gain;  //100x
    uint16_t point2_gain;  //100x
    uint16_t point3_gain;  //100x
    uint16_t point4_gain;  //100x
    uint16_t point5_gain;  //100x
    uint16_t point6_gain;  //100x
    uint16_t point7_gain;  //100x
    uint16_t point8_gain;  //100x
    uint16_t band1_startgain; //100x
    uint16_t band1_endgain; //100x
    uint16_t band2_startgain; //100x
    uint16_t band2_endgain; //100x
    uint16_t band3_startgain; //100x
    uint16_t band3_endgain; //100x
    uint16_t band4_startgain; //100x
    uint16_t band4_endgain; //100x
    uint16_t band5_startgain; //100x
    uint16_t band5_endgain; //100x
    uint16_t rollerNumber; //1x
    uint16_t rollerSize; //100x
    uint16_t bearingSize; //100x
    uint16_t alphaAngular; //100x
    uint16_t teethNumber;
    uint16_t mode;
    uint16_t target;
    uint16_t x_accWarning; //100x
    uint16_t x_accError; //100x
    uint16_t y_accWarning; //100x
    uint16_t y_accError; //100x
    uint16_t z_accWarning; //100x
    uint16_t z_accError; //100x
    uint16_t x_speedWarning; //100x
    uint16_t x_speedError; //100x
    uint16_t y_speedWarning; //100x
    uint16_t y_speedError; //100x
    uint16_t z_speedWarning; //100x
    uint16_t z_speedError; //100x
    uint16_t tempWarning; //100x
    uint16_t tempError; //100x
    uint16_t x_distanceWarning; //100x
    uint16_t x_distanceError; //100x
    uint16_t y_distanceWarning; //100x
    uint16_t y_distanceError; //100x
    uint16_t z_distanceWarning; //100x
    uint16_t z_distanceError; //100x
    uint16_t hpf_limit; //1x
    uint16_t lpf_limit; //1x
    uint16_t calcPeriod;
}JYD_OriginalData_t;

typedef union{
    JYD_OriginalData_t OriginalData;
    uint16_t JYD_DataArray[217];
}JYD_DATA_UNION;

extern JYD_OriginalData_t JYD_OriginalData;

extern ModbusClientRTU MB;

void Modbus_Init();

void Modbus_getRegisterValue(uint16_t startAddress, uint16_t dataLength);
void Modbus_configSingleRegister(uint16_t registerAddress, uint16_t value_Hex);

#endif // !__MODBUSTASK_H