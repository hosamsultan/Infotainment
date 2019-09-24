/*
 * Led.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Hossam-PC
 */

#ifndef LED_H_
#define LED_H_

	#include "LIB/Standard_Types.h"
	#include "Gpio.h"

	void toggle_led0(void);
	void LED0_Init(void);

	void toggle_led1(void);
	void LED1_Init(void);

	void toggle_led3(void);
	void LED3_Init(void);

	void toggle_led2(void);
	void LED2_Init(void);

	void LED0_ON(void);
	void LED1_ON(void);
	void LED2_ON(void);
	void LED3_ON(void);

#endif /* LED_H_ */
