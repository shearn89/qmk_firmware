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
    case CLMAKDH:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CLMAKDH);
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
  // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  hsv = rgb_matrix_get_hsv();
}

// matrix effects are done with HSV, so set HSV colors
__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t layer) {
    switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
        rgb_matrix_sethsv_noeeprom(HSV_WHITE);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_WAVE);
        break;
    case _FN2_LAYER:
        rgb_matrix_sethsv_noeeprom(HSV_GREEN);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_WAVE);
        break;
    default:
        rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v); // red?
        rgb_matrix_mode_noeeprom(RGB_MATRIX_HUE_WAVE);
        break;
    }
    return layer;
}

// LED_FLAG_MODIFIER = mods
// LED_FLAG_KEYLIGHT = alphas

/*
// use this to do clever stuff with indicators or specific keys.
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#indicators
__attribute__((weak)) void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > _WORKMAN) {
        // disable effect?
        // rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
        // rgb_matrix_sethsv_noeeprom(HSV_OFF);

        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_CYAN);
                }
            }
        }
    }
}
*/

__attribute__((weak)) void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
}

__attribute__((weak)) void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
}
