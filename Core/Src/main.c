/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "i2c-lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
char rx_data[50];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void lcd_led_control()
{
	  if (rx_data[0] == 0x65 && rx_data[1] == 0x00 && rx_data[2] == 0x02 && rx_data[3] == 0x01 && rx_data[4] == 0xFF && rx_data[5] == 0xFF && rx_data[6] == 0xFF)
	  {
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_All, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, GPIO_PIN_SET); // RED

		  lcd_send_cmd(0x01);
		  HAL_Delay(200);

		  lcd_send_cmd(0x80);
		  lcd_send_string("R");
		  HAL_Delay(100);
		  lcd_send_cmd(0x81);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x82);
		  lcd_send_string("d");
		  HAL_Delay(100);
		  lcd_send_cmd(0x83);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x84);
		  lcd_send_string("L");
		  HAL_Delay(100);
		  lcd_send_cmd(0x85);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x86);
		  lcd_send_string("d");
		  HAL_Delay(100);
		  lcd_send_cmd(0x87);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x88);
		  lcd_send_string("O");
		  HAL_Delay(100);
		  lcd_send_cmd(0x89);
		  lcd_send_string("n");
		  HAL_Delay(100);



	  }
	  if (rx_data[0] == 0x65 && rx_data[1] == 0x00 && rx_data[2] == 0x03 && rx_data[3] == 0x01 && rx_data[4] == 0xFF && rx_data[5] == 0xFF && rx_data[6] == 0xFF)
	  {
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_All, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_1, GPIO_PIN_SET); // GREEN

		  lcd_send_cmd(0x01);
		  HAL_Delay(200);

		  lcd_send_cmd(0x80);
		  lcd_send_string("G");
		  HAL_Delay(100);
		  lcd_send_cmd(0x81);
		  lcd_send_string("r");
		  HAL_Delay(100);
		  lcd_send_cmd(0x82);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x83);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x84);
		  lcd_send_string("n");
		  HAL_Delay(100);
		  lcd_send_cmd(0x85);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x86);
		  lcd_send_string("L");
		  HAL_Delay(100);
		  lcd_send_cmd(0x87);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x88);
		  lcd_send_string("d");
		  HAL_Delay(100);
		  lcd_send_cmd(0x89);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x8A);
		  lcd_send_string("O");
		  HAL_Delay(100);
		  lcd_send_cmd(0x8B);
		  lcd_send_string("n");
		  HAL_Delay(100);

	  }
	  if (rx_data[0] == 0x65 && rx_data[1] == 0x00 && rx_data[2] == 0x04 && rx_data[3] == 0x01 && rx_data[4] == 0xFF && rx_data[5] == 0xFF && rx_data[6] == 0xFF)
	  {
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_All, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2, GPIO_PIN_SET); // BLUE

		  lcd_send_cmd(0x01);
		  HAL_Delay(200);

		  lcd_send_cmd(0x80);
		  lcd_send_string("B");
		  HAL_Delay(100);
		  lcd_send_cmd(0x81);
		  lcd_send_string("l");
		  HAL_Delay(100);
		  lcd_send_cmd(0x82);
		  lcd_send_string("u");
		  HAL_Delay(100);
		  lcd_send_cmd(0x83);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x84);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x85);
		  lcd_send_string("L");
		  HAL_Delay(100);
		  lcd_send_cmd(0x86);
		  lcd_send_string("e");
		  HAL_Delay(100);
		  lcd_send_cmd(0x87);
		  lcd_send_string("d");
		  HAL_Delay(100);
		  lcd_send_cmd(0x88);
		  lcd_send_string(" ");
		  HAL_Delay(100);
		  lcd_send_cmd(0x89);
		  lcd_send_string("O");
		  HAL_Delay(100);
		  lcd_send_cmd(0x8A);
		  lcd_send_string("n");
		  HAL_Delay(100);

	  }

	  for(int i =0 ;i<50;i++)
	  {
		  rx_data[i] = '\0'; //Clear rx_data.
	  }
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
  MX_USART1_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_UART_Receive(&huart1, (uint8_t *)rx_data, 50 , 100);
	  lcd_led_control();

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

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 400000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PE2 PE0 PE1 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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
