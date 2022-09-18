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
// extern MidiDevice midi_device;
//
// #define MIDI_CC_OFF 0
// #define MIDI_CC_ON  127

enum my_keycodes {
  MY_00 = SAFE_RANGE,
  // MIDI_CC80,
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

      // case MIDI_CC80:
      //     if (record->event.pressed) {
      //         // when keycode QMKBEST is pressed
      //         midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_ON);
      //     } else {
      //         midi_send_cc(&midi_device, midi_config.channel, 80, MIDI_CC_OFF);
      //     }
      //     return true;

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
    _______, _______, _______, _______,
    _______, _______, _______, _______,
    _______, _______, _______, _______
  ),
  // [2] = LAYOUT_ortho_6x4(  // MIDI Layer for lr2midi if this works?
  //   _______, _______, KC_TRNS, TG(2),
  //   _______, _______, _______, _______,
  //   MIDI_CC80, _______, _______, _______,
  //   MI_E, _______, _______, _______,
  //   MI_D, _______, _______, _______,
  //   MI_C, _______, _______, _______
  // ),
};
