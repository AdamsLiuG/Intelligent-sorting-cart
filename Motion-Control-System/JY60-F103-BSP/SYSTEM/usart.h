#include "stm32f10x.h"

void uart1_init(u32 bound);
void uart3_init(u32 bound);


extern uint8_t RxSucceeflag;				//	接收成功标记位

extern float aX;			//	X轴上的加速度
extern float aY;			//	Y轴上的加速度
extern float aZ;			//	Z轴上的加速度

extern float wX;			//	X轴上的角速度
extern float wY;			//	Y轴上的角速度
extern float wZ;			//	Z轴上的角速度

extern float RollX;	//	滚转角
extern float PitchY;	//	俯仰角
extern float YawZ;		//	偏航角
