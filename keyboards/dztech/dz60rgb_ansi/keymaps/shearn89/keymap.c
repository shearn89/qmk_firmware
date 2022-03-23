#include QMK_KEYBOARD_H
#include "shearn89.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_QWERTY] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN1_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_RCTL
),
 [_WORKMAN] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN1_LAYER), KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, KC_I, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z, KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_RCTL
),
 [_CLMAKDH] = LAYOUT_60_ansi(
    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(_FN1_LAYER), KC_A, KC_R, KC_S, KC_T, KC_G, KC_M, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_ENT,
    KC_LSFT, KC_X, KC_C, KC_D, KC_V, KC_Z, KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN1_LAYER), MO(_FN2_LAYER), KC_RCTL
),
 [_FN1_LAYER] = LAYOUT_60_ansi(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_END, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______, _______, _______,
    _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, KC_MPLY, _______, _______, MO(_FN2_LAYER), _______
),
 [_FN2_LAYER] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, QWERTY,  _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______,
    _______, WORKMAN, _______, _______, _______, _______, _______, RGB_MOD, RGB_SPI, _______, _______, _______, _______,
    _______, CLMAKDH, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, RGB_TOG, _______, MO(_FN1_LAYER), _______, _______
 ),
};

/*
 * RGB_TOG - toggle
 * RGB_HUI - hue increase (supports shift)
 * RGB_SAI - saturation increase (supports shift)
 * RGB_VAI - brightness/value increase (supports shift)
 * RGB_MOD - mode cycle
 * RGB_SPI - mode speed (supports shift), not saved
 */
