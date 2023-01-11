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

#include "um70.h"

#ifdef RGB_MATRIX_ENABLE
/*
                          Underglow      Underglow             13,14 = split bksp, 14 = 2u bksp
    07 08 09 10 11 12 13     01             01        07 08 09 10 11 12 13 14
     14  15 16 17 18 19      02             02      15 16 17 18 19 20 21  22     23
20    21  22 23 24 25 26     03             03       24 25 26 27 28 29   30      31
27     28   29 30 31 32 33   04             04        32 33 34 35 36   37     38
34   35  36  37  38   39     05             05            39    40   41    42 43 44
                             06             06
*/

#define XX NO_LED

led_config_t g_led_config = { {
    {  6,  7,  8,  9, 10, 11, 12, XX },
    { 13, 14, 15, 16, 17, 18, XX, XX },
    { 20, 21, 22, 23, 24, 25, XX, XX },
    { 27, 28, 29, 30, 31, 32, XX, XX },
    { 34, 35, 36, 37, 38, 19, 26, 33 },

    { 45, 46, 47, 48, 49, 50, 51, 52 },
    { 53, 54, 55, 56, 57, 58, 59, 60 },
    { 62, 63, 64, 65, 66, 67, 68, XX },
    { 70, 71, 72, 73, 74, 75, 76, 61 },
    { 77, 78, 79, 80, 81, 82, XX, 69 },
}, {
    { 112, 0  }, { 112, 13 }, { 112, 26 }, { 112, 39 }, { 112, 52 }, {  112,  64 },

                 {  18,  0 }, {  37, 0  }, {  55, 0  }, { 73, 0  }, { 92, 0  }, {  110,  0  }, {  112,  0  },
                 {  18, 16 }, {  37, 16 }, {  55, 16 }, { 73, 16 }, { 92, 16 }, {  110,  16 },
    {   0, 32 }, {  18, 32 }, {  37, 32 }, {  55, 32 }, { 73, 32 }, { 92, 32 }, {  110,  32 },
    {   0, 48 }, {  18, 48 }, {  37, 48 }, {  55, 48 }, { 73, 48 }, { 92, 48 }, {  110,  48 },
    {   0, 64 }, {  18, 64 }, {  37, 64 }, {  55, 64 }, { 73, 64 }, { 92, 64 },

    { 112, 0  }, { 112, 13 }, { 112, 26 }, { 112, 39 }, { 112, 52 }, {  112,  64 },

    {   114,  0  }, {  128,  0 }, {  142, 0  }, {  155, 0  }, { 169, 0  }, { 183, 0  }, {  197,  0  }, {  224,  0  },
    {   114,  16 }, {  128, 16 }, {  142, 16 }, {  155, 16 }, { 169, 16 }, { 183, 16 }, {  197,  16 }, {  223,  16  }, {  224,  16  },
    {   114,  32 }, {  128, 32 }, {  142, 32 }, {  155, 32 }, { 169, 32 }, { 183, 32 }, {  197,  32 }, {  223,  32  },
    {   114,  48 }, {  128, 48 }, {  142, 48 }, {  155, 48 }, { 169, 48 }, { 183, 48 }, {  197,  48 },
    {   144,  46 }, {  128, 46 }, {  142, 64 }, {  155, 64 }, { 169, 64 }, { 183, 64 }

}, {
    2, 2, 2, 2, 2, 2,
    4, 4, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    4, 1, 4, 4, 4, 4, 4,
    4, 1, 4, 4, 4, 4, 4,
    4, 1, 1, 1, 1, 1,

    2, 2, 2, 2, 2, 2,
    4, 4, 4, 4, 4, 4, 4, 1,
    4, 4, 4, 4, 4, 4, 4, 1, 4,
    4, 4, 4, 4, 4, 4, 1, 4,
    4, 4, 4, 4, 4, 1, 4,
    1, 1, 1, 4, 4, 4
} };

#endif
