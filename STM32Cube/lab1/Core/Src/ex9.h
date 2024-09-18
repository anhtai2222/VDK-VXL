/*
 * ex9.h
 *
 *  Created on: 15 Sep 2024
 *      Author: Admin
 */

#include <stdint.h>
#ifndef SRC_EX8_H_
#define SRC_EX8_H_
uint16_t led[12]= { GPIO_PIN_1 , GPIO_PIN_2 , GPIO_PIN_3 ,GPIO_PIN_4 , GPIO_PIN_5 , GPIO_PIN_6 ,
		 GPIO_PIN_7 , GPIO_PIN_8 , GPIO_PIN_9 ,GPIO_PIN_10 , GPIO_PIN_11 , GPIO_PIN_12 };
void clearNumberOnClock(int tmp){
	HAL_GPIO_WritePin(GPIOA,led[tmp],GPIO_PIN_SET);
}

#endif /* SRC_EX9_H_ */
