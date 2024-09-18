/*
 * ex4.h
 *
 *  Created on: 14 Sep 2024
 *      Author: Admin
 */

#ifndef EX5_H_
#define EX5_H_
void display7SEG(int num) {
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (led7seg[num] >> i) & 1);
    }
}
void display7SEG2(int num) {
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

    for (int i = 7; i < 15; i++) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7 << i, (led7seg[num] >> i) & 1);
    }
}
void excerside5(void){
	int counter = 9;
	while (1)
	{
	    switch (counter) {
	        case 9:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	            display7SEG(4);
	          //  display7SEG2(3);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 8:
	            display7SEG(3);
	          //  display7SEG2(2);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 7:
	            display7SEG(2);
	           // display7SEG2(1);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 6:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	            display7SEG(1);
	          //  display7SEG2(0);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 5:
	            display7SEG(0);
	            //display7SEG2(3);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 4:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	            display7SEG(2);
	           // display7SEG2(2);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 3:
	            display7SEG(1);

	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 2:
	            display7SEG(0);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 1:
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
	            display7SEG(1);
	            HAL_Delay(1000);
	            counter--;
	            break;

	        case 0:
	            display7SEG(0);
	            HAL_Delay(1000);
	            counter += 9;
	            break;

	        default:
	            break;
	    }
	}

}


#endif /* EX5_H_ */
