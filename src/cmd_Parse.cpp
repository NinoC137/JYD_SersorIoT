#include "cmd_Parse.h"
#include "ModbusTask.h"

void wifi_cmd1(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(1));

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_speed", cJSON_CreateNumber(JYD_OriginalData.x_speed));
    cJSON_AddItemToObject(tx_root, "y_speed", cJSON_CreateNumber(JYD_OriginalData.y_speed));
    cJSON_AddItemToObject(tx_root, "z_speed", cJSON_CreateNumber(JYD_OriginalData.z_speed));
    
    char* json_string = cJSON_Print(tx_root);

    int httpCode = http.connected();
    if (httpCode == true)
    {
        http.POST(String(json_string));
        // Serial.printf("send: %s\r\n", json_string);
    }
    else
    {
        TX_Characteristics.setValue("http disconnected!");
        TX_Characteristics.notify();
        Serial.printf("http disconnected!\r\n");
    }

    cJSON_Delete(tx_root);
    free(json_string);
}

void wifi_cmd2(cJSON *root){

}

void wifi_cmd3(cJSON *root){

}

void wifi_cmd4(cJSON *root){

}

void wifi_cmd5(cJSON *root){

}

void wifi_cmd6(cJSON *root){

}

void wifi_cmd7(cJSON *root){

}

void wifi_cmd8(cJSON *root){

}

void wifi_cmd9(cJSON *root){

}

void wifi_cmd10(cJSON *root){

}

void wifi_cmd11(cJSON *root){

}

void wifi_cmd12(cJSON *root){

}

void wifi_cmd13(cJSON *root){

}

void wifi_cmd15(cJSON *root){

}

void wifi_cmd16(cJSON *root){

}

void wifi_cmd14(cJSON *root){

}

void wifi_cmd17(cJSON *root){

}

void wifi_cmd18(cJSON *root){

}

void wifi_cmd19(cJSON *root){

}

void wifi_cmd20(cJSON *root){

}

void wifi_cmd21(cJSON *root){

}

//设定WiFi账号与密码
void ble_cmd1(cJSON *root)
{
    cJSON *cmd_ssid = cJSON_GetObjectItem(root, "ssid");//提取出ssid和psw字段
    cJSON *cmd_psw = cJSON_GetObjectItem(root, "psw");

    if (cmd_ssid == NULL ||cmd_psw== NULL)
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    // BLE_Data.WiFi_store[cmd_idx->valueint].SSID = cmd_ssid->valuestring;
    WiFi_Data.WiFi_store[0].SSID = cmd_ssid->valuestring;
    WiFi_Data.WiFi_store[0].PassWord = cmd_psw->valuestring;
    WiFi.begin(WiFi_Data.WiFi_store[0].SSID, WiFi_Data.WiFi_store[0].PassWord);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(1));

    char* json_string = cJSON_Print(tx_root);
    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);

}

//设定设备时区
void ble_cmd2(cJSON *root)
{
    cJSON *cmd_timezone = cJSON_GetObjectItem(root, "timezone");//提取出timezone字段

    if (cmd_timezone == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    my_timezone = cmd_timezone->valueint;
    gmtOffset_sec = my_timezone * 3600;
    updateLocalTime();

    //if (strcmp(timezone->valuestring, "8") == 0) {
        // 如果符合预期，则设置响应消息

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(2));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//查询设备时区
void ble_cmd3(cJSON *root)
{
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(3));
    cJSON_AddItemToObject(tx_root, "timezone", cJSON_CreateNumber(my_timezone));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//设定服务器url地址
void ble_cmd4(cJSON *root)
{
    cJSON *cmd_serverip = cJSON_GetObjectItem(root, "serverip");//提取出serverip字段
    cJSON *cmd_serverport = cJSON_GetObjectItem(root, "serverport");//提取出serverport字段

    if (cmd_serverip == NULL || cmd_serverport == NULL)
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    WiFi_Data.serverip = cmd_serverip->valuestring;
    WiFi_Data.serverport = cmd_serverport->valueint;

    std::stringstream urlStream;
    urlStream << "http://" << WiFi_Data.serverip << ":" << WiFi_Data.serverport;

    http.begin(urlStream.str().c_str()); // 连接服务器对应域名

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(4));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//读取服务器设置
void ble_cmd5(cJSON *root)
{
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(5));
    cJSON_AddItemToObject(tx_root, "serverip", cJSON_CreateString(WiFi_Data.serverip.c_str()));
    cJSON_AddItemToObject(tx_root, "serverport", cJSON_CreateNumber(WiFi_Data.serverport));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);

}

