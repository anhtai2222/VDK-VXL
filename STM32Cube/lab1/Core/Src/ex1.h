/*
 * ex1.h
 *
 *  Created on: Sep 12, 2024
 *      Author: Admin
 */
// vi cac chan gpio đang ở trạng thái active-low nên để set là logic 0
#ifndef SRC_EX1_H_
#define SRC_EX1_H_

void excerside1(void){
	int status = 0;
	int cnt = 2;

	   while (1)
	    {
	      switch (status)
	      {
	      case 0:
	    	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5 , GPIO_PIN_SET ) ;
	    	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6 , GPIO_PIN_RESET ) ;
	        break;
	      case 1:
	    	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5 , GPIO_PIN_RESET ) ;
	    	  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6 , GPIO_PIN_SET ) ;
	        break;
	      default:
	        break;
	      }
	      cnt--;
	      if (cnt == 0)
	      {
	        cnt = 2;
	        status = !status;
	      }
	      HAL_Delay(1000);
	    }
}

#endif /* SRC_EX1_H_ */
