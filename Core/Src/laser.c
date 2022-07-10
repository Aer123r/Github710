//
// Created by WuGaoyuan on 2022/6/28.
//
#include "laser.h"
#include "usart.h"
#include "main.h"

extern uint8_t cmd1[9];
void getDis(uint8_t which)
{
    HAL_UART_Transmit_IT(&huart3,cmd1,9);
}