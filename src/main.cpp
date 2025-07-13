//==============================================================================
//
//  main.cpp
//
//
//==============================================================================
//  FILE INFORMATION
//==============================================================================
//
//  Source:
//
//  Project:    Sensor Data Dashboard
//
//  Author:     M.Zakriya
//
//  Date:       13/07/2025
//
//  Revision:   1.0
//
//==============================================================================
//  FILE DESCRIPTION
//==============================================================================
//
//! \file
//! This module takes care of the
//
//==============================================================================
//  REVISION HISTORY
//==============================================================================
//  Revision: 1.0
//
//

//==============================================================================
//  INCLUDES
//==============================================================================

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

// === EEZ Studio GUI headers ===
extern "C"
{
#include "ui/ui.h"
#include "ui/screens.h"
#include "ui/styles.h"
#include "ui/images.h"
#include "ui/actions.h"
#include "ui/fonts.h"
#include "ui/vars.h"
#include "ui/structs.h"
}

// === Touchscreen SPI pins ===
#define XPT2046_IRQ 36
#define XPT2046_MOSI 32
#define XPT2046_MISO 39
#define XPT2046_CLK 25
#define XPT2046_CS 33

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define DRAW_BUF_SIZE (SCREEN_WIDTH * 10) // Lines of buffer

// Globals
SPIClass touchscreenSPI(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
TFT_eSPI tft = TFT_eSPI();
lv_display_t *disp = nullptr;

// LVGL flush function
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
	tft.startWrite();
	int32_t w = area->x2 - area->x1 + 1;
	int32_t h = area->y2 - area->y1 + 1;
	tft.setAddrWindow(area->x1, area->y1, w, h);
	tft.pushColors((uint16_t *)px_map, w * h, true);
	tft.endWrite();
	lv_display_flush_ready(disp);
}

// LVGL input read function
void touchscreen_read(lv_indev_t *indev, lv_indev_data_t *data)
{
	(void)indev;
	if (touchscreen.tirqTouched() && touchscreen.touched())
	{
		TS_Point p = touchscreen.getPoint();
		int x = map(p.y, 240, 3800, SCREEN_WIDTH, 1);
		int y = map(p.x, 200, 3700, 1, SCREEN_HEIGHT);
		data->state = LV_INDEV_STATE_PRESSED;
		data->point.x = x;
		data->point.y = y;
	}
	else
	{
		data->state = LV_INDEV_STATE_RELEASED;
	}
}

// Optional LVGL log callback
void log_print_cb(lv_log_level_t level, const char *buf)
{
	Serial.println(buf);
}

void setup()
{
	Serial.begin(115200);
	delay(1000);

	// LVGL init
	lv_init();
	lv_log_register_print_cb(log_print_cb);

	// Init touchscreen SPI and touch
	touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
	touchscreen.begin(touchscreenSPI);
	touchscreen.setRotation(2); // Landscape mode

	// Init TFT display
	tft.begin();
	tft.setRotation(1); // Landscape

	// Display buffer
	static lv_color_t buf1[DRAW_BUF_SIZE];
	static lv_color_t buf2[DRAW_BUF_SIZE]; // Double buffering
	disp = lv_display_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	lv_display_set_flush_cb(disp, my_disp_flush);
	lv_display_set_buffers(disp, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

	// Touchscreen input
	lv_indev_t *indev = lv_indev_create();
	lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
	lv_indev_set_read_cb(indev, touchscreen_read);

	// Init EEZ Studio GUI
	ui_init();
}

void loop()
{
	lv_task_handler();
	lv_tick_inc(5);
	delay(5);
}
