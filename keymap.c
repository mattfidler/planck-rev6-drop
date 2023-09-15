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

#ifdef USE_MUSE
#include "muse.h"
#endif
#include "version.h"

enum planck_layers {
  _COLEMAK,
  _MOUSE,
  _MOVE,
  _MEDIA,
  _NUM,
  _SYM,
  _FN,
  _CA_NUM_R,
  _CA_NUM_L
};

enum planck_keycodes {
  M_NA= SAFE_RANGE,
  M_LARW,
  M_FALSE,
  M_AIC,
  M_RxODE,
  M_TRUE,
  M_CRAN,
  M_NULL,
  M_PIPE,
  M_ASGN,
};


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define LT_SPC  LT(_MOVE,      KC_SPACE)
#define LT_TAB    LT(_MOUSE,     KC_TAB)
#define LT_ESC LT(_MEDIA,     KC_ESCAPE)
#define LT_BSP LT(_NUM,       KC_BACKSPACE)
#define LT_RET  LT(_SYM,       KC_ENTER)
#define LT_DEL LT(_FN,        KC_DELETE)
#define LT_F      KC_F
#define LT_P      KC_P
#define LT_L      KC_L
#define LT_U      KC_U
//#define LT_M      LT(_CA_NUM_L,  KC_M)
#define LT_M      KC_M
#define LT_C      LT(_CA_NUM_R, KC_C)
//#define LT_V      LT(_CA_NUM_R,  KC_V)
#define LT_V      KC_V

#define Q_A  LGUI_T(KC_A)
#define Q_R LALT_T(KC_R)
#define Q_S LCTL_T(KC_S)
#define Q_T LSFT_T(KC_T)
#define Q_N RSFT_T(KC_N)
#define Q_E RCTL_T(KC_E)
#define Q_I RALT_T(KC_I)
#define Q_O RGUI_T(KC_O)
#define Q_QUO KC_QUOTE
#define Q_X KC_X
#define Q_CMA LT(_CA_NUM_L, KC_COMMA)
#define Q_DOT KC_DOT
#define Q_SLASH KC_SLASH


#define MW_UP   KC_MS_WH_UP
#define MW_DOWN KC_MS_WH_DOWN
#define MW_LEFT KC_MS_WH_LEFT
#define MW_RGHT KC_MS_WH_LEFT

#define MS_UP KC_MS_UP
#define MS_DOWN KC_MS_DOWN
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_1 KC_MS_BTN1
#define MS_2 KC_MS_BTN2
#define MS_3 KC_MS_BTN3

#define QLSHIFT KC_LEFT_SHIFT
#define QRSHIFT KC_RIGHT_SHIFT
#define QLCTRL KC_LEFT_CTRL
#define QLALT  KC_LEFT_ALT
#define QLGUI KC_LGUI
#define QRALT KC_RALT

#define UNDO KC_PC_UNDO
#define CUT  KC_PC_CUT
#define COPY  KC_PC_COPY
#define PASTE  KC_PC_PASTE
#define REDO LCTL(KC_Y)

#define Q_INS KC_INSERT
#define PG_DOWN KC_PAGE_DOWN
#define Q_RIGHT KC_RIGHT
#define Q_CAPS QK_CAPS_WORD_TOGGLE
#define KC_BSPACE KC_BACKSPACE

#define VOL_UP KC_AUDIO_VOL_UP
#define PREV KC_MEDIA_PREV_TRACK
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define NEXT KC_MEDIA_NEXT_TRACK
#define MUTE KC_AUDIO_MUTE
#define PLAY KC_MEDIA_PLAY_PAUSE
#define STOP KC_MEDIA_STOP

#define LBRACKET KC_LEFT_BRACKET
#define RBRACKET KC_RIGHT_BRACKET
#define KC_SCOLON KC_SEMICOLON
#define KC_BSLASH KC_BACKSLASH
#define KC_PSCREEN KC_SYSTEM_REQUEST
#define KC_SCROLLLOCK KC_SCROLL_LOCK
#define KC_RSHIFT KC_RIGHT_SHIFT
#define KC_LSHIFT KC_LEFT_SHIFT

#define APPS KC_APPLICATION

