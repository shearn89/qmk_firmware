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

__attribute__((weak)) void suspend_power_down_user(void) {}
__attribute__((weak)) void matrix_init_user(void) { }
__attribute__((weak)) void matrix_scan_user(void) { }


HSV hsv;

__attribute__((weak)) void keyboard_post_init_user(void) {
  rgb_matrix_mode(RGB_MATRIX_HUE_WAVE);
  hsv = rgb_matrix_get_hsv();
}

// matrix effects are done with HSV, so set HSV colors
__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t layer) {
    switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
        rgb_matrix_sethsv_noeeprom(HSV_CYAN);
        break;
    case _FN2_LAYER:
        rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
        break;
    default:
        rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
        break;
    }
    return layer;
}

// use this to do clever stuff with indicators or specific keys.
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#indicators
__attribute__((weak)) void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) { }
