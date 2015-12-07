/*
 * Signal_types.h
 *
 *  Created on: Dec 6, 2015
 *      Author: emma
 */

/*============================================================================*/
/*                         AEP SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * Source: Signal_Types.h
 * Revision: 1.0
 * Authors: María Isamar Saldaña Gálvez / Oswaldo García Cervantes
 * Date: Dec 05, 2015
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* Signal Types for Master - Slave LIN Network 
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2015                                  */
/* AUTOMOTIVE GROUP, Automotive Entry Program                                 */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/* REVISION |   DATE     |          COMMENT                  |    AUTHOR      */
/*----------------------------------------------------------------------------*/
/*   00     | 05/12/2015 | Added signal types               | Isamar Saldaña  */
/*============================================================================*/
#ifndef SIGNAL_TYPES_H_
#define SIGNAL_TYPES_H_

/* Includes */
/*============================================================================*/

/*============================================================================*/

/* Constants and types */
/*============================================================================*/
/*============================================================================*/


/* Exported Variables */
/*============================================================================*/

typedef enum
{
	cmd_NONE,
	cmd_LED_on,
	cmd_LED_off,
	cmd_LED_toggling,
	cmd_disable_slv,
	cmd_enable_slv
}T_CMDTYPE;

typedef T_UBYTE T_SCALAR;

typedef struct{
	T_UBYTE e[6];
} T_ARRAY;

typedef enum
{
	L_OFF,
	L_ON,
	TOGGLING
}T_LEDSTAT;


typedef enum
{
	DISABLED,
	ENABLED
}T_SLV_STAT;


/*============================================================================*/

/* Exported functions prototypes */
/*============================================================================*/

/*============================================================================*/

#endif /* SIGNAL_TYPES_H_ */
