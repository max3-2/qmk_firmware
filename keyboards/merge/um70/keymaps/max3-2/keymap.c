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

#include QMK_KEYBOARD_H
// #include <stdio.h>

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    MAC_LOCK = SAFE_RANGE,
    MAC_COPY,
    MAC_COPYALL,
    MAC_PASTE,
    MAC_PASTERAW,
    MAC_TAB,
    MAC_NEWWIN,

    WIN_LOCK,
    WIN_COPY,
    WIN_COPYALL,
    WIN_PASTE,
    WIN_TAB,
    WIN_NEWWIN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *          .---------------------------.          .-------------------------------.        .---.
 *          |Gr / Esc|  1|  2|  3|  4|  5|  6|          |  7|  8|  9|  0|  -|  =|  Bsp  |        |EC |
 *          |-------------------------.          .---------------------------------|        |---|
 *          |Tab  |  Q|  W|  E|  R|  T|          |  Y|  U|  I|  O|  P|  [|  ]|  \  |        |Hom|
 *   .---.  |-------------------------.          '---------------------------------|        |---|
 *   |M0 |  |Leader |  A|  S|  D|  F|  G|          |  H|  J|  K|  L|  ;|  :|   Retn |        |End|
 *   |---|  |----------------------------.        '--------------------------------|  .---. '---'
 *   |M1 |  |Shft    |  Z|  X|  C|  V|  B|          |  N|  M|  ,|  ,|  /|  Shift|     |Up |
 *   |---|  |----------------------------|          |---------------------------' .-----------.
 *   |M2 |  |Ctl |Gui |Alt |Space |FN   |          |    Space|   Alt|   Ctl|     |Lef|Dow|Rig|
 *   '---'  '----------------------------'          '-----------------------'     '-----------'
 */

[MAC_BASE] = LAYOUT_lspace_2u_bksp(
            QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,          KC_MUTE,
            KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,   KC_BSLS,   KC_DEL,
    MAC_COPY,   KC_LEAD, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,    KC_ENT,         KC_INS,
    MAC_PASTE,   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                   KC_UP,
    MAC_TAB,   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(1),                  KC_SPC, KC_RGUI, KC_RALT,                               KC_LEFT, KC_DOWN, KC_RGHT
),

[MAC_FN] = LAYOUT_lspace_2u_bksp(
                MAC_LOCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F7, KC_F8, KC_F9, KC_F10, RGB_VAD, RGB_VAI,      KC_TRNS,       KC_TRNS,
                RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_HUI,   KC_TRNS,   KC_HOME,
    MAC_COPYALL,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI,    KC_TRNS,         KC_END,
    MAC_PASTERAW,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_SPI, KC_TRNS,                      KC_TRNS,
    MAC_NEWWIN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS
),
[WIN_BASE] = LAYOUT_lspace_2u_bksp(
          QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6,                KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,   KC_BSPC,          KC_MUTE,
          KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,                     KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,   KC_BSLS,   KC_DEL,
    WIN_COPY,   KC_LEAD, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,    KC_ENT,         KC_INS,
    WIN_PASTE,   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                     KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                   KC_UP,
    WIN_TAB,   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, MO(1),                  KC_SPC, KC_RGUI, KC_RALT,                               KC_LEFT, KC_DOWN, KC_RGHT
),
[WIN_FN] = LAYOUT_lspace_2u_bksp(
          WIN_LOCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,             KC_F7, KC_F8, KC_F9, KC_F10, RGB_VAD, RGB_VAI,      KC_TRNS,       KC_TRNS,
          RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUD, RGB_HUI,   KC_TRNS,   KC_HOME,
    WIN_COPYALL,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI,    KC_TRNS,         KC_END,
    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                        KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_SPI, KC_TRNS,                      KC_TRNS,
    WIN_NEWWIN,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Encoder changes RGB when any mod layer is active
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(MAC_FN) || IS_LAYER_ON(WIN_FN)) {
      if (index == 0) { /* Master Left */
          if (clockwise) {
              rgb_matrix_step();
          } else {
              rgb_matrix_step_reverse();
          }
      } else if (index == 1) { /* Master Right */
          if (clockwise) {
              rgb_matrix_step();
          } else {
              rgb_matrix_step_reverse();
          }
      }
    }
    else {
      if (index == 0) { /* Master Left */
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      } else if (index == 1) { /* Master Right */
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
      }
    }
      return true;
}

