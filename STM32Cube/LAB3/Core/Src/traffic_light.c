/*
 * traffic_light.c
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */


#include "traffic_light.h"

uint16_t REDLIGHT [2] = {RED1_Pin, RED2_Pin};
uint16_t GREENLIGHT [2] = {GREEN1_Pin, GREEN2_Pin};
uint16_t AMBERLIGHT [2] = {YELLOW1_Pin, YELLOW2_Pin};
uint16_t BIT [16] = {BIT0_Pin, BIT1_Pin, BIT2_Pin, BIT3_Pin, BIT4_Pin,
		BIT5_Pin, BIT6_Pin, BIT7_Pin, BIT8_Pin, BIT9_Pin, BIT10_Pin,
		BIT11_Pin, BIT12_Pin, BIT13_Pin, BIT14_Pin, BIT15_Pin};
uint16_t BIT_A[9] = {BIT0_Pin, BIT1_Pin, BIT2_Pin, BIT3_Pin, BIT4_Pin,
                     BIT5_Pin, BIT6_Pin, BIT7_Pin, BIT8_Pin};
uint16_t BIT_B[7] = {BIT9_Pin, BIT10_Pin, BIT11_Pin, BIT12_Pin,
                     BIT13_Pin, BIT14_Pin, BIT15_Pin};
void setTrafficLightDefault(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}
void setTrafficLightRed(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}
void setTrafficLightGreen(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], RESET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], SET);
}
void setTrafficLightAmber(int lane){
	HAL_GPIO_WritePin(GPIOA, REDLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, GREENLIGHT[lane], SET);
	HAL_GPIO_WritePin(GPIOA, AMBERLIGHT[lane], RESET);
}


