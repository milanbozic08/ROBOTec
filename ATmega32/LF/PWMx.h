/*
 * PWM.h
 *
 * Created: 13/03/2019 11:38:36
 *  Author: milan
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <stdbool.h>
#define PWMRange 1000			// Vrednost u tajmeru , nije ovo PWM

#define DDR DDRD
#define M1	4
#define M2	5
#define M3	6
#define M4	7

#define M1_1OFF PORTD&=~(1<<4)
#define M1_2OFF PORTD&=~(1<<5)
#define M2_1OFF PORTD&=~(1<<6)
#define M2_2OFF PORTD&=~(1<<7) 

#define M1_1ON PORTD |=(1<<4)
#define M1_2ON PORTD |=(1<<5)
#define M2_1ON PORTD |=(1<<6)
#define M2_2ON PORTD |=(1<<7)

typedef enum
{
	CW,
	CCW,
}   direction;

/// MASTER FUNCTION ////////////


void timer1_init();
void Motor_init();

void MotorL_Setup(direction SMER,int PWM);
void MotorR_Setup(direction SMER,int PWM);

void MotorStart(bool);							// Master Start(True) / Stop(false)

/////////////////////////////////////////////





#endif /* PWM_H_ */