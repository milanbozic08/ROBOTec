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
float Kp=0.6;
float Kd=0;

float Kpb=0.4;

int PWM=300;		//Ovo nastane nakon brzinske regulacije
int PWMKocenje=100;
int PWMZadato=300;	//Zadaje se preko blututa

void BrzinskaRegulacija(int greska)
{
	greska=abs(greska);
	

	if(greska==0)
	{PWM=PWMZadato;	return;}
	
	if(greska==1)
	{PWM=3*PWMZadato/4;	return;}
	
	PWM=PWMZadato/2-(Kpb/1000.0*greska*PWMZadato);
}

int PID_reg(){
	
	float e=0;              //greska
	float incKp=0;          //inkrementalni deo uz Kp
	float incKd=0;          //inkrementalni deo uz Kd
	
	e=ReadOptoSenzor();    //merenje stvarne vrednosti
	
	//---------------
	//Brzinska regulacija
	//BrzinskaRegulacija(e);
	///////////////////////////////
	PWM=PWMZadato;
	
	
	incKi += Ki*e;     //inkrementalni deo uz Kp
	if(incKi>150) incKi=150;
	if(incKi<-150) incKi=-150;
	
	incKp = Kp*e;             //inkrementalni deo uz Ki
	
	incKd = Kd*(e-2*e_old+e+e_old2);     //inkrementalni deo uz Kd
	
	e_old2 = e_old;           //greska e(kT-2T)
	e_old = e;                //greska e(kT-T)
	
	u = incKp + incKi + incKd;  //izracunavanje izlazne velicine
	
	if( u > (PWM+PWMKocenje) )
	u = (PWM+PWMKocenje);             //provera opsega
	if( u < (-PWM-PWMKocenje) )
	u = (-PWM-PWMKocenje);             //provera opsega
	
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

void KontrolaMotora()
{
	int U=PID_reg();
	
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
}