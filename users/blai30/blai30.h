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
    RGB_TOI,       // Timeout idle time up
    RGB_TOD,       // Timeout idle time down
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

// PROTOTYPE FUNCTIONS
uint16_t get_timeout_threshold(void);
void timeout_reset_timer(void);
void timeout_update_threshold(bool increase);
void timeout_tick_timer(void);
#endif //IDLE_TIMEOUT_ENABLE

// OTHER FUNCTION PROTOTYPE
void activate_numlock(bool turn_on);
