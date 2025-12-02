// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐             ┌───┬───┬───┬───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │             │ Y │ U │ I │ O │ P │ + │ 7 │ 8 │ 9 │
      * └───┼───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┼───┼───┼───┼───┤
      *     │ A │ S │ D │ F │ G │             │ H │ J │ K │ L │ - │   │ 4 │ 5 │ 6 │
      *     ├───┼───┼───┼───┼───┤             ├───┼───┼───┼───┼───┤   ├───┼───┼───┤   
      *     │ Z │ X │ C │ V │ B │             │ N │ M │ , │ . │ / │   │ 1 │ 2 │ 3 │
      *     └───┴───┴───┴───┴───┼────┬────┬───┼───┴───┴───┴───┼───┤   ├───┼───┴───┘ 
      *     ┌─────┐             │BkSp│Shft│Spc├───┬───┬───┬───┤ * │   │ 0 │ ┌─────┐
      *     │ Tab │             └────┴────┴───┤ ← │ ↓ │ ↑ │ → ├───┘   └───┘ │Enter│
      *     └─────┘                           └───┴───┴───┴───┘             └─────┘
      
      * Home-row mods,
      * ASDF are Left-GUI,    Left-Alt,  Left-Ctrl, Left-Shift
      * JKL- are Right-Shift, Left-Ctrl, Left-Alt,  Left-GUI
      */
    [0] = LAYOUT(
        KC_ESC, KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,      KC_Y,     KC_U,               KC_I,               KC_O,                KC_P,                  KP_EQUAL, KP_7, KP_8, KP_9,
                MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G,      KC_H,     MT(MOD_RSFT, KC_J), MT(MOD_LCTL, KC_K), MT(MOD_LALT, KC_L),  MT(MOD_LGUI, KC_MINUS),          KP_4, KP_5, KP_6,
                KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,      KC_N,     KC_M,               KC_COMM,            KC_DOT,              KC_SLSH,                         KP_1, KP_2, KP_3,
                KC_TAB,                                                                    KC_BSPC, KC_LSHFT,  KC_SPC,       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,                   KC_KP_ASTERISK,                  KC_0,    KC_ENT
    )
};
