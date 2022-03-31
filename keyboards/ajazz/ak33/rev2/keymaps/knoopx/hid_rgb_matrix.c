void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id   = &(data[0]);
    uint8_t *command_data = &(data[1]);
    switch (*command_id) {
        case id_lighting_set_value: {
            backlight_set_value(command_data);
            break;
        }
        case id_lighting_get_value: {
            backlight_get_value(command_data);
            break;
        }
        case id_lighting_save: {
            backlight_config_save();
            break;
        }
        default: {
            // Unhandled message.
            *command_id = id_unhandled;
            break;
        }
    }
}