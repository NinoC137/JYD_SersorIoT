#include "cmd_Parse.h"
#include "ModbusTask.h"

void wifi_cmd1(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(1));

    float real_xSpeed, real_ySpeed, real_zSpeed;
    real_xSpeed = JYD_OriginalData.x_speed/100;
    real_ySpeed = JYD_OriginalData.y_speed/100;
    real_zSpeed = JYD_OriginalData.z_speed/100;
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_speed", cJSON_CreateNumber(real_xSpeed));
    cJSON_AddItemToObject(tx_root, "y_speed", cJSON_CreateNumber(real_ySpeed));
    cJSON_AddItemToObject(tx_root, "z_speed", cJSON_CreateNumber(real_zSpeed));
    
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
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(2));

    float real_temp;
    real_temp = JYD_OriginalData.temp/100;
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "temp", cJSON_CreateNumber(real_temp));
    
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

void wifi_cmd3(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(3));

    float real_xacc,real_yacc,real_zacc;
    real_xacc = JYD_OriginalData.x_acc/100;
    real_yacc = JYD_OriginalData.y_acc/100;
    real_zacc = JYD_OriginalData.z_acc/100;
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_acc", cJSON_CreateNumber(real_xacc));
    cJSON_AddItemToObject(tx_root, "y_acc", cJSON_CreateNumber(real_yacc));
    cJSON_AddItemToObject(tx_root, "z_acc", cJSON_CreateNumber(real_zacc));
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

void wifi_cmd4(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(4));

    float real_xspeedmax,real_xspeedkrt,real_xaccmax,real_xacckrt;
    float real_yspeedmax,real_yspeedkrt,real_yaccmax,real_yacckrt;
    float real_zspeedmax,real_zspeedkrt,real_zaccmax,real_zacckrt;
    real_xspeedmax = JYD_OriginalData.x_speedmax/100;
    real_xspeedkrt = JYD_OriginalData.x_speedkrt/100;
    real_xaccmax = JYD_OriginalData.x_accmax/100;
    real_xacckrt = JYD_OriginalData.x_acckrt/100;
    real_yspeedmax = JYD_OriginalData.y_speedmax/100;
    real_yspeedkrt = JYD_OriginalData.y_speedkrt/100;
    real_yaccmax = JYD_OriginalData.y_accmax/100;
    real_yacckrt = JYD_OriginalData.y_acckrt/100;
    real_zspeedmax = JYD_OriginalData.z_speedmax/100;
    real_zspeedkrt = JYD_OriginalData.z_speedkrt/100;
    real_zaccmax = JYD_OriginalData.z_accmax/100;
    real_zacckrt = JYD_OriginalData.z_acckrt/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_speedmax", cJSON_CreateNumber(real_xspeedmax));
    cJSON_AddItemToObject(tx_root, "x_speedkrt", cJSON_CreateNumber(real_xspeedkrt));
    cJSON_AddItemToObject(tx_root, "x_accmax", cJSON_CreateNumber(real_xaccmax));
    cJSON_AddItemToObject(tx_root, "x_acckrt", cJSON_CreateNumber(real_xacckrt));
    cJSON_AddItemToObject(tx_root, "y_speedmax", cJSON_CreateNumber(real_yspeedmax));
    cJSON_AddItemToObject(tx_root, "y_speedkrt", cJSON_CreateNumber(real_yspeedkrt));
    cJSON_AddItemToObject(tx_root, "y_accmax", cJSON_CreateNumber(real_yaccmax));
    cJSON_AddItemToObject(tx_root, "y_acckrt", cJSON_CreateNumber(real_yacckrt));
    cJSON_AddItemToObject(tx_root, "z_speedmax", cJSON_CreateNumber(real_zspeedmax));
    cJSON_AddItemToObject(tx_root, "z_speedkrt", cJSON_CreateNumber(real_zspeedkrt));
    cJSON_AddItemToObject(tx_root, "z_accmax", cJSON_CreateNumber(real_zaccmax));
    cJSON_AddItemToObject(tx_root, "z_acckrt", cJSON_CreateNumber(real_zacckrt));
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

void wifi_cmd5(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(5));

    float real_xdispeek,real_ydispeek,real_zdispeek;
    real_xdispeek = JYD_OriginalData.x_dispeek/1;
    real_ydispeek = JYD_OriginalData.y_dispeek/1;
    real_zdispeek = JYD_OriginalData.z_dispeek/1;
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_dispeek", cJSON_CreateNumber(real_xdispeek));
    cJSON_AddItemToObject(tx_root, "y_dispeek", cJSON_CreateNumber(real_ydispeek));
    cJSON_AddItemToObject(tx_root, "z_dispeek", cJSON_CreateNumber(real_zdispeek));
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

