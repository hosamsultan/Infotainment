/*
 *  SOS_Scheduler.c
 *
 *  Created on: 16/9/2019
 *  version:    1.3.0
 *  Author:     Ali Shawky
 */


/***************************************
 *included files                       *
 **************************************/
#include "SOS_Scheduler.h"

#include "Interrupt.h"
/***************************************
 * global variables                    *
 **************************************/

static uint8 system_tick = 0;



/****************************************************************************************
 * function name: SOS_Init                                                              *
 *                                                                                      *
 * arguments: input: (name: none ,type: none ,description: none)                         *                                                                                      *
 *            output: (name: none ,type:none ,description:void )                         *
 *            input/output: (name: none ,type:none ,description:void )                   *
 *                                                                                      *
 * return: void                                                                         *
 *                                                                                      *
 * description: this function initializes the small OS scheduler and selects timer0     *
 *               to start counting and enabling timer0's overflows interrupt            *
 *                                                                                      *
 ****************************************************************************************/

void SOS_Init()
{
	/*initialize OCR with initial value*/
	Timer0_Set_OCR0(130);
	/*initiate timer0 ctc mode with pre scaler 64*/
	Timer0_init();
	/*set call back function*/
	SetCallBack(Scheduler_CallBack);
	/*enable compare match interrupt*/
	Timer0_Interrupt_Enable();
	/*enable global interrupt*/
	Global_Interrupt_Enable();

}


/****************************************************************************************
 * function name: SOS_Run                                                               *
 *                                                                                      *
 * arguments: input: (name: none ,type: none ,description: none)                        *
 *                                                                                      *                                                                                      *
 *            output:(name: none ,type:none ,description:void )                         *
 *                                                                                      *
 *            input/output: (name: none ,type:none ,description:void )                  *
 *                                                                                      *
 * return: void                                                                         *
 *                                                                                      *
 * description: this function decides which task have the highest priority              *
 *                to be executed, and which task should turn to status waiting          *
 *                                                                                      *
 ****************************************************************************************/

void SOS_Run()
{
	uint8 task_number_var1 = 0;
	uint8 max_task_periority = 0;
	uint8 executed_task = 0;

	while(1)
	{
		/*searching for the ready tasks*/
		for(task_number_var1 =0 ;task_number_var1 < ToTal_SystemTasks; task_number_var1++ )
		{

			if(System_Tasks[task_number_var1].Task_Status_m == Ready)
			{
				/*finding the highest priority of ready task*/
				if(max_task_periority <= System_Tasks[task_number_var1].Task_Priority_m)
				{
					max_task_periority = System_Tasks[task_number_var1].Task_Priority_m;
					/*assign the highest priority task to a variable*/
					executed_task = task_number_var1;
				}

				/*turning the executed task to running state*/
				System_Tasks[executed_task].Task_Status_m = Running;
				/*execute the highest priority ready task*/
				System_Tasks[executed_task].Task_Ptr();
				/*turning the done task to status waiting*/
				System_Tasks[executed_task].Task_Status_m = Waiting;
				/*initialize counter to 0*/
				task_number_var1 = 0;
				/*minus the highest found priority to find the lower priority ready task*/
				max_task_periority--;

			}
		}

	}
}


/***************************************************************************************
 * function name: SOS_CreatTask                                                         *
 *                                                                                      *
 * arguments: input: (name: task_ptr ,type: pointer to function ,                       *
 *                    description:passing a call back function by using this argument), *
 *                                                                                      *
 *                   (name:time ,type: uint8 , description:the time frequency           *
 *                    for the each task),                                               *
 *                                                                                      *
 *                   (name: priority ,type:uint8 ,description:the priority for        *
 *                    each task),                                                       *
 *                                                                                      *
 *                   (name: ID ,type:uint8 ,task id)                                    *
 *                                                                                      *
 *                                                                                      *
 *            output:(name: none ,type:none ,description:void )                         *
 *                                                                                      *
 *            input/output: (name: none ,type:none ,description:void )                  *
 *                                                                                      *
 * return: void                                                                         *
 *                                                                                      *
 * description: this function creates shceduler's tasks                                 *
 *                                                                                      *
 ****************************************************************************************/

