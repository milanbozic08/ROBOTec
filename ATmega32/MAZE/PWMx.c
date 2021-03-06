/*
 * PWM.c
 *
 * Created: 13/03/2019 11:38:50
 *  Author: milan
 */ 

#include "PWMx.h"
#include "Uartavr.h"
#include <avr/interrupt.h>

long int tmr=0;

volatile direction SmerL=CW, SmerR=CW;
volatile int M_PWMLevi=10,M_PWMDesni=10;
volatile bool EnableMotors=false;

volatile int M_TimerLevi=0,M_TimerDesni=0;




void timer1_init() // Svakih 1mS na 8MHz
{
	// set up timer with prescaler = 256
	TCCR1B |= (1 << CS11);
	
	// initialize counter
	TCNT1 = 65536-20;
	
	// enable overflow interrupt
	TIMSK |= (1 << TOIE1);

}

void Motor_init()
{
	DDRA |=(1<<7);
	DDRA |=(1<<6);
	DDRA |=(1<<5);
	DDRA |=(1<<4);
	
	M1_1OFF;
	M1_2OFF;
	M2_1OFF;
	M2_2OFF;
}

void M_Levi_OFF()
{
	M1_1ON;
	M1_2ON;
}
void M_Levi_ON()
{
	if(SmerL==CCW)
	{
		M1_1OFF;
		M1_2ON;
	}
	else
	{
		M1_1ON;
		M1_2OFF;
	}

}
void M_Desni_OFF()
{
	M2_2ON;
	M2_1ON;
}
void M_Desni_ON()
{
	if(SmerR==CCW)
	{
		M2_1OFF;
		M2_2ON;
	}
	else
	{
		M2_1ON;
		M2_2OFF;
	}
}

void MotorL_Smer_Set(direction X)
{
	SmerL=X;
}
void MotorR_Smer_Set(direction X)
{
	SmerR=X;
}
void MotorL_PWM_Set(int X)
{
	if(X> (PWMRange-1) ) X=(PWMRange-1);
	if(X<1) X=1;
	
	M_PWMLevi=X;
}
void MotorR_PWM_Set(int X)
{
	if(X> (PWMRange-1) ) X=(PWMRange-1);
	if(X<1) X=1;
	 
	M_PWMDesni=X;
}
void MotorStart(bool X)
{
	EnableMotors=X;
}

void MotorL_Setup(direction SMER,int PWM)
{
	MotorL_Smer_Set(SMER);
	MotorL_PWM_Set(PWM);
}
void MotorR_Setup(direction SMER,int PWM)
{
	MotorR_Smer_Set(SMER);
	MotorR_PWM_Set(PWM);
}


ISR(TIMER1_OVF_vect)			// motori su na 50Hz sa rasponom PWM od 0-1000 na f od 8Mhz
{
	cli();
	
	TCNT1 = 65536-20;
	
	
	/*tmr++;
	if(tmr>50000)		// Svake sekunde
	{
		uart_send_string("TMR");
		tmr=0;
	}*/
	
	
	//////////Brojaci
	M_TimerLevi++;
	M_TimerDesni++;

	/////////MOTOR Levi
	if(M_TimerLevi==M_PWMLevi)
	{
		
		M_Levi_OFF();
	}
	if(M_TimerLevi>PWMRange && EnableMotors)
	{
		M_Levi_ON();
		M_TimerLevi=0;
	}
	//////////Motor Desni
	if(M_TimerDesni==M_PWMDesni)
	{
		M_Desni_OFF();
	}
	if(M_TimerDesni>PWMRange && EnableMotors)
	{
		M_Desni_ON();
		M_TimerDesni=0;
	}

	sei();
}