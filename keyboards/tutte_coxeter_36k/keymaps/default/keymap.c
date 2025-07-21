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

// Only have one LED at index zero:
const rgblight_segment_t PROGMEM my_num_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_caps_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);
const rgblight_segment_t PROGMEM my_scroll_lock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_compose_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_kana_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
// etc...

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_num_lock_layer,
    my_caps_lock_layer,
    my_scroll_lock_layer,
    my_compose_layer,
    my_kana_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.num_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.scroll_lock);
    rgblight_set_layer_state(3, led_state.compose);
    rgblight_set_layer_state(4, led_state.kana);
    return true;
}
