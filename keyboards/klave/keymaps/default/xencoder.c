#include "xencoder.h"
#include "keymap.h"


extern user_config_t user_config;


void update_left(bool clockwise) {
    if (layer_state_is(L_ADJUST)) {
        return;
    } else if (layer_state_is(L_RAISE)) {
        return;
    } else if (layer_state_is(L_LOWER)) {
        tap_code(clockwise ? KC_MEDIA_NEXT_TRACK : KC_MEDIA_PREV_TRACK);
    } else {
        tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
    }
}

void update_right(bool clockwise) {
    tap_code(user_config.encoder_scroll_mode
        ? (clockwise ? KC_PGDOWN : KC_PGUP)
        : (clockwise ? KC_MS_WH_DOWN : KC_MS_WH_UP));
}


void encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case ENCODER_INDEX_LEFT:
            update_left(clockwise);
            break;
        case ENCODER_INDEX_RIGHT:
            update_right(clockwise);
            break;
    }
}


bool process_encoder(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        case K_ENC_SM:
            if (record->event.pressed) {
                user_config.encoder_scroll_mode ^= true;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        default:
            break;
    }

    return true;

}
