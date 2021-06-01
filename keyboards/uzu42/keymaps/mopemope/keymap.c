#include QMK_KEYBOARD_H
#include "uzu42.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif


#ifdef RGBLIGHT_ENABLE
#include <stdio.h>
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif
#include "keymap_jp.h"

#define QGMLWY  0
#define LOWER   1
#define RAISE   2
#define MISCL   3
#define MISCR   4
#define COMBA   5
#define COMBN   6
#define COMBE   7
#define COMBT   8
#define CYBER   9
#define BL2    10
#define R6S    12
#define KOC    14
#define APEX1  16
#define APEX2  17
#define DIV1   20
#define DIV2   21
#define VAL1   22
#define EFT1   23
#define EFT2   24

#define ______ KC_TRNS
#define XXXXXX KC_NO

/* #define WRKSP1 LALT(LCTL(KC_UP)) */
/* #define WRKSP2 LALT(LCTL(KC_DOWN)) */
/* #define UWRKSP LSFT(LALT(LCTL(KC_UP))) */
/* #define DWRKSP LSFT(LALT(LCTL(KC_DOWN))) */
#define WRKSP1 LGUI(KC_PGUP)
#define WRKSP2 LGUI(KC_PGDN)
#define UWRKSP LSFT(LGUI(KC_PGUP))
#define DWRKSP LSFT(LGUI(KC_PGDN))
#define PREVTB LSFT(LCTL(KC_UP))
#define NEXTTB LSFT(LCTL(KC_DOWN))
#define CAF2   LALT(LCTL(KC_F2))
#define CAF7   LALT(LCTL(KC_F7))
#define PREVW  LGUI(LCTL(KC_LEFT))
#define NEXTW  LGUI(LCTL(KC_RIGHT))

#define TAB    KC_TAB
#define MINS   ALT_T(JP_MINS)
#define SMINS  SFT_T(JP_MINS)
#define SBSLS  SFT_T(JP_BSLS)
#define BSP    KC_BSPC
#define DEL    KC_DEL
#define SDEL   SFT_T(KC_DEL)
#define PSCR   KC_PSCR
#define SPSCR  LSFT(KC_PSCR)
#define RJ     LT(RAISE,KC_J)
#define LK     LT(LOWER,KC_K)
#define AC     LT(COMBA,KC_A)
#define NC     LT(COMBN,KC_N)
#define EC     LT(COMBE,KC_E)
#define KC     LT(COMBE,KC_K)
#define TC     LT(COMBT,KC_T)
#define SPC    LT(RAISE,KC_SPC)
#define CSPC   LCTL(KC_SPC)
#define CRET   LCTL(KC_ENT)
#define ENT    LT(LOWER,KC_ENT)
#define CENT   CTL_T(KC_ENT)
#define BSPC   RCTL_T(KC_BSPC)
#define SBSPC  SFT_T(KC_BSPC)
#define ABSPC  ALT_T(KC_BSPC)
#define CBSPC  CTL_T(KC_BSPC)
#define D_M    LT(MISCL,KC_D)
#define D_C    CTL_T(KC_D)
#define Z_A    ALT_T(KC_Z)
#define Z_C    CTL_T(KC_Z)
#define Z_S    LSFT_T(KC_Z)
#define I_S    LSFT_T(KC_I)
#define X_CT   LCTL_T(KC_X)
#define P_AL   LALT_T(KC_P)
#define J_C    RCTL_T(KC_J)
#define P_C    RCTL_T(KC_P)
#define A_C    RCTL_T(KC_A)
#define H_M    LT(MISCR,KC_H)
#define S_C    CTL_T(JP_SLSH)
#define S_S    RSFT_T(JP_SLSH)
#define V_A    LALT_T(KC_V)
#define O_C    CTL_T(KC_O)
#define AT_A   ALT_T(JP_AT)
#define AT_C   CTL_T(JP_AT)
#define GL     LGUI(KC_LEFT)
#define GU     LGUI(KC_UP)
#define GD     LGUI(KC_DOWN)
#define GR     LGUI(KC_RIGHT)
#define CLEFT  LCTL(KC_LEFT)
#define CUP    LCTL(KC_UP)
#define CDOWN  LCTL(KC_DOWN)
#define CRIGHT LCTL(KC_RIGHT)
#define MLEFT  LALT(KC_LEFT)
#define MUP    LALT(KC_UP)
#define MDOWN  LALT(KC_DOWN)
#define MRIGHT LALT(KC_RIGHT)
#define MLT    LALT(KC_LT)
#define MGT    LALT(KC_GT)
#define GH     LGUI(KC_H)
#define EXLM   JP_EXLM
#define DQT    JP_DQT
#define HASH   JP_HASH
#define DLR    JP_DLR
#define PERC   JP_PERC
#define AMPR   JP_AMPR
#define QUOT   JP_QUOT
#define GRV    JP_GRV
#define PIPE   JP_PIPE
#define YEN    JP_YEN
#define AT     JP_AT
#define LCBR   JP_LCBR
#define RCBR   JP_RCBR
#define UNDS   JP_UNDS
#define TILD   JP_TILD
#define EQL    JP_EQL
#define COLN   JP_COLN
#define SLSH   JP_SLSH
#define ASTR   JP_ASTR
#define LPRN   JP_LPRN
#define RPRN   JP_RPRN
#define BSLS   JP_BSLS
#define CIRC   CTL_T(JP_CIRC)
#define SCLN   JP_SCLN
#define COMM   JP_COMM
#define CCOM   LCTL(JP_COMM)
#define DOT    JP_DOT
#define CDOT   LCTL(JP_DOT)
#define MCOM   LALT(JP_COMM)
#define MDOT   LALT(JP_DOT)
#define PLUS   JP_PLUS
#define LBRC   JP_LBRC
#define RBRC   ALT_T(JP_RBRC)
#define GUI    KC_LGUI
#define ZHTG   JP_ZHTG
#define C_S    SFT_T(KC_C)
#define ESC    KC_ESC

