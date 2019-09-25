/*
 * KeyPad.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ali
 */

//Designed by: Ali Shawky


/**************************************
 *         included files
 **************************************/
#include "KeyPad.h"

/**************************************
 *         KEYPAD Application
 **************************************/
const uint8 KeyVal[3][3]={{'Y','N','9'},
		{'4','5','6'},
		{'1','2','3'}};


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
void KeyPad_Init(void)
{
	DIO_SetPinDirection(col1,OUTPUT);
	DIO_SetPinDirection(col2,OUTPUT);
	DIO_SetPinDirection(col3,OUTPUT);
	DIO_SetPinDirection(row1,INPUT);
	DIO_SetPinDirection(row2,INPUT);
	DIO_SetPinDirection(row3,INPUT);
	DIO_WritePin(col1,HIGH);
	DIO_WritePin(col2,HIGH);
	DIO_WritePin(col3,HIGH);
	DIO_WritePin(row1,HIGH);
	DIO_WritePin(row2,HIGH);
	DIO_WritePin(row3,HIGH);
}


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
Button_Status Get_KeyVal(uint8* Value_ptr)
{
	/*the current column position*/
	uint8 Col_Loc = 0;
	/*the current row position*/
	uint8 Row_Loc = 0;
	/*the temp variable to check if a button is pressed*/
	uint8 Temp = 0;
	/*the returned status of the button*/
	Button_Status returned_Status = Not_Pressed;
	/*the current status of the button*/
	static Button_Status Status = Not_Pressed;


	/*looping on the columns*/
	for(Col_Loc = 0 ; Col_Loc <= 2 ; Col_Loc++ )
	{
		/*output value zero on the columns*/
		DIO_WritePin((Col_Loc+col1) , LOW);
		/*looping on the rows*/
		for(Row_Loc = 0 ; Row_Loc <= 2 ; Row_Loc++ )
		{
			/*hold the current value of this current button*/
			Temp = DIO_ReadPin(Row_Loc + row1);
			/*checking if this current button is pressed and this button  is in columns 0('Y' button)
			 *   or columns 1('N' button) and in row0*/
			if((!Temp) && ((Col_Loc == 0) || (Col_Loc == 1))  && (Row_Loc == 0) )
			{
				/*checking the status of the button*/
				switch(Status)
				{
				/*in the first calling of the scheduler (after 20ms) and the button is
				 *  pressed it's status will be changed to Pre_Pressed*/
				case Not_Pressed:

					Status = Pre_Pressed;

					break;
					/*in the second calling of the scheduler (after another 20ms) and the button is
					 *  pressed it's status will be changed to Pressed
					 *  the total passed time of pressing should be 40 ms*/
				case Pre_Pressed:

					Status = Pressed;

					break;
					/*if the button is pressed get the pressed button value and return status: pressed*/
				case Pressed:

					*Value_ptr = KeyVal[Row_Loc][Col_Loc];
					returned_Status = Pressed;
					Status = Not_Pressed;

					break;

				default:
					break;
			}

		}
			/*if the button is released*/
		else if((Temp==1) && ((Col_Loc == 0) || (Col_Loc == 1))  && (Row_Loc == 0))
		{
			/*the current button status is Not_Pressed*/
			Status = Not_Pressed;
			/*the returned status is Not_Pressed*/
			returned_Status = Status;
		}
	}
		/*output value high on the columns*/
	DIO_WritePin((Col_Loc+col1) , HIGH);

	}
	/*return the status of the button*/
return returned_Status;

}
