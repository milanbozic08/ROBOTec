/*
 * GccApplication1.c
 *
 * Created: 13/03/2019 10:45:54
 * Author : milan
 */ 

#include <avr/io.h>
#include "Uartavr.h"
#include "PWMx.h"
#include "HCSR04.h"
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
	
	///HCRS04 INIT
	HCSR04_Timer2_init();
	HCSR04Init();
	////////////////
	
	_delay_ms(10);
	uart_send_string("Start");		//UART TEST

	sei();					// OBAVEZNO (Ukljucuje prekide)
	
	
    while (1) 
    {
	
	}
}

