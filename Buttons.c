/*
 * Buttons.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Hossam-PC
 */
#include "Buttons.h"

#include "Gpio.h"
#include "del.h"
uint8 scan_btn1(void)  //keypad button 1 pull up resistor
{
	uint8 ret=0;
	if(DIO_ReadPin(btn1)==0)
		{
			del_ms(30);
			if(DIO_ReadPin(btn1)==0)
			{
				ret=1;
			}
		}
	return ret;
}

uint8 scan_btn0(void)  //button pull down resistor
{
	uint8 ret=0;
	if(DIO_ReadPin(btn0))
		{
			del_ms(30);
			if(DIO_ReadPin(btn0))
			{
				ret=1;
			}
		}
	return ret;
}
