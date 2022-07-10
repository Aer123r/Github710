//
// Created by WuGaoyuan on 2022/5/28.
//
#include "motor.h"
#include "main.h"
#include "tim.h"

void change_Speed(uint8_t no,short speed)
{
    switch (no) {
        case 1:
            __HAL_TIM_SetCompare(&htim1,TIM_CHANNEL_3,speed);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

    }
}
void motor_rotate_All(uint8_t direction)
{
    if(direction==0)
    {
        __Motor_rotate(1);
        __Motor_rotate(2);
        __Motor_rotate(3);
        __Motor_rotate(4);

    }
    else
    {
        __Motor_In_rotate(1);
        __Motor_In_rotate(2);
        __Motor_In_rotate(3);
        __Motor_In_rotate(4);
    }
}
void motor_start(uint8_t serial)
{
    if(serial & 0x1 != 0)
    {
        __Motor_rotate(1);

    }
    if(serial & 0x2 != 0)
    {
        __Motor_rotate(2);
    }
    if(serial & 0x4 != 0)
    {
        __Motor_rotate(3);
    }
    if(serial & 0x8 != 0)
    {
        __Motor_rotate(4);
    }

}

void motor_stop(uint8_t serial)
{
    HAL_GPIO_WritePin(motor1_A_GPIO_Port,motor1_A_Pin,RESET);
    HAL_GPIO_WritePin(motor1_B_GPIO_Port,motor1_B_Pin,RESET);

    HAL_GPIO_WritePin(motor2_A_GPIO_Port,motor2_A_Pin,RESET);
    HAL_GPIO_WritePin(motor2_B_GPIO_Port,motor2_B_Pin,RESET);

    HAL_GPIO_WritePin(motor3_A_GPIO_Port,motor3_A_Pin,RESET);
    HAL_GPIO_WritePin(motor3_B_GPIO_Port,motor3_B_Pin,RESET);

    HAL_GPIO_WritePin(motor4_A_GPIO_Port,motor4_A_Pin,RESET);
    HAL_GPIO_WritePin(motor4_B_GPIO_Port,motor4_B_Pin,RESET);
}


void __Motor_rotate(uint8_t number)
{
    switch (number) {
        case 1:
            HAL_GPIO_WritePin(motor1_A_GPIO_Port,motor1_A_Pin,RESET);
            HAL_GPIO_WritePin(motor1_B_GPIO_Port,motor1_B_Pin,SET);
            break;
        case 2:
            HAL_GPIO_WritePin(motor2_A_GPIO_Port,motor2_A_Pin,RESET);
            HAL_GPIO_WritePin(motor2_B_GPIO_Port,motor2_B_Pin,SET);
            break;
        case 3:
            HAL_GPIO_WritePin(motor3_A_GPIO_Port,motor3_A_Pin,RESET);
            HAL_GPIO_WritePin(motor3_B_GPIO_Port,motor3_B_Pin,SET);
            break;
        case 4:
            HAL_GPIO_WritePin(motor4_A_GPIO_Port,motor4_A_Pin,RESET);
            HAL_GPIO_WritePin(motor4_B_GPIO_Port,motor4_B_Pin,SET);
            break;
    }
}

void __Motor_In_rotate(uint8_t number)
{
    switch (number) {
        case 1:
            HAL_GPIO_WritePin(motor1_A_GPIO_Port,motor1_A_Pin,SET);
            HAL_GPIO_WritePin(motor1_B_GPIO_Port,motor1_B_Pin,RESET);
            break;
        case 2:
            HAL_GPIO_WritePin(motor2_A_GPIO_Port,motor2_A_Pin,SET);
            HAL_GPIO_WritePin(motor2_B_GPIO_Port,motor2_B_Pin,RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(motor3_A_GPIO_Port,motor3_A_Pin,SET);
            HAL_GPIO_WritePin(motor3_B_GPIO_Port,motor3_B_Pin,RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(motor4_A_GPIO_Port,motor4_A_Pin,SET);
            HAL_GPIO_WritePin(motor4_B_GPIO_Port,motor4_B_Pin,RESET);
            break;
    }
}

void car_circle()
{

    __Motor_rotate(1);
    __Motor_rotate(2);
    __Motor_In_rotate(3);
    __Motor_In_rotate(4);
}
