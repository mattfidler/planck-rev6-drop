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
  _QWERTY,
  _DVORAK,
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
  _MACRO_R1,
  _PLOVER
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  EXT_PLV,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
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


#define LT_SPACE  LT(_MOVE,      KC_SPACE)
#define LT_TAB    LT(_MOUSE,     KC_TAB)
#define LT_ESCAPE LT(_MEDIA,     KC_ESCAPE)
#define LT_BSPACE LT(_NUM,       KC_BSPACE)
#define LT_ENTER  LT(_SYM,       KC_ENTER)
#define LT_F      LT(_MACRO_R2,  KC_F)
#define LT_P      LT(_MACRO_R1,  KC_P)
#define LT_L      LT(_MACRO_L1,  KC_L)
#define LT_U      LT(_MACRO_L2,  KC_U)
#define LT_M      LT(_CA_NUM_L,  KC_M)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak
 * ,---------------------------------------------------------------------.
 * | Q | W |  F  |   P  |   G  |      |      |  J  |  L  |   U |  Y  | ' |
 * |-------+-----+------+------+------+------+-----+-----+-----+-----+---|
 * | A | R |  S  |   T  |   D  |      |      |  H  |  N  |   E |  I  | O |
 * |---+---+-----+------+------+------+------+-----+-----+-----+-----+---|
 * | Z | X |  C  |   V  |   B  |      |      |  N  |  M  |   , |  .  | / |
 * |---+---+-----+------+------+------+------+-----+-----+-----+-----+---|
 * |   |   | Del | Bspc |Enter |    Reset    | Tab | Spc | Esc |     |   |
 * `---------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    TD(D_Q),        KC_W,           LT_F,           LT_P,           KC_G,  KC_NO, KC_NO,   D_J,     LT_L,           LT_U,           KC_Y,           KC_QUOTE,
    LGUI_T(KC_A),   LALT_T(KC_R),   LCTL_T(KC_S),   LSFT_T(KC_T),   KC_D,  KC_NO, KC_NO,   KC_H,    RSFT_T(KC_N),   RCTL_T(KC_E),   RALT_T(KC_I),   RGUI_T(KC_O),
    KC_Z,           RALT_T(KC_X),   KC_C,           TD(D_V),        KC_B,  KC_NO, KC_NO,  TD(D_K),  LT_M,           KC_COMMA,       LALT_T(KC_DOT), KC_SLASH,
    KC_NO,          KC_NO,          KC_DELETE,      LT_BSPACE,    LT_ENTER,RESET, RESET,  LT_TAB,   LT_SPACE,       KC_ESCAPE,      KC_NO,          KC_NO
),


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    TD(D_Q),        KC_W,           KC_E,           KC_R,           KC_T,  KC_NO, KC_NO,   KC_Y,    KC_U,           KC_I,           KC_O,           KC_P,
    LGUI_T(KC_A),   LALT_T(KC_S),   LCTL_T(KC_D),   LSFT_T(KC_F),   KC_G,  KC_NO, KC_NO,   KC_H,    RSFT_T(KC_J),   RCTL_T(KC_K),   RALT_T(KC_L),   RGUI_T(KC_QUOTE),
    KC_Z,           RALT_T(KC_X),   KC_C,           TD(D_V),        KC_B,  KC_NO, KC_NO,   KC_N,    LT_M,           KC_COMMA,       LALT_T(KC_DOT), KC_SLASH,
    KC_NO,          KC_NO,          KC_DELETE,      LT_BSPACE,    LT_ENTER,KC_NO, KC_NO,  LT_TAB,   LT_SPACE,       KC_ESCAPE,      KC_NO,          KC_NO
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_QUOTE,     KC_COMMA,    KC_DOT,       KC_P,         KC_Y,     KC_NO,   KC_NO,   KC_F,         KC_G,          KC_C,         KC_R,   KC_L,
    LGUI_T(KC_A), LALT(KC_O),  LCTL_T(KC_E), LSFT_T(KC_U), KC_I,     KC_NO,   KC_NO,   KC_D,  RSFT_T(KC_H),  RCTL_T(KC_T), RALT_T(KC_N),  RGUI_T(KC_S),
    KC_SLASH,     KC_Q,        KC_J,         KC_K,         KC_X,     KC_NO,   KC_NO,   KC_B,         KC_M,          KC_W,         KC_V,   KC_Z,
    KC_NO,        KC_NO,       KC_DELETE,    LT_BSPACE,   LT_ENTER, KC_NO,   KC_NO,  LT_TAB,         LT_SPACE,      KC_ESCAPE,    KC_NO,  KC_NO
),
/* Mouse
 * ,------------------------------------------------------------------------------.
 * | WhUp  | <-Wh |  ^   | Wh->  |       |   |   |   |       |      |     | Reset |
 * |-------+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * | WhDwn |  <-  |  v   |   ->  |       |   |   |   | Shift | Ctrl | Alt | Gui   |
 * |-------+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * | Undo  | Cut  | Copy | Paste | Redo  |   |   |   |       |      |     | End   | 
 * |----- -+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * |       |      |  Del |  Bksp | Enter |       |   |XXXXXXX|      |     |       |
 * `------------------------------------------------------------------------------'
 */

