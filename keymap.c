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


enum planck_layers {
  _COLEMAK,
  _MOUSE,
  _MOVE,
  _MEDIA,
  _NUM,
  _SYM,
  _FN,
  _CA_NUM_R,
  _CA_NUM_L,
  _MACRO_L2,
  _MACRO_R2,
  _MACRO_L1,
  _MACRO_R1
};

enum planck_keycodes {
  COLEMAK= SAFE_RANGE,
  KMOUSE,
  KMOVE,
  M_NA,
  M_NVS,
  M_LARW,
  M_PRO,
  M_REAL,
  M_SXP,
  M_WPM,
  M_FALSE,
  M_PMX,
  M_AIC,
  M_RxODE,
  M_SEXP,
  M_TRUE,
  M_DRAFT,
  M_CRAN,
  M_BIC,
  M_NULL,
  M_INTEGER,
  M_GMAIL,
  M_PIPE,
  M_ASGN,
};

enum tap_dance_codes {
  D_Q,
  D_V,
  D_K,
  D_J,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;


td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void v_finished(qk_tap_dance_state_t *state, void *user_data);
void v_reset(qk_tap_dance_state_t *state, void *user_data);

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

qk_tap_dance_action_t tap_dance_actions[] = {
  [D_Q] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LGUI(KC_L)),
  [D_V] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_finished, v_reset),
  [D_K] = ACTION_TAP_DANCE_DOUBLE(KC_K, KC_APPLICATION),
  [D_J] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_LGUI),
};


#define LT_SPC  LT(_MOVE,      KC_SPACE)
#define LT_TAB    LT(_MOUSE,     KC_TAB)
#define LT_ESC LT(_MEDIA,     KC_ESCAPE)
#define LT_BSP LT(_NUM,       KC_BSPACE)
#define LT_RET  LT(_SYM,       KC_ENTER)
#define LT_DEL LT(_FN,        KC_DELETE)
#define LT_F      LT(_MACRO_R2,  KC_F)
#define LT_P      LT(_MACRO_R1,  KC_P)
#define LT_L      LT(_MACRO_L1,  KC_L)
#define LT_U      LT(_MACRO_L2,  KC_U)
#define LT_M      LT(_CA_NUM_L,  KC_M)

#define Q_A  LGUI_T(KC_A)
#define Q_R LALT_T(KC_R)
#define Q_S LCTL_T(KC_S)
#define Q_T LSFT_T(KC_T)
#define Q_N RSFT_T(KC_N)
#define Q_E RCTL_T(KC_E)
#define Q_I RALT_T(KC_I)
#define Q_O RGUI_T(KC_O)
#define Q_QUO KC_QUOTE
#define Q_X RALT_T(KC_X)
#define Q_CMA KC_COMMA
#define Q_DOT LALT_T(KC_DOT)
#define Q_SLASH KC_SLASH


#define MW_UP   KC_MS_WH_UP
#define MW_DOWN KC_MS_WH_DOWN
#define MW_LEFT KC_MS_WH_LEFT
#define MW_RGHT KC_MS_WH_LEFT

#define MS_UP KC_MS_UP
#define MS_DOWN KC_MS_LEFT
#define MS_LEFT KC_MS_LEFT
#define MS_RGHT KC_MS_RIGHT
#define MS_1 KC_MS_BTN1
#define MS_2 KC_MS_BTN2
#define MS_3 KC_MS_BTN3

#define QLSHIFT KC_LSHIFT
#define QRSHIFT KC_RSHIFT
#define QLCTRL KC_LCTRL
#define QLALT  KC_LALT
#define QLGUI KC_LGUI
#define QRALT KC_RALT

#define UNDO KC_PC_UNDO
#define CUT  KC_PC_CUT
#define COPY  KC_PC_COPY
#define PASTE  KC_PC_PASTE
#define REDO LCTL(KC_Y)

#define Q_INS KC_INSERT
#define PG_DOWN KC_PGDOWN
#define Q_RIGHT KC_RIGHT
#define Q_CAPS KC_CAPSLOCK

