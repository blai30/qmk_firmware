#include QMK_KEYBOARD_H
#include "blai30.h"

#ifdef ENCODER_ENABLE
#    ifndef DYNAMIC_KEYMAP_LAYER_COUNT
#        define DYNAMIC_KEYMAP_LAYER_COUNT 3 // default in case this is not already defined elsewhere
#    endif
#    ifndef ENCODER_DEFAULTACTIONS_INDEX
#        define ENCODER_DEFAULTACTIONS_INDEX 0 // can select encoder index if there are multiple encoders
#    endif

void encoder_action_volume(bool clockwise) {
    tap_code(clockwise ? KC_VOLU : KC_VOLD);
}

void encoder_action_mediatrack(bool clockwise) {
    tap_code(clockwise ? KC_MEDIA_NEXT_TRACK : KC_MEDIA_PREV_TRACK);
}

void encoder_action_navword(bool clockwise) {
    tap_code(clockwise ? LCTL(KC_RGHT) : LCTL(KC_LEFT));
}

void encoder_action_navpage(bool clockwise) {
    tap_code(clockwise ? KC_PGUP : KC_PGDN);
}

// LAYER HANDLING
uint8_t selected_layer = 0;

uint8_t get_selected_layer(void) {
    return selected_layer;
}

void encoder_action_layerchange(bool clockwise) {
    if (clockwise) {
        if (selected_layer < (DYNAMIC_KEYMAP_LAYER_COUNT - 1)) {
            selected_layer++;
            layer_move(selected_layer);
        }
    } else {
        if (selected_layer > 0) {
            selected_layer--;
            layer_move(selected_layer);
        }
    }
}

#    ifdef RGB_MATRIX_ENABLE
void encoder_action_rgb_speed(bool clockwise) {
    if (clockwise) {
        rgb_matrix_increase_speed_noeeprom();
    } else {
        rgb_matrix_decrease_speed_noeeprom();
    }
}
void encoder_action_rgb_hue(bool clockwise) {
    if (clockwise) {
        rgb_matrix_increase_hue_noeeprom();
    } else {
        rgb_matrix_decrease_hue_noeeprom();
    }
}
void encoder_action_rgb_saturation(bool clockwise) {
    if (clockwise) {
        rgb_matrix_increase_sat_noeeprom();
    } else {
        rgb_matrix_decrease_sat_noeeprom();
    }
}
void encoder_action_rgb_brightness(bool clockwise) {
    if (clockwise) {
        rgb_matrix_increase_val_noeeprom();
    } else {
        rgb_matrix_decrease_val_noeeprom();
    }
}
void encoder_action_rgb_mode(bool clockwise) {
    if (clockwise) {
        rgb_matrix_step_noeeprom();
    } else {
        rgb_matrix_step_reverse_noeeprom();
    }
}
#    elif defined(RGBLIGHT_ENABLE)
void encoder_action_rgb_speed(bool clockwise) {
    if (clockwise) {
        rgblight_increase_speed_noeeprom();
    } else {
        rgblight_decrease_speed_noeeprom();
    }
}
void encoder_action_rgb_hue(bool clockwise) {
    if (clockwise) {
        rgblight_increase_hue_noeeprom();
    } else {
        rgblight_decrease_hue_noeeprom();
    }
}
void encoder_action_rgb_saturation(bool clockwise) {
    if (clockwise) {
        rgblight_increase_sat_noeeprom();
    } else {
        rgblight_decrease_sat_noeeprom();
    }
}
void encoder_action_rgb_brightness(bool clockwise) {
    if (clockwise) {
        rgblight_increase_val_noeeprom();
    } else {
        rgblight_decrease_val_noeeprom();
    }
}
void encoder_action_rgb_mode(bool clockwise) {
    if (clockwise) {
        rgblight_step_noeeprom();
    } else {
        rgblight_step_reverse_noeeprom();
    }
}
#    endif // RGB_MATRIX_ENABLE || RGBLIGHT_ENABLE
#endif     // ENCODER_ENABLE

// Encoder Functionality
#if defined(ENCODER_ENABLE) && defined(ENCODER_DEFAULTACTIONS_ENABLE)
__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {
    return true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!encoder_update_keymap(index, clockwise)) {
        return false;
    }
    if (index != ENCODER_DEFAULTACTIONS_INDEX) {
        return true;
    } // exit if the index doesn't match
    uint8_t mods_state = get_mods();
    if (mods_state & MOD_BIT(KC_RSFT)) {
        // Holding FN with right shift, page up/down.
        unregister_mods(MOD_BIT(KC_RSFT));
        encoder_action_navpage(clockwise);
        register_mods(MOD_BIT(KC_RSFT));
    } else if (mods_state & MOD_BIT(KC_RALT)) {
        // Holding FN with right alt, media next/prev track.
        encoder_action_mediatrack(clockwise);
    } else if (mods_state & MOD_BIT(KC_RCTL)) {
        // Holding FN with right ctrl, change layers.
        encoder_action_layerchange(clockwise);
    } else {
        switch (get_highest_layer(layer_state)) {
            case _FN1:
                // Holding FN, adjust RGB brightness.
                encoder_action_rgb_brightness(clockwise);
                break;
            default:
                // Otherwise it just changes volume.
                encoder_action_volume(clockwise);
                break;
        }
    }
    return false;
}
#endif // ENCODER_ENABLE