[_MOUSE] = LAYOUT_planck_grid(
    KC_MS_WH_UP,    KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_NO,          KC_NO, KC_NO, PLOVER,         DVORAK,         COLEMAK,        QWERTY,    RESET,
    KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO, KC_NO, KC_NO, KC_LSHIFT,  KC_LCTRL, KC_LALT, KC_LGUI,        
    KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    LCTL(KC_Y),     KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,    KC_RALT, KC_NO,          
    KC_NO,          KC_NO,          KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     KC_NO, KC_NO, KC_NO, KC_NO,      KC_NO,    KC_NO,   KC_NO
  ),

/* Move
 * ,------------------------------------------------------------------------------.
 * | PgUp  | Home |  ^   |  End  |  Ins  |   |   |   |       |      |     | Reset |
 * |-------+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * | PgDwn |  <-  |  v   |   ->  | Caps  |   |   |   | Shift | Ctrl | Alt | Gui   |
 * |-------+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * | Undo  | Cut  | Copy | Paste | Redo  |   |   |   |       |      |     | End   | 
 * |----- -+------+------+-------+-------+---+---+---+-------+------+-----+-------|
 * |       |      |  Del |  Bksp | Enter |       |   |       |XXXXXX|     |       |
 * `------------------------------------------------------------------------------'
 */
[_MOVE] = LAYOUT_planck_grid(
    KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_INSERT,      KC_NO, KC_NO, PLOVER,         DVORAK,         COLEMAK,        QWERTY,    RESET, 
    KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_CAPSLOCK,    KC_NO, KC_NO, KC_NO,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,  KC_LGUI,        
    KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    LCTL(KC_Y),     KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_RALT,  KC_NO,          
    KC_NO,          KC_NO,          KC_DELETE,      KC_BSPACE,      KC_ENTER,       KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO,    KC_NO
),
/* Media
 * ,------------------------------------------------------------------------------.
 * | VaIn  | Spd  | VolUp | Spi  |  Ins  |   |   |   |       |      |     | Reset |
 * |-------+------+-------+------+-------+---+---+---+-------+------+-----+-------|
 * | VaDw  | Prev | VolDwn| Next | Caps  |   |   |   | Shift | Ctrl | Alt | Gui   |
 * |-------+------+-------+------+-------+---+---+---+-------+------+-----+-------|
 * | RGB   | MOD  | Hud   | Hui  | MOD   |   |   |   |       |      |     |       | 
 * |----- -+------+-------+------+-------+---+---+---+-------+------+-----+-------|
 * |       |      |  Mute | Play | Stop  |       |   |       |      |XXXXX|       |
 * `------------------------------------------------------------------------------'
 */

