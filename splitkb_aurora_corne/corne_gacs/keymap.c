#include QMK_KEYBOARD_H
#include <keymap_french.h>
#include <stdio.h>

// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)

// Right-hand home row mods
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

char wpm_str[10];

enum layer_names {
  _BASE,
  _NAV,
  _SYMB,
  _CONF,
  _NUM,
  _FUNC,
  _GAMING,
  _EMPTY,
};

enum {
  TD_BASE,
  TD_FUNC,
  TD_CAPSLOCK,
};

//Combos
enum combos {
    CMB_RBRC,
    CMB_ACCENTED_E1,
    CMB_ACCENTED_E2,
    CMB_QUOTE,
    CMB_CCEDILLE,
    CMB_ACCENTED_A,
    CMB_DASH,
};

const uint16_t PROGMEM cmb_rbrc[] = {KC_MINS, KC_DELETE, COMBO_END};
const uint16_t PROGMEM cmb_accented_e1[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cmb_accented_e2[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_quote[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_ccedille[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_accented_a[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM cmb_dash[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [CMB_RBRC] = COMBO(cmb_rbrc, KC_EQL),
    [CMB_ACCENTED_E1] = COMBO(cmb_accented_e1, KC_2),
    [CMB_ACCENTED_E2] = COMBO(cmb_accented_e2, KC_7),
    [CMB_QUOTE] = COMBO(cmb_quote, KC_4),
    [CMB_CCEDILLE] = COMBO(cmb_ccedille, KC_9),
    [CMB_ACCENTED_A] = COMBO(cmb_accented_a, KC_0),
    [CMB_DASH] = COMBO(cmb_dash, KC_6),
};

//Layers definition
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(

      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      KC_HOME, GUI_A, ALT_S, CTL_D, SFT_F, KC_G,                  KC_H, SFT_J, CTL_K, ALT_L, GUI_SCLN, KC_QUOT,
      KC_END, KC_Z, KC_X, KC_C, KC_V, KC_B,                       KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TD(TD_FUNC),
                    MO(_NUM), MO(_NAV), KC_ENT,                 KC_SPC, MO(_SYMB), TD(TD_CAPSLOCK)

                    ),


  [_NAV] = LAYOUT_split_3x6_3(

      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                          KC_6, KC_7, KC_8, KC_9, KC_0, KC_DELETE,
      KC_PGUP, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_LBRC, KC_EQL,
      KC_PGDN, XXXXXXX, KC_CUT, KC_COPY, KC_PSTE, LCTL(KC_B),      KC_MINS, KC_EQL, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,
                    _______, _______, _______,                    _______, MO(_CONF), _______

                    ),


  [_SYMB] = LAYOUT_split_3x6_3(

      KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______, _______, _______, _______, _______, XXXXXXX,       FR_MINS, FR_PLUS, FR_CIRC, FR_DLR, FR_ASTR, FR_PIPE,
      _______, FR_LABK, FR_RABK, XXXXXXX, XXXXXXX, XXXXXXX,       FR_LPRN, FR_RPRN, FR_LCBR, FR_RCBR, FR_LBRC, FR_RBRC,
                    _______, MO(_CONF), _______,                      _______, _______, _______

                    ),


  [_CONF] = LAYOUT_split_3x6_3(

      QK_BOOT, LCTL(LALT(KC_DEL)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       TG(_BASE), TG(_NAV), TG(_SYMB), TG(_CONF), TG(_NUM), TG(_FUNC),
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                  TG(_GAMING), TG(_EMPTY), TG(8), TG(9), TG(10), TG(11),
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                  TG(12), TG(13), TG(14), TG(15), XXXXXXX, XXXXXXX,
                    _______, _______, _______,                               _______, _______, _______

                    ),


  [_NUM] = LAYOUT_split_3x6_3(

      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_PERC,        KC_LPRN, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PMNS,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC,       KC_RPRN, KC_P4, KC_P5, KC_P6, KC_PAST, KC_PPLS,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LT, KC_GT,           KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_PEQL,
                    TD(TD_BASE), MO(_BASE), _______,                      _______, _______, _______

                    ),


  [_FUNC] = LAYOUT_split_3x6_3(

      KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
      _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,       KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TD(TD_BASE),
                    _______, _______, _______,                    _______, _______, _______

                    ),


  [_GAMING] = LAYOUT_split_3x6_3(

      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                       KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
      XXXXXXX, KC_A, KC_S, KC_D, KC_F, KC_G,                      KC_H, SFT_J, CTL_K, ALT_L, GUI_SCLN, MO(_FUNC),
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,                      KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
                    KC_LALT, KC_LCTL, KC_SPC,                     KC_ENT, MO(_NAV), TD(TD_BASE)

                    ),


  [_EMPTY] = LAYOUT_split_3x6_3(

      KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______,                    _______, _______, _______

                    )
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_BASE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_LGUI, _BASE),
  [TD_FUNC] = ACTION_TAP_DANCE_LAYER_MOVE(KC_ESC, _FUNC),
  [TD_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_CAPS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

