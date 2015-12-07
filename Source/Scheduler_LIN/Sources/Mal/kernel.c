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
#include "MAL/Kernel.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/

T_ULONG raul_TimeCounter[NUMBER_OF_TASKS];


/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/

/*Add a new prototipe if you need a new task*/
PUBLIC_FCT void Task1_50ticks(void);

/* Exported functions */
/*============================================================================*/

/**************************************************************
 *  Name                 :  init_Sch_TimeCntrs
 *  Description          :  Init function of Scheduler time counters
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  This function must be called after cpu initialization.
 *  Postcondition        :  Function Sch_function_execution can be called.
 **************************************************************/
void init_Sch_TimeCntrs(void)
{
	T_ULONG lul_Position;
	for(lul_Position = 0; lul_Position < NUMBER_OF_TASKS; lul_Position++)
	{
		raul_TimeCounter[lul_Position] = cas_TaskList[NUMBER_OF_TASKS].Offset;
	}
}

/**************************************************************
 *  Name                 :  Sch_function_execution
 *  Description          :  Function of Scheduler 
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  This function must be called after Scheduler init.
 *  Postcondition        :  The Scheduler it is going to execute.
 **************************************************************/
void Sch_function_execution(void)
{
	T_ULONG lul_ArrayPosition;
	while(1)
		{
			if(rbi_TickFlag == TRUE)
			{
				rbi_TickFlag = FALSE;
				for(lul_ArrayPosition = 0; lul_ArrayPosition < NUMBER_OF_TASKS; lul_ArrayPosition++)
				{
					if(raul_TimeCounter[lul_ArrayPosition] != 0)
					{
						raul_TimeCounter[lul_ArrayPosition]--;
					}
					else
					{
						raul_TimeCounter[lul_ArrayPosition] = cas_TaskList[lul_ArrayPosition].Period;
						cas_TaskList[lul_ArrayPosition].PtrFunc();
					}
				}
			}
		}
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
