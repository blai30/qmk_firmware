#include QMK_KEYBOARD_H
#include "blai30.h"

// Initialize variable holding the binary representation of active modifiers.
uint8_t mod_state;

// ============================================= PROCESS KEY CODES =============================================

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

// Turn on/off NUM LOCK if current state is different
void activate_numlock(bool turn_on) {
    if (IS_HOST_LED_ON(USB_LED_NUM_LOCK) != turn_on) {
        tap_code(KC_NUMLOCK);
    }
}

// INITIAL STARTUP

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
#ifdef STARTUP_NUMLOCK_ON
    activate_numlock(true); // turn on Num lock by default so that the numpad layer always has predictable results
#endif                      // STARTUP_NUMLOCK_ON
}
