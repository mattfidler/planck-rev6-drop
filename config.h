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

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

#undef TAPPING_TERM
#define TAPPING_TERM 180
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD
#define USB_SUSPEND_WAKEUP_DELAY 0
#define TAPPING_TERM_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT

#define USB_MAX_POWER_CONSUMPTION USB_CONFIG_POWER_MA(100)

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED          7
#define MOUSEKEY_WHEEL_DELAY        400
#define MOUSEKEY_WHEEL_INTERVAL     MOUSEKEY_INTERVAL
#define MOUSEKEY_WHEEL_MAX_SPEED    MOUSEKEY_MAX_SPEED
#define MOUSEKEY_WHEEL_TIME_TO_MAX  MOUSEKEY_TIME_TO_MAX
#define TAPPING_TOGGLE  1

#define USE_MUSE

#define LAYOUT_matt( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
                     K30,   K31,   K32,   K33,   K34,   K35 \
) \
LAYOUT_planck_grid( \
  K00,   K01,   K02, K03, K04,  KC_NO, KC_NO, K05, K06, K07, K08,   K09, \
  K10,   K11,   K12, K13, K14,  KC_NO, KC_NO, K15, K16, K17, K18,   K19, \
  K20,   K21,   K22, K23, K24,  KC_NO, KC_NO, K25, K26, K27, K28,   K29, \
  KC_NO, KC_NO, K30, K31, K32,  KC_NO, KC_NO, K33, K34, K35, KC_NO, KC_NO \
)
