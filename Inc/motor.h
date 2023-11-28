#include "main.h"

#define TIM TIM_HandleTypeDef
#define UINT unsigned int
#define T_Count 200 //一个周期的最大计数

/**
参数:
- pwm : 控制pwm输出的定时器
- pwm_channel : 控制pwm输出的通道

功能:
- 启动定时器
- 占空比初始化为一半
*/
void Motor_Init(TIM pwm, UINT pwm_channel);

/**
参数:
- speed : 电机速度(0~100)

功能:
- 设置电机速度
*/
void Motor_Speed_Set(int speed);