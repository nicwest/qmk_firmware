#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#define _QW 0      // QWERTY
#define _WO 1      // WORKMAN
#define _DV 2      // DVORAK
#define _ME 3      // meta
#define _ST 4      // STENO

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QW] = LAYOUT(
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_HOME, KC_INSERT,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,
        KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,                   KC_ENT, 
        KC_LSFT,  KC_BSLS, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL,  MO(_ME), KC_LALT,                   KC_SPC,   KC_LGUI, KC_BSPC,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
    [_WO] = LAYOUT(
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_HOME, KC_INSERT,
        KC_TAB,   KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,     KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC, KC_NUHS,
        KC_ESC,   KC_A,    KC_S,    KC_H,    KC_T,    KC_G,     KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT,                   KC_ENT, 
        KC_LSFT,  KC_BSLS, KC_Z,    KC_X,    KC_M,    KC_C,     KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL,  MO(_ME), KC_LALT,                   KC_SPC,   KC_LGUI, KC_BSPC,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
    [_DV] = LAYOUT(
        KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LBRC, KC_RBRC, KC_HOME, KC_INSERT,
        KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,     KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, KC_EQL,  KC_NUHS,
        KC_ESC,   KC_A,    KC_O,    KC_E,    KC_U,    KC_I,     KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,                   KC_ENT, 
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,     KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_BSLS, KC_RSFT, XXXXXXX,
        KC_LCTL,  MO(_ME), KC_LALT,                   KC_SPC,   KC_LGUI, KC_BSPC,                   KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
    ),
    [_ME] = LAYOUT(
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_END,  _______,
        _______,  DF(_QW), DF(_WO), DF(_DV), DF(_ST), _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,  KC_MNXT, KC_MPLY, KC_MUTE, KC_MPRV, _______, KC_BRID, KC_BRIU, 
        _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  KC_NO,   _______,                   RGB_TOG,  _______, KC_DEL,                    _______, _______, KC_PGDN, KC_PGUP, _______
    ),
    [_ST] = LAYOUT(
        XXXXXXX,  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,   STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,  XXXXXXX, XXXXXXX,
        XXXXXXX,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,  XXXXXXX, XXXXXXX,
        XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,  STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  XXXXXXX, 
        XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, STN_A,   STN_O,    XXXXXXX, STN_E,   STN_U,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  DF(_QW), XXXXXXX,                   XXXXXXX,  XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
