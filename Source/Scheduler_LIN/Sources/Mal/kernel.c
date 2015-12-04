/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: kernel.c $
 * $Revision: version 1.0 $
 * $Author:  Oswaldo García Cervantes / María Isamar Saldaña Gálvez 
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** 
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2015                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     | Scheduler          | 1.0                             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: kernel.c  $
  ============================================================================*/

/* Includes */
#include "Mal\kernel.h"

/*============================================================================*/

/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/

T_UBYTE rub_cont = 0;
T_ULONG raul_dyn[num_tasks];
T_UBYTE rub_tickFlag;///8
T_ULONG raul_dyn[num_tasks];

/* Private functions prototypes */
/*============================================================================*/

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/

//Function for run the tasks
void Run_Tasks(void)
{
	for(rub_cont = 0; rub_cont < num_tasks; rub_cont++)
	{
		raul_dyn[rub_cont] = task_list[rub_cont].offset;       //Init the offset
	}
	while(1){
		if(rub_tickFlag)
		{
			rub_tickFlag = 0;
			for(rub_cont = 0; rub_cont < num_tasks; rub_cont++)
			{
				if(raul_dyn[rub_cont] > 0)
				{
					raul_dyn[rub_cont]--;
				}
				else
				{
					raul_dyn[rub_cont] = task_list[rub_cont].period;
					task_list[rub_cont].tasks();
				}
			}
		}
	}
}

//Function for configuration the interruption
void Interrupt_Flag(void)
{ 
	if(STM.CH[0].CIR.B.CIF){
		rub_tickFlag = 1;
		STM.CNT.R = 0; 				//Init in 0 the timer STM
		STM.CH[0].CIR.B.CIF = 1;	//Clear interrupt flag		
	}

}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
