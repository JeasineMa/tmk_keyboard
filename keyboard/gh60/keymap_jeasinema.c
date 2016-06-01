#include "keymap_common.h"
#include "led.h"
#include "action_layer.h"
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {	
  /* 0: qwerty */
    KEYMAP_HHKB(ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,BSPC,NO, \
           TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,        \
           LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,  ENT,			 \
           LSFT,  Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,UP,  GRV,			 \
           LCTL,LGUI,LALT,          SPC,                     FN0,LEFT,DOWN,RIGHT),
/*1:Fn layer*/
	KEYMAP_HHKB(
			ESC,   F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL, TRNS, \
			TRNS,FN4,FN5,FN6,TRNS,TRNS,   7,   8,   9,TRNS,PSCR,TRNS,TRNS,BSPC,      \
			TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,   4,   5,   6,TRNS,TRNS,TRNS,     PENT,      \
			LSFT, MNXT, MPRV, MPLY,TRNS,TRNS,   1,   2,   3,   0,TRNS,     PGUP,TRNS,      \
			TRNS,TRNS,LALT,          TRNS,                    TRNS,HOME,PGDN, END),



};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
   // [1] = ACTION_LAYER_MOMENTARY(2),
   // [2] = ACTION_LAYER_TAP_KEY(2, KC_3),
   // [3] = ACTION_FUNCTION(TRICKY_ESC),  // Shift + ESC -> ~ 
    [4] = ACTION_BACKLIGHT_TOGGLE(),
    [5] = ACTION_BACKLIGHT_DECREASE(),
    [6] = ACTION_BACKLIGHT_INCREASE(),
   // [7] = ACTION_FUNCTION(VIM_LAYOUT_ON),
   // [8] = ACTION_FUNCTION(VIM_LAYOUT_OFF),
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif 
