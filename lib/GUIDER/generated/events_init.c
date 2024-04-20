/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

static void btn_1_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_add_flag(guider_ui.btn_1_img_4, LV_OBJ_FLAG_HIDDEN);
	}
		break;
	default:
		break;
	}
}

void events_init_btn_1(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->btn_1_img_4, btn_1_img_4_event_handler, LV_EVENT_ALL, ui);
}
