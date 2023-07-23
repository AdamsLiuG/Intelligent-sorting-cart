#include "pid.h"

//定义一个结构体类型变量
tPid pidJY60Yawmovement;
tPid pidJY60Yawmovementback;
tPid pidJY60YawRotation;
tPid pidDistance;

//给结构体类型变量赋初值
void PID_init()
{
	/* 直线行驶PID参数 */
	pidJY60Yawmovement.actual_val=0.0;
	pidJY60Yawmovement.target_val=0.00;
	pidJY60Yawmovement.err=0.0;
	pidJY60Yawmovement.err_last=0.0;
	pidJY60Yawmovement.err_sum=0.0;
	pidJY60Yawmovement.Kp=12;//12
	pidJY60Yawmovement.Ki=0;
	pidJY60Yawmovement.Kd=6;//8.5
	
	/* 原地旋转PID参数 */
	pidJY60YawRotation.actual_val=0.0;
	pidJY60YawRotation.target_val=0.0;
	pidJY60YawRotation.err=0.0;
	pidJY60YawRotation.err_last=0.0;
	pidJY60YawRotation.err_sum=0.0;
	pidJY60YawRotation.Kp=20;
	pidJY60YawRotation.Ki=0.01;
	pidJY60YawRotation.Kd=5;
	
	/* 超声波距离调整PID参数 */
	pidDistance.actual_val=0.0;
	pidDistance.target_val=4.0;
	pidDistance.err=0.0;
	pidDistance.err_last=0.0;
	pidDistance.err_sum=0.0;
	pidDistance.Kp=50;
	pidDistance.Ki=0;
	pidDistance.Kd=0;
	
	/* 返回过程的直线行驶PID参数 */
	pidJY60Yawmovementback.actual_val=0.0;
	pidJY60Yawmovementback.target_val=0.00;
	pidJY60Yawmovementback.err=0.0;
	pidJY60Yawmovementback.err_last=0.0;
	pidJY60Yawmovementback.err_sum=0.0;
	pidJY60Yawmovementback.Kp=30;//12
	pidJY60Yawmovementback.Ki=0;
	pidJY60Yawmovementback.Kd=10;//8.5	
}
//比例p调节控制函数
float P_realize(tPid * pid,float actual_val)
{
	pid->actual_val = actual_val;//传递真实值
	pid->err = pid->target_val - pid->actual_val;//当前误差=目标值-真实值
	//比例控制调节   输出=Kp*当前误差
	pid->actual_val = pid->Kp*pid->err;
	return pid->actual_val;
}
//比例P 积分I 控制函数
float PI_realize(tPid * pid,float actual_val)
{
	pid->actual_val = actual_val;//传递真实值
	pid->err = pid->target_val - pid->actual_val;//当前误差=目标值-真实值
	pid->err_sum += pid->err;//误差累计值 = 当前误差累计和
	//使用PI控制 输出=Kp*当前误差+Ki*误差累计值
	pid->actual_val = pid->Kp*pid->err + pid->Ki*pid->err_sum;
	
	return pid->actual_val;
}
// PID控制函数
float PID_realize(tPid * pid,float actual_val)
{
	pid->actual_val = actual_val;//传递真实值
	pid->err = pid->target_val - pid->actual_val;////当前误差=目标值-真实值
	pid->err_sum += pid->err;//误差累计值 = 当前误差累计和
	//使用PID控制 输出 = Kp*当前误差  +  Ki*误差累计值 + Kd*(当前误差-上次误差)
	pid->actual_val = pid->Kp*pid->err + pid->Ki*pid->err_sum + pid->Kd*(pid->err - pid->err_last);
	//保存上次误差: 这次误差赋值给上次误差
	pid->err_last = pid->err;
	
	return pid->actual_val;
}
