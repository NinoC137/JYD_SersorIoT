/*
 * Copyright 2024 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

static lv_obj_t * g_kb_table_1;
static void kb_table_1_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *kb = lv_event_get_target(e);
	if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}
__attribute__((unused)) static void ta_table_1_event_cb(lv_event_t *e)
{

	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *ta = lv_event_get_target(e);
	lv_obj_t *kb = lv_event_get_user_data(e);
	if (code == LV_EVENT_FOCUSED || code == LV_EVENT_CLICKED)
	{
		lv_keyboard_set_textarea(kb, ta);
		lv_obj_move_foreground(kb);
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
	if (code == LV_EVENT_CANCEL || code == LV_EVENT_DEFOCUSED)
	{
		lv_keyboard_set_textarea(kb, NULL);
		lv_obj_move_background(kb);
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void setup_scr_table_1(lv_ui *ui){

	//Write codes table_1
	ui->table_1 = lv_obj_create(NULL);

	//Create keyboard on table_1
	g_kb_table_1 = lv_keyboard_create(ui->table_1);
	lv_obj_add_event_cb(g_kb_table_1, kb_table_1_event_cb, LV_EVENT_ALL, NULL);
	lv_obj_add_flag(g_kb_table_1, LV_OBJ_FLAG_HIDDEN);
	lv_obj_set_style_text_font(g_kb_table_1, &lv_font_simsun_18, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_scrollbar_mode(ui->table_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for table_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->table_1, lv_color_make(0x04, 0x49, 0xfd), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->table_1, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->table_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes table_1_img_1
	ui->table_1_img_1 = lv_img_create(ui->table_1);
	lv_obj_set_pos(ui->table_1_img_1, 59, 0);
	lv_obj_set_size(ui->table_1_img_1, 202, 49);
	lv_obj_set_scrollbar_mode(ui->table_1_img_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for table_1_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->table_1_img_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->table_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->table_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->table_1_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->table_1_img_1,&_JYD_LOGO_alpha_202x49);
	lv_img_set_pivot(ui->table_1_img_1, 50,50);
	lv_img_set_angle(ui->table_1_img_1, 0);

	//Write codes table_1_table_1
	ui->table_1_table_1 = lv_table_create(ui->table_1);
	lv_obj_set_pos(ui->table_1_table_1, 28, 66);
	lv_obj_set_scrollbar_mode(ui->table_1_table_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for table_1_table_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->table_1_table_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->table_1_table_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->table_1_table_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->table_1_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->table_1_table_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->table_1_table_1, lv_color_make(0xfe, 0xc2, 0x04), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->table_1_table_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->table_1_table_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->table_1_table_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for table_1_table_1. Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->table_1_table_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->table_1_table_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->table_1_table_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->table_1_table_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->table_1_table_1, lv_color_make(0xd5, 0xde, 0xe6), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->table_1_table_1, 3, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->table_1_table_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->table_1_table_1, lv_color_make(0x39, 0x3c, 0x41), LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->table_1_table_1, &lv_font_montserratMedium_12, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_text_decor(ui->table_1_table_1, LV_TEXT_DECOR_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_table_set_col_cnt(ui->table_1_table_1,2);
	lv_table_set_row_cnt(ui->table_1_table_1,5);
	lv_table_set_cell_value(ui->table_1_table_1,0,0,"Device_ID");
	lv_table_set_cell_value(ui->table_1_table_1,1,0,"IPv4");
	lv_table_set_cell_value(ui->table_1_table_1,2,0,"ServerIP");
	lv_table_set_cell_value(ui->table_1_table_1,3,0,"ServerPort");
	lv_table_set_cell_value(ui->table_1_table_1,4,0,"runTime");
	lv_table_set_cell_value(ui->table_1_table_1,0,1,"0001");
	lv_table_set_cell_value(ui->table_1_table_1,1,1,"192.168.5.154");
	lv_table_set_cell_value(ui->table_1_table_1,2,1,"192.168.5.8");
	lv_table_set_cell_value(ui->table_1_table_1,3,1,"3001");
	lv_table_set_cell_value(ui->table_1_table_1,4,1,"2913");
	lv_obj_set_style_pad_left(ui->table_1_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->table_1_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->table_1_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->table_1_table_1, 10, LV_PART_ITEMS|LV_STATE_DEFAULT);
}