#define DQG    DF(QGMLWY)
#define GBL2   DF(BL2)
#define GCYB   DF(CYBER)
#define GVAL   DF(VAL1)
#define GEFT   DF(EFT1)
#define GR6S   DF(R6S)
#define GDV2   DF(DIV1)
#define GAPEX  DF(APEX1)
#define GKOC   DF(KOC)

#define SELA   LCTL(KC_A)
#define COPY   LCTL(KC_C)
#define PASTE  LCTL(KC_V)
#define CZ     LCTL(KC_Z)
#define CSL    LCTL(JP_SLSH)
#define CMN    LALT(LCTL(KC_N))
#define CMM    LALT(LCTL(KC_M))
#define CMD    LALT(LCTL(JP_DOT))
#define CMY    LALT(LCTL(JP_YEN))
#define CG     LCTL(KC_G)
#define CQ     LCTL(KC_Q)
#define CT     LCTL(KC_T)
#define CJ     LCTL(KC_J)
#define CC     LCTL(KC_C)
#define CS     LCTL(KC_S)
#define CX     LCTL(KC_X)
#define CL     LCTL(KC_L)
#define CK     LCTL(KC_K)
#define CE     LCTL(KC_E)
#define CP     LCTL(KC_P)
#define CN     LCTL(KC_N)
#define CF     LCTL(KC_F)
#define CB     LCTL(KC_B)
#define CAT    LCTL(JP_AT)
#define MX     LALT(KC_X)
#undef  MD
#define MD     LALT(KC_D)
#define MSCLN  LALT(JP_SCLN)
#define APERC  LALT(JP_PERC)
#define CPIPE  LCTL(JP_PIPE)
#define CEXLM  LCTL(JP_EXLM)

