/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef DEBOUNCE
#define DEBOUNCE 5

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 128

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 50

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 30

#define AUTO_SHIFT_TIMEOUT 200
#define HOLD_ON_OTHER_KEY_PRESS
#define SERIAL_NUMBER "QmM9p/5WW9Jw"
#define LAYER_STATE_8BIT

#define TAPPING_TERM_PER_KEY
#define RGB_MATRIX_STARTUP_SPD 60

#define PERMISSIVE_HOLD
