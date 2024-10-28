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

void updateAllButtons() {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        getKeyInput(i);
    }
}
