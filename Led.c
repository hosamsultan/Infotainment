/*
 * Led.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Hossam-PC
 */


#include "Led.h"

/*****************************************************************/
					/*Toggle 0 Function*/

void toggle_led0(void)
{
	PORTB^=1<<4;

	//DIO_WritePin(LED0,DIO_ReadPin(LED0)^1);
	/*if(DIO_ReadPin(LED0)==LOW)
	{
	DIO_WritePin(LED0,HIGH);
	}
	else
	{
		DIO_WritePin(LED0,LOW);
	}*/
}

/*****************************************************************/
					/*Init LED0 Function*/
void LED0_Init(void)
{
	DIO_SetPinDirection(LED0,OUTPUT);
	DIO_WritePin(LED0,LOW);
}
/*****************************************************************/
					/*Toggle 1 Function*/
void toggle_led1(void)
{
	PORTB^=1<<5;

}



/*****************************************************************/
					/*Init LED1 Function*/
void LED1_Init(void)
{
	DIO_SetPinDirection(LED1,OUTPUT);
	DIO_WritePin(LED1,LOW);
}
/*****************************************************************/
					/*Toggle 2 Function*/

void toggle_led2(void)
{
	PORTB^=1<<6;

}
/*****************************************************************/
					/*Init LED3 Function*/
void LED2_Init(void)
{
	DIO_SetPinDirection(LED2,OUTPUT);
	DIO_WritePin(LED2,LOW);
}

/*****************************************************************/
					/*Toggle 3 Function*/

void toggle_led3(void)
{
	PORTB^=1<<7;

}
/*****************************************************************/
					/*Init LED3 Function*/
void LED3_Init(void)
{
	DIO_SetPinDirection(LED3,OUTPUT);
	DIO_WritePin(LED3,LOW);
}

void LED0_ON(void)
{
	DIO_WritePin(LED0,HIGH);

}
void LED1_ON(void)
{
	DIO_WritePin(LED1,HIGH);

}

void LED2_ON(void)
{
	DIO_WritePin(LED2,HIGH);

}

void LED3_ON(void)
{
	DIO_WritePin(LED3,HIGH);

}
/*******************************************************
 * 														*
 * 														*
 * 														*
 * 														*
 * 														*
 * 														*
 * 														*
 * 														*
 * 														*
 * ******************************************************/
