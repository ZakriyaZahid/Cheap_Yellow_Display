#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main()
{
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff81baf4), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // spec5_home_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.spec5_home_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(11));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(88));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // active_nodes_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.active_nodes_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(5));
                    lv_obj_set_size(obj, LV_PCT(80), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_nodes_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_spec5_home_page_labels(obj);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Active Nodes");
                }
                {
                    // group_message_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.group_message_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(20));
                    lv_obj_set_size(obj, LV_PCT(80), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_grp_msg_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_spec5_home_page_labels(obj);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Group Message");
                }
                {
                    // received_message_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.received_message_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(35));
                    lv_obj_set_size(obj, LV_PCT(80), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_rcvd_msgs_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_spec5_home_page_labels(obj);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Received Messages");
                }
                {
                    // sent_message_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.sent_message_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(50));
                    lv_obj_set_size(obj, LV_PCT(80), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_sent_msgs_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_spec5_home_page_labels(obj);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Sent Messages");
                }
                {
                    // terminal_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.terminal_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(65));
                    lv_obj_set_size(obj, LV_PCT(80), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_terminal_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_spec5_home_page_labels(obj);
                    lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Terminal");
                }
            }
        }
        {
            // header_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.header_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(1));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(10));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // title_header_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.title_header_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(5), LV_PCT(10));
                    lv_obj_set_size(obj, LV_PCT(50), LV_PCT(80));
                    lv_label_set_text(obj, "Spec5 Home");
                }
                {
                    // info_header_label
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.info_header_label = obj;
                    lv_obj_set_pos(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_set_size(obj, LV_PCT(40), LV_PCT(80));
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // terminal_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.terminal_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(11));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(88));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // terminal_back_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.terminal_back_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(2), LV_PCT(92));
                    lv_obj_set_size(obj, LV_PCT(20), LV_PCT(7));
                    lv_obj_add_event_cb(obj, action_terminal_back_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_add_event_cb(obj, action_back_from_msg_btn_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "back");
                        }
                    }
                }
                {
                    // terminal_text_area
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.terminal_text_area = obj;
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(90));
                    lv_textarea_set_max_length(obj, 1000);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // left_icon_bar
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.left_icon_bar = obj;
            lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
            lv_obj_set_size(obj, LV_PCT(20), LV_PCT(100));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffc78080), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(28));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "   Nodes");
                }
                {
                    // spec5_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.spec5_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(17), LV_PCT(3));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_spec5_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_spec5, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_spec5_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // nodes_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.nodes_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(10), LV_PCT(18));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_nodes_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_active_nodes, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_active_nodes_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // recieved_messages_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.recieved_messages_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(10), LV_PCT(50));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_rcvd_msgs_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_received_messages, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_recolor_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_received_messages_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // sent_messages_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.sent_messages_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(10), LV_PCT(65));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_sent_msgs_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_sent_messages, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_sent_messages_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    // group_messages_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.group_messages_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(10), LV_PCT(34));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_grp_msg_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_group_message, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_group_message_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(43));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, " Grp Msg");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(60));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, " Rcvd Msgs");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(75));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "  Sent Msgs");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(12));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "    spec5");
                }
                {
                    // terminal_icon_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.terminal_icon_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(10), LV_PCT(80));
                    lv_obj_set_size(obj, LV_PCT(60), LV_PCT(10));
                    lv_obj_add_event_cb(obj, action_terminal_btn_event, LV_EVENT_PRESSED, (void *)0);
                    add_style_left_menu_button_style(obj);
                    lv_obj_set_style_bg_image_src(obj, &img_terminal, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_image_src(obj, &img_terminal_active, LV_PART_MAIN | LV_STATE_PRESSED);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(90));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(7));
                    add_style_left_menu_label_style(obj);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "  Terminal");
                }
            }
        }
        {
            // input_text_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.input_text_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(11));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(88));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // send_input_text_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.send_input_text_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(78), LV_PCT(92));
                    lv_obj_set_size(obj, LV_PCT(20), LV_PCT(7));
                    lv_obj_add_event_cb(obj, action_send_txt_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Send");
                        }
                    }
                }
                {
                    // input_text_area
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.input_text_area = obj;
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(90));
                    lv_textarea_set_max_length(obj, 1000);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // label_list_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.label_list_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(11));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(88));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff6f2d2d), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // label_list
                    lv_obj_t *obj = lv_list_create(parent_obj);
                    objects.label_list = obj;
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(100));
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // label1
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label1 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label1_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label1");
                        }
                        {
                            // label2
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label2 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label2_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label2");
                        }
                        {
                            // label3
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label3 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label3_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label3");
                        }
                        {
                            // label4
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label4 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label4_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label4");
                        }
                        {
                            // label5
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label5 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label5_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label5");
                        }
                        {
                            // label6
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label6 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label6_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label6");
                        }
                        {
                            // label7
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label7 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label7_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label7");
                        }
                        {
                            // label8
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label8 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label8_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label8");
                        }
                        {
                            // label9
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label9 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label9_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label9");
                        }
                        {
                            // label10
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            objects.label10 = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_PCT(100), LV_PCT(10));
                            lv_label_set_long_mode(obj, LV_LABEL_LONG_DOT);
                            lv_obj_add_event_cb(obj, action_label10_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_CLICKABLE);
                            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                            add_style_list_labels(obj);
                            lv_label_set_text(obj, "label10");
                        }
                    }
                }
            }
        }
        {
            // text_container
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.text_container = obj;
            lv_obj_set_pos(obj, LV_PCT(20), LV_PCT(11));
            lv_obj_set_size(obj, LV_PCT(78), LV_PCT(88));
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // back_from_text_btn
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    objects.back_from_text_btn = obj;
                    lv_obj_set_pos(obj, LV_PCT(2), LV_PCT(92));
                    lv_obj_set_size(obj, LV_PCT(20), LV_PCT(7));
                    lv_obj_add_event_cb(obj, action_send_txt_btn_event, LV_EVENT_PRESSED, (void *)0);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            lv_obj_add_event_cb(obj, action_back_from_msg_btn_event, LV_EVENT_PRESSED, (void *)0);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "back");
                        }
                    }
                }
                {
                    // msg_text_area
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.msg_text_area = obj;
                    lv_obj_set_pos(obj, LV_PCT(0), LV_PCT(0));
                    lv_obj_set_size(obj, LV_PCT(100), LV_PCT(90));
                    lv_textarea_set_max_length(obj, 1000);
                    lv_textarea_set_one_line(obj, false);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
    }

    tick_screen_main();
}

void tick_screen_main()
{
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index)
{
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId)
{
    tick_screen_funcs[screenId - 1]();
}

void create_screens()
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);

    create_screen_main();
}
