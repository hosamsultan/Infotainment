#ifndef _Gpio_INT_H
#define _Gpio_INT_H
#include  "LIB/Standard_Types.h"
#include "Registers.h"

#define INPUT  0
#define OUTPUT 1

#define HIGH   1
#define LOW    0

	/* PIN MAPPING*/

#define LED0	12
#define LED1	13
#define LED2	14
#define LED3	15
	/*buttons*/
#define btn0    20
#define btn1    10


	/*wifi*/
#define WIFI_CH_EN	16


	/* keypad rows*/
#define row1    18
#define row2    19
#define row3    20

/*keypad coloumns*/
#define col1	21
#define col2	22
#define col3	23




////////////////////////////////////////

void DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection);

#endif
