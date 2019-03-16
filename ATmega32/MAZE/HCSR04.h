/*
 * HCSR04.h
 *
 * Created: 13/03/2019 16:03:38
 *  Author: milan
 */ 


#ifndef HCSR04_H_
#define HCSR04_H_
#include <stdbool.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define coef 8.0/5.8		//8us svaki tcnt2

////////////SENZOR 1 //////////////
#define TrigerON PORTD|=(1<<4)
#define TrigerOFF PORTD&=~(1<<4) 

#define IsEcho (PIND & (1<<PIND5))
//////////////////////////////////////

////////SENZOR 2//////////////////////
#define TrigerON2 PORTD|=(1<<6)
#define TrigerOFF2 PORTD&=~(1<<6)

#define IsEcho2 (PIND & (1<<PIND7))
/////////////////////////////////////


void  HCSR04_Timer2_init();
void  HCSR04Init();

int HCSR_04(int Senzor);			//prosledjuje se 1 za senzor1 ili 2 za senzor2

#endif /* HCSR04_H_ */