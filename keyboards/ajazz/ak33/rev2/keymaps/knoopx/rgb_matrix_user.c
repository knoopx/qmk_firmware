#include QMK_KEYBOARD_H

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t layer = get_highest_layer(layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t  index  = g_led_config.matrix_co[row][col];
            keypos_t keypos = {col, row};

            if (g_led_config.flags[index] == LED_FLAG_NONE) {
                rgb_matrix_set_color(index, RGB_OFF);
                continue;
            }

            // caps lock indicator
            if (row == 3 && col == 0) {
                if (host_keyboard_led_state().caps_lock) {
                    g_led_config.flags[index] = LED_FLAG_INDICATOR;
                } else {
                    g_led_config.flags[index] = keymap_key_to_keycode(layer, keypos) == KC_TRNS ? LED_FLAG_NONE : LED_FLAG_KEYLIGHT;
                }
            }

            if (g_led_config.flags[index] == LED_FLAG_INDICATOR) {
                rgb_matrix_set_color(index, RGB_RED);
                continue;
            }
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t  index  = g_led_config.matrix_co[row][col];
            keypos_t keypos = {col, row};

            // transparent keys
            if (keymap_key_to_keycode(layer, keypos) == KC_TRNS) {
                g_led_config.flags[index] = LED_FLAG_NONE;
                continue;
            }

            g_led_config.flags[index] = LED_FLAG_KEYLIGHT;
        }
    }

    return state;
}
