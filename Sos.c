/*
 * SOS.c
 *
 *  Created on: Sep 16, 2019
 *      Author: Hossam-PC
 */

/**********************************************************************************
* 					Included Libraries
**********************************************************************************/
#include "Sos.h"
/**********************************************************************************
* 					Used Global Variables
**********************************************************************************/
uint16 uint16count;
uint32 Counter_Flag=0;
EnumErorrState correctflag=OK;
uint16 maxprior=0;
//uint8 ready_counter=0;
uint16 Readytasks[no_tasks];

/**********************************************************************************
* 					Functions Definitions
**********************************************************************************/


/**************************************************************************
 * Function Name : Sos_Init
 *
 * Description	 : start the timer and configure the ocr0 register to have an interrupt every 1ms and enable
 *  compare match interrupt and the global interrupt
 *
 * INPUTS		 : pointer to function ptr,uint16 u16period,uint16 u16prior,uint16 u16ID
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void Sos_Init(void)
{
	uint16 u16counter_flag;
	for(u16counter_flag=0;u16counter_flag<no_tasks;u16counter_flag++)
	{
		sys_tasks[u16counter_flag].u8Reserved_Flag=0;
	}
	Timer0_init(&CallbackfromTimer);
	Timer0_Set_OCR0(130);
	Timer0_Input_capture_Interrupt_Enable();
	Global_Interrupt_Enable();
}
/**************************************************************************
 * Function Name : Sos_create_Task
 *
 * Description	 :  create the task with the desired priority ,periodicty ,ID and pointer
 *  to the address of that task
 *
 * INPUTS		 : pointer to function ptr,uint16 u16period,uint16 u16prior,uint16 u16ID
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void Sos_create_Task(void (*ptr)(void),uint16 u16period,uint16 u16prior,uint16 u16ID)
{
		sys_tasks[u16ID].fptr_Task=ptr;
		sys_tasks[u16ID].u16periodicity=u16period;
		sys_tasks[u16ID].u16priority=u16prior;
		sys_tasks[u16ID].u8Reserved_Flag=1;
		sys_tasks[u16ID].Task_State=READY;
}
/**************************************************************************
 * Function Name : Sos_Run
 *
 * Description	 : Running the scheduler with inside it while(1) which manage tasks and check the highest priority task and run it .
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void Sos_Run(void)
{
	uint8 run_counter=0;
	while(1)
	{
		for(run_counter=0;run_counter<no_tasks;run_counter++)
		{
			if( (sys_tasks[run_counter].Task_State == READY))  /*(sys_tasks[run_counter].u16priority) == maxprior) &&*/
			{
				sys_tasks[run_counter].Task_State=RUNNING;
				sys_tasks[run_counter].fptr_Task();
				sys_tasks[run_counter].Task_State=WAITING;

			}
		}
	}
	CPU_Sleep();

}
/**************************************************************************
 * Function Name : Sos_Delete_Task
 *
 * Description	 : delete the task with the id
 *
 * INPUTS		 : uint16 ID_of_Task
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void Sos_Delete_Task(uint16 ID_of_Task)
{
	uint8 check_ID_counter;
	for(check_ID_counter=0;check_ID_counter<no_tasks;check_ID_counter++)
	{
		if(sys_tasks[check_ID_counter].u16ID_of_Task == ID_of_Task)
		{
			sys_tasks[check_ID_counter].fptr_Task=NULL;
			sys_tasks[check_ID_counter].Task_State=DELETED;
			break;
		}
	}
}

/**************************************************************************
 * Function Name : CallbackfromTimer
 *
 * Description	 : increment the counter flag which indicates the number of 1ms and then check which task has to be ready and change its state to ready
 *
 * INPUTS		 : void
 *
 * OUTPUTS 		 : void
 *
 * Return		 : void
 **************************************************************************/
void CallbackfromTimer(void)
{
	//maxprior=0;
	Counter_Flag++;
	for( uint16count=0;uint16count<no_tasks;uint16count++)
	{
		if(sys_tasks[uint16count].Task_State != DELETED)
		{
			if((Counter_Flag%sys_tasks[uint16count].u16periodicity) == 0u)
			{
				sys_tasks[uint16count].Task_State=READY;
				if(sys_tasks[uint16count].u16priority>maxprior)
				{
					maxprior=sys_tasks[uint16count].u16priority;
				}
			}
			else
			{
				sys_tasks[uint16count].Task_State=WAITING;
			}
		}
	}
}


void CPU_Sleep(void)/*CPU Sleep function*/
{
	Set_Bit(MCUCR,SE);	/*set the SE bit in MCUCSR Register to enable sleep mode*/
	Clr_Bit(MCUCR,SM0);/*IDLE mode*/
	Clr_Bit(MCUCR,SM1);
	Clr_Bit(MCUCR,SM2);
}

