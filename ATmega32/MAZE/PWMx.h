/*
 * PWM.h
 *
 * Created: 13/03/2019 11:38:36
 *  Author: milan
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <stdbool.h>
#define PWMRange 255

#define DDR DDRA
#define M1	5
#define M2	4
#define M3	7
#define M4	6

#define M1_1OFF PORTA&=~(1<<5)
#define M1_2OFF PORTA&=~(1<<4)
#define M2_1OFF PORTA&=~(1<<7)
#define M2_2OFF PORTA&=~(1<<6) 

#define M1_1ON PORTA |=(1<<5)
#define M1_2ON PORTA |=(1<<4)
#define M2_1ON PORTA |=(1<<7)
#define M2_2ON PORTA |=(1<<6)

typedef enum
{
	CW,
	CCW,
}   direction;

extern volatile bool EnableMotors;
/// MASTER FUNCTION ////////////


void timer1_init();
void Motor_init();

void MotorL_Setup(direction SMER,int PWM);
void MotorR_Setup(direction SMER,int PWM);

void MotorStart(bool);							// Master Start(True) / Stop(false)

/////////////////////////////////////////////





#endif /* PWM_H_ */