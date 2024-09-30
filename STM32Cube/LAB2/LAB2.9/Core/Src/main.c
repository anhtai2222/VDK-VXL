/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "softwaretimer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RUN_TIME    100
#define MAX_LED_MATRIX 8
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */
int counter = RUN_TIME;
int index_led = 0;
int led_buffer[4] = {1, 2, 3, 4};
int hour = 12, minute = 34, second = 58;
uint8_t LED7_SEG[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* Function to display 7-segment LED */
void display7SEG(int index) {
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((LED7_SEG[index] >> 0) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((LED7_SEG[index] >> 1) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((LED7_SEG[index] >> 2) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((LED7_SEG[index] >> 3) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((LED7_SEG[index] >> 4) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((LED7_SEG[index] >> 5) & 0x01));
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((LED7_SEG[index] >> 6) & 0x01));
}

/* Enable corresponding 7-segment display */
void enable7SEG(int index) {
    switch (index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);  // EN0
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);    // EN1
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);    // EN2
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);    // EN3
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);    // EN0
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);  // EN1
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);    // EN2
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);    // EN3
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);    // EN0
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);    // EN1
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, RESET);  // EN2
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);    // EN3
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);    // EN0
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);    // EN1
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, SET);    // EN2
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);  // EN3
            break;
        default:
            break;
    }
}

void updateLEDMatrix(int index) {

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, SET);    // ENM0
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, SET);    // ENM1
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, SET);   // ENM2
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, SET);   // ENM3
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, SET);   // ENM4
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, SET);   // ENM5
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, SET);   // ENM6
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, SET);   // ENM7


    switch (index) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, RESET);  // ENM0
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, RESET);  // ENM1
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, RESET); // ENM2
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, RESET); // ENM3
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, RESET); // ENM4
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, RESET); // ENM5
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_14, RESET); // ENM6
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, RESET); // ENM7
            break;
    }
    uint8_t data = matrix_buffer[index];
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8, (data & 0x01) ? RESET : SET);   // Cột 0
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, (data & 0x02) ? RESET : SET);   // Cột 1
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, (data & 0x04) ? RESET : SET);  // Cột 2
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, (data & 0x08) ? RESET : SET);  // Cột 3
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, (data & 0x10) ? RESET : SET);  // Cột 4
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, (data & 0x20) ? RESET : SET);  // Cột 5
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, (data & 0x40) ? RESET : SET);  // Cột 6
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, (data & 0x80) ? RESET : SET);  // Cột 7

}


/* Update the 7-segment display buffer */
void updateClockBuffer() {
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer0(RUN_TIME);
  while (1)
  {
    /* USER CODE END WHILE */
	  if (timer0_flag == 1) {
	             if (index_led == 0) {
	                 second++;
	                 if (second >= 60) {
	                     second = 0;
	                     minute++;
	                 }
	                 if (minute >= 60) {
	                     minute = 0;
	                     hour++;
	                 }
	                 if (hour >= 24) {
	                     hour = 0;
	                 }
	                 updateClockBuffer();
	             }
	             HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	             if (index_led == 2 || index_led == 0) {
	                 HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
	             }

	             enable7SEG(index_led);
	             display7SEG(led_buffer[index_led++]);
	             if (index_led > 3) {
	                 index_led = 0;
	             }

	             updateLEDMatrix(index_led_matrix);
	             index_led_matrix++;// Update LED matrix
	             if (index_led_matrix >= MAX_LED_MATRIX) {
	                 index_led_matrix = 0;
	             }

	             setTimer0(RUN_TIME);
	         }

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA2 PA3 PA4 PA5
                           PA6 PA7 PA8 PA9
                           PA10 PA11 PA12 PA13
                           PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9
                          |GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13
                          |GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    timer_run();
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