#define CTL_1 LCTL(KC_1)
#define CTL_2 LCTL(KC_2)
#define CTL_3 LCTL(KC_3)
#define CTL_4 LCTL(KC_4)
#define CTL_5 LCTL(KC_5)
#define CTL_6 LCTL(KC_6)
#define CTL_7 LCTL(KC_7)
#define CTL_8 LCTL(KC_8)
#define CTL_9 LCTL(KC_9)
#define CTL_0 LCTL(KC_0)

#define ALT_1 LALT(KC_1)
#define ALT_2 LALT(KC_2)
#define ALT_3 LALT(KC_3)
#define ALT_4 LALT(KC_4)
#define ALT_5 LALT(KC_5)
#define ALT_6 LALT(KC_6)
#define ALT_7 LALT(KC_7)
#define ALT_8 LALT(KC_8)
#define ALT_9 LALT(KC_9)
#define ALT_0 LALT(KC_0)

#define ACTL_1 LALT(LCTL(KC_1))
#define ACTL_2 LALT(LCTL(KC_2))
#define ACTL_3 LALT(LCTL(KC_3))
#define ACTL_4 LALT(LCTL(KC_4))
#define ACTL_5 LALT(LCTL(KC_5))
#define ACTL_6 LALT(LCTL(KC_6))
#define ACTL_7 LALT(LCTL(KC_7))
#define ACTL_8 LALT(LCTL(KC_8))
#define ACTL_9 LALT(LCTL(KC_9))
#define ACTL_0 LALT(LCTL(KC_0))
#define AF4    LALT(KC_F4)

