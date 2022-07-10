/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#define motor2_A_Pin GPIO_PIN_6
#define motor2_A_GPIO_Port GPIOF
#define motor1_A_Pin GPIO_PIN_1
#define motor1_A_GPIO_Port GPIOC
#define motor1_B_Pin GPIO_PIN_2
#define motor1_B_GPIO_Port GPIOC
#define motor2_B_Pin GPIO_PIN_3
#define motor2_B_GPIO_Port GPIOC
#define Trig_Pin GPIO_PIN_8
#define Trig_GPIO_Port GPIOC
#define Echo_Pin GPIO_PIN_9
#define Echo_GPIO_Port GPIOC
#define motor3_A_Pin GPIO_PIN_0
#define motor3_A_GPIO_Port GPIOD
#define motor4_B_Pin GPIO_PIN_1
#define motor4_B_GPIO_Port GPIOD
#define motor4_A_Pin GPIO_PIN_3
#define motor4_A_GPIO_Port GPIOD
#define motor3_B_Pin GPIO_PIN_7
#define motor3_B_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