#define VOL_UP KC_AUDIO_VOL_UP
#define PREV KC_MEDIA_PREV_TRACK
#define VOL_DOWN KC_AUDIO_VOL_DOWN
#define NEXT KC_MEDIA_NEXT_TRACK
#define MUTE KC_AUDIO_MUTE
#define PLAY KC_MEDIA_PLAY_PAUSE
#define STOP KC_MEDIA_STOP

#define LBRACKET KC_LBRACKET
#define RBRACKET KC_RBRACKET

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_matt(
 //,---------------------------------------.                       ,---------------------------------------.
    TD(D_Q),   KC_W,   LT_F,   LT_P,   KC_G,                        TD(D_J),   LT_L,   LT_U,   KC_Y,  Q_QUO,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
        Q_A,    Q_R,    Q_S,    Q_T,   KC_D,                           KC_H,    Q_N,    Q_E,    Q_I,    Q_O,
 //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_Z,    Q_X,   KC_C,TD(D_V),   KC_B,                        TD(D_K),   LT_M,  Q_CMA,  Q_DOT,Q_SLASH,
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
       UNDO,    CUT,   COPY,  PASTE,   REDO,                         KC_NO,  KMOUSE,  KC_NO,  QRALT,  KC_NO,
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
       UNDO,    CUT,   COPY,  PASTE,   REDO,                          KC_NO,  KMOVE,  KC_NO,  QRALT,  KC_NO,
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
 //,---------------------------------------.                       ,---------------------------------------
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
 //,---------------------------------------.                       ,---------------------------------------
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
 //,---------------------------------------.                       ,---------------------------------------
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
  //,---------------------------------------.                       ,---------------------------------------
       RESET,  KC_NO, KC_NO,   KC_NO,  KC_NO,                          CTL_6,  CTL_7,  CTL_8,  CTL_9,  CTL_0,
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      QLGUI, QLSHIFT,QLSHIFT,QLSHIFT,  KC_NO,                          ALT_6,  ALT_7,  ALT_8,  ALT_9,  ALT_0,     
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                         ACTL_6, ACTL_7, ACTL_8, ACTL_9, ACTL_0,           
  //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                              KC_NO,  KC_NO,  KC_NO,           APPS,   APPS,   APPS
  //                        |-------+-------+-------|       |-------+-------+-------|
  ),
[_CA_NUM_L] = LAYOUT_matt(
  //,---------------------------------------.                       ,---------------------------------------
       CTL_1,  CTL_2,  CTL_3,  CTL_4,  CTL_5,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       ALT_1,  ALT_2,  ALT_3,  ALT_4,  ALT_5,                          KC_NO,QLSHIFT,QRSHIFT,QRSHIFT,  QLGUI,        
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
      ACTL_1, ACTL_2, ACTL_3, ACTL_4, ACTL_5,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+--------|
                               APPS,   APPS,   APPS,          KC_NO,  KC_NO,  KC_NO
  //                        |-------+-------+-------|       |-------+-------+-------|
  ),
[_MACRO_R2] = LAYOUT_matt(
  //,---------------------------------------.                       ,---------------------------------------
       RESET,  KC_NO,  KC_NO, KC_NO,   KC_NO,                          KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_NO,          
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,   M_NA,  KC_NO,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  M_NVS,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+--------|
                              KC_NO, KC_NO,  KC_NO,          M_LARW,  KC_NO,  KC_NO
  //                        |-------+-------+-------|       |-------+-------+-------|
  ),

[_MACRO_L2] = LAYOUT_matt(
  //,---------------------------------------.                       ,---------------------------------------
       KC_NO,  KC_NO,  KC_NO, M_PRO,   KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_NO, M_REAL,  M_SXP,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------|                       |-------+-------+-------+-------+-------|
       KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,                          KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,          
  //|-------+-------+-------+-------+-------+-------|       |-------+-------+-------+-------+-------+-------|
                               KC_NO,  KC_NO,  KC_NO,          KC_NO,  KC_NO,  KC_NO
  //                        |-------+-------+-------|       |-------+-------+-------|
  ),
[_MACRO_L1] = LAYOUT_planck_grid(
    KC_NO,          M_WPM,     M_FALSE,     M_PMX,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          
    M_AIC,     M_RxODE,    M_SEXP,    M_TRUE,    M_DRAFT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          M_CRAN,    KC_NO,          M_BIC,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),
