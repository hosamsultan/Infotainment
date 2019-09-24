
//Designed by: Ali Shawky



#include "util/delay.h"
#include "LCD.h"
/* ---------------------------------    INITIALIZE LCD  --------------------------------------------------   */
void LCD_Init(void)
{


	/*INITIALIZE LCD PINS DIRECTION*/
	DIO_SetPinDirection( LCD_E_PIN,OUTPUT);
	DIO_SetPinDirection( LCD_RW_PIN,OUTPUT);
	DIO_SetPinDirection( LCD_RS_PIN,OUTPUT);


	DIO_SetPinDirection( LCD_D4,OUTPUT);
	DIO_SetPinDirection( LCD_D5,OUTPUT);
	DIO_SetPinDirection( LCD_D6,OUTPUT);
	DIO_SetPinDirection( LCD_D7,OUTPUT);

	_delay_us(100);

	/*SEND 4BIT LCD_Mode COMMANDS*/
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	LCD_WriteCommand(0x0c);
	LCD_WriteCommand(0x01);
	LCD_WriteCommand(0x06);
	LCD_WriteCommand(0x02);

}


/*  ---------------------------------    SENDING COMMANDS  ------------------------------------------------  */

void LCD_WriteCommand(uint8 cmd)
{

	DIO_WritePin(LCD_RW_PIN, LOW);
	DIO_WritePin(LCD_RS_PIN, LOW);
	DIO_WritePin(LCD_E_PIN, LOW);

	LCD_4BIT_PORT = (cmd & 0xf0) | (LCD_4BIT_PORT & 0x0f);

	DIO_WritePin(LCD_E_PIN, HIGH);
	_delay_us(100);
	DIO_WritePin(LCD_E_PIN, LOW);

	LCD_4BIT_PORT = (cmd << 4) | (LCD_4BIT_PORT & 0x0f);

	DIO_WritePin(LCD_E_PIN, HIGH);
	_delay_us(100);
	DIO_WritePin(LCD_E_PIN, LOW);
	_delay_us(500);

}


/*  ---------------------------------  SENDING DATA   --------------------------------------------------  */


void LCD_WriteCharacter(uint8 chr)
{

	DIO_WritePin(LCD_RW_PIN, LOW);
	DIO_WritePin(LCD_RS_PIN, HIGH);
	DIO_WritePin(LCD_E_PIN, LOW);

	LCD_4BIT_PORT = (chr & 0xf0) | (LCD_4BIT_PORT & 0x0f);

	DIO_WritePin(LCD_E_PIN, HIGH);
	_delay_us(100);
	DIO_WritePin(LCD_E_PIN, LOW);

	LCD_4BIT_PORT = (chr << 4) | (LCD_4BIT_PORT & 0x0f);

	DIO_WritePin(LCD_E_PIN, HIGH);
	_delay_us(100);
	DIO_WritePin(LCD_E_PIN, LOW);
	_delay_us(500);

}


/* ---------------------------------  WRITE A STRING  --------------------------------------------------  */


void LCD_WriteString(uint8* str)
{
	uint8 i= 0;

	while(str[i] !='\0')
	{
		LCD_WriteCharacter(str[i]);
		i++;
	}
}


/*  ---------------------------------  WRITE INTEGER --------------------------------------------------  */

void LCD_WriteInteger(uint32 intgr)
{


	uint32 y = 1;

	while(intgr > 0)
	{
		y = ((y*10) + (intgr%10));
		intgr /= 10;
	}

	while(y > 1 )
	{
		LCD_WriteCharacter(((y%10)+48));
		y /= 10;
	}

}

/*  ---------------------------------  GOTO SPECIFIC LOCATION  -------------------------------------------------- */

void LCD_GoTo(uint8 row,uint8 col)
{
	uint8 arr[2] = {0x80,0xc0};

	LCD_WriteCommand(arr[row]+col);

}


/*  ---------------------------------  CLEAR LCD  --------------------------------------------------  */

void LCD_Clear(void)
{

	LCD_WriteCommand(0x01);
}





