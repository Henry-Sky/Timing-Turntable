#include "motor.h"
#include "stm32f1xx_hal.h"

TIM _pwm;
UINT _pwm_channel;
TIM _encode;
UINT _ea_channel;
UINT _eb_channel;


void Motor_Init(TIM pwm, UINT pwm_channel){
    // 初始化赋值
    _pwm = pwm;
    _pwm_channel = pwm_channel;
    // 启动pwm的定时器
    HAL_TIM_PWM_Start(&_pwm, _pwm_channel);
    __HAL_TIM_SetCompare(&_pwm, _pwm_channel, T_Count/2);
}

void Motor_Encoder_Init(TIM encode, UINT ea_channel, UINT eb_channel){
    // 初始化赋值
    _encode = encode;
    _ea_channel = ea_channel;
    _eb_channel = eb_channel;
    // 启动编码器计数
    HAL_TIM_Encoder_Start(&_encode, _ea_channel);
    HAL_TIM_Encoder_Start(&_encode, _eb_channel);
}

void Motor_Speed_Set(int speed){
    speed = speed % 100;
    int __speed = (speed * T_Count) / 100;
    __HAL_TIM_SetCompare(&_pwm, _pwm_channel, __speed);
}