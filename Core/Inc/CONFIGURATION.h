/*
 * CONFIGURATION.h
 *
 *  Created on: May 28, 2021
 *      Author: Ollie
 */

#ifndef INC_CONFIGURATION_H_
#define INC_CONFIGURATION_H_

#define LCD_BL_ON  lcd_bl_GPIO_Port->ODR &= ~lcd_bl_Pin; // 1
#define LCD_BL_OFF lcd_bl_GPIO_Port->ODR |= lcd_bl_Pin; // 0
#define BUZZ_OFF  BUZZER_GPIO_Port->ODR &= ~BUZZER_Pin; // 1
#define BUZZ_ON BUZZER_GPIO_Port->ODR |= BUZZER_Pin; // 0
#endif /* INC_CONFIGURATION_H_ */
