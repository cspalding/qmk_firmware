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

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_planck_mit(
        KC_ESC,  KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TAB,
        KC_BSPC, LT(1,KC_A), KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,       KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LSFT_T(KC_ENT),
        KC_NO,   KC_LCTL,    KC_LALT, KC_LCMD, MO(2),       KC_SPC,       MO(3),   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT_planck_mit(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT_planck_mit(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_BSLS, KC_F10,  RM_NEXT,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MSTP, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, RM_VALU, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_VOLU, KC_VOLD, KC_TRNS
    ),

    [3] = LAYOUT_planck_mit(
        KC_TRNS, KC_GRV,  KC_LPRN, KC_LBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_TRNS, KC_Z,    KC_RPRN, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RSFT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )

};
// clang-format on

/*
 * From https://www.reddit.com/r/olkb/comments/188wx4u/qmk_inland_mk47_guide/
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        default:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;

        case 0:
            rgb_matrix_set_color_all(RGB_WHITE);
            break;

        case 1:
            // turn ALL keys off
            rgb_matrix_set_color_all(0, 0, 0);

            // light only these 4 keys (replace with your rows/cols)
            rgb_matrix_set_color(19, RGB_CHARTREUSE); // key 2
            rgb_matrix_set_color(20, RGB_CHARTREUSE); // key 2
            rgb_matrix_set_color(21, RGB_CHARTREUSE); // key 3
            rgb_matrix_set_color(22, RGB_CHARTREUSE); // key 1
            break;

        case 2:
            rgb_matrix_set_color_all(RGB_CYAN);
            break;

        case 3:
            rgb_matrix_set_color_all(RGB_PURPLE);
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
