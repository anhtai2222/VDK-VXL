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

    if (num < 0 || num > 9) {
        num = 0;
    }

    for (int i = 0; i < 4; i++) {
        displaySEG(type * 4 + i, (num >> i) & 0x01);
    }
}
