/*
  * Timer.c
 *
 *  Created on: Aug 18, 2019
 *      Author: Hossam-PC
 */
#include "Timer.h"
#include "LIB/Bit_Math.h"
#include "LIB/Standard_Types.h"


volatile uint8 counter=0;

 void(*Function_Ptr)(void);
/*************************************************************/
		/*timer0 initial*/
void Timer0_init(void)
{


}

/*************************************************************/
		/*timer0 set TCNT0*/
void Timer0_Set_TCNT0(uint8 value)
{
    TCNT0 = value;
}
/*************************************************************/
		/*timer0 set OCR0*/
void Timer0_Set_OCR0(uint8 value)
{
    OCR0 = value;
    TCCR0 |= (1 << CS00); /*prescaler=64*/
    TCCR0 |= (1 << CS01);
}

/*************************************************************/
		/*timer0 delay*/
void timer_delay(uint32 n)
{
	uint32 i;
	OCR0=249;
	TCNT0=0;
	for(i=0;i<n/2;i++)
	{
		while((TIFR&OCF0)==0);	//	(polling on OCF0 flag)
		Set_Bit(TIFR,OCF0);
	}

}

/*************************************************************/
		/*timer0 Deinit*/
void Timer0_Deinit(void)
{
	Clr_Bit(TCCR0,CS00);
	Clr_Bit(TCCR0,CS01);
	Clr_Bit(TCCR0,CS02);
}

/*************************************************************/
		/*timer0 Input_capture_Interrupt_Enable*/
void Timer0_Interrupt_Enable(void)
{
	Set_Bit(TIMSK,OCIE0);
}
void SetCallBack(void(*CallFunction_Ptr)(void))
{
	Function_Ptr = CallFunction_Ptr;
}
/*****************************************************************/
					/*ISR Compare match*/
void __vector_10(void) __attribute__((signal,__INTR_ATTRS));
void __vector_10(void)
{
	Function_Ptr();
}

