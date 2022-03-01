#ifndef USERSPACE
#define USERSPACE

#pragma once

#include "quantum.h"
#include "color.h"

enum user_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
};

enum user_layers {
  _WORKMAN,
  _QWERTY,
  _FN1_LAYER,
  _FN2_LAYER,
};

// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_HUE_WAVE
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

#endif
