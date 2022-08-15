// Copyright 2022 CMM.Studio Freather
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers{
  MAC_BASE,
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_FILE_EXPLORER,
    MAC_HOME,
    MAC_END,
    WIN_TASKMAN,
    Z_CUST,
    Y_CUST
};

// persistent zy shift in EEPROM config
typedef union {
  uint32_t raw;
  struct {
    bool     zy_shift :1;  // defaults to false
  };
} user_config_t;

user_config_t user_config;
bool zy_shift;

// EEPROM reset state
void eeconfig_init_user(void) {  // EEPROM is getting reset!
  user_config.raw = 0;
  user_config.zy_shift = false;
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

#define MAC_APPVIEW C(KC_DOWN)  //ctrl + down is app view on mac
#define KC_MCTL KC_MISSION_CONTROL

// Lighting layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_RED}
);
const rgblight_segment_t PROGMEM my_capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_BLUE}
);
const rgblight_segment_t PROGMEM my_mac_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_CHAT}
);
const rgblight_segment_t PROGMEM my_mac_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_GREEN}
);
const rgblight_segment_t PROGMEM my_win_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_PURPLE}
);
const rgblight_segment_t PROGMEM my_win_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 8, MY_CYAN}
);
const rgblight_segment_t PROGMEM my_yes_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 8, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_no_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 8, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_win_base_layer,
    my_mac_base_layer,
    my_win_fn_layer,
    my_mac_fn_layer,
    my_capsword_layer,
    my_capslock_layer,
    my_yes_layer,
    my_no_layer  // last has strongest override
);

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
    // Set default layer, if enabled
    if (user_config.zy_shift) {
      zy_shift = true;
    }

    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// and enable callbacks
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(5, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, WIN_BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, MAC_BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, WIN_FN));
    rgblight_set_layer_state(3, layer_state_cmp(state, MAC_FN));
    return state;
}

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, MAC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    Y_CUST,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, MAC_END,
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
        KC_LSFT, Z_CUST,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN, KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_RGUI,   MO(MAC_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT(
        _______,  _______, _______, KC_MISSION_CONTROL, MAC_APPVIEW, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, RGB_VAD, _______
    ),
    [WIN_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    Y_CUST,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_END,
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGUP,
        KC_LSFT, Z_CUST,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_PGDN, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_RALT,   MO(WIN_FN), KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [WIN_FN] = LAYOUT(
        _______,  _______, _______, KC_FILE_EXPLORER, WIN_TASKMAN, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAI,
        _______, _______, _______, _______, _______, _______, _______, RGB_VAD, _______
    ),

};

LEADER_EXTERNS();

void matrix_scan_user(void) {

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Caps word when using double leader
        SEQ_ONE_KEY(KC_LEAD) {
            caps_word_on();
            rgblight_set_layer_state(4, true);
        }

        // caps lock with triple leader
        SEQ_TWO_KEYS(KC_LEAD, KC_LEAD) {
            tap_code(KC_CAPS);
        }

        // mac layer with mac
        SEQ_THREE_KEYS(KC_M, KC_A, KC_C) {
          //switch to mac layer and deactivate others
          layer_clear();
          //persistent
          set_single_persistent_default_layer(MAC_BASE);
          //make some leds shine in layers above
        }

        // win layer with win
        SEQ_THREE_KEYS(KC_W, KC_I, KC_N) {
          //switch to win layer
          layer_clear();
          //persistent
          set_single_persistent_default_layer(WIN_BASE);
          //make some leds shine in layers above
        }

        // change zy shift with zy
        SEQ_TWO_KEYS(KC_S, KC_W) {
            zy_shift = !zy_shift;
            if (zy_shift) {
              rgblight_blink_layer_repeat(6, 300, 4);
            }
            else {
              rgblight_blink_layer_repeat(7, 300, 4);
            }
            // Update eeprom
            user_config.zy_shift = zy_shift;
            eeconfig_update_user(user_config.raw);
        }

        // more basic replace macros
        SEQ_TWO_KEYS(KC_S, KC_C) {
            send_string("[sic!]");
        }

    }
}

// disable caps word light
void caps_word_set_user(bool active) {
    if (!active) {
      rgblight_set_layer_state(4, false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key

        case MAC_HOME:
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_LEFT);
          } else {
            unregister_code(KC_LEFT);
            unregister_code(KC_LGUI);
          }
          return false;

        case MAC_END:
          if (record->event.pressed) {
            register_code(KC_LGUI);
            register_code(KC_RGHT);
          } else {
            unregister_code(KC_RGHT);
            unregister_code(KC_LGUI);
          }
          return false;

        case KC_FILE_EXPLORER:
          if (record->event.pressed) {
            SEND_STRING(SS_LGUI("E"));
          } else {

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

        case Z_CUST:
          if (record->event.pressed) {
            if (!zy_shift) {
              register_code(KC_Z);
            }
            else {
              register_code(KC_Y);
            }
          }
          else {
            if (!zy_shift) {
              unregister_code(KC_Z);
            }
            else {
              unregister_code(KC_Y);
            }
          }
          return false;

        case Y_CUST:
        if (record->event.pressed) {
          if (!zy_shift) {
            register_code(KC_Y);
          }
          else {
            register_code(KC_Z);
          }
        }
        else {
          if (!zy_shift) {
            unregister_code(KC_Y);
          }
          else {
            unregister_code(KC_Z);
          }
        }
        return false;

        default:
            return true;   // Process all other keycodes normally
    }
};
