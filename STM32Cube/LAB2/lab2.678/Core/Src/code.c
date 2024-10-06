/*
 * code.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Admin
 */

#include"code.h"
static uint8_t LED7_SEG[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
void display7SEG(int index) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((LED7_SEG[index] >> 0) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((LED7_SEG[index] >> 1) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((LED7_SEG[index] >> 2) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((LED7_SEG[index] >> 3) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((LED7_SEG[index] >> 4) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((LED7_SEG[index] >> 5) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((LED7_SEG[index] >> 6) & 0x01));
}

void enable7SEG(int index) {
    switch (index) {
        case 0: {
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
            break;
        }
        case 1: {
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
            break;
        }
        case 2: {
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
            break;
        }
        case 3:
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);
        	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
            break;
        default:
            break;
    }
}
