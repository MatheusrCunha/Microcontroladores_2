/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#define S1_R_Pin GPIO_PIN_0
#define S1_R_GPIO_Port GPIOA
#define S1_Y_Pin GPIO_PIN_1
#define S1_Y_GPIO_Port GPIOA
#define S1_G_Pin GPIO_PIN_2
#define S1_G_GPIO_Port GPIOA
#define S2_R_Pin GPIO_PIN_3
#define S2_R_GPIO_Port GPIOA
#define S2_Y_Pin GPIO_PIN_4
#define S2_Y_GPIO_Port GPIOA
#define S2_G_Pin GPIO_PIN_5
#define S2_G_GPIO_Port GPIOA
#define S3_R_Pin GPIO_PIN_6
#define S3_R_GPIO_Port GPIOA
#define S3_RA7_Pin GPIO_PIN_7
#define S3_RA7_GPIO_Port GPIOA
#define S4_R_Pin GPIO_PIN_0
#define S4_R_GPIO_Port GPIOB
#define S4_Y_Pin GPIO_PIN_1
#define S4_Y_GPIO_Port GPIOB
#define S4_G_Pin GPIO_PIN_2
#define S4_G_GPIO_Port GPIOB
#define S3_Y_Pin GPIO_PIN_8
#define S3_Y_GPIO_Port GPIOA
#define S3_G_Pin GPIO_PIN_9
#define S3_G_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
