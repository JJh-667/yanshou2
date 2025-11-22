#ifndef __TRACK_H
#define __TRACK_H

#define X1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define X2 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define X3 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)
#define X4 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)

void Track_Init(void);
void Track_task(void);

#endif
