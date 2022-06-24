/* Copyright 2021 Jonavin Eng @Jonavin
   Copyright 2022 gourdo1 <jcblake@outlook.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// DEFINE MACROS
#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

// LAYERS
enum custom_user_layers {
    _BASE,
    _FN1,
    _NUMPAD
};

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_AF4 LALT(KC_F4)
#define KC_TASK LCTL(LSFT(KC_ESC))
#define CT_PGUP RCTL(KC_PGUP)
#define CT_PGDN RCTL(KC_PGDN)
#define CT_HOME RCTL(KC_HOME)
#define CT_END RCTL(KC_END)
#define KC_SHIFTSPC LSFT(KC_SPC)

// KEYCODES
enum custom_user_keycodes {
    ENCFUNC,
    RGB_TOI,       // Timeout idle time up
    RGB_TOD,       // Timeout idle time down
    KC_TSTOG,      // Tab Scroll Toggle
    NEW_SAFE_RANGE // new safe range for keymap level custom keycodes
};

// ENCODER ACTIONS
#ifdef ENCODER_ENABLE
void encoder_action_volume(bool clockwise);
void encoder_action_mediatrack(bool clockwise);
void encoder_action_navword(bool clockwise);
void encoder_action_navpage(bool clockwise);

uint8_t get_selected_layer(void);
void encoder_action_layerchange(bool clockwise);

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
void encoder_action_rgb_speed(bool clockwise);
void encoder_action_rgb_hue(bool clockwise);
void encoder_action_rgb_saturation(bool clockwise);
void encoder_action_rgb_brightness(bool clockwise);
void encoder_action_rgb_mode(bool clockwise);
#endif // RGB_MATRIX_ENABLE / RGBLIGHT_ENABLE
#endif // ENCODER_ENABLE

// IDLE TIMEOUTS
#ifdef IDLE_TIMEOUT_ENABLE
#define TIMEOUT_THRESHOLD_DEFAULT 15 // default timeout minutes
#define TIMEOUT_THRESHOLD_MAX 140 // upper limits (2 hours and 10 minutes -- no rgb indicators above this value)

//prototype  functions
uint16_t get_timeout_threshold(void);
void timeout_reset_timer(void);
void timeout_update_threshold(bool increase);
void timeout_tick_timer(void);
#endif //IDLE_TIMEOUT_ENABLE

// OTHER FUNCTION PROTOTYPE
void activate_numlock(bool turn_on);
