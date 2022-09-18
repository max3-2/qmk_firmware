/* Copyright 2019 Ryota Goto
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
#include QMK_KEYBOARD_H

enum my_keycodes {
  MY_00 = SAFE_RANGE,
  DANCER,
  SNEK,
  POOP,
  CAM,
  HV,
  CHECK,
};

// enum unicode_names {
//     BANG,
//     IRONY,
//     SNEK
// };
//
const uint32_t PROGMEM unicode_map[] = {
    [0] = 0x00E4, // ä
    [1] = 0x00C4, // Ä
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case MY_00:
          if (record->event.pressed) {
              SEND_STRING("00");
          } else {
              // when keycode is released
          }
          break;

      // case AE:
      //     if (record->event.pressed) {
      //         send_unicode_string("ä");
      //     } else {
      //         // when keycode is released
      //     }
      //     break;

      case DANCER:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("D83D+DC83"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;

      case SNEK:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("D83D+DC0D"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;

      case POOP:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("D83D+DCA9"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;

      case CAM:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("D83D+DCF8"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;

      case HV:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("26A1"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;

      case CHECK:
        if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
          SEND_STRING(SS_LALT("2705"));
        } else {
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_SPACE)SS_UP(X_LCTL)SS_DELAY(50));
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_6x4( /* Base */
    KC_TAB, KC_DOT, KC_BACKSPACE, MO(1),
    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_P0,   MY_00,   KC_PDOT, KC_PENT
  ),
  [1] = LAYOUT_ortho_6x4(  // UNICODE Layer with some basic light control
    RGB_TOG, BL_TOGG, KC_TRNS, KC_TRNS,
    RGB_VAD, RGB_VAI, BL_DEC, BL_INC,
    _______, _______, _______, _______,
    CAM, CHECK, HV, _______,
    DANCER, POOP, SNEK, _______,
    _______, _______, _______, _______
  ),
};
