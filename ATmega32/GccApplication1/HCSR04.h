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

#define TrigerON PORTD|=(1<<4)
#define TrigerOFF PORTD&=~(1<<4) 

#define IsEcho (PIND & (1<<PIND5))

extern bool TimerTimeOut;

void timer2_init();
int HCSR_04();

#endif /* HCSR04_H_ */