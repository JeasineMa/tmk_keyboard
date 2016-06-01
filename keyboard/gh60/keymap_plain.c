#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {	
  /* 0: qwerty */
    KEYMAP_HHKB(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,BSPC,NO, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,        \
           CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,  ENT,			 \
           LSFT,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,UP,  GRV,			 \
           LCTL,LGUI,LALT,          SPC,                     RALT,LEFT,DOWN,RIGHT),

//	KEYMAP_ANSI(
//        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, TRNS, \
//        TRNS,FN2, UP,  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,CALC,TRNS,HOME,INS, FN4,  \
//        TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,PSCR,SLCK,PAUS,TRNS,FN3, END,      TRNS, \
//        TRNS,DEL, TRNS,WHOM,MUTE,VOLU,VOLD,TRNS,PGUP,PGDN,DEL,           TRNS, \

};

const uint16_t PROGMEM fn_actions[] = {};
#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif 
