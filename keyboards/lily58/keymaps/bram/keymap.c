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
  _______, _______,  KC_GRV, KC_CIRC, KC_HASH, KC_PERC, _______, _______, KC_ASTR, KC_PLUS, KC_AT, _______, INIT_QUES, _______, \
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
  _______, _______, _______, _______,  KC_F11,  KC_F12, _______,  UC_MOD, _______, _______, KC_LCTRL, KC_RALT, _______, _______, \
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
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
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
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
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
