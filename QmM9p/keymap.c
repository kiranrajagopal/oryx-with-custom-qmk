#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
};

void housekeeping_task_user(void) {
  achordion_task();
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  return 200;  // Default of 100 ms.
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_LEFT_ALT,    KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_RIGHT_ALT,   
    KC_LEFT_CTRL,   KC_A,           MT(MOD_LSFT, KC_S),MT(MOD_LALT, KC_D),MT(MOD_LCTL, KC_F),KC_G,                                           KC_H,           MT(MOD_RCTL, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RSFT, KC_L),LT(3,KC_SCLN),  KC_RIGHT_CTRL,  
    KC_LEFT_GUI,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       TG(1),          
                                                    MT(MOD_RGUI, KC_ENTER),MT(MOD_LSFT, KC_TAB),                                LT(1,KC_BSPC),  LT(2,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT,                                 KC_PAGE_UP,     KC_HOME,        LGUI(KC_TAB),   LGUI(KC_GRAVE), KC_PLUS,        KC_PIPE,        
    KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_COLN,        KC_DQUO,        
    KC_TRANSPARENT, KC_MS_WH_RIGHT, KC_MS_BTN4,     KC_MS_BTN3,     KC_MS_BTN5,     KC_MS_WH_UP,                                    KC_PGDN,        KC_END,         LGUI(LSFT(KC_LBRC)),LGUI(LSFT(KC_RBRC)),KC_RIGHT_SHIFT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_SLD,        RGB_VAD,        RGB_VAI,                                        KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE,KC_PAUSE,       QK_BOOT,        KC_MEDIA_STOP,  
    KC_TRANSPARENT, KC_GRAVE,       KC_MINUS,       KC_EQUAL,       KC_COMMA,       KC_DOT,                                         KC_0,           KC_1,           KC_2,           KC_3,           KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SCLN,        KC_QUOTE,       KC_BSLS,        KC_LPRN,        KC_RPRN,                                        KC_COMMA,       KC_4,           KC_5,           KC_6,           KC_SCLN,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,                                        KC_DOT,         KC_7,           KC_8,           KC_9,           KC_SLASH,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_5,     ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_9,                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_S):
        case MT(MOD_LALT, KC_D):
        case MT(MOD_LCTL, KC_F):
        case MT(MOD_RCTL, KC_J):
        case MT(MOD_RALT, KC_K):
        case MT(MOD_RSFT, KC_L):
            return TAPPING_TERM + 100;
        case LT(1,KC_BSPC):
        case LT(2,KC_SPACE):
            return TAPPING_TERM - 50;
        case MT(MOD_RGUI, KC_ENTER):
            return TAPPING_TERM ;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255} },

    [1] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [2] = { {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146}, {3,255,255}, {3,255,255}, {3,255,255}, {3,255,255}, {91,192,146}, {91,192,146}, {91,192,146}, {3,255,255}, {3,255,255}, {3,255,255}, {91,192,146}, {91,192,146}, {91,192,146}, {3,255,255}, {3,255,255}, {3,255,255}, {91,192,146}, {91,192,146}, {91,192,146}, {91,192,146} },

    [3] = { {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240}, {41,249,240} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCLN)) SS_DELAY(100) SS_TAP(X_W) SS_DELAY(100) SS_TAP(X_Q)  SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_UP));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_P));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_N));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_DOWN));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_TAP(X_RIGHT));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LSFT(SS_TAP(X_NUBS)));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_RCTL(SS_TAP(X_A)) SS_DELAY(100) SS_LSFT(SS_TAP(X_MINUS)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



