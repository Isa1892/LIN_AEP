/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: task.c 
 * $Revision: version 1.0 
 * $Author: María Isamar Saldaña Gálvez / Oswaldo García Cervantes $
 * $Date: 13/11/15 
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** This file contains the functions necessary to configure the scheduler's 
 * tasks, the usuar only can see this .c, because in this part the client do
 * can modificade for dd new tasks.
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
 * $Log: task.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "Application\task.h"


/* Constants and types  */
/*============================================================================*/

/*
 * --------------------List of task for the scheduler-----------------------------
 * */
const S_TASK cas_TaskList[NUMBER_OF_TASKS] = 
{
	/*	Name					Execution Period(ticks)		Startup delay(ticks)	*/
	{	Task1_50ticks,					50, 						1	},
/*	{	Taskn,							Period, 				  offset}	Add if you need a new task*/
};


/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/*
 * --------Add a new definition if you need a new task--------------------------
 * */

 /**************************************************************
  *  Name                 :  Task1_50ticks
  *  Description          :  Init function of Scheduler module
  *  Parameters           :  void
  *  Return               :  void
  *  Precondition         :  This function must be called after cpu initialization.
  *  Postcondition        :  Function gsc_sch_core_exec can be called.
  **************************************************************/
void Task1_50ticks(void)
{
	Slave_Actions();
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */


