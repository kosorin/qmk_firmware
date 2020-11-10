#pragma once

#include "quantum.h"


typedef union {
    uint32_t raw;
    struct {
        bool encoder_scroll_mode : 1;
    };
} user_config_t;


// Layers
enum {
    L_BASE,
    L_LOWER,
    L_RAISE,
    L_ADJUST,
} ;

// Keycodes
enum {
    // Transparent
    __LYR__ = _______,
    __MOD__ = _______,
    __WSP__ = _______,
    __ESC__ = _______,

    // Layers
    K_LWR = MO(L_LOWER),
    K_RSE = MO(L_RAISE),

    // Modifiers
    K_LSFT = OSM(MOD_LSFT),
    K_RSFT = OSM(MOD_RSFT),
};

// Custom keycodes
enum {
    K_SAFE_RANGE = SAFE_RANGE,

    // Diacritics
    K_DIAC,

    // Encoder
    K_ENC_SM,
};
