#ifndef USERSPACE
#define USERSPACE

#pragma once

#include "quantum.h"

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

#endif
