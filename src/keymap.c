#include QMK_KEYBOARD_H
#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layers {
    BASE,
    SYMB,
    MDIA,
};

// Software mappings
// these may be different depending on the target so a software mapping seems more robust
#define SM_EURO KC_NO // €
#define SM_AE KC_NO // Ä
#define SM_OE KC_NO // Ö
#define SM_UE KC_NO // Ü
#define SM_SS KC_NO // ß
#define SM_SSH KC_NO // Screenshot
#define SM_SSHC KC_NO // Screenshot to clipboard

// Custom keys (aliases)
#define CC_TILD LSFT(KC_GRV) // ~
#define CC_PIPE LSFT(KC_BSLS) // |
#define CC_PLUS LSFT(KC_EQL) // +
#define CC_LBRS LSFT(KC_LBRC) // {
#define CC_RBRS LSFT(KC_RBRC) // }
#define CC_PERC LSFT(KC_5) // %
#define CC_CART LSFT(KC_6) // ^
#define CC_UNDS LSFT(KC_MINS) // _

// Base layer home row
#define HM_A MT(MOD_LGUI, KC_A) // A
#define HM_S MT(MOD_LALT, KC_S) // S
#define HM_D MT(MOD_LSFT, KC_D) // D
#define HM_F MT(MOD_LCTL, KC_F) // F
#define HM_J MT(MOD_RCTL, KC_J) // J
#define HM_K MT(MOD_RSFT, KC_K) // K
#define HM_L MT(MOD_LALT, KC_L) // L
#define HM_SCLN MT(MOD_RGUI, KC_SCLN) // ;

// Symbol layer home row
#define HM_1 MT(MOD_LGUI, LSFT(KC_1)) // !
#define HM_2 MT(MOD_LALT, LSFT(KC_2)) // @
#define HM_3 MT(MOD_LSFT, LSFT(KC_3)) // #
#define HM_4 MT(MOD_LCTL, LSFT(KC_4)) // $
#define HM_7 MT(MOD_RCTL, LSFT(KC_7)) // &
#define HM_8 MT(MOD_RSFT, LSFT(KC_8)) // *
#define HM_9 MT(MOD_LALT, LSFT(KC_9)) // (
#define HM_0 MT(MOD_RGUI, LSFT(KC_0)) // )

// Layer keys
#define MO_SYMB MO(SYMB) // Momenttary Symbols Layer
#define MO_MDIA MO(MDIA) // Momentary Media Layer
#define TO_BASE TO(BASE) // Toggle Base Layer
#define TO_SYMB TO(SYMB) // Toggle Symbols Layer
#define TO_MDIA TO(MDIA) // Toggle Media Layer

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    RGB_SLD = ML_SAFE_RANGE,
    ST_MACRO_0,
    ST_MACRO_1,
    ST_MACRO_2,
    ST_MACRO_3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , XXXXXXX ,           XXXXXXX , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , XXXXXXX ,           XXXXXXX , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         KC_DEL  , HM_A    , HM_S    , HM_D    , HM_F    , KC_G    , TO_SYMB ,           TO_MDIA , KC_H    , HM_J    , HM_K    , HM_L    , HM_SCLN , KC_BSPC ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,                               KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /*****/   XXXXXXX ,           SM_SSH  , /*****/   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 KC_SPC  , MO_SYMB , XXXXXXX ,           XXXXXXX , MO_MDIA , KC_ENT  ),
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

    [SYMB] = LAYOUT(
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , XXXXXXX ,           XXXXXXX , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , KC_GRV  , CC_TILD , SM_EURO , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , CC_PIPE  , KC_MINS, CC_PLUS , CC_LBRS , CC_RBRS , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , HM_1    , HM_2    , HM_3    , HM_4    , CC_PERC , TO_MDIA ,           TO_BASE , CC_CART , HM_7    , HM_8    , HM_9    , HM_0    , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , SM_AE   , SM_OE   , SM_UE   , SM_SS   , XXXXXXX ,                               KC_BSLS , CC_UNDS , KC_EQL  , KC_LBRC  , KC_RBRC, XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /*****/   XXXXXXX ,           XXXXXXX , /*****/   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , MO_MDIA , XXXXXXX ),
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

    [MDIA] = LAYOUT(
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX  , KC_MUTE, KC_VOLD , KC_VOLU , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_BASE ,           TO_SYMB , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                               XXXXXXX , XXXXXXX , KC_BRID , KC_BRIU , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , /*****/   XXXXXXX ,           XXXXXXX , /*****/   XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX ),
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

};


/**
 * Key Combos:
 * F11 = F1 + F10
 * F12 = F2 + F10
 * ESC = J + K
 * ESC = F + D
 */
const uint16_t PROGMEM combo0[] = { KC_F1, KC_F10, COMBO_END };
const uint16_t PROGMEM combo1[] = { KC_F2, KC_F10, COMBO_END };
const uint16_t PROGMEM combo2[] = { HM_J, HM_K, COMBO_END };
const uint16_t PROGMEM combo3[] = { HM_F, HM_D, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_F11),
    COMBO(combo1, KC_F12),
    COMBO(combo2, KC_ESC),
    COMBO(combo3, KC_ESC),
};

