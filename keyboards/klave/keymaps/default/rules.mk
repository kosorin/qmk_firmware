# Build options
SRC += diacritic.c
SRC += tap_dance.c
SRC += xencoder.c

# Features
OLED_DRIVER_ENABLE = no
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
LEADER_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Testing and debugging
CONSOLE_ENABLE = yes
