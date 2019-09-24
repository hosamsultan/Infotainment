/*
 * Interrupt.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */


#include "Interrupt.h"

void Global_Interrupt_Enable(void)
{
	Set_Bit(SREG,I);
}

void Timer1_overflow_Interrupt_Enable(void)
{
	Set_Bit(TIMSK,TOIE1);
}
void Timer0_overflow_Interrupt_Enable(void)
{
	Set_Bit(TIMSK,TOIE0);
}
void Timer1_Input_capture_Interrupt_Enable(void)
{
	Set_Bit(TIMSK,TICIE1);
}

void Ext2_Interrupt2_Enable(void)
{
    Set_Bit(GICR,INT2);
}

void Ext2_Interrupt2_Mode(uint8 mode)
{
	switch(mode)
		{
		case 0:
			 Clr_Bit(MCUCSR,ISC2);
			break;
		case 1:
			Set_Bit(MCUCSR,ISC2);
			break;
		}
}
void Global_Interrupt_Disable(void)
{
	Clr_Bit(SREG,I);
}

void Timer0_overflow_Interrupt_Disable()
{
	Clr_Bit(TIMSK,TOIE0);
}
