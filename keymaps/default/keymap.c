// Copyright 2026 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_1,    /* SW1 - Top Switch (GP26) */
        KC_2,    /* SW2 - Center Switch (GP27) */
        KC_3,    /* SW3 - Bottom Switch (GP28) */
        KC_4,    /* SW4 - Right Switch (GP29) */
        KC_MUTE  /* SW5 - Encoder Push Button (GP1) */
    )
};

#if defined(ENCODER_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION180;
}

bool oled_task_user(void) {
    oled_write_ln_P(PSTR("Hackpad of Artem"), false);
    return false;
}
#endif
