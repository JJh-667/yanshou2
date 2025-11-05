#include "stm32f10x.h"                  // Device header
#include "Key.h"

uint8_t Key_Num=0;

#define KEY_PRESSED   1
#define KEY_UNPRESSED 0

uint8_t Key_Flag;

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitSructure;
	GPIO_InitSructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitSructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitSructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitSructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t Temp;
	Temp=Key_Num;
	Key_Num=0;
	return Temp;
}

uint8_t Key_GetState(void)
{
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)==0)
	{
		return 1;
	}
	return 0;
}

uint8_t Key_Check(uint8_t Flag)
{
	if (Key_Flag & Flag)
	{
		if(Flag!=KEY_HOLD)
		{
			Key_Flag &= ~Flag;
		}
		return 1;
	}
	return 0;
}



void Key_Tick(void)
{
	static uint8_t Count;
	static uint8_t CurrState,PrevState;
	Count++;
	if (Count>=20)
	{
		Count=0;
		
		PrevState=CurrState;
		CurrState=Key_GetState();
		
		if (CurrState==0 && PrevState!=0)
		{
			Key_Num=PrevState;
		}
	}
}
