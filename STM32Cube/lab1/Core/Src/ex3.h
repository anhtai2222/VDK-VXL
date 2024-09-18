/*
 * ex3.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */

#ifndef SRC_EX3_H_
#define SRC_EX3_H_
void excerside3(void){
    int cnt = 9;
    switch (cnt) {
        case 9:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
            HAL_Delay(1000);
            cnt--;
            break;

        case 8:
            HAL_Delay(1000);
            cnt--;
            break;

        case 7:
            HAL_Delay(1000);
            cnt--;
            break;

        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
            HAL_Delay(1000);
            cnt--;
            break;

        case 5:
            HAL_Delay(1000);
            cnt--;
            break;

        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
            HAL_Delay(1000);
            cnt--;
            break;

        case 3:
            HAL_Delay(1000);
            cnt--;
            break;

        case 2:
            HAL_Delay(1000);
            cnt--;
            break;

        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
            HAL_Delay(1000);
            cnt--;
            break;

        case 0:
            HAL_Delay(1000);
            cnt += 9;
            break;

        default:
            break;
    }
}
#endif /* SRC_EX3_H_ */