void wifi_cmd6(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(6));

    float real_fftcount,real_xSpeed_channalID,real_xSpeed_rotate_speed,real_xAcc_inside_eigenvalue,real_xAcc_outside_eigenvalue,real_xAcc_roll_eigenvalue,real_xAcc_shell_eigenvalue;
    float real_xAcc_point_1,real_xAcc_point_2,real_xAcc_point_3,real_xAcc_point_4,real_xAcc_point_5,real_xAcc_point_6,real_xAcc_point_7,real_xAcc_point_8;
    float real_xAcc_band_1,real_xAcc_band_2,real_xAcc_band_3,real_xAcc_band_4,real_xAcc_band_5;
    float real_xAcc_maxpower_order,real_xAcc_total_power;
    real_fftcount = JYD_OriginalData.fft_count/1;
    real_xSpeed_channalID = JYD_OriginalData.xSpeed_channalID/1;
    real_xSpeed_rotate_speed = JYD_OriginalData.xSpeed_rotate_speed/100;
    real_xAcc_inside_eigenvalue = JYD_OriginalData.xAcc_inside_eigenvalue/100;
    real_xAcc_outside_eigenvalue = JYD_OriginalData.xAcc_outside_eigenvalue/100;
    real_xAcc_roll_eigenvalue = JYD_OriginalData.xAcc_roll_eigenvalue/100;
    real_xAcc_shell_eigenvalue = JYD_OriginalData.xAcc_shell_eigenvalue/100;
    real_xAcc_point_1 = JYD_OriginalData.xAcc_point_1/100;
    real_xAcc_point_2 = JYD_OriginalData.xAcc_point_2/100;
    real_xAcc_point_3 = JYD_OriginalData.xAcc_point_3/100;
    real_xAcc_point_4 = JYD_OriginalData.xAcc_point_4/100;
    real_xAcc_point_5 = JYD_OriginalData.xAcc_point_5/100;
    real_xAcc_point_6 = JYD_OriginalData.xAcc_point_6/100;
    real_xAcc_point_7 = JYD_OriginalData.xAcc_point_7/100;
    real_xAcc_point_8 = JYD_OriginalData.xAcc_point_8/100;
    real_xAcc_band_1 = JYD_OriginalData.xAcc_band_1/100;
    real_xAcc_band_2 = JYD_OriginalData.xAcc_band_2/100;
    real_xAcc_band_3 = JYD_OriginalData.xAcc_band_3/100;
    real_xAcc_band_4 = JYD_OriginalData.xAcc_band_4/100;
    real_xAcc_band_5 = JYD_OriginalData.xAcc_band_5/100;
    real_xAcc_maxpower_order = JYD_OriginalData.xAcc_maxpower_order/10;
    real_xAcc_total_power = JYD_OriginalData.xAcc_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "fft_count", cJSON_CreateNumber(real_fftcount));
    cJSON_AddItemToObject(tx_root, "xSpeed_channalID", cJSON_CreateNumber(real_xSpeed_channalID));
    cJSON_AddItemToObject(tx_root, "xSpeed_rotate_speed", cJSON_CreateNumber(real_xSpeed_rotate_speed));
    cJSON_AddItemToObject(tx_root, "xAcc_inside_eigenvalue", cJSON_CreateNumber(real_xAcc_inside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "xAcc_outside_eigenvalue", cJSON_CreateNumber(real_xAcc_outside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "xAcc_roll_eigenvalue", cJSON_CreateNumber(real_xAcc_roll_eigenvalue));
    cJSON_AddItemToObject(tx_root, "xAcc_shell_eigenvalue", cJSON_CreateNumber(real_xAcc_shell_eigenvalue));
    cJSON_AddItemToObject(tx_root, "xAcc_point_1", cJSON_CreateNumber(real_xAcc_point_1));
    cJSON_AddItemToObject(tx_root, "xAcc_point_2", cJSON_CreateNumber(real_xAcc_point_2));
    cJSON_AddItemToObject(tx_root, "xAcc_point_3", cJSON_CreateNumber(real_xAcc_point_3));
    cJSON_AddItemToObject(tx_root, "xAcc_point_4", cJSON_CreateNumber(real_xAcc_point_4));
    cJSON_AddItemToObject(tx_root, "xAcc_point_5", cJSON_CreateNumber(real_xAcc_point_5));
    cJSON_AddItemToObject(tx_root, "xAcc_point_6", cJSON_CreateNumber(real_xAcc_point_6));
    cJSON_AddItemToObject(tx_root, "xAcc_point_7", cJSON_CreateNumber(real_xAcc_point_7));
    cJSON_AddItemToObject(tx_root, "xAcc_point_8", cJSON_CreateNumber(real_xAcc_point_8));
    cJSON_AddItemToObject(tx_root, "xAcc_band_1", cJSON_CreateNumber(real_xAcc_band_1));
    cJSON_AddItemToObject(tx_root, "xAcc_band_2", cJSON_CreateNumber(real_xAcc_band_2));
    cJSON_AddItemToObject(tx_root, "xAcc_band_3", cJSON_CreateNumber(real_xAcc_band_3));
    cJSON_AddItemToObject(tx_root, "xAcc_band_4", cJSON_CreateNumber(real_xAcc_band_4));
    cJSON_AddItemToObject(tx_root, "xAcc_band_5", cJSON_CreateNumber(real_xAcc_band_5));
    cJSON_AddItemToObject(tx_root, "xAcc_maxpower_order", cJSON_CreateNumber(real_xAcc_maxpower_order));
    cJSON_AddItemToObject(tx_root, "xAcc_total_power", cJSON_CreateNumber(real_xAcc_total_power));

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

void wifi_cmd7(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(7));

    float real_xSpeed_paddle_eigenvalue_1,real_xSpeed_paddle_eigenvalue_2,real_xSpeed_paddle_eigenvalue_3,real_xSpeed_paddle_eigenvalue_4;
    float real_xSpeed_point_1,real_xSpeed_point_2,real_xSpeed_point_3,real_xSpeed_point_4,real_xSpeed_point_5,real_xSpeed_point_6,real_xSpeed_point_7,real_xSpeed_point_8;
    float real_xSpeed_band_1,real_xSpeed_band_2,real_xSpeed_band_3,real_xSpeed_band_4,real_xSpeed_band_5;
    float real_xSpeed_maxpower_order,real_xSpeed_total_power;

    real_xSpeed_paddle_eigenvalue_1 = JYD_OriginalData.xSpeed_paddle_eigenvalue_1/100;
    real_xSpeed_paddle_eigenvalue_2 = JYD_OriginalData.xSpeed_paddle_eigenvalue_2/100;
    real_xSpeed_paddle_eigenvalue_3 = JYD_OriginalData.xSpeed_paddle_eigenvalue_3/100;
    real_xSpeed_paddle_eigenvalue_4 = JYD_OriginalData.xSpeed_paddle_eigenvalue_4/100;
    real_xSpeed_point_1 = JYD_OriginalData.xSpeed_point_1/100;
    real_xSpeed_point_2 = JYD_OriginalData.xSpeed_point_2/100;
    real_xSpeed_point_3 = JYD_OriginalData.xSpeed_point_3/100;
    real_xSpeed_point_4 = JYD_OriginalData.xSpeed_point_4/100;
    real_xSpeed_point_5 = JYD_OriginalData.xSpeed_point_5/100;
    real_xSpeed_point_6 = JYD_OriginalData.xSpeed_point_6/100;
    real_xSpeed_point_7 = JYD_OriginalData.xSpeed_point_7/100;
    real_xSpeed_point_8 = JYD_OriginalData.xSpeed_point_8/100;
    real_xSpeed_band_1 = JYD_OriginalData.xSpeed_band_1/100;
    real_xSpeed_band_2 = JYD_OriginalData.xSpeed_band_2/100;
    real_xSpeed_band_3 = JYD_OriginalData.xSpeed_band_3/100;
    real_xSpeed_band_4 = JYD_OriginalData.xSpeed_band_4/100;
    real_xSpeed_band_5 = JYD_OriginalData.xSpeed_band_5/100;
    real_xSpeed_maxpower_order = JYD_OriginalData.xSpeed_maxpower_order/10;
    real_xSpeed_total_power = JYD_OriginalData.xSpeed_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "xSpeed_paddle_eigenvalue_1", cJSON_CreateNumber(real_xSpeed_paddle_eigenvalue_1));
    cJSON_AddItemToObject(tx_root, "xSpeed_paddle_eigenvalue_2", cJSON_CreateNumber(real_xSpeed_paddle_eigenvalue_2));
    cJSON_AddItemToObject(tx_root, "xSpeed_paddle_eigenvalue_3", cJSON_CreateNumber(real_xSpeed_paddle_eigenvalue_3));
    cJSON_AddItemToObject(tx_root, "xSpeed_paddle_eigenvalue_4", cJSON_CreateNumber(real_xSpeed_paddle_eigenvalue_4));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_1", cJSON_CreateNumber(real_xSpeed_point_1));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_2", cJSON_CreateNumber(real_xSpeed_point_2));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_3", cJSON_CreateNumber(real_xSpeed_point_3));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_4", cJSON_CreateNumber(real_xSpeed_point_4));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_5", cJSON_CreateNumber(real_xSpeed_point_5));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_6", cJSON_CreateNumber(real_xSpeed_point_6));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_7", cJSON_CreateNumber(real_xSpeed_point_7));
    cJSON_AddItemToObject(tx_root, "xSpeed_point_8", cJSON_CreateNumber(real_xSpeed_point_8));
    cJSON_AddItemToObject(tx_root, "xSpeed_band_1", cJSON_CreateNumber(real_xSpeed_band_1));
    cJSON_AddItemToObject(tx_root, "xSpeed_band_2", cJSON_CreateNumber(real_xSpeed_band_2));
    cJSON_AddItemToObject(tx_root, "xSpeed_band_3", cJSON_CreateNumber(real_xSpeed_band_3));
    cJSON_AddItemToObject(tx_root, "xSpeed_band_4", cJSON_CreateNumber(real_xSpeed_band_4));
    cJSON_AddItemToObject(tx_root, "xSpeed_band_5", cJSON_CreateNumber(real_xSpeed_band_5));
    cJSON_AddItemToObject(tx_root, "xSpeed_maxpower_order", cJSON_CreateNumber(real_xSpeed_maxpower_order));
    cJSON_AddItemToObject(tx_root, "xSpeed_total_power", cJSON_CreateNumber(real_xSpeed_total_power));

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

void wifi_cmd8(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(8));

    float real_ySpeed_channalID,real_ySpeed_rotate_speed,real_yAcc_inside_eigenvalue,real_yAcc_outside_eigenvalue,real_yAcc_roll_eigenvalue,real_yAcc_shell_eigenvalue;
    float real_yAcc_point_1,real_yAcc_point_2,real_yAcc_point_3,real_yAcc_point_4,real_yAcc_point_5,real_yAcc_point_6,real_yAcc_point_7,real_yAcc_point_8;
    float real_yAcc_band_1,real_yAcc_band_2,real_yAcc_band_3,real_yAcc_band_4,real_yAcc_band_5;
    float real_yAcc_maxpower_order,real_yAcc_total_power;
    
    real_ySpeed_channalID = JYD_OriginalData.ySpeed_channalID/2;
    real_ySpeed_rotate_speed = JYD_OriginalData.ySpeed_rotate_speed/100;
    real_yAcc_inside_eigenvalue = JYD_OriginalData.yAcc_inside_eigenvalue/100;
    real_yAcc_outside_eigenvalue = JYD_OriginalData.yAcc_outside_eigenvalue/100;
    real_yAcc_roll_eigenvalue = JYD_OriginalData.yAcc_roll_eigenvalue/100;
    real_yAcc_shell_eigenvalue = JYD_OriginalData.yAcc_shell_eigenvalue/100;
    real_yAcc_point_1 = JYD_OriginalData.yAcc_point_1/100;
    real_yAcc_point_2 = JYD_OriginalData.yAcc_point_2/100;
    real_yAcc_point_3 = JYD_OriginalData.yAcc_point_3/100;
    real_yAcc_point_4 = JYD_OriginalData.yAcc_point_4/100;
    real_yAcc_point_5 = JYD_OriginalData.yAcc_point_5/100;
    real_yAcc_point_6 = JYD_OriginalData.yAcc_point_6/100;
    real_yAcc_point_7 = JYD_OriginalData.yAcc_point_7/100;
    real_yAcc_point_8 = JYD_OriginalData.yAcc_point_8/100;
    real_yAcc_band_1 = JYD_OriginalData.yAcc_band_1/100;
    real_yAcc_band_2 = JYD_OriginalData.yAcc_band_2/100;
    real_yAcc_band_3 = JYD_OriginalData.yAcc_band_3/100;
    real_yAcc_band_4 = JYD_OriginalData.yAcc_band_4/100;
    real_yAcc_band_5 = JYD_OriginalData.yAcc_band_5/100;
    real_yAcc_maxpower_order = JYD_OriginalData.yAcc_maxpower_order/10;
    real_yAcc_total_power = JYD_OriginalData.yAcc_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "ySpeed_channalID", cJSON_CreateNumber(real_ySpeed_channalID));
    cJSON_AddItemToObject(tx_root, "ySpeed_rotate_speed", cJSON_CreateNumber(real_ySpeed_rotate_speed));
    cJSON_AddItemToObject(tx_root, "yAcc_inside_eigenvalue", cJSON_CreateNumber(real_yAcc_inside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "yAcc_outside_eigenvalue", cJSON_CreateNumber(real_yAcc_outside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "yAcc_roll_eigenvalue", cJSON_CreateNumber(real_yAcc_roll_eigenvalue));
    cJSON_AddItemToObject(tx_root, "yAcc_shell_eigenvalue", cJSON_CreateNumber(real_yAcc_shell_eigenvalue));
    cJSON_AddItemToObject(tx_root, "yAcc_point_1", cJSON_CreateNumber(real_yAcc_point_1));
    cJSON_AddItemToObject(tx_root, "yAcc_point_2", cJSON_CreateNumber(real_yAcc_point_2));
    cJSON_AddItemToObject(tx_root, "yAcc_point_3", cJSON_CreateNumber(real_yAcc_point_3));
    cJSON_AddItemToObject(tx_root, "yAcc_point_4", cJSON_CreateNumber(real_yAcc_point_4));
    cJSON_AddItemToObject(tx_root, "yAcc_point_5", cJSON_CreateNumber(real_yAcc_point_5));
    cJSON_AddItemToObject(tx_root, "yAcc_point_6", cJSON_CreateNumber(real_yAcc_point_6));
    cJSON_AddItemToObject(tx_root, "yAcc_point_7", cJSON_CreateNumber(real_yAcc_point_7));
    cJSON_AddItemToObject(tx_root, "yAcc_point_8", cJSON_CreateNumber(real_yAcc_point_8));
    cJSON_AddItemToObject(tx_root, "yAcc_band_1", cJSON_CreateNumber(real_yAcc_band_1));
    cJSON_AddItemToObject(tx_root, "yAcc_band_2", cJSON_CreateNumber(real_yAcc_band_2));
    cJSON_AddItemToObject(tx_root, "yAcc_band_3", cJSON_CreateNumber(real_yAcc_band_3));
    cJSON_AddItemToObject(tx_root, "yAcc_band_4", cJSON_CreateNumber(real_yAcc_band_4));
    cJSON_AddItemToObject(tx_root, "yAcc_band_5", cJSON_CreateNumber(real_yAcc_band_5));
    cJSON_AddItemToObject(tx_root, "yAcc_maxpower_order", cJSON_CreateNumber(real_yAcc_maxpower_order));
    cJSON_AddItemToObject(tx_root, "yAcc_total_power", cJSON_CreateNumber(real_yAcc_total_power));

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

void wifi_cmd9(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(9));

    float real_ySpeed_paddle_eigenvalue_1,real_ySpeed_paddle_eigenvalue_2,real_ySpeed_paddle_eigenvalue_3,real_ySpeed_paddle_eigenvalue_4;
    float real_ySpeed_point_1,real_ySpeed_point_2,real_ySpeed_point_3,real_ySpeed_point_4,real_ySpeed_point_5,real_ySpeed_point_6,real_ySpeed_point_7,real_ySpeed_point_8;
    float real_ySpeed_band_1,real_ySpeed_band_2,real_ySpeed_band_3,real_ySpeed_band_4,real_ySpeed_band_5;
    float real_ySpeed_maxpower_order,real_ySpeed_total_power;

    real_ySpeed_paddle_eigenvalue_1 = JYD_OriginalData.yAcc_paddle_eigenvalue_1/100;
    real_ySpeed_paddle_eigenvalue_2 = JYD_OriginalData.yAcc_paddle_eigenvalue_2/100;
    real_ySpeed_paddle_eigenvalue_3 = JYD_OriginalData.yAcc_paddle_eigenvalue_3/100;
    real_ySpeed_paddle_eigenvalue_4 = JYD_OriginalData.yAcc_paddle_eigenvalue_4/100;
    real_ySpeed_point_1 = JYD_OriginalData.ySpeed_point_1/100;
    real_ySpeed_point_2 = JYD_OriginalData.ySpeed_point_2/100;
    real_ySpeed_point_3 = JYD_OriginalData.ySpeed_point_3/100;
    real_ySpeed_point_4 = JYD_OriginalData.ySpeed_point_4/100;
    real_ySpeed_point_5 = JYD_OriginalData.ySpeed_point_5/100;
    real_ySpeed_point_6 = JYD_OriginalData.ySpeed_point_6/100;
    real_ySpeed_point_7 = JYD_OriginalData.ySpeed_point_7/100;
    real_ySpeed_point_8 = JYD_OriginalData.ySpeed_point_8/100;
    real_ySpeed_band_1 = JYD_OriginalData.ySpeed_band_1/100;
    real_ySpeed_band_2 = JYD_OriginalData.ySpeed_band_2/100;
    real_ySpeed_band_3 = JYD_OriginalData.ySpeed_band_3/100;
    real_ySpeed_band_4 = JYD_OriginalData.ySpeed_band_4/100;
    real_ySpeed_band_5 = JYD_OriginalData.ySpeed_band_5/100;
    real_ySpeed_maxpower_order = JYD_OriginalData.ySpeed_maxpower_order/10;
    real_ySpeed_total_power = JYD_OriginalData.ySpeed_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "ySpeed_paddle_eigenvalue_1", cJSON_CreateNumber(real_ySpeed_paddle_eigenvalue_1));
    cJSON_AddItemToObject(tx_root, "ySpeed_paddle_eigenvalue_2", cJSON_CreateNumber(real_ySpeed_paddle_eigenvalue_2));
    cJSON_AddItemToObject(tx_root, "ySpeed_paddle_eigenvalue_3", cJSON_CreateNumber(real_ySpeed_paddle_eigenvalue_3));
    cJSON_AddItemToObject(tx_root, "ySpeed_paddle_eigenvalue_4", cJSON_CreateNumber(real_ySpeed_paddle_eigenvalue_4));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_1", cJSON_CreateNumber(real_ySpeed_point_1));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_2", cJSON_CreateNumber(real_ySpeed_point_2));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_3", cJSON_CreateNumber(real_ySpeed_point_3));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_4", cJSON_CreateNumber(real_ySpeed_point_4));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_5", cJSON_CreateNumber(real_ySpeed_point_5));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_6", cJSON_CreateNumber(real_ySpeed_point_6));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_7", cJSON_CreateNumber(real_ySpeed_point_7));
    cJSON_AddItemToObject(tx_root, "ySpeed_point_8", cJSON_CreateNumber(real_ySpeed_point_8));
    cJSON_AddItemToObject(tx_root, "ySpeed_band_1", cJSON_CreateNumber(real_ySpeed_band_1));
    cJSON_AddItemToObject(tx_root, "ySpeed_band_2", cJSON_CreateNumber(real_ySpeed_band_2));
    cJSON_AddItemToObject(tx_root, "ySpeed_band_3", cJSON_CreateNumber(real_ySpeed_band_3));
    cJSON_AddItemToObject(tx_root, "ySpeed_band_4", cJSON_CreateNumber(real_ySpeed_band_4));
    cJSON_AddItemToObject(tx_root, "ySpeed_band_5", cJSON_CreateNumber(real_ySpeed_band_5));
    cJSON_AddItemToObject(tx_root, "ySpeed_maxpower_order", cJSON_CreateNumber(real_ySpeed_maxpower_order));
    cJSON_AddItemToObject(tx_root, "ySpeed_total_power", cJSON_CreateNumber(real_ySpeed_total_power));

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

