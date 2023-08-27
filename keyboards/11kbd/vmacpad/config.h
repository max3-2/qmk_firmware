/* Copyright max3-2
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

// Should be default by now
// #define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE

// HSE CLK reconfig, see also mcuconf.h (taken from xelus/rs108/mcuconf.h)
// This can be removed in rev.2 with 8MHz crystal
#define STM32_HSECLK 16000000

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

// Encoder better setup - resolution in info json and more debounce tolerance
// #define ENCODER_RESOLUTION 1
// #define TAP_CODE_DELAY 5
// #define ENCODER_DEFAULT_POS 0x03

// RGB Backlight
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_HUE 195

// RGB Matrix
// #define RGB_MATRIX_LED_COUNT 6
// #define RGB_MATRIX_DEFAULT_VAL 150

// #define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
// #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING

// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
