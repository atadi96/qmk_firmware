// Copyright 2022 @boardsource
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
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

enum custom_keycodes {
  ST_MACRO_UE = SAFE_RANGE,
  ST_MACRO_OE,
  ST_MACRO_AE,
  ST_MACRO_AA,
  ST_MACRO_OO,
  ST_MACRO_UU,
  ST_MACRO_II,
  ST_MACRO_ESCAPED_SMILEY,
};


enum tap_dance_codes {
  DANCE_BRACKET_LEFT,
  DANCE_BRACKET_RIGHT,
};

enum unicode_names {
    OOE_LOWER,
    OOE_UPPER,
    UUE_LOWER,
    UUE_UPPER,
};

const uint32_t PROGMEM unicode_map[] = {
    [OOE_LOWER] = 0x151,  // ő
    [OOE_UPPER] = 0x150,  // Ő
    [UUE_LOWER] = 0x171, // ű
    [UUE_UPPER] = 0x170, // Ű
};

#define NUM_LAYERS 6

uint16_t keymaps[NUM_LAYERS][MATRIX_ROWS][MATRIX_COLS] = {
        [0] = LAYOUT_ortho_4x12(KC_DEL, KC_Q, KC_D, KC_R, KC_W, KC_B, KC_J, KC_F, KC_U, KC_P, KC_SCLN, KC_BSLS, KC_BSPC, KC_A, KC_S, KC_H, KC_T, KC_G, KC_Y, KC_N, KC_E, KC_O, KC_I, LT(4,KC_QUOT), SC_LSPO, LCTL_T(KC_Z), KC_X, KC_M, KC_C, KC_V, KC_K, KC_L, KC_COMM, KC_DOT, RCTL_T(KC_SLSH), SC_RSPC, LT(5,KC_GRV), MT(MOD_LALT, KC_APPLICATION), LSFT(KC_LALT), KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_TAB, KC_DOWN, KC_UP, MO(5)),
        [1] = LAYOUT_ortho_4x12(KC_TILD, KC_EXLM, KC_EQL, KC_LT, KC_GT, KC_F2, KC_NO, KC_HOME, KC_END, KC_DLR, KC_CIRC, KC_TRNS, KC_TRNS, KC_AMPR, KC_PIPE, TD(DANCE_BRACKET_LEFT), TD(DANCE_BRACKET_RIGHT), LALT(KC_F12), KC_F12, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_ESC, KC_TRNS, KC_PSLS, KC_PAST, KC_PPLS, KC_PMNS, KC_F5, KC_F6, KC_UNDS, LCTL(KC_SPC), LCTL(KC_DOT), KC_AT, KC_TRNS, CW_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_TRNS, KC_MPLY),
        [2] = LAYOUT_ortho_4x12(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),
        [3] = LAYOUT_ortho_4x12(QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_HUI, RGB_HUD, RGB_M_P, KC_NO, KC_NO, BL_TOGG, BL_STEP, BL_BRTG, KC_NO, ST_MACRO_ESCAPED_SMILEY, KC_NO, RGB_TOG, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_NO, BL_ON, BL_OFF, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO),
        [4] = LAYOUT_ortho_4x12(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ST_MACRO_OE, ST_MACRO_UE, ST_MACRO_OO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, UP(UUE_LOWER, UUE_UPPER), ST_MACRO_AE, ST_MACRO_AA, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ST_MACRO_II, UP(OOE_LOWER, OOE_UPPER), ST_MACRO_UU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
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

uint8_t ledmap[NUM_LAYERS][MY_LED_COUNT][3] = {
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

void flip_keycodes(void) {
    size_t row_bound = (MATRIX_ROWS + 1) / 2;
    //size_t col_bound = (MATRIX_COLS + 1) / 2;
    for (size_t layer_index = 0; layer_index < NUM_LAYERS; layer_index++)
    {
        for (size_t row_index = 0; row_index < row_bound; row_index++)
        {
            for (size_t col_index = 0; col_index < MATRIX_COLS; col_index++)
            {
                size_t row_other = MATRIX_ROWS - 1 - row_index;
                size_t col_other = MATRIX_COLS - 1 - col_index;
                uint16_t temp = keymaps[layer_index][row_index][col_index];
                keymaps[layer_index][row_index][col_index] = keymaps[layer_index][row_other][col_other];
                keymaps[layer_index][row_other][col_other] = temp;
            }
        }
    }
}

void flip_ledmaps(void) {
    size_t led_bound = (MY_LED_COUNT + 1) / 2;
    for (size_t layer_index = 0; layer_index < NUM_LAYERS; layer_index++)
    {
        for (size_t led_index = 0; led_index < led_bound; led_index++)
        {
            for (size_t hsv_index = 0; hsv_index < 3; hsv_index++)
            {
                size_t led_other = MY_LED_COUNT - 1 - led_index;
                uint8_t temp = ledmap[layer_index][led_index][hsv_index];
                ledmap[layer_index][led_index][hsv_index] = ledmap[layer_index][led_other][hsv_index];
                ledmap[layer_index][led_other][hsv_index] = temp;
            }
        }
    }
}

void keyboard_post_init_user(void) {
    flip_keycodes();
    flip_ledmaps();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_ESCAPED_SMILEY:
    if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_BSLS) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_LSFT(SS_TAP(X_0)));
    }
    break;
    case ST_MACRO_OE:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_4) )); // Ö
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_4) SS_TAP(X_KP_6) )); // ö
            //SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) )); // ö ???
        }
    }
    break;
    case ST_MACRO_UE:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_2) SS_TAP(X_KP_0) )); // Ü
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9) )); // ü
        }
    }
    break;
    case ST_MACRO_OO:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_1) )); // Ó
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_2) )); // ó
        }
    }
    break;
    case ST_MACRO_UU:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_1) SS_TAP(X_KP_8) )); // Ú
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3) )); // ú
        }
    }
    break;
    case ST_MACRO_AE:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_1) )); // É
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_0) )); // é
        }
    }
    break;
    case ST_MACRO_AA:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_9) SS_TAP(X_KP_3) )); // Á
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_0) )); // á
        }
    }
    break;
    case ST_MACRO_II:
    if (record->event.pressed) {
        uint8_t shift_mods = get_mods() & MOD_MASK_SHIFT;
        if (shift_mods)
        {
            unregister_mods(shift_mods);
            SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_2) SS_TAP(X_KP_0) SS_TAP(X_KP_5) )); // Í
            register_mods(shift_mods);
        }
        else
        {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_1) )); // í
        }
    }
    break;
  }
  return true;
}



typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_LBRC));
        tap_code16(LSFT(KC_LBRC));
        tap_code16(LSFT(KC_LBRC));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_LBRC));
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BRACKET_LEFT].step = dance_step(state);
    switch (dance_state[DANCE_BRACKET_LEFT].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_LBRC)); break;
        case SINGLE_HOLD: register_code16(KC_LBRC); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_LBRC)); register_code16(LSFT(KC_LBRC)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_LBRC)); register_code16(LSFT(KC_LBRC));
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BRACKET_LEFT].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_LBRC)); break;
        case SINGLE_HOLD: unregister_code16(KC_LBRC); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_LBRC)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_LBRC)); break;
    }
    dance_state[DANCE_BRACKET_LEFT].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LSFT(KC_RBRC));
        tap_code16(LSFT(KC_RBRC));
        tap_code16(LSFT(KC_RBRC));
    }
    if(state->count > 3) {
        tap_code16(LSFT(KC_RBRC));
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[DANCE_BRACKET_RIGHT].step = dance_step(state);
    switch (dance_state[DANCE_BRACKET_RIGHT].step) {
        case SINGLE_TAP: register_code16(LSFT(KC_RBRC)); break;
        case SINGLE_HOLD: register_code16(KC_RBRC); break;
        case DOUBLE_TAP: register_code16(LSFT(KC_RBRC)); register_code16(LSFT(KC_RBRC)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LSFT(KC_RBRC)); register_code16(LSFT(KC_RBRC));
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[DANCE_BRACKET_RIGHT].step) {
        case SINGLE_TAP: unregister_code16(LSFT(KC_RBRC)); break;
        case SINGLE_HOLD: unregister_code16(KC_RBRC); break;
        case DOUBLE_TAP: unregister_code16(LSFT(KC_RBRC)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LSFT(KC_RBRC)); break;
    }
    dance_state[DANCE_BRACKET_RIGHT].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_BRACKET_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_BRACKET_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
