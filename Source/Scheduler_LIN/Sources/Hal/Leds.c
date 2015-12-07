
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Leds.c 
 * $Revision: 1.0 
 * $Author: Oswaldo García Cervantes / María Isamar Saldaña Gálvez 
 * $Date: 13/11/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    In this code you can see when configuration of leds
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
 * $Log: Leds.c  
  ============================================================================*/

/* Includes */
/*============================================================================*/

#include "Hal\Leds.h"
#include "Mal\stdtypedef.h"
#include "Mal\MPC5606B.h"

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


/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */

//Function for configuration and initialization the leds
void Init_Leds(void)
{
	T_UBYTE lub_count;
	
	ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
	ME.RUNPC[0].R = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
	ME.PCTL[68].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  
	
	for(lub_count = LED1; lub_count <= LED4; lub_count++)
	{
		SIU.PCR[lub_count].R = 0x0201;
		SIU.GPDO[lub_count].B.PDO = 1;
	}	
}

//Function for do toogle the led
void Led_Toggle(T_SBYTE lsb_led)
{
	SIU.GPDO[lsb_led].B.PDO ^= 1;
}

/* Exported functions */
/*============================================================================*/

 /* Notice: the file ends with a blank new line to avoid compiler warnings */


