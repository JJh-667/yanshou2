#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "menu.h"

uint8_t m=0;
uint8_t n=0;
uint16_t LED_Count=0;

void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_IniStructure;
	GPIO_IniStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_IniStructure.GPIO_Pin=GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_IniStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_IniStructure);
	GPIO_SetBits(GPIOB,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
}


void LED1_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void LED1_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}	

void LED2_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_13);
}	
void LED2_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_13);
}
void LED3_ON(void)
{	
	GPIO_ResetBits(GPIOB,GPIO_Pin_14);
}
void LED3_OFF(void)
{
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
}
void LED4_ON(void)
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_15);
}
void LED4_OFF(void)
{	
	GPIO_SetBits(GPIOB,GPIO_Pin_15);
}

void LED_Tick(void)
{
	LED_Count ++;
	LED_Count%=8000;
	m=out1();
	n=out2();
	if(m==0 && n==0)
	{
		if(LED_Count<500)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1500)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<2000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<2500)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<3000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<3500)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<4000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==4000)
		{
			LED_Count=0;
		}
	}
	if(m==0 && n==1)
	{
		if(LED_Count<500)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<1000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1500)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<2000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<2500)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<3000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<3500)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<4000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==4000)
		{
			LED_Count=0;
		}
	}
	if(m==1 && n==0)
	{
		if(LED_Count<1000)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<2000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<3000)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<4000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<5000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<6000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<7000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<8000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==8000)
		{
			LED_Count=0;
		}
	}
	if(m==1 && n==1)
	{
		if(LED_Count<1000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<2000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<3000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<4000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<5000)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<6000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<7000)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<8000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==8000)
		{
			LED_Count=0;
		}
	}
	if(m==2 && n==0)
	{
		if(LED_Count<200)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<400)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<600)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<800)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1000)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<1200)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1400)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<1600)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==1600)
		{
			LED_Count=0;
		}
	}
	if(m==2 && n==1)
	{
		if(LED_Count<200)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_ON();
		}
		else if(LED_Count<400)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<600)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_ON();
			LED4_OFF();
		}
		else if(LED_Count<800)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1000)
		{
			LED1_OFF();
			LED2_ON();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1200)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1400)
		{
			LED1_ON();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count<1600)
		{
			LED1_OFF();
			LED2_OFF();
			LED3_OFF();
			LED4_OFF();
		}
		else if(LED_Count==1600)
		{
			LED_Count=0;
		}
	}
}
