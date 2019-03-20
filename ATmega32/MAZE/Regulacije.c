/*
 * Regulacije.c
 *
 * Created: 16/03/2019 18:51:10
 *  Author: milan
 */ 
#include "Regulacije.h"
#include <math.h>

static float incKi=0,e_old=0,e_old2=0,u=0;

float Ki=0;
float Kp=0.5;
float Kd=0;

float Kpb=0.4;

int PWM=150;		//Ovo nastane nakon brzinske regulacije
int PWMKocenje=0;
//int PWMZadato=300;	//Zadaje se preko blututa

void BrzinskaRegulacija(int greska)
{
	greska=abs(greska);
	

	if(greska==0)
	{PWM=PWMZadato;	return;}
	
	if(greska==1)
	{PWM=PWMZadato/2;	return;}
	
	PWM=PWMZadato/2-(Kpb/1000.0*greska*PWMZadato);
}

int PID_reg(int merenje){
	
	float e=0;              //greska
	float incKp=0;          //inkrementalni deo uz Kp
	float incKd=0;          //inkrementalni deo uz Kd
	
	e=(13-merenje)*100; // AKO JE POZITIVNO TREBA DA SE KOCI LEVI MOTOR

	//---------------
	//Brzinska regulacija
	//BrzinskaRegulacija(e);
	///////////////////////////////
	
	
	incKi += Ki*e;     //inkrementalni deo uz Kp
	if(incKi>150) incKi=150;
	if(incKi<-150) incKi=-150;
	
	incKp = Kp*e;             //inkrementalni deo uz Ki
	
	incKd = Kd*(e-2*e_old+e+e_old2);     //inkrementalni deo uz Kd
	
	e_old2 = e_old;           //greska e(kT-2T)
	e_old = e;                //greska e(kT-T)
	
	u = incKp + incKi + incKd;  //izracunavanje izlazne velicine
	
	if( u > (PWM/2) )
	u = (PWM/2);     //provera opsega
	if( u < (-PWM/4) )
	u = (-PWM/4);
	
	return (int)u;
}

void MotorR_Setupx(int U)
{		
	if(U>PWM)
	{MotorR_Setup(CCW,(U-PWM));	//Vrti u suprotnom ako je greska prevelika
	return;}
	MotorR_Setup(CW,(PWM-U));		// Za normalnu gresku vrti samo sporije
}

void MotorL_Setupx(int U)
{
	if(U>PWM)
	{MotorL_Setup(CCW,(U-PWM));	//Vrti u suprotnom ako je greska prevelika
	return;}
	MotorL_Setup(CW,(PWM-U));		// Za normalnu gresku vrti samo sporije
}

bool KontrolaMotora()
{
	int merenje=0;
	
	_delay_ms(1);
	merenje=HCSR_04(2);
	
	//printf_int(merenje);
	if(merenje>27)
	{
		if(HCSR_04(2)>27)
		TESTLED_ON;
		_delay_ms(50);
		TESTLED_OFF;
		return true;
	}
	
	int U=PID_reg(merenje);	// AKO JE POZITIVNO TREBA DA SE KOCI LEVI MOTOR
	
	if(U>0)		//Usporavaj levi motor
	{
		MotorR_Setupx(0);
		MotorL_Setupx(U);
	}
	else		// Usporavaj desni motor
	{
		U=U*(-1);
		MotorR_Setupx(U);
		MotorL_Setupx(0);
	}
	
	return false;
}