/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED1_Pin GPIO_PIN_1
#define RED1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_2
#define YELLOW1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_3
#define GREEN1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_4
#define RED2_GPIO_Port GPIOA
#define YELLOW2_Pin GPIO_PIN_5
#define YELLOW2_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_6
#define GREEN2_GPIO_Port GPIOA
#define BIT0_Pin GPIO_PIN_7
#define BIT0_GPIO_Port GPIOA
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOB
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOB
#define BUTTON3_Pin GPIO_PIN_2
#define BUTTON3_GPIO_Port GPIOB
#define BIT1_Pin GPIO_PIN_8
#define BIT1_GPIO_Port GPIOA
#define BIT2_Pin GPIO_PIN_9
#define BIT2_GPIO_Port GPIOA
#define BIT3_Pin GPIO_PIN_10
#define BIT3_GPIO_Port GPIOA
#define BIT4_Pin GPIO_PIN_11
#define BIT4_GPIO_Port GPIOA
#define BIT5_Pin GPIO_PIN_12
#define BIT5_GPIO_Port GPIOA
#define BIT6_Pin GPIO_PIN_13
#define BIT6_GPIO_Port GPIOA
#define BIT7_Pin GPIO_PIN_14
#define BIT7_GPIO_Port GPIOA
#define BIT8_Pin GPIO_PIN_15
#define BIT8_GPIO_Port GPIOA
#define BIT9_Pin GPIO_PIN_3
#define BIT9_GPIO_Port GPIOB
#define BIT10_Pin GPIO_PIN_4
#define BIT10_GPIO_Port GPIOB
#define BIT11_Pin GPIO_PIN_5
#define BIT11_GPIO_Port GPIOB
#define BIT12_Pin GPIO_PIN_6
#define BIT12_GPIO_Port GPIOB
#define BIT13_Pin GPIO_PIN_7
#define BIT13_GPIO_Port GPIOB
#define BIT14_Pin GPIO_PIN_8
#define BIT14_GPIO_Port GPIOB
#define BIT15_Pin GPIO_PIN_9
#define BIT15_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
