#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  BASE = 0,
  SYMB = 1,
  MDIA = 2,
};

enum unicode_names {
  DIGIT_0,
  DIGIT_1,
  DIGIT_2,
  DIGIT_3,
  DIGIT_4,
  DIGIT_5,
  DIGIT_6,
  DIGIT_7,
  DIGIT_8,
  DIGIT_9,
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
  C_CEDIL,
  C_CEDIL_MAJ,
  O_CIRC,
  O_CIRC_MAJ,
  U_GRAV,
  U_GRAV_MAJ,
  OE,
  OE_MAJ,
  DIAER,
  CIRCUMF,
  COMMA,
  SEMICLN,
  DOT,
  COLON,
  EXCLAM,
  APOSTR,
  QUOT,
  PARENTH_L,
  PARENTH_R,
  DEGREE,
  SQUARE,
  CUBE,
  DOLLAR,
  EURO,
  AT,
  HASH,
  AND,
  PERCENT,
  COPYR,
  REGIST,
  INFEQ,
  SUPEQ,
  GUILL_L,
  GUILL_R,
  UNEQUAL,
  PRETTYMUCH,
  INFINIT,
};

const uint32_t PROGMEM unicode_map[] = {
  [DIGIT_0] = 0x0030, // 0 0
  [DIGIT_1] = 0x0031, // 1 1
  [DIGIT_2] = 0x0032, // 2 2
  [DIGIT_3] = 0x0033, // 3 3
  [DIGIT_4] = 0x0034, // 4 4
  [DIGIT_5] = 0x0035, // 5 5
  [DIGIT_6] = 0x0036, // 6 6
  [DIGIT_7] = 0x0037, // 7 7
  [DIGIT_8] = 0x0038, // 8 8
  [DIGIT_9] = 0x0039, // 9 9
  [E_AIG] = 0x00E9,  // 10 é
  [E_AIG_MAJ] = 0x00C9,  // 11 É
  [E_GRV]  = 0x00E8,  // 12 è
  [E_GRV_MAJ] = 0x00C8,  // 13 È
  [E_CIRC]  = 0x00EA,  // 14 ê
  [E_CIRC_MAJ] = 0x00CA,  // 15 Ê
  [E_TREMA]  = 0x00EB,  // 16 ë
  [E_TREMA_MAJ] = 0x00CB,  // 17 Ë
  [A_CIRC]  = 0x00E2,  // 18 â
  [A_CIRC_MAJ] = 0x00C2,  // 19 Ê
  [A_GRV]  = 0x00E0,  // 20 à
  [A_GRV_MAJ] = 0x00C0,  // 21 À
  [C_CEDIL]  = 0x00E7,  // 22 ç
  [C_CEDIL_MAJ] = 0x00C7,  // 23 Ç
  [O_CIRC]  = 0x00F4,  // 24 ô
  [O_CIRC_MAJ] = 0x00D4,  // 25 Ô
  [U_GRAV]  = 0x00F9,  // 26 ù
  [U_GRAV_MAJ] = 0x00D9,  // 27 Ù
  [OE]  = 0x0153,  // 28 œ
  [OE_MAJ] = 0x0152,  // 29 Œ
  [DIAER] = 0x00A8, // 30 ¨
  [CIRCUMF] = 0x005E, // 31 ^
  [COMMA] = 0x002C, // 32 ,
  [SEMICLN] = 0x003B, // 33 ;
  [DOT] = 0x002E, // 34 .
  [COLON] = 0x003A, // 35 :
  [EXCLAM] = 0x0021, // 36 !
  [APOSTR] = 0x0027, // 37 '
  [QUOT] = 0x0022, // 38 "
  [PARENTH_L] = 0x0028, // 39 (
  [PARENTH_R] = 0x0029, // 40 )
  [DEGREE] = 0x00B0, // 41 °
  [SQUARE]  = 0x00B2,  // 42 ²
  [CUBE] = 0x00B3,  // 43 ³
  [DOLLAR] = 0x0024, // 44 $
  [EURO]  = 0x20AC,  // 45 €
  [AT] = 0x0040, // 46 @
  [HASH] = 0x0023, // 47 #
  [AND] = 0x0026, // 48 &
  [PERCENT] = 0x0025, // 49 %
  [COPYR]  = 0x00A9,  // 50 ©
  [REGIST] = 0x00AE,  // 51 ®
  [INFEQ]  = 0x2264,  // 51 ≤
  [SUPEQ] = 0x2265,  // 52 ≥
  [GUILL_L]  = 0x00AB,  // 53 «
  [GUILL_R] = 0x00BB,  // 54 »
  [UNEQUAL]  = 0x2260,  // 55 ≠
  [PRETTYMUCH] = 0x2248,  // 56 ≈
  [INFINIT] = 0x221E,  // 57 ∞
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
        KC_ESC,  XP(DIGIT_1,EXCLAM), XP(DIGIT_2,HASH),  XP(DIGIT_3,EURO), XP(DIGIT_4,DOLLAR), XP(DIGIT_5,PERCENT), BL_TOGG,
        KC_TAB,  KC_Q,               KC_W,              KC_E,             KC_R,               KC_T,                KC_LBRC,
        KC_CAPS, KC_A,               KC_S,              KC_D,             KC_F,               KC_G,
        KC_LSFT, KC_Z,               KC_X,              KC_C,             KC_V,               KC_B,                XP(PARENTH_L,AND),
        KC_LCTL, KC_LGUI,            KC_APP,            KC_LALT,          KC_LABK,
                                                                                              KC_BSPC,             KC_DEL,
                                                                                                                   KC_PSCR,
                                                                          KC_SPC,             MO(1),               KC_INS,
        // right hand
        KC_SLEP,          XP(DIGIT_6,A_GRV), XP(DIGIT_7,E_AIG), XP(DIGIT_8,E_GRV), XP(DIGIT_9,C_CEDIL),    XP(DIGIT_0,U_GRAV), KC_BSLS,
        KC_RBRC,          KC_Y,              KC_U,              KC_I,              KC_O,          KC_P,    KC_EQL,
                          KC_H,              KC_J,              KC_K,              KC_L,          KC_NO,   KC_MINS,
        XP(PARENTH_R,AT), KC_N,              KC_M,              XP(COMMA,SEMICLN), XP(DOT,COLON), KC_UP,   KC_SLSH,
                                             XP(APOSTR,QUOT),   KC_RALT,           KC_LEFT,       KC_DOWN, KC_RGHT,
        KC_HOME,                             KC_END,
        KC_PGUP,
        KC_PGDN,          MO(2),   KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * | Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   °  |   ²  |   ³  |   ©  |   ®  |      |           |      |  Up  |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ≤  |   ≥  |   ≠  |   ≈  |   ∞  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  œ Œ |   «  |   »  |   `  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |EEP_RST |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *  `------------------------------------'                                       `----------------------------------'
 *                                        ,--------------.        ,-------------.
 *                                        |Animat|       |        |Toggle |Solid |
 *                                 ,------|------|-------|        |-------+------+------.
 *                                 |      |      |Bright-|        | Hue-  |      |      |
 *                                 |      |      |-------|        |-------|      |      |
 *                                 |      |      |Bright+|        | Hue+  |      |      |
 *                                 `---------------------'        `---------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,    KC_F1,         KC_F2,       KC_F3,      KC_F4,         KC_F5,     KC_TRNS,
       KC_TRNS, X(DEGREE),     X(SQUARE),   X(CUBE),    X(COPYR),      X(REGIST), KC_TRNS,
       KC_TRNS, X(INFEQ),      X(SUPEQ),    X(UNEQUAL), X(PRETTYMUCH), X(INFINIT),
       KC_TRNS, XP(OE,OE_MAJ), X(GUILL_L),  X(GUILL_R), KC_GRV,        KC_TILD,   KC_TRNS,
       EEP_RST, KC_TRNS,       KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                       RGB_MOD,   KC_TRNS,
                                                                                  RGB_VAD,
                                                        KC_TRNS,       KC_TRNS,   RGB_VAI,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       RGB_HUD,
       RGB_HUI, KC_TRNS, KC_TRNS
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
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
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