[_MACRO_R1] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          M_NULL,    KC_NO,          M_INTEGER,    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          M_GMAIL,    M_PIPE,    KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          M_ASGN,    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  )
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _KC_NO, _ADJUST); */
/* } */

#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case HM_T:
  case HM_N:
    return TAPPING_TERM;
  default:
    return TAPPING_TERM + 30;
  }
}

bool isMouse = false;
bool isMove = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KMOUSE:
    if (record->event.pressed) {
      if (isMouse) {
        set_single_persistent_default_layer(_COLEMAK);
        isMouse = false;
        isMove = false;
      } else {
        set_single_persistent_default_layer(_MOUSE);
        isMouse = true;
        isMove = false;
      }
    }
    return false;
    break;
  case KMOVE:
    if (record->event.pressed) {
      if (isMove) {
        set_single_persistent_default_layer(_COLEMAK);
        isMouse = false;
        isMove = false;
      } else {
        set_single_persistent_default_layer(_MOVE);
        isMouse = false;
        isMove = true;
      }
    }
    return false;
    break;
  case M_NA:
    if (record->event.pressed) {
      SEND_STRING("NA");
    }
    break;
  case M_NVS:
    if (record->event.pressed) {
      SEND_STRING("matt.fidler@novartis.com");

    }
    break;
  case M_LARW:
    if (record->event.pressed) {
      SEND_STRING("->");

    }
    break;
  case M_PRO:
    if (record->event.pressed) {
      SEND_STRING("PROTECT");

    }
    break;
  case M_REAL:
    if (record->event.pressed) {
      SEND_STRING("REAL");

    }
    break;
  case M_SXP:
    if (record->event.pressed) {
      SEND_STRING("SXP");

    }
    break;
  case M_WPM:
    if (record->event.pressed) {
      SEND_STRING("WPM");

    }
    break;
  case M_FALSE:
    if (record->event.pressed) {
      SEND_STRING("FALSE");

    }
    break;
  case M_PMX:
    if (record->event.pressed) {
      SEND_STRING("PMX");

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
  case M_SEXP:
    if (record->event.pressed) {
      SEND_STRING("SEXP");
    }
    break;
  case M_TRUE:
    if (record->event.pressed) {
      SEND_STRING("TRUE");

    }
    break;
  case M_DRAFT:
    if (record->event.pressed) {
      SEND_STRING("DRAFT");

    }
    break;
  case M_CRAN:
    if (record->event.pressed) {
      SEND_STRING("CRAN");

    }
    break;
  case M_BIC:
    if (record->event.pressed) {
      SEND_STRING("BIC");

    }
    break;
  case M_NULL:
    if (record->event.pressed) {
      SEND_STRING("NULL");

    }
    break;
  case M_INTEGER:
    if (record->event.pressed) {
      SEND_STRING("INTEGER");

    }
    break;
  case M_GMAIL:
    if (record->event.pressed) {
      SEND_STRING("matthew.fidler@gmail.com");

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
    break;
    
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
      tap_code(KC_PGDN);
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
    /* case KC_NO: */
    /* case LOWER: */
    /*   return false; */
    default:
      return true;
  }
}



/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'v' tap dance.
static td_tap_t vtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void v_finished(qk_tap_dance_state_t *state, void *user_data) {
    vtap_state.state = cur_dance(state);
    switch (vtap_state.state) {
    case TD_SINGLE_TAP: register_code(KC_V); break;
    case TD_SINGLE_HOLD: layer_on(_CA_NUM_R); break;
    case TD_DOUBLE_TAP: register_code16(LALT(KC_F4)); break;
    case TD_DOUBLE_HOLD: register_code(KC_V); break;
    case TD_DOUBLE_SINGLE_TAP: tap_code(KC_V); register_code(KC_V);
    default: break;
    }
}

void v_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (vtap_state.state) {
    case TD_SINGLE_TAP: unregister_code(KC_V); break;
    case TD_SINGLE_HOLD: layer_off(_CA_NUM_R); break;
    case TD_DOUBLE_TAP: unregister_code16(LALT(KC_F4)); break;
    case TD_DOUBLE_HOLD: unregister_code(KC_V);
    case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_V);
    default: break;
    }
   vtap_state.state = TD_NONE;
}
