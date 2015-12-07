/*
 * Leds.h
 *
 *  Created on: Nov 17, 2015
 *      Author: emma
 */

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
/*In this part of code, you can see the heders and prototypes of functions 
 * that use the folder Leds.c
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
 * $Log: Leds.h  
  ============================================================================*/
#ifndef LEDS_H_
#define LEDS_H_

/* Includes */
/*============================================================================*/
#include "Mal\Mal_headers.h"
#include "Application\task.h"
#include "Mal\stdtypedef.h"

/* Constants and types */
/*============================================================================*/
#define LED1 68
#define LED2 69
#define LED3 70
#define LED4 71

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */

void Init_Leds (void);
void Led_Toggle(T_SBYTE lsb_led);

/*============================================================================*/

#endif /* LEDS_H_ */    /* Notice: the file ends with a blank new line to avoid compiler warnings */
