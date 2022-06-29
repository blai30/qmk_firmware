// Note: Several functions referenced in this file are defined in users/blai30/blai30.c

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"
#include "blai30.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base Layout
    // ,-------------------------------------------------------------------------------------------------------------.
    // | Esc  ||  F1  |  F2  |  F3  |  F4  ||  F5  |  F6  |  F7  |  F8  ||  F9  | F10  | F11  | F12  || PrSc || Mute |
    // |=============================================================================================================|
    // |  ` ~ |  1 ! |  2 @ |  3 # |  4 $ |  5 % |  6 ^ |  7 & |  8 * |  9 ( |  0 ) |  - _ |  = + |  Backspc || Ins  |
    // |------+------+------+------+------+------+------+------+------+------+------+------+------+----------++------|
    // |   Tab   |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | [ }  | ] }  |  \ |  || Del  |
    // |---------+------+------+------+------+------+------+------+------+------+------+------+------+-------++------|
    // |  Capslock  |  A   |  S   |  D   |  F  |  G   |  H   |  J   |  K   |  L   | ; :  | ' "  |    Enter   || Home |
    // |------------+------+------+------+-----+------+------+------+------+------+------+------|----+========+------|
    // |    LShift    |  Z   |  X   |  C   |  V   |  B   |  N   |  M   | , <  | . >  | / ?  | RShift ||  ↑   || End  |
    // |--------------+------+------+------+------+------+------+------+------+------+------+--+=====++------++======|
    // |  Ctrl  |   Win  |  LAlt  |               Space                  | RAlt |  Fn  | Ctrl ||  ←   |  ↓   |  →   ||
    // `-------------------------------------------------------------------------------------------------------------'

    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_HOME,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_FN1),KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN1] = LAYOUT(
        EE_CLR,  KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_F13,           _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_PAUS,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_SCRL,
        KC_NUM,  RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, KC_PGDN,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PMNS, KC_PPLS, _______,          _______,
        _______, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______,          _______,
        KC_NUM,  KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,          KC_PENT,          _______,
        _______,          XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PSLS,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_ENABLE
// Caps lock, scroll lock and num lock indicator on left RGB strip.
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Num lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
        rgb_matrix_set_color(LED_L1, RGB_GREEN);
        rgb_matrix_set_color(LED_L2, RGB_GREEN);
        rgb_matrix_set_color(LED_ESC, RGB_GREEN);
        rgb_matrix_set_color(LED_GRV, RGB_GREEN);
        rgb_matrix_set_color(LED_DOWN, RGB_GREEN);
    }

    // Caps lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_LETTERS); i++) {
            rgb_matrix_set_color(LED_LIST_LETTERS[i], RGB_CHARTREUSE);
        }
        rgb_matrix_set_color(LED_L4, RGB_GREEN);
        rgb_matrix_set_color(LED_L5, RGB_GREEN);
        rgb_matrix_set_color(LED_TAB, RGB_GREEN);
        rgb_matrix_set_color(LED_CAPS, RGB_GREEN);
        rgb_matrix_set_color(LED_LSFT, RGB_GREEN);
        rgb_matrix_set_color(LED_LEFT, RGB_GREEN);
    }

    // Scroll lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
        rgb_matrix_set_color(LED_L7, RGB_GREEN);
        rgb_matrix_set_color(LED_L8, RGB_GREEN);
        rgb_matrix_set_color(LED_LCTL, RGB_GREEN);
        rgb_matrix_set_color(LED_RIGHT, RGB_GREEN);
    }

    // Fn selector mode RGB setup
    switch (get_highest_layer(layer_state)) {
        case _FN1: // on Fn layer select what the encoder does when pressed
            rgb_matrix_set_color(LED_FN, RGB_RED);

            // NEW RGB LIGHTING TO RING KEYBOARD ON FN LAYER ACTIVATION:
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_FUNCROW); i++) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[i], RGB_RED);
            }
            for (uint8_t i = 0; i < ARRAYSIZE(LED_SIDE_LEFT); i++) {
                rgb_matrix_set_color(LED_SIDE_LEFT[i], RGB_RED);
            }
            for (uint8_t i = 0; i < ARRAYSIZE(LED_SIDE_RIGHT); i++) {
                rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_RED);
            }
            rgb_matrix_set_color(LED_BSLS, RGB_RED);
            break;

        // Numpad & Mouse Keys overlay RGB
        case _NUMPAD:
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_BLUE);
            }
            break;

        default:
            break;
    }
}
#endif
