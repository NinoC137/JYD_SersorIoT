/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_screen(lv_ui *ui)
{
	//Write codes screen
	ui->screen = lv_obj_create(NULL);
	lv_obj_set_size(ui->screen, 320, 240);
	lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

	//Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_1
	ui->screen_img_1 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_1, &_JYD_LOGO_alpha_148x38);
	lv_img_set_pivot(ui->screen_img_1, 50,50);
	lv_img_set_angle(ui->screen_img_1, 0);
	lv_obj_set_pos(ui->screen_img_1, 0, 0);
	lv_obj_set_size(ui->screen_img_1, 148, 38);

	//Write style for screen_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_2
	ui->screen_img_2 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_2, &_wifi_alpha_48x52);
	lv_img_set_pivot(ui->screen_img_2, 50,50);
	lv_img_set_angle(ui->screen_img_2, 0);
	lv_obj_set_pos(ui->screen_img_2, 151, -2);
	lv_obj_set_size(ui->screen_img_2, 48, 52);

	//Write style for screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_3
	ui->screen_img_3 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_3, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_3, &_BLE_alpha_37x38);
	lv_img_set_pivot(ui->screen_img_3, 50,50);
	lv_img_set_angle(ui->screen_img_3, 0);
	lv_obj_set_pos(ui->screen_img_3, 157, 101);
	lv_obj_set_size(ui->screen_img_3, 37, 38);

	//Write style for screen_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_4
	ui->screen_img_4 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_4, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_4, &_Devices_alpha_50x46);
	lv_img_set_pivot(ui->screen_img_4, 50,50);
	lv_img_set_angle(ui->screen_img_4, 0);
	lv_obj_set_pos(ui->screen_img_4, 150, 143);
	lv_obj_set_size(ui->screen_img_4, 50, 46);

	//Write style for screen_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_5
	ui->screen_img_5 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_5, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_5, &_IP_alpha_42x39);
	lv_img_set_pivot(ui->screen_img_5, 50,50);
	lv_img_set_angle(ui->screen_img_5, 0);
	lv_obj_set_pos(ui->screen_img_5, 155, 53);
	lv_obj_set_size(ui->screen_img_5, 42, 39);

	//Write style for screen_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_6
	ui->screen_img_6 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_6, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_6, &_sysTime_alpha_43x44);
	lv_img_set_pivot(ui->screen_img_6, 50,50);
	lv_img_set_angle(ui->screen_img_6, 0);
	lv_obj_set_pos(ui->screen_img_6, 154, 193);
	lv_obj_set_size(ui->screen_img_6, 43, 44);

	//Write style for screen_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_7
	ui->screen_img_7 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_7, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_7, &_WiFi_dB_alpha_49x51);
	lv_img_set_pivot(ui->screen_img_7, 50,50);
	lv_img_set_angle(ui->screen_img_7, 0);
	lv_obj_set_pos(ui->screen_img_7, 3, 141);
	lv_obj_set_size(ui->screen_img_7, 49, 51);

	//Write style for screen_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_8
	ui->screen_img_8 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_8, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_8, &_rooooler_alpha_100x100);
	lv_img_set_pivot(ui->screen_img_8, 50,50);
	lv_img_set_angle(ui->screen_img_8, 0);
	lv_obj_set_pos(ui->screen_img_8, 24, 41);
	lv_obj_set_size(ui->screen_img_8, 100, 100);

	//Write style for screen_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_img_9
	ui->screen_img_9 = lv_img_create(ui->screen);
	lv_obj_add_flag(ui->screen_img_9, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->screen_img_9, &_RAM_alpha_40x40);
	lv_img_set_pivot(ui->screen_img_9, 50,50);
	lv_img_set_angle(ui->screen_img_9, 0);
	lv_obj_set_pos(ui->screen_img_9, 7, 195);
	lv_obj_set_size(ui->screen_img_9, 40, 40);

	//Write style for screen_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->screen_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes screen_CPU_bar
	ui->screen_CPU_bar = lv_bar_create(ui->screen);
	lv_obj_set_style_anim_time(ui->screen_CPU_bar, 1000, 0);
	lv_bar_set_mode(ui->screen_CPU_bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_CPU_bar, 0, 100);
	lv_bar_set_value(ui->screen_CPU_bar, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_CPU_bar, 56, 156);
	lv_obj_set_size(ui->screen_CPU_bar, 90, 20);

	//Write style for screen_CPU_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_CPU_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_CPU_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_CPU_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_CPU_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_CPU_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_CPU_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_CPU_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_CPU_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_CPU_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_CPU_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_RAM_bar
	ui->screen_RAM_bar = lv_bar_create(ui->screen);
	lv_obj_set_style_anim_time(ui->screen_RAM_bar, 1000, 0);
	lv_bar_set_mode(ui->screen_RAM_bar, LV_BAR_MODE_NORMAL);
	lv_bar_set_range(ui->screen_RAM_bar, 0, 100);
	lv_bar_set_value(ui->screen_RAM_bar, 50, LV_ANIM_OFF);
	lv_obj_set_pos(ui->screen_RAM_bar, 56, 203);
	lv_obj_set_size(ui->screen_RAM_bar, 90, 20);

	//Write style for screen_RAM_bar, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_RAM_bar, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_RAM_bar, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_RAM_bar, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_RAM_bar, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_RAM_bar, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_RAM_bar, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_RAM_bar, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_RAM_bar, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_RAM_bar, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_RAM_bar, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write codes screen_WiFi_SSID
	ui->screen_WiFi_SSID = lv_textarea_create(ui->screen);
	lv_textarea_set_text(ui->screen_WiFi_SSID, "GDUT-HUAWEI");
	lv_textarea_set_placeholder_text(ui->screen_WiFi_SSID, "");
	lv_textarea_set_password_bullet(ui->screen_WiFi_SSID, "*");
	lv_textarea_set_password_mode(ui->screen_WiFi_SSID, false);
	lv_textarea_set_one_line(ui->screen_WiFi_SSID, false);
	lv_textarea_set_accepted_chars(ui->screen_WiFi_SSID, "");
	lv_textarea_set_max_length(ui->screen_WiFi_SSID, 32);
	lv_obj_set_pos(ui->screen_WiFi_SSID, 194, 18);
	lv_obj_set_size(ui->screen_WiFi_SSID, 122, 26);

	//Write style for screen_WiFi_SSID, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_WiFi_SSID, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_WiFi_SSID, &lv_font_ArchitectsDaughter_9, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_WiFi_SSID, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_WiFi_SSID, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_WiFi_SSID, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_WiFi_SSID, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_WiFi_SSID, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_WiFi_SSID, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_WiFi_SSID, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_WiFi_SSID, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_WiFi_SSID, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_WiFi_SSID, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_WiFi_SSID, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_WiFi_SSID, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_WiFi_SSID, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_WiFi_SSID, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_WiFi_SSID, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_WiFi_SSID, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_WiFi_SSID, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_WiFi_SSID, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_WiFi_SSID, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_WiFi_SSID, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_IPv4
	ui->screen_IPv4 = lv_textarea_create(ui->screen);
	lv_textarea_set_text(ui->screen_IPv4, "192.168.5.137");
	lv_textarea_set_placeholder_text(ui->screen_IPv4, "");
	lv_textarea_set_password_bullet(ui->screen_IPv4, "*");
	lv_textarea_set_password_mode(ui->screen_IPv4, false);
	lv_textarea_set_one_line(ui->screen_IPv4, false);
	lv_textarea_set_accepted_chars(ui->screen_IPv4, "");
	lv_textarea_set_max_length(ui->screen_IPv4, 32);
	lv_obj_set_pos(ui->screen_IPv4, 193, 62);
	lv_obj_set_size(ui->screen_IPv4, 123, 26);

	//Write style for screen_IPv4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_IPv4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_IPv4, &lv_font_ArchitectsDaughter_10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_IPv4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_IPv4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_IPv4, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_IPv4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_IPv4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_IPv4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_IPv4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_IPv4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_IPv4, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_IPv4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_IPv4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_IPv4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_IPv4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_IPv4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_IPv4, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_IPv4, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_IPv4, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_IPv4, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_IPv4, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_IPv4, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_BLE
	ui->screen_BLE = lv_textarea_create(ui->screen);
	lv_textarea_set_text(ui->screen_BLE, "BLE connected");
	lv_textarea_set_placeholder_text(ui->screen_BLE, "");
	lv_textarea_set_password_bullet(ui->screen_BLE, "*");
	lv_textarea_set_password_mode(ui->screen_BLE, false);
	lv_textarea_set_one_line(ui->screen_BLE, false);
	lv_textarea_set_accepted_chars(ui->screen_BLE, "");
	lv_textarea_set_max_length(ui->screen_BLE, 32);
	lv_obj_set_pos(ui->screen_BLE, 194, 108);
	lv_obj_set_size(ui->screen_BLE, 127, 25);

	//Write style for screen_BLE, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_BLE, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_BLE, &lv_font_ArchitectsDaughter_9, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_BLE, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_BLE, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_BLE, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_BLE, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_BLE, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_BLE, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_BLE, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_BLE, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_BLE, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_BLE, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_BLE, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_BLE, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_BLE, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_BLE, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_BLE, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_BLE, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_BLE, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_BLE, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_BLE, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_BLE, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_Dev
	ui->screen_Dev = lv_textarea_create(ui->screen);
	lv_textarea_set_text(ui->screen_Dev, "Dev connected");
	lv_textarea_set_placeholder_text(ui->screen_Dev, "");
	lv_textarea_set_password_bullet(ui->screen_Dev, "*");
	lv_textarea_set_password_mode(ui->screen_Dev, false);
	lv_textarea_set_one_line(ui->screen_Dev, false);
	lv_textarea_set_accepted_chars(ui->screen_Dev, "");
	lv_textarea_set_max_length(ui->screen_Dev, 32);
	lv_obj_set_pos(ui->screen_Dev, 194, 153);
	lv_obj_set_size(ui->screen_Dev, 125, 26);

	//Write style for screen_Dev, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_Dev, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_Dev, &lv_font_ArchitectsDaughter_9, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_Dev, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_Dev, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_Dev, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_Dev, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Dev, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Dev, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_Dev, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_Dev, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_Dev, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_Dev, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_Dev, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_Dev, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_Dev, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_Dev, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Dev, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_Dev, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_Dev, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_Dev, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_Dev, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_Dev, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//Write codes screen_sysTime
	ui->screen_sysTime = lv_textarea_create(ui->screen);
	lv_textarea_set_text(ui->screen_sysTime, "2810ms");
	lv_textarea_set_placeholder_text(ui->screen_sysTime, "");
	lv_textarea_set_password_bullet(ui->screen_sysTime, "*");
	lv_textarea_set_password_mode(ui->screen_sysTime, false);
	lv_textarea_set_one_line(ui->screen_sysTime, false);
	lv_textarea_set_accepted_chars(ui->screen_sysTime, "");
	lv_textarea_set_max_length(ui->screen_sysTime, 32);
	lv_obj_set_pos(ui->screen_sysTime, 206, 201);
	lv_obj_set_size(ui->screen_sysTime, 97, 25);

	//Write style for screen_sysTime, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_text_color(ui->screen_sysTime, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->screen_sysTime, &lv_font_montserratMedium_9, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->screen_sysTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->screen_sysTime, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->screen_sysTime, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->screen_sysTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sysTime, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sysTime, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->screen_sysTime, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->screen_sysTime, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->screen_sysTime, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->screen_sysTime, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->screen_sysTime, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->screen_sysTime, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->screen_sysTime, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->screen_sysTime, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sysTime, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for screen_sysTime, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->screen_sysTime, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->screen_sysTime, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->screen_sysTime, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->screen_sysTime, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//The custom code of screen.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->screen);

}
