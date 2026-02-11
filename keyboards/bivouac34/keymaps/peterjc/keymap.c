// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┐                 ┌───┬───┬───┬───┐
      * │Esc│ P(V)G(Q)M ├───┐         ┌───┤BkS│ '(Z)- │ + │
      * ├───┼───┼───┼───┤ K │         │ . ├───┼───┼───┼───┤
      * │ S │ N │ T │ H ├───┤         ├───┤ A │ E │ I │ C │
      * ├───┼───┼───┼───┤ J │         │ , ├───┼───┼───┼───┤
      * │ B │ F(X)D │ L ├───┘         └───┤ U │ O │ Y │ W │
      * └───┴───┴───┴───┘                 └───┴───┴───┴───┘
      *             ┌───┬───┬───┐ ┌───┬───┬───┐
      *             │<--│ R │BkS│ │RSh│Spc│-->│
      *             └───┴───┴───┘ └───┴───┴───┘
      * The above only shows the four letter combos (V, Q, Z and X, but not the symbols)
      */
    [0] = LAYOUT_split_3x5_2(
        KC_ESC,  KC_P,    KC_G,    KC_M,    KC_K,        KC_DOT,  KC_BSPC, KC_QUOT, KC_MINS, KC_EQL,
        KC_S,    KC_N,    KC_T,    KC_H,    KC_J,        KC_COMM, KC_A,    KC_E,    KC_I,    KC_C,
        KC_B,    KC_F,    KC_D,    KC_L,    KC_LEFT,     KC_RGHT, KC_U,    KC_O,    KC_Y,    KC_W,
                                   KC_R,    KC_BSPC,     KC_RSFT, LT(1, KC_SPC)
    ),
    [1] = LAYOUT_split_3x5_2(
        KC_PSLS, KC_1,    KC_2,    KC_3,    KC_PPLS,     KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_MPLY,
        KC_PAST, KC_4,    KC_5,    KC_6,    KC_PMNS,     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU,
        KC_PDOT, KC_7,    KC_8,    KC_9,    KC_TRNS,     KC_TRNS, A(KC_LEFT), KC_ENT, A(KC_RGHT), KC_VOLD,
                      MT(MOD_LSFT,KC_0),    KC_TRNS,     KC_RSFT, KC_TRNS
    )
};

#ifdef COMBO_ENABLE
combo_t key_combos[] = {
  // The core letters:
  COMBO({KC_G,KC_M,COMBO_END},KC_Q),
  COMBO({KC_P,KC_G,COMBO_END},KC_V),
  COMBO({KC_F,KC_D,COMBO_END},KC_X),
  COMBO({KC_QUOT,KC_MINS,COMBO_END},KC_Z),
};
#endif
