#include QMK_KEYBOARD_H
#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum layers {
    BASE,
    SYMB,
    MDIA,
};

enum unicode_names {
    UN_AELO,   // ä
    UN_AEUP,   // Ä
    UN_OELO,   // ö
    UN_OEUP,   // Ö
    UN_UELO,   // ü
    UN_UEUP,   // Ü
    UN_SZ  ,   // ß
    UN_EURO,   // €
    UN_POUN,   // £
};

const uint32_t PROGMEM unicode_map[] = {
    [UN_AELO]    = 0x00E4, // ä
    [UN_AEUP]    = 0x00C4, // Ä
    [UN_OELO]    = 0x00F6, // ö
    [UN_OEUP]    = 0x00D6, // Ö
    [UN_UELO]    = 0x00FC, // ü
    [UN_UEUP]    = 0x00DC, // Ü
    [UN_SZ  ]    = 0x00DF, // ß
    [UN_EURO]    = 0x20AC, // €
    [UN_POUN]    = 0x00A3, // £
};

#define UC_AE   UP(UN_AELO, UN_AEUP)
#define UC_OE   UP(UN_OELO, UN_OEUP)
#define UC_UE   UP(UN_UELO, UN_UEUP)
#define UC_SZ   UM(UN_SZ           )
#define UC_CURR UP(UN_EURO, UN_POUN)

#define CC_TILD LSFT(KC_GRV ) // ~
#define CC_PIPE LSFT(KC_BSLS) // |
#define CC_PLUS LSFT(KC_EQL ) // +
#define CC_LBRS LSFT(KC_LBRC) // {
#define CC_RBRS LSFT(KC_RBRC) // }
#define CC_PERC LSFT(KC_5   ) // %
#define CC_CART LSFT(KC_6   ) // ^
#define CC_UNDS LSFT(KC_MINS) // _

#define MO_SYMB MO(SYMB) // Momenttary Symbols Layer
#define MO_MDIA MO(MDIA) // Momentary Media Layer

