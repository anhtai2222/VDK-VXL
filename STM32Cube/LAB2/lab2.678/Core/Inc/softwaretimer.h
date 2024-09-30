/*
 * softwaretimer.h
 *
 *  Created on: Sep 30, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_


extern int timer0_flag, timer0_counter, TIMER_CYCLE;

void setTimer0(int duration);

void timer_run();




#endif /* INC_SOFTWARETIMER_H_ */
