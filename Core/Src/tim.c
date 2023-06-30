/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    tim.c
 * @brief   This file provides code for the configuration
 *          of the TIM instances.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* TIM6 init function */
void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

//  LL_TIM_InitTypeDef TIM_InitStruct = {0};
//
//  /* Peripheral clock enable */
//  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM6);
//
//  /* TIM6 interrupt Init */
//
//
//  /* USER CODE BEGIN TIM6_Init 1 */
//
//  /* USER CODE END TIM6_Init 1 */
//  TIM_InitStruct.Prescaler = 4800;
//  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
//  TIM_InitStruct.Autoreload = 10000-LL_TIM_IC_FILTER_FDIV1_N2;
//  LL_TIM_Init(TIM6, &TIM_InitStruct);
//  LL_TIM_DisableARRPreload(TIM6);
//  /* USER CODE BEGIN TIM6_Init 2 */
//
//    TIM6->DIER |= TIM_DIER_UIE;
//    /* Start Timer */
//    TIM6->CR1 |= TIM_CR1_CEN;
//    NVIC_SetPriority(TIM6_IRQn, 0);
//      NVIC_EnableIRQ(TIM6_IRQn);
//    /* These are CMSIS calls to enable interrupts */

	 // Enable the TIM6 clock
	    RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

	    // Configure the TIM6 prescaler and auto-reload value
	    TIM6->PSC = 48000000/479;
	    TIM6->ARR = 25000-1;

	    // Enable the update event interrupt
	    TIM6->DIER |= TIM_DIER_UIE;

	    // Enable the TIM6 interrupt in the NVIC
	    NVIC_EnableIRQ(TIM6_IRQn);

	    // configure the priority of the interrupt
	    NVIC_SetPriority(TIM6_IRQn, 1);

	    // Enable the timer
	    TIM6->CR1 |= TIM_CR1_CEN;
  /* USER CODE END TIM6_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
