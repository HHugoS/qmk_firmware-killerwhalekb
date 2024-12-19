// Copyright 2021 Hayashi (@w_vwbw)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lib/add_keycodes.h"
#include "keymap_japanese.h"

// レイヤー名h
enum layer_number {
    _BASE = 0,
    _JP,
    _FN, _MOUSE, _BALL_SETTINGS, _LIGHT_SETTINGS // 自動マウスレイヤー切り替えや設定用のレイヤー
};

// キーマップの設定
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_SCLN,
              KC_Z, KC_X, KC_C, KC_V, KC_COMM,
                    LALT(KC_GRV),
        // 側面スイッチ
        KC_LCTL, KC_LSFT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP,   KC_DOWN, KC_LEFT, KC_RIGHT,       XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        KC_LGUI, KC_ENT,                           MO(_JP),

        // 右手
        // 天面スイッチ
        KC_EQL,  KC_6, KC_7, KC_8,    KC_9,    KC_0,
        KC_RBRC, KC_Y, KC_U, KC_I,    KC_O,    KC_P,
        KC_QUOT, KC_H, KC_J, KC_K,    KC_L,    LT(_MOUSE, KC_SLSH),
        KC_DOT,  KC_B, KC_N, KC_M,    KC_GRV,
                             KC_BSLS,
        // 側面スイッチ
        LT(_FN, KC_TAB), KC_LALT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        KC_SPC, KC_DEL,                           MO(_MOUSE)
    ),
    [_JP] = LAYOUT(
        // 左手
        // 天面スイッチ
        KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,
        KC_A, KC_S, KC_D, KC_F, KC_G, KC_SCLN,
              KC_Z, KC_X, KC_C, KC_V, KC_COMM,
                    LALT(KC_GRV),
        // 側面スイッチ
        KC_LCTL, KC_LSFT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        KC_UP,   KC_DOWN, KC_LEFT, KC_RIGHT,       XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        KC_LGUI, KC_ENT,                           MO(_JP),

        // 右手
        // 天面スイッチ
        KC_EQL,  KC_6, KC_7, KC_8,    KC_9,    KC_0,
        KC_RBRC, KC_Y, KC_U, KC_I,    KC_O,    KC_P,
        KC_QUOT, KC_H, KC_J, KC_K,    KC_L,    LT(_MOUSE, KC_SLSH),
        KC_DOT,  KC_B, KC_N, KC_M,    KC_GRV,
                             KC_BSLS,
        // 側面スイッチ
        LT(_FN, KC_TAB), KC_LALT,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,        XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        KC_SPC, KC_DEL,                           MO(_MOUSE)
    ),
    [_FN] = LAYOUT(
        // 左手
        // 天面スイッチ
          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                             // トグルスイッチ
         KC_ESC, _______,                            _______,

        // 右手
        // 天面スイッチ
         KC_F12,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                          _______,
        // 側面スイッチ
        _______,  KC_BSPC,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                             // トグルスイッチ
        _______, KC_DEL,                            _______
    ),
    [_MOUSE] = LAYOUT(
        // 左手
        // 天面スイッチ
        MO(_LIGHT_SETTINGS), _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,
                            _______,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                             // トグルスイッチ
        _______, _______,                            _______,

        // 右手
        // 天面スイッチ
           _______,    _______,    _______, _______, _______, MO(_BALL_SETTINGS),
           XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX,
          MOD_SCRL, KC_MS_BTN1, KC_MS_BTN2, XXXXXXX, XXXXXXX,         MO(_MOUSE),
        KC_MS_BTN3, KC_MS_BTN4, KC_MS_BTN5, XXXXXXX, XXXXXXX,
                                                     XXXXXXX,
        // 側面スイッチ
        _______, _______,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        _______, _______, _______, _______,          _______,
        // 追加スイッチ                             // トグルスイッチ
        _______, _______,                            MO(_MOUSE)
    ),
    [_BALL_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, L_SPD_I,   L_CHMOD,
        AUTO_MOUSE, XXXXXXX, XXXXXXX, L_ANG_D,   L_INV,   L_ANG_I,
                    XXXXXXX, XXXXXXX, XXXXXXX, L_SPD_D,   XXXXXXX,
                             INV_SCRL,
        // 側面スイッチ
        XXXXXXX, XXXXXXX,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        XXXXXXX, INV_SCRL,                           XXXXXXX,

        // 右手
        // 天面スイッチ
        R_CHMOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, R_SPD_I, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        R_ANG_D,   R_INV, R_ANG_I, XXXXXXX, XXXXXXX, AUTO_MOUSE,
        XXXXXXX, R_SPD_D, XXXXXXX, XXXXXXX, XXXXXXX,
        // 側面スイッチ
                                     INV_SCRL,
        XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX,                            XXXXXXX
    ),
    [_LIGHT_SETTINGS] = LAYOUT(
        // 左手
        // 天面スイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_MOD, _______,
        XXXXXXX, RGB_SPI, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 RGB_SPD, RGB_VAD, RGB_SAD, RGB_HUD, XXXXXXX,
                          XXXXXXX,
        // 側面スイッチ
        RGB_MOD, RGB_MOD,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX,

        // 右手
        // 天面スイッチ
        XXXXXXX, RGB_MOD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,
        RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,
                                   XXXXXXX,
        // 側面スイッチ
        RGB_MOD, RGB_MOD,
        // 十字キーorジョイスティック                // ジョイスティックスイッチ
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        // 追加スイッチ                             // トグルスイッチ
        XXXXXXX, XXXXXXX,                            XXXXXXX
    )
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX)
    },
    [_JP] =   {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX)
    },
    [_MOUSE] =   {
        ENCODER_CCW_CW(KC_ESC, KC_TAB),
        ENCODER_CCW_CW(REDO, UNDO),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(KC_DEL, KC_BSPC),
        ENCODER_CCW_CW(KC_UP, KC_DOWN),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(KC_WH_U, KC_WH_D),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX)
    },
    [_LIGHT_SETTINGS] =   {
        ENCODER_CCW_CW(RGB_SPI, RGB_SPD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX),
        ENCODER_CCW_CW(RGB_SPI, RGB_SPD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(XXXXXXX, XXXXXXX)
    },
};