#define TO_BASE TO(BASE) // Toggle Base Layer
#define TO_SYMB TO(SYMB) // Toggle Symbols Layer
#define TO_MDIA TO(MDIA) // Toggle Media Layer

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃/* q Q */┃/* w W */┃/* e E */┃/* r R */┃/* t T */┃         ┃         ┃         ┃/* y Y */┃/* u U */┃/* i I */┃/* o O */┃/* p P */┃/*  󰌍  */┃
         KC_DEL  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , TO_SYMB ,           TO_MDIA , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃/*  󰘶  */┃/ a A */ ┃/* s S */┃/* d D */┃/* f F */┃/* g G */┃/*  󰌒  */┃         ┃         ┃/* h H */┃/* j J */┃/* k K */┃/* l L */┃/* ; : */┃/*  󰘶  */┃
         KC_LSFT , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_TAB  ,           XXXXXXX , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_RSFT ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃/* z Z */┃/* x X */┃/* c C */┃/* v V */┃/* b B */┃                             ┃/* n N */┃/* m M */┃/* , < */┃/* . > */┃/* / ? */┃         ┃
         XXXXXXX , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    ,                               KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃/*  󰘴  */┃/*  󰘵  */┃/*  󰘳  */┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃/*  󰘳  */┃/*  󰘵  */┃/*  󰘴  */┃         ┃         ┃
         XXXXXXX , XXXXXXX , KC_LCTL , KC_LALT , KC_LGUI , /*****/   XXXXXXX ,           XXXXXXX , /*****/   KC_RGUI , KC_LALT , KC_RCTL , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃/*  󱁐  */┃         ┃         ┃         ┃         ┃         ┃/*  󰌑  */┃
                                                 KC_SPC  , MO_SYMB , XXXXXXX ,           XXXXXXX , MO_MDIA , KC_ENT  ),
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    //                                         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛         ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛

    [SYMB] = LAYOUT(
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃/*  `  */┃/*  ~  */┃         ┃         ┃         ┃/*    */┃         ┃/*    */┃/*  |  */┃/*  -  */┃/*  +  */┃/*  {  */┃/*  }  */┃         ┃
         XXXXXXX , KC_GRV  , CC_TILD , XXXXXXX , XXXXXXX , XXXXXXX , UC_MAC  ,           UC_LINX , CC_PIPE , KC_MINS , CC_PLUS , CC_LBRS , CC_RBRS , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃/*  󰘶  */┃/* 1 ! */┃/* 2 @ */┃/* 3 # */┃/* 4 $ */┃/* 5 % */┃         ┃         ┃         ┃/* 6 ^ */┃/* 7 & */┃/* 8 * */┃/* 9 ( */┃/* 0 ) */┃/*  󰘶  */┃
         KC_LSFT , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , TO_MDIA ,           TO_BASE , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_RSFT ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃/* ä Ä */┃/* ö Ö */┃/* ü Ü */┃/*  ß  */┃/* € £ */┃                             ┃/*  \  */┃/*  _  */┃/*  =  */┃/*  [  */┃/*  ]  */┃         ┃
         XXXXXXX , UC_AE   , UC_OE   , UC_UE   , UC_SZ   , UC_CURR ,                               KC_BSLS , CC_UNDS , KC_EQL  , KC_LBRC , KC_RBRC , XXXXXXX ,
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
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃/*    */┃/*    */┃/*    */┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,           XXXXXXX , XXXXXXX , KC_VOLD , KC_MUTE , KC_VOLU , XXXXXXX , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃/*  󰒮  */┃/*  󰐊  */┃/*  󰒭  */┃/*    */┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , TO_BASE ,           TO_SYMB , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT , KC_MSTP , XXXXXXX ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃/*  󰃞  */┃         ┃/*  󰃠  */┃         ┃         ┃
         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                               XXXXXXX , KC_BRID , XXXXXXX , KC_BRIU , XXXXXXX , XXXXXXX ,
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
const uint16_t PROGMEM combo2[] = { KC_J,  KC_K,   COMBO_END };
const uint16_t PROGMEM combo3[] = { KC_F,  KC_D,   COMBO_END };
const uint16_t PROGMEM combo4[] = { KC_K,  KC_L,   COMBO_END };
const uint16_t PROGMEM combo5[] = { KC_S,  KC_D,   COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_F11),
    COMBO(combo1, KC_F12),
    COMBO(combo2, KC_ESC),
    COMBO(combo3, KC_ESC),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

#define WHITE   {255, 255, 255}
#define BLACK   {  0,   0,   0}
#define RED     {255,   0,   0}
#define GREEN   {  0, 255,   0}
#define BLUE    {  0,   0, 255}
#define YELLOW  {255, 255,   0}
#define CYAN    {  0, 255, 255}
#define PINK    {255,   0, 255}
#define DRKVLT  {148,   0, 211}
#define IRIS    { 93,  63, 211}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [BASE] = {
    // ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓         ┏━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┳━━━━━━━━━┓
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         BLACK   , BLACK   , BLACK   , BLACK   , BLACK   , BLACK   , BLACK   ,           BLACK   , BLACK   , BLACK   , BLACK   , BLACK   , BLACK   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         RED     , WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , GREEN   ,           GREEN   , WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , RED     ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         IRIS    , WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , RED     ,           RED     , WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , IRIS    ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┛         ┗━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
         BLACK   , WHITE   , WHITE   , WHITE   , WHITE   , WHITE   ,                               WHITE   , WHITE   , WHITE   , WHITE   , WHITE   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃                             ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┓         ┏━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
         BLACK   , BLACK   , IRIS    , IRIS    , IRIS    , /*****/   BLACK   ,           DRKVLT  , /*****/   IRIS    , IRIS    , IRIS    , BLACK   , BLACK   ,
    // ┃         ┃         ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃ /*****/ ┃         ┃         ┃         ┃         ┃         ┃
    // ┗━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┻━━━━━━━━━┛
    //                                         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
                                                 RED     , GREEN   , BLACK   ,           BLACK   , GREEN   , RED     },
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
         0       , 5       , 10      , 15      , 20      , 25      , 29      ,           65      , 61      , 56      , 51      , 46      , 41      , 36      ,
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
    // ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫         ┣━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━╋━━━━━━━━━┫
    // ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃         ┃
         1       , 6       , 11      , 16      , 21      , 26      , 30      ,           66      , 62      , 57      , 52      , 47      , 42      , 37      ,
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
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    }
    return true;
};
