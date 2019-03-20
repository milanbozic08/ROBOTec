/*
 * Encoder.h
 *
 * Created: 18/03/2019 02:09:49
 *  Author: milan
 */ 


#ifndef ENCODER_H_
#define ENCODER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "Uartavr.h"

void EncoderInit();

void UDesno();
void ULevo();




#endif /* ENCODER_H_ */