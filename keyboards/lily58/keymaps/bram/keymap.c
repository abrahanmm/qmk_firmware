#include QMK_KEYBOARD_H

bool tilde_pulsado = false;

enum layer_number {
  _QWERTY = 0,
  _SYMBOLS,
  _MOVEMENT,
  _FUNCTIONS,
  _NUMBERS,
  _ADJUST,
};

enum custom_keycodes {
    TILDE = SAFE_RANGE,
    DIE_U, //u con dieresis
    EURO,
    INIT_QUES,
    SELLINE,
    DELLINE
};

// keys
#define L_SYMBOLS LT(_SYMBOLS, KC_SPC)
#define L_MOVEMENT LT(_MOVEMENT, KC_SPC)
#define L_FUNCTIONS LT(_FUNCTIONS, KC_DEL)
#define L_FUNC LT(_FUNCTIONS, KC_TAB)
#define B_FUNC LT(_FUNCTIONS, KC_BSPC)
#define E_NUMB LT(_NUMBERS, KC_ENT)
#define COPY RCTL(KC_C)
#define CUT RCTL(KC_X)
#define PASTE RCTL(KC_V)
#define UNDO RCTL(KC_Z)
#define SAVE RCTL(KC_S)
#define CLOSE LALT(KC_F4)
#define RELOAD RCTL(KC_F5)
#define DEF_VS RCTL(KC_F12) // go to definition at visual studio

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */
 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_QUOT, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  TILDE, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_BSPC,  KC_ENT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                    KC_LALT, KC_LGUI, L_MOVEMENT, B_FUNC, E_NUMB,    L_SYMBOLS, TILDE, KC_DEL \
 ),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ^  |   #  |   €  |   (  |   )  |                    |   &  |   /  |   |  |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   @  |   $  |   %  |   {  |   }  |-------.    ,-------|   !  |   =  |   >  |   -  |   _  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   `  |   <  |   >  |   [  |   ]  |-------|    |-------|   *  |   +  |   _  |   _  |   ¿  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */
