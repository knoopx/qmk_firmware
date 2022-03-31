#include QMK_KEYBOARD_H

#define PASSWORD_GENERATOR_LENGTH 16

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case USER00:
            if (record->event.pressed) {
                for (int i = 0; i < PASSWORD_GENERATOR_LENGTH; i++) {
                    tap_random_base64();
                }
                false;
            }
            break;
    }
    return true;
}