//小指で押している間マウスレイヤーに切り替え


//日本語キーに変換
const key_override_t at_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, JP_AT, 1<<_JP);  //Shift 2 -> @
const key_override_t circ_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, JP_CIRC, 1<<_JP); //Shift 6 -> ^
const key_override_t ampr_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, JP_AMPR, 1<<_JP); //Shift 7 -> &
const key_override_t astr_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, JP_ASTR, 1<<_JP); //Shift 8
const key_override_t lprn_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, JP_LPRN, 1<<_JP); //Shift 9
const key_override_t rprn_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, JP_RPRN, 1<<_JP); //Shift 0
const key_override_t unds_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, JP_UNDS, 1<<_JP); //Shift -
const key_override_t eql_key_override = ko_make_with_layers_and_negmods(0, KC_EQL, JP_EQL, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //=
const key_override_t plus_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQL, JP_PLUS, 1<<_JP); //Shift =
const key_override_t lbrc_key_override = ko_make_with_layers_and_negmods(0, KC_LBRC, JP_LBRC, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //[
const key_override_t lcbr_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, JP_LCBR, 1<<_JP); //Shift [
const key_override_t rbrc_key_override = ko_make_with_layers_and_negmods(0, KC_RBRC, JP_RBRC, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //]
const key_override_t rcbr_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, JP_RCBR, 1<<_JP); //Shift ]
const key_override_t yen_key_override = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_YEN, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //"\"
const key_override_t pipe_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE, 1<<_JP); //Shift "\"
const key_override_t coln_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, JP_COLN, 1<<_JP); //Shift ";"
const key_override_t quot_key_override = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //'
const key_override_t dquo_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO, 1<<_JP); //Shift '
const key_override_t grv_key_override = ko_make_with_layers_and_negmods(0, KC_GRV, JP_GRV, 1<<_JP, (uint8_t) MOD_MASK_SHIFT); //`
const key_override_t tild_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_GRV, JP_TILD, 1<<_JP); //Shift `
const key_override_t lang_key_override = ko_make_with_layers(MOD_MASK_ALT, KC_GRV, JP_ZKHK, 1<<_JP); //Alt Grave
const key_override_t del_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);  //Shift BSPC -> Del

const key_override_t *key_overrides[] = {
    &at_key_override,
    &circ_key_override,
    &ampr_key_override,
    &astr_key_override,
    &lprn_key_override,
    &rprn_key_override,
    &unds_key_override,
    &eql_key_override,
    &plus_key_override,
    &lbrc_key_override,
    &lcbr_key_override,
    &rbrc_key_override,
    &rcbr_key_override,
    &yen_key_override,
    &pipe_key_override,
    &coln_key_override,
    &quot_key_override,
    &dquo_key_override,
    &grv_key_override,
    &tild_key_override,
    &lang_key_override,
    &del_key_override
};
