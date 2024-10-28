/*
 * traffic_light.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_
#include "main.h"
void setTrafficLightDefault(int lane);
void setTrafficLightRed(int lane);
void setTrafficLightGreen(int lane);
void setTrafficLightAmber(int lane);

 uint16_t BIT_A[9];
 uint16_t BIT_B[7];
 uint8_t segmentBits[10];
#endif /* INC_TRAFFIC_LIGHT_H_ */
