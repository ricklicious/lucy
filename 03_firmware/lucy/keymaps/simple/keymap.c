#include QMK_KEYBOARD_H

// Flash bootloader: avrdude -c avrisp -P /dev/cu.usbmodem123451 -p atmega32u4 -U flash:w:bootloader_atmega32u4_1_0_0.hex:i
 
// Layers
#define _BASE         0
#define _LOWER        1
#define _RAISE        2
#define _FUNCTION     3

// Readability keycodes
#define _______		  KC_TRNS

// Layer codes
  #define LOWER         MO(_LOWER) // Momentary Lower macOS layer
  #define RAISE         MO(_RAISE) // Momenraty raise macOS layer
  #define FN            MO(_FUNCTION) // Momentary Function macOS layer
  #define RSESPC        LT(RAISE, KC_SPC) // Raise on hold, space on tap

// Other
  #define MUTE_ZOOM     LGUI(LSFT(KC_A)) // Mute Zoom
  #define CAM_ZOOM      LGUI(LSFT(KC_V)) // Toggle Zoom camera
  #define LOCK          LGUI(LCTL(KC_Q)) // Lock macOS

// Begin keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base
  .--------------------------------------------------------------------------------------------------------------------------------------------------------------.
  |    Esc    |     Q     |     W     |     E     |     R     |     T     |     Y     |     U     |     I     |     O     |     P     |    BS     |  |   Play    |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |    Tab    |     A     |     S     |     D     |     F     |     G     |     H     |     J     |     K     |     L     |     ;     |     '     |  |   Mute    |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |   Shift   |     Z     |     X     |     C     |     V     |     B     |     N     |     M     |     ,     |     .     |     /     |   Enter   |  | Cam Zoom  |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |    Fn     |   Ctrl    |    Opt    |    Cmd    |   Lower   |     BS    |   Space   | Rse/Space |   Left    |   Down    |     Up    |   Right   |  | Mute Zoom |
  '--------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/ 
  [_BASE] = LAYOUT_ortho_4x12x1(
    KC_ESC,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,        KC_MPLY,
    KC_TAB,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,        KC_MUTE,
    KC_LSFT,   KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_ENT,         MUTE_ZOOM,
    FN,        KC_LCTL,    KC_LALT,    KC_LGUI,    LOWER,      KC_BSPC,    KC_SPC,     RSESPC,     KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,        CAM_ZOOM
  ),

/* Lower
  .--------------------------------------------------------------------------------------------------------------------------------------------------------------.
  |           |    F1     |    F2     |    F3     |    F4     |    F5     |    F6     |    F7     |     F8    |    F9     |    F10    |    Del    |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |   LWL0    |    F11    |    F12    |           |           |           |           |           |           |           |           |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |   Caps    |     _     |     =     |           |           |           |           |           |           |           |           |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |   Reset   |           |           |           |   Lower   |           |           |           |           |           |           |           |  |           |
  '--------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/
  [_LOWER] = LAYOUT_ortho_4x12x1(
    _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_DEL,        _______,
    _______,    KC_F11,     KC_F12,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______,
    KC_CAPS,    KC_UNDS,    KC_EQL,     _______,    _______,    _______,    _______,    _______,    _______,    KC_MINS,    _______,    _______,       _______,
    RESET,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,       _______
  ),

/* Raise
  .--------------------------------------------------------------------------------------------------------------------------------------------------------------.
  |    ` ~    |     1     |     2     |     3     |     4     |     5     |     6     |     7     |     8     |     9     |     0     |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |     !     |     @     |     #     |     $     |     %     |     ^     |     &     |     *     |     (     |     )     |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |     -     |     +     |           |           |           |           |           |     [     |     ]     |    \ |    |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |           |           |           |           |           |           |   Raise   |   Play    |   Vol-    |   Vol+    |   Mute    |  |   Lock    |
  '--------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/
  [_RAISE] = LAYOUT_ortho_4x12x1(
    KC_TILDE,   KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,       _______,
    _______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    _______,       _______,
    _______,    KC_MINS,    KC_PPLS,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_PIPE,    _______,       _______,
    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_VOLD,    KC_VOLU,    KC_MUTE,       LOCK
  )

  /* FN
  .--------------------------------------------------------------------------------------------------------------------------------------------------------------.
  |           |           |           |           |           |           |           |           |           |           |           |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |           |           |           |           |           |           |           |           |           |           |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |           |           |           |           |           |           |           |           |           |           |           |  |           |
  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|  |-----------|
  |           |           |           |           |           |           |           |           |           |           |           |           |  |           |
  '--------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/ 

 /* [_FUNCTION] = LAYOUT_ortho_1x4x12(
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ 
  ) */

}; 

const uint16_t PROGMEM maactions[] = {

};

// Encoder stuff
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch(biton32(layer_state)){
      // Base layers      
        case 0:
          if (clockwise) { // Volume
            tap_code(KC_VOLD);
          } else {
            tap_code(KC_VOLU);
          }
        break;
    }
  }
  return true;
}
// #endif

/* FN2
  .--------------------------------------------------------------------------------------------------------------------------------------------------------------.
  |           |  |           |           |           |           |           |           |           |           |           |           |           |           |
  |-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
  |           |  |           |           |           |           |           |           |           |           |           |           |           |           |
  |-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
  |           |  |           |           |           |           |           |           |           |           |           |           |           |           |
  |-----------|  |-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------|
  |           |  |           |           |           |           |           |           |           |           |           |           |           |           |
  '--------------------------------------------------------------------------------------------------------------------------------------------------------------'
*/ 
/*
  [_FN2] = LAYOUT_ortho_1x4x12(
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,      _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ 
  ) */