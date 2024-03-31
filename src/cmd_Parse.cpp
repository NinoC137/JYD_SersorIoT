#include "cmd_Parse.h"

void cmd1(cJSON *root){
    cJSON *tx_root = cJSON_CreateObject();
    cJSON_AddItemToObject(tx_root, "res", cJSON_CreateNumber(0));
    cJSON_AddItemToObject(tx_root, "cmd", cJSON_CreateNumber(1));

    static int x = 0,y = 0,z = 0;

    cJSON_AddItemToObject(tx_root, "X_SPEED", cJSON_CreateNumber(x++));
    cJSON_AddItemToObject(tx_root, "Y_SPEED", cJSON_CreateNumber(y++));
    cJSON_AddItemToObject(tx_root, "Z_SPEED", cJSON_CreateNumber(z++));
    
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