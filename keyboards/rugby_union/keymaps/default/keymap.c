// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Physical layout close to this:
      *
      * ┌───┬───┬───┬───┐          ┌───┬───┬───┬───┐
      * │ Q │ W │ E │ R ├───┐  ┌───┤ U │ I │ O │ P │
      * ├───┼───┼───┼───┤ T │  │ Y ├───┼───┼───┼───┤
      * │ A │ S │ D │ F ├───┤  ├───┤ J │ K │ L │ ; │
      * ├───┼───┼───┼───┤ G │  │ H ├───┼───┼───┼───┤
      * │ Z │ X │ C │ V ├───┘  └───┤ M │ , │ . │ / │
      * └───┴───┴───┴───┘          └───┴───┴───┴───┘
      *                 ┌───┐  ┌───┐
      *                 │ B │  │ N │
      *                 └───┘  └───┘
      *
      * The logical layout here is 3 rows of 10:
      *
      * Q 	W 	E 	R 	T 		Y 	U 	I 	O 	P
      * A 	S 	D 	F 	G 		H 	J 	K 	L 	;
      * Z 	X 	C 	V 	B 		N 	M 	, 	. 	/
      *
      */
    [0] = LAYOUT_default(
        KC_Q, KC_W, KC_E, KC_R, KC_T,      KC_Y, KC_U, KC_I,    KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G,      KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
        KC_Z, KC_X, KC_C, KC_V, KC_B,      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
    )
};
