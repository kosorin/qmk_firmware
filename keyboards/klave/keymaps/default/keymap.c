#include "keymap.h"
#include "diacritic.h"
#include "tap_dance.h"
#include "xencoder.h"
#include QMK_KEYBOARD_H

#include "quantum.h"
#include "print.h"


LEADER_EXTERNS();


user_config_t user_config;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base layer
 */
    [L_BASE] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                   /**/                KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_GRV,         /**/
    /**/    K_DIAC,     KC_Q,       KC_W,       KC_M,       KC_D,       KC_F,                   /**/                KC_B,       KC_L,       KC_U,       KC_Y,       KC_DQUO,    K_DIAC,         /**/
    /**/    KC_LSFT,    KC_A,       KC_R,       KC_S,       KC_T,       KC_P,       KC_MUTE,    /**/    K_ENC_SM,   KC_K,       KC_N,       KC_E,       KC_I,       KC_O,       KC_RSFT,        /**/
    /**/    KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_G,                   /**/                KC_J,       KC_H,       KC_COMM,    KC_DOT,     KC_QUES,    KC_RCTL,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                KC_TAB,     KC_LEAD,    /**/    KC_HYPR,    KC_DEL,                                                                     /**/
    /**/                            KC_LGUI,    KC_LALT,    K_LWR,      KC_SPC,     KC_ENT,     /**/    KC_MEH,     KC_BSPC,    K_RSE,      KC_RALT,    KC_RGUI,                                /**/
                                                                                                                                                                                                /**/
    _),

/*
 * Lower layer
 */
    [L_LOWER] = LAYOUT(
                                                                                                                                                                                                /**/
    /**/    __ESC__,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     XXXXXXX,                /**/                XXXXXXX,    KC_7,       KC_8,       KC_9,       XXXXXXX,    KC_CIRC,        /**/
    /**/    XXXXXXX,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     DM_PLY2,                /**/                KC_ASTR,    KC_4,       KC_5,       KC_6,       KC_SLSH,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      DM_PLY1,    KC_MPLY,    /**/    XXXXXXX,    KC_PLUS,    KC_1,       KC_2,       KC_3,       KC_MINS,    __MOD__,        /**/
    /**/    __MOD__,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_PSCR,                /**/                KC_PERC,    KC_0,       KC_COMM,    KC_DOT,     KC_EQL,     __MOD__,        /**/
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
    /**/    __ESC__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                /**/                XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_TILD,        /**/
    /**/    XXXXXXX,    KC_LABK,    KC_RABK,    KC_LPRN,    KC_RPRN,    KC_PIPE,                /**/                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_QUOT,    XXXXXXX,        /**/
    /**/    __MOD__,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_SLSH,    XXXXXXX,    /**/    XXXXXXX,    KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_MINS,    __MOD__,        /**/
    /**/    __MOD__,    KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,    KC_BSLS,                /**/                KC_UNDS,    KC_EQL,     KC_SCLN,    KC_COLN,    KC_EXLM,    __MOD__,        /**/
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
    /**/    __ESC__,    XXXXXXX,    TD(TD_SLP), TD(TD_RST), TD(TD_EER), XXXXXXX,                /**/                KC_INS,     KC_NLCK,    KC_CLCK,    KC_SLCK,    XXXXXXX,    KC_PAUS,        /**/
    /**/    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC2,                /**/                XXXXXXX,    KC_MPLY,    KC_VOLU,    KC_MSTP,    XXXXXXX,    XXXXXXX,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_REC1,    XXXXXXX,    /**/    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_VOLD,    KC_MNXT,    XXXXXXX,    __MOD__,        /**/
    /**/    __MOD__,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DM_RSTP,                /**/                XXXXXXX,    KC_MRWD,    KC_MUTE,    KC_MFFD,    XXXXXXX,    __MOD__,        /**/
    /**/                                                                                                                                                                                        /**/
    /**/                                                                XXXXXXX,    KC_APP,     /**/    __MOD__,    XXXXXXX,                                                                    /**/
    /**/                            __MOD__,    __MOD__,    __LYR__,    XXXXXXX,    XXXXXXX,    /**/    __MOD__,    XXXXXXX,    __LYR__,    __MOD__,    __MOD__,                                /**/
                                                                                                                                                                                                /**/
    _),

};


void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.encoder_scroll_mode = false;
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {

#if CONSOLE_ENABLE
    debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;
#endif

    user_config.raw = eeconfig_read_user();

}

void matrix_scan_user(void) {

    diacritic_update_user();

    LEADER_DICTIONARY() {
        leading = false; 
        
        if (false) { }

        else SEQ_TWO_KEYS(KC_E, KC_E) {
            SEND_STRING("david@kosorin.net");
        }
        else SEQ_TWO_KEYS(KC_E, KC_G) {
            SEND_STRING("david.kosorin@gmail.com");
        }
        else SEQ_TWO_KEYS(KC_E, KC_O) {
            SEND_STRING("david.kosorin@outlook.com");
        }

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
