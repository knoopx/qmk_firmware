#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
#include "rgb_matrix_user.h"

#define PASSWORD_GENERATOR_LENGTH 16

#define RGB_MATRIX_IDLE_TIMEOUT 1000 * 30
#define RGB_MATRIX_IDLE_MODE RGB_MATRIX_BREATHING

static uint8_t rgb_matrix_idle_prev_mode;
static bool    rgb_matrix_idle_state = false;

void housekeeping_task_user(void) {
  // idle?
  if (!rgb_matrix_idle_state &&
      last_input_activity_elapsed() > RGB_MATRIX_IDLE_TIMEOUT) {
    rgb_matrix_idle_prev_mode = rgb_matrix_get_mode();
    rgb_matrix_idle_state = true;
    rgb_matrix_set_flags(LED_FLAG_ALL);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_IDLE_MODE);
  }
}

// case ES_LSPO:
//   perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_8);
//   return false;
// case ES_RSPC:
//   perform_space_cadet(record, keycode, KC_LSFT, KC_LSFT, KC_9);
//   return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (rgb_matrix_idle_state) {
    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
    rgb_matrix_mode_noeeprom(rgb_matrix_idle_prev_mode);
    rgb_matrix_idle_state = false;
  }

  switch (keycode) {
#ifdef VIA_ENABLE
  case USER00:
    if (record->event.pressed) {
      for (int i = 0; i < PASSWORD_GENERATOR_LENGTH; i++) {
        tap_random_base64();
      }
      false;
    }
    break;
#endif
  }
  return true;
}
