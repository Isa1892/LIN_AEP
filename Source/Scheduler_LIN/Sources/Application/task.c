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
#include "Mal\kernel.h"
/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/

/*In this part you can add a new function, if you like a new task
 * 
 * **First: You can do add a new task function in the low part
 * **Second: You can add a function in the struct 
 */ 

const s_task task_list[num_tasks] = {
	
/*  Name task	           |Period	              |Offset			*/		
	{task_led1,	        	 250,			        10},
	{task_led2,		         500,			        20},
	{task_led3,		        1000,			        30},
	{task_led4,		        2000,			        40}

};


/*Tasks of the scheduller*/

void task_led1(void){    //Task 1 
	Led_Toggle(LED1);
}

void task_led2(void){    //Task 2
	Led_Toggle(LED2);
}

void task_led3(void){    //Task 3
	Led_Toggle(LED3);
}

void task_led4(void){    //Task 4
	Led_Toggle(LED4);
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */

