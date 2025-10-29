/* Copyright (C) 2023 jonylee@hfd
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

enum custom_keycodes {
    LAYERRAISE = SAFE_RANGE,
    LAYERDROP,
    WINCYC,
    LN_STRT,
    LN_END,
    WRDLEFT,
    WRDRGHT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,       KC_W,       KC_E,    KC_R, KC_T, KC_Y,   KC_U, KC_I,     KC_O,    KC_P,    KC_TAB,
        KC_BSPC, LT(1,KC_A), LT(2,KC_S), KC_D,    KC_F, KC_G, KC_H,   KC_J, KC_K,     KC_L,    KC_SCLN, LSFT_T(KC_QUOT),
        KC_LSFT, KC_Z,       KC_X,       KC_C,    KC_V, KC_B, KC_N,   KC_M, KC_COMM,  KC_DOT,  KC_SLSH, KC_ENT,
        KC_NO,   KC_LCTL,    KC_LALT,    KC_LCMD, MO(3),    KC_SPC,   MO(4), KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_EQL,  KC_7,    KC_8,    KC_9, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS, KC_MINS, KC_4,    KC_5,    KC_6, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT, KC_LCMD, KC_TRNS, KC_DOT,  KC_1,    KC_2,    KC_3, KC_RSFT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LN_STRT, LN_END,  WINCYC,  KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, WRDLEFT, WRDRGHT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_TRNS
    ),

    [3] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LN_STRT, KC_TRNS, KC_TRNS, LN_END, KC_TRNS,
        KC_TRNS, KC_LCTL, KC_LALT, KC_LCMD, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, WRDLEFT, KC_TRNS, KC_TRNS, WRDRGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [4] = LAYOUT_planck_mit(
        KC_TRNS, KC_GRV,  KC_LPRN, KC_LBRC, KC_LCBR, KC_BSLS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_COMM, KC_RPRN, KC_RBRC, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS,  KC_RSFT, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_DOT,  KC_EQL,  KC_PIPE, KC_UNDS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

};
// clang-format on

/*
 * From https://www.reddit.com/r/olkb/comments/188wx4u/qmk_inland_mk47_guide/
 * NOTE: useful LED indices - Q: 1, A: 13, J: 19
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        default:
            rgb_matrix_set_color_all(0, 0, 0);
            break;

        case 0:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_matrix_set_color(13, RGB_CHARTREUSE);
            rgb_matrix_set_color(14, RGB_CORAL);
            rgb_matrix_set_color(40, RGB_PURPLE);
            rgb_matrix_set_color(42, RGB_CYAN);
            break;

        case 1:
            // turn ALL keys off
            rgb_matrix_set_color_all(0, 0, 0);

            rgb_matrix_set_color(16, RGB_CHARTREUSE); // LSFT
            rgb_matrix_set_color(26, RGB_CHARTREUSE); // LCTL
            rgb_matrix_set_color(27, RGB_CHARTREUSE); // LALT
            rgb_matrix_set_color(28, RGB_CHARTREUSE); // LGUI

            // light only these 4 keys (replace with your rows/cols)
            rgb_matrix_set_color(44, RGB_CHARTREUSE); // 0

            rgb_matrix_set_color(30, RGB_CHARTREUSE); // .
            rgb_matrix_set_color(31, RGB_CHARTREUSE); // 1
            rgb_matrix_set_color(32, RGB_CHARTREUSE); // 2
            rgb_matrix_set_color(33, RGB_CHARTREUSE); // 3

            rgb_matrix_set_color(18, RGB_CHARTREUSE); // -
            rgb_matrix_set_color(19, RGB_CHARTREUSE); // 4
            rgb_matrix_set_color(20, RGB_CHARTREUSE); // 5
            rgb_matrix_set_color(21, RGB_CHARTREUSE); // 6

            rgb_matrix_set_color(6, RGB_CHARTREUSE); // =
            rgb_matrix_set_color(7, RGB_CHARTREUSE); // 7
            rgb_matrix_set_color(8, RGB_CHARTREUSE); // 8
            rgb_matrix_set_color(9, RGB_CHARTREUSE); // 9
            break;

        case 2:
            rgb_matrix_set_color_all(0, 0, 0);

            rgb_matrix_set_color(7, RGB_CORAL);
            rgb_matrix_set_color(8, RGB_CORAL);
            rgb_matrix_set_color(9, RGB_CORAL);

            rgb_matrix_set_color(19, RGB_CORAL);
            rgb_matrix_set_color(20, RGB_CORAL);

            rgb_matrix_set_color(29, RGB_CORAL);
            rgb_matrix_set_color(30, RGB_CORAL);
            rgb_matrix_set_color(31, RGB_CORAL);
            rgb_matrix_set_color(32, RGB_CORAL);
            rgb_matrix_set_color(33, RGB_CORAL);
            rgb_matrix_set_color(44, RGB_CORAL);
            rgb_matrix_set_color(45, RGB_CORAL);
            break;

        case 3:
            rgb_matrix_set_color_all(0, 0, 0);

            rgb_matrix_set_color(7, RGB_PURPLE);
            rgb_matrix_set_color(10, RGB_PURPLE);

            rgb_matrix_set_color(13, RGB_PURPLE);
            rgb_matrix_set_color(14, RGB_PURPLE);
            rgb_matrix_set_color(15, RGB_PURPLE);

            rgb_matrix_set_color(19, RGB_PURPLE);
            rgb_matrix_set_color(20, RGB_PURPLE);
            rgb_matrix_set_color(21, RGB_PURPLE);
            rgb_matrix_set_color(22, RGB_PURPLE);

            rgb_matrix_set_color(31, RGB_PURPLE);
            rgb_matrix_set_color(34, RGB_PURPLE);

            break;

        case 4:
            rgb_matrix_set_color_all(0, 0, 0);

            // a bunch of symbols
            rgb_matrix_set_color(1, RGB_CYAN);
            rgb_matrix_set_color(2, RGB_CYAN);
            rgb_matrix_set_color(3, RGB_CYAN);
            rgb_matrix_set_color(4, RGB_CYAN);
            rgb_matrix_set_color(5, RGB_CYAN);

            rgb_matrix_set_color(13, RGB_CYAN);
            rgb_matrix_set_color(14, RGB_CYAN);
            rgb_matrix_set_color(15, RGB_CYAN);
            rgb_matrix_set_color(16, RGB_CYAN);

            rgb_matrix_set_color(20, RGB_CYAN);
            rgb_matrix_set_color(25, RGB_CYAN);
            rgb_matrix_set_color(26, RGB_CYAN);
            rgb_matrix_set_color(27, RGB_CYAN);
            rgb_matrix_set_color(28, RGB_CYAN);
            break;

    }
    return false;
}

/*
 * ChatGPT creation for debugging. Prints out the key index and its LED index.
 * Helpful to figure out lighting.
*/
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (record->event.pressed) {
//         uint8_t row = record->event.key.row;
//         uint8_t col = record->event.key.col;
//         uprintf("row:%u col:%u -> LED index:%d\n", row, col, g_led_config.matrix_co[row][col]);
//     }
//     return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        uint8_t row = record->event.key.row;
        uint8_t col = record->event.key.col;
        int led = g_led_config.matrix_co[row][col];
        uprintf(
            "row:%u col:%u -> LED:%d keycode:%s\n",
            row, col, led, get_u16_str(keycode, 16)
        );

        switch (keycode) {
            case WINCYC:
                // macOS example: Cmd + `
                register_code(KC_LCMD);
                tap_code(KC_GRV);
                unregister_code(KC_LCMD);
                break;
            case LN_STRT:
                register_code(KC_LCMD);
                tap_code(KC_LEFT);
                unregister_code(KC_LCMD);
                break;
            case LN_END:
                register_code(KC_LCMD);
                tap_code(KC_RIGHT);
                unregister_code(KC_LCMD);
                break;
            case WRDLEFT:
                register_code(KC_LALT);
                tap_code(KC_LEFT);
                break;
            case WRDRGHT:
                register_code(KC_LALT);
                tap_code(KC_RIGHT);
                break;
        }
    }
    return true;
}