// Leader control code
LEADER_EXTERNS();

void matrix_scan_user(void) {

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Caps word when using double leader
        SEQ_ONE_KEY(KC_LEAD) {
            caps_word_on();
        }

        // caps lock with triple leader
        SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) {
            tap_code(KC_CAPS);
        }

        // more basic replace macros
        SEQ_TWO_KEYS(KC_S, KC_C) {
            send_string("[sic!]");
        }

        // mac layer with mac
        SEQ_THREE_KEYS(KC_M, KC_A, KC_C) {
          //switch to mac layer and deactivate others
          layer_clear();
          //persistent
          set_single_persistent_default_layer(MAC_BASE);
        }

        // win layer with win
        SEQ_THREE_KEYS(KC_W, KC_I, KC_N) {
          //switch to win layer
          layer_clear();
          //persistent
          set_single_persistent_default_layer(WIN_BASE);
        }

    }
}

// custom keys
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // mac macros
        case MAC_LOCK:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                register_code(KC_LGUI);
                register_code(KC_Q);
            } else {
                unregister_code(KC_LCTL);
                unregister_code(KC_LGUI);
                unregister_code(KC_Q);
            }
            return false;

        case MAC_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
            }
        return false;

        case MAC_COPYALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("ac"));
            }
            return false;

        case MAC_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            }
            return false;

        case MAC_PASTERAW:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_LSFT(SS_LGUI("v"))));
            }
            return false;

        case MAC_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("t"));
            }
            return false;

        case MAC_NEWWIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("n"));
            }
            return false;

        // win macros
        case WIN_LOCK:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_L);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_L);
            }
            return false;

        case WIN_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            }
        return false;

        case WIN_COPYALL:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("ac"));
            }
            return false;

        case WIN_PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("v"));
            }
            return false;

        case WIN_TAB:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("tl"));
            }
            return false;

        case WIN_NEWWIN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("nl"));
            }
            return false;

        default:
            return true;
    }
}

// OLED control code
#ifdef OLED_ENABLE