[_MEDIA] = LAYOUT_planck_grid(
    RGB_VAI,        RGB_SPD,        KC_AUDIO_VOL_UP,RGB_SPI,        KC_NO,          KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO,    RESET,
    RGB_VAD,        KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_MEDIA_NEXT_TRACK,KC_NO,          KC_NO, KC_NO, KC_NO,          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,
    RGB_TOG,        RGB_MOD,        RGB_HUD,        RGB_HUI,        RGB_MOD,        KC_NO, KC_NO, KC_NO,          KC_NO, KC_NO,          KC_RALT,        KC_NO,          
    KC_NO, KC_NO, KC_AUDIO_MUTE,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_STOP,  KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_NO
  ),
/* Number Layer
 * ,------------------------------------------------------------.
 * | Reset |     |       |      |   |   |   | [ | 7 | 8 | 9 | ] |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |  Gui  | Alt |  Ctrl | Shift|   |   |   | = | 4 | 5 | 6 | ; |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |       |     |       |      |   |   |   | \ | 1 | 2 | 3 | ` |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |       |     |       |XXXXXX|   |       | - | 0 | . |   |   |
 * `------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    RESET,          QWERTY,         COLEMAK,        DVORAK,         PLOVER,         KC_NO, KC_NO, KC_LBRACKET,    KC_7,           KC_8,           KC_9,           KC_RBRACKET,    
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_NO, KC_NO, KC_EQUAL,       KC_4,           KC_5,           KC_6,           KC_SCOLON,      
    KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_BSLASH,      KC_1,           KC_2,           KC_3,           KC_GRAVE,       
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_MINUS,       KC_0,           KC_DOT,         KC_NO,          KC_NO
),
/* Symbol Layer
 * ,------------------------------------------------------------.
 * | Reset |     |       |      |   |   |   | [ | & | * | ( | } |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |  Gui  | Alt |  Ctrl | Shift|   |   |   | = | $ | % | ^ | : |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |       |     |       |      |   |   |   | \ | ! | @ | # | ~ |
 * |-------+-----+-------+------+---+---+---+---+---+---+---+---|
 * |       |     |       |      |XXX|       | _ | ( | ) |   |   |
 * `------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    RESET,          QWERTY,         COLEMAK,        DVORAK,         PLOVER,          KC_NO, KC_NO, KC_LCBR,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RCBR,        
    KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_NO, KC_NO, KC_PLUS,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_COLN,        
    KC_NO,          KC_RALT,        KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_PIPE,        KC_EXLM,        KC_AT,          KC_HASH,        KC_TILD,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_UNDS,        KC_LPRN,        KC_RPRN,        KC_NO,          KC_NO
  ),
/* Function Layer
 * ,----------------------------------------------------------------------.
 * | Reset |     |       |      |   |   |   | PrnScn | f7 | f8 | f9 | f12 |
 * |-------+-----+-------+------+---+---+---+--------+----+----+----+-----|
 * |  Gui  | Alt |  Ctrl | Shift|   |   |   | ScrlLck| f4 | f5 | f6 | f11 |
 * |-------+-----+-------+------+---+---+---+--------+----+----+----+-----|
 * |       |     |       |      |   |   |   | Pause  | f1 | f2 | f3 | f10 |
 * |-------+-----+-------+------+---+---+---+--------+----+----+----+-----|
 * |       |     |       |      |XXX|       | Tab    | Spc|Apps|    |     |
 * `----------------------------------------------------------------------'
 */
[_FN] = LAYOUT_planck_grid(
    RESET,          QWERTY,         COLEMAK,        DVORAK,         PLOVER,    KC_NO, KC_NO, KC_PSCREEN,     KC_F7,          KC_F8,          KC_F9,          KC_F12,         
    KC_LGUI,        KC_LALT,   KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_NO, KC_NO, KC_SCROLLLOCK,  KC_F4,          KC_F5,          KC_F6,          KC_F11,         
    KC_NO,          KC_RALT,   KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_PAUSE,       KC_F1,          KC_F2,          KC_F3,          KC_F10,         
    KC_NO,          KC_NO,     KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_TAB,         KC_SPACE,       KC_APPLICATION, KC_NO, KC_NO
  ),

