#if defined(EEZ_FOR_LVGL)
#include <eez/core/vars.h>
#endif

#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"







#if defined(EEZ_FOR_LVGL)

void ui_init() {
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick() {
    eez_flow_tick();
    tick_screen(g_currentScreen);
}

#else

#include <string.h>

static int16_t currentScreen = -1;

static lv_obj_t *getLvglObjectFromIndex(int32_t index) {
    if (index == -1) {
        return 0;
    }
    return ((lv_obj_t **)&objects)[index];
}

void loadScreen(enum ScreensEnum screenId) {
    currentScreen = screenId - 1;
    lv_obj_t *screen = getLvglObjectFromIndex(currentScreen);
    lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 200, 0, false);
}

void show_main_screen_cb(lv_timer_t *timer)
{
    loadScreen(SCREEN_ID_MAIN);
    lv_timer_del(timer); // optional: delete timer after use
}

void ui_init()
{
    create_screens();
    loadScreen(SCREEN_ID_LOADING);

    // Set a 3-second timer to switch to main screen
    lv_timer_create(show_main_screen_cb, 3000, NULL);
}

// void ui_init() {
//     create_screens();
//     loadScreen(SCREEN_ID_MAIN);

// }

void ui_tick() {
    tick_screen(currentScreen);
}

#endif