void suspend_power_down_user(void) {
    oled_off();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

static const char PROGMEM wpm_str[6] = "Bongo!";

// WPM-responsive animation stuff here
#define IDLE_FRAMES 3 // size reduced from 5
#define IDLE_SPEED 20  // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 25  // above this wpm value typing animation to trigger

#define ANIM_FRAME_DURATION 180 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 512 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
static void render_anim(void) {
    static const char PROGMEM idle[IDLE_FRAMES][ANIM_SIZE] = {
        {
        0,  0,  0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
        // {
        // 0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16, 16,  8,  8,  4,  4,  4,  8, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        // 0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 24,100,130,  2,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        // 0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 56,  4,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        // 0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        // },
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16,  8,  4,  2,  2,  4, 24, 96,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,194,  1,  1,  2,  2,  4,  4,  2,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 96, 96,  0,129,130,130,132,  8, 16, 32, 64,128,  0,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 25,  6,  0,  0,  0,  0,  0,  0,  0, 24, 24, 24, 27,  3,  0, 64,160, 34, 36, 20, 18, 18, 18, 11,  8,  8,  8,  8,  5,  5,  9,  9, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
        // {
        // 0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        // 0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        // 0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        // 0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        // },
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  4,  2,  2,  2,  4, 56, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 28,226,  1,  1,  2,  2,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,192,193,193,194,  4,  8, 16, 32, 64,128,  0,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 13,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  2,  2,  4,  4,  8,  8,  8,  8,  8,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        }
    };
    // static const char PROGMEM prep[][ANIM_SIZE] = {
    //     {
    //     0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
    //     0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
    //     0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132,195,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
    //     0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
    //     }
    // };
    static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,248,248,248,248,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,129,128,128,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,  1,  2,  4,  8, 16, 32, 67,135,  7,  1,  0,184,188,190,159, 95, 95, 79, 76, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0, 24,  6,  5,152,153,132, 67,124, 65, 65, 64, 64, 32, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  8,  8, 16, 16, 16, 16, 16, 17, 15,  1, 61,124,252,252,252,252,252, 60, 12,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32,  16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,  2,  2,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
        {
        0,  0,0,0, 0, 0,0, 0,  0, 0, 0,0,0, 0, 0,  0,0,0, 0, 0,0,0,  0,0,0,  0,0,0, 0, 0,0,0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,128, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  4,  2,  1,  1,  2, 12, 48, 64,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,
        0,  0,  0,  0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,0,0,0,0, 0, 0, 0, 0,0,0, 0, 0, 0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 30,225,  0,  0,  1,  1,  2,  2,  1,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0, 48, 48,  0,  0,  1,225, 26,  6,  9, 49, 53,  1,138,124,  0,  0,128,128,128,128, 64, 64, 64, 64, 32, 32, 32, 32, 16, 16, 16, 16,  8,  8,  8,  8,  8,196,  4,196,  4,196,  2,194,  2,194,  1,  1,  1,  1,  0,  0,  0,
        0,  0,0, 0,  0,  0,0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0, 0,0,  0,  0, 0,0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,112, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 64,160, 33, 34, 18, 17, 17, 17,  9,  8,  8,  8,  8,  4,  4,  4,  4,  4,  4,  2,  2,  2,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,170,170,255,255,195,191,127,  3,127,191,195,255,255,170,170,  0,  0,  0,  0,
        0,  0, 0,0,0,  0, 0, 0,0,0,0, 0, 0, 0, 0,0,  0,0,  0,0, 0, 128, 128, 128, 128,64,64, 64, 64,  32, 32, 32, 32,  16, 16, 16, 16,  8,  8,  8,  8,  8,  4,  4,  4,  4,  4,  2,  3,122,122,121,121,121,121, 57, 49,  2,  2,  4,  4,  8,  8,  8,8,8,7,0,  0,  0,  48,  60,  124,  124,  126,  126,  126,  126,  0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,2,7, 31,  7,31,  7, 28,  7,31,  7,31,  7,  2, 2,  0,  0,  0,  0,
        },
    };

    //assumes 1 frame prep stage
    void animation_phase(void) {
        if(get_current_wpm() <= IDLE_SPEED){
            current_idle_frame = (current_idle_frame + 1) % IDLE_FRAMES;
            oled_write_raw_P(idle[abs((IDLE_FRAMES-1)-current_idle_frame)], ANIM_SIZE);
         }
         if(get_current_wpm() > IDLE_SPEED && get_current_wpm() < TAP_SPEED){
             // oled_write_raw_P(prep[abs((PREP_FRAMES-1)-current_prep_frame)], ANIM_SIZE); // uncomment if IDLE_FRAMES >1
             // no prep due to size issues
             // oled_write_raw_P(prep[0], ANIM_SIZE);  // remove if IDLE_FRAMES >1
         }
         if(get_current_wpm() >= TAP_SPEED){
             current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;
             oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
         }
    }

    if(get_current_wpm() != 000) {
        oled_on(); // not essential but turns on animation OLED with any alpha keypress
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animation_phase();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animation_phase();
            }
        }
    }
}

bool oled_task_user(void) {
    render_anim();

    // default that needs too much space
    // sprintf(wpm_str, "WPM:%03d", get_current_wpm());
    // oled_write(wpm_str, false);

    // small space version, wip
    oled_set_cursor(0, 0);
    oled_write_P(wpm_str, false);
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("L: "), false);
    switch (get_highest_layer(layer_state)) {
        case MAC_BASE:
            oled_write_P(PSTR("M"), false);
            break;
        case MAC_FN:
            oled_write_P(PSTR("MF"), false);
            break;
        case WIN_BASE:
            oled_write_P(PSTR("W"), false);
            break;
        case WIN_FN:
            oled_write_P(PSTR("WF"), false);
            break;
        default:
            oled_write_P(PSTR("X"), false);
    }
    return false;
}

#endif
