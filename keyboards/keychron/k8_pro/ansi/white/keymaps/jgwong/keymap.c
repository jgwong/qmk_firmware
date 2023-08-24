/* Copyright 2021 @ Keychron (https://www.keychron.com)
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
enum layers {
  PC_BASE = 0,
  JG_BASE = 2,
  MAC_BASE,
  FN,
  MOVE,
  MOUSE
};

// Combos
enum combos {
    COMBO_LEFT_CTRL,
    COMBO_LEFT_GUI,
    COMBO_LEFT_ALT,
    COMBO_RIGHT_CTRL,
    COMBO_RIGHT_GUI,
    COMBO_RIGHT_ALT,

    // Trick to avoid manually specifing the combo count in config.h.
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// Left modifiers
const uint16_t PROGMEM combo_left_ctrl[] = { KC_A, KC_S, COMBO_END };
const uint16_t PROGMEM combo_left_gui[] = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_left_alt[] = { KC_D, KC_F, COMBO_END };

// Right modifiers
const uint16_t PROGMEM combo_right_ctrl[] = { KC_L, KC_SCLN, COMBO_END };
const uint16_t PROGMEM combo_right_gui[] = { KC_K, KC_L, COMBO_END };
const uint16_t PROGMEM combo_right_alt[] = { KC_J, KC_K, COMBO_END };

combo_t key_combos[] = {
    [COMBO_LEFT_CTRL] = COMBO(combo_right_ctrl, KC_LCTL),
    [COMBO_LEFT_GUI] = COMBO(combo_right_gui, KC_LGUI),
    [COMBO_LEFT_ALT] = COMBO(combo_right_alt, KC_LALT),

    [COMBO_RIGHT_CTRL] = COMBO(combo_right_ctrl, KC_RCTL),
    [COMBO_RIGHT_GUI] = COMBO(combo_right_gui, KC_RGUI),
    [COMBO_RIGHT_ALT] = COMBO(combo_right_alt, KC_LALT),
};

// Key aliases for readability
#define K_MOVE LT(MOVE, KC_CAPS)
#define K_JG_B TO(JG_BASE)
#define K_MAC_B TO(MAC_BASE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[PC_BASE] = LAYOUT_tkl_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             KC_PSCR,   KC_CTANA, BL_STEP,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,    KC_END,   KC_PGDN,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RGUI, MO(FN),    KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
),

[JG_BASE] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            K_JG_B,   K_MAC_B,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    K_MOVE,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  MO(FN),   _______,  _______,  _______,  _______
),

[MAC_BASE] = LAYOUT_tkl_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    KC_LCTL,  KC_LOPTN, KC_LCMMD,                               _______,                                KC_ROPTN, KC_RCMMD, MO(FN),   KC_RCTL, _______,  _______,  _______
),

[FN] = LAYOUT_tkl_ansi(
    _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  _______,  BL_TOGG,
    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    BL_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[MOVE] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  MO(MOUSE),_______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[MOUSE] = LAYOUT_tkl_ansi(
    K_JG_B,
              _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN2,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,  _______,  _______,  _______,  _______,  KC_BTN3,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,            KC_BTN1,
    _______,            _______,  _______,  _______,  _______,  _______,  KC_WH_D,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
)

};

bool led_matrix_indicators_user(void) {
    if (layer_state_is(JG_BASE)) {
        led_matrix_set_value(47, 128);
    }
    if (layer_state_is(MAC_BASE)) {
        led_matrix_set_value(48, 128);
    }
    return false;
}

void keyboard_post_init_user(void) {
    layer_move(JG_BASE);
}
