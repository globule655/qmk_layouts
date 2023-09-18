#include QMK_KEYBOARD_H


enum layer_names {
  BASE,
  NAV,
  SYMB,
  CONF,
  NUM,
  FUNC,
  EMPTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x6_3(
      
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G,                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
      KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                    KC_LGUI, MO(NAV), KC_ENT,                       KC_SPC, MO(SYMB), KC_RALT    ),


  [NAV] = LAYOUT_split_3x6_3(
      
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                       KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_HOME, KC_PGDN, KC_UP, KC_PGUP, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_END, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, XXXXXXX,
                    _______, _______, _______,                    _______, MO(CONF), _______),


  [SYMB] = LAYOUT_split_3x6_3(
      
      _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                    _______, MO(CONF), _______,                      _______, _______, _______),


  [CONF] = LAYOUT_split_3x6_3(

      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       TG(BASE), TG(NAV), TG(SYMB), TG(CONF), TG(NUM), TG(FUNC),
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,       TG(EMPTY), TG(7), TG(8), TG(9), TG(10), TG(11),
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,       TG(12), TG(13), TG(14), TG(15), XXXXXXX, XXXXXXX, 
                    _______, _______, _______,                    _______, _______, _______),


  [NUM] = LAYOUT_split_3x6_3(

      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_PERC,        KC_LPRN, KC_KP7, KC_KP8, KC_KP9, KC_PSLS, KC_PMNS, 
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,       KC_RPRN, KC_KP4, KC_KP5, KC_KP6, KC_PAST, KC_PPLS, 
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LT, KC_GT,           KC_KP0, KC_KP1, KC_KP2, KC_KP3, KC_PDOT, KC_PEQL, 
                    _______, MO(BASE), _______,                      _______, _______, _______),


  [FUNC] = LAYOUT_split_3x6_3(

      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC, 
                    _______, _______, _______,                    _______, _______, _______),


  [EMPTY] = LAYOUT_split_3x6_3(

      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, 
                    _______, _______, _______,                    _______, _______, _______)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




