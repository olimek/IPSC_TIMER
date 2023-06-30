/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#include "stm32f0xx_ll_adc.h"
#include "stm32f0xx_ll_i2c.h"
#include "stm32f0xx_ll_crs.h"
#include "stm32f0xx_ll_rcc.h"
#include "stm32f0xx_ll_bus.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_ll_exti.h"
#include "stm32f0xx_ll_cortex.h"
#include "stm32f0xx_ll_utils.h"
#include "stm32f0xx_ll_pwr.h"
#include "stm32f0xx_ll_dma.h"
#include "stm32f0xx_ll_spi.h"
#include "stm32f0xx_ll_tim.h"
#include "stm32f0xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdbool.h>
#include "font.h"
#include "nokia5110_LCD.h"
#include "stm32f0xx_it.h"
#include  <stdlib.h>
#include "adc.h"
#include "i2c.h"
#include "spi.h"
#include "gpio.h"
#include "menu.h"
#include "CONFIGURATION.h"
#include "callbacks/callbacks.h"
#include "callbacks/par_callbacks.h"
#include "callbacks/train_callbacks.h"
//#include "menu.h"
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


#define BUTTON_MAIN !(GPIOC->IDR&(1<<9))
#define BUTTON_1 !(GPIOC->IDR&(1<<8))
#define BUTTON_2 !(GPIOA->IDR&(1<<8))
#define BUTTON_3 !(GPIOA->IDR&(1<<9))
#define BUTTON_STOP !(GPIOA->IDR&(1<<11))
#define BUTTON_START !(GPIOA->IDR&(1<<10))
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define POWER_ALL_Pin LL_GPIO_PIN_0
#define POWER_ALL_GPIO_Port GPIOA
#define USB_CS_Pin LL_GPIO_PIN_2
#define USB_CS_GPIO_Port GPIOA
#define ADC_MIC_NG_Pin LL_GPIO_PIN_4
#define ADC_MIC_NG_GPIO_Port GPIOA
#define lcd_bl_Pin LL_GPIO_PIN_6
#define lcd_bl_GPIO_Port GPIOA
#define MIC_IN_Pin LL_GPIO_PIN_1
#define MIC_IN_GPIO_Port GPIOB
#define MIC_SHDN_Pin LL_GPIO_PIN_2
#define MIC_SHDN_GPIO_Port GPIOB
#define MIC_GAIN_Pin LL_GPIO_PIN_10
#define MIC_GAIN_GPIO_Port GPIOB
#define MIC_A_R_Pin LL_GPIO_PIN_11
#define MIC_A_R_GPIO_Port GPIOB
#define LED1_Pin LL_GPIO_PIN_14
#define LED1_GPIO_Port GPIOB
#define LED2_Pin LL_GPIO_PIN_15
#define LED2_GPIO_Port GPIOB
#define BUZZER_Pin LL_GPIO_PIN_7
#define BUZZER_GPIO_Port GPIOC
#define EEPROM_WC_Pin LL_GPIO_PIN_5
#define EEPROM_WC_GPIO_Port GPIOB
#ifndef NVIC_PRIORITYGROUP_0
#define NVIC_PRIORITYGROUP_0         ((uint32_t)0x00000007) /*!< 0 bit  for pre-emption priority,
                                                                 4 bits for subpriority */
#define NVIC_PRIORITYGROUP_1         ((uint32_t)0x00000006) /*!< 1 bit  for pre-emption priority,
                                                                 3 bits for subpriority */
#define NVIC_PRIORITYGROUP_2         ((uint32_t)0x00000005) /*!< 2 bits for pre-emption priority,
                                                                 2 bits for subpriority */
#define NVIC_PRIORITYGROUP_3         ((uint32_t)0x00000004) /*!< 3 bits for pre-emption priority,
                                                                 1 bit  for subpriority */
#define NVIC_PRIORITYGROUP_4         ((uint32_t)0x00000003) /*!< 4 bits for pre-emption priority,
                                                                 0 bit  for subpriority */
#endif

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
