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
#include "features/layer_lock.h"

enum custom_keycodes {
  K_LLOCK = SAFE_RANGE,
  K_SARR, // "Single" Arrow ->
  K_DARR, // "Double" Arrow =>
};

// clang-format off
enum layers {
  PC_BASE = 0,
  MAC_BASE = 2,
  FN,
  JCAPS, // Caps lock layer
  JOPTN, // Option layer
  JCOLON, // Colon layer
  JTAB, // Tab layer
  JSQUA, // Square layer
  MOVE,
  MOUSE,
};

// Key aliases for readability
#define K_JCAPS MO(JCAPS)
#define K_JCOLON LT(JCOLON, KC_SCLN)
#define K_JTAB LT(JTAB, KC_TAB)
#define K_JSQUA LT(JSQUA, KC_MPLY)
#define K_LPAR S(KC_9) // Left parenthesis
#define K_RPAR S(KC_0) // Right parenthesis
#define K_LCBRC S(KC_LBRC) // Left curly bracket
#define K_RCBRC S(KC_RBRC) // Right curly bracket
#define K_BROW_P S(C(KC_TAB)) // Browser tab previous
#define K_BROW_N C(KC_TAB) // Browser tab next
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)

// Combos
enum combos {
    COMBO_LAYER_LOCK,
    COMBO_GUI1,
    COMBO_GUI2,
    COMBO_GUI3,
    COMBO_GUI4,
    COMBO_GUI5,
    COMBO_GUI6,
    COMBO_GUI7,
    COMBO_GUI8,
    COMBO_GUI9,
    COMBO_GUI0,

    // Trick to avoid manually specifing the combo count in config.h.
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_layer_lock[] = { KC_F12, KC_BACKSPACE, COMBO_END };

// GUI+number combos
const uint16_t PROGMEM combo_1q[] = { KC_1, KC_Q, COMBO_END };
const uint16_t PROGMEM combo_2w[] = { KC_2, KC_W, COMBO_END };
const uint16_t PROGMEM combo_3e[] = { KC_3, KC_E, COMBO_END };
const uint16_t PROGMEM combo_4r[] = { KC_4, KC_R, COMBO_END };
const uint16_t PROGMEM combo_5t[] = { KC_5, KC_T, COMBO_END };
const uint16_t PROGMEM combo_6y[] = { KC_6, KC_Y, COMBO_END };
const uint16_t PROGMEM combo_7u[] = { KC_7, KC_U, COMBO_END };
const uint16_t PROGMEM combo_8i[] = { KC_8, KC_I, COMBO_END };
const uint16_t PROGMEM combo_9o[] = { KC_9, KC_O, COMBO_END };
const uint16_t PROGMEM combo_0p[] = { KC_0, KC_P, COMBO_END };

combo_t key_combos[] = {
    [COMBO_LAYER_LOCK] = COMBO(combo_layer_lock, K_LLOCK),

    [COMBO_GUI1] = COMBO(combo_1q, LGUI(KC_1)),
    [COMBO_GUI2] = COMBO(combo_2w, LGUI(KC_2)),
    [COMBO_GUI3] = COMBO(combo_3e, LGUI(KC_3)),
    [COMBO_GUI4] = COMBO(combo_4r, LGUI(KC_4)),
    [COMBO_GUI5] = COMBO(combo_5t, LGUI(KC_5)),
    [COMBO_GUI6] = COMBO(combo_6y, LGUI(KC_6)),
    [COMBO_GUI7] = COMBO(combo_7u, LGUI(KC_7)),
    [COMBO_GUI8] = COMBO(combo_8i, LGUI(KC_8)),
    [COMBO_GUI9] = COMBO(combo_9o, LGUI(KC_9)),
    [COMBO_GUI0] = COMBO(combo_0p, LGUI(KC_0)),
};

// Key aliases for readability
#define K_MOVE LT(MOVE, KC_CAPS)
#define K_JG_B TO(JG_BASE)
#define K_MAC_B TO(MAC_BASE)

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (! process_layer_lock(keycode, record, K_LLOCK)) {
      return false;
  }

  switch (keycode) {
      case K_SARR:
          if (record->event.pressed) {
              SEND_STRING("->");
          }
          break;

      case K_DARR:
          if (record->event.pressed) {
              SEND_STRING("=>");
          }
          break;
  }

  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[PC_BASE] = LAYOUT_tkl_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             K_JSQUA,   KC_MUTE,  BL_TOGG,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS,    KC_HOME,  KC_PGUP,
    K_JTAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL,    KC_END,   KC_PGDN,
    K_JCAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     K_JCOLON, KC_QUOT,            KC_ENT,
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(JOPTN),MO(FN),   KC_RCTL,  KC_LEFT,   KC_DOWN,  KC_RGHT
),

[MAC_BASE] = LAYOUT_tkl_ansi(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  KC_LOPTN, KC_LCMMD,                               _______,                                KC_ROPTN, _______,  _______,  _______,  _______,  _______,  _______
),

// FN layer
[FN] = LAYOUT_tkl_ansi(
    _______,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  _______,  BL_STEP,
    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    BL_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    KC_CAPS,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// Caps Lock layer
[JCAPS] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
    _______,  KC_BTN1,  KC_BTN3,  KC_BTN2,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN2,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,  KC_INS,   KC_DEL,   _______,  K_BROW_P, K_BROW_N, KC_BTN3,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  TO(MOUSE),_______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,  _______,            KC_BTN1,
    _______,            _______,  _______,  _______,  _______,  _______,  KC_PGDN,  KC_HOME,  KC_END,   _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// Option layer
[JOPTN] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_NUM,   KC_SCRL,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// Colon layer
[JCOLON] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  K_LPAR,   K_RPAR,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  OSM_ALT,  OSM_SFT,  OSM_CTL,  OSM_GUI,  OSM_GUI,  OSM_CTL,  OSM_SFT,  OSM_ALT,  _______,  _______,            _______,
    _______,            K_SARR,   K_DARR,   KC_LBRC,  KC_RBRC,  _______,  K_LCBRC,  K_RCBRC,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// Tab layer
[JTAB] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_P7,    KC_P8,    KC_P9,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P4,    KC_P5,    KC_P6,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

// Square layer
[JSQUA] = LAYOUT_tkl_ansi(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,            _______,  KC_MPRV,  KC_MNXT,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[MOUSE] = LAYOUT_tkl_ansi(
    TG(MOUSE),_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_BTN2,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,  _______,  _______,  _______,  _______,  KC_BTN3,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,  _______,  _______,            KC_BTN1,
    _______,            _______,  _______,  _______,  _______,  _______,  KC_WH_D,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______,  _______,  _______
),

};
