/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _MAIN,
  _NAV,
  _SYS,
  _FN,
  _GAME,
  _ER
};

enum preonic_keycodes {
  MAIN = SAFE_RANGE,
  NAV,
  SYS,
  FN,
  GAME,
  ER,
  // RUN,  for elden ring lock running by sending space down
  // ROLL, for elden ring rolls by sending space up if needed and then sending space down space up. various delays are necessary, but I don't rmember exactly where or how long
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_MAIN] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,             KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,
  KC_QUOT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,             KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,             KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_MENU, KC_LALT, KC_LSFT, MO(NAV), LCTL_T(KC_SPC),   MO(FN),  KC_RALT, KC_ENT,  KC_BSLS, KC_RCTL
),


[_NAV] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS,
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_UNDS,
  KC_DQT,  KC_ESC,  KC_BSPC, KC_DEL,  KC_LSFT, KC_PGUP, KC_HOME, KC_LEFT, KC_UP,  KC_RIGHT, _______, _______,
  _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PGDN, _______, KC_END,  KC_DOWN, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


[_SYS] = LAYOUT_preonic_grid(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


[_FN] = LAYOUT_preonic_grid(
  QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  
  _______,  KC_ESC,  KC_BSPC, KC_DEL, KC_LSFT, _______, _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, TO(GAME),_______, TO(ER),  TO(SYS)
),

[_GAME] = LAYOUT_preonic_grid(
  KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_DEL , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_LCTL,   KC_NO,   KC_NO, KC_LALT, KC_LSFT, KC_SPC,  KC_RCTL, KC_RALT, MO(FN),      _______, _______, TO(MAIN)
),

// todo: define the RUN and ROLL keys and put them in KC_BSPC and KC_SPC
[_ER] = LAYOUT_preonic_grid(
  KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_DEL , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_BSPC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  KC_LCTL,   KC_NO,   KC_NO, KC_LALT, KC_LSFT, KC_SPC,  KC_RCTL, KC_RALT, MO(FN),      _______, _______, TO(MAIN)
),

  // _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case MAIN:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MAIN);
          }
          return false;
          break;
        case NAV:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_NAV);
          }
          return false;
          break;
        case SYS:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_SYS);
          }
          return false;
          break;
        case FN:
          if (record->event.pressed) {
            layer_on(_FN);
            update_tri_layer(_FN, _GAME, _ER);
          } else {
            layer_off(_FN);
            update_tri_layer(_FN, _GAME, _ER);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            layer_on(_GAME);
            update_tri_layer(_FN, _GAME, _ER);
          } else {
            layer_off(_GAME);
            update_tri_layer(_FN, _GAME, _ER);
          }
          return false;
          break;
        case ER:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_GAME)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ER);
            } else {
                layer_off(_ER);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case GAME:
    case FN:
      return false;
    default:
      return true;
  }
}
