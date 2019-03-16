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
#include "AnalogSenzor.h"
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

	sei();					// OBAVEZNO (Ukljucuje prekide)

    while (1) 
    {
		
	/* ----------TEST SENZOR---------------
	 	
		_delay_ms(300);
		printf_string("HCSR04 1: ");
		printf_int(HCSR_04(1));
		printf_string(" mm\n");
		
		
		printf_string("HCSR04 2: ");
		printf_int(HCSR_04(2));
		printf_string(" mm\n");
	
		
		printf_string("Sharp: ");
		printf_int(SharpRead());
		printf_string(" od 1024\n");
		
		
		printf_string("CNY: ");
		printf_int(ColorRead());
		printf_string(" od 1024\n\n");*/
	
	/* ---------TEST MOTOR-------------------
	
		MotorStart(true);
		MotorL_Setup(CW,200);
		MotorR_Setup(CW,200);
		_delay_ms(2000);
		
		MotorStart(false);
		_delay_ms(2000);
		
		MotorStart(true);
		MotorL_Setup(CCW,200);
		MotorR_Setup(CCW,200);
		_delay_ms(2000);
	*/
				
	}
}

