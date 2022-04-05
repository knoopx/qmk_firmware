VIA_ENABLE = yes

LTO_ENABLE = no
MIDI_ENABLE = no
STENO_ENABLE = no
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no

NKRO_ENABLE = yes
UCIS_ENABLE = yes
# UNICODE_ENABLE = no
# UNICODEMAP_ENABLE = no
EXTRAKEY_ENABLE = yes

# TAP_DANCE_ENABLE = no
# AUTO_SHIFT_ENABLE = no
# RGB_MATRIX_CUSTOM_USER = no

# CONSOLE_ENABLE = yes
# COMMAND_ENABLE = no

# SRC += hid_rgb_matrix.c
SRC += rgb_matrix_user.c
SRC += process_record_user.c
SRC += led_user.c
SRC += ucis_user.c