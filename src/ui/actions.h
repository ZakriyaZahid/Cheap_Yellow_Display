#include "screens.h" // assuming this defines loadScreen
#include "ui.h"      // assuming this defines objects
#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>
//<lvgl.h>

#ifdef __cplusplus
extern "C"
{
#endif

    extern void action_go_to_home(lv_event_t *e);
    extern void action_update_critical_values(lv_event_t *e);
    extern void action_go_to_settings(lv_event_t *e);

    //==============================================================================
    //
    //   Addition Starts
    //
    //   Author:   M. Zakriya
    //   Date:     13/07/2025
    //==============================================================================
    void update_critical_values_from_inputs(void);
    void populate_critical_inputs(void);
    void update_sensor_display_cb(lv_timer_t *timer);
    void init_sensor_data();
    void keypad_event_cb(lv_event_t *e);
    void textarea_event_cb(lv_event_t *e);
    // Arrays to simulate sensor values
    float temp_values[50];
    float humid_values[50];
    float co2_values[50];

    // Index tracker
    extern int value_index;
    extern float temp_critical;
    extern float humid_critical;
    extern float co2_critical;
    //==============================================================================
    //
    //   Addition Ends
    //
    //   Author:   M. Zakriya
    //   Date:     13/07/2025
    //==============================================================================

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/