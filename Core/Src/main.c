/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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


int SampleSoundG() {
	uint32_t start_millis = Millis();  // Start of sample window
	// the peak to peak reading will be the total loudness change across the
	// sample wiindow!
	int peak_to_peak = 0; // peak_to_peak level
	int sample = 0;
	int signal_max = 0;
	int signal_min = 4096;

	// collect data for duration of g_sample_window
	while (Millis() - start_millis < 50) {
		ADC1->CHSELR = ADC_CHSELR_CHSEL9;
		ADC1->CR |= ADC_CR_ADSTART;
		while (ADC1->CR & ADC_CR_ADSTART)
			;
		sample = ADC1->DR;

		if (sample < 4096) // toss out spurious readings
				{
			if (sample > signal_max) {
				signal_max = sample; // save just the max levels
			} else if (sample < signal_min) {
				signal_min = sample; // save just the min levels
			}
		}
	}
	peak_to_peak = signal_max - signal_min; // max - min = peak-peak amplitude
	return (peak_to_peak);
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
  LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC_Init();
  MX_SPI1_Init();
  MX_I2C1_Init();
  MX_TIM6_Init();
  /* USER CODE BEGIN 2 */

	SysTick_Config(SystemCoreClock / 1000);

	LL_SPI_Enable(SPI1);

	LCD_init();
	LCD_BL_ON
	;


	LCD_print("Elo mordo", 0, 0);
	Delay_ms(1000);
	ADC1->CR = ADC_CR_ADCAL;
	while (ADC1->CR & ADC_CR_ADCAL)
		;

	ADC1->CFGR1 = ADC_CFGR1_OVRMOD;
	ADC1->CFGR2 = ADC_CFGR2_CKMODE_1;
	ADC1->SMPR = ADC_SMPR_SMP;
	ADC1->CHSELR = ADC_CHSELR_CHSEL16;
	ADC->CCR = ADC_CCR_VREFEN | ADC_CCR_TSEN;
	ADC1->CR = ADC_CR_ADEN;
	LCD_clrScr();


	while (!(ADC1->ISR & 1))
		;


	menu_refresh();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
		//if( BUTTON_START/*||BUTTON_3||BUTTON_START||BUTTON_STOP ||BUTTON_1) {BUZZ_ON;}
		//	else {BUZZ_OFF;}
		/*
		 if(BUTTON_MAIN ) {last_shoot = 0; last_shootG = 0;}*/
		//if(BUTTON_MAIN ) LL_GPIO_ResetOutputPin(POWER_ALL_GPIO_Port, POWER_ALL_Pin);
		 key_next_press();
		 key_prev_press();
		 key_esc_press();
		 key_ok_press();
		 key_start_press();
		 key_stop_press();

		 menu_refresh();


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
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_1);
  while(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_1)
  {
  }
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_HSI14_Enable();

   /* Wait till HSI14 is ready */
  while(LL_RCC_HSI14_IsReady() != 1)
  {

  }
  LL_RCC_HSI14_SetCalibTrimming(16);
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE_DIV_1, LL_RCC_PLL_MUL_3);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_Init1msTick(48000000);
  LL_SetSystemCoreClock(48000000);
  LL_RCC_HSI14_EnableADCControl();
  LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_HSI);
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
	while (1) {
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