//设置心跳包
void ble_cmd6(cJSON *root)
{
    cJSON *cmd_keepalivetime = cJSON_GetObjectItem(root, "keepalivetime");

    if (cmd_keepalivetime == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    HeartBeat.keepAliveTime = cmd_keepalivetime->valueint;

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(6));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//读取心跳包
void ble_cmd7(cJSON *root)
{
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(6));
    cJSON_AddItemToObject(tx_root, "keepalivetime", cJSON_CreateNumber(HeartBeat.keepAliveTime));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器参数
void ble_cmd8(cJSON *root)
{
    cJSON *cmd_key = cJSON_GetObjectItem(root, "key");

    if (cmd_key == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(160, cmd_key->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(8));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//修改传感器运行模式
void ble_cmd9(cJSON *root)
{
    cJSON *cmd_mode = cJSON_GetObjectItem(root, "mode");

    if (cmd_mode == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(160, cmd_mode->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(9));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器modbus从机地址
void ble_cmd10(cJSON *root)
{
    cJSON *cmd_address = cJSON_GetObjectItem(root, "address");

    if (cmd_address == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(162, cmd_address->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(10));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器串口波特率
void ble_cmd11(cJSON *root)
{
    cJSON *cmd_baudrate = cJSON_GetObjectItem(root, "baudrate");

    if (cmd_baudrate == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(164, cmd_baudrate->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(11));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器速度高通截止频率
void ble_cmd12(cJSON *root)
{
    cJSON *cmd_speed_hpf = cJSON_GetObjectItem(root, "speed_hpf");

    if (cmd_speed_hpf == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(164, cmd_speed_hpf->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(12));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器速度低通截止频率
void ble_cmd13(cJSON *root)
{
    cJSON *cmd_speed_lpf = cJSON_GetObjectItem(root, "speed_lpf");

    if (cmd_speed_lpf == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(165, cmd_speed_lpf->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(13));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器加速度高通截止频率
void ble_cmd14(cJSON *root)
{
    cJSON *cmd_acc_hpf = cJSON_GetObjectItem(root, "acc_hpf");

    if (cmd_acc_hpf == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(166, cmd_acc_hpf->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(14));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//配置传感器加速度低通截止频率
void ble_cmd15(cJSON *root)
{
    cJSON *cmd_acc_lpf = cJSON_GetObjectItem(root, "acc_lpf");

    if (cmd_acc_lpf == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(167, cmd_acc_lpf->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(15));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//入传感器的转速测量值与传动比
void ble_cmd16(cJSON *root)
{
    cJSON *cmd_measue_speed = cJSON_GetObjectItem(root, "measue_speed");
    cJSON *cmd_proportion = cJSON_GetObjectItem(root, "proportion");

    if (cmd_measue_speed == NULL ||cmd_proportion == NULL)
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(169, cmd_measue_speed->valueint);
    Modbus_configSingleRegister(170, cmd_proportion->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(16));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//写入传感器各关注点的转频倍数与关注带起始+结束点转频倍数
void ble_cmd17(cJSON *root)
{
    cJSON *cmd_point1_gain = cJSON_GetObjectItem(root, "point1_gain");
    cJSON *cmd_band1_startgain = cJSON_GetObjectItem(root, "band1_startgain");
    cJSON *cmd_band1_endgain = cJSON_GetObjectItem(root, "band1_endgain");

    if (cmd_point1_gain == NULL || cmd_band1_startgain == NULL ||cmd_band1_endgain == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    //定义一个数组存储point[i]_gain
    static uint16_t point_gain[8];

    for (int i = 0;i <= 8; i++)
    {
        char key[12];
        sprintf(key,"point%d_gain",i+1);
        cJSON *cmd_point_gain = cJSON_GetObjectItem(root, key);
        if (cmd_point_gain != NULL )
        {
            point_gain[i] = cmd_point_gain->valueint;
        }
    }

    //定义一个数组存储band[i]_startgain
    static uint16_t band_startgain[5];
    static uint16_t band_endgain[5];

    for (int i = 1;i <= 5; i++)
    {
        char key1[12];
        char key2[12];
        sprintf(key1,"band%d_startgain",i);
        sprintf(key2,"band%d_endgain",i);
        cJSON *cmd_band_endgain = cJSON_GetObjectItem(root, key1);
        cJSON *cmd_band_startgain = cJSON_GetObjectItem(root, key2);
        if (cmd_band_startgain != NULL )
        {
            band_startgain[i] = cmd_band_startgain->valueint;
        }
        if (cmd_band_endgain != NULL )
        {
            band_endgain[i] = cmd_band_endgain->valueint;
        }
    }

    uint16_t value_send[17];
    int j = 0;
    for(j; j < 8 ; j++){
        value[j] = point_gain[j];
    }

    for(int f = 0; f < 5; f += 2){
        value[f+8] = band_startgain[f];
        value[f+8+1] = band_endgain[f];
    }

    int index = 171;
    for(index; index <= 187; index++){
        Modbus_configSingleRegister(index, value[index-171]);
    }

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(17));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//写入滚动体个数, 滚动体直径与轴承节径
void ble_cmd18(cJSON *root)
{
    cJSON *cmd_rollerNumber = cJSON_GetObjectItem(root, "rollerNumber");
    cJSON *cmd_rollerSize = cJSON_GetObjectItem(root, "rollerSize");
    cJSON *cmd_bearingSize = cJSON_GetObjectItem(root, "bearingSize");

    if (cmd_rollerNumber == NULL ||cmd_rollerSize == NULL || cmd_bearingSize == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(188, cmd_rollerNumber->valueint);
    Modbus_configSingleRegister(189, cmd_rollerSize->valueint);
    Modbus_configSingleRegister(190, cmd_bearingSize->valueint);


    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(18));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//写入alpha接触角与叶片数/输入侧齿数
void ble_cmd19(cJSON *root)
{
    cJSON *cmd_alphaAngular = cJSON_GetObjectItem(root, "alphaAngular");
    cJSON *cmd_teethNumber = cJSON_GetObjectItem(root, "teethNumber");


    if (cmd_alphaAngular == NULL ||cmd_teethNumber == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(191, cmd_alphaAngular->valueint);
    Modbus_configSingleRegister(192, cmd_teethNumber->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(19));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//写入当前的诊断场景与诊断类型
void ble_cmd20(cJSON *root)
{
    cJSON *cmd_mode = cJSON_GetObjectItem(root, "mode");
    cJSON *cmd_target = cJSON_GetObjectItem(root, "target");

    if (cmd_mode == NULL ||cmd_target == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(193, cmd_mode->valueint);
    Modbus_configSingleRegister(194, cmd_target->valueint);


    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(20));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//获取各类预警与报警门限
void ble_cmd21(cJSON *root)
{
    cJSON *cmd_x_accWarning = cJSON_GetObjectItem(root, "x_accWarning");
    cJSON *cmd_x_accError = cJSON_GetObjectItem(root, "x_accError");
    cJSON *cmd_y_accWarning = cJSON_GetObjectItem(root, "y_accWarning");
    cJSON *cmd_y_accError = cJSON_GetObjectItem(root, "y_accError");
    cJSON *cmd_z_accWarning = cJSON_GetObjectItem(root, "z_accWarning");
    cJSON *cmd_z_accError = cJSON_GetObjectItem(root, "z_accError");
    cJSON *cmd_x_speedWarning = cJSON_GetObjectItem(root, "x_speedWarning");
    cJSON *cmd_x_speedError = cJSON_GetObjectItem(root, "x_speedError");
    cJSON *cmd_y_speedWarning = cJSON_GetObjectItem(root, "y_speedWarning");
    cJSON *cmd_y_speedError = cJSON_GetObjectItem(root, "y_speedError");
    cJSON *cmd_z_speedWarning = cJSON_GetObjectItem(root, "z_speedWarning");
    cJSON *cmd_z_speedError = cJSON_GetObjectItem(root, "z_speedError");
    cJSON *cmd_tempWarning = cJSON_GetObjectItem(root, "tempWarning");
    cJSON *cmd_tempError = cJSON_GetObjectItem(root, "tempError");
    cJSON *cmd_x_distanceWarning = cJSON_GetObjectItem(root, "x_distanceWarning");
    cJSON *cmd_x_distanceError = cJSON_GetObjectItem(root, "x_distanceError");
    cJSON *cmd_y_distanceWarning = cJSON_GetObjectItem(root, "y_distanceWarning");
    cJSON *cmd_y_distanceError = cJSON_GetObjectItem(root, "y_distanceError");
    cJSON *cmd_z_distanceWarning = cJSON_GetObjectItem(root, "z_distanceWarning");
    cJSON *cmd_z_distanceError = cJSON_GetObjectItem(root, "z_distanceError");

    if (cmd_x_accWarning == NULL || cmd_x_accError == NULL ||
        cmd_y_accWarning == NULL || cmd_y_accError == NULL ||
        cmd_z_accWarning == NULL || cmd_z_accError == NULL ||
        cmd_x_speedWarning == NULL || cmd_x_speedError == NULL ||
        cmd_y_speedWarning == NULL || cmd_y_speedError == NULL ||
        cmd_z_speedWarning == NULL || cmd_z_speedError == NULL ||
        cmd_tempWarning == NULL || cmd_tempError == NULL ||
        cmd_x_distanceWarning == NULL || cmd_x_distanceError == NULL ||
        cmd_y_distanceWarning == NULL || cmd_y_distanceError == NULL ||
        cmd_z_distanceWarning == NULL || cmd_z_distanceError == NULL)
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    uint16_t x_accWarning = cmd_x_accWarning->valueint;
    Modbus_configSingleRegister(195, x_accWarning);
    uint16_t x_accError = cmd_x_accError->valueint;
    Modbus_configSingleRegister(196, x_accError);
    uint16_t y_accWarning = cmd_y_accWarning->valueint;
    Modbus_configSingleRegister(197, y_accWarning);
    uint16_t y_accError = cmd_y_accError->valueint;
    Modbus_configSingleRegister(198, y_accError);
    uint16_t z_accWarning = cmd_z_accWarning->valueint;
    Modbus_configSingleRegister(199, z_accWarning);
    uint16_t z_accError = cmd_z_accError->valueint;
    Modbus_configSingleRegister(200, z_accError);
    uint16_t x_speedWarning = cmd_x_speedWarning->valueint;
    Modbus_configSingleRegister(201, x_speedWarning);
    uint16_t x_speedError = cmd_x_speedError->valueint;
    Modbus_configSingleRegister(202, x_speedError);
    uint16_t y_speedWarning = cmd_y_speedWarning->valueint;
    Modbus_configSingleRegister(203, y_speedWarning);
    uint16_t y_speedError = cmd_y_speedError->valueint;
    Modbus_configSingleRegister(204, y_speedError);
    uint16_t z_speedWarning = cmd_z_speedWarning->valueint;
    Modbus_configSingleRegister(205, z_speedWarning);
    uint16_t z_speedError = cmd_z_speedError->valueint;
    Modbus_configSingleRegister(206, z_speedError);
    uint16_t tempWarning = cmd_tempWarning->valueint;
    Modbus_configSingleRegister(207, tempWarning);
    uint16_t tempError = cmd_tempError->valueint;
    Modbus_configSingleRegister(208, tempError);
    uint16_t x_distanceWarning = cmd_x_distanceWarning->valueint;
    Modbus_configSingleRegister(209, x_distanceWarning);
    uint16_t x_distanceError = cmd_x_distanceError->valueint;
    Modbus_configSingleRegister(210, x_distanceError);
    uint16_t y_distanceWarning = cmd_y_distanceWarning->valueint;
    Modbus_configSingleRegister(211, y_distanceWarning);
    uint16_t y_distanceError = cmd_y_distanceError->valueint;
    Modbus_configSingleRegister(212, y_distanceError);
    uint16_t z_distanceWarning = cmd_z_distanceWarning->valueint;
    Modbus_configSingleRegister(213, z_distanceWarning);
    uint16_t z_distanceError = cmd_z_distanceError->valueint;
    Modbus_configSingleRegister(214, z_distanceError);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(21));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}

//获取振动位移的高通,低通截止频率与时域数据计算周期
void ble_cmd22(cJSON *root)
{
    cJSON *cmd_hpf_limit = cJSON_GetObjectItem(root, "hpf_limit");
    cJSON *cmd_lpf_limit = cJSON_GetObjectItem(root, "lpf_limit");
    cJSON *cmd_calcPeriod = cJSON_GetObjectItem(root, "calcPeriod");

    if (cmd_hpf_limit == NULL ||cmd_lpf_limit == NULL || cmd_calcPeriod == NULL )
    {
        TX_Characteristics.setValue("json string error!!");
        TX_Characteristics.notify();
        return;
    }

    Modbus_configSingleRegister(215, cmd_hpf_limit->valueint);
    Modbus_configSingleRegister(216, cmd_lpf_limit->valueint);
    Modbus_configSingleRegister(217, cmd_calcPeriod->valueint);

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(22));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}