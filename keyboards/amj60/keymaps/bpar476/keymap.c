
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEF 0
#define _UTIL 1

// increase readability
#define _______ KC_TRNS

// Macro keys
#define M1_REC DYN_REC_START1
#define M2_REC DYN_REC_START2
#define M1 DYN_MACRO_PLAY1
#define M2 DYN_MACRO_PLAY2
#define M_STOP DYN_REC_STOP

// Toggle layer with two taps
#define TAPPING_TOGGLE 2

enum keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    PLOVER,
    LOWER,
    RAISE,
    BACKLIT,
    EXT_PLV,
    DYNAMIC_MACRO_RANGE,
}

#include "dynamic_macros.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap _DEF: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =| \ | ~ |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| bspc|
     * |-----------------------------------------------------------|
     * |TT     | A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |
     * |-----------------------------------------------------------|
     * |Sft| OSL |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Sft |   |
     * |-----------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space           |Alt |Win |Menu|RCtl|
     * `-----------------------------------------------------------'
     */
    [_DEF] = LAYOUT_max(
        KC_ESC,   KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSLS, KC_GRV, \
        KC_TAB,   KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSPC,  \
        TG(_UTIL),  KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, KC_ENT,   \
        KC_LSFT, OSL(_UTIL), KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,_______,\
        KC_LCTL,  KC_LALT, KC_LGUI,             KC_SPACE,                       KC_RGUI, KC_RALT, KC_RCTL,_______,

    /* Keymap 1: General utility layer. F keys, Vim movement, audio controls and other.
     * ,--------------------------------------------------------------------.
     * |PrSc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|     |         |
     * |--------------------------------------------------------------------|
     * |AltTab| RecM1 | RecM2 | MRecStop|  |  |  |     |  |  |  |  |  | Del |
     * |--------------------------------------------------------------------|
     * |      | M1    | M2    | |  |  |Lft|Dwn|Up|Right|  | |               |
     * |--------------------------------------------------------------------|
     * |    |   |   |   |   |   |   |   |   |   |   |   |      | Vol+       |
     * |--------------------------------------------------------------------|
     * |    |    |    |                        |<-|Play/Paus|->| Vol-       |
     * `--------------------------------------------------------------------'
     */
    [_UTIL] = LAYOUT_max(
        KC_PSCR, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_F6,    KC_F7,     KC_F8,     KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,  \
        LALT(KC_TAB), M1_REC, M2_REC, M_STOP,  _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_DEL, \
        _______, M1, M2, _______, _______, _______, KC_LEFT,  KC_DOWN,   KC_UP,     KC_RGHT, _______, _______, _______, \
        _______, _______, _______, _______,  _______, _______, KC_SPACE, _______,      _______,   _______, _______, _______, _______, KC_VOLU, \
        _______, _______, _______,                                  _______,                                 KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD),

};
