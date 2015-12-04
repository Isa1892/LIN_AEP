
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: STM_Timer.c 
 * $Revision: 1.0 
 * $Author:  Oswaldo García Cervantes && María Isamar Saldaña Gálvez
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** In this code, you can see the configuration for timer STM
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
 * $Log: Stm_Timer.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "Mal\STM_Timer.h"

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

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/

//Function for configuration clock STM
void Init_STM(void)
{
	STM.CNT.R = 0;                      // Count init in 0
	STM.CH[TM_1MS].CMP.R = 0xFA00;     // 1msec
	STM.CH[TM_1MS].CCR.B.CEN = 1;     // Activate comparator
	STM.CR.B.FRZ = 1;                // 0: timer runs in debug mode
	STM.CR.B.CPS = 0;               // Prescaler
	STM.CR.B.TEN = 1;              // Activate timer
	INTC.CPR.R = 0;               //Activate interrupts
}


//Function for restart the clock STM
void Restart_STM(T_UBYTE lub_channel)
{
	STM.CNT.R = 0; 							//Init in 0
	STM.CH[lub_channel].CIR.B.CIF = 1;		//Clean flag
}

T_UBYTE Flag_STM(T_UBYTE lub_channel)
{
	return STM.CH[lub_channel].CIR.B.CIF;
}


/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */


