/*
 * Senzori.c
 *
 * Created: 16/03/2019 18:13:29
 *  Author: milan
 */ 

#include "Senzori.h"

#define IsSharp (PINA & (1<<PINA0))

#define IsCentral0	(PINA & (1<<PINA3))
#define IsCentral1	(PINA & (1<<PINA6))
#define IsLeft1		(PINA & (1<<PINA4))
#define IsLeft2		(PINA & (1<<PINA2))
#define IsLeft3		(PINA & (1<<PINA1))
#define IsRight1	(PINA & (1<<PINA5))
#define IsRight2	(PINC & (1<<PINC1))
#define IsRight3	(PINA & (1<<PINA7))

static int backValue=0;

void SenzorInit()
{
	DDRA=0; // svi su ulazni
	PORTC |=(1<<1);
	DDRC &= ~(1<<1);
}
int ReadOptoSenzor()
{
	if(IsCentral0==0)
	{backValue=0; return 0;}
	if(IsCentral1==0)
	{backValue=0; return 1;}
	
	if(IsLeft1==0)
	{backValue=100; return 200;}
	if(IsRight1==0)
	{backValue=-100; return -200;}
	
	if(IsLeft2==0)
	{backValue=300; return 400;}
	if(IsRight2==0)
	{backValue=-300; return -400;}
	
	if(IsLeft3==0)
	{backValue=1000; return 1000;}
	if(IsRight3==0)
	{backValue=-1000; return -1000;}
	
	if(backValue>999)
	return 2000;
	if(backValue<-999)
	return -2000;
	
	return 0;	//Ako bude prekid linije
}
bool ReadSharpSensor()
{
	if(IsSharp)
	{
		return true;
	}
	return false;
}