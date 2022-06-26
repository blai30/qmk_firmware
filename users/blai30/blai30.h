#pragma once

// DEFINE MACROS
#define ARRAYSIZE(arr) sizeof(arr) / sizeof(arr[0])

// LAYERS
enum custom_user_layers {
    _BASE,
    _FN1,
    _NUMPAD
};

// KEYCODES
enum custom_user_keycodes {
    ENCFUNC,
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

// OTHER FUNCTION PROTOTYPE
void activate_numlock(bool turn_on);
