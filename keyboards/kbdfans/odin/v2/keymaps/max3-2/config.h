/* Copyright 2023 max3-2
 * MIT License
 * Custom keymap for Odin v2, max3-2
 */

#pragma once

#ifdef RGB_DI_PIN
    #define RGBLIGHT_LAYERS_RETAIN_VAL
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#endif

// More light
#ifdef RGBLIGHT_VAL_STEP
    #undef RGBLIGHT_VAL_STEP
    #define RGBLIGHT_VAL_STEP 10
#endif
#ifdef RGBLIGHT_LIMIT_VAL
    #undef RGBLIGHT_LIMIT_VAL
    #define RGBLIGHT_LIMIT_VAL 200
#endif

// Leader config
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 275

// Fancy LED layer
#define RGBLIGHT_LAYERS
