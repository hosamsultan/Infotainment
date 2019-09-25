/*
 * KeyPad.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: yosry
 */

//Designed by: Ali Shawky

#ifndef KEYPAD_H_
#define KEYPAD_H_


/*************************************
 *        the included files
 ************************************/
#include "util/delay.h"
#include "LIB/Bit_Math.h"
#include "LIB/Standard_Types.h"
#include "Gpio.h"
#include "KeyPad_Config.h"
#include "Registers.h"


/*************************************
 * the status of the pushed buttons
 ************************************/
typedef enum
{
	Not_Pressed,
	Pre_Pressed,
	Pressed,
	Pre_Released,
	Released
}Button_Status;

/*******************************************************************
 * function name: KeyPad_Init
 *
 * arguments: input: (name: none ,type: none ,description: none ) ;
 *            output:
 *            input/output:
 *
 * return: void
 *
 * description: this function initialize the key pad
 *
 ******************************************************************/
void KeyPad_Init(void);

/*************************************************************************
 * function name: Get_KeyVal
 *
 * arguments: input: (name: Value_ptr ,type: uint8* ,description: pointer
 *                      holds the value of pushed button  ) ;
 *            output:
 *            input/output:
 *
 * return: status of the button
 *
 * description: this function checks if any key is pressed and returns the
 *               value of that button and it's status
 *
 ****************************************************************************/
Button_Status Get_KeyVal(uint8* Value_ptr);

#endif /* KEYPAD_H_ */
