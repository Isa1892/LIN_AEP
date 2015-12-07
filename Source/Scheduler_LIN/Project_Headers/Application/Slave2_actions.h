/*
 * Slave2_actions.h
 *
 *  Created on: Dec 6, 2015
 *      Author: emma
 */

/*============================================================================*/
/*                                  AEP		                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: Slave_Actions.h $
 * $Revision: version 1.0$
 * $Author: Oswaldo García Cervantes && Maria Isamar Saldaña Galvéz
 * $Date: 06/12/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
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
/*                     |LIN network Slave 4 |            1.0                  */
/*					   |					|  Project_Headers/Application    */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: filename.h  $
  ============================================================================*/
#ifndef SLAVE2_ACTIONS_H_
#define SLAVE2_ACTIONS_H_

/* Includes */
/*============================================================================*/
#include "MAL\stdtypedef.h"
#include "HAL\General_config.h"
#include "HAL\LIN_flex.h"
#include "Mal\Signal_types.h"

/* Constants and types */
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/
PUBLIC_DATA T_SLV_STAT re_SlaveStatus;
PUBLIC_DATA T_LEDSTAT re_LEDStatus;

/* Exported functions prototypes */
/*============================================================================*/
 PUBLIC_FCT void Slave_Actions (void);
 

#endif /* SLAVE2_ACTIONS_H_ */
