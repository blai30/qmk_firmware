#pragma once

#ifdef RGB_MATRIX_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// RGB step values
#define RGBLIGHT_HUE_STEP 32 // The number of steps to cycle through the hue by (default 10)
#define RGBLIGHT_SAT_STEP 17 // The number of steps to increment the saturation by (default 17)
#define RGBLIGHT_VAL_STEP 17 // The number of steps to increment the brightness by (default 17)

// blai30 modified.
#define DYNAMIC_KEYMAP_LAYER_COUNT 3
