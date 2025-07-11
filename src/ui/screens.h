#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct _objects_t
    {
        lv_obj_t *dashboard;
        lv_obj_t *settings;
        lv_obj_t *main;
        lv_obj_t *settings_button;
        lv_obj_t *obj0;
        lv_obj_t *obj1;
        lv_obj_t *obj2;
        lv_obj_t *obj3;
        lv_obj_t *obj4;
        lv_obj_t *co2_value_display;
        lv_obj_t *humid_value_display;
        lv_obj_t *obj5;
        lv_obj_t *temp_value_display;
        lv_obj_t *obj6;
        lv_obj_t *co2_critical_value;
        lv_obj_t *humid_critical_value;
        lv_obj_t *temp_critical_value;
        lv_obj_t *home_button;
        lv_obj_t *update_critical_values_button;
        lv_obj_t *keypad;
        lv_obj_t *obj7;
    } objects_t;

    extern objects_t objects;

    enum ScreensEnum
    {
        SCREEN_ID_DASHBOARD = 1,
        SCREEN_ID_SETTINGS = 2,
        SCREEN_ID_MAIN = 3,
    };

    void create_screen_dashboard();
    void tick_screen_dashboard();

    void create_screen_settings();
    void tick_screen_settings();

    void create_screen_main();
    void tick_screen_main();

    void tick_screen_by_id(enum ScreensEnum screenId);
    void tick_screen(int screen_index);

    void create_screens();

    // ############################################################# //
    extern void keypad_event_cb(lv_event_t *e);
    extern void init_sensor_data();
    extern void update_sensor_display_cb(lv_timer_t *timer);
    extern float temp_critical;
    extern float humid_critical;
    extern float co2_critical;


    // ############################################################# //

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/