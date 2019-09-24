/*
 * SOS.h
 *
 *  Created on: Sep 16, 2019
 *      Author: Hossam-PC
 */

#ifndef SOS_H_
#define SOS_H_

/**********************************************************************************
* 					Included Libraries
**********************************************************************************/
	#include "LIB/Standard_Types.h"
	#include "Timer.h"
	#include "Led.h"
	#include "Sos_PBCfg.h"
	#include "Interrupt.h"

/**********************************************************************************
* 					Used Enumerations
**********************************************************************************/
	typedef enum EnumStates{
		READY,
		RUNNING,
		WAITING,
		DELETED
	}EnumTaskState;

typedef enum EnumEroor{
		OK,
		NOT_OK
}EnumErorrState;
/**********************************************************************************
* 					Used Structures
**********************************************************************************/
	typedef struct
	{
		uint8  u8Reserved_Flag;
		uint16 u16periodicity;
		uint16 u16priority;
		uint16 u16ID_of_Task;
		EnumTaskState Task_State;
		void (*fptr_Task)(void);
	}Task;


/**********************************************************************************
* 					Used Macros
**********************************************************************************/
Task sys_tasks[no_tasks];

/**********************************************************************************
* 					functions' Declarations
**********************************************************************************/
	void Sos_Init(void);

	void Sos_create_Task(void (*ptr)(void),uint16 u16period,uint16 u16prior,uint16 u16ID);

	void Sos_Run(void);

	void Sos_Delete_Task(uint16 ID_of_Task);

	void CallbackfromTimer(void);
	void CPU_Sleep(void);

#endif /* SOS_H_ */
