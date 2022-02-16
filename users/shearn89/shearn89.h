#ifndef USERSPACE
#define USERSPACE

#pragma once

#include "quantum.h"
#include "annepro2.h"

enum ap_keycodes {
  QWERTY = AP2_SAFE_RANGE,
  WORKMAN,
};

enum anne_pro_layers {
  _WORKMAN,
  _QWERTY,
  _FN1_LAYER,
  _FN2_LAYER,
};

// turn off leds when pc sleeps
#define RGBLIGHT_SLEEP
// turn on leds
#define RGBLIGHT_ENABLE

#endif
