#include "images.h"

const ext_img_desc_t images[12] = {
    { "active_nodes", &img_active_nodes },
    { "active_nodes_active", &img_active_nodes_active },
    { "group_message", &img_group_message },
    { "group_message_active", &img_group_message_active },
    { "received_messages", &img_received_messages },
    { "received_messages_active", &img_received_messages_active },
    { "sent_messages", &img_sent_messages },
    { "sent_messages_active", &img_sent_messages_active },
    { "Spec5", &img_spec5 },
    { "Spec5_active", &img_spec5_active },
    { "terminal", &img_terminal },
    { "terminal_active", &img_terminal_active },
};
