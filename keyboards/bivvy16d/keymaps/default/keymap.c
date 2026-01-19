// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┐                   ┌───┬───┬───┬───┐
      * │ Q │ W │ E │ R ├───┐           ┌───┤ U │ I │ O │ P │
      * ├───┼───┼───┼───┤ T │           │ Y ├───┼───┼───┼───┤
      * │ A │ S │ D │ F ├───┤           ├───┤ J │ K │ L │ ; │
      * ├───┼───┼───┼───┤ G │           │ H ├───┼───┼───┼───┤
      * │ Z │ X │ C │ V ├───┘           └───┤ M │ , │ . │ / │
      * └───┴───┴───┴───┘                   └───┴───┴───┴───┘
      *                 ┌───┬───┐  ┌───┬───┐ 
      *                 │ B │BkS│  │SPC│ N │
      *                 └───┴───┘  └───┴───┘
      * Home-row mods,
      * ASDF are Left-GUI,    Left-Alt,  Left-Ctrl, Left-Shift
      * JKL; are Right-Shift, Left-Ctrl, Left-Alt,  Left-GUI
      */
    [0] = LAYOUT_L16R16(
        KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,      KC_Y,     KC_U,               KC_I,               KC_O,                KC_P,
        MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G,      KC_H,     MT(MOD_RSFT, KC_J), MT(MOD_LCTL, KC_K), MT(MOD_LALT, KC_L),  MT(MOD_LGUI, KC_SCLN),
        KC_Z,               KC_X,               KC_C,               KC_V,                                    KC_M,               KC_COMM,            KC_DOT,              KC_SLSH,
                                                                    KC_B,               KC_BSPC,   KC_SPC,   KC_N
    )
};
