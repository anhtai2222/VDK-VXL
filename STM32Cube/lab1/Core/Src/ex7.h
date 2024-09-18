/*
 * ex7.h
 *
 *  Created on: 15 Sep 2024
 *      Author: Admin
 */

#ifndef EX7_H_
#define EX7_H_

void clearAllClock () {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2
                             | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
                             | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8
                             | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11
                             | GPIO_PIN_12, GPIO_PIN_SET);
}


#endif /* EX7_H_ */
