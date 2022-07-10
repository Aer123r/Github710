//
// Created by WuGaoyuan on 2022/5/28.
//

#ifndef PIN_ROBOT_PID_H
#define PIN_ROBOT_PID_H
#include "stdint.h"
//int PID_Calc1(int NowPoint,int SetPoint);
short GetSpeed(uint8_t);
short PID_Cal(short Speed,short *error);
short PID_Cal2(short Speed,short *error);
short PID_Cal3(short Speed,short *error);
short PID_Cal4(short Speed,short *error);
short Generic_PID_Cal(short no,short real_Speed,short Target_Speed);
#endif //PIN_ROBOT_PID_H
