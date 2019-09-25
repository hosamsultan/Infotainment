

/**********************************************************************************
 * 					Included Libraries
 **********************************************************************************/
#include "Gpio.h"
#include "SOS_Scheduler.h"
#include "Interrupt.h"
#include "KeyPad.h"
#include "LCD.h"

/**********************************************************************************
 * 					Used Enumerations
 **********************************************************************************/
typedef enum {
	YES_BUTTON = 1,
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
uint8 pressed_flag = 0;
ENUMButton_Name Button = 0;


/**********************************************************************************
 * 					Declarations of Tasks
 **********************************************************************************/
/*Init LED3 Function*/
void LED2_Init(void)
{
	DIO_SetPinDirection(LED2,OUTPUT);
	DIO_WritePin(LED2,LOW);
}

void toggle_led2(void)
{
	if(DIO_ReadPin(LED2)==LOW)
	{
		DIO_WritePin(LED2,HIGH);
	}
	else
	{
		DIO_WritePin(LED2,LOW);
	}
}


/**************************************************************************
 * Function Name : View_On_LCD
 *
 * Description	 : View On LCD Questions and check the answer by checking
 *                  the pressed buttons every 20ms .
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void View_On_LCD(void)
{
	/*variable holds the user choice if pressed 'Y' button to start game*/
	static uint8 accept = 0;
	/*looping if the number of questions is less than 5 questions*/
	if(Question_Counter < 5)
	{
		/*check if the user started the game*/
		switch (accept)
		{
		/*case not started yet*/
		case 0:
			/*display the game intro*/
			LCD_WriteString("let's play?");
			LCD_GoTo(1,0);
			LCD_WriteString("BUT1= Y / BUT2=N");

			/*if the user started the game*/
			if(Button==YES_BUTTON)
			{
				/*the user accepted*/
				accept = 1;
				LCD_Clear();
				/*ask the first question*/
				LCD_WriteString(Question[Question_Counter]);
				/*return the button to its initial status*/
				Button = 0;
			}

			/*if the user refused to start*/
			if(Button==NO_BUTTON)
			{
				/*refused to start*/
				accept = 0;
				/*return the button to its initial status*/
				Button = 0;
			}

			break;

			/*case he started the game*/
		case 1:
			/*if the user's answer is "yes"*/
			if(Button==YES_BUTTON)
			{
				/*checking the answer*/
				if(Answers[Question_Counter]==YES)
				{
					/*if true answer increase result*/
					Result++;

				}
				/*get the next question*/
				Question_Counter++;

				LCD_Clear();
				/*ask the next question*/
				LCD_WriteString(Question[Question_Counter]);
				/*reinitialize the button value*/
				Button = 0;

			}
			/*if the answer is "No"*/
			else if(Button==NO_BUTTON)
			{
				/*check the answer*/
				if(Answers[Question_Counter]==NO)
				{
					/*if correct increase the result*/
					Result++;
				}
				/*get the next question*/
				Question_Counter++;

				LCD_Clear();
				/*ask the next question*/
				LCD_WriteString(Question[Question_Counter]);
				/*reinitialize the button value*/
				Button = 0;
			}

			break;

		default:
			break;

		}
	}

/*if there is no more questions*/
	else if(Question_Counter == 5)
	{
		LCD_Clear();
		LCD_WriteString("Your Result= ");
		/*display the final result*/
		LCD_WriteInteger(Result);
	}

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
/*check if there's button pushed and it's value*/
	if(Get_KeyVal(&Button_pressed)==Pressed)
	{

		if(Button_pressed=='Y')
		{
			Button=YES_BUTTON;

		}
		else if(Button_pressed=='N')
		{
			Button=NO_BUTTON;
		}
	}
}


/*********************************************************/
/*main Function*/
int main(void)
{
	LCD_Init();
	KeyPad_Init();
	LED2_Init();

	SOS_Init();

	SOS_CreatTask(toggle_led2, 1000, 2, 1);
	SOS_CreatTask(View_On_LCD, 50, 1, 2);
	SOS_CreatTask(get_key, 20, 3, 0);

	SOS_Run();

	while(1)
	{


	}
	return 0;
}

