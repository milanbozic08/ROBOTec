/*
 * HCSR04.c
 *
 * Created: 13/03/2019 16:03:19
 *  Author: milan
 */ 
#include "HCSR04.h"

bool TimerTimeOut=false;

long int num;

void HCSR04Init()
{
	PORTD &= ~(1<<4);		//Senzor 1
	DDRD |=(1<<4);
	PORTD &= ~(1<<5);
	DDRD &=~(1<<5);
	
	PORTD &= ~(1<<6);		//Senzor 2
	DDRD |=(1<<6);
	PORTD &= ~(1<<7);
	DDRD &=~(1<<7);
}

void HCSR04_Timer2_init()			//TCNT++ svakih 8uS
{
	TimerTimeOut=false;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22); // preskaler /128 
	TCCR2 |= (1 << CS20);
	TIMSK |= (1 << TOIE2);
}

int HCSR_04(int Senzor)		//return u mm
{
	if(Senzor == 1)
	{
		TrigerON;
		_delay_us(50);
		TrigerOFF;
	
		TimerTimeOut=false;
		TCNT2 = 0;
		while (IsEcho==0 && !TimerTimeOut);
	
		if(TimerTimeOut) return 1;
	
		TimerTimeOut=false;
		TCNT2 = 0;
	
		while(!TimerTimeOut && IsEcho!=0);
	
		return (int)(TCNT2*coef);
	}
	if(Senzor == 2)
	{
		TrigerON2;
		_delay_us(50);
		TrigerOFF2;
		
		TimerTimeOut=false;
		TCNT2 = 0;
		while (IsEcho2==0 && !TimerTimeOut);
		
		if(TimerTimeOut) return 1;
		
		TimerTimeOut=false;
		TCNT2 = 0;
		
		while(!TimerTimeOut && IsEcho2!=0);
		
		return (int)(TCNT2*coef);
	}
	
	return -1;
}

ISR(TIMER2_OVF_vect)
{
	TimerTimeOut=true;
}