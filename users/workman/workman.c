#include "workman.h"

#include "process_tap_dance.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

const uint32_t PROGMEM unicode_map[] = {
    [OOE_LOWER] = 0x151,  // ő
    [OOE_UPPER] = 0x150,  // Ő
    [UUE_LOWER] = 0x171, // ű
    [UUE_UPPER] = 0x170, // Ű
    [UE_LOWER] = 0x00FC, // ü
    [UE_UPPER] = 0x00DC, // Ü
    [OE_LOWER] = 0x00F6, // ö
    [OE_UPPER] = 0x00D6, // Ö
    [AE_LOWER] = 0x00E9, // é
    [AE_UPPER] = 0x00C9, // É
    [AA_LOWER] = 0x00E1, // á
    [AA_UPPER] = 0x00C1, // Á
    [OO_LOWER] = 0x00F3, // ó
    [OO_UPPER] = 0x00D3, // Ó
    [UU_LOWER] = 0x00FA, // ú
    [UU_UPPER] = 0x00DA, // Ú
    [II_LOWER] = 0x00ED, // í
    [II_UPPER] = 0x00CD // Í
};

bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_WINDOWS:
            set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        case OS_UNSURE:
        case OS_MACOS:
        case OS_IOS:
            break;
    }
    
    return true;
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
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
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(OE_LOWER, OE_UPPER)));
        }
    }
    break;
    case ST_MACRO_UE:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(UE_LOWER, UE_UPPER)));
        }
    }
    break;
    case ST_MACRO_OO:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(OO_LOWER, OO_UPPER)));
        }
    }
    break;
    case ST_MACRO_UU:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(UU_LOWER, UU_UPPER)));
        }
    }
    break;
    case ST_MACRO_AE:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(AE_LOWER, AE_UPPER)));
        }
    }
    break;
    case ST_MACRO_AA:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(AA_LOWER, AA_UPPER)));
        }
    }
    break;
    case ST_MACRO_II:
    if (record->event.pressed) {
        if(get_unicode_input_mode() == UNICODE_MODE_WINCOMPOSE) {
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
        } else {
            register_unicodemap(unicodemap_index(UP(II_LOWER, II_UPPER)));
        }
    }
    break;
  }
  return process_record_keymap(keycode, record);
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

static tap dance_state[3];

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

void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(LCTL(KC_TAB)));
        tap_code16(LALT(LCTL(KC_TAB)));
        tap_code16(LALT(LCTL(KC_TAB)));
    }
    if(state->count > 3) {
        tap_code16(LALT(LCTL(KC_TAB)));
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(LCTL(KC_TAB))); break;
        case SINGLE_HOLD: register_code16(LALT(KC_TAB)); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LSFT(KC_TAB)))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(LCTL(KC_TAB))); register_code16(LALT(LCTL(KC_TAB)));
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(LCTL(KC_TAB))); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_TAB)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LSFT(KC_TAB)))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(LCTL(KC_TAB))); break;
    }
    dance_state[0].step = 0;
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
        [DANCE_WINDOW_SELECT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_BRACKET_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_BRACKET_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
};
