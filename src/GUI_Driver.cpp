#include "GUI_Driver.h"

#include <stdarg.h>

lv_disp_draw_buf_t draw_buf;     // 定义显示器变量完
lv_color_t buf[TFT_WIDTH * 350]; // 定义刷新缓存

TFT_eSPI tft = TFT_eSPI();

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
    tft.setRotation(0);

    tft.fillScreen(TFT_BLACK);

    lv_init();
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, TFT_WIDTH * 100);

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