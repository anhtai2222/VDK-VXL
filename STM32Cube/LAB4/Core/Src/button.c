/*
 * button.c
 *
 * Created on: Oct 20, 2024
 * Author: Admin
 */

#include "button.h"



Button buttons[BUTTON_COUNT] = {
    {BUTTON1_GPIO_Port, BUTTON1_Pin, {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}, 500, 0},
    {BUTTON2_GPIO_Port, BUTTON2_Pin, {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}, 500, 0},
    {BUTTON3_GPIO_Port, BUTTON3_Pin, {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE, NORMAL_STATE}, 500, 0}
};

int isButtonPressed(int buttonIndex) {
    int pressed = buttons[buttonIndex].flag;
    buttons[buttonIndex].flag = 0;
    return pressed;
}

void subKeyProcess(int buttonIndex) {
    buttons[buttonIndex].flag = 1;
}

void getKeyInput(int buttonIndex) {
    Button *button = &buttons[buttonIndex];

    button->state[0] = button->state[1];
    button->state[1] = button->state[2];
    button->state[2] = HAL_GPIO_ReadPin(button->port, button->pin);

    if (button->state[0] == button->state[1] && button->state[1] == button->state[2]) {
        if (button->state[3] != button->state[2]) {
            button->state[3] = button->state[2];

            if (button->state[2] == PRESSED_STATE) {
                subKeyProcess(buttonIndex);
                button->pressTimer = 500;
            }
        } else {

            if (--button->pressTimer <= 0) {
                button->state[3] = NORMAL_STATE;
                button->pressTimer = 500;
            }
        }
    }
}
#include "button.h"


int buttonFlag[3] = {0,0,0};
uint8_t count = 0;
void getKeyinput1(){
	if (count > 0 ) count--;
	//-----PROCESS BUTTON 1------------
	if((count == 0) && (HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin) == 0)){
		buttonFlag[0] = 1;
		count = 10;
	}
	// ----PROCESS BUTTON 2-----------
	if((count == 0) && (HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin) == 0)){
		buttonFlag[1] = 1;
		count = 10;
	}
	// ----- PROCESS BUTTON 3 -----------
	if((count == 0) && (HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin) == 0)){
		buttonFlag[2] = 1;
		count = 10;
	}

}
int isButtonPress(int i){
	if(buttonFlag[i] == 1){
		buttonFlag[i] = 0;
		return 1;
	}
	return 0;
}
void updateAllButtons() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        getKeyInput(i);
    }
}
