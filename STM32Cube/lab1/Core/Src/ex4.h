/*
 * ex4.h
 *
 *  Created on: 13 Sep 2024
 *      Author: Admin
 */

#ifndef EX4_H_
#define EX4_H_

void display7SEG1(int num) {
    char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, (led7seg[num] >> i) & 1);
    }
}

void excerside4(void){
	int counter = 0;
		while (1)
		{
			display7SEG1(counter);
			counter++;
			if (counter >= 10)
				counter = 0;
			HAL_Delay(1000);
}
}
#endif /* EX4_H_ */
