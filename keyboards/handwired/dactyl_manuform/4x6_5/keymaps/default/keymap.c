#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

//#define GUI_SLS  LGUI(KC_SLSH)
//#define GUI_ENT  LGUI(KC_ENT)
#define GUI_TAB  LGUI_T(KC_TAB)

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum {
    TD1 = 1,
    TD2 = 2,
    TD3 = 3,
    TD4 = 4,
    TD5 = 5,
    TD6 = 6,
    TD7 = 7,
    TD8 = 8,
    TD9 = 9,
    TD10 = 10,
    TD11 = 11
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD1] = ACTION_TAP_DANCE_DOUBLE(KC_EXCLAIM, KC_AT),
    [TD2] = ACTION_TAP_DANCE_DOUBLE(KC_HASH, KC_DOLLAR),
    [TD3] = ACTION_TAP_DANCE_DOUBLE(KC_PERCENT, KC_CIRCUMFLEX),
    [TD4] = ACTION_TAP_DANCE_DOUBLE(KC_AMPERSAND, KC_ASTERISK),
    [TD5] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD6] = ACTION_TAP_DANCE_DOUBLE(KC_MINUS, KC_EQUAL),
    [TD7] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
    [TD8] = ACTION_TAP_DANCE_DOUBLE(KC_BSLASH, KC_SLASH),
    [TD9] = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON, KC_QUOTE),
    [TD10] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT),
    [TD11] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_DOT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* Base (qwerty)
	 * +-----------------------------------------+                             +-----------------------------------------+
	 * | TAB  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  | DEL  |
	 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
	 * | SHFT |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |  '   |
	 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
	 * | CTRL |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |ENTER |
	 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
	 *                      |lower | spc  | alt  |                             | gui  | bspc |raise |
	 *                      +------+------+------+                             +------+------+------+
	 */

    /*
       Colemak DHm
	[_BASE] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          GUI_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,   KC_DEL,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   KC_O, KC_QUOT,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,KC_ENTER,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, KC_LALT,  KC_SPC, KC_LGUI, KC_MPLY,    KC_MUTE, KC_LALT, KC_BSPC,  KC_LGUI,  RAISE \
		                                  //|--------------------------|  |--------------------------|
	),
    */
	[_BASE] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
          GUI_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_DEL,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCOLON, KC_QUOT,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,KC_ENTER,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, KC_LALT,  KC_SPACE, KC_LGUI, XXXXXXX,    XXXXXXX, KC_LALT, KC_BSPACE,  KC_ENTER,  RAISE \
		                                  //|--------------------------|  |--------------------------|
	),


	[_LOWER] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		  KC_TILD, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,                      XXXXXXX, TD(TD2), XXXXXXX, XXXXXXX, XXXXXXX, RESET  ,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, XXXXXXX,                      TD(TD3), TD(TD1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, KC_LALT,  KC_SPACE, KC_LGUI, XXXXXXX,    XXXXXXX, KC_LALT, KC_BSPACE,  KC_ENTER,  RAISE \
		                                  //|--------------------------|  |--------------------------|
	),
    /*
	[_LOWER_OLD] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		  KC_TILD, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,                      XXXXXXX, TD(TD2), XXXXXXX, KC_WH_U, XXXXXXX, RESET  ,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_WH_R, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL, KC_PGUP, KC_PGDN, KC_HOME,  KC_END, XXXXXXX,                      TD(TD3), TD(TD1), KC_WH_L, KC_WH_D, KC_PSCR, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, KC_LALT,  KC_SPC, KC_LGUI, KC_MPLY,    KC_MUTE, KC_LALT, KC_BSPC, GUI_ENT,  RAISE \
		                                  //|--------------------------|  |--------------------------|
	),
    */
	[_RAISE] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_MINUS, KC_EQUAL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT, TD(TD1), TD(TD2), TD(TD3), TD(TD4), TD(TD5),                       TD(TD6),  TD(TD7), TD(TD8), TD(TD9), TD(TD10), TD(TD11),\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, KC_LALT,  KC_SPACE, KC_LGUI, XXXXXXX,    XXXXXXX, KC_LALT, KC_BSPACE,  KC_ENTER,  RAISE \
		                                  //|--------------------------|  |--------------------------|       
	)

/*
	[_RAISE] = LAYOUT( \
	  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
		   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LSFT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		  KC_LCTL,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MPRV, KC_MNXT, KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX,\
	  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
		                      LOWER, GUI_SLS,  KC_SPC, KC_LGUI, KC_MPLY,    KC_MUTE, KC_LALT, KC_BSPC,  KC_LGUI,  RAISE \
		                                  //|--------------------------|  |--------------------------|       
	)
    */
};


void persistent_default_layer_set(uint16_t default_layer) {
	  eeconfig_update_default_layer(default_layer);
	  default_layer_set(default_layer);
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
