/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: task.h $
 * $Revision: version 1.0 $
 * $Author: María Isamar Saldaña Gálvez / Oswaldo García Cervantes 
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Headers of task.c, includes the enum necessary to configure the number 
 * of tasks
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
 * $Log: task.h  $
  ============================================================================*/
#ifndef TASK_H_
#define TASK_H_

/* Includes */
/*============================================================================*/
#include "MAL\stdtypedef.h"
#include "Application\Slave2_actions.h"

/* Constants and types */
/*============================================================================*/
typedef void(*T_PFUNC)(void);

typedef struct{
	T_PFUNC PtrFunc;
	T_ULONG Period;
	T_UBYTE Offset;
}S_TASK;

typedef enum {
	TASK1,
	/*number of task*/
	NUMBER_OF_TASKS
}E_NUMTASK;

/* Exported Variables */
/*============================================================================*/



/* Exported functions prototypes */
/*============================================================================*/
PUBLIC_FCT void LED_StateMachine(void);

/* Functions prototypes */
/*============================================================================*/
void Task1_50ticks(void);

#endif /* TASK_H_ */  /* Notice: the file ends with a blank new line to avoid compiler warnings */


