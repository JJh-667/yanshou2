#include "stm32f10x.h"                  // Device header
#include "Key.h"
#include "OLED.h"
#include "Encoder.h"

uint8_t KeyNum;
uint8_t task=0;

void menu(void)
{
	uint8_t flag=1;

	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			OLED_ShowChar(flag,1,' ');
			flag=3-flag;
			OLED_ShowChar(flag,1,'>');
			task=1-task;
		}
  }
}

uint8_t Get_Task(void)
{
	return task;
}
