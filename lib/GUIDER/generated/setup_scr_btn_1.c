/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_btn_1(lv_ui *ui){

	//Write codes btn_1
	ui->btn_1 = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->btn_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->btn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_img_1
	ui->btn_1_img_1 = lv_img_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_img_1, 0, 0);
	lv_obj_set_size(ui->btn_1_img_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->btn_1_img_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_img_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->btn_1_img_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->btn_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->btn_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->btn_1_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->btn_1_img_1,&_backgroud_alpha_320x240);
	lv_img_set_pivot(ui->btn_1_img_1, 50,50);
	lv_img_set_angle(ui->btn_1_img_1, 0);

	//Write codes btn_1_sw_1
	ui->btn_1_sw_1 = lv_switch_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_sw_1, 125, 9);
	lv_obj_set_size(ui->btn_1_sw_1, 71, 28);
	lv_obj_set_scrollbar_mode(ui->btn_1_sw_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_sw_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_sw_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_sw_1, lv_color_make(0xe6, 0xe2, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_sw_1, lv_color_make(0xe6, 0xe2, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_sw_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->btn_1_sw_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->btn_1_sw_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for btn_1_sw_1. Part: LV_PART_INDICATOR, State: LV_STATE_CHECKED
	lv_obj_set_style_bg_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_sw_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_bg_opa(ui->btn_1_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_width(ui->btn_1_sw_1, 0, LV_PART_INDICATOR|LV_STATE_CHECKED);
	lv_obj_set_style_border_opa(ui->btn_1_sw_1, 255, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Set style for btn_1_sw_1. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_sw_1, 100, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_sw_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_sw_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_sw_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->btn_1_sw_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->btn_1_sw_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->btn_1_sw_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes btn_1_speed
	ui->btn_1_speed = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_speed, 148, 199);
	lv_obj_set_size(ui->btn_1_speed, 114, 33);
	lv_obj_set_scrollbar_mode(ui->btn_1_speed, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_speed, "当前功率:");
	lv_label_set_long_mode(ui->btn_1_speed, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_speed. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_speed, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_speed, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_speed, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_speed, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_speed, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_speed, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_speed, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_speed, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_speed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_speed, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_speed, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_data
	ui->btn_1_data = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_data, 41, 3);
	lv_obj_set_size(ui->btn_1_data, 107, 40);
	lv_obj_set_scrollbar_mode(ui->btn_1_data, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_data, "关闭\n");
	lv_label_set_long_mode(ui->btn_1_data, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_data. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_data, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_data, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_data, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_data, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_data, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_data, lv_color_make(0x00, 0xcb, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_data, &lv_font_simsun_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_data, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_data, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_data, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_data, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_1
	ui->btn_1_label_1 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_1, 15, 199);
	lv_obj_set_size(ui->btn_1_label_1, 88, 27);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_1, "当前温度:");
	lv_label_set_long_mode(ui->btn_1_label_1, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_1, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_1, &lv_font_simsun_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_6
	ui->btn_1_label_6 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_6, 176, 3);
	lv_obj_set_size(ui->btn_1_label_6, 107, 40);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_6, "开启");
	lv_label_set_long_mode(ui->btn_1_label_6, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_6. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_6, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_6, lv_color_make(0x00, 0xcb, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_6, &lv_font_simsun_22, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_6, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_7
	ui->btn_1_label_7 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_7, 70, 199);
	lv_obj_set_size(ui->btn_1_label_7, 100, 32);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_7, "60");
	lv_label_set_long_mode(ui->btn_1_label_7, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_7. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_7, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_7, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_7, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_7, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_8
	ui->btn_1_label_8 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_8, 220, 199);
	lv_obj_set_size(ui->btn_1_label_8, 100, 32);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_8, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_8, "1000w");
	lv_label_set_long_mode(ui->btn_1_label_8, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_8. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_8, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_8, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_8, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_8, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_9
	ui->btn_1_label_9 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_9, 30, 151);
	lv_obj_set_size(ui->btn_1_label_9, 107, 40);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_9, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_9, "温度调节(度)\n");
	lv_label_set_long_mode(ui->btn_1_label_9, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_9. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_9, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_9, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_9, lv_color_make(0x00, 0xcb, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_9, &lv_font_simsun_13, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_9, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_9, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_10
	ui->btn_1_label_10 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_10, 175, 151);
	lv_obj_set_size(ui->btn_1_label_10, 133, 26);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_10, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_10, "速度调节(万转/min)\n");
	lv_label_set_long_mode(ui->btn_1_label_10, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_10. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_10, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_10, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_10, lv_color_make(0x00, 0xcb, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_10, &lv_font_simsun_12, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_10, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_10, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_img_2
	ui->btn_1_img_2 = lv_img_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_img_2, 30, 59);
	lv_obj_set_size(ui->btn_1_img_2, 100, 100);
	lv_obj_set_scrollbar_mode(ui->btn_1_img_2, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_img_2. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->btn_1_img_2, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->btn_1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->btn_1_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->btn_1_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->btn_1_img_2,&_button_alpha_100x100);
	lv_img_set_pivot(ui->btn_1_img_2, 50,50);
	lv_img_set_angle(ui->btn_1_img_2, 0);

	//Write codes btn_1_img_3
	ui->btn_1_img_3 = lv_img_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_img_3, 191, 59);
	lv_obj_set_size(ui->btn_1_img_3, 100, 100);
	lv_obj_set_scrollbar_mode(ui->btn_1_img_3, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_img_3. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->btn_1_img_3, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->btn_1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->btn_1_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->btn_1_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->btn_1_img_3,&_button_alpha_100x100);
	lv_img_set_pivot(ui->btn_1_img_3, 50,50);
	lv_img_set_angle(ui->btn_1_img_3, 0);

	//Write codes btn_1_temperate
	ui->btn_1_temperate = lv_arc_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_temperate, 12, 43);
	lv_obj_set_size(ui->btn_1_temperate, 137, 169);
	lv_obj_set_scrollbar_mode(ui->btn_1_temperate, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_temperate. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_temperate, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_temperate, lv_color_make(0xf6, 0xf6, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_temperate, lv_color_make(0xf6, 0xf6, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_temperate, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_temperate, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_temperate, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->btn_1_temperate, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_temperate, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_temperate, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_temperate, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_temperate, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->btn_1_temperate, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->btn_1_temperate, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for btn_1_temperate. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_arc_color(ui->btn_1_temperate, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->btn_1_temperate, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for btn_1_temperate. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->btn_1_temperate, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_temperate, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_temperate, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_temperate, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->btn_1_temperate, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_mode(ui->btn_1_temperate, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->btn_1_temperate, 0, 100);
	lv_arc_set_bg_angles(ui->btn_1_temperate, 0, 270);
	lv_arc_set_angles(ui->btn_1_temperate, 0, 270);
	lv_arc_set_rotation(ui->btn_1_temperate, 135);

	//Write codes btn_1_arc_1
	ui->btn_1_arc_1 = lv_arc_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_arc_1, 173, 43);
	lv_obj_set_size(ui->btn_1_arc_1, 137, 169);
	lv_obj_set_scrollbar_mode(ui->btn_1_arc_1, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_arc_1. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_arc_1, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_arc_1, lv_color_make(0xf6, 0xf6, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_arc_1, lv_color_make(0xf6, 0xf6, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_arc_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_arc_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_arc_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->btn_1_arc_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_arc_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_color(ui->btn_1_arc_1, lv_color_make(0xe6, 0xe6, 0xe6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->btn_1_arc_1, 12, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Set style for btn_1_arc_1. Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT
	lv_obj_set_style_arc_color(ui->btn_1_arc_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_arc_width(ui->btn_1_arc_1, 12, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Set style for btn_1_arc_1. Part: LV_PART_KNOB, State: LV_STATE_DEFAULT
	lv_obj_set_style_bg_color(ui->btn_1_arc_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_arc_1, lv_color_make(0x21, 0x95, 0xf6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_arc_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_arc_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_all(ui->btn_1_arc_1, 5, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_arc_set_mode(ui->btn_1_arc_1, LV_ARC_MODE_NORMAL);
	lv_arc_set_range(ui->btn_1_arc_1, 0, 100);
	lv_arc_set_bg_angles(ui->btn_1_arc_1, 0, 270);
	lv_arc_set_angles(ui->btn_1_arc_1, 0, 270);
	lv_arc_set_rotation(ui->btn_1_arc_1, 135);

	//Write codes btn_1_label_11
	ui->btn_1_label_11 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_11, 12, 118);
	lv_obj_set_size(ui->btn_1_label_11, 27, 21);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_11, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_11, "50");
	lv_label_set_long_mode(ui->btn_1_label_11, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_11. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_11, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_11, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_11, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_11, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_11, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_11, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_12
	ui->btn_1_label_12 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_12, 3, 82);
	lv_obj_set_size(ui->btn_1_label_12, 38, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_12, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_12, "60");
	lv_label_set_long_mode(ui->btn_1_label_12, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_12. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_12, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_12, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_12, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_12, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_12, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_12, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_13
	ui->btn_1_label_13 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_13, 30, 50);
	lv_obj_set_size(ui->btn_1_label_13, 38, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_13, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_13, "70");
	lv_label_set_long_mode(ui->btn_1_label_13, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_13. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_13, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_13, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_13, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_13, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_13, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_13, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_14
	ui->btn_1_label_14 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_14, 121, 82);
	lv_obj_set_size(ui->btn_1_label_14, 38, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_14, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_14, "90");
	lv_label_set_long_mode(ui->btn_1_label_14, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_14. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_14, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_14, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_14, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_14, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_14, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_14, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_14, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_14, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_14, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_15
	ui->btn_1_label_15 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_15, 96, 50);
	lv_obj_set_size(ui->btn_1_label_15, 34, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_15, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_15, "80");
	lv_label_set_long_mode(ui->btn_1_label_15, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_15. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_15, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_15, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_15, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_15, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_15, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_15, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_16
	ui->btn_1_label_16 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_16, 125, 118);
	lv_obj_set_size(ui->btn_1_label_16, 35, 23);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_16, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_16, "100");
	lv_label_set_long_mode(ui->btn_1_label_16, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_16. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_16, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_16, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_16, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_16, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_16, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_16, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_16, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_16, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_16, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_17
	ui->btn_1_label_17 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_17, 182, 133);
	lv_obj_set_size(ui->btn_1_label_17, 38, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_17, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_17, "0");
	lv_label_set_long_mode(ui->btn_1_label_17, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_17. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_17, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_17, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_17, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_17, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_17, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_17, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_17, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_17, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_17, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_17, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_17, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_19
	ui->btn_1_label_19 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_19, 170, 100);
	lv_obj_set_size(ui->btn_1_label_19, 27, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_19, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_19, "2\n");
	lv_label_set_long_mode(ui->btn_1_label_19, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_19. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_19, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_19, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_19, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_19, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_19, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_19, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_19, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_19, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_19, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_19, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_20
	ui->btn_1_label_20 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_20, 182, 68);
	lv_obj_set_size(ui->btn_1_label_20, 26, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_20, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_20, "4\n");
	lv_label_set_long_mode(ui->btn_1_label_20, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_20. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_20, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_20, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_20, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_20, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_20, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_20, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_20, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_20, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_20, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_20, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_20, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_21
	ui->btn_1_label_21 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_21, 276, 68);
	lv_obj_set_size(ui->btn_1_label_21, 26, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_21, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_21, "8");
	lv_label_set_long_mode(ui->btn_1_label_21, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_21. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_21, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_21, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_21, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_21, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_21, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_21, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_21, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_21, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_21, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_21, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_22
	ui->btn_1_label_22 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_22, 284, 100);
	lv_obj_set_size(ui->btn_1_label_22, 34, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_22, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_22, "10");
	lv_label_set_long_mode(ui->btn_1_label_22, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_22. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_22, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_22, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_22, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_22, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_22, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_22, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_22, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_22, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_22, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_22, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_23
	ui->btn_1_label_23 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_23, 276, 133);
	lv_obj_set_size(ui->btn_1_label_23, 35, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_23, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_23, "12");
	lv_label_set_long_mode(ui->btn_1_label_23, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_23. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_23, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_23, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_23, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_23, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_23, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_23, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_23, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_23, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_label_24
	ui->btn_1_label_24 = lv_label_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_label_24, 228, 43);
	lv_obj_set_size(ui->btn_1_label_24, 26, 18);
	lv_obj_set_scrollbar_mode(ui->btn_1_label_24, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->btn_1_label_24, "6");
	lv_label_set_long_mode(ui->btn_1_label_24, LV_LABEL_LONG_WRAP);

	//Set style for btn_1_label_24. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_radius(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->btn_1_label_24, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_color(ui->btn_1_label_24, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->btn_1_label_24, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_color(ui->btn_1_label_24, lv_color_make(0x21, 0x95, 0xf6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_opa(ui->btn_1_label_24, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_spread(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_x(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_ofs_y(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->btn_1_label_24, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->btn_1_label_24, &lv_font_montserratMedium_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->btn_1_label_24, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->btn_1_label_24, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->btn_1_label_24, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->btn_1_label_24, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes btn_1_img_4
	ui->btn_1_img_4 = lv_img_create(ui->btn_1);
	lv_obj_set_pos(ui->btn_1_img_4, 0, 0);
	lv_obj_set_size(ui->btn_1_img_4, 320, 240);
	lv_obj_set_scrollbar_mode(ui->btn_1_img_4, LV_SCROLLBAR_MODE_OFF);

	//Set style for btn_1_img_4. Part: LV_PART_MAIN, State: LV_STATE_DEFAULT
	lv_obj_set_style_img_recolor(ui->btn_1_img_4, lv_color_make(0xff, 0xff, 0xff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_recolor_opa(ui->btn_1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_img_opa(ui->btn_1_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->btn_1_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->btn_1_img_4,&_shouye_alpha_320x240);
	lv_img_set_pivot(ui->btn_1_img_4, 50,50);
	lv_img_set_angle(ui->btn_1_img_4, 0);

	//Init events for screen
	events_init_btn_1(ui);
}