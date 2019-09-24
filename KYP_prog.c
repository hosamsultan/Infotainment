/*
 * KYP_prog.c
 *
 *  Created on: May 31, 2019
 *      Author: Hossam-PC
 */

#include "LIB/Standard_Types.h"
#include "Gpio.h"
#include "KYP_int.h"
Button_status button_state=NOT_PRESSED;
void KYP_vidInit(void)
{
	//c1->c3 are input // r1->r3 are output
	DIO_SetPinDirection(col1,INPUT);
	DIO_SetPinDirection(col2,INPUT);
	DIO_SetPinDirection(col3,INPUT);
	DIO_SetPinDirection(row1,OUTPUT);
	DIO_SetPinDirection(row2,OUTPUT);
	DIO_SetPinDirection(row3,OUTPUT);
	DIO_WritePin(col1,HIGH);
	DIO_WritePin(col2,HIGH);
	DIO_WritePin(col3,HIGH);

}

Button_status Kyp_getPressedButton(uint8* Button_Num)
{
	uint8 buttonvalue=0;
	uint8 col=0;
	uint8 row=0;
	for(col=0;col<3;col++)
	{
		DIO_WritePin((col1+col),LOW);
		for(row=0;row<3;row++)
		{
			if(DIO_ReadPin(row1+row)==0)
			{
				buttonvalue=(row*3)+col+1;
			}
		}
		DIO_WritePin((col1+col),HIGH);
	}
		if(buttonvalue)
		{
			if(((buttonvalue==1)||(buttonvalue==2))&&button_state==NOT_PRESSED)
			{
				button_state=PRE_PRESSED;
			}
			else
			{
				button_state=NOT_PRESSED;
			}
		}
		else
		{
			button_state=NOT_PRESSED;
		}
		switch(button_state)
		{
		case NOT_PRESSED:
			break;

		case PRE_PRESSED:
			button_state=PRESSED;
			break;

		case PRESSED:
			if((buttonvalue==1)||(buttonvalue==0))
			{
				if(buttonvalue==1)
				{
					*Button_Num=1;
				}
				else if(buttonvalue==2)
				{
					*Button_Num=2;
				}
				else
				{
					*Button_Num=0;
				}
			}
			else
			{
				*Button_Num=0;
			}
			button_state=NOT_PRESSED;
			break;

		default:
			break;
		}
	return button_state;
}