void wifi_cmd10(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(10));

    float real_zSpeed_channalID,real_zSpeed_rotate_speed,real_zAcc_inside_eigenvalue,real_zAcc_outside_eigenvalue,real_zAcc_roll_eigenvalue,real_zAcc_shell_eigenvalue;
    float real_zAcc_point_1,real_zAcc_point_2,real_zAcc_point_3,real_zAcc_point_4,real_zAcc_point_5,real_zAcc_point_6,real_zAcc_point_7,real_zAcc_point_8;
    float real_zAcc_band_1,real_zAcc_band_2,real_zAcc_band_3,real_zAcc_band_4,real_zAcc_band_5;
    float real_zAcc_maxpower_order,real_zAcc_total_power;
    
    real_zSpeed_channalID = JYD_OriginalData.zSpeed_channalID/2;
    real_zSpeed_rotate_speed = JYD_OriginalData.zSpeed_rotate_speed/100;
    real_zAcc_inside_eigenvalue = JYD_OriginalData.zAcc_inside_eigenvalue/100;
    real_zAcc_outside_eigenvalue = JYD_OriginalData.zAcc_outside_eigenvalue/100;
    real_zAcc_roll_eigenvalue = JYD_OriginalData.zAcc_roll_eigenvalue/100;
    real_zAcc_shell_eigenvalue = JYD_OriginalData.zAcc_shell_eigenvalue/100;
    real_zAcc_point_1 = JYD_OriginalData.zAcc_point_1/100;
    real_zAcc_point_2 = JYD_OriginalData.zAcc_point_2/100;
    real_zAcc_point_3 = JYD_OriginalData.zAcc_point_3/100;
    real_zAcc_point_4 = JYD_OriginalData.zAcc_point_4/100;
    real_zAcc_point_5 = JYD_OriginalData.zAcc_point_5/100;
    real_zAcc_point_6 = JYD_OriginalData.zAcc_point_6/100;
    real_zAcc_point_7 = JYD_OriginalData.zAcc_point_7/100;
    real_zAcc_point_8 = JYD_OriginalData.zAcc_point_8/100;
    real_zAcc_band_1 = JYD_OriginalData.zAcc_band_1/100;
    real_zAcc_band_2 = JYD_OriginalData.zAcc_band_2/100;
    real_zAcc_band_3 = JYD_OriginalData.zAcc_band_3/100;
    real_zAcc_band_4 = JYD_OriginalData.zAcc_band_4/100;
    real_zAcc_band_5 = JYD_OriginalData.zAcc_band_5/100;
    real_zAcc_maxpower_order = JYD_OriginalData.zAcc_maxpower_order/10;
    real_zAcc_total_power = JYD_OriginalData.zAcc_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "zSpeed_channalID", cJSON_CreateNumber(real_zSpeed_channalID));
    cJSON_AddItemToObject(tx_root, "zSpeed_rotate_speed", cJSON_CreateNumber(real_zSpeed_rotate_speed));
    cJSON_AddItemToObject(tx_root, "zAcc_inside_eigenvalue", cJSON_CreateNumber(real_zAcc_inside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "zAcc_outside_eigenvalue", cJSON_CreateNumber(real_zAcc_outside_eigenvalue));
    cJSON_AddItemToObject(tx_root, "zAcc_roll_eigenvalue", cJSON_CreateNumber(real_zAcc_roll_eigenvalue));
    cJSON_AddItemToObject(tx_root, "zAcc_shell_eigenvalue", cJSON_CreateNumber(real_zAcc_shell_eigenvalue));
    cJSON_AddItemToObject(tx_root, "zAcc_point_1", cJSON_CreateNumber(real_zAcc_point_1));
    cJSON_AddItemToObject(tx_root, "zAcc_point_2", cJSON_CreateNumber(real_zAcc_point_2));
    cJSON_AddItemToObject(tx_root, "zAcc_point_3", cJSON_CreateNumber(real_zAcc_point_3));
    cJSON_AddItemToObject(tx_root, "zAcc_point_4", cJSON_CreateNumber(real_zAcc_point_4));
    cJSON_AddItemToObject(tx_root, "zAcc_point_5", cJSON_CreateNumber(real_zAcc_point_5));
    cJSON_AddItemToObject(tx_root, "zAcc_point_6", cJSON_CreateNumber(real_zAcc_point_6));
    cJSON_AddItemToObject(tx_root, "zAcc_point_7", cJSON_CreateNumber(real_zAcc_point_7));
    cJSON_AddItemToObject(tx_root, "zAcc_point_8", cJSON_CreateNumber(real_zAcc_point_8));
    cJSON_AddItemToObject(tx_root, "zAcc_band_1", cJSON_CreateNumber(real_zAcc_band_1));
    cJSON_AddItemToObject(tx_root, "zAcc_band_2", cJSON_CreateNumber(real_zAcc_band_2));
    cJSON_AddItemToObject(tx_root, "zAcc_band_3", cJSON_CreateNumber(real_zAcc_band_3));
    cJSON_AddItemToObject(tx_root, "zAcc_band_4", cJSON_CreateNumber(real_zAcc_band_4));
    cJSON_AddItemToObject(tx_root, "zAcc_band_5", cJSON_CreateNumber(real_zAcc_band_5));
    cJSON_AddItemToObject(tx_root, "zAcc_maxpower_order", cJSON_CreateNumber(real_zAcc_maxpower_order));
    cJSON_AddItemToObject(tx_root, "zAcc_total_power", cJSON_CreateNumber(real_zAcc_total_power));

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

void wifi_cmd11(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(11));

    float real_zSpeed_paddle_eigenvalue_1,real_zSpeed_paddle_eigenvalue_2,real_zSpeed_paddle_eigenvalue_3,real_zSpeed_paddle_eigenvalue_4;
    float real_zSpeed_point_1,real_zSpeed_point_2,real_zSpeed_point_3,real_zSpeed_point_4,real_zSpeed_point_5,real_zSpeed_point_6,real_zSpeed_point_7,real_zSpeed_point_8;
    float real_zSpeed_band_1,real_zSpeed_band_2,real_zSpeed_band_3,real_zSpeed_band_4,real_zSpeed_band_5;
    float real_zSpeed_maxpower_order,real_zSpeed_total_power;

    real_zSpeed_paddle_eigenvalue_1 = JYD_OriginalData.zAcc_paddle_eigenvalue_1/100;
    real_zSpeed_paddle_eigenvalue_2 = JYD_OriginalData.zAcc_paddle_eigenvalue_2/100;
    real_zSpeed_paddle_eigenvalue_3 = JYD_OriginalData.zAcc_paddle_eigenvalue_3/100;
    real_zSpeed_paddle_eigenvalue_4 = JYD_OriginalData.zAcc_paddle_eigenvalue_4/100;
    real_zSpeed_point_1 = JYD_OriginalData.zSpeed_point_1/100;
    real_zSpeed_point_2 = JYD_OriginalData.zSpeed_point_2/100;
    real_zSpeed_point_3 = JYD_OriginalData.zSpeed_point_3/100;
    real_zSpeed_point_4 = JYD_OriginalData.zSpeed_point_4/100;
    real_zSpeed_point_5 = JYD_OriginalData.zSpeed_point_5/100;
    real_zSpeed_point_6 = JYD_OriginalData.zSpeed_point_6/100;
    real_zSpeed_point_7 = JYD_OriginalData.zSpeed_point_7/100;
    real_zSpeed_point_8 = JYD_OriginalData.zSpeed_point_8/100;
    real_zSpeed_band_1 = JYD_OriginalData.zSpeed_band_1/100;
    real_zSpeed_band_2 = JYD_OriginalData.zSpeed_band_2/100;
    real_zSpeed_band_3 = JYD_OriginalData.zSpeed_band_3/100;
    real_zSpeed_band_4 = JYD_OriginalData.zSpeed_band_4/100;
    real_zSpeed_band_5 = JYD_OriginalData.zSpeed_band_5/100;
    real_zSpeed_maxpower_order = JYD_OriginalData.zSpeed_maxpower_order/10;
    real_zSpeed_total_power = JYD_OriginalData.zSpeed_total_power/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "zSpeed_paddle_eigenvalue_1", cJSON_CreateNumber(real_zSpeed_paddle_eigenvalue_1));
    cJSON_AddItemToObject(tx_root, "zSpeed_paddle_eigenvalue_2", cJSON_CreateNumber(real_zSpeed_paddle_eigenvalue_2));
    cJSON_AddItemToObject(tx_root, "zSpeed_paddle_eigenvalue_3", cJSON_CreateNumber(real_zSpeed_paddle_eigenvalue_3));
    cJSON_AddItemToObject(tx_root, "zSpeed_paddle_eigenvalue_4", cJSON_CreateNumber(real_zSpeed_paddle_eigenvalue_4));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_1", cJSON_CreateNumber(real_zSpeed_point_1));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_2", cJSON_CreateNumber(real_zSpeed_point_2));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_3", cJSON_CreateNumber(real_zSpeed_point_3));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_4", cJSON_CreateNumber(real_zSpeed_point_4));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_5", cJSON_CreateNumber(real_zSpeed_point_5));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_6", cJSON_CreateNumber(real_zSpeed_point_6));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_7", cJSON_CreateNumber(real_zSpeed_point_7));
    cJSON_AddItemToObject(tx_root, "zSpeed_point_8", cJSON_CreateNumber(real_zSpeed_point_8));
    cJSON_AddItemToObject(tx_root, "zSpeed_band_1", cJSON_CreateNumber(real_zSpeed_band_1));
    cJSON_AddItemToObject(tx_root, "zSpeed_band_2", cJSON_CreateNumber(real_zSpeed_band_2));
    cJSON_AddItemToObject(tx_root, "zSpeed_band_3", cJSON_CreateNumber(real_zSpeed_band_3));
    cJSON_AddItemToObject(tx_root, "zSpeed_band_4", cJSON_CreateNumber(real_zSpeed_band_4));
    cJSON_AddItemToObject(tx_root, "zSpeed_band_5", cJSON_CreateNumber(real_zSpeed_band_5));
    cJSON_AddItemToObject(tx_root, "zSpeed_maxpower_order", cJSON_CreateNumber(real_zSpeed_maxpower_order));
    cJSON_AddItemToObject(tx_root, "zSpeed_total_power", cJSON_CreateNumber(real_zSpeed_total_power));

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

