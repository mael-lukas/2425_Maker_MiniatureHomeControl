/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fonts.h"
#include "st7735.h"
#include "rat_dance.h"
#include "neopixel.h"
#include "servos.h"
#include "mp3.h"
#include "bluetooth_protocol.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;
}

GETCHAR_PROTOTYPE
{
	uint8_t ch = 0;

	/* Clear the Overrun flag just before receiving the first character */
	__HAL_UART_CLEAR_OREFLAG(&huart2);

	/* Wait for reception of a character on the USART RX line and echo this
	 * character on console */
	HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}


///////////////////////////////////////////////////////// BLUETOOTH PROTOCOL //////////////////////////////////////////////////////////////////////
char startChar = '@';
char endChar = '#';

uint8_t rx_char; // Variable to store the received character

char instruction[200];
int instructionIndex = 0;

int UARTReceiverState = 0;

volatile int flagUART1 = 0;


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	// Re-enable UART interrupt reception
	HAL_UART_Receive_IT(&huart3, &rx_char, 1);

	instruction[instructionIndex] = rx_char;
	instructionIndex++;

	if (rx_char == '#')
	{
		instruction[instructionIndex] = 0; // 0 character for the printf
		instructionIndex = 0;
		flagUART1 = 1;
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
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_UART4_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();

  /* USER CODE BEGIN 2 */

///////////////////////////////////////////////////////////// MP3 PLAYER //////////////////////////////////////////////////////////////////////////
  	mp3_selectStorageDevice();
  	waitNms(20);
  	mp3_setVolume(10);
  	waitNms(20);
  	mp3_playWithIndex(2);


///////////////////////////////////////////////////////////// NEOPIXEL ////////////////////////////////////////////////////////////////////////////
  animateBlink(0xFF0000,2500);


///////////////////////////////////////////////////////////// SERVO MOTORS ////////////////////////////////////////////////////////////////////////////
  h_servo_t servo1;
  servoInit(&servo1,&htim1,TIM_CHANNEL_4);
  turnServo(&servo1);
  HAL_Delay(1000);
  turnServo(&servo1);
  HAL_Delay(1000);


//////////////////////////////////////////////////////////// SPI SCREEN ///////////////////////////////////////////////////////////////////////////
  ST7735_Init();
  ST7735_FillScreen(ST7735_BLACK);
  ST7735_WriteString(0,0,"Hello World !",Font_7x10,ST7735_WHITE,ST7735_BLACK);
  HAL_Delay(300);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame00);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame01);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame02);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame03);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame04);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame05);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame06);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame07);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame08);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame09);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame10);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame11);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame12);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame13);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame14);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame15);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame16);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame17);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame18);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame19);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame20);
	  HAL_Delay(33);
	  ST7735_DrawImage(0, 0, ST7735_WIDTH, ST7735_HEIGHT, rd_frame21);
	  HAL_Delay(33);

    /* USER CODE END WHILE */

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

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

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
