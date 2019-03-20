/*
 * Sharp.h
 *
 * Created: 16/03/2019 13:55:58
 *  Author: milan
 */ 


#ifndef SHARP_H_
#define SHARP_H_

#include <stdbool.h>

#define SharpPin 0
#define ColorPin 1

int SharpRead();
bool ColorRead();

#endif /* SHARP_H_ */