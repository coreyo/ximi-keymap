#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _QWERTY,
    _NUMSYM,
    _MEDNAV,
    _NUMPAD,
    _GAMING,
    _AUTOMOUSE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,                        KC_J,                 KC_L,                 KC_U,         KC_Y,         KC_QUOT,      KC_MINUS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,                        KC_M,                 RSFT_T(KC_N),         RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_SCLN,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,                        KC_K,                 KC_H,                 KC_COMM,      KC_DOT,       KC_SLSH,      KC_RSFT,
  KC_MUTE,                                  KC_ENT,       KC_ESC,       LT(_NUMSYM, KC_BSPC),        LT(_MEDNAV, KC_SPC),  LT(_NUMPAD, KC_TAB),  KC_DEL,                                   KC_MUTE,
                                            C(KC_Z),     C(S(KC_Z)),   C(KC_Y),                     KC_VOLD,              KC_MUTE,              KC_VOLU
),

/* Qwerty
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|  Del |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                        KC_Y,                 KC_U,                 KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,                        KC_H,                 RSFT_T(KC_J),         RALT_T(KC_K), RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                        KC_N,                 KC_M,                 KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
  KC_MUTE,                                  KC_ENT,       KC_ESC,       LT(_NUMSYM, KC_BSPC),        LT(_MEDNAV, KC_SPC),  LT(_NUMPAD, KC_TAB),  KC_DEL,                                      KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),                     KC_VOLD,              KC_MUTE,              KC_VOLU
),

/* Numbers/Symbols
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |   |      |  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |   \  |   :  |   ;  |   {  |  [   |             |   ]  |   }  |   =  |   +  |  -   |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */

[_NUMSYM] = LAYOUT_ximi(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_BSLS, KC_COLN, KC_SCLN, KC_LCBR, KC_LBRC,      KC_RBRC, KC_RCBR, KC_EQL,  KC_PLUS, KC_MINS, _______,
  _______,                   _______, _______, _______,      _______, _______, _______,                   _______,
                             _______, _______, _______,      _______, _______, _______
),

/* Media/Navigation
 *
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  | F10  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      | PGUP | PSCR |      |      | F11  |   |      |  |      | LEFT | DOWN |  UP  | RGHT |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      | PGDN | SCRL |      |      | F12  |             |      | MLFT | MDWN |  MUP | MRGT |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_MEDNAV] = LAYOUT_ximi(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  _______, KC_PGUP, KC_PSCR, _______, _______, KC_F11,       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
  _______, KC_PGDN, KC_SCRL, _______, _______, KC_F12,       _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______,                   _______, _______, _______,      _______, _______, _______,                   _______,
                             _______, _______, _______,      _______, _______, _______
),


/* 10Key/Numpad 
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |   *  | NUM7 | NUM8 | NUM9 |   -  |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |  |   /  | NUM4 | NUM5 | NUM6 |   +  |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             | NUM0 | NUM1 | NUM2 | NUM3 |   .  | ENTR |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_NUMPAD] =  LAYOUT_ximi(
  _______,      _______, FP_ACCEL_TOG, FP_SCROLL_DPI_UP, FP_POINT_DPI_UP, TO(_COLEMAK),         KC_PAST, KC_P7,   KC_P8,   KC_P9,  KC_PMNS, KC_BSPC,
  TO(_COLEMAK), _______, _______, FP_SCROLL_DPI_DN, FP_POINT_DPI_DN, TO(_GAMING),          KC_PSLS, KC_P4,   KC_P5,   KC_P6,  KC_PPLS, KC_PEQL,
  TO(_QWERTY),  _______, _______, FP_SCROLL_DPI_RESET, FP_POINT_DPI_RESET, TO(_NUMPAD),          KC_P0,   KC_P1,   KC_P2,   KC_P3,  KC_PDOT, KC_PENT,
  _______,                        _______, _______, _______,              _______, _______, _______,                  KC_NUM,
                                  _______, _______, _______,              _______, _______, _______
),


/* Gaming
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          |      |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        |      |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_GAMING] =  LAYOUT_ximi(
  KC_TAB,  KC_Y, KC_Q, KC_W,    KC_E,    KC_R,      _______, _______, _______, _______, _______, _______,
  KC_LSFT, KC_G, KC_A, KC_S,    KC_D,    KC_F,      _______, _______, _______, _______, _______, _______,
  KC_LCTL, KC_Z, KC_X, KC_C,    KC_V,    KC_B,      _______, _______, _______, _______, _______, _______,
  LCTL(KC_TAB),        KC_LALT, KC_ESC,  KC_SPC,    _______, _______, TO(_COLEMAK),              _______,
                       _______, _______, _______,   _______, _______, _______

),

/* Auto Mouse
 * ,-----------------------------------------.             ,-----------------------------------------.
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   ,------.  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |   |      |  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|   `------'  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |             |      |      |      |      |      |      |
 * `-----------------------------------------'             `-----------------------------------------'
 *          ,------.        ,--------------------.    ,--------------------.        ,------.
 *          | MUTE |        |   \  | Enter| LOWER|    | RAISE| Space| Del  |        | DELW |
 *          `------'        `--------------------'    `--------------------.        `------'
 */
