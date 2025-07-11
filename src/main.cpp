#include <Arduino.h>
#include <lvgl.h> // Top-level include for LVGL 8.x
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
#define DRAW_BUF_SIZE (SCREEN_WIDTH * 10)

SPIClass touchscreenSPI = SPIClass(VSPI);
XPT2046_Touchscreen touchscreen(XPT2046_CS, XPT2046_IRQ);
TFT_eSPI tft = TFT_eSPI();

// === Display flush for LVGL ===
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
	tft.startWrite();
	int32_t w = area->x2 - area->x1 + 1;
	int32_t h = area->y2 - area->y1 + 1;
	tft.setAddrWindow(area->x1, area->y1, w, h);
	tft.pushColors((uint16_t *)color_p, w * h, true);

	tft.pushColors((uint16_t *)&color_p->full,
				   (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1),
				   true);
	tft.endWrite();
	lv_disp_flush_ready(disp);
}

// === Touch input read ===
void touchscreen_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
{
	(void)indev_drv;
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

// === Optional logging ===
void log_print(const char *buf)
{
	Serial.println(buf);
	Serial.flush();
}

void setup()
{
	Serial.begin(115200);
	delay(1000);

	// Init LVGL
	lv_init();
	lv_log_register_print_cb(log_print);

	// Init Touch
	touchscreenSPI.begin(XPT2046_CLK, XPT2046_MISO, XPT2046_MOSI, XPT2046_CS);
	touchscreen.begin(touchscreenSPI);
	touchscreen.setRotation(2); // landscape

	// Init TFT
	tft.begin();
	tft.setRotation(1); // landscape

	// LVGL display buffer
	static lv_disp_draw_buf_t draw_buf;
	static lv_color_t buf1[DRAW_BUF_SIZE];
	lv_disp_draw_buf_init(&draw_buf, buf1, NULL, DRAW_BUF_SIZE);

	// LVGL display driver
	static lv_disp_drv_t disp_drv;
	lv_disp_drv_init(&disp_drv);
	disp_drv.hor_res = SCREEN_WIDTH;
	disp_drv.ver_res = SCREEN_HEIGHT;
	disp_drv.flush_cb = my_disp_flush;
	disp_drv.draw_buf = &draw_buf;
	lv_disp_drv_register(&disp_drv);

	// LVGL input driver
	static lv_indev_drv_t indev_drv;
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = touchscreen_read;
	lv_indev_drv_register(&indev_drv);

	// EEZ UI
	ui_init();
}

void loop()
{
	lv_task_handler();
	lv_tick_inc(5); // ✅ This is where LVGL time advances
	delay(5);
}
