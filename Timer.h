/*
 * Timer.h
 *
 *  Created on: Aug 18, 2019
 *      Author: Hossam-PC
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "LIB/Standard_Types.h"
#include "Registers.h"

#define NULL (void*)(0)

/************************************************/
          /*bits used in TCCR0*/
#define FOC0 	7
#define WGM00	6
#define COM01 	5
#define COM00	4
#define WGM01	3
#define CS02 	2
#define CS01 	1
#define CS00 	0

#define OCIE0 	1



#define OCF0	1

#define __INTR_ATTRS used,externally_visible

void Timer0_init(void(*CallBack)(void));

void Timer0_Deinit(void);

void Timer0_Set_TCNT0(uint8 value);

void timer_delay(uint32 n);

void Check1ms(void);

void Timer0_Input_capture_Interrupt_Enable(void);

void Timer0_Set_OCR0(uint8 value);

#endif /* TIMER_H_ */
