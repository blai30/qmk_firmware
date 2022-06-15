#pragma once

#ifdef RGB_MATRIX_ENABLE
    #define RGB_DISABLE_WHEN_USB_SUSPENDED true
    // 3 minutes (3 * 60 * 1000 ms).
    #define RGB_DISABLE_TIMEOUT 180000
#endif
