
#include "LIB/Bit_Math.h"
#include "Gpio.h"



void DIO_WritePin(uint8 PinNum,uint8 PinValue)
{
	if(PinValue==LOW)
	{
		if((PinNum>=0)&&(PinNum<=7))   //PORT A
		{
			Clr_Bit(PORTA,PinNum);
		}

		else if((PinNum>=8)&&(PinNum<=15)) // PORT B
		{
			Clr_Bit(PORTB,(PinNum-8));
		}
		
		else if((PinNum>=16)&&(PinNum<=23)) //PORT C
		{
			Clr_Bit(PORTC,(PinNum-16));
		}
		else if((PinNum>=24)&&(PinNum<=31)) //PORT D
		{
			Clr_Bit(PORTD,(PinNum-24));
		}
	}
	else if(PinValue==HIGH)
	{
		if(PinNum>=0&&PinNum<=7)	//PORT A
		{
			Set_Bit(PORTA,PinNum);
		}
		
		else if((PinNum>=8&&PinNum<=15))	//PORT B
		{
			Set_Bit(PORTB,(PinNum-8));
		}
		else if((PinNum>=16&&PinNum<=23))	//PORT C
		{
			Set_Bit(PORTC,(PinNum-16));
		}
		
		else if((PinNum>=24&&PinNum<=31))	//PORT D
		{
			Set_Bit(PORTD,(PinNum-24));
		}
	}
}


uint8 DIO_ReadPin(uint8 PinNum)
{
	uint8 res=0;
	if((PinNum>=0)&&(PinNum<=7))	//PORT A
	{
		res= Get_Bit(PINA,PinNum);
	}
	
	else if((PinNum>=8)&&(PinNum<=15))	//PORT B
	{
		res= Get_Bit(PINB,(PinNum-8));
	}
	
	else if((PinNum>=16)&&(PinNum<=23))	//PORT C
	{
		res= Get_Bit(PINC,(PinNum-16));
	}
	
	else if((PinNum>=24)&&(PinNum<=31))	//PORT D
	{
		res= Get_Bit(PIND,(PinNum-24));
	}

	return res;
	
}


void DIO_SetPinDirection(uint8 PinNum,uint8 PinDirection)
{
	if(PinDirection==OUTPUT)						//set pin direction high
	{
		if((PinNum>=0)&&(PinNum<=7))	//PORT A
		{
			Set_Bit(DDRA,PinNum);
		}
	
		else if((PinNum>=8)&&(PinNum<=15))	//PORT B
		{
			Set_Bit(DDRB,(PinNum-8));
		}
	
		else if((PinNum>=16)&&(PinNum<=23))	//PORT C
		{
			Set_Bit(DDRC,(PinNum-16));
		}
	
		else if((PinNum>=24)&&(PinNum<=31))		//PORT D
		{
			Set_Bit(DDRD,(PinNum-24));
		}
	}
	else if(PinDirection==INPUT)
	{
		if(PinNum>=0&&PinNum<=7)	//PORT A
		{
			Clr_Bit(DDRA,PinNum);
		}
	
		else if((PinNum>=8)&&(PinNum<=15))	//PORT B
		{
			Clr_Bit(DDRB,(PinNum-8));
		}
			
		else if((PinNum>=16)&&(PinNum<=23))	//PORT C
		{
			Clr_Bit(DDRC,(PinNum-16));
		}
			
		else if((PinNum>=24)&&(PinNum<=31)) 	//PORT D

		{
			Clr_Bit(DDRD,(PinNum-24));
		}
	}
}
