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
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOD, RGB_TOI, _______,          KC_PAUS,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,          KC_SCRL,
        KC_NUM,  RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, KC_PGDN,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PMNS, KC_PPLS, _______,          _______,
        _______, KC_PGUP, KC_UP,   KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,          KC_PENT,          _______,
        _______,          XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PSLS,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),
};

#ifdef RGB_MATRIX_ENABLE
// Caps lock, scroll lock and num lock indicator on left RGB strip.
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Num lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
        rgb_matrix_set_color(LED_L1, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_L2, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_ESC, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_GRV, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_DOWN, RGB_SPRINGGREEN2);
    }

    // Caps lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_LETTERS); i++) {
            rgb_matrix_set_color(LED_LIST_LETTERS[i], RGB_CHARTREUSE);
        }
        rgb_matrix_set_color(LED_L4, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_L5, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_TAB, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_CAPS, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_LSFT, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_LEFT, RGB_SPRINGGREEN2);
    }

    // Scroll lock indicator RGB setup
    if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
        rgb_matrix_set_color(LED_L7, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_L8, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_LCTL, RGB_SPRINGGREEN2);
        rgb_matrix_set_color(LED_RIGHT, RGB_SPRINGGREEN2);
    }

    // Fn selector mode RGB setup
    switch (get_highest_layer(layer_state)) {
        case _FN1: // on Fn layer select what the encoder does when pressed
            rgb_matrix_set_color(LED_FN, RGB_RED);

            // NEW RGB LIGHTING TO RING KEYBOARD ON FN LAYER ACTIVATION:
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_FUNCROW); i++) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[i], RGB_RED);
            }
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMROW); i++) {
                rgb_matrix_set_color(LED_LIST_NUMROW[i], RGB_RED);
            }
            rgb_matrix_set_color(LED_BSLS, RGB_RED);
            rgb_matrix_set_color(LED_L1, RGB_RED);
            rgb_matrix_set_color(LED_L2, RGB_RED);
            rgb_matrix_set_color(LED_L3, RGB_RED);
            rgb_matrix_set_color(LED_L4, RGB_RED);
            rgb_matrix_set_color(LED_L5, RGB_RED);
            rgb_matrix_set_color(LED_L6, RGB_RED);
            rgb_matrix_set_color(LED_L7, RGB_RED);
            rgb_matrix_set_color(LED_L8, RGB_RED);
            rgb_matrix_set_color(LED_R1, RGB_RED);
            rgb_matrix_set_color(LED_R2, RGB_RED);
            rgb_matrix_set_color(LED_R3, RGB_RED);
            rgb_matrix_set_color(LED_R4, RGB_RED);
            rgb_matrix_set_color(LED_R5, RGB_RED);
            rgb_matrix_set_color(LED_R6, RGB_RED);
            rgb_matrix_set_color(LED_R7, RGB_RED);
            rgb_matrix_set_color(LED_R8, RGB_RED);
            rgb_matrix_set_color(LED_MINS, RGB_GREEN);
            rgb_matrix_set_color(LED_EQL, RGB_GREEN);

            // Add RGB Timeout Indicator -- shows 0 to 139 using F row and num row; larger numbers using 16bit code
            uint16_t timeout_threshold = get_timeout_threshold();
            if (timeout_threshold <= 10) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[timeout_threshold], RGB_YELLOW);
            } else if (timeout_threshold < 140) {
                rgb_matrix_set_color(LED_LIST_FUNCROW[(timeout_threshold / 10)], RGB_YELLOW);
                rgb_matrix_set_color(LED_LIST_NUMROW[(timeout_threshold % 10)], RGB_YELLOW);
            } else { // >= 140 minutes; max
                rgb_matrix_set_color(LED_LIST_NUMROW[10], RGB_YELLOW);
            }
            break;

        // Numpad & Mouse Keys overlay RGB
        case _NUMPAD:
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_OFFBLUE);
            }
            rgb_matrix_set_color(LED_L5, RGB_OFFBLUE);
            rgb_matrix_set_color(LED_L6, RGB_OFFBLUE);
            rgb_matrix_set_color(LED_CAPS, RGB_OFFBLUE);
            rgb_matrix_set_color(LED_UP, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_DOWN, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_LEFT, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_RIGHT, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_RCTL, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_RSFT, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_END, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_PGUP, RGB_CHARTREUSE);
            rgb_matrix_set_color(LED_PGDN, RGB_CHARTREUSE);
            break;

        default:
            break;
    }
}
#endif

// void keyboard_post_init_keymap(void) {
//     // keyboard_post_init_user() moved to userspace
//     #ifdef RGB_MATRIX_ENABLE
//     rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_PINWHEEL);
//     // Default startup color (hue, sat, val/brightness)
//     rgb_matrix_sethsv_noeeprom(20, 140, 255);
//     #endif
// }