[_AUTOMOUSE] =  LAYOUT_ximi(
  _______, _______, _______,         _______,         _______, _______,      _______, _______, _______,         _______,         _______, _______,
  _______, _______, LGUI_T(KC_BTN2), LALT_T(KC_BTN3), KC_BTN1, _______,      _______, KC_BTN1, RALT_T(KC_BTN3), RGUI_T(KC_BTN2), _______, _______,
  _______, _______, _______,         _______,         _______, _______,      _______, _______, _______,         _______,         _______, _______,
  KC_BTN1,                           KC_BTN2,         KC_BTN3, KC_BTN1,      KC_BTN2, _______, _______,                                   _______,
                                     _______,         _______, _______,      _______, _______, _______

),

};


/* BEGIN COMBO DEFINITIONS */
enum combos { 
  W_F_TILDE,
  Y_QUOTE_MINUS,
  Q_W_GRAVE,
  F_J_PIPE,
  I_O_SEMICOLON,
  T_N_CAPSWORD_TOGGLE,
  LEFT_ESC_B_BOOTLOADER,
  RIGHT_J_MINUS_BOOTLOADER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM w_f_tilde[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM y_quote_minus[] = {KC_Y, KC_QUOT, COMBO_END};
const uint16_t PROGMEM q_w_grave[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM f_j_pipe[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM i_o_semicolon[] = {RGUI_T(KC_I), RCTL_T(KC_O), COMBO_END};
const uint16_t PROGMEM t_n_capsword_toggle[] = {LSFT_T(KC_T), RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM esc_b_bootloader[] = {KC_ESC, KC_B, COMBO_END};
const uint16_t PROGMEM j_minus_bootloader[] = {KC_J, KC_MINUS, COMBO_END};

combo_t key_combos[] = {
  [W_F_TILDE] = COMBO(w_f_tilde, KC_TILDE),
  [Y_QUOTE_MINUS] = COMBO(y_quote_minus, KC_MINUS),
  [Q_W_GRAVE] = COMBO(q_w_grave, KC_GRAVE),
  [F_J_PIPE] = COMBO(f_j_pipe, KC_PIPE),
  [I_O_SEMICOLON] = COMBO(i_o_semicolon, KC_SCLN),
  [T_N_CAPSWORD_TOGGLE] = COMBO(t_n_capsword_toggle, CW_TOGG),
  [LEFT_ESC_B_BOOTLOADER] = COMBO(esc_b_bootloader, QK_BOOT),
  [RIGHT_J_MINUS_BOOTLOADER] = COMBO(j_minus_bootloader, QK_BOOT)
};

/* restrict combos to specific layers */
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo_index) {
	    case W_F_TILDE:
	    case Y_QUOTE_MINUS:
	    case Q_W_GRAVE:
	    case F_J_PIPE:
	    case I_O_SEMICOLON:
	    case T_N_CAPSWORD_TOGGLE:
	    case LEFT_ESC_B_BOOTLOADER:
	    case RIGHT_J_MINUS_BOOTLOADER:
                if (layer_state_is(_COLEMAK)) {
                    return true;
                }
    }
    return false;
}
/* END COMBO DEFINITIONS */


/* STARTUP TASKS */

/* initialize numlock */
void matrix_init_user (void) {
  if (!(host_keyboard_leds() & (1 << USB_LED_NUM_LOCK))) {
      register_code(KC_NUM_LOCK);
      unregister_code(KC_NUM_LOCK);
  }
}