#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I LALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HM_T:
  case HM_N:
    return TAPPING_TERM;
  default:
    return TAPPING_TERM + 50;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
       KC_Q,   KC_W,   LT_F,   LT_P,   KC_G,                           KC_J,   LT_L,   LT_U,   KC_Y,  Q_QUO,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
        Q_A,    Q_R,    Q_S,    Q_T,   KC_D,                           KC_H,    Q_N,    Q_E,    Q_I,    Q_O,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_Z,    Q_X,   LT_C,   LT_V,   KC_B,                           KC_K,   LT_M,  Q_CMA,  Q_DOT,Q_SLASH,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                             LT_DEL, LT_BSP, LT_RET,         LT_TAB, LT_SPC, LT_ESC
 //                        |-------+-------+-------|       |-------+-------+-------|
                           ),
  [_MOUSE] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      MW_UP,MW_LEFT,  MS_UP,MW_RGHT,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
    MW_DOWN,MS_LEFT,MS_DOWN,MS_RGHT,  KC_NO,                          KC_NO,QLSHIFT, QLCTRL,  QLALT,  QLGUI,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       UNDO,    CUT,   COPY,  PASTE,   REDO,                         KC_NO,  KC_NO,  KC_NO,  QRALT,  KC_NO,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                               MS_3,   MS_2,   MS_1,          KC_NO,  KC_NO,  KC_NO
 //                        |-------+-------+-------|       |-------+-------+-------|
                         ),
  [_MOVE] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
    KC_PGUP,KC_HOME,  KC_UP, KC_END,  Q_INS,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
    PG_DOWN,KC_LEFT,KC_DOWN,Q_RIGHT, Q_CAPS,                          KC_NO,QLSHIFT, QLCTRL,  QLALT,  QLGUI,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       UNDO,    CUT,   COPY,  PASTE,   REDO,                          KC_NO,  KC_NO,  KC_NO,  QRALT,  KC_NO,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                       KC_DELETE,  KC_BSPACE, KC_ENTER,       KC_NO, KC_NO, KC_NO
 //                        |-------+-------+-------|       |-------+-------+-------|
                        ),
  [_MEDIA] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
    RGB_VAI,RGB_SPD, VOL_UP,RGB_SPI,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
    RGB_VAD,   PREV,VOL_DOWN,  NEXT,  KC_NO,                          KC_NO,QLSHIFT, QLCTRL, QLALT,   QLGUI,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
    RGB_TOG,RGB_MOD,RGB_HUD,RGB_HUI,RGB_MOD,                          KC_NO,  KC_NO,  KC_NO,  QRALT,  KC_NO,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                               MUTE,   PLAY,   STOP,          KC_NO,  KC_NO,  KC_NO
 //                        |-------+-------+-------|       |-------+-------+-------|
                         ),
  [_NUM] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      RESET,    KC_NO,  KC_NO,  KC_NO,  KC_NO,                       LBRACKET,   KC_7,   KC_8,   KC_9, RBRACKET,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      QLGUI,  QLALT, QLCTRL,QLSHIFT,  KC_NO,                       KC_EQUAL,   KC_4,   KC_5,   KC_6, KC_SCOLON,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      KC_NO,  QRALT,  KC_NO,  KC_NO,  KC_NO,                      KC_BSLASH,   KC_1,   KC_2,   KC_3, KC_GRAVE,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                              KC_NO,  KC_NO, KC_NO,        KC_MINUS,   KC_0, KC_DOT
 //                        |-------+-------+-------|       |-------+-------+-------|
                       ),
  [_SYM] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      RESET, KC_NO,   KC_NO,  KC_NO,  KC_NO,                        KC_LCBR,KC_AMPR,KC_ASTR,KC_LPRN,KC_RCBR,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      QLGUI,  QLALT, QLCTRL,QLSHIFT,  KC_NO,                        KC_PLUS, KC_DLR,KC_PERC,KC_CIRC,KC_COLN,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      KC_NO,  QRALT,  KC_NO,  KC_NO,  KC_NO,                        KC_PIPE,KC_EXLM,  KC_AT,KC_HASH,KC_TILD,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                              KC_NO,  KC_NO,  KC_NO,        KC_UNDS,KC_LPRN,KC_RPRN
 //                        |-------+-------+-------|       |-------+-------+-------|
                       ),
  [_FN] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      RESET,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                     KC_PSCREEN,  KC_F7,  KC_F8,  KC_F9, KC_F12,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      QLGUI,  QLALT, QLCTRL,QLSHIFT,  KC_NO,                  KC_SCROLLLOCK,  KC_F4,  KC_F5,  KC_F6, KC_F11,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      KC_NO,  QRALT,  KC_NO,  KC_NO,  KC_NO,                       KC_PAUSE,  KC_F1,  KC_F2,  KC_F3, KC_F10,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                              KC_NO,  KC_NO,  KC_NO,           APPS,   APPS,   APPS
 //                        |-------+-------+-------|       |-------+-------+-------|
                      ),
  [_CA_NUM_R] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      RESET,  KC_NO, KC_NO,   KC_NO,  KC_NO,                          CTL_6,  CTL_7,  CTL_8,  CTL_9,  CTL_0,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      QLGUI, QLSHIFT,QLSHIFT,QLSHIFT,  KC_NO,                          ALT_6,  ALT_7,  ALT_8,  ALT_9,  ALT_0,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                         M_NULL, KC_NO,   KC_NO, M_PIPE,  KC_NO,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                              KC_NO,  KC_NO,  KC_NO,         M_ASGN, M_LARW,   APPS
 //                        |-------+-------+-------|       |-------+-------+-------|
                            ),
  [_CA_NUM_L] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
      CTL_1,  CTL_2,  CTL_3,  CTL_4,  CTL_5,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      ALT_1,  ALT_2,  ALT_3,  ALT_4,  ALT_5,                          KC_NO,QLSHIFT,QRSHIFT,QRSHIFT,  QLGUI,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
     KC_NO, M_RxODE, M_CRAN,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
 //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                               APPS, M_TRUE,M_FALSE,          KC_NO,  KC_NO,  KC_NO
 //                        |-------+-------+-------|       |-------+-------+-------|
                            )
};

bool isMouse = false;
bool isMove = false;

