/*
 * fsm_manual.c
 *
 *  Created on: 28 Oct 2024
 *      Author: Admin
 */

#include"fsm_manual.h"
int tempDuration = 0;
void changeMode(int mode){
	setTrafficLightDefault(0);
	setTrafficLightDefault(1);
	MODE = mode;

}

void displayDuration(int mode, int duration){
	display7SEG(0, mode);
	display7SEG(1, 0);
	display7SEG(2, duration % 10);
	display7SEG(3, (int) (duration / 10));

}

void fsm_manual_run(){
	switch(MODE){
		case MODE_1:
//			fsm_automatic_run(0);
//			fsm_automatic_run(1);
			//displayDuration(1, 0);
			 SCH_Add_Task(task_fsm_lane_0,0,10);  // Lên lịch cho lane 0
			 SCH_Add_Task(task_fsm_lane_1, 0,10);  // Lên lịch cho lane 1
			 SCH_Add_Task(task_display_time_1,0,1000);
			 SCH_Add_Task(task_display_time_0,0,1000);
			if (isButtonPress(0) == 1){
				SCH_Delete_Task(task_fsm_lane_0);
				SCH_Delete_Task(task_fsm_lane_1);
				SCH_Delete_Task(task_display_time_1);
				SCH_Delete_Task(task_display_time_0);
				tempDuration = RED_DURATION;
				changeMode(MODE_2);
			}
			break;
		case MODE_2:

			displayDuration(2, tempDuration);
			if (isButtonPress(0) == 1){
				tempDuration = YELLOW_DURATION;
				changeMode(MODE_3);
			}
			if (isButtonPress(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				RED_DURATION = tempDuration;
			}
			if (isButtonPress(2) == 1){
				RED_DURATION = tempDuration;
			}
			if(buttonFlag[1]== 0) {
				HAL_GPIO_TogglePin(GPIOA, RED1_Pin);
				HAL_GPIO_TogglePin(GPIOA, RED2_Pin);
			}
			break;
		case MODE_3:

			displayDuration(3, tempDuration);
			if (isButtonPress(0) == 1){
				tempDuration = GREEN_DURATION;
				changeMode(MODE_4);
			}
			if (isButtonPress(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				YELLOW_DURATION = tempDuration;
			}
			if (isButtonPress(2) == 1){
				YELLOW_DURATION = tempDuration;
			}
			if(buttonFlag[1]==0) {
				HAL_GPIO_TogglePin(GPIOA, YELLOW1_Pin);
				HAL_GPIO_TogglePin(GPIOA, YELLOW2_Pin);
						}
			break;
		case MODE_4:

			displayDuration(4, tempDuration);
			if (isButtonPress(0) == 1){
				LED_STATE [0] = INIT_STATE;
				LED_STATE [1] = INIT_STATE;
				changeMode(MODE_1);
			}
			if (isButtonPress(1) == 1){
				tempDuration++;
				tempDuration %= 100;
				GREEN_DURATION = tempDuration;
			}
			if (isButtonPress(2) == 1){
				GREEN_DURATION = tempDuration;
			}
			if(buttonFlag[1]==0) {
				HAL_GPIO_TogglePin(GPIOA, GREEN1_Pin);
				HAL_GPIO_TogglePin(GPIOA, GREEN2_Pin);
			}
			break;
		default:
			 break;

	}
}
