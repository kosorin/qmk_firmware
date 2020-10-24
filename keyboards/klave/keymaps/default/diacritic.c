#include "diacritic.h"
#include "keymap.h"


#define DIACRITIC_INDEX(kc) ((kc) - KC_A)
#define DIACRITIC_COUNT ((KC_Z - KC_A) + 1)

enum {
    D_ACUTE = ALGR(KC_EQL),
    D_CARON = ALGR(LSFT(KC_EQL)),
    D_RING = ALGR(LSFT(KC_GRV)),
};

bool diacritic = false;
uint16_t diacritic_timer = 0;
bool diacritic_holding = false;
bool diacritic_other_key = false;
bool diacritic_pressed[DIACRITIC_COUNT];


void tap_diacritic(uint8_t keycode, uint16_t diacritic_keycode) {
    suspend_mods();
    tap_code16(diacritic_keycode);
    resume_mods();
    tap_code(keycode);
}


void diacritic_update_user() {
#if defined(ONESHOT_TIMEOUT) && (ONESHOT_TIMEOUT > 0)
    if (diacritic && !diacritic_holding && timer_elapsed(diacritic_timer) > ONESHOT_TIMEOUT) {
        diacritic = false;
        dprintln("DIAC OFF timeout");
    }
#endif
}

bool process_diacritic(uint16_t keycode, keyrecord_t *record) {

    bool use_diacritic = diacritic;
    
    if (record->event.pressed) {
        if (diacritic) {
            if (keycode == K_DIAC || keycode == K_LSFT || keycode == K_RSFT) {
                diacritic_timer = timer_read();
            } else {
                diacritic_other_key = true;
                if (!diacritic_holding) {
                    diacritic = false;
                    dprintln("DIAC OFF other key");
                }
            }
        }
    }

    switch (keycode) {
        case K_DIAC:
            if (record->event.pressed) {
                diacritic = true;
                diacritic_timer = timer_read();
                diacritic_holding = true;
                diacritic_other_key = false;
                dprintln("DIAC ON");
            } else {
                diacritic_holding = false;
                if (diacritic_other_key || timer_elapsed(diacritic_timer) > TAPPING_TERM) {
                    diacritic = false;
                    dprintf("DIAC OFF %s\n", diacritic_other_key ? "other key release" : "holding");
                }
            }
            return false;
        case KC_A ... KC_Z:
        {
            if (record->event.pressed) {
                if (use_diacritic) {
                    dprintln("DIAC use");
                    uint8_t actual_keycode = keycode;
                    uint16_t diacritic_keycode = KC_NO;
                    switch (keycode) {
                        // Acute
                        case KC_M: diacritic_keycode = D_ACUTE; actual_keycode = KC_E; break;
                        case KC_J: diacritic_keycode = D_ACUTE; actual_keycode = KC_U; break;
                        case KC_I: diacritic_keycode = D_ACUTE; break;
                        case KC_O: diacritic_keycode = D_ACUTE; break;
                        case KC_A: diacritic_keycode = D_ACUTE; break;
                        case KC_Y: diacritic_keycode = D_ACUTE; break;
                        // Caron
                        case KC_E: diacritic_keycode = D_CARON; break;
                        case KC_R: diacritic_keycode = D_CARON; break;
                        case KC_T: diacritic_keycode = D_CARON; break;
                        case KC_Z: diacritic_keycode = D_CARON; break;
                        case KC_S: diacritic_keycode = D_CARON; break;
                        case KC_D: diacritic_keycode = D_CARON; break;
                        case KC_C: diacritic_keycode = D_CARON; break;
                        case KC_N: diacritic_keycode = D_CARON; break;
                        // Ring
                        case KC_U: diacritic_keycode = D_RING; break;
                        default: return true;
                    }
                    tap_diacritic(actual_keycode, diacritic_keycode);
                    diacritic_pressed[DIACRITIC_INDEX(keycode)] = true;
                    return false;
                }
            }
            else {
                if (diacritic_pressed[DIACRITIC_INDEX(keycode)]) {
                    diacritic_pressed[DIACRITIC_INDEX(keycode)] = false;
                    return false;
                }
            }
            return true;
        }
        default:
            break;
    }

    return true;
}