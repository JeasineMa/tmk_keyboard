#include "keymap_common.h"
#include "led.h"
#include "action_layer.h"

/*
 * HHKB Layout
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
     * ,-----------------------------------------------------------.
     * |Esc| 1| 2 |3/FN2| 4|  5|  6|  7|  8|  9|  0|  -|  =| Bs|DEL|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L| ; |  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |  `|
     * |-----------------------------------------------------------|
     * |CAPS |Gui |Alt |      Space            | Fn0| Fn1| Alt|Ctrl|
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        FN3, 1,   2, FN2,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, GRV, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM, DOT, SLSH,    RSFT,FN1,       \
        CAPS,  LGUI,LALT,          SPC,                     FN0, RALT, RCTL, DEL),

    /* 1: FN0 Layer
     * ,-----------------------------------------------------------.
     * |` | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10|F11|F12|DEL|INS|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   | 7 | 8 | 9 |Psc |   |   |    |
     * |-----------------------------------------------------------|
     * |      |Mu |V- |V+ |   |   |   | 4 | 5 | 6 |   |   |        |
     * |-----------------------------------------------------------|
     * | Shift  |Blt|Bl↓|Bl↑|   |   | 0 | 1 | 2 | 3 | 0 | PgUp |   |
     * |-----------------------------------------------------------|
     * |    |    | Alt|                        |    |Home|PgDn|End |
     * `-----------------------------------------------------------'
     */


    KEYMAP_HHKB(
        GRV,   F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, DEL, INS, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   7,   8,   9,TRNS,PSCR,TRNS,TRNS,BSPC,      \
        TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,   4,   5,   6,TRNS,TRNS,TRNS,     PENT,      \
        LSFT, FN4, FN5, FN6,TRNS,TRNS,   1,   2,   3,   0,TRNS,     PGUP,TRNS,      \
        TRNS,TRNS,LALT,          TRNS,                    TRNS,HOME,PGDN, END),
    
	/* 2: FN1 vim layer
     * ,-----------------------------------------------------------.
     * |FN7|   |   |   |END|   |HOME|  |   |   |HOME|   |  |BSPC| `|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |PgU |INS|   |   |FN7|   | DEL|
     * |-----------------------------------------------------------|
     * |      |   |  |PgD |PgD |   |Left|Down|Up|Right|  |  |      |
     * |-----------------------------------------------------------|
     * | Shift  |   |   |   |PgU |   |   |   |   |   |   |  Up |   |
     * |-----------------------------------------------------------|
     * |    |    | Alt|                        |   |Left|Down|Right|
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        FN7, TRNS,TRNS,TRNS, END,TRNS,HOME,TRNS,TRNS,TRNS,HOME,TRNS,TRNS,BSPC,GRV, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP, INS,TRNS,TRNS, FN7,TRNS,DEL,      \
        TRNS,TRNS,TRNS,PGDN,PGDN,TRNS,LEFT,DOWN,  UP,RGHT,TRNS,TRNS,    TRNS,      \
        LSFT,   TRNS,DEL,TRNS,TRNS,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,   UP, TRNS,      \
        TRNS,TRNS,LALT,            TRNS,                  TRNS,LEFT,DOWN,RGHT),

	/* 3: FN7 vim layer
     * ,-----------------------------------------------------------.
     * |`  |   |   |   |END|   |HOME|  |   |   |HOME|   |  |BSPC| `|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |PgU |FN8|   |   |   |   | DEL|
     * |-----------------------------------------------------------|
     * |      |FN8|  |PgD |PgD |   |Left|Down|Up|Right|  |  |      |
     * |-----------------------------------------------------------|
     * | Shift  |   |   |   |PgU |   |   |   |   |   |   |  Up |   |
     * |-----------------------------------------------------------|
     * |    |    | Alt|                        |   |Left|Down|Right|
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        GRV, TRNS,TRNS,TRNS, END,TRNS,HOME,TRNS,TRNS,TRNS,HOME,TRNS,TRNS,BSPC,GRV, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP, FN8,TRNS,TRNS,TRNS,TRNS,DEL,      \
        TRNS, FN8,TRNS,PGDN,PGDN,TRNS,LEFT,DOWN,  UP,RGHT,TRNS,TRNS,    TRNS,      \
        LSFT,   TRNS,DEL,TRNS,TRNS,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,   UP, TRNS,      \
        TRNS,TRNS,LALT,            TRNS,                  TRNS,LEFT,DOWN,RGHT),
};


enum function_id {
    TRICKY_ESC,
	VIM_LAYOUT_ON,
	VIM_LAYOUT_OFF
};

void layer_on_off(uint8_t layer, bool state) {
	action_t action;
	if (state) {
		// layer on
		action.code = ACTION_LAYER_ON(layer, ON_PRESS);
	} else {
		// layer off
		action.code = ACTION_LAYER_OFF(layer, ON_PRESS);
	}
	// copied from /common/action.c
	uint8_t shift = action.layer_bitop.part*4;
	uint32_t bits = ((uint32_t)action.layer_bitop.bits)<<shift;
	uint32_t mask = (action.layer_bitop.xbit) ? ~(((uint32_t)0xf)<<shift) : 0;
	switch (action.layer_bitop.op) {
		case OP_BIT_AND: layer_and(bits | mask); break;
		case OP_BIT_OR:  layer_or(bits | mask);  break;
		case OP_BIT_XOR: layer_xor(bits | mask); break;
		case OP_BIT_SET: layer_and(mask); layer_or(bits); break;
	}
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
    if (record->event.pressed) dprint("P"); else dprint("R");

    static uint8_t tricky_esc_registered;
    switch (id) {
        case TRICKY_ESC:
            if (record->event.pressed) {
                if (get_mods() & MODS_SHIFT_MASK) {
                    tricky_esc_registered = KC_GRV;
                }
                else {
                    tricky_esc_registered = KC_ESC;
                }
                register_code(tricky_esc_registered);
                send_keyboard_report();
            }
            else {
                unregister_code(tricky_esc_registered);
                send_keyboard_report();
            }
            break;
		case VIM_LAYOUT_ON:
			led_set((1<<USB_LED_CAPS_LOCK));
			layer_on_off(3, 1);
			break;
		case VIM_LAYOUT_OFF:
			led_set(0);
			layer_on_off(3, 0);
			break;
    }
}

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_TAP_KEY(2, KC_3),
    [3] = ACTION_FUNCTION(TRICKY_ESC),  // Shift + ESC -> ~ 
    [4] = ACTION_BACKLIGHT_TOGGLE(),
    [5] = ACTION_BACKLIGHT_DECREASE(),
    [6] = ACTION_BACKLIGHT_INCREASE(),
	[7] = ACTION_FUNCTION(VIM_LAYOUT_ON),
	[8] = ACTION_FUNCTION(VIM_LAYOUT_OFF),
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
