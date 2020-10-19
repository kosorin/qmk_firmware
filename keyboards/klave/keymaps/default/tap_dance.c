#include "tap_dance.h"

#include "quantum.h"


#define SAFE_TAP_DANCE_COUNT 3


void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= SAFE_TAP_DANCE_COUNT) {
        if (get_mods() & MOD_MASK_ALT) {
            eeconfig_init();
        } else {
            reset_keyboard();
        }
    }
}

void safe_sleep(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= SAFE_TAP_DANCE_COUNT) {
        tap_code(KC_SYSTEM_SLEEP);
    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_reset, NULL),
    [TD_SLP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, safe_sleep, NULL),
};
