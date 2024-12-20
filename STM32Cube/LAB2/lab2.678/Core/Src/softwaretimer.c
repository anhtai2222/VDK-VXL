/*
 * softwaretimer.c
 *
 *  Created on: Sep 30, 2024
 *      Author: Admin
 */

#include "softwaretimer.h"

int timer0_flag = 0;
int timer0_counter = 0;
int TIMER_CYCLE = 10;

void setTimer0(int duration) {
    timer0_counter = duration/TIMER_CYCLE ;
    timer0_flag = 0;
}

void timer_run() {
    if (timer0_counter > 0) {
        timer0_counter--;
        if (timer0_counter <= 0)
            timer0_flag = 1;
    }
}
