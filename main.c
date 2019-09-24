/**********************************************************************************
* 					Included Libraries
**********************************************************************************/
#include "Sos.h"
#include "KYP_int.h"
#include "LCD.h"

/**********************************************************************************
* 					Declarations of Tasks
**********************************************************************************/

void get_key(void);
/**********************************************************************************
* 					Used Enumerations
**********************************************************************************/

typedef enum {
	YES_BUTTON,
	NO_BUTTON
}ENUMButton_Name;


typedef enum {
	NO,
	YES
}ENUMAnswer;
/**********************************************************************************
* 					Used Global Variables
**********************************************************************************/
uint8 Question[5][20]={"how old","how long","how much","what time","do you want"};

ENUMAnswer Answers[5]={YES,NO,NO,NO,YES};

uint8 Result=0;
uint8 Button_pressed=0;
uint8 Question_Counter=0;
ENUMButton_Name Button;

int main(void)
{
	LCD_Init();
	Sos_create_Task(&get_key,10,1,0);  				/*Create the get key function as task 1 on the OS*/
	Sos_create_Task(&View_On_LCD,20,2,1);			/*Create the view on LCD function as task 2 on the OS*/
	Sos_Init();    /*Init OS*/
	Sos_Run();		/*Run OS*/
	while(1)
	{

	}
	return 0;
}
/**************************************************************************
 * Function Name : get_key
 *
 * Description	 : get the pressed key and it repeated every 10ms .
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/

void get_key(void)
{
	if(Kyp_getPressedButton(&Button_pressed)==PRESSED)
	{
		if(Button_pressed==1)     /*if button 1 is pressed*/
		{
			Button=YES_BUTTON;
		}
		else if(Button_pressed==2)
		{
			Button=NO_BUTTON;
		}
		button_state=NOT_PRESSED;
	}
}
/**************************************************************************
 * Function Name : View_On_LCD
 *
 * Description	 : View On LCD Questions and check the answer by checking the pressed buttons every 20ms .
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void View_On_LCD(void)
{
	if(Question_Counter<5)
	{
		LCD_Clear();
		LCD_WriteString(Question[Question_Counter]);

		if(Button==YES_BUTTON)
		{
			if(Answers[Question_Counter]==YES)
			{
				Result++;
				Question_Counter++;
			}
		}
		else if(Button==NO_BUTTON)
		{
			if(Answers[Question_Counter]==NO)
			{
				Result++;
				Question_Counter++;
			}
		}
	}
	else
	{
		LCD_Clear();
		LCD_WriteString("Your Result= ");
		LCD_WriteInteger(Result);
	}
}
