/*
 * ex10.h
 *
 *  Created on: 15 Sep 2024
 *      Author: Admin
 */

#ifndef SRC_EX10_H_
#define SRC_EX10_H_
#include "ex7.h"
#include "ex8.h"
#include "ex9.h"
int sec = -1;
int min = 0;
int hou =2 ;

void displayClock(int hourLED, int minuteLED, int secondLED) {
	clearAllClock();
    setNumberOnClock(hourLED);
    setNumberOnClock(minuteLED);
    setNumberOnClock(secondLED);
}
void excerside10(void){

    sec++;
    if (sec >=60)
    {
        sec = 0;
        min++;
    }
    if (min >= 60)
    {
        min = 0;
        hou++;
    }
    if (hou >= 12)
    {
        hou = 0;
    }
    displayClock(hou, min/5, sec/5);
    HAL_Delay(50);

}



#endif /* SRC_EX10_H_ */
