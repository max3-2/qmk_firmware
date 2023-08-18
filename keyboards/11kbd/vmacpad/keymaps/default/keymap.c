// Copyright max3-2

#include QMK_KEYBOARD_H

#define ____ KC_TRNS

enum layers{
  _BASE,
  _FN
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H, KC_I, KC_J,
                    TG(_FN),
        KC_L, KC_M, KC_N, KC_O, KC_P
    ),

    [_FN] = LAYOUT(
        ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____,
                    ____,
        ____, ____, ____, ____, ____
    ),

};

// Encoder with backend so this won't be proccessed by default matrix code
// with fast encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // there's only one encoder
        switch(biton32(layer_state)){
            case _FN:
                if (clockwise) {
                    register_code(KC_LEFT);
                    tap_code(KC_LEFT);
                    unregister_code(KC_LCTL);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    tap_code(KC_RIGHT);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LSFT);
                }
                break;

            default:  // _BASE
                if (clockwise){
                    tap_code(KC_DOWN);
                } else{
                    tap_code(KC_UP);
                }
                break;
        }
    }
    return false;
}
