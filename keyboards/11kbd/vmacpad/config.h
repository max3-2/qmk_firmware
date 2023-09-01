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

// Encoder better setup - resolution
// Res. of 2 working for alpine
// #define ENCODER_RESOLUTION 2
// Res. of 4 working for Bourns 64
#define ENCODER_RESOLUTION 4

// RGB Backlight
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_DEFAULT_HUE 195
