/*
 * GccApplication1.c
 *
 * Created: 13/03/2019 10:45:54
 * Author : milan
 */ 

#define F_CPU 8000000UL

#include <avr/io.h>
#include "Uartavr.h"
#include "PWMx.h"
#include "HCSR04.h"
#include "AnalogSenzor.h"
#include "UARTHendler.h"
#include <util/delay.h>
#include "Encoder.h"
#include "Regulacije.h"
#include <avr/interrupt.h>



int main(void)
{
	//////INIT Led
	//PORTD |= (1<<2);		//D2
	DDRD |= (1<<2);
	/////////////////
	
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
	
	//ENKODERI
	EncoderInit();

	sei();					// OBAVEZNO (Ukljucuje prekide)

	//printf_string("RADI");

    while (1) 
    {
	/*	TESTLED_OFF;
		_delay_ms(1000);
		TESTLED_ON;
		_delay_ms(1000);
		*/
		if(uart_full())
		{
			RecognizeMSG();
			
			uart_clear();
		}
		
		//printf_int(SharpRead());
		if(SharpRead()==9)
		{
			ULevo();
			TESTLED_ON;
			_delay_ms(10);
			TESTLED_OFF;
			////printf_int(SharpRead());	
		}
		
		
		if(KontrolaMotora())
		UDesno();
		
		//if(ColorRead())
		//MotorStart(false);
		
		
		//KontrolaMotora();  //Vraca true za skretanje u desno
		//UDesno();
		//_delay_ms(10000);
		
		//UDesno();
		//while(1);
		
	///*// ----------TEST SENZOR---------------
	 	
	/*	_delay_ms(300);
		printf_string("HCSR04: ");
		printf_int(HCSR_04(2));*/
		//printf_string(" mm\n");
		
		
		/*printf_string("HCSR04 2: ");
		printf_int(HCSR_04(2));*/
		//printf_string(" mm\n");*/
	
		
		//printf_string("Sharp: ");
		//printf_int(SharpRead());
		//printf_string(" od 1024\n");
		
		
		//printf_string("CNY: ");
		//printf_int(ColorRead());
		//printf_string(" od 1024\n\n");*/
	
	///* ---------TEST MOTOR-------------------
	
		/*MotorStart(true);
		MotorL_Setup(CW,150);
		MotorR_Setup(CW,300);
		_delay_ms(2000);*/
		
		/*MotorStart(false);
		_delay_ms(2000);
		
		MotorStart(true);
		MotorL_Setup(CCW,200);
		MotorR_Setup(CCW,200);
		_delay_ms(2000);*/
	
				
	}
}

