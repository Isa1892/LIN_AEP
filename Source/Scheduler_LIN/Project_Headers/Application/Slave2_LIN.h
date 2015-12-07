/*
 * Slave2_LIN.h
 *
 *  Created on: Dec 6, 2015
 *      Author: emma
 */

/*============================================================================*/
/*                         			AEP 	                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * Source: Slave2_LIN.h
 * Revision: 1.0
 * Authors: Oswaldo García Cervantes && Maria Isamar Saldaña Galvéz
 * Date: December 06, 2015
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* LIN state machine
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
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
/*   1.0    | 06/12/2015 | Added LIN State machine function  | Oswaldo García */
/*============================================================================*/
#ifndef SLAVE2_LIN_H_
#define SLAVE2_LIN_H_


/* Includes */
/*============================================================================*/
#include "MAL\MPC5606B.h"
#include "MAL\stdtypedef.h"
#include "HAL\LIN_flex.h"
#include "Application\Slave2_actions.h"

/*============================================================================*/

/* Constants and types */
/*============================================================================*/

typedef enum
{
	TX_INTERRUPT,
	RX_INTERRUPT
}E_INTERRUPT_EVNT;

typedef enum
{
	IDLE,
	TX_ID,
	RX_ID
}E_LIN_STATES;


#define MASTER_CMD_ALL 		0x0F   		/* ID: CF */ 
#define MASTER_CMD_SLV2 	0x11  		/* ID: 11 */
#define SLAVE2_RSP 			0x21       	/* ID: 61 */
#define SLAVE2_ID 			0x31        /* ID: B1 */

/*Get data bytes of the buffer*/
#define GETBYTE_ID			((T_UBYTE)(LINFLEX_0.BIDR.B.ID))
#define GETBYTE_DATA0		((T_UBYTE)(LINFLEX_0.BDRL.B.DATA0))

/*Put data bytes on the buffer*/
#define PUTBYTE_DATA0		(LINFLEX_0.BDRL.B.DATA0)
#define PUTBYTE_DATA1		(LINFLEX_0.BDRL.B.DATA1)
#define PUTBYTE_DATA2		(LINFLEX_0.BDRL.B.DATA2)
#define PUTBYTE_DATA3		(LINFLEX_0.BDRL.B.DATA3)
#define PUTBYTE_DATA4		(LINFLEX_0.BDRM.B.DATA4)
#define PUTBYTE_DATA5		(LINFLEX_0.BDRM.B.DATA5)
#define PUTBYTE_DATA6		(LINFLEX_0.BDRM.B.DATA6)
#define RESTART_LIN_STMCH	(LINFLEX_0.LINCR2.B.DDRQ = 1)
/*============================================================================*/

/* Exported Variables */
/*============================================================================*/
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/
PUBLIC_FCT void LIN_Slv_StateMachine(E_INTERRUPT_EVNT le_event);
/*============================================================================*/

#endif /* Slave2_LIN_H_ */

