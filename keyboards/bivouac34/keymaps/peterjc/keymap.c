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

// The core letters:
const uint16_t PROGMEM combo_Q[] = {KC_G,KC_M,COMBO_END};
const uint16_t PROGMEM combo_V[] = {KC_P,KC_G,COMBO_END};
const uint16_t PROGMEM combo_X[] = {KC_F,KC_D,COMBO_END};
const uint16_t PROGMEM combo_Z[] = {KC_QUOT,KC_MINS,COMBO_END};
// 3-key horizontal
const uint16_t PROGMEM combo_tab[] = {KC_F,KC_D,KC_L,COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_U,KC_O,KC_Y,COMBO_END};
// 2-key horizontal HRM
const uint16_t PROGMEM combo_lalt[] = {KC_S,KC_N,COMBO_END};
const uint16_t PROGMEM combo_lctl[] = {KC_N,KC_T,COMBO_END};
const uint16_t PROGMEM combo_lgui[] = {KC_T,KC_H,COMBO_END};
const uint16_t PROGMEM combo_ralt[] = {KC_C,KC_I,COMBO_END};
const uint16_t PROGMEM combo_rctl[] = {KC_I,KC_E,COMBO_END};
const uint16_t PROGMEM combo_rgui[] = {KC_E,KC_A,COMBO_END};
// 2-key vertical symbols, left
const uint16_t PROGMEM combo_btick[] = {KC_S,KC_ESC,COMBO_END};
const uint16_t PROGMEM combo_at[] = {KC_N,KC_P,COMBO_END};
const uint16_t PROGMEM combo_pound[] = {KC_T,KC_G,COMBO_END};
const uint16_t PROGMEM combo_dollar[] = {KC_H,KC_M,COMBO_END};
const uint16_t PROGMEM combo_bslash[] = {KC_K,KC_J,COMBO_END};
// 2-key vertical symbols, right
const uint16_t PROGMEM combo_slash[] = {KC_COMM,KC_DOT,COMBO_END};
const uint16_t PROGMEM combo_amp[] = {KC_A,KC_BSPC,COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_E,KC_QUOT,COMBO_END};
const uint16_t PROGMEM combo_excl[] = {KC_I,KC_MINS,COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_C,KC_EQL,COMBO_END};
// 2-key brackets etc on inner column, left:
const uint16_t PROGMEM combo_percent[] = {KC_M,KC_K,COMBO_END};
const uint16_t PROGMEM combo_open_curly[] = {KC_H,KC_K,COMBO_END};
const uint16_t PROGMEM combo_open_bracket[] = {KC_H,KC_J,COMBO_END};
const uint16_t PROGMEM combo_open_square[] = {KC_L,KC_J,COMBO_END};
// 2-key brackets etc on inner column, right:
const uint16_t PROGMEM combo_caret[] = {KC_DOT,KC_BSPC,COMBO_END};
const uint16_t PROGMEM combo_close_curly[] = {KC_DOT,KC_A,COMBO_END};
const uint16_t PROGMEM combo_close_bracket[] = {KC_COMM,KC_A,COMBO_END};
const uint16_t PROGMEM combo_close_square[] = {KC_COMM,KC_U,COMBO_END};

combo_t key_combos[] = {
  COMBO(combo_Q, KC_Q),
  COMBO(combo_V, KC_V),
  COMBO(combo_X, KC_X),
  COMBO(combo_Z, KC_Z),
  // 3-key horizontal
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_ent, KC_ENT),
  // 2-key horizontal HRM
  COMBO(combo_lalt, KC_LALT),
  COMBO(combo_lctl, KC_LCTL),
  COMBO(combo_lgui, KC_LGUI),
  COMBO(combo_ralt, KC_RALT),
  COMBO(combo_rctl, KC_RCTL),
  COMBO(combo_rgui, KC_RGUI),
  // 2-key vertical symbols, left
  COMBO(combo_btick, KC_GRV),
  COMBO(combo_at, S(KC_QUOT)),
  COMBO(combo_pound, S(KC_3)),
  COMBO(combo_dollar, S(KC_4)),
  COMBO(combo_bslash, KC_NUBS),
  // 2-key vertical symbols, right
  COMBO(combo_slash, KC_SLSH),
  COMBO(combo_amp, S(KC_7)),
  COMBO(combo_hash, KC_NUHS),
  COMBO(combo_excl, S(KC_1)),
  COMBO(combo_tilde, S(KC_NUHS)),
  // 2-key brackets etc on inner column, left
  COMBO(combo_percent, S(KC_5)),
  COMBO(combo_open_curly, S(KC_LBRC)),
  COMBO(combo_open_bracket, S(KC_9)),
  COMBO(combo_open_square, KC_LBRC),
  // 2-key brackets etc on inner column, right
  COMBO(combo_caret, S(KC_6)),
  COMBO(combo_close_curly, S(KC_RBRC)),
  COMBO(combo_close_bracket, S(KC_0)),
  COMBO(combo_close_square, KC_RBRC),
 };

#endif
