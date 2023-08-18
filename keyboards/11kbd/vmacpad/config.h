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

#define RGB_MATRIX_LED_COUNT 6

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

#define RGB_MATRIX_DEFAULT_VAL 150

#define RGB_DISABLE_WHEN_USB_SUSPENDED  // turn off effects when suspended
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_GRADIENT_UP_DOWN

#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN

// Default 4, upscaled to make the encoder slower
#define ENCODER_RESOLUTION 8
