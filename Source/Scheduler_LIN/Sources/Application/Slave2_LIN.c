/*
 * Slave2_LIN.c
 *
 *  Created on: Dec 6, 2015
 *      Author: emma
 */
/*============================================================================*/
/*                        			 AEP 	                                  */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*
 * $Source: Slave2_LIN.c 
 * $Revision: 1.0 
 * Authors: Oswaldo Garc�a Cervantes && Maria Isamar Salda�a Galv�z 
 * $Date: December 06, 2015 
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/* LINFLEX State machine.    
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
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/* REVISION |   DATE     |          COMMENT                  |    AUTHOR      */
/*----------------------------------------------------------------------------*/
/*   1.0    | 06/12/2015 | 	Added the state machine	 		 |Oswaldo Garc�a  */
/*============================================================================*/

/* Includes */
/*============================================================================*/
#include "Application\Slave2_LIN.h"

/*============================================================================*/

/* Constants and types  */
/*============================================================================*/
const T_SCALAR cub_TeamNumber = 0x08;
const T_ARRAY caub_Names = {'O', 'G', 'C', 'I', 'S', 'G'};


/*============================================================================*/

/* Variables */
/*============================================================================*/
E_LIN_STATES re_SlvState = IDLE;


/*============================================================================*/

/* Private functions prototypes */
/*============================================================================*/
/*============================================================================*/

/* Inline functions */
/*============================================================================*/
/*============================================================================*/

/* Private functions */
/*============================================================================*/
/*============================================================================*/

/**************************************************************
 *  Name                 :  LIN_Slv_StateMachine
 *  Description          :  State machine for the actualization of the parameters of the slave 4
 *  Parameters           :  void
 *  Return               :  void
 *  Precondition         :  An interrupt must occur.
 *  Postcondition        :  Acquires the data of LIN.
 **************************************************************/
void LIN_Slv_StateMachine(E_INTERRUPT_EVNT le_event) 
{
	switch(re_SlvState)
	{
		case IDLE:
				if(le_event == RX_INTERRUPT)
				{
					rub_Rx_ID = GETBYTE_ID;
					re_SlvState = RX_ID;
				}
				else if(le_event == TX_INTERRUPT)
				{
					rub_Rx_ID = GETBYTE_ID;
					re_SlvState = TX_ID;
				}
				else
				{
					re_SlvState = IDLE; 		/*Guard condition*/
				}
			break;
			
		case RX_ID:
				if((rub_Rx_ID == MASTER_CMD_ALL) || (rub_Rx_ID == MASTER_CMD_SLV2))
				{
					re_SlvCmd = GETBYTE_DATA0 & 0x07;
					re_SlvState = IDLE; 
				}
				else
				{
					re_SlvState = IDLE; 		/*Guard condition*/
				}
			break;
			
		case TX_ID:
				if(rub_Rx_ID == SLAVE2_RSP)
				{
					PUTBYTE_DATA0 = (T_UBYTE)(re_LEDStatus);
					PUTBYTE_DATA1 = (T_UBYTE)(re_SlaveStatus);
					LINFLEX_0.LINCR2.B.DTRQ = 1;
					re_SlvState = IDLE; 
				}
				else if(rub_Rx_ID == SLAVE2_ID)
				{
					PUTBYTE_DATA1 = (T_UBYTE)(caub_Names.e[0]);
					PUTBYTE_DATA2 = (T_UBYTE)(caub_Names.e[1]);
					PUTBYTE_DATA3 = (T_UBYTE)(caub_Names.e[2]);
					PUTBYTE_DATA4 = (T_UBYTE)(caub_Names.e[3]);
					PUTBYTE_DATA5 = (T_UBYTE)(caub_Names.e[4]);
					PUTBYTE_DATA6 = (T_UBYTE)(caub_Names.e[5]);
					PUTBYTE_DATA0 = (T_UBYTE)(cub_TeamNumber);
					LINFLEX_0.LINCR2.B.DTRQ = 1;
					re_SlvState = IDLE; 
				}
				else
				{
					re_SlvState = IDLE;		/*Guard condition*/
				}
			break;
			
		default:
			re_SlvState = IDLE;			/*Guard condition*/
			RESTART_LIN_STMCH;
			break;
	}
}


/* Exported functions */
/*============================================================================*/


/*============================================================================*/

/* Notice: the file ends with a blank new line to avoid compiler warnings */


