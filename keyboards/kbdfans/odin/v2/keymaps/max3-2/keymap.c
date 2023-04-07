/* Copyright 2023 max3-2
 * MIT License
 * Custom keymap for Odin v2, max3-2
 */

#include QMK_KEYBOARD_H

enum layers{
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    KC_FILE_EXPLORER = SAFE_RANGE,
    WIN_TASKMAN,
    WIN_LOCK,
    WIN_SNIP
};

// Lighting layers
const rgblight_segment_t PROGMEM my_capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, RGB_CORAL}
);
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, RGB_PINK}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capsword_layer,
    my_capslock_layer // last has strongest override
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
};

// and enable callbacks
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
};

// Custom KC overides for home and end on alt LR
const key_override_t home_override = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT, KC_LEFT, KC_HOME,
    0, MOD_MASK_CSG
);
const key_override_t end_override = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT, KC_RGHT, KC_END,
    0, MOD_MASK_CSG
);
const key_override_t pgup_override = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT, KC_UP, KC_PGUP,
    ~0, MOD_MASK_CSG
);
const key_override_t pgdn_override = ko_make_with_layers_and_negmods(
    MOD_MASK_ALT, KC_DOWN, KC_PGDN,
    ~0, MOD_MASK_CSG
);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&home_override,
	&end_override,
    &pgup_override,
    &pgdn_override,
	NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT(

        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_MAIL, KC_WWW_SEARCH, KC_CALC, WIN_SNIP,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_PGUP, KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGDN, KC_P7, KC_P8, KC_P9, KC_PPLS,
        QK_LEAD, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(WIN_FN), KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT

    ),

    [WIN_FN] = LAYOUT(

        WIN_LOCK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WWW_HOME, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD,
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_AUDIO_VOL_UP, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_AUDIO_VOL_DOWN, KC_END, _______, _______

    ),
};



void leader_end_user(void) {
    if (leader_sequence_one_key(QK_LEAD)) {
        caps_word_on();
        rgblight_set_layer_state(0, true);
    }
    else if (leader_sequence_two_keys(QK_LEAD, QK_LEAD)) {
        tap_code(KC_CAPS);
    }
    else if (leader_sequence_two_keys(KC_S, KC_C)) {
        SEND_STRING("[sic!]");
    }
};

// disable caps word light
void caps_word_set_user(bool active) {
    if (!active) {
      rgblight_set_layer_state(0, false);
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_FILE_EXPLORER:
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_E);
          } else {
            unregister_code(KC_LGUI);
            unregister_code(KC_E);
          }
          return false;

        case WIN_TASKMAN:
            if (record->event.pressed) {
              register_code(KC_LCTL);
              register_code(KC_LSFT);
              register_code(KC_ESC);
            } else {
              unregister_code(KC_LCTL);
              unregister_code(KC_LSFT);
              unregister_code(KC_ESC);
            }
            return false;

        case WIN_LOCK:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_L);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_L);
            }
            return false;

        case WIN_SNIP:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_S);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
                unregister_code(KC_S);
            }
            return false;

        default:
            return true;   // Process all other keycodes normally
    }
};