void wifi_cmd12(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(12));

    float real_channalx_status,real_channaly_status,real_channalz_status;
    float real_temp_status;
    float real_x_warning,real_y_warning,real_z_warning;

    real_channalx_status = JYD_OriginalData.channalx_status/1;
    real_channaly_status = JYD_OriginalData.channaly_status/1;
    real_channalz_status = JYD_OriginalData.channalz_status/1;
    real_temp_status = JYD_OriginalData.temp_status/1;
    real_x_warning = JYD_OriginalData.x_warning/1;
    real_y_warning = JYD_OriginalData.y_warning/1;
    real_z_warning = JYD_OriginalData.z_warning/1;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "channalx_status", cJSON_CreateNumber(real_channalx_status));
    cJSON_AddItemToObject(tx_root, "channaly_status", cJSON_CreateNumber(real_channaly_status));
    cJSON_AddItemToObject(tx_root, "channalz_status", cJSON_CreateNumber(real_channalz_status));
    cJSON_AddItemToObject(tx_root, "temp_status", cJSON_CreateNumber(real_temp_status));
    cJSON_AddItemToObject(tx_root, "x_warning", cJSON_CreateNumber(real_x_warning));
    cJSON_AddItemToObject(tx_root, "y_warning", cJSON_CreateNumber(real_y_warning));
    cJSON_AddItemToObject(tx_root, "z_warning", cJSON_CreateNumber(real_z_warning));
   
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

