#pragma once

#ifdef RGB_MATRIX_ENABLE
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_PINWHEEL
#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_MATRIX_STARTUP_SAT 120
#endif

// RGB step values
#define RGBLIGHT_HUE_STEP 32 // The number of steps to cycle through the hue by (default 10)
#define RGBLIGHT_SAT_STEP 17 // The number of steps to increment the saturation by (default 17)
#define RGBLIGHT_VAL_STEP 17 // The number of steps to increment the brightness by (default 17)

#define DYNAMIC_KEYMAP_LAYER_COUNT 3
