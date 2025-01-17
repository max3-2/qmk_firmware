/* Copyright 2021 duoshock
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#pragma once

#include "config_common.h"

// disable almost all default effects
#undef RGB_MATRIX_ALPHAS_MODS
#undef RGB_MATRIX_GRADIENT_UP_DOWN
#undef RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef RGB_MATRIX_BREATHING
#undef RGB_MATRIX_BAND_SAT
#undef RGB_MATRIX_BAND_VAL
#undef RGB_MATRIX_BAND_PINWHEEL_SAT
#undef RGB_MATRIX_BAND_PINWHEEL_VAL
#undef RGB_MATRIX_BAND_SPIRAL_SAT
#undef RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

// Allow fancy RGB
#define RGB_MATRIX_KEYRELEASES
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

// Simple RGB effects, saved due to win layering and space
// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS

// Reactive RGB
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS

#define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 40

// more power
#undef RGBLIGHT_LIMIT_VAL
#define RGBLIGHT_LIMIT_VAL 160

// Leader config
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 300

// Leader LEd indication on right, only caps word not lock. skip this
// #define SPLIT_LED_STATE_ENABLE

// OLED config
#define OLED_FONT_H "./keymaps/max3-2/glcdfont.c"
#define OLED_TIMEOUT 600000
#define OLED_BRIGHTNESS 200

// save some more space
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_ACTION_ONESHOT
#define LAYER_STATE_8BIT

// Fix WakeUp
#define USB_SUSPEND_WAKEUP_DELAY 150
#define SPLIT_WATCHDOG_ENABLE
