#include "lvgl.h"
#include "actions.h"
#include "screens.h"

void action_go_to_settings(lv_event_t *e)
{
    // Example logic to switch screen
    loadScreen(SCREEN_ID_SEETINGS);
}

void action_go_to_home(lv_event_t *e)
{
    loadScreen(SCREEN_ID_MAIN);
}

void action_update_critical_values(lv_event_t *e)
{
    // Your custom logic here
}