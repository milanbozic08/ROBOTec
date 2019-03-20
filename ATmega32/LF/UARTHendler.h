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

#define TESTLED_OFF PORTB &= ~(1<<0)
#define TESTLED_ON  PORTB |= (1<<0)

void RecognizeMSG();


#endif /* UARTHENDLER_H_ */