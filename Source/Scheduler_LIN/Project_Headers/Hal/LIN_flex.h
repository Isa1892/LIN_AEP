/*
 * LIN_flex.h
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
 * Source: LIN_flex.h
 * Revision: 1.0
 * Authors: Oswaldo García Cervantes && María Isamar Saldaña Galvéz
 * Date: December 06, 2015
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* header - LINFLEX Initialization, configuration and ISR
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
/*   1.0    | 06/12/2015 | Added LIN initialization function | Oswaldo García */
/*          |            | header 				             |                */
/*============================================================================*/
#ifndef LIN_FLEX_H_
#define LIN_FLEX_H_


/* Includes */
/*============================================================================*/
#include "MAL\MPC5606B.h"
#include "MAL\stdtypedef.h"
#include "Application\Slave2_LIN.h"
#include "Mal\Signal_types.h"


/*============================================================================*/

/* Constants and types */
/*============================================================================*/



/*============================================================================*/

/* Exported Variables */
/*============================================================================*/
/*============================================================================*/
PUBLIC_DATA T_UBYTE		rub_Rx_ID;			/*Variable for Received ID      */
PUBLIC_DATA T_CMDTYPE	re_SlvCmd;	/*Variable for Received Command */

/* Exported functions prototypes */
/*============================================================================*/
PUBLIC_FCT void init_LINflex_Slv(void);

/*============================================================================*/

#endif /* LINFLEX_H_ */


