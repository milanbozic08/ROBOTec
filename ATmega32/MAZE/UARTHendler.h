/*
 * UARTHendler.h
 *
 * Created: 16/03/2019 15:20:46
 *  Author: milan
 */ 


#ifndef UARTHENDLER_H_
#define UARTHENDLER_H_

#include "Uartavr.h"
#include "Regulacije.h"
#include "PWMx.h"

#define TESTLED_OFF PORTD &= ~(1<<2)
#define TESTLED_ON  PORTD |= (1<<2)

void RecognizeMSG();


#endif /* UARTHENDLER_H_ */