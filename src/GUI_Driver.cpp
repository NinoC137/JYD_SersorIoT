#include "GUI_Driver.h"

#include <stdarg.h>

lv_disp_draw_buf_t draw_buf;     // 定义buffer结构体
lv_color_t buf[TFT_WIDTH * 60]; // 定义刷新缓存

TFT_eSPI tft = TFT_eSPI();

lv_ui guider_ui;

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();                                        // 使能写功能
  tft.setAddrWindow(area->x1, area->y1, w, h);             // 设置填充区域
  tft.pushColors((uint16_t *)&color_p->full, w * h, true); // 写入颜色缓存和缓存大小
  tft.endWrite();                                          // 关闭写功能

  lv_disp_flush_ready(disp); // 调用区域填充颜色函数
}

void GUI_setup()
{
    tft.init();
    tft.setRotation(1);

    tft.fillScreen(TFT_BLACK);

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 60);

    // 定义屏幕
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_HEIGHT;
    disp_drv.ver_res = TFT_WIDTH;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    setup_ui(&guider_ui);
    events_init(&guider_ui);
}

void GUI_sysPrint(int32_t x, int32_t y, const char* str, ...){
    char buffer[256];
    va_list args;
    va_start(args, str);

    vsnprintf(buffer, sizeof(buffer), str, args);
    va_end(args);

    tft.drawString(buffer, x, y, 2);
}

extern Error modbusError;
void GUI_sysInfoUpdate(){
  ModbusError me(modbusError);
  char sysTime[8];
  snprintf(sysTime, 8, "%d s", ProjectData.runTime);

  lv_textarea_set_text(guider_ui.screen_WiFi_SSID, WiFi_Data.WiFi_store[0].SSID);
  lv_textarea_set_text(guider_ui.screen_IPv4, WiFi_Data.WiFi_store[0].ipv4.toString().c_str());
  lv_textarea_set_text(guider_ui.screen_BLE, ProjectData.blestatus ? "BLE Connected" : "disconnect");
  lv_textarea_set_text(guider_ui.screen_Dev, (const char *)me);
  lv_textarea_set_text(guider_ui.screen_sysTime, sysTime);

  lv_bar_set_value(guider_ui.screen_RAM_bar, (int32_t)ProjectData.heapUsage, LV_ANIM_ON);
  lv_bar_set_value(guider_ui.screen_CPU_bar, (int32_t)ProjectData.WiFi_dB, LV_ANIM_ON);
}