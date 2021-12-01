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

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#include "config-user.h"

#ifdef PLANCK
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

#endif

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

#ifdef PLANCK
#define USE_MUSE

#define LAYOUT_matt( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
                     K30,   K31,   K32,   K33,   K34,   K35 \
) \
LAYOUT_planck_grid( \
  K00,   K01,   K02,   K03, K04,  KC_NO, KC_NO, K05, K06, K07,     K08,   K09, \
  K10,   K11,   K12,   K13, K14,  KC_NO, KC_NO, K15, K16, K17,     K18,   K19, \
  K20,   K21,   K22,   K23, K24,  KC_NO, KC_NO, K25, K26, K27,     K28,   K29, \
  KC_NO, KC_NO, KC_NO, K30, K31,    K32,   K33, K34, K35, KC_NO, KC_NO, KC_NO      \
) 
#endif

#ifdef CRKBD

#ifdef RGB_MATRIX_ENABLE
#   define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#   define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash. 
#    define RGB_MATRIX_HUE_STEP 8
#    define RGB_MATRIX_SAT_STEP 8
#    define RGB_MATRIX_VAL_STEP 8
#    define RGB_MATRIX_SPD_STEP 10

/* Disable the animations you don't want/need.  You will need to disable a good number of these    *
 * because they take up a lot of space.  Disable until you can successfully compile your firmware. */
//#   define DISABLE_RGB_MATRIX_ALPHAS_MODS
//#   define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#   define DISABLE_RGB_MATRIX_BREATHING
//#   define DISABLE_RGB_MATRIX_CYCLE_ALL
 #   define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
 #   define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
 #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
 #   define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
 #   define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 #   define DISABLE_RGB_MATRIX_DUAL_BEACON
 #   define DISABLE_RGB_MATRIX_RAINBOW_BEACON
 #   define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
 #   define DISABLE_RGB_MATRIX_RAINDROPS
 #   define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
 #   define DISABLE_RGB_MATRIX_TYPING_HEATMAP
 #   define DISABLE_RGB_MATRIX_DIGITAL_RAIN
 #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #   define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
 #   define DISABLE_RGB_MATRIX_SPLASH
 #   define DISABLE_RGB_MATRIX_MULTISPLASH
 #   define DISABLE_RGB_MATRIX_SOLID_SPLASH
 #   define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif // RGB_MATRIX_ENABLE
#define LAYOUT_matt( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
                     K30,   K31,   K32,   K33,   K34,   K35 \
) \
LAYOUT_split_3x5_3( \
  K00,   K01,   K02, K03, K04,  K05, K06, K07, K08,   K09, \
  K10,   K11,   K12, K13, K14,  K15, K16, K17, K18,   K19, \
  K20,   K21,   K22, K23, K24,  K25, K26, K27, K28,   K29, \
  K30, K31, K32,  K33, K34, K35 \
)

#define USE_SERIAL_PD2

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

#endif // CRKBD

#ifdef MOON
r#define LAYOUT_matt( \
       K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09, \
       K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19, \
       K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29, \
                     K30,   K31,   K32,   K33,   K34,   K35 \
) \
  LAYOUT_moonlander( \
        K00,   K01,    K02,    K03,    K04,  KC_NO,    KC_NO,           KC_NO, KC_NO,    K05,  K06,   K07,    K08,     K09, \
        K10,   K11,    K12,    K13,    K14,  KC_NO,    KC_NO,           KC_NO, KC_NO,    K15,  K16,   K17,    K18,     K19, \
        K20,   K21,    K22,    K23,    K24,  KC_NO,    KC_NO,           KC_NO, KC_NO,    K25,  K26,   K27,    K28,     K29, \
        KC_NO, KC_NO,  KC_NO,  K30,    K31,  K32,        kxw                        K33,    K34,  K35,   KC_NO,  KC_NO, KC_NO, \
        KC_NO, KC_NO,  KC_NO,KC_NO,  KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, \
                                             KC_NO, KC_NO,  KC_NO,         KC_NO, KC_NO,  KC_NO )

#define ORYX_CONFIGURATOR
#define USE_MUSE
#endif //MOON
