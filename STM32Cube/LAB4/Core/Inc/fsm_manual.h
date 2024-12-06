/*
 * fsm_manual.h
 *
 *  Created on: 28 Oct 2024
 *      Author: Admin
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_
#include"global.h"

void fsm_manual_run();
void displayDuration(int mode, int duration);
void task_toggle_red_lights(void);
void task_toggle_yellow_lights(void);
void task_toggle_green_lights(void);
void task_fsm_manual(void);
#endif /* INC_FSM_MANUAL_H_ */
