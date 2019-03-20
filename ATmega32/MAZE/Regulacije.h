/*
 * Regulacije.h
 *
 * Created: 16/03/2019 18:50:55
 *  Author: milan
 */ 


#ifndef REGULACIJE_H_
#define REGULACIJE_H_

#include "PWMx.h"
#include <stdbool.h>
#include "HCSR04.h"
#include "UARTHendler.h"

#define merenjeZaSkretanje 25  //kad bude merenje vece od 25cm on ce skrenuti u desno

extern int PWMZadato;
extern int PWM;
extern int PWMKocenje;

extern float Ki;
extern float Kp;
extern float Kd;

extern float Kpb;

int PID_reg();
void BrzinskaRegulacija(int);
bool KontrolaMotora();

#endif /* REGULACIJE_H_ */