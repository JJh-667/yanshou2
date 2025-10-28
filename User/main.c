#include "stm32f10x.h"
#include "Delay.h"
#include "OLED.h"
#include "Key.h"
#include "menu.h"
#include "LED.h"
#include "Encoder.h"
#include "Timer.h"

int main(void)
{
	int menu2;
	OLED_Init();
	Key_Init();
	LED_Init();
	Timer_Init();
	Encoder_Init();
	while (1)
	{
		menu2=menu1();
		if(menu2==1)
		{
			menu12();
		}
		if(menu2==2)
		{
			menu22();
		}
		if(menu2==3)
		{
			menu32();
		}
		if(menu2==4)
		{
			menu42();
		}	
	}
}

void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		LED_Tick();
		Key_Tick();
		Key_Tick1();
		Key_Tick2();
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}
