/*
 * global.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "fsm_automatic.h"
#include"fsm_manual.h"
#include"led7_seg.h"
#define INIT_STATE 1
#define RED_STATE 2
#define GREEN_STATE 3
#define YELLOW_STATE 4
#define MODE_1 11
#define MODE_2 12
#define MODE_3 13
#define MODE_4 14
extern int LED_STATE [2];
extern int MODE;
extern int RED_DURATION;
extern int YELLOW_DURATION;
extern int GREEN_DURATION;
extern int current_lane;
extern int remaining_time_lane_0;
extern int remaining_time_lane_1;
#endif /* INC_GLOBAL_H_ */
