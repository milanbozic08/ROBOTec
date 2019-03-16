/*
 * GccApplication1.c
 *
 * Created: 13/03/2019 10:45:54
 * Author : milan
 */ 

#include <avr/io.h>
#include "Uartavr.h"
#include "PWMx.h"
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	////UART INIT
	uart_clear();
	Uart_inic();
	////////////////
	
	///MOTOR INIT
	timer1_init();
	Motor_init();
	///////////////////

	sei();					// OBAVEZNO (Ukljucuje prekide)
	
	
    while (1) 
    {
	
	}
}

