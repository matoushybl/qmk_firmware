/* Copyright 2020 Matous Hybl
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    RUN = SAFE_RANGE,
    KC_DEBUG,
    BUILD,
    RENAME,
    GENERATE,
    TERMINAL,
    FF
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        RUN, KC_DEBUG, BUILD, LT(_FN, KC_PSCR), KC_MUTE,
        GENERATE, RENAME, TERMINAL, FF, KC_MPLY
    ),
    [_FN] = LAYOUT(
        RESET, RGB_MODE_PLAIN, KC_C, KC_D, KC_Y,
        RGB_TOG, RGB_MODE_FORWARD, RGB_HUI, RGB_HUD, KC_I
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RUN:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F10)));
            }
            break;
        case KC_DEBUG:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F9)));
            }
            break;
        case BUILD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
            }
            break;
        case RENAME:
            if (record->event.pressed) {
                SEND_STRING(SS_LSFT(SS_TAP(X_F6)));
            }
            break;
        case GENERATE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_INS)));
            }
            break;
        case TERMINAL:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(SS_TAP(X_ENT)));
            }
            break;
        case FF:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("."));
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {
    rgblight_enable();
    rgblight_sethsv(128, 128, 128);
}

/*


void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
            if (!clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        } else if (index == 1) { /* Second encoder */
            if (!clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
    }
}
