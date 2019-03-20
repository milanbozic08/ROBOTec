/*
 * GccApplication1.c
 *
 * Created: 13/03/2019 10:45:54
 * Author : milan
 */ 

#include <avr/io.h>
#include "Uartavr.h"
#include "PWMx.h"
#include "Senzori.h"
#include "Regulacije.h"
#include "UARTHendler.h"
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
	
	///SENZORI INIT
	SenzorInit();
	//////////////////
	
	/// LED TEST INIT
	DDRB |= (1<<0);
	//////////////////

	sei();					// OBAVEZNO (Ukljucuje prekide)
	
    while (1) 
    {
		if(uart_full())
		{
			RecognizeMSG();
			uart_clear();
		}
		
 		KontrolaMotora();
 		_delay_us(10);
		 
		 
		
		/*MotorL_Setup(CW,200);
		MotorR_Setup(CW,200);
		_delay_ms(2000);
		
		MotorL_Setup(CW,1);
		MotorR_Setup(CW,1);
		_delay_ms(2000);
		
		MotorL_Setup(CCW,200);
		MotorR_Setup(CCW,200);
		_delay_ms(2000);
		
		MotorL_Setup(CCW,1);
		MotorR_Setup(CCW,1);
		_delay_ms(2000);*/
		 
		/*
		printf_int(ReadOptoSenzor());
		_delay_ms(30);*/
		
	}
}

