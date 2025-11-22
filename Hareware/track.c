#include "stm32f10x.h"                  // Device header
#include "Track.h"
#include "Motoe.h"

void Track_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Track_task(void)
{
	if(X1==0 && X3==0)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(50);
	}
	if(X1==1 && X3==0)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(0);
	}
	if(X1==0 && X3==1)
	{
		Motor1_SetPWM(0);
		Motor2_SetPWM(50);
	}
	if(X1==1 && X2==0 && X3==1 && X4==1)
	{
		Motor1_SetPWM(-50);
		Motor2_SetPWM(50);
	}
	if(X1==1 && X2==1 && X3==1 && X4==0)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(-50);
	}
	if(X1==0 && X2==0 && X3==0 && X4==0)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(50);
	}
	if(X1==0 && X2==0 && X3==0 && X4==1)
	{
		Motor1_SetPWM(50);
		Motor2_SetPWM(-50);
	}
	if(X1==0 && X2==0 && X3==1 && X4==0)
	{
		Motor1_SetPWM(-50);
		Motor2_SetPWM(50);
	}
}
