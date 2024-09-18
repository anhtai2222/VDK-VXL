/*
 * ex2.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */

#ifndef EX2_H_
#define EX2_H_

void excerside2(void){
	int status=0;
	int cnt=5;
	 while (1)
	    {
	        switch (status)
	        {
	        case 0:
	            HAL_GPIO_WritePin(GPIOA , GPIO_PIN_5 ,GPIO_PIN_RESET);
	            HAL_GPIO_WritePin(GPIOA , GPIO_PIN_6 , GPIO_PIN_SET);
	            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	            break;
	        case 1:
	        	 HAL_GPIO_WritePin(GPIOA , GPIO_PIN_5 ,GPIO_PIN_SET);
	        	 HAL_GPIO_WritePin(GPIOA , GPIO_PIN_6 , GPIO_PIN_RESET);
	        	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	            break;
	        case 2:
	        	 HAL_GPIO_WritePin(GPIOA , GPIO_PIN_5 ,GPIO_PIN_SET);
	        	 HAL_GPIO_WritePin(GPIOA , GPIO_PIN_6 , GPIO_PIN_SET);
	        	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	            break;
	        default:
	            break;
	        }
	        cnt--;
	        if (cnt == 0)
	        {
	            switch (status)
	            {
	            case 0:
	                status = 2;
	                cnt = 3;
	                break;
	            case 1:
	                status = 0;
	                cnt = 5;
	                break;
	            case 2:
	                status = 1;
	                cnt = 2;
	                break;
	            default:
	                break;
	            }
	        }
	        HAL_Delay(1000);
	    }
}

#endif /* EX2_H_ */
