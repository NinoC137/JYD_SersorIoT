/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *table_1;
	bool table_1_del;
	lv_obj_t *table_1_img_1;
	lv_obj_t *table_1_table_1;
}lv_ui;

void ui_init_style(lv_style_t * style);
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_table_1(lv_ui *ui);
LV_IMG_DECLARE(_JYD_LOGO_alpha_202x49);

#ifdef __cplusplus
}
#endif
#endif