#include "keymap.h"
#include "diacritic.h"
#include "tap_dance.h"
#include "xencoder.h"
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "print.h"


LEADER_EXTERNS();


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base layer
 */
    [L_BASE] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   /**/                KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,        /**/
    /**/    K_DIAC,     KC_Q,       KC_W,       KC_M,       KC_D,       KC_F,                   /**/                KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    K_DIAC,         /**/
    /**/    K_LSFT,     KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       KC_MUTE,    /**/    K_ENC_SM,   KC_K,       KC_N,       KC_E,       KC_I,       KC_O,       K_RSFT,         /**/
    /**/    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_G,                   /**/                KC_B,       KC_H,       KC_COMM,    KC_DOT,     KC_DQUO,    KC_RCTL,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                KC_TAB,     KC_LEAD,    /**/    KC_MEH,     KC_DEL,                                                                     /**/
    /**/                            KC_LGUI,    KC_LALT,    K_LWR,      KC_SPC,     KC_ENT,     /**/    KC_HYPR,    KC_BSPC,    K_RSE,      KC_RALT,    KC_RGUI,                                /**/
                                                                                                                                                                                                /**/
    _),

/*
 * Lower layer
 */
    [L_LOWER] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    __ESC__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    KC_UNDS,        /**/
    /**/    XXXXXXX,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     DM_PLY2,                /**/                KC_TILD,    KC_AT,      KC_HASH,    KC_AMPR,    KC_COLN,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,    KC_MPLY,    /**/    _______,    KC_PERC,    KC_EQL,     KC_PLUS,    KC_ASTR,    KC_GRV,     __MOD__,        /**/
    /**/    __MOD__,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_PSCR,                /**/                KC_CIRC,    KC_DLR,     KC_QUES,    KC_EXLM,    KC_QUOT,    __MOD__,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                __WSP__,    XXXXXXX,    /**/    __MOD__,    __WSP__,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __WSP__,    __WSP__,    /**/    __MOD__,    __WSP__,    __LYR__,    __MOD__,    __MOD__,                                /**/
                                                                                                                                                                                                /**/
    _),

/*
 * Raise layer
 */
    [L_RAISE] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    __ESC__,    _______,    _______,    _______,    _______,    _______,                /**/                _______,    _______,    _______,    _______,    _______,    XXXXXXX,        /**/
    /**/    XXXXXXX,    XXXXXXX,    KC_BSLS,    KC_PIPE,    KC_SLSH,    XXXXXXX,                /**/                KC_HOME,    K_WRD_PREV, KC_UP,      K_WRD_NEXT, KC_PGUP,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_LABK,    KC_LCBR,    KC_LBRC,    KC_LPRN,    XXXXXXX,    KC_MSTP,    /**/    _______,    KC_END,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PGDN,    __MOD__,        /**/
    /**/    __MOD__,    KC_RABK,    KC_RCBR,    KC_RBRC,    KC_RPRN,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    __MOD__,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                __WSP__,    XXXXXXX,    /**/    __MOD__,    __WSP__,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    __WSP__,    __WSP__,    /**/    __MOD__,    __WSP__,    __LYR__,    __MOD__,    __MOD__,                                /**/
                                                                                                                                                                                                /**/
    _),

/*
 * Adjust layer
 */
    [L_ADJUST] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    TD(TD_SLP), XXXXXXX,    XXXXXXX,                /**/                KC_INS,     XXXXXXX,    KC_NLCK,    KC_CLCK,    KC_SLCK,    KC_PAUS,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC2,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC1,    KC_MSEL,    /**/    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    __MOD__,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_RSTP,                /**/                KC_APP,     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    __MOD__,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                XXXXXXX,    TD(TD_RST), /**/    __MOD__,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    XXXXXXX,    XXXXXXX,    /**/    __MOD__,    XXXXXXX,    __LYR__,    __MOD__,    __MOD__,                                /**/
                                                                                                                                                                                                /**/
    _),

};


void keyboard_post_init_user(void) {
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;
}

void matrix_scan_user(void) {

    diacritic_update_user();

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
    }

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!process_diacritic(keycode, record)) {
        return false;
    }
    if (!process_encoder(keycode, record)) {
        return false;
    }

    switch (keycode) {
        default:
            break;
    }
            
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    static layer_state_t last_state = 0;

    state = update_tri_layer_state(state, L_LOWER, L_RAISE, L_ADJUST);

    if (layer_state_cmp(state, L_LOWER) != layer_state_cmp(last_state, L_LOWER)) {
        if (layer_state_cmp(state, L_LOWER)) {
            writePinLow(B0);
        } else {
            writePinHigh(B0);
        }
    }
    if (layer_state_cmp(state, L_RAISE) != layer_state_cmp(last_state, L_RAISE)) {
        if (layer_state_cmp(state, L_RAISE)) {
            writePinLow(D5);
        } else {
            writePinHigh(D5);
        }
    }

    last_state = state;
    return state;
}
