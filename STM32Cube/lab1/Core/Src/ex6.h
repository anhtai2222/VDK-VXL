/*
 * ex6.h
 *
 *  Created on: 15 Sep 2024
 *      Author: Admin
 */
#include <stdint.h>
#ifndef EX6_H_
#define EX6_H_
uint16_t led[12]={GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,
					GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,GPIO_PIN_12};
void testled(int tmp){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 |GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|
						GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA,led[tmp],GPIO_PIN_RESET);
}
void excerside6(void){
	for(int i=0; i<12;i++){
		testled(i);
		HAL_Delay(1000);
	}
}

#endif /* EX6_H_ */