void wifi_cmd13(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(13));

    float real_version,real_license;
    real_version = JYD_OriginalData.version/1;
    real_license = JYD_OriginalData.license/1;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "version", cJSON_CreateNumber(real_version));
    cJSON_AddItemToObject(tx_root, "license", cJSON_CreateNumber(real_license));
    
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

void wifi_cmd14(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(14));

    float real_BPFI,real_BPFO,real_BSF,real_FTF;
    real_BPFI = JYD_OriginalData.BPFI/100;
    real_BPFO = JYD_OriginalData.BPFO/100;
    real_BSF = JYD_OriginalData.BSF/100;
    real_FTF = JYD_OriginalData.FTF/100;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "BPFI", cJSON_CreateNumber(real_BPFI));
    cJSON_AddItemToObject(tx_root, "BPFO", cJSON_CreateNumber(real_BPFO));
    cJSON_AddItemToObject(tx_root, "BSF", cJSON_CreateNumber(real_BSF));
    cJSON_AddItemToObject(tx_root, "FTF", cJSON_CreateNumber(real_FTF));
    
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

void wifi_cmd15(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(15));

    float real_measue_speed,real_proportion;
    real_measue_speed = JYD_OriginalData.measue_speed/1;
    real_proportion = JYD_OriginalData.proportion/1;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "measue_speed", cJSON_CreateNumber(real_measue_speed));
    cJSON_AddItemToObject(tx_root, "proportion", cJSON_CreateNumber(real_proportion));
    
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

