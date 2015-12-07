/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: kernel.h $
 * $Revision: version 1.0 $
 * $Author: Oswaldo García Cervantes && María Isamar Saldaña Gálvez 
 * $Date: 17/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/*This is the kernel of document
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
 * $Log: filename.h  $
  ============================================================================*/
#ifndef KERNEL_H_
#define KERNEL_H_

/* Includes */
/*============================================================================*/
#include "MAL\stdtypedef.h"
#include "Application\task.h"


/* Constants and types */
/*============================================================================*/




/* Exported Variables */
/*============================================================================*/
PUBLIC_DATA T_BOOLEAN rbi_TickFlag;
PUBLIC_DATA const S_TASK cas_TaskList[NUMBER_OF_TASKS];


/* Exported functions prototypes */
/*============================================================================*/

/* Functions prototypes */
/*============================================================================*/
void init_Sch_TimeCntrs(void);
void Sch_function_execution(void);


#endif /* KERNEL_H_  Notice: the file ends with a blank new line to avoid compiler warnings */






