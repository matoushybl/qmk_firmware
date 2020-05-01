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
  KC_BSPCDEL = SAFE_RANGE,
  KC_M_L,
  KC_M_R,
  KC_M_U,
  KC_M_D,
  KC_M_B,
  SSTEST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_all( /* 0: qwerty */
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPCDEL, KC_GRV,
        LT(3, KC_TAB),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        MO(1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,   KC_ENT,
        KC_LSFT, TG(2),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                      KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
    ),

    [1] = LAYOUT_all( /* 1: fn */
        RESET,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, _______,
        KC_SLEP, KC_PWR, KC_VOLU, KC_MPLY, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______,
        _______, KC_MPRV, KC_VOLD, KC_MNXT, _______, KC_INS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, _______, _______,
        MO(2), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   KC_BTN1,                                     KC_HOME, KC_PGDOWN, KC_PGUP, KC_END
    ),
    [2] = LAYOUT_all( /* 1: shift */
        _______,  LSFT(KC_F1),   LSFT(KC_F2),   LSFT(KC_F3),   LSFT(KC_F4),   LSFT(KC_F5),   LSFT(KC_F6),   LSFT(KC_F7),   LSFT(KC_F8),   LSFT(KC_F9),   LSFT(KC_F10),  LSFT(KC_F11),  LSFT(KC_F12),  KC_DEL, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   KC_BTN2,                                     _______, _______, _______, _______
    ),
    [3] = LAYOUT_all( /* 1: czech shit */
        _______, _______, KC_INT7, _______, _______,   LSFT(KC_F5),   LSFT(KC_F6),   LSFT(KC_F7),   LSFT(KC_F8),   LSFT(KC_F9),   LSFT(KC_F10),  LSFT(KC_F11),  LSFT(KC_F12),  KC_DEL, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   KC_BTN2,                                     _______, _______, _______, _______
    ),
    [4] = LAYOUT_all( /* sleep layer */
        KC_PWR,  KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,   KC_PWR,  KC_PWR,  KC_PWR,  KC_PWR, KC_PWR,
        KC_PWR, KC_PWR, KC_PWR,   KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR,
        KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR,
        KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR, KC_PWR,
        KC_PWR, KC_PWR, KC_PWR,                   KC_PWR,                                     KC_PWR, KC_PWR, KC_PWR, KC_PWR
    )
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
        case SSTEST:
            SEND_STRING("é");
            return true;
        break;
        default:
            return true;
    }
}

void keyboard_post_init_user(void) {
    gh60_esc_led_on();
    gh60_poker_leds_on();
}

void suspend_power_down_user(void) {
    gh60_esc_led_off();
    gh60_poker_leds_off();
    // layer_move(2);
}

void suspend_wakeup_init_user(void) {
    gh60_esc_led_on();
    gh60_poker_leds_on();
    // layer_move(0);
}

void matrix_scan_user(void) {

};
