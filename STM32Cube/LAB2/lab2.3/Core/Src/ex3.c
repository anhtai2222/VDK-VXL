/*
 * ex3.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Admin
 */
#include"ex3.h"
uint16_t pin7 [4] = { GPIO_PIN_6 , GPIO_PIN_7 , GPIO_PIN_8 ,
GPIO_PIN_9 };
const int MAX_LED = 4;
 int index_led = 0;
 int led_buffer [4] = {1 , 2 , 3 , 4};
 void clearLED () {
  HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 |
		  GPIO_PIN_9 , GPIO_PIN_SET ) ;
  HAL_GPIO_WritePin ( GPIOB , GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 |
		  GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 |
		  GPIO_PIN_6 , GPIO_PIN_SET ) ;
		  }
 void display7seg( int index, int num ) {
	 HAL_GPIO_WritePin( GPIOA ,pin7[ index ], GPIO_PIN_RESET );
  char led7seg[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
   for ( int i = 0; i < 7; i ++) {
   HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0<<i ,(led7seg[num]>>i)&1) ;
   }
 }

 void update7SEG (int index ) {
	 clearLED();
	 display7seg(index, led_buffer[index] );
}
