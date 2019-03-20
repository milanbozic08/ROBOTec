/*
 * Regulacije.h
 *
 * Created: 16/03/2019 18:50:55
 *  Author: milan
 */ 


#ifndef REGULACIJE_H_
#define REGULACIJE_H_

#include "PWMx.h"
#include "Senzori.h"

extern int PWMZadato;
extern int PWM;
extern int PWMKocenje;

extern float Ki;
extern float Kp;
extern float Kd;

extern float Kpb;

int PID_reg();
void BrzinskaRegulacija(int);
void KontrolaMotora();

#endif /* REGULACIJE_H_ */