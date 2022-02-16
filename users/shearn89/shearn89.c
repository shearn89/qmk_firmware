#include "shearn89.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // // Useful in future?
  // update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
    default:
      return true;
  }
  return true;
}

__attribute__((weak)) void keyboard_post_init_user(void) {}
__attribute__((weak)) void suspend_power_down_user(void) {}
__attribute__((weak)) void matrix_init_user(void) { }
__attribute__((weak)) void matrix_scan_user(void) { }