#define WH_D   KC_WH_D
#define WH_U   KC_WH_U
#define PGDN   KC_PGDN
#define PGUP   KC_PGUP
#define MS_L   KC_MS_L
#define MS_U   KC_MS_U
#define MS_D   KC_MS_D
#define MS_R   KC_MS_R
#define KLEFT  KC_LEFT
#define KUP    KC_UP
#define KDOWN  KC_DOWN
#define KRIGHT KC_RIGHT
#define MUTE   KC_MUTE
#define VOLD   KC_VOLD
#define VOLU   KC_VOLU
#define BTN2   KC_BTN2
#define BTN1   KC_BTN1
#define ASTG   KC_ASTG
#define RTOG   RGB_TOG
#define RMOD   RGB_MOD
#define RRMOD  RGB_RMOD
#define RHUI   RGB_HUI
#define RHUD   RGB_HUD
#define RSAI   RGB_SAI
#define RSAD   RGB_SAD
#define RVAI   RGB_VAI
#define RVAD   RGB_VAD
#define CTL    OSM(MOD_RCTL)
#define ALT    OSM(MOD_LALT)
#define SFTZ   SFT_T(JP_ZHTG)
#define C_V    LCTL(KC_V)
#define M_V    LALT(KC_V)
#define ALTZ   LALT(KC_Z)
#define REC    LALT(KC_F9)
#define C_LT   LCTL(JP_LT)
#define C_GT   LCTL(JP_GT)
#define EFTS   LT(EFT2,KC_SPC)
#define R6_C   LT(R6S2,KC_C)
#define DI_C   LT(DIV2,KC_LCTL)
#define AP_I   LT(APEX2,KC_I)
#define GCTL   KC_LCTL
#define GALT   KC_LALT
#define AQ     LALT(KC_Q)
#define AE     LALT(KC_E)

