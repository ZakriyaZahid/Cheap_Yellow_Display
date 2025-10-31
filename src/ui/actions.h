
// ##########################################################################//
#include "screens.h" // assuming this defines loadScreen
#include "ui.h"      // assuming this defines objects

// ##########################################################################//

#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // ##########################################################################//

    extern char active_nodes[10][30];
    extern char recieved_messages[10][150];
    extern char sent_messages[10][150];

    void hide_all_containers();
    void show_message_labels();
    void hide_message_labels();
    void show_recieved_msgs_list();
    void show_sent_msgs_list();
    void show_active_nodes_list();

    // ##########################################################################//

    extern void action_spec5_btn_event(lv_event_t *e);
    extern void action_nodes_btn_event(lv_event_t *e);
    extern void action_grp_msg_btn_event(lv_event_t *e);
    extern void action_rcvd_msgs_btn_event(lv_event_t *e);
    extern void action_sent_msgs_btn_event(lv_event_t *e);
    extern void action_terminal_btn_event(lv_event_t *e);
    extern void action_send_txt_btn_event(lv_event_t *e);
    extern void action_back_from_msg_btn_event(lv_event_t *e);
    extern void action_label1_event(lv_event_t *e);
    extern void action_label2_event(lv_event_t *e);
    extern void action_label3_event(lv_event_t *e);
    extern void action_label4_event(lv_event_t *e);
    extern void action_label5_event(lv_event_t *e);
    extern void action_label6_event(lv_event_t *e);
    extern void action_label7_event(lv_event_t *e);
    extern void action_label8_event(lv_event_t *e);
    extern void action_label9_event(lv_event_t *e);
    extern void action_label10_event(lv_event_t *e);
    extern void action_terminal_back_btn_event(lv_event_t *e);

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/