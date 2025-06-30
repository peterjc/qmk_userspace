#pragma once

/* Randomly generated as per Vial docs */
#define VIAL_KEYBOARD_UID {0x1C, 0xF4, 0xA2, 0x03, 0x11, 0x30, 0xC7, 0x49}

#define DYNAMIC_KEYMAP_LAYER_COUNT 6

/* Original Gamma-Omega used keys 0,0 (Q) and 3,6 (P) */
/* with our sparse matrix those are 1,0 (Q) and 12,11 (P) instead. */
#define VIAL_UNLOCK_COMBO_ROWS { 1, 12 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 11 }
