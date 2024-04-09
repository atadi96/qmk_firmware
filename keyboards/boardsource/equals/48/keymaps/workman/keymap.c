// Copyright 2022 @boardsource
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "color.h"

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
    _ADJUST,
    _HUN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

/*const*/ uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_ortho_4x12(KC_DEL, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_BSLS, KC_BSPC, KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, KC_I, LT(4,KC_QUOT), SC_LSPO, LCTL_T(KC_Z), KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, RCTL_T(KC_SLSH), SC_RSPC, CW_TOGG, KC_LCTL, KC_LALT, KC_LGUI, LT(1,KC_SPC), KC_SPC, KC_ENT, LT(2,KC_ENT), KC_TAB, KC_DOWN, KC_UP, MO(5)),
        [1] = LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_EQL, KC_LT, KC_GT, KC_F2, KC_NO, KC_HOME, KC_END, KC_DLR, KC_CIRC, KC_TRNS, KC_TRNS, KC_AMPR, KC_PIPE, KC_LCBR, KC_RCBR, LALT(KC_F12), KC_F12, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_ESC, KC_TRNS, KC_PSLS, KC_PAST, KC_PPLS, KC_PMNS, KC_F5, KC_F6, KC_UNDS, LCTL(KC_SPC), LCTL(KC_DOT), KC_AT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_TRNS, KC_MPLY),
        [2] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
        [3] = LAYOUT_ortho_4x12(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_HUD, RGB_M_P, KC_NO, KC_NO, BL_TOGG, BL_STEP, BL_BRTG, KC_NO, KC_NO, KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_NO, BL_ON, BL_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
        [4] = LAYOUT_ortho_4x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC(0xF6), UC(0xFC), UC(0xF3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC(0x171), UC(0xE9), UC(0xE1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UC(0xED), UC(0x151), UC(0xFA), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
        [5] = LAYOUT_ortho_4x12(KC_TRNS, KC_EXLM, KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_TRNS, KC_TRNS, KC_HASH, KC_DLR, KC_LPRN, KC_RPRN, KC_GRV, KC_NO, KC_P4, KC_P5, KC_P6, KC_PAST, KC_TRNS, KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_P1, KC_P2, KC_P3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PEQL, KC_P0, KC_PDOT, KC_PPLS, KC_TRNS)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 3);
}



extern rgb_config_t rgb_matrix_config;

#define NEON_BONEYARD {195,61,255}
#define LINDERHOF_GARDEN {85,203,158}
#define MELLOW_MELON {243,222,234}
#define HABANERO_GOLD {32,176,255}

#define MY_LED_COUNT 48

uint8_t ledmap[][MY_LED_COUNT][3] = {
    [1] = { NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, LINDERHOF_GARDEN, {HSV_BLACK},      LINDERHOF_GARDEN, LINDERHOF_GARDEN, NEON_BONEYARD,    NEON_BONEYARD,    {HSV_BLACK},
            {HSV_BLACK},   NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, LINDERHOF_GARDEN, LINDERHOF_GARDEN, LINDERHOF_GARDEN, LINDERHOF_GARDEN, LINDERHOF_GARDEN, LINDERHOF_GARDEN, LINDERHOF_GARDEN,
            {HSV_BLACK},   NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, NEON_BONEYARD, MELLOW_MELON,     LINDERHOF_GARDEN, NEON_BONEYARD,    LINDERHOF_GARDEN, HABANERO_GOLD,    NEON_BONEYARD,    {HSV_BLACK},
            {HSV_BLACK},   {HSV_BLACK},   {HSV_BLACK},   {HSV_BLACK},   {HSV_BLACK},   {HSV_BLACK},      {HSV_BLACK},      {HSV_BLACK},      LINDERHOF_GARDEN, LINDERHOF_GARDEN, {HSV_BLACK},      LINDERHOF_GARDEN }
};

void set_layer_color(int layer) {
  int keyIndex = 0;
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    if ((g_led_config.flags[i] & (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER)) && keyIndex < MY_LED_COUNT)
    {
        HSV hsv = {
            .h = ledmap[layer][keyIndex][0],
            .s = ledmap[layer][keyIndex][1],
            .v = ledmap[layer][keyIndex][2],
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
        ++keyIndex;
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (!rgb_matrix_is_enabled()) { return false; }
  switch (biton32(layer_state)) {
    //case 0:
    //  set_layer_color(0);
    //  break;
    case 1:
      set_layer_color(1);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}