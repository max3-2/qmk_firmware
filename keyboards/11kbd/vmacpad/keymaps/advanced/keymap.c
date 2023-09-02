// Copyright max3-2

#include QMK_KEYBOARD_H
#include "print.h"

#define ____ KC_TRNS

enum layers{
    _FCP,
    _LR,
    _CODE,
    _FCPFN,
    _LRFN,
    _CODEFN
};

enum custom_keycodes {
    ENC_LEVEL = SAFE_RANGE,
    NEXT_LAYER
};

//Encoder state
volatile bool enc_level = false;

// Layer lights
const rgblight_segment_t PROGMEM layer1_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM layer2_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM layer3_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_CHARTREUSE}
);
const rgblight_segment_t PROGMEM layer_fn_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 1, HSV_MAGENTA}
);
const rgblight_segment_t PROGMEM layer_enc_light[] = RGBLIGHT_LAYER_SEGMENTS(
    {4, 1, HSV_ORANGE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer1_light,
    layer2_light,
    layer3_light,
    layer_enc_light,
    layer_fn_light
);

void keyboard_post_init_user(void) {
    // Enable the LED layersi
    rgblight_layers = my_rgb_layers;
    rgblight_set_layer_state(3, enc_level);
    uint8_t current_layer = get_highest_layer(default_layer_state);
    rgblight_set_layer_state(current_layer, true);
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FCP));
    rgblight_set_layer_state(1, layer_state_cmp(state, _LR));
    rgblight_set_layer_state(2, layer_state_cmp(state, _CODE));
    return state;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    bool is_active_fn = layer_state_cmp(state, _FCPFN) |
                        layer_state_cmp(state, _LRFN) ||
                        layer_state_cmp(state, _CODEFN);
    rgblight_set_layer_state(4, is_active_fn);

    return state;
};

// COMBOS to switch layer always I, O
const uint16_t PROGMEM next_layer_combo[] = {KC_I, KC_O, COMBO_END};
combo_t key_combos[] = {
    COMBO(next_layer_combo, NEXT_LAYER),
};

// Layer cycles
#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END   2

//////////////
// Keymaps
/////////////
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_FCP] = LAYOUT(
        LGUI(KC_MINUS), KC_S, MO(_FCPFN), LSFT(KC_Z), LGUI(KC_EQUAL),
        KC_A, KC_P, KC_T, KC_R, KC_B,
                    ENC_LEVEL,
        KC_I, KC_J, KC_SPACE, KC_L, KC_O
    ),

    [_FCPFN] = LAYOUT(
        LGUI(KC_1), LGUI(LALT(KC_1)), ____, LGUI(KC_3), LGUI(KC_2),
        ____, ____, ____, LGUI(LALT(KC_3)), ____,
                    ____,
        ____, ____, ____, ____, ____
    ),

    [_LR] = LAYOUT(
        LGUI(KC_MINUS), KC_S, MO(_LRFN), LSFT(KC_Z), LGUI(KC_EQUAL),
        LGUI(LALT(KC_1)), LGUI(LALT(KC_2)), LGUI(LALT(KC_3)), LGUI(LALT(KC_4)), LGUI(LALT(KC_5)),
                    ENC_LEVEL,
        KC_I, KC_COMMA, KC_SPACE, KC_DOT, KC_O
    ),

    [_LRFN] = LAYOUT(
        LGUI(KC_1), LGUI(LALT(KC_1)), ____, LGUI(KC_3), LGUI(KC_2),
        ____, ____, ____, LGUI(LALT(KC_3)), ____,
                    ____,
        ____, ____, ____, ____, ____
    ),
        [_CODE] = LAYOUT(
        LGUI(KC_MINUS), KC_S, MO(_CODEFN), LSFT(KC_Z), LGUI(KC_EQUAL),
        KC_Z, ____, ____, ____, ____,
                    ENC_LEVEL,
        KC_I, KC_J, KC_SPACE, KC_L, KC_O
    ),

    [_CODEFN] = LAYOUT(
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
    uint8_t current_layer = get_highest_layer(default_layer_state);
    switch(current_layer){
        case 0:
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
            return false;

        case 1:
            if (enc_level) {  // Fast
                    if (clockwise) {
                        tap_code(KC_EQUAL);
                    } else {
                        tap_code(KC_MINUS);
                    }
                }
            else {  // Slow
                if (clockwise) {
                    register_code(KC_LALT);
                    tap_code(KC_EQUAL);
                    unregister_code(KC_LALT);
                } else {
                    register_code(KC_LALT);
                    tap_code(KC_MINUS);
                    unregister_code(KC_LALT);
                }
            }
            return false;

        default:
            return false;
    }
    return false;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ENC_LEVEL:
        if (record->event.pressed) {
        enc_level = !enc_level;
        rgblight_set_layer_state(3, enc_level);
        }
        return false; // Skip all further processing of this key

    case NEXT_LAYER:
        // Our logic will happen on presses, nothing is done on releases
        if (!record->event.pressed) {
            return false;
        }
        uint8_t current_layer = get_highest_layer(default_layer_state);
        // Skip two so FN is always between
        // Now single skip with reorder
        uint8_t next_layer = current_layer + 1;
        if (next_layer > LAYER_CYCLE_END) {
            next_layer = LAYER_CYCLE_START;
        }
        set_single_persistent_default_layer(next_layer);
        // layer_move(next_layer);
        return false;

    default:
      return true; // Process all other keycodes normally
  }
};
