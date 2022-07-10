//
// Created by WuGaoyuan on 2022/6/10.
//
#include "Echo.h"
#include "main.h"
extern TIM_HandleTypeDef htim8;
float get_Distance()
{
    uint32_t times=0;
    HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET);
    HAL_Delay(12);
    HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET);

    while(HAL_GPIO_ReadPin(Echo_GPIO_Port,Echo_Pin)==GPIO_PIN_RESET);
    HAL_TIM_Base_Start(&htim8);
    HAL_TIM_Base_Start_IT(&htim8);
    while(HAL_GPIO_ReadPin(Echo_GPIO_Port,Echo_Pin)==GPIO_PIN_SET);
    HAL_TIM_Base_Stop(&htim8);
    HAL_TIM_Base_Start_IT(&htim8);
    times = __HAL_TIM_GET_COUNTER(&htim8);
    __HAL_TIM_SetCounter(&htim8,0);
    times*0.017;
}