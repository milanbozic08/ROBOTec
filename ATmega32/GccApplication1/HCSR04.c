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
	PORTD &= ~(1<<4);
	DDRD |=(1<<4);
	PORTD &= ~(1<<5);
	DDRD &=~(1<<5);
}

void StartTimer()			//TCNT++ svakih 8uS
{
	TimerTimeOut=false;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22); // preskaler /64
	TIMSK |= (1 << TOIE2);
}

long int StopTimerAndGetTCNT()
{
	//TCCR2 &= ~(1 << CS20);
	//TIMSK &= ~(1 << TOIE2);
	return TCNT2;
}

int HCSR_04()		//return u mm
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

ISR(TIMER2_OVF_vect)
{
	TimerTimeOut=true;
}