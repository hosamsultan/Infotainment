/*
 *  SOS_Scheduler.h
 *
 *  Created on: 16/9/2019
 *  version:    1.3.0
 *  Author:     Ali Shawky
 */

#ifndef SOS_SCHEDULER_H_
#define SOS_SCHEDULER_H_

/*******************************************
 * the included files                      *
 ******************************************/
#include "SOS_Scheduler_PBCfg.h"
#include "Timer.h"



/******************************************
 * the configurations                     *
 *****************************************/
#define SYSTEM_TICK        1
#define MAX_SYSTEM_TICKS   5


/******************************************
 * structs and enums and arrays           *
 *****************************************/
typedef enum{
	Ready,
	Running,
	Waiting,
	Deleted
}Task_Status;



typedef struct
{
	void(*Task_Ptr)(void);
	uint16 Task_Time_m;
	uint16 Task_Periodicity_m;
	uint8 Task_Priority_m;
	uint8 Task_ID_m;
	Task_Status Task_Status_m;
}Task_Stack;


Task_Stack System_Tasks[ToTal_SystemTasks];



/******************************************
 *   functions prototypes                 *
 *****************************************/

/***************************************************************************************
* function name: SOS_Init                                                              *
*                                                                                      *
* arguments: input: (name: none ,type: none ,description: none)                        *                                                                                      *
*            output: (name: none ,type:none ,description:void )                        *
*            input/output: (name: none ,type:none ,description:void )                  *
*                                                                                      *
* return: void                                                                         *
*                                                                                      *
* description: this function initializes the small OS scheduler and selects timer0     *
*               to start counting and enabling timer0's overflows interrupt            *
*                                                                                      *
****************************************************************************************/
void SOS_Init(void);


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
void SOS_Run(void);


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
void SOS_CreatTask(void(*task_ptr)(void), uint16 time, uint8 periority, uint8 ID);


/***************************************************************************************
* function name: SOS_Delete                                                            *
*                                                                                      *
* arguments: input: (name: none ,type:none ,description:void )                         *
*            output: (name: none ,type:none ,description:void )                        *
*            input/output: (name: none ,type:none ,description:void )                  *
*                                                                                      *
* return: void                                                                         *
*                                                                                      *
* description: this function deletes system tasks and turns them to status Deleted     *
*                                                                                      *
****************************************************************************************/
void SOS_Delete(uint8 ID);


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
void Scheduler_CallBack(void);


void CPU_Sleep(void);


#endif /* SOS_SCHEDULER_H_ */
