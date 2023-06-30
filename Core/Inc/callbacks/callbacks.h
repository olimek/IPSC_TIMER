/*
 * callbacks.h
 *
 *  Created on: 16 cze 2022
 *      Author: Ollie
 */

#ifndef INC_CALLBACKS_H_
#define INC_CALLBACKS_H_

void INFO_MODE_refresh(void);
void INFO_MODE_callback(void);
void COM_MODE_refresh(void);
void VIR_MODE_refresh(void);
void TRAIN_MODE_refresh(void);

void screen_orientation_callback(void);
void motor_flux_callback(void);

#endif /* CALLBACKS_H_ */
