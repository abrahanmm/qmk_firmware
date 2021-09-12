#include QMK_KEYBOARD_H

bool tilde_pulsado = false;

enum layer_number {
  _QWERTY = 0,
  _SYMBOLS,
  _MOVEMENT,
  _FUNCTIONS,
  _ADJUST,
};

enum custom_keycodes {
    TILDE = SAFE_RANGE,
    DIE_U, //u con dieresis
    EURO,
    INIT_QUES
};

// keys
#define L_SYMBOLS LT(_SYMBOLS, KC_SPC)
#define L_MOVEMENT LT(_MOVEMENT, KC_SPC)
#define L_FUNCTIONS LT(_FUNCTIONS, KC_DEL)
#define COPY RCTL(KC_C)
#define CUT RCTL(KC_X)
#define PASTE RCTL(KC_V)
#define UNDO RCTL(KC_Z)
#define SAVE RCTL(KC_S)
#define CLOSE LALT(KC_F4)
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
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LALT, KC_LGUI, L_MOVEMENT, KC_BSPC, KC_ENT, L_SYMBOLS, TILDE, L_FUNCTIONS \
),
/* SYMBOLS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |   €  |   (  |   )  |                    |   &  |   /  |   |  |   \  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   $  |      |   {  |   }  |-------.    ,-------|   !  |   =  |   _  |   -  |      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |   `  |   ^  |   #  |   %  |-------|    |-------|   *  |   +  |   @  |      |   ¿  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */
[_SYMBOLS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______,  _______, _______, _______, _______,\
  _______, _______, _______,   EURO , KC_LPRN, KC_RPRN,                   KC_AMPR, KC_SLSH, KC_PIPE, KC_BSLASH, _______,_______, \
  _______, _______,  KC_DLR, _______, KC_LCBR, KC_RCBR,                   KC_EXLM, KC_EQUAL,KC_UNDS, KC_MINS, _______, _______, \
  KC_CAPS, _______,  KC_GRV, KC_CIRC, KC_HASH, KC_PERC, _______, _______, KC_ASTR, KC_PLUS, KC_AT, _______, INIT_QUES, KC_CAPS, \
                             _______, _______, _______, _______, _______,  _______, _______, _______\
),
/* MOVEMENT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |BackSP|PASTE |  DEL |                    |PageUp| Home |  Up  |  End |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | RGUI | RALT | RSFT | RCTRL| COPY |-------.    ,-------|PageDo| Left | Down | Right|      |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |CpsLck|      |      | SAVE |  CUT | UNDO |-------|    |-------|      |      |      |      |      |CpsLck|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */

[_MOVEMENT] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______,   _______, _______, _______, _______, _______, \
  _______, _______, _______, KC_BSPC,  PASTE ,  KC_DEL,                     KC_PGUP,   KC_HOME,  KC_UP , KC_END, _______, _______, \
  _______, KC_RGUI, KC_RALT, KC_RSFT, KC_RCTRL, COPY  ,                     KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  KC_CAPS, _______, _______,   SAVE ,   CUT  ,  UNDO  ,  _______, _______,  _______,   _______, _______,  _______, _______, KC_CAPS, \
                             _______, _______, _______,  _______, _______,  _______,   _______, _______ \
),
/* FUNCTIONS                                                            Mouse Wheel
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |      |      |   ü  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F6  |  F7  |  F8  |  F9  |  F10 |-------.    ,-------|      |  Up  |CTRL+F12|ALT+F4|     |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |  F11 |  F12 |-------|    |-------|      | Down | LCTRL| RALT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                 | LAlt | LGUI |MOVEMENT| /BackSP/        \Enter \  | SYMBOLS | ACCENT | DEL |
 *                 |      |      | space  |/      /          \      \ |  space  |        |     |
 *                  `----------------------------'            '--------------------------------'
 */

[_FUNCTIONS] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,\
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   _______,   DIE_U, _______, _______, _______, _______, \
  _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                   _______, _______,  DEF_VS, CLOSE , _______, _______, \
  KC_CAPS, _______, _______, _______,  KC_F11,  KC_F12, _______,  UC_MOD, _______, _______, KC_LCTRL, KC_RALT, _______, KC_CAPS, \
                             _______, _______, _______, _______, _______, _______, _______, _______\
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
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
    // 'logo', 128x32px
    /*0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00*/
    // 'Code', 32x128px
