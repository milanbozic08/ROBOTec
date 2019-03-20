/*
 * Senzori.h
 *
 * Created: 16/03/2019 18:13:48
 *  Author: milan
 */ 


#ifndef SENZORI_H_
#define SENZORI_H_

#include <avr/io.h>
#include <stdbool.h>

void SenzorInit();
int ReadOptoSenzor();
bool ReadSharpSensor();




#endif /* SENZORI_H_ */