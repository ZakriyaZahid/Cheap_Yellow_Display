#if defined(EEZ_FOR_LVGL)
#include <eez/core/vars.h>
#endif

#include "ui.h"
#include "screens.h"
#include "images.h"
#include "actions.h"
#include "vars.h"

#if defined(EEZ_FOR_LVGL)

void ui_init()
{
    eez_flow_init(assets, sizeof(assets), (lv_obj_t **)&objects, sizeof(objects), images, sizeof(images), actions);
}

void ui_tick()
{
    eez_flow_tick();
    tick_screen(g_currentScreen);
}

#else

#include <string.h>

static int16_t currentScreen = -1;

static lv_obj_t *getLvglObjectFromIndex(int32_t index)
{
    if (index == -1)
    {
        return 0;
    }
    return ((lv_obj_t **)&objects)[index];
}

void loadScreen(enum ScreensEnum screenId)
{
    currentScreen = screenId - 1;
    lv_obj_t *screen = getLvglObjectFromIndex(currentScreen);
    // lv_scr_load_anim(screen, LV_SCR_LOAD_ANIM_FADE_IN, 50, 0, false);
    lv_scr_load(screen);
}

// ############################################################# //
void go_to_main_screen_cb(lv_timer_t *timer)
{
    loadScreen(SCREEN_ID_DASHBOARD);
    lv_timer_del(timer); // Optional: clean up the timer
}

// ############################################################# //

void ui_init()
{
    create_screens();
    loadScreen(SCREEN_ID_MAIN);
    // Set a one-shot timer to switch to dashboard after 2000 ms
    lv_timer_create(go_to_main_screen_cb, 2000, NULL);
}

void ui_tick()
{
    tick_screen(currentScreen);
}

#endif
