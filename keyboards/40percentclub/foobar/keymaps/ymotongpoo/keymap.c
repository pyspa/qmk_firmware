/* Copyright 2018
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

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum foobar_layers {
  QWERTY,
  FN1,
  FN2,
  FN3,
  FN4,
  FN5
};

#define FN1_B       LT(FN1, KC_B)
#define FN2_N       LT(FN2, KC_N)
#define FN3_D       LT(FN3, KC_D)
#define FN4_F       LT(FN4, KC_F)
#define FN5_P       LT(FN5, KC_P)
#define CTL_A       CTL_T(KC_A)
#define CTL_SCLN    CTL_T(KC_SCLN)
#define SFT_Z       LSFT_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_N       ALGR_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_SLSH    RSFT_T(KC_SLSH)
#define SFT_ENT     RSFT_T(KC_ENT)
#define SFTSPC      LSFT(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [QWERTY] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    FN5_P,
    CTL_A,   KC_S,    FN3_D,   FN4_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    CTL_SCLN,
    SFT_Z,   ALT_X,   KC_C,    KC_V,    FN1_B,   FN2_N,   KC_M,    KC_COMM, KC_DOT,  SFT_SLSH
  ),

  [FN1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_F11,  KC_F12
  ),

  [FN2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [FN3] = LAYOUT_ortho_3x10(
    _______, _______, KC_LGUI, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_TAB,  _______, SFTSPC,  _______, KC_DEL,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    _______, _______, _______, _______, KC_BSPC, KC_SPC,  _______, _______, _______, _______
  ),

  [FN4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_GRV,  KC_TILD, KC_QUOT, _______, _______,
    _______, _______, _______, KC_ESC,  _______, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
  ),

  [FN5] = LAYOUT_ortho_3x10(
    KC_CALC, KC_WHOM, KC_MAIL, KC_MYCM, _______, KC_PSCR, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, BL_DEC,  BL_INC,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

const rgblight_segment_t PROGMEM rgb_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_ORANGE}
);

const rgblight_segment_t PROGMEM rgb_fn1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM rgb_fn2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_GREEN}
);

const rgblight_segment_t PROGMEM rgb_fn3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_AZURE}
);

const rgblight_segment_t PROGMEM rgb_fn4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CYAN}
);

const rgblight_segment_t PROGMEM rgb_fn5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_RED}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_qwerty_layer,
    rgb_fn1_layer,
    rgb_fn2_layer,
    rgb_fn3_layer,
    rgb_fn4_layer,
    rgb_fn5_layer
);

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom_orange();
    rgblight_layers = rgb_layers;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, FN1));
    rgblight_set_layer_state(2, layer_state_cmp(state, FN2));
    rgblight_set_layer_state(3, layer_state_cmp(state, FN3));
    rgblight_set_layer_state(4, layer_state_cmp(state, FN4));
    rgblight_set_layer_state(5, layer_state_cmp(state, FN5));
    return state;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
