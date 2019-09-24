/*
 * LCD.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: yosry
 */

//Designed by: Ali Shawky

#ifndef LCD_H_
#define LCD_H_

#include "Gpio.h"
#include "LIB/Bit_Math.h"
#include "LIB/Standard_Types.h"
#include "Registers.h"
#include "LCD_Config.h"
//#include "data_types.h"

/*Initilizing LCD*/
void LCD_Init(void);
/*sending commands*/
void LCD_WriteCommand(uint8 cmd);
/*sending data*/
void LCD_WriteCharacter(uint8 chr);
/*sending string*/
void LCD_WriteString(uint8* str);
/*sending integer*/
void LCD_WriteInteger(uint32 intgr);
/*GOTO LOCATION*/
void LCD_GoTo(uint8 row,uint8 col);
/*clear lcd*/
void LCD_Clear(void);



#endif /* LCD_H_ */
