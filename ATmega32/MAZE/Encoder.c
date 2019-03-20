/*
 * Encoder.c
 *
 * Created: 18/03/2019 02:09:36
 *  Author: milan
 */ 
#include "Encoder.h"
#include "PWMx.h"
#include "Regulacije.h"

volatile int Lcounter=0;
volatile int Rcounter=0;
volatile int BrojKorakaL=0;
volatile int BrojKorakaR=0; //Ovaj Broj zadas da uradi toliko koraka (75 po krugu)
volatile bool DozvoliZaustavljanjeDesno=false;
volatile bool DozvoliZaustavljanjeLevo=false;

void EncoderInit()
{
	DDRD &= ~(1<<3);		//(Using for interupt INT1)
	PORTD |= (1<<3);	
	DDRB &= ~(1<<2);		//  (Using for interupt INT2)
	PORTB |= (1<<2);	
	
	GICR |= (1<<INT1);					// Enable INT0
	GICR |= (1<<INT2);					// Enable INT0
	MCUCR = 1<<ISC11 | 1<<ISC10 | 1<<ISC2;	// Trigger INT0 on rising edge
	//MCUCRS |= (1<<ISC02); 	// Trigger INT0 on rising edge
}


void VoziEnkoderima(direction L,direction R,int PWML,int PWMR,int koraciDesno,int koraciLevo)
{
	DozvoliZaustavljanjeLevo=true;
	DozvoliZaustavljanjeDesno=true;
	Rcounter=0;
	Lcounter=0;
	BrojKorakaL=koraciLevo;
	BrojKorakaR=koraciDesno;
	MotorStart(true);
	MotorL_Setup(L,PWML);
	MotorR_Setup(R,PWMR);
	
	bool ispadni1=false,ispadni2=false;
	
	while(!ispadni1 || !ispadni2)
	{
		if(Lcounter > koraciLevo)
		{
			MotorL_Setup(L,1);
			ispadni1 = true;
		}
		if(Rcounter > koraciDesno)
		{
			MotorR_Setup(R,1);
			ispadni2 = true;
		}
	}
	
}

void ULevo()
{
	if(EnableMotors)
	{
		VoziEnkoderima(CCW,CW,100,100,23,23);
	}
	
}

void UDesno()
{
	if(EnableMotors)
	{ 
	VoziEnkoderima(CW,CW,150,150,18,60);
	}
	
}


ISR(INT1_vect)
{
	Rcounter++;
	if(Rcounter>500) Rcounter=500;
}

ISR(INT2_vect)     
{
	Lcounter++;
	if(Lcounter>500) Lcounter=500;
}