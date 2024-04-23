#ifndef _GUI_DRIVER__H
#define _GUI_DRIVER__H

#include "TFT_eSPI.h"
#include <lvgl.h>
#include <gui_guider.h>
#include <events_init.h>

#include "WiFi_BLE.h"
#include "ModbusTask.h"

void GUI_setup();

void GUI_sysPrint(int32_t x, int32_t y, const char* str, ...);

void GUI_sysInfoUpdate();

extern TFT_eSPI tft;

#endif // !_GUI_DRIVER__H