// TODO: custom rgb matrix
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define WHITE	{255,255,255}
#define BLACK	{0,0,0}
#define RED	{255,0,0}
#define GREEN	{0,255,0}
#define BLUE	{0,0,255}
#define YELLOW	{255,255,0}
#define CYAN	{0,255,255}
#define PINK	{255,0,255}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = {
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    , RED     ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         BLUE    , YELLOW  , CYAN    , PINK    , RED     , GREEN   , BLUE    ,           BLACK   , BLACK   , WHITE   , WHITE   , BLACK   , WHITE   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         CYAN    , PINK    , RED     , GREEN   , BLUE    , YELLOW  , CYAN    ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    ,                               BLACK   , WHITE   , WHITE   , BLACK   , BLACK   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , /*****/   WHITE   ,           BLACK   , /*****/   BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 WHITE   , WHITE   , WHITE   ,           WHITE   , BLACK   , WHITE   },
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

    [SYMB] = {
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    , RED     ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         BLUE    , YELLOW  , CYAN    , PINK    , RED     , GREEN   , BLUE    ,           BLACK   , BLACK   , WHITE   , WHITE   , BLACK   , WHITE   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         CYAN    , PINK    , RED     , GREEN   , BLUE    , YELLOW  , CYAN    ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    ,                               BLACK   , WHITE   , WHITE   , BLACK   , BLACK   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , /*****/   WHITE   ,           BLACK   , /*****/   BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 WHITE   , WHITE   , WHITE   ,           WHITE   , BLACK   , WHITE   },
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

    [MDIA] = {
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    , RED     ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         BLUE    , YELLOW  , CYAN    , PINK    , RED     , GREEN   , BLUE    ,           BLACK   , BLACK   , WHITE   , WHITE   , BLACK   , WHITE   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         CYAN    , PINK    , RED     , GREEN   , BLUE    , YELLOW  , CYAN    ,           WHITE   , WHITE   , BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , GREEN   , BLUE    , YELLOW  , CYAN    , PINK    ,                               BLACK   , WHITE   , WHITE   , BLACK   , BLACK   , WHITE   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , /*****/   WHITE   ,           BLACK   , /*****/   BLACK   , BLACK   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 WHITE   , WHITE   , WHITE   ,           WHITE   , BLACK   , WHITE   },
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
};

void transform_ledmap(const uint8_t source[RGB_MATRIX_LED_COUNT][3], const uint8_t mapping[RGB_MATRIX_LED_COUNT], uint8_t output[RGB_MATRIX_LED_COUNT][3]) {
    // For each LED
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        // Get the new position from the mapping array
        uint8_t new_pos = mapping[i];
        
        // Copy RGB values to new position
        output[new_pos][0] = source[i][0];  // R
        output[new_pos][1] = source[i][1];  // G
        output[new_pos][2] = source[i][2];  // B
    }
}

void set_layer_color(int layer) {
  uint8_t transformed[RGB_MATRIX_LED_COUNT][3];

    // who tf arranged the LEDs like this?
    static const uint8_t led_mapping[RGB_MATRIX_LED_COUNT] = {
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         0       , 5       , 10      , 15      , 20      , 25      , 30      ,           65      , 61      , 56      , 51      , 46      , 41      , 36      ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         1       , 6       , 11      , 16      , 21      , 26      , 32      ,           66      , 62      , 57      , 52      , 47      , 42      , 37      ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         2       , 7       , 12      , 17      , 22      , 27      , 31      ,           67      , 63      , 58      , 53      , 48      , 43      , 38      ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         3       , 8       , 13      , 18      , 23      , 28      ,                               64      , 59      , 54      , 49      , 44      , 39      ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         4       , 9       , 14      , 19      , 24      , /*****/   35      ,           71      , /*****/   60      , 55      , 50      , 45      , 40      ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 32      , 33      , 34      ,           70      , 69      , 68      };
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

  transform_ledmap(ledmap[layer], led_mapping, transformed);

  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&transformed[i][0]),
      .g = pgm_read_byte(&transformed[i][1]),
      .b = pgm_read_byte(&transformed[i][2]),
    };
    float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
    rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );   
  }
}

bool rgb_matrix_indicators_user(void) {
  // TODO: rawhid is undeclared - also I have no idea what the fuck this is doing
  /* if (rawhid_state.rgb_control) { */
  /*     return false; */
  /* } */
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
    if (keycode == RGB_SLD) {
        /* if (rawhid_state.rgb_control) { */
        /*     return false; */
        /* } */
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
        case VRSN:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        /* case ST_MACRO_0: */
        /*     SEND_STRING(SS_LALT(SS_TAP(X_2) )); */
        /*     return true; */
        /* case ST_MACRO_1: */
        /*     SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_A)); */
        /*     return true; */
        /* case ST_MACRO_2: */
        /*     SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_O)); */
        /*     return true; */
        /* case ST_MACRO_3: */
        /*     SEND_STRING(SS_LALT(SS_TAP(X_U)) SS_DELAY(100) SS_TAP(X_U)); */
        /*     return true; */
        }
    }
    return true;
};