#ifdef OLED_ENABLE
void set_keylog(uint16_t keycode, keyrecord_t *record);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
#endif
  switch (keycode) {
  case M_NA:
    if (record->event.pressed) {
      SEND_STRING("NA");
    }
    break;
  case M_LARW:
    if (record->event.pressed) {
      SEND_STRING("->");
    }
    break;
  case M_FALSE:
    if (record->event.pressed) {
      SEND_STRING("FALSE");
    }
    break;
  case M_AIC:
    if (record->event.pressed) {
      SEND_STRING("AIC");
    }
    break;
  case M_RxODE:
    if (record->event.pressed) {
      SEND_STRING("RxODE");

    }
    break;
  case M_TRUE:
    if (record->event.pressed) {
      SEND_STRING("TRUE");
    }
    break;
  case M_CRAN:
    if (record->event.pressed) {
      SEND_STRING("CRAN");
    }
    break;
  case M_NULL:
    if (record->event.pressed) {
      SEND_STRING("NULL");
    }
    break;
  case M_PIPE:
    if (record->event.pressed) {
      SEND_STRING("%>%");
    }
    break;
  case M_ASGN:
    if (record->event.pressed) {
      SEND_STRING("<-");
    }
    // http://norvig.com/mayzner.html
    // th = 3.56% (Alternating hand bigram)
    // he = 3.07% (H is not home row)
    // in = 2.43%
    // er = 2.05% Alternating hand // ctrl
    // an = 1.99% Alternating hand // win n
    // re = 1.85% Alternating hand // alt e
    // on = 1.76%
    // at = 1.49%
    // en = 1.45%
    // nd = 1.35% Alternating hand // D
    // ti = 1.34% Alternating hand // I
    // es = 1.34% Alternating hand // ctrl s
    // or = 1.28% Alternating hand // run command redundant with simple windows key
    // te = 1.20% Alternating hand // E
    // of = 1.17% Alternating hand // win + f
    // ed = 1.17% Alternating hand // ctrl d
    // is = 1.13% Alternating hand // alt s
    // it = 1.12% Alternating hand // alt t
    // al = 1.09% Alternating hand // win l
    // ar = 1.07%
    // st = 1.05%
    // to = 1.04% Alternating hand // O
    // nt = 1.04% Alternating hand // T
    // ng = 0.95% Alternating hand // G
    // se = 0.93% Alternating hand // ctrl e
    // ha = 0.93% Alternating hand // non home row modifiers
    // as = 0.87%
    // ou = 0.87%
    // io = 0.83%
    // le = 0.83% no home row mods
    // ve = 0.83% no home row mods
    // co = 0.79% alternating hands
    // me = 0.79% no home row mods
    // de = 0.76% no howe row mods
    // hi = 0.73% no home row mods
    // ri = 0.73% Alternating hands alt i
    // ro = 0.73% Alternating hands alt o
    // ic = 0.70% Alternating hands alt c
    // ne = 0.69%

    // Bigrams that do not exist jq, qg, qy, qz, wq, and qz


    // common bigraphs that contain home row mods on same hand
    // ou, in, st, en
  case HM_R:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
        // or = 1.28% Alternating hand // run command redundant with simple windows key
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_O);
        tap_code(KC_R);
        add_mods(MOD_BIT(KC_RGUI));
        return false;
      } else if (get_mods() & MOD_BIT(KC_LGUI)) {
        // ar 1.07%
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_A);
        tap_code(KC_R);
        add_mods(MOD_BIT(KC_LGUI));
        return false;
      }
    }
    return true;
  case LT_F:
    //// of = 1.17% Alternating hand // win + f
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_O);
        tap_code(KC_F);
        add_mods(MOD_BIT(KC_RGUI));
        return false;
      }
    }
    return true;
  case LT_L:
    //al = 1.09% Alternating hand
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_A);
        tap_code(KC_L);
        add_mods(MOD_BIT(KC_LGUI));
        return false;
      }
    }
    return true;
  case LT_M:
    // om bigraph
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_O);
        tap_code(KC_M);
        add_mods(MOD_BIT(KC_RGUI));
        return false;
      } else if (get_mods() & MOD_BIT(KC_RCTL)) {
        // em bigraph
        unregister_mods(MOD_BIT(KC_RCTL));
        tap_code(KC_E);
        tap_code(KC_M);
        add_mods(MOD_BIT(KC_RCTL));
        return false;
      }
    }
    return true;
  case LT_U:
    // handle ou case and send ou for gui right+u
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
        // ou = 0.87%
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_O);
        tap_code(KC_U);
        add_mods(MOD_BIT(KC_RGUI));
        return false;
      }
    }
    return true;
  case HM_T:
    // handles st
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
        // handle at 1.49%
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_A);
        tap_code(KC_T);
        unregister_mods(MOD_BIT(KC_LGUI));
        return false;
      } else if (get_mods() & MOD_BIT(KC_LCTL)) {
        // handle st 1.05%
        unregister_mods(MOD_BIT(KC_LCTL));
        tap_code(KC_S);
        tap_code(KC_T);
        add_mods(MOD_BIT(KC_LCTL));
        return false;
      }
    }
    return true;
  case HM_N:
    // handle en and in
    if (record->tap.count > 0) {
      uint8_t current_mods = get_mods();
      if (current_mods & MOD_BIT(KC_RALT)) {
        // in 2.43%
        unregister_mods(MOD_BIT(KC_RALT));
        tap_code(KC_I);
        tap_code(KC_N);
        add_mods(MOD_BIT(KC_RALT));
        return false;
      } else if (current_mods & MOD_BIT(KC_LGUI))  {
        //an = 1.99% Alternating hand
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_A);
        tap_code(KC_N);
        add_mods(MOD_BIT(KC_LGUI));
        return false;
      } else if (current_mods & MOD_BIT(KC_RGUI)) {
        // on 1.76%
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_O);
        tap_code(KC_N);
        add_mods(MOD_BIT(KC_RGUI));
        return false;
      } else if (current_mods & MOD_BIT(KC_RCTL)) {
        // en 1.45%
        unregister_mods(MOD_BIT(KC_RCTL));
        tap_code(KC_E);
        tap_code(KC_N);
        add_mods(MOD_BIT(KC_RCTL));
        return false;
      }
    }
    return true;
  case HM_S:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
        // as 0.87%
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_A);
        tap_code(KC_S);
        add_mods(MOD_BIT(KC_LGUI));
        return false;
      }
      return true;
    }
  case HM_O:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RALT)) {
        // handle io 0.83%
        unregister_mods(MOD_BIT(KC_RALT));
        tap_code(KC_I);
        tap_code(KC_O);
        add_mods(MOD_BIT(KC_RALT));
        return false;
      }
    }
    return true;
  case HM_E:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RSHIFT)) {
        // ne
        unregister_mods(MOD_BIT(KC_RSHIFT));
        tap_code(KC_N);
        tap_code(KC_E);
        add_mods(MOD_BIT(KC_RSHIFT));
        return false;
      }
    }
    return true;
  case HM_A:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RALT)) {
        // ra
        unregister_mods(MOD_BIT(KC_RALT));
        tap_code(KC_R);
        tap_code(KC_A);
        add_mods(MOD_BIT(KC_RALT));
        return false;
      }
    }
    return true;
  case LT_SPC:
    if (record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RSHIFT)) {
        // n
        unregister_mods(MOD_BIT(KC_RSHIFT));
        tap_code(KC_N);
        tap_code(KC_SPC);
        add_mods(MOD_BIT(KC_RSHIFT));
        return false;
      } else if (get_mods() & MOD_BIT(KC_LSHIFT)) {
        // t
        unregister_mods(MOD_BIT(KC_LSHIFT));
        tap_code(KC_T);
        tap_code(KC_SPC);
        add_mods(MOD_BIT(KC_LSHIFT));
        return false;
      }
    }
    break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (clockwise) {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_DOWN);
