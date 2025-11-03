//==============================================================================
//
//  actions.c
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

#include "lvgl.h"
#include "actions.h"
#include "screens.h"
#include <stdio.h>

#include <string.h> // for strcpy

char active_nodes[10][30] = {
    "User_Ahmad_1023",
    "User_Sara_2045",
    "User_Zain_3101",
    "User_Ayesha_1189",
    "User_Talha_4520",
    "User_Mina_6732",
    "User_Hassan_7810",
    "User_Laiba_2299",
    "User_Fahad_3902",
    "User_Nida_5477"};

char sent_messages[10][150] = {
    "1. Temperature reading request initiated at 10:32 AM.",
    "2. Device status check command issued successfully.",
    "3. Firmware update package transmitted to node A12.",
    "4. Alert triggered due to threshold breach in sensor 3.",
    "5. Synchronization signal dispatched to all connected modules.",
    "6. Configuration parameters uploaded to remote unit.",
    "7. Heartbeat signal sent to maintain active connection.",
    "8. Data logging enabled for environmental metrics.",
    "9. Request for historical data from last 24 hours.",
    "10. Shutdown command issued for non-responsive device."};

char recieved_messages[10][150] = {
    "1. Temperature reading acknowledged, value is 24.7°C.",
    "2. Device status is normal, all systems operational.",
    "3. Firmware update completed successfully on node A12.",
    "4. Alert confirmed, initiating safety protocol sequence.",
    "5. Synchronization complete across all active modules.",
    "6. Configuration parameters accepted and applied.",
    "7. Heartbeat acknowledged, connection stable.",
    "8. Data logging active, metrics being recorded.",
    "9. Historical data retrieved and ready for analysis.",
    "10. Shutdown confirmed, device powered down safely."};

// strcpy(messages[0], "New text");

//==============================================================================
//
//   void textarea_event_cb(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void show_active_nodes_list()
{
    hide_all_containers();
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t *labels[] = {
        objects.label1,
        objects.label2,
        objects.label3,
        objects.label4,
        objects.label5,
        objects.label6,
        objects.label7,
        objects.label8,
        objects.label9,
        objects.label10};

    for (int i = 0; i < 10; i++)
    {
        lv_label_set_text(labels[i], active_nodes[i]);
        lv_obj_clear_flag(labels[i], LV_OBJ_FLAG_HIDDEN);
    }
}

//==============================================================================
//
//   void textarea_event_cb(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void show_recieved_msgs_list()
{
    hide_all_containers();
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t *labels[] = {
        objects.label1,
        objects.label2,
        objects.label3,
        objects.label4,
        objects.label5,
        objects.label6,
        objects.label7,
        objects.label8,
        objects.label9,
        objects.label10};

    for (int i = 0; i < 10; i++)
    {
        lv_label_set_text(labels[i], recieved_messages[i]);
        lv_obj_clear_flag(labels[i], LV_OBJ_FLAG_HIDDEN);
    }
}

//==============================================================================
//
//   void textarea_event_cb(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void show_sent_msgs_list()
{
    hide_all_containers();
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t *labels[] = {
        objects.label1,
        objects.label2,
        objects.label3,
        objects.label4,
        objects.label5,
        objects.label6,
        objects.label7,
        objects.label8,
        objects.label9,
        objects.label10};

    for (int i = 0; i < 10; i++)
    {
        lv_label_set_text(labels[i], sent_messages[i]);
        lv_obj_clear_flag(labels[i], LV_OBJ_FLAG_HIDDEN);
    }
}

//==============================================================================
//
//   action_go_to_home(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void show_labels()
{

    lv_obj_t *labels[] = {
        objects.label1,
        objects.label2,
        objects.label3,
        objects.label4,
        objects.label5,
        objects.label6,
        objects.label7,
        objects.label8,
        objects.label9,
        objects.label10};

    for (int i = 0; i < 10; i++)
    {
        lv_obj_clear_flag(labels[i], LV_OBJ_FLAG_HIDDEN);
    }
}
//==============================================================================
//
//   action_go_to_home(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//

//==============================================================================
void hide_labels()
{

    lv_obj_t *labels[] = {
        objects.label1,
        objects.label2,
        objects.label3,
        objects.label4,
        objects.label5,
        objects.label6,
        objects.label7,
        objects.label8,
        objects.label9,
        objects.label10};

    for (int i = 0; i < 10; i++)
    {
        lv_obj_add_flag(labels[i], LV_OBJ_FLAG_HIDDEN);
    }
}

//==============================================================================
//
//   action_go_to_home(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void hide_all_containers()
{

    lv_obj_add_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.input_text_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.terminal_container, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(objects.spec5_home_container, LV_OBJ_FLAG_HIDDEN);
}

//==============================================================================
//
//   action_go_to_settings(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_spec5_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Spec5 Home");
    lv_obj_clear_flag(objects.spec5_home_container, LV_OBJ_FLAG_HIDDEN);
}

//==============================================================================
//
//   action_go_to_home(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_nodes_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Active Nodes");
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);
    show_active_nodes_list();
}

//==============================================================================
//
//   void action_update_critical_values(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_grp_msg_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Group Message");
    lv_obj_clear_flag(objects.input_text_container, LV_OBJ_FLAG_HIDDEN);
}

//==============================================================================
//
//   void textarea_event_cb(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_rcvd_msgs_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Recieved Msgs");
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);
    show_recieved_msgs_list();
}

//==============================================================================
//
//   void keypad_event_cb(lv_event_t *e)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_sent_msgs_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Sent Messages");
    lv_obj_clear_flag(objects.label_list_container, LV_OBJ_FLAG_HIDDEN);
    show_sent_msgs_list();
    // lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    // lv_textarea_set_text(objects.my_textbox, "New text");
}

//==============================================================================
//
//   void init_sensor_data()
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_terminal_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Terminal");
    lv_obj_clear_flag(objects.terminal_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.terminal_text_area, "");
}

//==============================================================================
//
//   void update_sensor_display_cb(lv_timer_t *timer)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_send_txt_btn_event(lv_event_t *e)
{
    printf("Node 1 clicked!\n");
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label1_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[0]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label2_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[1]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label3_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[2]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label4_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[3]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label5_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[4]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label6_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[5]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label7_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[6]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label8_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[7]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label9_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[8]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_label10_event(lv_event_t *e)
{
    hide_all_containers();
    lv_obj_clear_flag(objects.text_container, LV_OBJ_FLAG_HIDDEN);
    lv_textarea_set_text(objects.msg_text_area, "");
    // lv_textarea_add_text(objects.my_textbox, "Hello");
    lv_textarea_set_text(objects.msg_text_area, recieved_messages[9]);
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_back_from_msg_btn_event(lv_event_t *e)
{
    printf("Node 1 clicked!\n");
}

//==============================================================================
//
//   void populate_critical_inputs(void)
//
//   Author:   M. Zakriya
//   Date:     13/07/2025
//
//!
//
//==============================================================================
void action_terminal_back_btn_event(lv_event_t *e)
{
    hide_all_containers();
    lv_label_set_text(objects.title_header_label, "Spec5 Home");
    lv_obj_clear_flag(objects.spec5_home_container, LV_OBJ_FLAG_HIDDEN);
}
