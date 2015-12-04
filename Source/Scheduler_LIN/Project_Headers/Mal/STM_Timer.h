/*
 * Timer.h
 *
 *  Created on: Nov 3, 2015
 *      Author: Isa
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Mal\Mal_headers.h"
#include "Hal\Hal_headers.h"


//Macros for channels of timer
#define TM_1MS		0
#define	TM_400MS 	1
#define TM_500MS	2
#define	TM_5S		3

void Init_STM(void);
void Restart_STM(T_UBYTE lub_channel);   //error
T_UBYTE Flag_STM(T_UBYTE lub_channel);   //Error


#endif /* TIMER_H_ */
