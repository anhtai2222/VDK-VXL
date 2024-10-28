/*
 * button.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_
#include "main.h"
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define BUTTON_COUNT 3
typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
    int state[4];
    int pressTimer;
    int flag;
} Button;


extern Button buttons[BUTTON_COUNT];


int isButtonPressed(int buttonIndex);

void subKeyProcess(int buttonIndex);

void getKeyInput(int buttonIndex);

void updateAllButtons(void);


#endif /* INC_BUTTON_H_ */
