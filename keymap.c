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
    // ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , KC_1         , KC_2         , KC_3         , KC_4         , KC_5         , XXXXXXX      ,                XXXXXXX      , KC_6         , KC_7         , KC_8         , KC_9         , KC_0         , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         KC_TAB       , KC_Q         , KC_W         , KC_E         , KC_R         , KC_T         , XXXXXXX      ,                XXXXXXX      , KC_Y         , KC_U         , KC_I         , KC_O         , KC_P         , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         KC_DEL       , HM_A         , HM_S         , HM_D         , HM_F         , KC_G         , TO_SYMB      ,                TO_MDIA      , KC_H         , HM_J         , HM_K         , HM_L         , HM_SCLN      , KC_BSPC      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , KC_Z         , KC_X         , KC_C         , KC_V         , KC_B         ,                                              KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , /* empty  */   XXXXXXX      ,                SM_SSH       , /* empty  */   XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
    // ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
                                                                     KC_SPC       , MO_SYMB      , XXXXXXX      ,                XXXXXXX      , MO_MDIA      , KC_ENT       ),
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    //                                                             ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛

    [SYMB] = LAYOUT(
    // ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , KC_F1        , KC_F2        , KC_F3        , KC_F4        , KC_F5        , XXXXXXX      ,                XXXXXXX      , KC_F6        , KC_F7        , KC_F8        , KC_F9        , KC_F10       , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , KC_GRV       , CC_TILD      , SM_EURO      , XXXXXXXX     , XXXXXXXX     , XXXXXXX      ,                XXXXXXX      , CC_PIPE       , KC_MINS     , CC_PLUS      , CC_LBRS      , CC_RBRS      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXXX     , HM_1         , HM_2         , HM_3         , HM_4         , CC_PERC      , TO_MDIA      ,                TO_BASE      , CC_CART      , HM_7         , HM_8         , HM_9         , HM_0         , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , SM_AE        , SM_OE        , SM_UE        , SM_SS        , XXXXXXX      ,                                              KC_BSLS      , CC_UNDS      , KC_EQL       , KC_LBRC       , KC_RBRC     , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , /* empty  */   XXXXXXX      ,                XXXXXXX      , /* empty  */   XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
    // ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
                                                                     XXXXXXX      , XXXXXXX      , XXXXXXX      ,                XXXXXXX      , MO_MDIA      , XXXXXXX      ),
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    //                                                             ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛

    [MDIA] = LAYOUT(
    // ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,                XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,                XXXXXXX      , XXXXXXX       , KC_MUTE     , KC_VOLD      , KC_VOLU      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , TO_BASE      ,                TO_SYMB      , XXXXXXX      , KC_MPRV      , KC_MPLY      , KC_MNXT      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,                                              XXXXXXX      , XXXXXXX      , KC_BRID      , KC_BRIU      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃              ┃                                            ┃              ┃              ┃              ┃              ┃              ┃              ┃
    // ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┓              ┏━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
         XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , /* empty  */   XXXXXXX      ,                XXXXXXX      , /* empty  */   XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      , XXXXXXX      ,
    // ┃              ┃              ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃ /**********/ ┃              ┃              ┃              ┃              ┃              ┃
    // ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫              ┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
                                                                     XXXXXXX      , XXXXXXX      , XXXXXXX      ,                XXXXXXX      , XXXXXXX      , XXXXXXX      ),
    //                                                             ┃              ┃              ┃              ┃              ┃              ┃              ┃              ┃
    //                                                             ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛              ┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛

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


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {86,255,255}, {172,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,255,255}, {86,255,255}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {172,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {86,255,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {86,255,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {172,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,255,255}, {86,255,255}, {0,255,255}, {0,0,0}, {43,255,255} },

    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {0,0,255}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {0,0,255}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {0,0,255}, {0,0,0}, {0,0,255}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {86,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {0,0,0}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,255}, {86,255,255}, {86,255,255}, {86,255,255}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