[_SYMBOLS] = LAYOUT( \
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN, _______,\
  _______, KC_CIRC, KC_HASH,   EURO , KC_LPRN, KC_RPRN,                   KC_AMPR, KC_SLSH, KC_PIPE, KC_BSLASH, _______,_______, \
  _______,   KC_AT,  KC_DLR, KC_PERC, KC_LCBR, KC_RCBR,                   KC_EXLM, KC_EQUAL,KC_RABK, KC_MINS, KC_UNDS, _______, \
  KC_CAPS, KC_GRV,  KC_LABK, KC_RABK, KC_LBRC, KC_RBRC, _______, _______, KC_ASTR, KC_PLUS, KC_UNDS, KC_UNDS, INIT_QUES, _______, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* MOVEMENT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |     |DELLINE| CUT  | COPY | PASTE|                    |PageUp| Home |  Up  |  End | DEL  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | RGUI | RALT | RSFT | RCTRL| SAVE |-------.    ,-------|PageDo| Left | Down | Right|      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |CpsLck|      |      |     |SELLINE| UNDO |-------|    |-------|      |      |      |      |      |CpsLck|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */

[_MOVEMENT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______,   _______, _______, _______, _______, _______, \
  _______, _______, DELLINE,     CUT,    COPY,   PASTE,                     KC_PGUP,   KC_HOME,  KC_UP , KC_END, KC_DEL, _______, \
  _______, KC_RGUI, KC_RALT, KC_RSFT, KC_RCTRL,   SAVE,                     KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  KC_CAPS, _______, _______,_______,   SELLINE,   UNDO,  _______, _______,  _______,   _______, _______,  _______, _______, _______, \
                             _______, _______, _______,  _______, _______,  _______,   _______, _______ \
),
/* FUNCTIONS                                                            Mouse Wheel
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |   ü  |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------|      |CTRL+F5|CTRL+F12|ALT+F4|    |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      | CTRL |  ALT | SHIFT|  F11 |  F12 |-------|    |-------|      |      | LCTRL| RALT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */

[_FUNCTIONS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   _______,   DIE_U, _______, _______, _______, _______, \
  _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                   _______, RELOAD,  DEF_VS, CLOSE , _______, _______, \
  KC_CAPS, KC_LCTRL, KC_RALT, KC_LSFT,  KC_F11,  KC_F12, _______,  _______, _______, KC_LCTRL, KC_RALT, KC_LSFT, _______, _______, \
                             _______, _______, _______, _______, _______, _______, _______, _______\
),
/* NUMBERS                                                            Mouse Wheel
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   /  |   7  |   8  |   9  |  -   |                    |   /  |   7  |   8  |   9  |   +  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   *  |   4  |   5  |   6  |  +   |-------.    ,-------|   *  |   4  |   5  |   6  |   -  |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |   1  |   2  |   3  |  ,   |-------|    |-------|      |   1  |   2  |   3   |     |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |    0   | /Enter /        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      |        |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */

[_NUMBERS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,\
  _______,KC_BSLASH,    KC_7,   KC_8,   KC_9,  KC_MINS,                   KC_BSLASH, KC_7,   KC_8,   KC_9, KC_MINS, _______, \
  _______,  KC_ASTR,    KC_4,   KC_5,   KC_6,  KC_PLUS,                   KC_ASTR, KC_4,   KC_5,   KC_6, KC_PLUS, _______, \
  _______, _______,     KC_1,   KC_2,   KC_3,  KC_COMM, _______,  _______,_______, KC_1,   KC_2,   KC_3, KC_COMM, _______, \
                             _______,  _______,  KC_0, KC_ENT, _______,  KC_ENT,  KC_0, _______\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  UC_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYMBOLS, _MOVEMENT, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x22, 0xA2, 0x6E, 0xAA,
    0x2A, 0xEE, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x00, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x80, 0x00, 0x40,
    0x20, 0x10, 0x04, 0x82, 0x36, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0C, 0x18, 0x18, 0x38, 0x78,
    0xF8, 0xD8, 0x98, 0x10, 0x10, 0x30,
    0x30, 0x38, 0x38, 0x2C, 0x2C, 0x6E,
    0x66, 0x66, 0x46, 0xC6, 0xC7, 0xC6,
    0x86, 0x86, 0x06, 0x0E, 0x0C, 0x1C,
    0x18, 0x30, 0x60, 0xC0, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x99, 0x24,
    0x24, 0xA5, 0xA5, 0x18, 0x00, 0x52,
    0x52, 0x52, 0xDE, 0xD2, 0x5E, 0x00,
    0x3B, 0x10, 0x10, 0x90, 0x90, 0xB8,
    0x00, 0x33, 0x48, 0x48, 0x48, 0x48,
    0x30, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x60, 0x10, 0x0C, 0x03, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x11, 0x10,
    0x90, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x80, 0x80, 0x88, 0x88, 0x88,
    0x08, 0x48, 0x48, 0x48, 0x48, 0x60,
    0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xE1, 0xFF, 0x3F,
    0x0E, 0x1C, 0x38, 0x70, 0xE0, 0xC0,
    0x00, 0x00, 0x00, 0x20, 0x40, 0xC0,
    0xC0, 0xE0, 0xF0, 0xC1, 0x81, 0x83,
    0x83, 0x82, 0x86, 0x84, 0x8C, 0x89,
    0x9F, 0x9F, 0x38, 0x60, 0x60, 0xC0,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x89, 0x8A, 0xBB, 0xA8, 0xA8, 0xBB,
    0x00, 0x74, 0x96, 0x97, 0x95, 0x94,
    0x74, 0x00, 0xE2, 0x27, 0x25, 0xE8,
    0x28, 0xE8, 0x00, 0x91, 0x59, 0x5D,
    0x57, 0x53, 0x91, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0x00, 0x08, 0x00,
    0x08, 0x08, 0x00, 0x04, 0x02, 0x20,
    0x18, 0x06, 0x00, 0x00, 0x00, 0x00,
    0x31, 0x41, 0x09, 0x80, 0x04, 0x04,
    0x04, 0x04, 0x00, 0x02, 0x02, 0x02,
    0x02, 0x00, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
    0x3F, 0xFC, 0xE0, 0x80, 0x00, 0x80,
    0x81, 0xC3, 0x7F, 0x3C, 0x00, 0x00,
    0x02, 0x83, 0x83, 0x87, 0xCF, 0xC1,
    0xC1, 0xE1, 0x61, 0x71, 0x31, 0x39,
    0x19, 0x9D, 0xED, 0x7C, 0x1E, 0x06,
    0x03, 0x03, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x4B, 0x28, 0x18, 0x6B,
    0x48, 0x3B, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
    0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x02, 0x03, 0x00, 0x02, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x02,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x00, 0x08, 0x08, 0x08, 0x08,
    0x12, 0x02, 0x22, 0x24, 0x44, 0x08,
    0x48, 0x41, 0x50, 0x32, 0x02, 0x10,
    0x14, 0x08, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
    0x18, 0x18, 0x1C, 0x1C, 0x0F, 0x0F,
    0x0F, 0x0F, 0x1F, 0x3E, 0x36, 0x36,
    0x67, 0x63, 0x63, 0x63, 0x61, 0x61,
    0x61, 0x60, 0x70, 0x30, 0x30, 0x18,
    0x1C, 0x0E, 0x07, 0x03, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#    define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _SYMBOLS:
            oled_write_ln_P(PSTR("SYMB"), false);
            break;
        case _MOVEMENT:
            oled_write_P(PSTR("MOVE"), false);
            break;
        case _FUNCTIONS:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
        case _NUMBERS:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJUST"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_ln_P(PSTR("Mods"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    render_mod_status(get_mods());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

void oled_task_user(void) {
  update_log();
  if (is_keyboard_master()) {
    render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_lily58_logo();
  }
}
#endif // OLED_DRIVER_ENABLE

bool send_accent_unicode_string(const char *string, const char *capitalizeString)
{
    if (tilde_pulsado) {
        //TODO: comprobar que el bloqueo mayusculas está activado
        if ((get_mods() & MOD_MASK_SHIFT) || host_keyboard_led_state().caps_lock) {
            send_unicode_string(capitalizeString);
        }
        else {
            send_unicode_string(string);
        }
        tilde_pulsado = false;
        return false;
    }
    else {
        return true;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        add_keylog(keycode);
    }
#endif
  switch (keycode) {
    case INIT_QUES:
        if (record->event.pressed) {
            send_unicode_string("¿");
        }
        return false;
        break;
    case EURO:
        if (record->event.pressed) {
            send_unicode_string("€");
        }
      return false;
      break;
    case TILDE:
        if (record->event.pressed) {
            tilde_pulsado = true;
        }
        return false;
        break;
    case KC_LSFT:
        return true;
        break;
    case KC_RSFT:
        return true;
        break;
    case DIE_U:
        if (record->event.pressed) {
            send_unicode_string("ü");
        }
        tilde_pulsado = false;
        return false;
        break;
    case SELLINE:  // Selects the current line.
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            // Mac users, use:
            // SEND_STRING(SS_LCTL("a" SS_LSFT("e")));
        }
        return false;
    case DELLINE:  // Selects the current line.
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)) SS_TAP(X_BSPC) SS_TAP(X_BSPC));
            // Mac users, use:
            // SEND_STRING(SS_LCTL("a" SS_LSFT("e")));
        }
        return false;
        
    case KC_A:
        return send_accent_unicode_string("á", "Á");
        break;
    case KC_E:
        return send_accent_unicode_string("é", "É");
        break;
    case KC_I:
        return send_accent_unicode_string("í", "Í");
        break;
    case KC_O:
        return send_accent_unicode_string("ó", "Ó");
        break;
    case KC_U:
        return send_accent_unicode_string("ú", "Ú");
        break;
    case KC_N:
        return send_accent_unicode_string("ñ", "Ñ");
        break;
      default:
          if (record->event.pressed) {
              tilde_pulsado = false;
            }
            return true;
        break;
    }
}
