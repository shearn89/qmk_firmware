#include <stdint.h>
#include "shearn89.h"
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    annepro2LedEnable();
    // annepro2LedSetProfile(1);
    // white = 0x80ff99
#endif
}

layer_state_t layer_state_set_user(layer_state_t layer) {
#ifdef RGBLIGHT_ENABLE
  switch(get_highest_layer(layer)) {
    case _FN1_LAYER:
      annepro2LedSetForegroundColor(0x00, 0xFF, 0x00);
      break;
    case _FN2_LAYER:
      annepro2LedSetForegroundColor(0x00, 0x00, 0xFF);
      break;
    default:
      annepro2LedSetForegroundColor(0xFF, 0x99, 0x00);
      // annepro2LedResetForegroundColor();
      break;
  }
#endif
  return layer;
}

