/*
 * UARTHendler.c
 *
 * Created: 16/03/2019 15:21:19
 *  Author: milan
 */ 
#include "UARTHendler.h"
#include <util/delay.h>

void RecognizeMSG()
{
	if(Resive[0]=='O' && Resive[1]=='N')
	{
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		MotorStart(true);
		return;
	}
	if(Resive[0]=='O' && Resive[1]=='F')
	{
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		MotorStart(false);
		return;
	}
	if(Resive[0]=='P' && Resive[1]=='W')		//PWM
	{
		int X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48)*100;
		X+=(Resive[3]-48)*10;
		X+=(Resive[4]-48);
		
		PWM=X;
		return;
	}
	
	if(Resive[0]=='W' && Resive[1]=='P')		// P parametar
	{
		float X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48);
		X+=(Resive[4]-48)/10.0;
		X+=(Resive[5]-48)/100.0;
		X+=(Resive[6]-48)/1000.0;
		
		Kp=X;
		return;
	}
	
	if(Resive[0]=='W' && Resive[1]=='I')		// I parametar
	{
		float X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48);
		X+=(Resive[4]-48)/10.0;
		X+=(Resive[5]-48)/100.0;
		X+=(Resive[6]-48)/1000.0;
		
		Ki=X;
		return;
	}
	
	if(Resive[0]=='W' && Resive[1]=='D')		// D parametar
	{
		float X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48);
		X+=(Resive[4]-48)/10.0;
		X+=(Resive[5]-48)/100.0;
		X+=(Resive[6]-48)/1000.0;
		
		Kd=X;
		return;
	}
	
	if(Resive[0]=='S' && Resive[1]=='P')		// P za brzinsku regulaciju
	{
		float X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48);
		X+=(Resive[4]-48)/10.0;
		X+=(Resive[5]-48)/100.0;
		X+=(Resive[6]-48)/1000.0;
		
		Kpb=X;
		
		return;
	}
	
	if(Resive[0]=='S' && Resive[1]=='D')		// D za brzinsku regulaciju
	{
		int X=0;
		
		TESTLED_ON;
		_delay_ms(10);
		TESTLED_OFF;
		
		X=(Resive[2]-48)*100;
		X+=(Resive[3]-48)*10;
		X+=(Resive[4]-48);
		//X+=(Resive[6]-48)/1000.0;
		PWMKocenje=X;
		
		return;
	}
}