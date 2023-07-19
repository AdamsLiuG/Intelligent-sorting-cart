#include <stdio.h>
#include <string.h>
#include "z_adc.h"
#include "z_global.h"
#include "z_gpio.h"
#include "z_timer.h"
#include "z_usart.h"
#include "z_main.h"
#include "z_delay.h"
#include "z_sensor.h"

static u8 flagSoundStart=0;

u8 ir_data[4],ir_flag;

//初始化超声波
void setup_csb() {
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOA, ENABLE);  
	
	//初始化超声波IO口 Trig PB0  Echo PA2
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;  
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB, &GPIO_InitStructure); 	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;   
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_Init(GPIOA, &GPIO_InitStructure); 	
	
	//初始化超声波定时器
	TIM3_Int_Init(30000, 71);
}

//初始化传感器IO口
void setup_sensor(void) {
	setup_csb();	//初始化超声波
}



//处理智能传感器功能
void loop_sensor(void) {
	static u8 AI_mode_bak;
	
	if(AI_mode == 0) 
	{
		AI_dingju_jiaqu();				//循迹模式
	} 
	else if(AI_mode == 1) 
	{
		AI_bizhang();				 //循迹模式
		//AI_shengkong_jiaqu();			//声控夹取
	} 
	
	if(AI_mode_bak != AI_mode) {
		//car_set(0, 0, 0, 0);
		AI_mode_bak = AI_mode;
		flagSoundStart=0;
		group_do_ok = 1;
	}
}


void csb_Delay_Us(uint16_t time)  //延时函数
{ 
	uint16_t i,j;
	for(i=0;i<time;i++)
  		for(j=0;j<9;j++);
}
//下面是两个最基本的函数
/*************************************************************
函数名称：get_csb_value()
功能介绍：采集超声波数据
函数参数：无
返回值：  距离 
*************************************************************/
u16 get_csb_value(void) {
	u16 csb_t;
	Trig(1);
	csb_Delay_Us(20);
	Trig(0);
	while(Echo() == 0);      //读取引脚的电平，等待接收口高电平输出
	TIM_SetCounter(TIM3,0);//清除计数
	TIM_Cmd(TIM3, ENABLE);  //使能TIMx外设
	while(Echo() == 1);     //如果引脚为高电平
	TIM_Cmd(TIM3, DISABLE);  //使能TIMx外设      
	csb_t = TIM_GetCounter(TIM3);//获取时间,分辨率为1US
	//340m/s = 0.017cm/us
	if(csb_t < 25000) 
	{
//		sprintf((char *)cmd_return, "csb_time=%d\r\n", (int)(csb_t*0.17));
//		uart1_send_str(cmd_return);
		csb_t = csb_t*0.017;//计算距离
		return csb_t;
	}
	return 0;
}
/*************************************************************
函数名称：get_adc_csb_middle()
功能介绍：处理超声波采集到的数据，取采集到的中间值
函数参数：无
返回值：  处理后的超声波数据  
*************************************************************/
int get_adc_csb_middle() {
	u8 i;
	static int ad_value[5] = {0}, myvalue;// ad_value_bak[5] = {0}, 
	for(i=0;i<5;i++)
	{
		ad_value[i] = get_csb_value();
		mdelay(5);
	}
	selection_sort(ad_value, 5);
	myvalue = ad_value[2];
// 	for(i=0;i<5;i++)ad_value[i] = ad_value_bak[i];
	return myvalue;  
}


//下面的函数可用于小车在行进过程中进行避障
/*************************************************************
函数名称：AI_ziyou_bizhang()
功能介绍：识别物体距离从而避开物体前进
函数参数：无
返回值：  无  
*************************************************************/
void AI_bizhang(void) {
	static bool flag = 1;
	static u32 systick_ms_bak = 0;
	int speed = 500, adc_csb;
	if(millis() - systick_ms_bak > 500) {
		systick_ms_bak = millis();
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
		//sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
		//uart1_send_str(uart_receive_buf);
		if((adc_csb < 35) && (flag ==1)) {//距离低于50cm就右转
			car_set(speed, -speed, speed, -speed);
			flag = 0;
		} else {
			 if(flag==0){
			   car_set(0, 0, 0, 0);
				 flag = 1;
			 
			 }	
		}
	}
}
/*************************************************************
函数名称：AI_dingju_jiaqu()
功能介绍：识别物体距离夹取物体
函数参数：无
返回值：  无  
*************************************************************/
void AI_dingju_jiaqu(void) {
	static u32 systick_ms_bak = 0;
	
	int adc_csb;
	if(group_do_ok == 0)return;

	//每20ms计算一次
	if(millis() - systick_ms_bak > 100) {
		systick_ms_bak = millis();
		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
// 		sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
// 		uart1_send_str(uart_receive_buf);
		if(adc_csb == 10) {//距离10cm左右就夹取
			car_set(0,0,0,0);
			beep_on_times(1, 100);
			parse_cmd((u8 *)"$DGT:3-11,1!");
		} 
	}
	
}