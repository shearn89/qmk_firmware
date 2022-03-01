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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
    case _QWERTY:
        // rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_GOLDENROD);
        break;
    case _WORKMAN:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_GOLD);
        break;
    case _FN1_LAYER:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_GREEN);
        break;
    case _FN2_LAYER:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_CYAN);
        break;
    default: //  for any other layers, or the default layer
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        rgb_matrix_set_color_all(RGB_WHITE);
        break;
    }
  return state;
}
