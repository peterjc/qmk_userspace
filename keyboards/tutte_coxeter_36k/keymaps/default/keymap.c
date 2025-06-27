// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │Del├───┐           ┌───┤BkS│
      *           └───┤Tab├───┐   ┌───┤Esc├───┘
      *               └───┤Spc│   │Ent├───┘
      *                   └───┘   └───┘
      * Home-row mods,
      * ASDF are Left-GUI,    Left-Alt,  Left-Ctrl, Left-Shift
      * JKL; are Right-Shift, Left-Ctrl, Left-Alt,  Left-GUI
      */
    [0] = LAYOUT_split_3x5_3(
        KC_Q,               KC_W,               KC_E,               KC_R,               KC_T,      KC_Y,     KC_U,               KC_I,               KC_O,                KC_P,
        MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G,      KC_H,     MT(MOD_RSFT, KC_J), MT(MOD_LCTL, KC_K), MT(MOD_LALT, KC_L),  MT(MOD_LGUI, KC_SCLN),
        KC_Z,               KC_X,               KC_C,               KC_V,               KC_B,      KC_N,     KC_M,               KC_COMM,            KC_DOT,              KC_SLSH,
                                                KC_DEL,             KC_TAB,             KC_SPC,    KC_ENT,   KC_ESC,             KC_BSPC
    )
};
