// Copyright max3-2

#include QMK_KEYBOARD_H

#define ____ KC_TRNS

enum layers{
  _BASE,
  _FN
};

enum custom_keycodes {
    ENC_LEVEL = SAFE_RANGE
};

//Encoder state
volatile bool enc_level = true;

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        LGUI(KC_MINUS), KC_S, MO(_FN), LSFT(KC_Z), LGUI(KC_EQUAL),
        KC_A, KC_P, KC_T, KC_R, KC_B,
                    ENC_LEVEL,
        KC_I, KC_J, KC_SPACE, KC_L, KC_O
    ),

    [_FN] = LAYOUT(
        LGUI(KC_1), LGUI(LALT(KC_1)), ____, LGUI(KC_3), LGUI(KC_2),
        ____, ____, ____, LGUI(LALT(KC_3)), ____,
                    ____,
        ____, ____, ____, ____, ____
    ),

};

// Encoder with backend so this won't be proccessed by default matrix code
// with fast encoders. This is debounced by two-step since the encoder works
// best with its native resolution which then has too many pulses
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // there's only one encoder
        if (enc_level) {  // Fast
            if (clockwise) {
                register_code(KC_LSFT);
                tap_code(KC_RIGHT);
                unregister_code(KC_LSFT);
            } else {
                register_code(KC_LSFT);
                tap_code(KC_LEFT);
                unregister_code(KC_LSFT);
            }
        }
        else {  // Slow
            if (clockwise) {
                    tap_code(KC_RIGHT);
            } else {
                    tap_code(KC_LEFT);
            }
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ENC_LEVEL:
      if (record->event.pressed) {
        enc_level = !enc_level;
      }
      return false; // Skip all further processing of this key

    default:
      return true; // Process all other keycodes normally
  }
}

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }
