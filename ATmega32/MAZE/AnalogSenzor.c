/*
 * Sharp.c
 *
 * Created: 16/03/2019 13:55:40
 *  Author: milan
 */ 
#include "AnalogSenzor.h"

int ADCsingleREAD(uint8_t adctouse) //adctouse koji pin treba da se obradi
{
	int ADCval;

	ADMUX = adctouse;         // use #5 ADC
	ADMUX |= (1 << REFS0);    // use AVcc as the reference
	ADMUX &= ~(1 << ADLAR);   // clear for 10 bit resolution
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);    // 128 prescale brzina konverzije
	ADCSRA |= (1 << ADEN);    // Enable the ADC

	ADCSRA |= (1 << ADSC);    // Start the ADC conversion

	while(ADCSRA & (1 << ADSC));      // Thanks T, this line waits for the ADC to finish


	ADCval = ADCL;
	ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again

	return ADCval;
}

int SharpRead()
{
	return ADCsingleREAD(SharpPin);
}
int ColorRead()
{
	return ADCsingleREAD(ColorPin);
}

