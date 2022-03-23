#ifndef USERSPACE
#define USERSPACE

#pragma once

#include "quantum.h"
#include "color.h"

// set startup RGB mode to mostly-static
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_HUE_WAVE

enum user_keycodes {
  QWERTY = SAFE_RANGE,
  WORKMAN,
  CLMAKDH,
};

enum user_layers {
  _QWERTY,
  _WORKMAN,
  _CLMAKDH,
  _FN1_LAYER,
  _FN2_LAYER,
};

#endif
