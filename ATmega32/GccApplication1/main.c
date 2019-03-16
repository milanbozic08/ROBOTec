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
	//_delay_ms(100);
	uart_clear();
	Uart_inic();
	timer1_init();
	StartTimer();
	HCSR04Init();
	Motor_init();
	MotorStart(true);
	MotorL_PWM_Set(100);
	MotorR_PWM_Set(100);
	
	_delay_ms(10);
	uart_send_string("Start");
    /* Replace with your application code */
	sei();
    while (1) 
    {
			
	//printf_int(HCSR_04());

		
    }
}

