//
// Created by WuGaoyuan on 2022/5/28.
//
#include "PID.h"
#include "stm32f1xx_hal.h"
#include "tim.h"
static double   Kp=0.89;                               //比例常数 Proportional Const
static double   Ki=0.54;                                 //积分常数 Integral Const
static double   Kd=0.005;                                 //b不采用微分
extern short   error[];
/********************增量式PID控制设计************************************/
//NowPoint当前输出值
//SetPoint设定值
//int PID_Calc1(int NowPoint,int SetPoint)
//{
//    //微分常数 Derivative Const
//    static int      LastError1;                                //Error[-1]
//    static int      PrevError1;                                //Error[-2]
//    int iError,Outpid;                                   //当前误差
//
//    iError=SetPoint-NowPoint;                           //增量计算
//    Outpid=(Proportion * iError)                   //E[k]项
//           -(Integral * LastError1)      //E[k-1]项
//           +(Derivative * PrevError1);   //E[k-2]项
//
//    PrevError1=LastError1;                     //存储误差，用于下次计算
//    LastError1=iError;
//    return(Outpid);                                      //返回增量值
//}
short GetSpeed(uint8_t which_motor)
{
    short SPEED = 0;
    switch (which_motor) {
        case 1: SPEED = (short)( __HAL_TIM_GetCounter(&htim1));
            __HAL_TIM_SET_COUNTER(&htim1,0);
            break;
        case 2: SPEED = (short)( __HAL_TIM_GetCounter(&htim2));
            __HAL_TIM_SET_COUNTER(&htim2,0);
            break;
        case 3: SPEED = (short)( __HAL_TIM_GetCounter(&htim4));
            __HAL_TIM_SET_COUNTER(&htim4,0);
            break;
        case 4: SPEED = (short)( __HAL_TIM_GetCounter(&htim8));
            __HAL_TIM_SET_COUNTER(&htim8,0);
            break;
    }


      return SPEED;
}

short Generic_PID_Cal(short no,short real_Speed,short Target_Speed);
{
    no--;
    short Error = Target_Speed - real_Speed;
    static short Error_last[4] = {0,0,0,0}, Error_prev[4] = {0,0,0,0};
    short pwm_add = 0;
    error[no] = Target_Speed-Speed;
    pwm_add = Kp*(Error -Error_last[no])+Ki*Error+Kd*(Error-2.0f*Error_last[no]+Error_prev[no]);
    Error_prev[no] = Error_last[no];
    Error_last[no] = Error;
    return pwm_add;

}

//short PID_Cal(short Speed,short *error)
//{
//    short Error = TargetSpeed - Speed;
//    static short Error_last = 0, Error_prev = 0;
//    short pwm_add = 0;
//    *error = TargetSpeed-Speed;
//    pwm_add = Kp*(Error -Error_last)+Ki*Error+Kd*(Error-2.0f*Error_last+Error_prev);
//    Error_prev = Error_last;
//    Error_last = Error;
//    return pwm_add;
//}
//short PID_Cal2(short Speed,short *error)
//{
//    short Error = TargetSpeed - Speed;
//    static short Error_last2 = 0, Error_prev2 = 0;
//    short pwm_add = 0;
//    *error = Error;
//    pwm_add = Kp*(Error -Error_last2)+Ki*Error+Kd*(Error-2.0f*Error_last2+Error_prev2);
//    Error_prev2 = Error_last2;
//    Error_last2 = Error;
//    return pwm_add;
//}
//short PID_Cal3(short Speed,short *error)
//{
//    short Error = TargetSpeed - Speed;
//    static short Error_last3 = 0, Error_prev3 = 0;
//    short pwm_add = 0;
//    *error = Error;
//    pwm_add = Kp*(Error -Error_last3)+Ki*Error+Kd*(Error-2.0f*Error_last3+Error_prev3);
//    Error_prev3 = Error_last3;
//    Error_last3 = Error;
//    return pwm_add;
//
//}
//short PID_Cal4(short Speed,short *error)
//{
//    short Error = TargetSpeed - Speed;
//    static short Error_last4 = 0, Error_prev4 = 0;
//    short pwm_add = 0;
//    *error = Error;
//    pwm_add = Kp*(Error -Error_last4)+Ki*Error+Kd*(Error-2.0f*Error_last4+Error_prev4);
//    Error_prev4 = Error_last4;
//    Error_last4 = Error;
//    return pwm_add;
//}