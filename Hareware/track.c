#include "stm32f10x.h"                  // Device header
#include "Track.h"
#include "Motoe.h"
#include "Encoder.h"
#include "Delay.h"
#include "math.h"
#include "stdlib.h"

float Target1=0, Actual1, Out1, Target2=0, Actual2, Out2;			
float Kp1=1.25, Ki1=0.19, Kd1=0.01, Kp2=1.25, Ki2=0.2, Kd2=0.01;					
float Error01, Error11, Error21, Error02, Error12, Error22;
float Integral1=0,LastOut1=0,Integral2=0,LastOut2=0;
static float LastActual1 = 0, LastActual2 = 0;



void Track_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

      
int8_t PID1(int8_t target)
{
     Target1 = target;
    Actual1 = EncoderA_Get();
    
    Error21 = Error11;
    Error11 = Error01;
    Error01 = Target1 - Actual1;

    if(fabs(Actual1 - LastActual1) > Target1*0.2) {
        Error01 = 0;
    }
    LastActual1 = Actual1;

    Integral1 += Ki1 * Error01;
    if(Integral1 > 50) Integral1 = 50;
    else if(Integral1 < -50) Integral1 = -50;
    if((LastOut1 >= 90 && Error01 > 0) || (LastOut1 <= -90 && Error01 < 0)) {
        Integral1 -= Ki1 * Error01;
    }

    float delta_u = Kp1*(Error01 - Error11) + Integral1 + Kd1*(Error01 - 2*Error11 + Error21);

    #define MAX_STEP 4
    if(delta_u > MAX_STEP) delta_u = MAX_STEP;
    else if(delta_u < -MAX_STEP) delta_u = -MAX_STEP;

    Out1 = LastOut1 + delta_u;
    if(Out1 > 90) Out1 = 90;
    else if(Out1 < -90) Out1 = -90;

    if(Actual1 < Target1*0.8) Out1 += 10;

    LastOut1 = Out1;
    return (int8_t)Out1;

}

int8_t PID2(int8_t target)
{
    Target2 = target;
    Actual2 = EncoderB_Get();
    
    Error22 = Error12;
    Error12 = Error02;
    Error02 = Target2 - Actual2;

    if(fabs(Actual2 - LastActual2) > Target2*0.2) {
        Error02 = 0;
    }
    LastActual2 = Actual2;

    Integral2 += Ki2 * Error02;
    if(Integral2 > 50) Integral2 = 50;
    else if(Integral2 < -50) Integral2 = -50;
    if((LastOut2 >= 90 && Error02 > 0) || (LastOut2 <= -90 && Error02 < 0)) {
        Integral2 -= Ki2 * Error02;
    }

    float delta_u = Kp2*(Error02 - Error12) + Integral2 + Kd2*(Error02 - 2*Error12 + Error22);

    #define MAX_STEP 4
    if(delta_u > MAX_STEP) delta_u = MAX_STEP;
    else if(delta_u < -MAX_STEP) delta_u = -MAX_STEP;

    Out2 = LastOut2 + delta_u;
    if(Out2 > 90) Out2 = 90;
    else if(Out2 < -90) Out2 = -90;

    if(Actual2 < Target2*0.8) Out2 += 10;

    LastOut2 = Out2;
    return (int8_t)Out2;
}

void Track_task(void)
{
	if(X1==1 && X3==1 && X2==0 && X4==0)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(55);
	}
	if(X1==1 && X3==0 && X2==0 && X4==0)
	{
		Motor1_SetPWM(70);
		Motor2_SetPWM(-70);
	}
	if(X1==0 && X3==1 && X2==0 && X4==0)
	{
		Motor1_SetPWM(-70);
		Motor2_SetPWM(70);
	}
	if(X1==0 && X2==0 && X3==0 && X4==1)
	{
		Motor1_SetPWM(-100);
		Motor2_SetPWM(100);
	}
	if(X1==0 && X2==1 && X3==0 && X4==0)
	{
		Motor1_SetPWM(100);
		Motor2_SetPWM(-100);
	}
	if(X1==0 && X2==0 && X3==1 && X4==1)
	{
		Motor1_SetPWM(-100);
		Motor2_SetPWM(100);
	}
	if(X1==1 && X2==1 && X3==0 && X4==0)
	{
		Motor1_SetPWM(100);
		Motor2_SetPWM(-100);
	}
	if(X1==1 && X2==1 && X3==1 && X4==1)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(55);
	}
	
}