void wifi_cmd16(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(16));

    float real_point1_gain,real_point2_gain,real_point3_gain,real_point4_gain,real_point5_gain,real_point6_gain,real_point7_gain,real_point8_gain;
    float real_band1_startgain,real_band2_startgain,real_band3_startgain,real_band4_startgain,real_band5_startgain;
    float real_band1_endgain,real_band2_endgain,real_band3_endgain,real_band4_endgain,real_band5_endgain;

    real_point1_gain = JYD_OriginalData.point1_gain/100;
    real_point2_gain = JYD_OriginalData.point2_gain/100;
    real_point3_gain = JYD_OriginalData.point3_gain/100;
    real_point4_gain = JYD_OriginalData.point4_gain/100;
    real_point5_gain = JYD_OriginalData.point5_gain/100;
    real_point6_gain = JYD_OriginalData.point6_gain/100;
    real_point7_gain = JYD_OriginalData.point7_gain/100;
    real_point8_gain = JYD_OriginalData.point8_gain/100;
    real_band1_startgain = JYD_OriginalData.band1_startgain/100;
    real_band1_endgain = JYD_OriginalData.band1_endgain/100;
    real_band2_startgain = JYD_OriginalData.band2_startgain/100;
    real_band2_endgain = JYD_OriginalData.band2_endgain/100;
    real_band3_startgain = JYD_OriginalData.band3_startgain/100;
    real_band3_endgain = JYD_OriginalData.band3_endgain/100;
    real_band4_startgain = JYD_OriginalData.band4_startgain/100;
    real_band4_endgain = JYD_OriginalData.band4_endgain/100;
    real_band5_startgain = JYD_OriginalData.band5_startgain/100;
    real_band5_endgain = JYD_OriginalData.band5_endgain/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "point1_gain", cJSON_CreateNumber(real_point1_gain));
    cJSON_AddItemToObject(tx_root, "point2_gain", cJSON_CreateNumber(real_point2_gain));
    cJSON_AddItemToObject(tx_root, "point3_gain", cJSON_CreateNumber(real_point3_gain));
    cJSON_AddItemToObject(tx_root, "point4_gain", cJSON_CreateNumber(real_point4_gain));
    cJSON_AddItemToObject(tx_root, "point5_gain", cJSON_CreateNumber(real_point5_gain));
    cJSON_AddItemToObject(tx_root, "point6_gain", cJSON_CreateNumber(real_point6_gain));
    cJSON_AddItemToObject(tx_root, "point7_gain", cJSON_CreateNumber(real_point7_gain));
    cJSON_AddItemToObject(tx_root, "point8_gain", cJSON_CreateNumber(real_point8_gain));
    cJSON_AddItemToObject(tx_root, "band1_startgain", cJSON_CreateNumber(real_band1_startgain));
    cJSON_AddItemToObject(tx_root, "band1_endgain", cJSON_CreateNumber(real_band1_endgain));
    cJSON_AddItemToObject(tx_root, "band2_startgain", cJSON_CreateNumber(real_band2_startgain));
    cJSON_AddItemToObject(tx_root, "band2_endgain", cJSON_CreateNumber(real_band2_endgain));
    cJSON_AddItemToObject(tx_root, "band3_startgain", cJSON_CreateNumber(real_band3_startgain));
    cJSON_AddItemToObject(tx_root, "band3_endgain", cJSON_CreateNumber(real_band3_endgain));
    cJSON_AddItemToObject(tx_root, "band4_startgain", cJSON_CreateNumber(real_band4_startgain));
    cJSON_AddItemToObject(tx_root, "band4_endgain", cJSON_CreateNumber(real_band4_endgain));
    cJSON_AddItemToObject(tx_root, "band5_startgain", cJSON_CreateNumber(real_band5_startgain));
    cJSON_AddItemToObject(tx_root, "band5_endgain", cJSON_CreateNumber(real_band5_endgain));

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

void wifi_cmd17(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(17));

    float real_rollerNumber,real_rollerSize,real_bearingSize;
    real_rollerNumber = JYD_OriginalData.rollerNumber/1;
    real_rollerSize = JYD_OriginalData.rollerSize/100;
    real_bearingSize = JYD_OriginalData.bearingSize/100;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "rollerNumber", cJSON_CreateNumber(real_rollerNumber));
    cJSON_AddItemToObject(tx_root, "rollerSize", cJSON_CreateNumber(real_rollerSize));
    cJSON_AddItemToObject(tx_root, "bearingSize", cJSON_CreateNumber(real_bearingSize));

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

void wifi_cmd18(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(18));

    float real_alphaAngular,real_teethNumber;
    real_alphaAngular = JYD_OriginalData.alphaAngular/100;
    real_teethNumber = JYD_OriginalData.teethNumber/1;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "alphaAngular", cJSON_CreateNumber(real_alphaAngular));
    cJSON_AddItemToObject(tx_root, "teethNumber", cJSON_CreateNumber(real_teethNumber));

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

