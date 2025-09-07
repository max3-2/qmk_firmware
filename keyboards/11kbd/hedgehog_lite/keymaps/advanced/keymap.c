#include QMK_KEYBOARD_H

#define ____ KC_TRNS

enum layers{
  _BASE,
  _FN,
  _SUPERFN
};

enum custom_keycodes {
    MAC_LOCK = SAFE_RANGE,
    LR_AEDIT
};

// Lighting layers
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, MY_RED}
);
const rgblight_segment_t PROGMEM my_capsword_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, MY_BLUE}
);
const rgblight_segment_t PROGMEM my_mac_superfn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, MY_GOLD}
);
const rgblight_segment_t PROGMEM my_mac_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 15, MY_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_mac_fn_layer,
    my_mac_superfn_layer,
    my_capsword_layer,
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// and enable callbacks
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SUPERFN));
    return state;
}

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_GRV,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, TG(_FN),
        KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_SPC, KC_RALT, QK_LEAD, MO(_FN)
    ),

    [_FN] = LAYOUT(
        MAC_LOCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, ____, KC_DEL,
        UG_TOGG, ____, KC_UP, LR_AEDIT, ____, ____, ____, ____, ____, ____, ____, UG_PREV, UG_NEXT, KC_AUDIO_MUTE, ____,
        ____, KC_LEFT, KC_DOWN, KC_RIGHT, ____, ____, ____, ____, ____, ____, UG_VALD, UG_VALU, KC_MEDIA_PLAY_PAUSE,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, UG_HUED, UG_HUEU, MO(_SUPERFN),
        ____, ____, ____, ____, ____, ____
    ),
    [_SUPERFN] = LAYOUT(
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, KC_PAGE_UP, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, KC_HOME, KC_PAGE_DOWN, KC_END, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
        ____, ____, ____, ____, ____, ____
    ),
};

void leader_end_user(void) {
    if (leader_sequence_one_key(QK_LEAD)) {
        caps_word_on();
        rgblight_set_layer_state(1, true);
    }
    else if (leader_sequence_two_keys(QK_LEAD, QK_LEAD)) {
        tap_code(KC_CAPS);
    }
    else if (leader_sequence_two_keys(KC_S, KC_C)) {
        SEND_STRING("[sic!]");
    }
}

// disable caps word light
void caps_word_set_user(bool active) {
    if (!active) {
      rgblight_set_layer_state(1, false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
      case LR_AEDIT:
          if (record->event.pressed) {
              register_code(KC_LGUI);
              register_code(KC_U);
          } else {
              unregister_code(KC_LGUI);
              unregister_code(KC_U);
          }
          return false;

      default:
          return true;
    }
}
