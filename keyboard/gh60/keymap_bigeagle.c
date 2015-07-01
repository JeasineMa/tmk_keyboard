#include "keymap_common.h"

/*
 * HHKB Layout
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
     * ,-----------------------------------------------------------.
     * |Esc|1/Fn2| 2| 3|  4|  5|  6|  7|  8|  9|  0|  -|  =| Bs | `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|   \ |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L| ; |  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn1|
     * |-----------------------------------------------------------|
     * |CAPS |Gui |Alt |      Space            | Fn0 |Alt |Ctrl|DEL|
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        FN3, FN2,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC, GRV, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,      \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,FN1,       \
        CAPS,  LGUI,LALT,          SPC,                     FN0, RALT, RCTL, DEL),

    /* 1: FN0 Layer
     * ,-----------------------------------------------------------.
     * |` | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10|F11|F12|DEL|INS|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |Psc |   |   |    |
     * |-----------------------------------------------------------|
     * |      |Mu |V- |V+ |   |   |   |   |   |   |   |   |        |
     * |-----------------------------------------------------------|
     * | Shift  |Blt|Bl↓|Bl↑|   |   |   |   |   |   |   | PgUp |   |
     * |-----------------------------------------------------------|
     * |    |    | Alt|                        |    |Home|PgDn|End |
     * `-----------------------------------------------------------'
     */


    KEYMAP_HHKB(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL, INS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,TRNS,TRNS,TRNS,      \
        TRNS,MUTE, VOLD,VOLU, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     PENT,      \
        LSFT,FN4, FN5, FN6, TRNS, TRNS, TRNS,TRNS,TRNS, TRNS,TRNS,     PGUP,TRNS,      \
        TRNS,TRNS,LALT,          TRNS,                    TRNS,HOME,PGDN,END),
    
	/* 2: FN1/FN2 layer
     * ,-----------------------------------------------------------.
     * |`  |   |   |   |END|   |HOME|  |   |   |HOME|   |   |DEL| `|
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |PgU |   |   |   |   |   |    |
     * |-----------------------------------------------------------|
     * |      |   |  |PgD |PgD |   |Left|Down|Up|Right|  |  |      |
     * |-----------------------------------------------------------|
     * | Shift  |   |   |   |PgU |   |   |   |   |   |   |     |   |
     * |-----------------------------------------------------------|
     * |    |    | Alt|                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        GRV,TRNS,TRNS,TRNS,END,TRNS,HOME,TRNS,TRNS,TRNS,HOME,TRNS,TRNS,DEL,GRV, \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,      \
        TRNS,TRNS, TRNS,PGDN,PGDN,TRNS,LEFT,DOWN,UP,RGHT,TRNS,TRNS,    TRNS,      \
        LSFT,TRNS,TRNS, TRNS, TRNS, PGUP, TRNS,TRNS,TRNS, TRNS,TRNS,     TRNS,TRNS,      \
        TRNS,TRNS,LALT,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
};


enum function_id {
    TRICKY_ESC,
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
    }
}

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),
	[1] = ACTION_LAYER_MOMENTARY(2),
	[2] = ACTION_LAYER_TAP_KEY(2, KC_1),
    [3] = ACTION_FUNCTION(TRICKY_ESC),  // Shift + ESC -> ~ 
    [4] = ACTION_BACKLIGHT_TOGGLE(),
    [5] = ACTION_BACKLIGHT_DECREASE(),
    [6] = ACTION_BACKLIGHT_INCREASE()
};

#ifdef KEYMAP_IN_EEPROM_ENABLE
uint16_t keys_count(void) {
    return sizeof(keymaps) / sizeof(keymaps[0]) * MATRIX_ROWS * MATRIX_COLS;
}

uint16_t fn_actions_count(void) {
    return sizeof(fn_actions) / sizeof(fn_actions[0]);
}
#endif