void wifi_cmd19(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(19));

    float real_mode,real_target;
    real_mode = JYD_OriginalData.mode/1;
    real_target = JYD_OriginalData.target/1;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "mode", cJSON_CreateNumber(real_mode));
    cJSON_AddItemToObject(tx_root, "target", cJSON_CreateNumber(real_target));

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

void wifi_cmd20(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(20));

    float real_x_accWarning,real_y_accWarning,real_z_accWarning;
    float real_x_accError,real_y_accError,real_z_accError;
    float real_x_speedWarning,real_y_speedWarning,real_z_speedWarning;
    float real_x_speedError,real_y_speedError,real_z_speedError;
    float real_tempWarning,real_tempError;
    float real_x_distanceWarning,real_y_distanceWarning,real_z_distanceWarning;
    float real_x_distanceError,real_y_distanceError,real_z_distanceError;
    
    real_x_accWarning = JYD_OriginalData.x_accWarning/100;
    real_x_accError = JYD_OriginalData.x_accError/100;
    real_y_accWarning = JYD_OriginalData.y_accWarning/100;
    real_y_accError = JYD_OriginalData.y_accError/100;
    real_z_accWarning = JYD_OriginalData.z_accWarning/100;
    real_z_accError = JYD_OriginalData.z_accError/100;
    real_x_speedWarning = JYD_OriginalData.x_speedWarning/100;
    real_x_speedError = JYD_OriginalData.x_speedError/100;
    real_y_speedWarning = JYD_OriginalData.y_speedWarning/100;
    real_y_speedError = JYD_OriginalData.y_speedError/100;
    real_z_speedWarning = JYD_OriginalData.z_speedWarning/100;
    real_z_speedError = JYD_OriginalData.z_speedError/100;
    real_tempWarning = JYD_OriginalData.tempWarning/100;
    real_tempError = JYD_OriginalData.tempError/100;
    real_x_distanceWarning = JYD_OriginalData.x_distanceWarning/100;
    real_x_distanceError = JYD_OriginalData.x_distanceError/100;
    real_y_distanceWarning = JYD_OriginalData.y_distanceWarning/100;
    real_y_distanceError = JYD_OriginalData.y_distanceError/100;
    real_z_distanceWarning = JYD_OriginalData.z_distanceWarning/100;
    real_z_distanceError = JYD_OriginalData.z_distanceError/100;

    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "x_accWarning", cJSON_CreateNumber(real_x_accWarning));
    cJSON_AddItemToObject(tx_root, "x_accError", cJSON_CreateNumber(real_x_accError));
    cJSON_AddItemToObject(tx_root, "y_accWarning", cJSON_CreateNumber(real_y_accWarning));
    cJSON_AddItemToObject(tx_root, "y_accError", cJSON_CreateNumber(real_y_accError));
    cJSON_AddItemToObject(tx_root, "z_accWarning", cJSON_CreateNumber(real_z_accWarning));
    cJSON_AddItemToObject(tx_root, "z_accError", cJSON_CreateNumber(real_z_accError));
    cJSON_AddItemToObject(tx_root, "x_speedWarning", cJSON_CreateNumber(real_x_speedWarning));
    cJSON_AddItemToObject(tx_root, "x_speedError", cJSON_CreateNumber(real_x_speedError));
    cJSON_AddItemToObject(tx_root, "y_speedWarning", cJSON_CreateNumber(real_y_speedWarning));
    cJSON_AddItemToObject(tx_root, "y_speedError", cJSON_CreateNumber(real_y_speedError));
    cJSON_AddItemToObject(tx_root, "z_speedWarning", cJSON_CreateNumber(real_z_speedWarning));
    cJSON_AddItemToObject(tx_root, "z_speedError", cJSON_CreateNumber(real_z_speedError));
    cJSON_AddItemToObject(tx_root, "tempWarning", cJSON_CreateNumber(real_tempWarning));
    cJSON_AddItemToObject(tx_root, "tempError", cJSON_CreateNumber(real_tempError));
    cJSON_AddItemToObject(tx_root, "x_distanceWarning", cJSON_CreateNumber(real_x_distanceWarning));
    cJSON_AddItemToObject(tx_root, "x_distanceError", cJSON_CreateNumber(real_x_distanceError));
    cJSON_AddItemToObject(tx_root, "y_distanceWarning", cJSON_CreateNumber(real_y_distanceWarning));
    cJSON_AddItemToObject(tx_root, "y_distanceError", cJSON_CreateNumber(real_y_distanceError));
    cJSON_AddItemToObject(tx_root, "z_distanceWarning", cJSON_CreateNumber(real_z_distanceWarning));
    cJSON_AddItemToObject(tx_root, "z_distanceError", cJSON_CreateNumber(real_z_distanceError));

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

void wifi_cmd21(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(21));

    float real_hpf_limit,real_lpf_limit,real_calcPeriod;
    real_hpf_limit = JYD_OriginalData.hpf_limit/1;
    real_lpf_limit = JYD_OriginalData.lpf_limit/1;
    real_calcPeriod = JYD_OriginalData.calcPeriod/1;
    
    cJSON_AddItemToObject(tx_root, "sysRunTime", cJSON_CreateNumber(ProjectData.runTime));
    cJSON_AddItemToObject(tx_root, "hpf_limit", cJSON_CreateNumber(real_hpf_limit));
    cJSON_AddItemToObject(tx_root, "lpf_limit", cJSON_CreateNumber(real_lpf_limit));
    cJSON_AddItemToObject(tx_root, "calcPeriod", cJSON_CreateNumber(real_calcPeriod));

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
        // 如果符合预期,则设置响应消息

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

extern uint8_t dataLogMode;
void ble_cmd23(cJSON *root){
    cJSON *cmd_dataLogMode = cJSON_GetObjectItem(root, "dataLog");

    dataLogMode = cmd_dataLogMode->valueint;

    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(23));

    char* json_string = cJSON_Print(tx_root);//转换成字符串

    TX_Characteristics.setValue(json_string);
    TX_Characteristics.notify();

    cJSON_Delete(tx_root);
    free(json_string);
}