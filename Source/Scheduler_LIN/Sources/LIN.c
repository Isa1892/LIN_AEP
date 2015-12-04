/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: main.c 
 * $Revision: 1.0 
 * $Author: María Isamar Saldaña Gálvez / Oswaldo García Cervantes   
 * $Date: 04/12/15 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    LIN functions
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
/*                     | Scheduler_LIN      | 1.0                             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: main.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "LIN.h"
#include "Mal\MPC5606B.h"
/*============================================================================*/

/* Constants and types  */
/*============================================================================*/
/*============================================================================*/

/* Variables */
/*============================================================================*/

//T_UBYTE		lub_RXID = 0;			/*Variable for Received ID      */
//t_cmdType	le_RXCMD = cmd_NONE;	/*variable for Received Command */

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

/* Exported functions */
/*============================================================================*/


void init_linflex(void) 
{

	/*----------------------------------------------------------- */
	/*        LIN control register 1 (LINFLEX_0_LINCR1)           */
	/*----------------------------------------------------------- */
	/* MPC5606B Datasheet pag. 478*/
	LINFLEX_0.LINCR1.B.INIT  = 1;     /* Put LINFlex hardware in initialization mode     */    
    
	while(LINFLEX_0.LINSR.B.LINS != 1)
	{
		/*Wait for INIT state*/
	} 
    
    LINFLEX_0.UARTCR.B.UART = 0;	  /* UART working on LIN mode                        */
    
    LINFLEX_0.LINCR1.B.MBL   = 0x03;  /* LIN Master Break Length: 13 bits                */ 
    LINFLEX_0.LINCR1.B.BF    = 1;     /* Bypass Filter: Enabled                          */ 
    LINFLEX_0.LINCR1.B.MME   = 0;     /* Master Mode Enable: Slave                       */    
    LINFLEX_0.LINCR1.B.SBDT  = 0;     /* Slave Mode Break Detection Threshold:  11 bits  */
    LINFLEX_0.LINCR1.B.RBLM  = 0;     /* Receive Buffer: Not Locked on overrun           */
    LINFLEX_0.LINCR1.B.CCD   = 0;     /* Checksum Calculation is done by hardware.       */
    LINFLEX_0.LINCR1.B.CFD   = 0;     /* Checksum field: Enabled                         */ 
    LINFLEX_0.LINCR1.B.LASE  = 1;     /* LIN Slave Automatic Resynchronization: enabled   */
	    
    /*----------------------------------------------------------- */
    /*     LIN interrupt enable register  (LINFLEX_0_LINIER)      */
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 481 */
    LINFLEX_0.LINIER.B.SZIE  = 0;  /*Stuck at Zero Interrupt: Disabled, No interrupt when SZF bit in LINESR or UARTSR is set.                */
    LINFLEX_0.LINIER.B.OCIE  = 0;  /*Output Compare Interrupt: Disabled, No interrupt when OCF bit in LINESR or UARTSR is set.               */	
    LINFLEX_0.LINIER.B.BEIE  = 0;  /*Bit error Interrupt generated when BEF bit in LINESR is set.                                            */
    LINFLEX_0.LINIER.B.CEIE  = 1;  /*Checksum error, Interruption generated when checksum error flag (CEF) in LINESR is set.                 */
    LINFLEX_0.LINIER.B.HEIE  = 1;  /*Header error, Interrupt generated on Break Delimiter error, Synch Field error, Identifier field error.  */
    LINFLEX_0.LINIER.B.FEIE  = 1;  /*Frame Error Interrupt: Enabled, interrupt on Framing error.                                         */
    LINFLEX_0.LINIER.B.BOIE  = 0;  /*Buffer Overrun Error Interrupt: Disabled,No interrupt on Buffer overrun.                                */
    LINFLEX_0.LINIER.B.LSIE  = 0;  /*LIN State Interrupt: Disabled, No interrupt on LIN state change.                                        */
    LINFLEX_0.LINIER.B.WUIE  = 0;  /*Wake up Interrupt: Disabled,No interrupt when WUF bit in LINSR or UARTSR is set.                        */  
    LINFLEX_0.LINIER.B.DBFIE = 0;  /*Data Buffer Full Interrupt: Disabled, No interrupt when buffer data register is full.                   */ 
    LINFLEX_0.LINIER.B.DBEIE = 0;  /*Data Buffer Empty Interrupt: Disabled, Data Buffer Empty Interrupt Enable                               */
    LINFLEX_0.LINIER.B.DRIE  = 1;  /*Interruption generated when data received flag (DRF) in LINSR or UARTSR is set.                         */	
    LINFLEX_0.LINIER.B.DTIE  = 1;  /*Interruption generated when data transmitted flag (DTF) is set in LINSR or UARTSR.                      */
    LINFLEX_0.LINIER.B.HRIE  = 1;  /*Interrupt generated when a valid LIN header has been received, that is, HRF bit in LINSR is set.        */
    
    /*----------------------------------------------------------- */
    /*        LIN control register 2   (LINFLEX_0_LINCR2)         */
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 493   */
    LINFLEX_0.LINCR2.B.IOBE = 0; /*Idle on bit error: Disabled, Bit error does not reset state machine                    */
    LINFLEX_0.LINCR2.B.IOPE = 0; /*Idle on Bit Error: Disabled, Identifier Parity error does not reset LIN state machine. */  
    LINFLEX_0.LINCR2.B.WURQ = 0; /*Wake-up Generation Request: Disabled                                                   */   
    LINFLEX_0.LINCR2.B.DDRQ = 0; /*Data Discard Request: Disabled                                                         */
    LINFLEX_0.LINCR2.B.DTRQ = 0; /*Data Transmission Request: Disabled                                                    */
    LINFLEX_0.LINCR2.B.ABRQ = 0; /*Abort Request: Disabled                                                                */
    LINFLEX_0.LINCR2.B.HTRQ = 0; /*Header Transmission Request: Disabled                                                  */

    /*----------------------------------------------------------- */
    /*        LIN integer baudrate register  (LINFLEX_0_LINIBRR)        */
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 473,474 and 492 */
    LINFLEX_0.LINIBRR.R = 0x00D0;  
    /* Baudrate : 19201.9 Symbols/sec, Integer Baud Rate Factor: 208   */
    /* Tx/Rx baud =(fperiph_set_1_clk /(16 × LFDIV)  with 0.01% Error  */
    
    
    /*----------------------------------------------------------- */
    /*        LIN fractional baudrate register  (LINFLEX_0_LINIBRR)*/
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 473,474 and 491*/
    LINFLEX_0.LINFBRR.R = 0x0005;  /* Fractional Baud Rate Factor: 5 */
    
    
    /*----------------------------------------------------------- */
    /*        Identifier filter mode register  (LINFLEX_0_IFMR)   */
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 499 */
    LINFLEX_0.IFMR.R = 0x0000;  /*Disable filters to be able to set them manually*/

    /*----------------------------------------------------------- */
    /*        Identifier filter enable register  (LINFLEX_0_IFER) */
    /*----------------------------------------------------------- */
    /* MPC5606B Datasheet pag. 497 */
    LINFLEX_0.IFER.R = 0x0003;  /*Disable filters to be able to set them manually                   */
        
    //TODO: Set the IDfor the next 4 filters
    /*----------------------------------------------------------- */
	/*        Valid ID's for Slave2 (LINFLEX_0_IFCR0)			  */
	/*----------------------------------------------------------- */
	/* MPC5606B Datasheet pag. 500           					  */
   
    /* MASTER_CMD_ALL */
    LINFLEX_0.IFCR[0].B.DFL = 0x01; /* Data Field Length (Bytes): 1 		   */
    LINFLEX_0.IFCR[0].B.DIR = 0x00; /* Direction:  Receive          		   */
    LINFLEX_0.IFCR[0].B.CCS = 0x00; /* Checksum:   Enhance          		   */
    LINFLEX_0.IFCR[0].B.ID  = 0x0F; /* Identifier: CF  Without parity bits: 0F */
     

    /* MASTER_CMD_SLV2 */
    LINFLEX_0.IFCR[1].B.DFL = 0x01; /* Data Field Length (Bytes): 1 		   */
	LINFLEX_0.IFCR[1].B.DIR = 0x00; /* Direction:  Receive          		   */
	LINFLEX_0.IFCR[1].B.CCS = 0x00; /* Checksum:   Enhance          		   */
	LINFLEX_0.IFCR[1].B.ID  = 0x11; /* Identifier: 11  Without parity bits: 11 */
	
	/* SLAVE2_RSP */
	LINFLEX_0.IFCR[2].B.DFL = 0x01; /* Data Field Length (Bytes): 2 		   */
	LINFLEX_0.IFCR[2].B.DIR = 0x01; /* Direction:  Transmit          		   */
	LINFLEX_0.IFCR[2].B.CCS = 0x00; /* Checksum:   Enhance          		   */
	LINFLEX_0.IFCR[2].B.ID  = 0x21; /* Identifier: 61  Without parity bits: 21 */
	
    /* SLAVE1_ID                                 */
	LINFLEX_0.IFCR[3].B.DFL = 0x07; /* Data Field Length (Bytes): 2 		   */
	LINFLEX_0.IFCR[3].B.DIR = 0x01; /* Direction:  Transmit          		   */
	LINFLEX_0.IFCR[3].B.CCS = 0x00; /* Checksum:   Enhance          		   */
	LINFLEX_0.IFCR[3].B.ID  = 0x31; /* Identifier: B1  Without parity bits: 31 */
	
    LINFLEX_0.LINCR1.B.INIT = 0; /* LIN operational // exit Initialization mode */
    while(LINFLEX_0.LINSR.B.LINS != 2)
	{
		/*Wait for IDLE state*/
	}
}



