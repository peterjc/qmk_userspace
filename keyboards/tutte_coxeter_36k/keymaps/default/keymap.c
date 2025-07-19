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

// Light our single RGB LED blue when caps lock is active.
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}       // Light 1 LEDs, starting with LED 1
);
// Light our single RGB LED cyan when keyboard layer 0 is active
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);
// Light our single RGB LED red when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);
// Light our single RGB LED purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
// Light our single RGB LED green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_GREEN}
);
// etc...

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {
    // Light up based on the layer
    rgblight_set_layer_state(2, layer_state_cmp(state, 1)); // Layer 1 active
    rgblight_set_layer_state(3, layer_state_cmp(state, 2)); // Layer 2 active
    rgblight_set_layer_state(4, layer_state_cmp(state, 3)); // Layer 3 active
    return state;
}