/*  c+a+num
 * ,----------------------------------------------------------------------.
 * | Reset |     |       |      |   |   |   | C-6 | C-7 | C-8 | C-9 | C-0 |
 * |-------+-----+-------+------+---+---+---+-----+-----+-----+-----+-----|
 * |  Gui  | Alt |  Ctrl | Shift|   |   |   | M-6 | M-7 | M-8 | M-9 | M-0 |
 * |-------+-----+-------+------+---+---+---+-----+-----+-----+-----+-----|
 * |       |     |       |      |   |   |   |  6  |  7  |  8  |  9  |  0  |
 * |-------+-----+-------+------+---+---+---+-----+-----+-----+-----+-----|
 * |       |     |       |      |XXX|       |     |     | Apps|     |     |
 * `----------------------------------------------------------------------'
 */
[_CA_NUM_R] = LAYOUT_planck_grid(
    RESET,          QWERTY,         COLEMAK,        DVORAK,         PLOVER,         KC_NO, KC_NO, LCTL(KC_6),     LCTL(KC_7),     LCTL(KC_8),     LCTL(KC_9),     LCTL(KC_0),     
    KC_LGUI,        KC_LSHIFT,      KC_LSHIFT,      KC_LSHIFT,      KC_NO,          KC_NO, KC_NO, LALT(KC_6),     LALT(KC_7),     LALT(KC_8),     LALT(KC_9),     LALT(KC_0),     
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO, KC_NO, KC_NO,          KC_APPLICATION, KC_NO,          KC_NO,          KC_NO
  ),
[_CA_NUM_L] = LAYOUT_planck_grid(
    LCTL(KC_1),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     LCTL(KC_5),     KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    LALT(KC_1),     LALT(KC_2),     LALT(KC_3),     LALT(KC_4),     LALT(KC_5),     KC_NO, KC_NO, KC_NO,          KC_LSHIFT,      KC_RSHIFT,      KC_RSHIFT,      KC_LGUI,        
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_APPLICATION, KC_NO,          KC_NO, KC_NO, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO
  ),
[_MACRO_L2] = LAYOUT_planck_grid(
    RESET,          QWERTY,         COLEMAK,        DVORAK,         PLOVER,         KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          ST_MACRO_0,     KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          ST_MACRO_1,     KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          ST_MACRO_2,     KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),

[_MACRO_R2] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_NO,          ST_MACRO_3,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          
    KC_NO,          ST_MACRO_4,     ST_MACRO_5,     KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),
[_MACRO_L1] = LAYOUT_planck_grid(
    KC_NO,          ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          
    ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    ST_MACRO_13,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          ST_MACRO_14,    KC_NO,          ST_MACRO_15,    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),
[_MACRO_R1] = LAYOUT_planck_grid(
    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          ST_MACRO_16,    KC_NO,          ST_MACRO_17,    KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          ST_MACRO_18,    ST_MACRO_19,    KC_NO,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, KC_NO,          ST_MACRO_20,    KC_NO,          KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT
  ),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PLOVER] = LAYOUT_planck_grid(
    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX
)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*   return update_tri_layer_state(state, _LOWER, _KC_NO, _ADJUST); */
/* } */

bool inColemak = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      print("mode just switched to qwerty and this is a huge string\n");
      set_single_persistent_default_layer(_QWERTY);
      inColemak=false;
    }
    return false;
    break;
  case COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
      inColemak=true;
    }
    return false;
    break;
  case DVORAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_DVORAK);
      inColemak=false;
    }
    return false;
    break;
  case PLOVER:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      stop_all_notes();
      PLAY_SONG(plover_song);
