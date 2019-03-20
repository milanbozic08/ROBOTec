/*
 * HCSR04.h
 *
 * Created: 13/03/2019 16:03:38
 *  Author: milan
 */ 

#define F_CPU 8000000UL

#ifndef HCSR04_H_
#define HCSR04_H_
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PWMx.h"

#define coef 32*0.01715 //U cm

////////////SENZOR 1 //////////////
#define TrigerON PORTD|=(1<<5)
#define TrigerOFF PORTD&=~(1<<5) 

#define IsEcho (PIND & (1<<PIND4))
//////////////////////////////////////

////////SENZOR 2//////////////////////
#define TrigerON2 PORTD|=(1<<7)
#define TrigerOFF2 PORTD&=~(1<<7)

#define IsEcho2 (PIND & (1<<PIND6))
/////////////////////////////////////


void  HCSR04_Timer2_init();
void  HCSR04Init();

int HCSR_04(int Senzor);			//prosledjuje se 1 za senzor1 ili 2 za senzor2

#endif /* HCSR04_H_ */