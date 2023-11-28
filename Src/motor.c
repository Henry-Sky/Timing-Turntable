#include "motor.h"
#include "stm32f1xx_hal.h"

TIM _pwm;
UINT _pwm_channel;

void Motor_Init(TIM pwm, UINT pwm_channel){
    // 初始化赋值
    _pwm = pwm;
    _pwm_channel = pwm_channel;
    // 启动pwm的定时器
    HAL_TIM_PWM_Start(&_pwm, _pwm_channel);
    __HAL_TIM_SetCompare(&_pwm, _pwm_channel, T_Count/2);
}

void Motor_Speed_Set(int speed){
    speed = speed % 100;
    int __speed = (speed * T_Count) / 100;
    __HAL_TIM_SetCompare(&_pwm, _pwm_channel, __speed);
}