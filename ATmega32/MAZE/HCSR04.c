/*
 * HCSR04.c
 *
 * Created: 13/03/2019 16:03:19
 *  Author: milan
 */ 
#include "HCSR04.h"

volatile bool TimerTimeOut=false;

long int num;

void HCSR04Init()
{
	//Senzor 1
	TrigerOFF;
	DDRD |=(1<<5);
	
	PORTD |= (1<<4);	//PULL UP
	DDRD &=~(1<<4);
	
	//Senzor 2
	TrigerOFF2;
	DDRD |=(1<<7);
	
	PORTD |= (1<<6);	//PULL UP
	DDRD &=~(1<<6);
}

void HCSR04_Timer2_init()			//TCNT++ svakih 32uS	//TimeOut 8,16mS
{
	TimerTimeOut=false;
	TCNT2 = 0;
	TCCR2 |= (1 << CS22); // preskaler /256
	TCCR2 |= (1 << CS21);
	TIMSK |= (1 << TOIE2);
}

int HCSR_04(int Senzor)		//return u cm
{	bool St=false;
	
// 	if(EnableMotors)
// 	{
// 		MotorStart(false);
// 		St=true;
// 	}
	
	float b=0;
	
	if(Senzor == 1)
	{
		TrigerON;
		_delay_us(10);
		TrigerOFF;
	
		TimerTimeOut=false;
		TCNT2 = 0;
		while (IsEcho==0 && !TimerTimeOut);
		
		if(TimerTimeOut) return 98;
		
		TCNT2 = 0;
		TimerTimeOut=false;
	
		if(TimerTimeOut) return 99;
	
		while(!TimerTimeOut && IsEcho!=0);
		
		b=TCNT2-100;
		b=b*coef;
		
// 		if(St)
// 		MotorStart(true);
		
		return (int)b;
	}
	if(Senzor == 2)
	{
		TrigerON2;
		_delay_us(10);
		TrigerOFF2;
		
		TimerTimeOut=false;
		TCNT2 = 0;
		while (IsEcho2==0 && !TimerTimeOut);
		
		if(TimerTimeOut) return 98;
		
		TCNT2 = 0;
		TimerTimeOut=false;
		
		while(!TimerTimeOut && IsEcho2!=0);
		
		if(TimerTimeOut) return 99;
		
		b=TCNT2;
	
		b=b*coef;
		
// 		if(St)
// 		MotorStart(true);
		
		return (int)b;
	}
	
	return -1;
}

ISR(TIMER2_OVF_vect)
{
	cli();
	TimerTimeOut=true;
	TCNT2=100;
	sei();
}