#include QMK_KEYBOARD_H

// disable any led unless on layer 0
bool led_update_user(led_t led_state) {
    if (get_highest_layer(layer_state) == 0) {
        return true;
    }
    writePin(LED_CAPS_LOCK_PIN, 1);
    return false;
}