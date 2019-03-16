/*
 * UartAVRc.c
 *
 * Created: 23.5.2017 14:11:19
 *  Author: Bozic

 */ 


#include "Uartavr.h"
#include <avr/interrupt.h>
#include <stdio.h>


volatile char Resive[100];
volatile bool ResivedOK=false;
volatile int brojcanik=-1;

void Uart_inic()
{
	PORTD |= (1<<0);
	DDRD &= ~(1<<0);
	//PORTD |= (1<<1);
	DDRD |= (1<<1);
	
	UBRRH =(MYUBRR)>>8;
	UBRRL = MYUBRR;
	
	UCSRB |= (1 << RXEN) | (1 << TXEN);      // Enable receiver and transmitter
	UCSRB |= (1 << RXCIE);                   // Enable the receiver interrupt
	UCSRC |= (1 << URSEL) |(1 << UCSZ1) | (1 << UCSZ0);    // Set frame: 8data, 1 stp
	
	//sei();
	
	
	for(int k=0;k<100;k++)
	{
		Resive[k]='\0';
	}	  
	
}

void printf_int(int Num)
{
	int i;
	uint8_t Str[100];

	for(i=0;i<100;i++)
	Str[i]='\0';

	sprintf((char*)Str,"%d \n",Num);

	printf_string((char *)Str);
}


void printf_string(char *Str)
{
	int x=strlen(Str),n=0;
	for(n=0;n<x;n++)
	{
		while ( !(UCSRA & (1 << UDRE)) );   // Wait until buffer is empty

		UDR = *Str;                     // Send the data to the TX buffer
		Str++;
	}
}

bool uart_full()	// ako je false onda nista nije stiglo ...
{
	return ResivedOK;
}

void uart_clear()
{
	ResivedOK=false;
	
	for(int k=0;k<100;k++)
	{
		Resive[k]='\0';
	}

	brojcanik=-1;
}

ISR (USART_RXC_vect)
{		
		brojcanik++;										
		if(brojcanik>99) brojcanik=99;											//ne daj prepunjavanje bafera
	
		Resive[brojcanik]=UDR;
		
		if(Resive[brojcanik]=='\r' || Resive[brojcanik]=='\n')
		{
			Resive[brojcanik]='\0';

			brojcanik=-1;

			ResivedOK=true;
		}	
}