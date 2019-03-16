/*
 * PWM.h
 *
 * Created: 13/03/2019 11:38:36
 *  Author: milan
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <stdbool.h>
#define PWMRange 1000

#define DDR DDRA
#define M1_1OFF PORTA&=~(1<<4)
#define M1_2OFF PORTA&=~(1<<5)
#define M2_1OFF PORTA&=~(1<<6)
#define M2_2OFF PORTA&=~(1<<7) 

#define M1_1ON PORTA |=(1<<4)
#define M1_2ON PORTA |=(1<<5)
#define M2_1ON PORTA |=(1<<6)
#define M2_2ON PORTA |=(1<<7)

typedef enum
{
	CW,
	CCW,
}   direction;



void timer1_init();
void Motor_init();

void MotorL_Smer_Set(direction);				// Menjanje smera motorima (CW,CCW)
void MotorR_Smer_Set(direction);

void MotorL_PWM_Set(int);						// Podesavanje PWM motora (1-999) **Bez zastite !!
void MotorR_PWM_Set(int);

void MotorStart(bool);							// Master Start(True) / Stop(false)

#endif /* PWM_H_ */