#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *seetings;
    lv_obj_t *loading;
    lv_obj_t *settings_button;
    lv_obj_t *temp_value_display;
    lv_obj_t *co2_value_display;
    lv_obj_t *humid_value_display;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
    lv_obj_t *co2_critical_value;
    lv_obj_t *humid_critical_value;
    lv_obj_t *temp_critical_value;
    lv_obj_t *home_button;
    lv_obj_t *update_critical_values_button;
    lv_obj_t *keypad;
    lv_obj_t *obj3;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SEETINGS = 2,
    SCREEN_ID_LOADING = 3,
};

void create_screen_main();
void tick_screen_main();

void create_screen_seetings();
void tick_screen_seetings();

void create_screen_loading();
void tick_screen_loading();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/