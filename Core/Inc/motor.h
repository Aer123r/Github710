//
// Created by WuGaoyuan on 2022/5/28.
//

#ifndef PIN_ROBOT_MOTOR_H
#define PIN_ROBOT_MOTOR_H
#include "stdint.h"

void motor_start(uint8_t serial);
void motor_rotate_All(uint8_t direction);
void motor_stop(uint8_t serial);
void __Motor_rotate(uint8_t number);
void __Motor_In_rotate(uint8_t number);
void change_Speed(uint8_t no,short speed);
void car_circle(void);
#endif //PIN_ROBOT_MOTOR_H
