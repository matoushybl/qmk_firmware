#include QMK_KEYBOARD_H

// const uint16_t PROGMEM home_combo[] = {KC_LALT, KC_LEFT, COMBO_END};
// const uint16_t PROGMEM end_combo[] = {KC_LALT, KC_RGHT, COMBO_END};
// const uint16_t PROGMEM pgup_combo[] = {KC_LALT, KC_UP, COMBO_END};
// const uint16_t PROGMEM pgdown_combo[] = {KC_LALT, KC_DOWN, COMBO_END};
//
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(home_combo, KC_HOME),
//     COMBO(end_combo, KC_END),
//     COMBO(pgup_combo, KC_PGUP),
//     COMBO(pgdown_combo, KC_PGDOWN)
// };
enum custom_keycodes {
  KC_BSPCDEL = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_all( /* 0: qwerty */
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPCDEL, KC_GRV,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,
        KC_LSFT, TG(2),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP, MO(1),
        KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                      MO(2), KC_LEFT, KC_DOWN,  KC_RGHT
    ),

    [1] = LAYOUT_all( /* 1: fn */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______,
        _______, _______, KC_AUDIO_VOL_UP,   _______, _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, _______, _______,
        _______, KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,
        _______, _______, _______,                   _______,                                     _______, KC_HOME, KC_PGDOWN, KC_END
    ),

    [2] = LAYOUT_all( /* 2: arrows */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
        _______, _______, _______,                   _______,                                     _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t saved_mods = 0;
    switch (keycode) {
        case KC_BSPCDEL:
            if (record->event.pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    saved_mods = get_mods() & MOD_MASK_SHIFT;
                    del_mods(saved_mods);
                    register_code(KC_DEL);
                } else {
                    saved_mods = 0;
                    register_code(KC_BSPC);
                }
            } else {
                add_mods(saved_mods);
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
            }
            return false;
        default:
            return true;
    }
}

void keyboard_post_init_user(void) {
    gh60_esc_led_on();
    gh60_poker_leds_on();
}

void matrix_scan_user(void) {

//Layer LED indicators
    uint32_t layer = layer_state;

    if (layer & (1<<1)) {
        gh60_wasd_leds_on();
        gh60_fn_led_on();
    } else {
        gh60_wasd_leds_off();
        gh60_fn_led_off();
    }

};
