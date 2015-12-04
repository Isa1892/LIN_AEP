/*
 * Init_all_system.c
 *
 *  Created on: Nov 17, 2015
 *      Author: emma
 */

#include "Mal\Init_all_system.h"
//#include "Mal\STM_Timer.h"

void Init_system(void)
{
	Init_STM();
	Init_Leds();
	//INTC_InstallINTCInterruptHandler(ISR_RX_LINFLEX,79,1);
	//INTC_InstallINTCInterruptHandler(ISR_RX_LINFLEX,80,2);
}

void Run_system(void)
{
	Run_Tasks();
}
