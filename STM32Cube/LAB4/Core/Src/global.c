/*
 * global.c
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#include "global.h"

int LED_STATE [2] = {INIT_STATE, INIT_STATE};
int MODE = MODE_1;
int remaining_time_lane_0 = 0;
int remaining_time_lane_1 = 0;
int RED_DURATION = 5;
int YELLOW_DURATION = 2;
int GREEN_DURATION = 3;
int current_lane = 0;