enum custom_keycodes {
  CXCF = SAFE_RANGE,
  CXCB,
  CXCS,
  CXO,
  CXU,
  CCN,
  CCP,
  CCZ,
  CCX,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QGMLWY] = LAYOUT( \
     KC_Q,   KC_G,   KC_M,   KC_L,   KC_W,                       KC_Y,   KC_F,   KC_U,   KC_B,   BSP,    \
     D_M,    KC_S,   TC,     NC,     KC_R,                       KC_I,   AC,     EC,     KC_O,   H_M,    \
     Z_S,    X_CT,   KC_C,   V_A,    GUI,                        GUI,    J_C,    KC_K,   P_AL,   S_S,    \
     KC_LSFT,GCTL,   TAB,    GCTL,   ALT,   SPC,         ENT,    BSPC,   GALT,   TAB,    GALT,   KC_LSFT \
  ),

  [LOWER] = LAYOUT( \
     EXLM,   DQT,    HASH,   DLR,    PERC,                       AMPR,   QUOT,   GRV,    PIPE,   YEN,    \
     ESC,    LPRN,   RPRN,   LCBR,   RCBR,                       TILD,   DOT,    SLSH,   EQL,    AT,     \
     CIRC,   LBRC,   RBRC,   KC_LT,  KC_GT,                      ______, COMM,   ______, ______, ______, \
     CIRC,   ______, ______, ______, ______, KC_SPC,     ______, ______, ______, ______, ______, ______ \
  ),

  [RAISE] = LAYOUT( \
     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   \
     TAB,    KC_F1,  KC_F2,  KC_F3,  KC_F4,                      KC_F5,  KC_F12, KC_F7,  KC_F8,  AT,     \
     UNDS,   KC_F9,  KC_F10, KC_F11, ______,                     DOT,    KC_F6,  KC_LT,  KC_GT,  MINS,   \
     UNDS,   ______, ______, ______, ______, ______,     DOT,    ______, ______, ______, ______, MINS    \
  ),

  [MISCL] = LAYOUT( \
     RESET,  ______, KUP,    ______, WRKSP1,                     UWRKSP, PGDN,   GU,     PGUP,   DEL,    \
     ______, KLEFT,  KDOWN,  KRIGHT, WRKSP2,                     DWRKSP, GL,     GD,     GR,     GH,     \
     ______, ______, ______, ______, ENT,                        MLT,    MGT,    SPSCR,  ______, ______, \
     ______, ______, ______, COPY,   PASTE,  GUI,        TAB,    M_V,    ______, ______, ______, ______  \
  ),

  [MISCR] = LAYOUT( \
     RESET,  ______, ______, ______, PREVW,                      PREVTB, MLT,    KUP,    MGT,    DEL,    \
     TAB,    ______, ______, ______, NEXTW,                      NEXTTB, KLEFT,  KDOWN,  KRIGHT, ______, \
     ______, ______, ______, ______, ______,                     ______, ______, ______, ______, ______, \
     ______, ______, ______, ______, CXU,    KC_SPC,     BSP,    CXU,    ______, ______, ______, ______ \
  ),

  [COMBA] = LAYOUT(                                                     \
     CQ,     CG,     CMM,    CL,     APERC,                      ______, CXCF,   CXU,    CXCB,   ______,  \
     MD,     CXCS,   CT,     CMN,    MX,                         ______, ______, CCZ,    CXO,    CAT,     \
     CZ,     CX,     CC,     ______, ______,                     ______, ______, CK,     ______, ______,  \
     CZ,     ______, ______, ______, ______, ZHTG,       CCX,    ______, ______, ______, ______, ______   \
  ),

  [COMBN] = LAYOUT(                                                     \
     ______, CG,     ______, CL,     ______,                     ______, MCOM,   CP,     MDOT,   MD,     \
     TAB,    CS,     CT,     ______, ______,                     MSCLN,  CLEFT,  CN,     CRIGHT, CAT,    \
     ______, CX,     CRET,   CSPC,   ______,                     MCOM,   MDOT,   ______, ______, CXU,    \
     ______, ______, ______, ______, ______, ______,     CJ,     ______, ______, ______, ______, ______  \
  ),

  [COMBE] = LAYOUT(                                                     \
    CAF7,   ______, CUP,    ______, ______,                      DQG,    ______, ______, ______, ______, \
    CAF2,   CLEFT,  CDOWN,  CRIGHT, ______,                      ______, ______, ______, ______, ______, \
    PSCR,   ______, ______, ______, ______,                      ______, ______, ______, ______, ______, \
    ______, ______, ______, ______, ______, KC_SPC,      BSP,    ______, ______, ______, ______, ______  \
  ),

  [COMBT] = LAYOUT( \
    GCYB,   GBL2,   GR6S,   GKOC,   ______,                      DQT,    EXLM,   PLUS,   ASTR,   PIPE,   \
    ______, ______, ______, ______, ______,                      TILD,   EQL,    COLN,   SCLN,   AT,     \
    ______, ______, ______, ______, ______,                      ______, MINS,   COMM,   DOT,    SLSH,   \
    ______, ______, ______, RSAD,   RSAI,   RTOG,        ______, ______, ______, ______, ______, ______  \
  ),

  [VAL1] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        KC_1,   KC_2,   KC_3,   KC_4,   ______,  \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        KC_5,   KC_6,   KC_7,   KC_8,   ______,  \
    GCTL,   KC_X,   KC_C,   KC_M,   KC_COMM,                     ______, ______, ______, ______, ______,  \
    ______, ______, ______, ______, KC_C,   KC_SPC,      DQG,    ALTZ,   REC,    ______, ______, ______   \
  ),

  [EFT1] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        KC_6,   KC_7,   KC_0,   KC_9,   KC_0,   \
    KC_CAPS,KC_X,   KC_C,   KC_V,   KC_G,                        KC_O,   KC_T,   KC_B,   KC_N,   DEL,    \
    ______, ______, ______, GCTL,   GALT,   EFTS,        DQG,    ALTZ,   REC,    ______, ______, ______ \
  ),

  [EFT2] = LAYOUT( \
    ESC,    ______, ______, ______, XXXXXX,                      KC_1,   KC_2,   KC_3,  KC_4,    KC_5,   \
    ______, ______, ______, KC_L,   KC_U,                        KC_6,   KC_7,   KC_0,  KC_9,    KC_0,   \
    KC_Z,   ______, ______, ______, ______,                      KC_U,   KC_Y,   PGUP,  PGDN,    ______, \
    ______, ______, ______, ______, ______, ______,      ______, ______, ______, ______, ______, ______  \
  ),

  [CYBER] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        ______, KC_M,   KC_J,   KC_K,   ESC,    \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ______, KC_I,   KC_O,   KC_P,   ______, \
    KC_Z,   KC_X,   GALT,   KC_V,   KC_T,                        ______, ______, ______, KC_V,   KC_N,   \
    ______, ______, ______, KC_Z,   KC_C,   KC_SPC,      DQG,    ALTZ,   REC,    ______, ______, DQG     \
  ),

  [BL2] = LAYOUT( \
    TAB,    KC_G,   KC_W,   KC_E,   KC_R,                        ______, KC_F5,  KC_F6,  KC_F7,  ESC,     \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ______, KC_5,   KC_6,   KC_7,   ______,  \
    KC_C,   KC_Q,   KC_M,   KC_U,   KC_G,                        KC_Y,   KC_T,   KC_B,   KC_U,   ______,  \
    XXXXXX, XXXXXX, XXXXXX, KC_V,   KC_C,   KC_SPC,      KC_Z,   ALTZ,   REC,    XXXXXX, XXXXXX, DQG      \
  ),

  [R6S] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        ______, KC_F5,  KC_F6,  KC_F7,  ESC,     \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ______, KC_5,   KC_6,   KC_7,   ______,  \
    GALT,   KC_Z,   GCTL,   KC_U,   KC_G,                        KC_Y,   KC_T,   KC_B,   KC_U,   ______,  \
    KC_5,   KC_6,   KC_B,   KC_V,   KC_C,   KC_SPC,      KC_Z,   ALTZ,   REC,    XXXXXX, XXXXXX, DQG      \
  ),

  /* [R6S2] = LAYOUT( \ */
  /*   ESC,    KC_F5,  KC_F6,  KC_F7,  KC_Y,                        ______, ______, ______, ______, ______,  \ */
  /*   ______, KC_5,   KC_6,   KC_7,   KC_F,                        ______, ______, ______, ______, ______,  \ */
  /*   KC_Z,   KC_B,   KC_U,   ______, ______,                      ______, ______, ______, ______, ______,  \ */
  /*   XXXXXX, XXXXXX, XXXXXX, XXXXXX, ______, XXXXXX,      DQG,    XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX   \ */
  /* ), */

  [KOC] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        ______, ______, ______, ______, ______,  \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ESC,    ______, ______, ______, ______,  \
    GCTL,   XXXXXX, XXXXXX, XXXXXX, XXXXXX,                      KC_X,   ______, ______, ______, ______,  \
    XXXXXX, XXXXXX, XXXXXX, GALT,   GCTL,   KC_SPC,      DQG,    ALTZ,   REC,    XXXXXX, XXXXXX, DQG      \
  ),

  [APEX1] = LAYOUT(                                                                        \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        ______, ______, ______, ______, ______,  \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ______, KC_ENT, ______, ______, ______,  \
    KC_C,   KC_Z,   GCTL,   KC_X,   KC_G,                        ______, KC_T,   KC_B,   KC_N,   ______,  \
    ______, ______, ______, KC_V,   AP_I,   KC_SPC,      DQG,    ALTZ,   REC,    ______, ______, ______  \
  ),

  [APEX2] = LAYOUT(                                                                        \
    ESC,    KC_1,   KC_2,   KC_3,   KC_4,                        ______, ______, ______, ______, ______,  \
    KC_5,   KC_6,   KC_7,   KC_8,   KC_9,                        ______, ______, ______, ______, ______,  \
    KC_Z,   KC_M,   KC_H,   KC_N,   KC_B,                        ______, ______, ______, ______, ______,  \
    ______, ______, ______, ______, ______, ______,      DQG,     ALTZ,  REC,    ______, ______, ______  \
  ),

  [DIV1] = LAYOUT( \
    TAB,    KC_Q,   KC_W,   KC_E,   KC_R,                        ______, ______, ______, ______, ______,  \
    KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,                        ______, ______, ______, ______, ______,  \
    GCTL,   KC_X,   KC_C,   KC_3,   KC_4,                        ______, ______, ______, ______, ______,  \
    ______, ______, ______, KC_V,   DI_C,  KC_SPC,       DQG,    ALTZ,   ESC,    ______, ______, ______   \
  ),

  [DIV2] = LAYOUT( \
    ESC,    KC_G,   KC_Q,   KC_T,   KC_Y,                        ______, ______, ______, ______, ______,   \
    KC_V,   KC_I,   KC_M,   KC_H,   KC_J,                        ______, ______, ______, ______, ______,   \
    KC_Z,   KC_B,   ______, ______, ______,                      ______, ______, ______, ______, ______,   \
    ______, ______, ______, ______, ______, ______,      DQG,    ALTZ,   ESC,    ______, ______, ______  \
  )

};