#else
      tap_code(KC_PAGE_DOWN);
#endif
    } else {
#ifdef MOUSEKEY_ENABLE
      tap_code(KC_MS_WH_UP);
#else
      tap_code(KC_PGUP);
#endif
    }
  }
  return true;
}

void matrix_scan_user(void) {
#ifdef USE_MUSE
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
    /* case KC_NO: */
    /* case LOWER: */
    /*   return false; */
  default:
    return true;
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}
// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);


const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);


void oled_render_layer_state(void) {
  char string [24];
  switch (get_highest_layer(default_layer_state|layer_state))
  {
      case _COLEMAK:
        oled_write_ln_P(PSTR("Layer: COLEMAK"),false);
        break;
      case _MOUSE:
        oled_write_ln_P(PSTR("Layer: MOUSE"),false);
        break;
      case _MOVE:
        oled_write_ln_P(PSTR("Layer: MOVE"),false);
        break;
      case _MEDIA:
        oled_write_ln_P(PSTR("Layer: MEDIA"),false);
        break;
      case _NUM:
        oled_write_ln_P(PSTR("Layer: Numbers"),false);
        break;
      case _SYM:
        oled_write_ln_P(PSTR("Layer: Symbols"),false);
        break;
      case _FN:
        oled_write_ln_P(PSTR("Layer: Function"),false);
        break;
      case _CA_NUM_R:
        oled_write_ln_P(PSTR("Layer: Right C/A Numbers"),false);
        break;
      case _CA_NUM_L:
        oled_write_ln_P(PSTR("Layer: Left C/A Numbers"),false);
        break;
      default:
        snprintf(string, sizeof(string), "%ld",layer_state);
        oled_write_P(PSTR("Layer: Undef-"),false);
        oled_write_ln(string, false);
    }
 }

/*
void matrix_render_user(struct CharacterMatrix *matrix) {
  if (has_usb()) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}
*/

char keylog_str[24] = {};
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return true;
}
#endif
