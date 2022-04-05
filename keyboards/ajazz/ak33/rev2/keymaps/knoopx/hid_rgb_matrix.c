void backlight_get_value(uint8_t *data) {
  uint8_t *value_id = &(data[0]);
  uint8_t *value_data = &(data[1]);
  switch (*value_id) {
  case id_qmk_backlight_brightness: {
    // level / BACKLIGHT_LEVELS * 255
    value_data[0] =
        ((uint16_t)kb_backlight_config.level) * 255 / BACKLIGHT_LEVELS;
    break;
  }
  case id_qmk_backlight_effect: {
    value_data[0] = kb_backlight_config.breathing ? 1 : 0;
    break;
  }
  }
}

void backlight_set_value(uint8_t *data) {
  uint8_t *value_id = &(data[0]);
  uint8_t *value_data = &(data[1]);
  switch (*value_id) {
  case id_qmk_backlight_brightness: {
    // level / 255 * BACKLIGHT_LEVELS
    kb_backlight_config.level =
        ((uint16_t)value_data[0]) * BACKLIGHT_LEVELS / 255;
    backlight_set(kb_backlight_config.level);
    break;
  }
  case id_qmk_backlight_effect: {
    if (value_data[0] == 0) {
      kb_backlight_config.breathing = false;
      breathing_disable();
    } else {
      kb_backlight_config.breathing = true;
      breathing_enable();
    }
    break;
  }
  }
}

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
  uint8_t *command_id = &(data[0]);
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