void matrix_init_user(void) {
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case CXCF:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xf"));
    }
    break;
  case CXCB:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xb"));
    }
    break;
  case CXCS:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("xs"));
    }
    break;
  case CXO:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x") "o");
    }
    break;
  case CXU:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("x") "u");
    }
    break;
  case CCN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "n");
    }
    break;
  case CCP:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "p");
    }
    break;
  case CCZ:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "z");
    }
    break;
  case CCX:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTRL("c") "x");
    }
  }
  return true;
}

bool change;
void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case GVAL:
      change = true;
      break;
    case GCYB:
      if (!change) {
        change = true;
        oled_write("CYBER PUNK 2077\n", false);
      }
      break;
    case GBL2:
      if (!change) {
        change = true;
        oled_write("Borderlands 2\n", false);
      }
      break;
    case GEFT:
      if (!change) {
        change = true;
        oled_write("Escape from Tarkov\n", false);
      }
      break;
    case GR6S:
      if (!change) {
        change = true;
        oled_write("Raibow Six Siege\n", false);
      }
      break;
    case GKOC:
      if (!change) {
        change = true;
        oled_write("Knockout City\n", false);
      }
      break;
    case GDV2:
      if (!change) {
        change = true;
        oled_write("Division 2\n", false);
      }
      break;
    case GAPEX:
      if (!change) {
        change = true;
        oled_write("Apex Legends\n", false);
      }
      break;
    case DQG:
      oled_clear();
      change = false;
      break;
    }
}


char layer_state_str[64];

const char *read_layer_state(void) {
  if (change) {
    return "";
  }
  uint8_t layer = biton32(layer_state);
  switch (layer)
  {
  case QGMLWY:
    if (!change) {
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QGMLWY\n");
    }
    break;
  case LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: LOWER\n");
    break;
  case RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: RAISE\n");
    break;
  case MISCR:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MISCR\n");
    break;
  case MISCL:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MISCL\n");
    break;
  case COMBA:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COMBA\n");
    break;
  case COMBN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COMBN\n");
    break;
  case COMBE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COMBE\n");
    break;
  case COMBT:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: COMBT\n");
    break;
  default:
    oled_clear();
    //snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%d", layer);
    break;
  }

  return layer_state_str;
}

const char *read_logo(void) {
  static char logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  return logo;
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    oled_write_ln(read_layer_state(), false);
  } else {
    oled_write_ln(read_layer_state(), false);
  }
}
