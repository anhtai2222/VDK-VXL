/*
 * led7_seg.c
 *
 *  Created on: 28 Oct 2024
 *      Author: Admin
 */

#include"led7_seg.h"
void displaySEG(int bit, uint16_t type) {
    if (bit < 9) {

        HAL_GPIO_WritePin(GPIOA, BIT_A[bit], type);
    } else {

        HAL_GPIO_WritePin(GPIOB, BIT_B[bit - 9], type);
    }
}
void display7SEG(int type, int num) {
    uint8_t segmentPatterns[10][4] = {
        {RESET, RESET, RESET, RESET}, // 0
        {SET,   RESET, RESET, RESET}, // 1
        {RESET, SET,   RESET, RESET}, // 2
        {SET,   SET,   RESET, RESET}, // 3
        {RESET, RESET, SET,   RESET}, // 4
        {SET,   RESET, SET,   RESET}, // 5
        {RESET, SET,   SET,   RESET}, // 6
        {SET,   SET,   SET,   RESET}, // 7
        {RESET, RESET, RESET, SET  }, // 8
        {SET,   RESET, RESET, SET  }  // 9
    };

    if (num < 0 || num > 9) {
        num = 0;
    }
    for (int i = 0; i < 4; i++) {
        displaySEG(type * 4 + i, segmentPatterns[num][i]);
    }
}
