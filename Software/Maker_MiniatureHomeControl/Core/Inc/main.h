/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

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
#define TIM1_CH1_Pin GPIO_PIN_0
#define TIM1_CH1_GPIO_Port GPIOC
#define TIM1_CH2_Pin GPIO_PIN_1
#define TIM1_CH2_GPIO_Port GPIOC
#define TIM1_CH3_Pin GPIO_PIN_2
#define TIM1_CH3_GPIO_Port GPIOC
#define TIM1_CH4_Pin GPIO_PIN_3
#define TIM1_CH4_GPIO_Port GPIOC
#define TIM2_CH2_Pin GPIO_PIN_1
#define TIM2_CH2_GPIO_Port GPIOA
#define USART2_TX_Pin GPIO_PIN_2
#define USART2_TX_GPIO_Port GPIOA
#define TIM3_CH1_Pin GPIO_PIN_6
#define TIM3_CH1_GPIO_Port GPIOA
#define USART1_TX_Pin GPIO_PIN_4
#define USART1_TX_GPIO_Port GPIOC
#define USART1_RX_Pin GPIO_PIN_5
#define USART1_RX_GPIO_Port GPIOC
#define USART3_TX_Pin GPIO_PIN_10
#define USART3_TX_GPIO_Port GPIOB
#define USART3_RX_Pin GPIO_PIN_11
#define USART3_RX_GPIO_Port GPIOB
#define SPI_DC_Pin GPIO_PIN_6
#define SPI_DC_GPIO_Port GPIOC
#define SPI_RST_Pin GPIO_PIN_7
#define SPI_RST_GPIO_Port GPIOC
#define SPI_CS_Pin GPIO_PIN_8
#define SPI_CS_GPIO_Port GPIOC
#define UART4_TX_Pin GPIO_PIN_10
#define UART4_TX_GPIO_Port GPIOC
#define UART4_RX_Pin GPIO_PIN_11
#define UART4_RX_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_4
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_5
#define LED2_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_6
#define LED3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