#endif
      /* layer_off(_KC_NO); */
      /* layer_off(_LOWER); */
      /* layer_off(_ADJUST); */
      layer_on(_PLOVER);
      if (!eeconfig_is_enabled()) {
        eeconfig_init();
      }
      keymap_config.raw = eeconfig_read_keymap();
      keymap_config.nkro = 1;
      eeconfig_update_keymap(keymap_config.raw);
      inColemak=false;
    }
    return false;
    break;
  case EXT_PLV:
    if (record->event.pressed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(plover_gb_song);
#endif
      layer_off(_PLOVER);
    }
    return false;
    break;
  case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_N)) SS_LSFT(SS_TAP(X_A)));

    }
    break;
  case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING("matt.fidler@novartis.com");

    }
    break;
  case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_LSFT(SS_TAP(X_DOT)));

    }
    break;
  case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING("PROTECT");

    }
    break;
  case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_R)) SS_LSFT(SS_TAP(X_E)) SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_L)));

    }
    break;
  case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_S)) SS_LSFT(SS_TAP(X_X)) SS_LSFT(SS_TAP(X_P)));

    }
    break;
  case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_W)) SS_LSFT(SS_TAP(X_P)) SS_LSFT(SS_TAP(X_M)));

    }
    break;
  case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_F)) SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_L)) SS_LSFT(SS_TAP(X_S)) SS_LSFT(SS_TAP(X_E)));

    }
    break;
  case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_P)) SS_LSFT(SS_TAP(X_M)) SS_LSFT(SS_TAP(X_X)));

    }
    break;
  case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_I)) SS_LSFT(SS_TAP(X_C)));

    }
    break;
  case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_R)) SS_TAP(X_X) SS_RSFT(SS_TAP(X_O)) SS_RSFT(SS_TAP(X_D)) SS_RSFT(SS_TAP(X_E)));

    }
    break;
  case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_S)) SS_LSFT(SS_TAP(X_E)) SS_LSFT(SS_TAP(X_X)) SS_LSFT(SS_TAP(X_P)));

    }
    break;
  case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_T)) SS_LSFT(SS_TAP(X_R)) SS_LSFT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_E)));

    }
    break;
  case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_D)) SS_LSFT(SS_TAP(X_R)) SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_F)) SS_LSFT(SS_TAP(X_T)));

    }
    break;
  case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_C)) SS_LSFT(SS_TAP(X_R)) SS_LSFT(SS_TAP(X_A)) SS_LSFT(SS_TAP(X_N)));

    }
    break;
  case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_B) SS_TAP(X_I) SS_TAP(X_C));

    }
    break;
  case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_N)) SS_LSFT(SS_TAP(X_U)) SS_LSFT(SS_TAP(X_L)) SS_LSFT(SS_TAP(X_L)));

    }
    break;
  case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING("INTEGER");

    }
    break;
  case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING("matthew.fidler@gmail.com");

    }
    break;
  case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_5)) SS_LSFT(SS_TAP(X_DOT)) SS_LSFT(SS_TAP(X_5)));
    }
    break;
  case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_TAP(X_MINUS));
    }
    break;
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)

#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RALT_T(KC_I)
#define HM_O RGUI_T(KC_O)
    
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RGUI)) {
	unregister_mods(MOD_BIT(KC_RGUI));
	tap_code(KC_O);
	tap_code(KC_M);
	add_mods(MOD_BIT(KC_RGUI));
	return false;
      } else if (inColemak && get_mods() & MOD_BIT(KC_RCTL)) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
	// handle at 1.49%
	unregister_mods(MOD_BIT(KC_LGUI));
	tap_code(KC_A);
	tap_code(KC_T);
	unregister_mods(MOD_BIT(KC_LGUI));
	return false;
      } else if (inColemak && get_mods() & MOD_BIT(KC_LCTL)) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
    if (inColemak && record->tap.count > 0) {
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
  case LT_SPACE:
    if (inColemak && record->tap.count > 0) {
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

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                /* layer_on(_ADJUST); */
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                /* layer_off(_ADJUST); */
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
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