0xff, 0xff, 0xff, 0x7f, 0x3f, 0x1f, 0x4f, 0xc7, 0xe7, 0x67, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 
0x67, 0xe7, 0x47, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa7, 0xb7, 0xb7, 0xb7, 0xa7, 0xb7, 0x37, 
0x67, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xfd, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
0x00, 0xc0, 0x21, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0f, 0x9f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0x7f, 
0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x1f, 0x03, 0x60, 0x7c, 0x9e, 0x84, 0x80, 0x80, 0xf4, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xfc, 
0xfe, 0xf4, 0x80, 0x80, 0x86, 0x9f, 0x7c, 0x60, 0x03, 0x0f, 0xff, 0xb7, 0xab, 0xaf, 0xaf, 0xb7, 
0xbb, 0xab, 0xb7, 0xff, 0xff, 0x59, 0x55, 0x55, 0x55, 0x15, 0x55, 0x55, 0xb9, 0xff, 0xff, 0x6f, 
0x6f, 0x6f, 0x6f, 0x6f, 0x6f, 0x6f, 0x47, 0xff, 0xff, 0xcb, 0xab, 0xab, 0xcb, 0xab, 0xaa, 0xa9, 
0xcd, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x83, 0x8d, 0x03, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x00, 
0x00, 0x00, 0x00, 0xe0, 0x00, 0x60, 0x80, 0x80, 0x94, 0x95, 0x95, 0xfc, 0x03, 0x01, 0x00, 0x40, 
0x00, 0x80, 0x00, 0x00, 0x01, 0x03, 0x85, 0x4d, 0xf9, 0xf1, 0x7b, 0xfb, 0x77, 0xef, 0x1f, 0xff, 
0xf8, 0xc0, 0x06, 0x3e, 0x79, 0x21, 0x01, 0x01, 0x2f, 0x7f, 0x3f, 0x1f, 0x1f, 0x1f, 0x1f, 0x3f, 
0x7f, 0x2f, 0x01, 0x01, 0x61, 0xf9, 0x3e, 0x06, 0xc0, 0xf0, 0xff, 0xcc, 0xea, 0xea, 0xea, 0xca, 
0xea, 0xea, 0xcc, 0xff, 0xff, 0x55, 0x55, 0x55, 0x55, 0x99, 0x55, 0x55, 0x59, 0xff, 0xff, 0xe5, 
0xf5, 0xf5, 0xf4, 0xe5, 0xf5, 0xf5, 0xe5, 0xff, 0xff, 0xaa, 0xaa, 0xaa, 0xaa, 0x8c, 0xaa, 0xaa, 
0xdc, 0xff, 0xff, 0xff, 0x03, 0x01, 0x81, 0xa1, 0xc0, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x00, 0x20, 0x60, 0x60, 0x00, 0x20, 0x00, 0x01, 0x23, 0x00, 
0x00, 0x00, 0x06, 0x08, 0x00, 0x0e, 0x01, 0x01, 0x29, 0xa9, 0xa9, 0x3f, 0xc0, 0x80, 0x00, 0x02, 
0x00, 0x01, 0x00, 0x00, 0x80, 0xc0, 0xa0, 0xb2, 0x9d, 0x8b, 0xcd, 0xdf, 0xed, 0xf5, 0xf8, 0xff, 
0xff, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xf2, 0xe3, 0xe7, 0xe6, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 
0xe6, 0xe7, 0xe2, 0xf0, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcd, 0xea, 0xee, 0xee, 0xce, 0xee, 0xea, 
0xcd, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xdf, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x02, 0x84, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf9, 0xfc, 0xfe, 0xff, 0xff, 0xff, 0xfe, 
0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
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
        if (get_mods() & MOD_MASK_SHIFT) {
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
      send_unicode_string("¿");
      return false;
      break;
    case EURO:
      send_unicode_string("€");
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
