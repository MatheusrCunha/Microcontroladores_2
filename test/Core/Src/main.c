/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {ESTADO_0, ESTADO_1, ESTADO_2, ESTADO_3, ESTADO_4, ESTADO_5,
		ESTADO_6, ESTADO_7, ESTADO_8, ESTADO_9} Tipo_estado;

Tipo_estado estado_atual;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void INIC_SYS();
void EST_RST();
void EST_S1R();
void EST_S1Y();
void EST_S1G();
void EST_S2R();
void EST_S2Y();
void EST_S2G();
void EST_S3R();
void EST_S3Y();
void EST_S3G();


/* USER CODE BEGIN PFP */

void (*tabela_estados[])() = {&EST_RST, &EST_S1R, &EST_S1Y, &EST_S1G, &EST_S2R, &EST_S2Y,
		&EST_S2G, &EST_S3R, &EST_S3Y, &EST_S3G};

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */
  void INIC_SYS();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
 /* USER CODE BEGIN 3 */

	  tabela_estados[estado_atual]();
	  HAL_Delay(200);

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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  HAL_GPIO_WritePin(GPIOA, S1_R_Pin|S1_Y_Pin|S1_G_Pin|S2_R_Pin 
                          |S2_Y_Pin|S2_G_Pin|S3_R_Pin|S3_Y_Pin 
                          |S4_Y_Pin|S4_G_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, S3_G_Pin|S4_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : S1_R_Pin S1_Y_Pin S1_G_Pin S2_R_Pin 
                           S2_Y_Pin S2_G_Pin S3_R_Pin S3_Y_Pin 
                           S4_Y_Pin S4_G_Pin */
  GPIO_InitStruct.Pin = S1_R_Pin|S1_Y_Pin|S1_G_Pin|S2_R_Pin 
                          |S2_Y_Pin|S2_G_Pin|S3_R_Pin|S3_Y_Pin 
                          |S4_Y_Pin|S4_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : S3_G_Pin S4_R_Pin */
  GPIO_InitStruct.Pin = S3_G_Pin|S4_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void INIC_SYS()
{
	estado_atual = ESTADO_0;

}
void EST_RST()
{
	HAL_GPIO_WritePin(S1_R_GPIO_Port,S1_R_Pin, 0);
	HAL_GPIO_WritePin(S1_Y_GPIO_Port,S1_Y_Pin, 1);
	HAL_GPIO_WritePin(S1_G_GPIO_Port,S1_G_Pin, 1);

	HAL_GPIO_WritePin(S2_R_GPIO_Port,S2_R_Pin, 0);
	HAL_GPIO_WritePin(S2_Y_GPIO_Port,S2_Y_Pin, 1);
	HAL_GPIO_WritePin(S2_G_GPIO_Port,S2_G_Pin, 1);

	HAL_GPIO_WritePin(S3_R_GPIO_Port,S3_R_Pin, 0);
	HAL_GPIO_WritePin(S3_Y_GPIO_Port,S3_Y_Pin, 1);
	HAL_GPIO_WritePin(S3_G_GPIO_Port,S3_G_Pin, 1);

	HAL_GPIO_WritePin(S4_R_GPIO_Port,S4_R_Pin, 0);
	HAL_GPIO_WritePin(S4_Y_GPIO_Port,S4_Y_Pin, 1);
	HAL_GPIO_WritePin(S4_G_GPIO_Port,S4_G_Pin, 1);
	HAL_Delay(500);

	estado_atual = ESTADO_1;


}
void EST_S1R()
{

	HAL_GPIO_WritePin(S1_R_GPIO_Port,S1_R_Pin, 1);
	HAL_GPIO_WritePin(S1_Y_GPIO_Port,S1_Y_Pin, 1);
	HAL_GPIO_WritePin(S1_G_GPIO_Port,S1_G_Pin, 0);
	HAL_Delay(500);

	estado_atual = ESTADO_2;


}
void EST_S1Y()
{
	HAL_GPIO_WritePin(S1_R_GPIO_Port,S1_R_Pin, 1);
	HAL_GPIO_WritePin(S1_Y_GPIO_Port,S1_Y_Pin, 0);
	HAL_GPIO_WritePin(S1_G_GPIO_Port,S1_G_Pin, 1);

	estado_atual = ESTADO_3;

}
void EST_S1G()
{
	HAL_GPIO_WritePin(S1_R_GPIO_Port,S1_R_Pin, 0);
	HAL_GPIO_WritePin(S1_Y_GPIO_Port,S1_Y_Pin, 1);
	HAL_GPIO_WritePin(S1_G_GPIO_Port,S1_G_Pin, 1);

	HAL_GPIO_WritePin(S2_R_GPIO_Port,S2_R_Pin, 1);
	HAL_GPIO_WritePin(S2_Y_GPIO_Port,S2_Y_Pin, 1);
	HAL_GPIO_WritePin(S2_G_GPIO_Port,S2_G_Pin, 0);
	HAL_Delay(500);

	estado_atual = ESTADO_4;


}
void EST_S2R()
{

	HAL_GPIO_WritePin(S2_R_GPIO_Port,S2_R_Pin, 1);
	HAL_GPIO_WritePin(S2_Y_GPIO_Port,S2_Y_Pin, 0);
	HAL_GPIO_WritePin(S2_G_GPIO_Port,S2_G_Pin, 1);

	estado_atual = ESTADO_5;


}
void EST_S2Y()
{
	HAL_GPIO_WritePin(S2_R_GPIO_Port,S2_R_Pin, 0);
	HAL_GPIO_WritePin(S2_Y_GPIO_Port,S2_Y_Pin, 1);
	HAL_GPIO_WritePin(S2_G_GPIO_Port,S2_G_Pin, 1);

	HAL_GPIO_WritePin(S3_R_GPIO_Port,S3_R_Pin, 1);
	HAL_GPIO_WritePin(S3_Y_GPIO_Port,S3_Y_Pin, 1);
	HAL_GPIO_WritePin(S3_G_GPIO_Port,S3_G_Pin, 0);
	HAL_Delay(500);

	estado_atual = ESTADO_6;
}
void EST_S2G()
{
	HAL_GPIO_WritePin(S3_R_GPIO_Port,S3_R_Pin, 1);
	HAL_GPIO_WritePin(S3_Y_GPIO_Port,S3_Y_Pin, 0);
	HAL_GPIO_WritePin(S3_G_GPIO_Port,S3_G_Pin, 1);

	estado_atual = ESTADO_7;


}
void EST_S3R()
{
	HAL_GPIO_WritePin(S3_R_GPIO_Port,S3_R_Pin, 0);
	HAL_GPIO_WritePin(S3_Y_GPIO_Port,S3_Y_Pin, 1);
	HAL_GPIO_WritePin(S3_G_GPIO_Port,S3_G_Pin, 1);

	HAL_GPIO_WritePin(S4_R_GPIO_Port,S4_R_Pin, 1);
	HAL_GPIO_WritePin(S4_Y_GPIO_Port,S4_Y_Pin, 1);
	HAL_GPIO_WritePin(S4_G_GPIO_Port,S4_G_Pin, 0);
	HAL_Delay(500);

	estado_atual = ESTADO_8;

}
void EST_S3Y()
{

	HAL_GPIO_WritePin(S4_R_GPIO_Port,S4_R_Pin, 1);
	HAL_GPIO_WritePin(S4_Y_GPIO_Port,S4_Y_Pin, 0);
	HAL_GPIO_WritePin(S4_G_GPIO_Port,S4_G_Pin, 1);

	estado_atual = ESTADO_9;

}
void EST_S3G()
{

	HAL_GPIO_WritePin(S4_R_GPIO_Port,S4_R_Pin, 0);
	HAL_GPIO_WritePin(S4_Y_GPIO_Port,S4_Y_Pin, 1);
	HAL_GPIO_WritePin(S4_G_GPIO_Port,S4_G_Pin, 1);

	estado_atual = ESTADO_1;

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