void SOS_CreatTask(void(*task_ptr)(void), uint16 time, uint8 priority, uint8 ID )
{
	static uint8 Task_Num = 0;

	/*assign the function address to the pointer to function member in the TCB*/
	System_Tasks[Task_Num].Task_Ptr = task_ptr;
	/*assign the frequent time of the task to the time member in the TCB*/
	System_Tasks[Task_Num].Task_Time_m = time;
	/*assign the frequent time to the periodicity member in the TCB*/
	System_Tasks[Task_Num].Task_Periodicity_m = time;
	/*assign the priority of the function to priority member in the TCB*/
	System_Tasks[Task_Num].Task_Priority_m = priority;
	/*assign the function address to the pointer to function member in the TCB*/
	System_Tasks[Task_Num].Task_ID_m = ID;
	/*assign the function address to the pointer to function member in the TCB*/
	System_Tasks[Task_Num].Task_Status_m = Ready;

	/*increment tne index of the TCB*/
	Task_Num++;
}

/****************************************************************************************
 * function name: SOS_Delete                                                            *
 *                                                                                      *
 * arguments: input: (name: ID ,type: uint8 ,description: task id)                      *
 *                                                                                      *                                                                                      *
 *            output:(name: none ,type:none ,description:void )                         *
 *                                                                                      *
 *            input/output: (name: none ,type:none ,description:void )                  *
 *                                                                                      *
 * return: void                                                                         *
 *                                                                                      *
 * description: this function deletes system tasks and turns them to status Deleted     *
 *                                                                                      *
 ****************************************************************************************/

void SOS_Delete(uint8 ID)
{
	uint8 task_number =0;

	/*searching for the task which it's id equales the deleted id*/
	for(task_number=0; task_number < ToTal_SystemTasks ;task_number++)
	{
		if(System_Tasks[task_number].Task_ID_m == ID)
		{
			/*turn the status of the found id to deleted*/
			System_Tasks[task_number].Task_Status_m = Deleted;
			break;
		}

	}
}


/***************************************************************************************
 * function name: Scheduler_CallBack                                                    *
 *                                                                                      *
 * arguments: input: (name: none ,type: none ,description: none)                        *
 *                                                                                      *                                                                                      *
 *            output:(name: none ,type:none ,description:void )                         *
 *                                                                                      *
 *            input/output: (name: none ,type:none ,description:void )                  *
 *                                                                                      *
 * return: void                                                                         *
 *                                                                                      *
 * description: this function increments the system tick and finds which task is ready  *
 *               to be executed                                                         *
 *                                                                                      *
 ****************************************************************************************/

void Scheduler_CallBack()
{

	uint8 task_number = 0;
	system_tick++;


	/*searching for the tasks with status waiting*/
	for(task_number= 0 ; task_number<ToTal_SystemTasks ; task_number++)
	{

		if((System_Tasks[task_number].Task_Status_m != Deleted) && (System_Tasks[task_number].Task_Status_m == Waiting))
		{
			/*decrement its delay time*/
			System_Tasks[task_number].Task_Time_m--;
			/*if task's delay time == 0, so it meets it's own time*/
			if(System_Tasks[task_number].Task_Time_m == 0 )
			{
				/*turn the waiting task status to ready*/
				System_Tasks[task_number].Task_Status_m = Ready;
				/*re initialize its delay time*/
				System_Tasks[task_number].Task_Time_m = System_Tasks[task_number].Task_Periodicity_m;
			}
			else
			{
				/*if the task doesn't meet it's own time so its not ready yet*/
				System_Tasks[task_number].Task_Status_m = Waiting;
			}
		}

	}


}


void CPU_Sleep(void)/*CPU Sleep function*/
{
	/*set the SE bit in MCUCSR Register to enable sleep mode*/
	Set_Bit(MCUCSR,7);
	/*IDLE mode*/
	Clr_Bit(MCUCSR,4);
	Clr_Bit(MCUCSR,5);
	Clr_Bit(MCUCSR,6);
}

