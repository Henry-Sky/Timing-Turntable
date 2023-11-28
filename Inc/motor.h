#include "main.h"

#define TIM TIM_HandleTypeDef
#define UINT unsigned int

#define T_Count 100 //一个周期的最大计数


void Motor_Init(TIM pwm, UINT pwm_channel);

void Motor_Encoder_Init(TIM encode, UINT ea_channel, UINT eb_channel);

void Motor_Speed_Set(int speed);