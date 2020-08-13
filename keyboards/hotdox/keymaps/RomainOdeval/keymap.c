#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  BASE = 0,
  SYMB = 1,
  MDIA = 2,
};

enum unicode_names {
  E_AIG,
  E_AIG_MAJ,
  E_GRV,
  E_GRV_MAJ,
  E_CIRC,
  E_CIRC_MAJ,
  E_TREMA,
  E_TREMA_MAJ,
  A_CIRC,
  A_CIRC_MAJ,
  A_GRV,
  A_GRV_MAJ,
  C_CEDILLA,
  C_CEDILLA_MAJ,
  O_CIRC,
  O_CIRC_MAJ,
  U_GRAV,
  U_GRAV_MAJ,
  OE,
  OE_MAJ,
  COMMA,
  SEMICOLON,
  DOT,
  COLON,
  APOSTROPHE,
  QUOTATIONMARK,
  DEGREE,
  SQUARE,
  CUBE,
  EURO,
  COPYRIGHT,
  REGISTERED,
  INFEQ,
  SUPEQ,
  GUILL_L,
  GUILL_R,
  UNEQUAL,
  PRETTYMUCH,
  INFINIT,
};

const uint32_t PROGMEM unicode_map[] = {
  [E_AIG]  = 0x00E9,  // 0 é
  [E_AIG_MAJ] = 0x00C9,  // 1 É
  [E_GRV]  = 0x00E8,  // 2 è
  [E_GRV_MAJ] = 0x00C8,  // 3 È
  [E_CIRC]  = 0x00EA,  // 4 ê
  [E_CIRC_MAJ] = 0x00CA,  // 5 Ê
  [E_TREMA]  = 0x00EB,  // 6 ë
  [E_TREMA_MAJ] = 0x00CB,  // 7 Ë
  [A_CIRC]  = 0x00E2,  // 8 â
  [A_CIRC_MAJ] = 0x00C2,  // 9 Ê
  [A_GRV]  = 0x00E0,  // 10 Â
  [A_GRV_MAJ] = 0x00C0,  // 11 À
  [C_CEDILLA]  = 0x00E7,  // 12 ç
  [C_CEDILLA_MAJ] = 0x00C7,  // 13 Ç
  [O_CIRC]  = 0x00F4,  // 14 ô
  [O_CIRC_MAJ] = 0x00D4,  // 15 Ô
  [U_GRAV]  = 0x00F9,  // 16 ù
  [U_GRAV_MAJ] = 0x00D9,  // 17 Ù
  [OE]  = 0x0153,  // 18 œ
  [OE_MAJ] = 0x0152,  // 19 Œ
  [COMMA] = 0x002C, // 20 ,
  [SEMICOLON] = 0x003B, // 21 ;
  [DOT] = 0x002E, // 22 .
  [COLON] = 0x003A, // 23 :
  [APOSTROPHE] = 0x0027, // 24 '
  [QUOTATIONMARK] = 0x0022, // 25 "
  [DEGREE] = 0x00B0, // 26 °
  [SQUARE]  = 0x00B2,  // 27 ²
  [CUBE] = 0x00B3,  // 28 ³
  [EURO]  = 0x20AC,  // 29 €
  [COPYRIGHT]  = 0x00A9,  // 30 ©
  [REGISTERED] = 0x00AE,  // 31 ®
  [INFEQ]  = 0x2264,  // 32 ≤
  [SUPEQ] = 0x2265,  // 33 ≥
  [GUILL_L]  = 0x00AB,  // 34 «
  [GUILL_R] = 0x00BB,  // 35 »
  [UNEQUAL]  = 0x2260,  // 36 ≠
  [PRETTYMUCH] = 0x2248,  // 37 ≈
  [INFINIT] = 0x221E,  // 38 ∞
};

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  1!  |  2#  |  3€  |  4$  |  5%  | Light|           |Sleep |  6à  |  7é  |  8è  |  9ç  |  0ù  |   \|   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |  {[  |           |  }]  |   Y  |   U  |   I  |   O  |   P  |   =+   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Caps  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ¨ ^  |   -_   |
 * |--------+------+------+------+------+------|  (&  |           |  )@  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,;  |  .:  |  Up  |   /?   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  | LCtrl | L OS |AltShf| LAlt |  <>  |                                       | ' "  | RAlt | Left | Down | Right |
 *  `-----------------------------------'                                       `-----------------------------------'
 *                                       ,--------------.       ,-------------.
 *                                       | BkSpa | Del  |       | Home |  End  |
 *                               ,-------|-------|------|       |------+-------+-------.
 *                               |       |       | PrSc |       | PgUp |       |       |
 *                               | Space | Layer |------|       |------| Layer | Enter |
 *                               |       |   1   | Ins  |       | PgDn |   2   |       |
 *                               `----------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,    KC_1,    KC_2,    KC_3,     KC_4,    KC_5,   BL_TOGG,
        KC_TAB,    KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,   KC_LBRC,
        KC_CAPS,   KC_A,    KC_S,    KC_D,     KC_F,    KC_G,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,   KC_LPRN,
        KC_LCTL,   KC_LGUI, KC_APP,  KC_LALT,  KC_LABK,
                                               KC_BSPC,         KC_DEL,
                                                                KC_PSCR,
                                               KC_SPC,  MO(1),  KC_INS,
        // right hand
        KC_SLEP,   KC_6,    KC_7,                         KC_8,                KC_9,          KC_0,    KC_BSLS,
        KC_RBRC,   KC_Y,    KC_U,                         KC_I,                KC_O,          KC_P,    KC_EQL,
                   KC_H,    KC_J,                         KC_K,                KC_L,          KC_NO,   KC_MINS,
        KC_RPRN,   KC_N,    KC_M,                         XP(COMMA,SEMICOLON), XP(DOT,COLON), KC_UP,   KC_SLSH,
                            XP(APOSTROPHE,QUOTATIONMARK), KC_RALT,             KC_LEFT,       KC_DOWN, KC_RGHT,
        KC_HOME,            KC_END,
        KC_PGUP,
        KC_PGDN,   MO(2),   KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EEP_RST  |      |      |      |      |                                    |      |    . |   0  |   =  |      |
 *   `--------------------------------------'                                    `----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         |Animat|      |       |Toggle|Solid |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                  |ness- |ness+ |------|       |------|      |      |
 *                                  |      |      |      |       |      |      |      |
 *                                  `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       EEP_RST,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
