#include "stm32f10x.h"

void uart1_init(u32 bound);
void uart3_init(u32 bound);


extern uint8_t RxSucceeflag;				//	���ճɹ����λ

extern float aX;			//	X���ϵļ��ٶ�
extern float aY;			//	Y���ϵļ��ٶ�
extern float aZ;			//	Z���ϵļ��ٶ�

extern float wX;			//	X���ϵĽ��ٶ�
extern float wY;			//	Y���ϵĽ��ٶ�
extern float wZ;			//	Z���ϵĽ��ٶ�

extern float RollX;	//	��ת��
extern float PitchY;	//	������
extern float YawZ;		//	ƫ����
