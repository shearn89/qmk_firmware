#include "shearn89.h"

HSV hsv;
int lastMode;
int lastSpeed;
int modSpeed = 255;
int brightness = 125;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
	rgb_matrix_sethsv(170, 255, brightness);
	rgb_matrix_set_speed(127);
	rgb_matrix_mode(RGB_MATRIX_HUE_PENDULUM);

	lastSpeed = 127;
	lastMode = RGB_MATRIX_HUE_PENDULUM;
	hsv = rgb_matrix_get_hsv();

      	autoshift_disable();
	set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case CLMAKDH:
      if (record->event.pressed) {
	rgb_matrix_sethsv(10, 200, brightness);
	rgb_matrix_set_speed(50);
	rgb_matrix_mode(RGB_MATRIX_HUE_PENDULUM);

	lastSpeed = 50;
	lastMode = RGB_MATRIX_HUE_PENDULUM;
	hsv = rgb_matrix_get_hsv();

      	autoshift_enable();
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

__attribute__((weak)) void keyboard_post_init_user(void) {
  lastMode = rgb_matrix_get_mode();
  hsv = rgb_matrix_get_hsv();
}

// matrix effects are done with HSV, so set HSV colors
__attribute__((weak)) layer_state_t layer_state_set_user(layer_state_t layer) {
  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
      rgb_matrix_set_speed(modSpeed);
      rgb_matrix_sethsv_noeeprom(85, 255, brightness); //green
      break;
    case _FN2_LAYER:
      rgb_matrix_mode_noeeprom(RGB_MATRIX_BREATHING);
      rgb_matrix_set_speed(modSpeed);
      rgb_matrix_sethsv_noeeprom(0, 255, brightness); // red
      break;
    default:
      rgb_matrix_mode_noeeprom(lastMode);
      rgb_matrix_set_speed(lastSpeed);
      rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v); // reset
      break;
  }
  return layer;
}

__attribute__((weak)) void suspend_power_down_kb(void) {
  rgb_matrix_set_suspend_state(true);
}

__attribute__((weak)) void suspend_wakeup_init_kb(void) {
  rgb_matrix_set_suspend_state(false);
}
