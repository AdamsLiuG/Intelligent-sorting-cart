//超声波
#include <stdio.h>
#include <string.h>
//#include "z_adc.h"
#include "global.h"
#include "gpio.h"
#include "timer.h"
#include "usart.h"
#include "main.h"
#include "delay.h"
#include "sensor.h"
#include "pid.h"
#include "math.h"
static u8 flagSoundStart=0;
extern tPid pidJY60Yawmovement;
extern tPid pidJY60YawRotation;
extern tPid pidDistance;
extern tPid pidJY60Yawmovementback;

float  g_fJY60YawMovePidOut = 0.00f; 
float  g_fJY60YawMovePidOut1 = 0.00f; 
float  g_fJY60YawMovePidOut2 = 0.00f; 
float  g_fJY60YawMovePidbackOut = 0.00f; 
float  g_fJY60YawMovePidbackOut1 = 0.00f; 
float  g_fJY60YawMovePidbackOut2 = 0.00f; 
float  g_fJY60YawRotPidOut = 0.00f; 
float  g_fJY60YawRotPidOut1 = 0.00f; 
float  g_fJY60YawRotPidOut2 = 0.00f; 
float  g_fDistancePidOut = 0.00f; 
float  g_fDistancePidOut1 = 0.00f; 
float  g_fDistancePidOut2 = 0.00f; 
float  yaw;

int speed_flag = 0;
int angle_flag = 1;

u8 ir_data[4],ir_flag;
u8 num =0 ;

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
u16 get_csb_value(void) 
{
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
int get_adc_csb_middle() 
{
	u8 i;
	static float ad_value[5] = {0}, myvalue;// ad_value_bak[5] = {0}, 
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

//处理智能传感器功能
void loop_sensor(void) {
	static u8 AI_mode_bak;
	static u32 systick_ms_bak = 0;
	static u8 init_flag = 0;
	static u8 i = 1;
	static u8 j =0;
	static u8 adc_csb = 0;
	static u16 speed1,speed2,speed3,speed4;
	static u8 stop_flag = 1;
	static u8 finish_flag = 1;
	
	AI_avoidance();	//一直调用的避障模式
	if(init_flag == 0)
	{			
		for(i=1;i<3;i++)
		{
				sprintf((char *)cmd_return, "$DGS:%d!", i);
			  parse_cmd(cmd_return);
			  tb_delay_ms(500);
		}
		init_flag++;
	}
	
	if(mode == 1)//前进模式
	{
		if(millis() - systick_ms_bak > 100) 
		{
			systick_ms_bak = millis();
			if (diff <= 180){
				yaw = diff;
			}
			else if (diff > 180){
				yaw = diff-360;
			}
//			sprintf((char *)uart_receive_buf, "yaw=%f\n",yaw);
//			uart1_send_str(uart_receive_buf);//向ART-PI发送
			g_fJY60YawMovePidOut = PID_realize(&pidJY60Yawmovement,yaw);//
//			sprintf((char *)uart_receive_buf, "g_fJY60YawMovePidOut=%f\n",g_fJY60YawMovePidOut);
//			uart1_send_str(uart_receive_buf);//向ART-PI发送
			g_fJY60YawMovePidOut1 = 350 + g_fJY60YawMovePidOut;//
			g_fJY60YawMovePidOut2 = 350 - g_fJY60YawMovePidOut;
			if(g_fJY60YawMovePidOut1 >400) g_fJY60YawMovePidOut1 =400;//
			if(g_fJY60YawMovePidOut1 <300) g_fJY60YawMovePidOut1 =300;
			if(g_fJY60YawMovePidOut2 >400) g_fJY60YawMovePidOut2 =400;
			if(g_fJY60YawMovePidOut2 <300) g_fJY60YawMovePidOut2 =300;
			car_set(g_fJY60YawMovePidOut2,g_fJY60YawMovePidOut1,g_fJY60YawMovePidOut2,g_fJY60YawMovePidOut1);
		}
	}
  else if(mode == 2)//微调模式
	{
			if(millis() - systick_ms_bak > 100) 
			{
				systick_ms_bak = millis();
				/* 读取偏航角信息 */
				if (diff <= 180){
					yaw = diff;
				}
				else if (diff > 180){
					yaw = diff-360;
				}

				/* 读取距离信息 */
				adc_csb = get_adc_csb_middle();
				if ((yaw < 2) && (yaw > -2)){
					car_set(0, 0, 0, 0); // 角度调整好后将速度设为0
				}
				/* PID调整角度 */
				else{
					g_fJY60YawRotPidOut = PID_realize(&pidJY60YawRotation,yaw);//
					g_fJY60YawRotPidOut1 = g_fJY60YawRotPidOut;//
					g_fJY60YawRotPidOut2 = -g_fJY60YawRotPidOut;
					if(g_fJY60YawRotPidOut1 > 150) g_fJY60YawRotPidOut1 =150;
					if(g_fJY60YawRotPidOut2 > 150) g_fJY60YawRotPidOut2 =150;
					car_set(g_fJY60YawRotPidOut2,g_fJY60YawRotPidOut1,g_fJY60YawRotPidOut2,g_fJY60YawRotPidOut1);
					sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
					uart1_send_str(uart_receive_buf);
					//speed1 = abs(g_fJY60YawRotPidOut2);
				}
				if(adc_csb>5)
				{
					car_set(200,200,200,200);
				}
				else if(adc_csb<3)
				{
					car_set(-200,-200,-200,-200);
				}
				else if(adc_csb==4)
				{
						sprintf((char *)uart_receive_buf, "B&");// 发送水果识别模式命令
						zx_uart_send_str(uart_receive_buf);
						if(stop_flag == 1)
						{
							parse_cmd((u8 *)"$DGS:1!");
							tb_delay_ms(500);
							parse_cmd((u8 *)"$DGS:0!");
							tb_delay_ms(500);
							parse_cmd((u8 *)"$DGS:5!");
							stop_flag = 0;
						}
				}
			}
		}
//				/* 先调整角度 */
//				if (angle_flag == 1){
//					if ((yaw < 2) && (yaw > -2)){
//						car_set(0, 0, 0, 0); // 角度调整好后将速度设为0
//						angle_flag = 0; 
//						/* 调整角度后如果距离不符合要求，则调整距离 */
//						if ((adc_csb > 3) && (adc_csb < 6)){
//							speed_flag = 1; // 输出调整距离的信号	
//							
//						}
//					}
//					/* PID调整角度 */
//					else{
//						g_fJY60YawRotPidOut = PID_realize(&pidJY60YawRotation,yaw);//
//						g_fJY60YawRotPidOut1 = g_fJY60YawRotPidOut;//
//						g_fJY60YawRotPidOut2 = -g_fJY60YawRotPidOut;
//						if(g_fJY60YawRotPidOut1 > 150) g_fJY60YawRotPidOut1 =150;
//						if(g_fJY60YawRotPidOut2 > 150) g_fJY60YawRotPidOut2 =150;
//						car_set(g_fJY60YawRotPidOut2,g_fJY60YawRotPidOut1,g_fJY60YawRotPidOut2,g_fJY60YawRotPidOut1);
//						sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
//						uart1_send_str(uart_receive_buf);
//					}
//				}
//				
//				/* 接下来调整距离 */
//				if (speed_flag == 1){
//					if ((adc_csb > 3) && (adc_csb < 6))
//					{
//						car_set(0, 0, 0, 0); // 距离调整好后将速度设为0
//						speed_flag = 0;
//						/* 调整距离后如果角度不符合要求，则调整角度 */		
//						if ((yaw < 2) && (yaw > -2)){
//							angle_flag = 1;
//						}
//						
//					}
//					else{
//							//sprintf((char *)uart_receive_buf, "yaw=%f\n",yaw);
//							//uart1_send_str(uart_receive_buf);// 向ART-PI发送
//							g_fDistancePidOut = PID_realize(&pidDistance,adc_csb);//
//							//sprintf((char *)uart_receive_buf, "g_fJY60YawRotPidOut=%f\n",g_fJY60YawRotPidOut);
//							//uart1_send_str(uart_receive_buf);// 向ART-PI发送
//							if(g_fJY60YawRotPidOut > 25) g_fJY60YawRotPidOut1 = 250;
//							car_set(-g_fJY60YawRotPidOut,-g_fJY60YawRotPidOut,-g_fJY60YawRotPidOut,-g_fJY60YawRotPidOut);
//					}					
//				}
//				
//				/* 如果距离和角度都符合要求，则进入下一个模式 */
//				if ((yaw < 2) && (yaw > -2) && (adc_csb > 3) && (adc_csb < 6))
//						sprintf((char *)uart_receive_buf, "B&");// 发送水果识别模式命令
//						zx_uart_send_str(uart_receive_buf);
//			}
//	 }			
//		else if(mode == 3)
//		{
//			car_set(-100,100,100,-100);//左移
//		}
//		else if(mode == 4)
//		{
//			car_set(100,-100,-100,100);//右移
//		}
	//识别模式
	else if(mode == 5)//夹取苹果
	{
		if(num != 4)
		{
		sprintf((char *)uart_receive_buf, "C&");
		zx_uart_send_str(uart_receive_buf);
		AI_clamp0();
		sprintf((char *)uart_receive_buf, "B&");
		zx_uart_send_str(uart_receive_buf);
		}
		if(num == 4)
		{
			if(millis() - systick_ms_bak > 100) 
			{
				systick_ms_bak = millis();
				sprintf((char *)uart_receive_buf, "D&");
				zx_uart_send_str(uart_receive_buf);
			}
			if(finish_flag == 1)
			{
			for(i=1;i<3;i++)
			{
				sprintf((char *)cmd_return, "$DGS:%d!", i);
			  parse_cmd(cmd_return);
			  tb_delay_ms(800);
			}
			finish_flag = 0;
			}
		}
	}
	else if(mode == 6)//夹取火龙果
	{
		if(num != 4)
		{
		sprintf((char *)uart_receive_buf, "C&");
		zx_uart_send_str(uart_receive_buf);
		AI_clamp1();
		sprintf((char *)uart_receive_buf, "B&");
		zx_uart_send_str(uart_receive_buf);
		}
		if(num == 4)
		{
			if(millis() - systick_ms_bak > 100) 
			{
				systick_ms_bak = millis();
				sprintf((char *)uart_receive_buf, "D&");
				zx_uart_send_str(uart_receive_buf);
			}
			if(finish_flag == 1)
			{
				for(i=1;i<3;i++)
				{
					sprintf((char *)cmd_return, "$DGS:%d!", i);
					parse_cmd(cmd_return);
					tb_delay_ms(800);
				}
			finish_flag = 0;
			}
		}
	}
	else if(mode == 7)//未识别到
	{
			if(millis() - systick_ms_bak > 100) 
			{
				systick_ms_bak = millis();
				parse_cmd((u8 *)"$DGS:5!");
			}
		if(num == 4)
		{
			if(millis() - systick_ms_bak > 100) 
			{
				systick_ms_bak = millis();
				sprintf((char *)uart_receive_buf, "D&");
				zx_uart_send_str(uart_receive_buf);
			}
			if(finish_flag == 1)
			{
				for(i=1;i<3;i++)
				{
					sprintf((char *)cmd_return, "$DGS:%d!", i);
					parse_cmd(cmd_return);
					tb_delay_ms(800);
				}
			finish_flag = 0;
			}
		}
	}
	else if(mode == 8)//返回
	{
		car_set1(-500, -500, -500, -500); //左后行驶
//		if(millis() - systick_ms_bak > 100) 
//		{
//			systick_ms_bak = millis();
//			if (diff <= 180){
//				yaw = diff;
//			}
//			else if (diff > 180){
//				yaw = diff-360;
//			}
//			sprintf((char *)uart_receive_buf, "yaw=%f\n",yaw);
//			uart1_send_str(uart_receive_buf);//向ART-PI发送
//			g_fJY60YawMovePidbackOut = PID_realize(&pidJY60Yawmovementback,yaw);//
//			sprintf((char *)uart_receive_buf, "g_fJY60YawMovePidbackOut=%f\n",g_fJY60YawMovePidbackOut);
//			uart1_send_str(uart_receive_buf);//向ART-PI发送
//			g_fJY60YawMovePidbackOut1 = -350 - g_fJY60YawMovePidbackOut;//
//			g_fJY60YawMovePidbackOut2 = -350 + g_fJY60YawMovePidbackOut;
//			if(g_fJY60YawMovePidbackOut1 < -400) g_fJY60YawMovePidbackOut1 = -400;//
//			if(g_fJY60YawMovePidbackOut1 > -300) g_fJY60YawMovePidbackOut1 = -300;
//			if(g_fJY60YawMovePidbackOut2 < -400) g_fJY60YawMovePidbackOut2 = -400;
//			if(g_fJY60YawMovePidbackOut2 > -300) g_fJY60YawMovePidbackOut2 = -300;
//			car_set(g_fJY60YawMovePidbackOut2,g_fJY60YawMovePidbackOut1,g_fJY60YawMovePidbackOut2,g_fJY60YawMovePidbackOut1);
//			// car_set(-300, -400, -300, -400); //左后行驶
//		}
	}
	if(AI_mode_bak != mode) {
		//car_set(0, 0, 0, 0);
		AI_mode_bak = mode;
		flagSoundStart=0;
		group_do_ok = 1;
	}
}





//下面的函数可用于小车在行进过程中进行避障
/*************************************************************
函数名称：AI_ziyou_bizhang()
功能介绍：识别物体距离从而避开物体前进
函数参数：无
返回值：  无  
*************************************************************/
void AI_avoidance(void) 
{
	static u8 flag = 0;
	static u8 avoidance_flag = 0;
	static u32 systick_ms_bak = 0;
	int speed = 500, adc_csb;
	if(flag == 0 &&millis() - systick_ms_bak > 100)
			{
			systick_ms_bak = millis();
			adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
			sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
			uart1_send_str(uart_receive_buf);
			if(adc_csb <20)
			{
			receive_flag = 0;
			car_set(0,0,0,0);
			sprintf((char *)uart_receive_buf, "A&");
			zx_uart_send_str(uart_receive_buf);
			flag++;
			receive_flag = 1;
			}
		}
}
//	if(flag==0&&millis() - systick_ms_bak > 100)
//	{	
//		systick_ms_bak = millis();
//		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
//		sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
//		uart1_send_str(uart_receive_buf);
//		if(adc_csb < 20)
//		{	
//			sprintf((char *)uart_receive_buf, "#Obstacle avoidance mode&\n");
//			uart3_send_str(uart_receive_buf);//向ART-PI发送
//			receive_flag = 0;
//			systick_ms_bak = millis();
//			while(millis() - systick_ms_bak < 1500)
//			{
//				car_set(-500,500,500,-500);
//				sprintf((char *)uart_receive_buf, "ZPY");
//				uart1_send_str(uart_receive_buf);
//				tb_delay_ms(1000);
//			}
//			systick_ms_bak = millis();
//			while(millis() - systick_ms_bak < 3000)
//			{
//				if (diff <= 180){
//					yaw = diff;
//				}
//				else if (diff > 180){
//					yaw = diff-360;
//				}
////				sprintf((char *)uart_receive_buf, "yaw=%f\n",yaw);
////				uart1_send_str(uart_receive_buf);//向ART-PI发送
//				g_fJY60YawMovePidOut = PID_realize(&pidJY60Yawmovement,yaw);//
////				sprintf((char *)uart_receive_buf, "g_fJY60YawMovePidOut=%f\n",g_fJY60YawMovePidOut);
////				uart1_send_str(uart_receive_buf);//向ART-PI发送
//				g_fJY60YawMovePidOut1 = 350 + g_fJY60YawMovePidOut;//
//				g_fJY60YawMovePidOut2 = 350 - g_fJY60YawMovePidOut;
//				if(g_fJY60YawMovePidOut1 >400) g_fJY60YawMovePidOut1 =400;//
//				if(g_fJY60YawMovePidOut1 <300) g_fJY60YawMovePidOut1 =300;
//				if(g_fJY60YawMovePidOut2 >400) g_fJY60YawMovePidOut2 =400;
//				if(g_fJY60YawMovePidOut2 <300) g_fJY60YawMovePidOut2 =300;
//				car_set(g_fJY60YawMovePidOut2,g_fJY60YawMovePidOut1,g_fJY60YawMovePidOut2,g_fJY60YawMovePidOut1);
//			}
//			systick_ms_bak = millis();
//			while(millis() - systick_ms_bak < 1500)
//			{
//				car_set(500,-500,-500,500);
//				sprintf((char *)uart_receive_buf, "YPY");
//				uart1_send_str(uart_receive_buf);
//				tb_delay_ms(1000);
//			}
//			avoidance_flag++;	
//			receive_flag = 1;
//		  sprintf((char *)uart_receive_buf, "#Driving mode&\n");
//			uart3_send_str(uart_receive_buf);//向ART-PI发送
//	  }
//  }
//	else if(avoidance_flag ==2&&(millis() - systick_ms_bak > 100))
//	{
//		adc_csb = get_adc_csb_middle();//获取a0的ad值，计算出距离
//		sprintf((char *)uart_receive_buf, "adc_csb = %d\r\n", adc_csb);
//		uart3_send_str(uart_receive_buf);
//		if(adc_csb < 10)
//		{
//		  systick_ms_bak = millis();
//		  sprintf((char *)uart_receive_buf, "#Regulation mode&\n");
//	  	uart3_send_str(uart_receive_buf);//向ART-PI发送
//			while(millis() - systick_ms_bak < 1000)
//			{
//		    car_set1(500,-500,-500,500);
//				sprintf((char *)uart_receive_buf, "YPY1");
//				uart1_send_str(uart_receive_buf);
//				tb_delay_ms(1000);
//			}
//			sprintf((char *)uart_receive_buf, "#Fine-tuning mode&\n");
//			uart3_send_str(uart_receive_buf);//向ART-PI发送
//			avoidance_flag++;
//		}
//	}
//}

//夹取函数
//夹取0类水果
void AI_clamp0(void)//
{
	static u32 systick_ms_bak = 0;
	static u8 i = 1;

	if(millis() - systick_ms_bak > 1000) 
	{
		if(clamp == 1)
		{
		receive_flag = 0;
		car_set(0,0,0,0);
		systick_ms_bak = millis();
		uart3_send_str(uart_receive_buf);
		uart1_send_str(uart_receive_buf);
		beep_on_times(1, 100);
		num++;
		for(i=5;i<11;i++)
		{
				sprintf((char *)cmd_return, "$DGS:%d!", i);
			  parse_cmd(cmd_return);
			  tb_delay_ms(1000);
		}
		
		receive_flag = 1;
	}
		clamp = 0;
	}
}

//夹取1类水果
void AI_clamp1(void) 
{
	static u32 systick_ms_bak = 0;
	static u8 i = 1;

	if(millis() - systick_ms_bak > 1000) 
	{
		if(clamp == 1)
		{
		receive_flag = 0;
		car_set(0,0,0,0);
		systick_ms_bak = millis();
		uart3_send_str(uart_receive_buf);
		uart1_send_str(uart_receive_buf);
		beep_on_times(1, 100);
		num++;
		for(i=11;i<20;i++)
		{
				sprintf((char *)cmd_return, "$DGS:%d!", i);
			  parse_cmd(cmd_return);
			  tb_delay_ms(1000);
		}
		
		receive_flag = 1;
	}
		clamp = 0;
	}
}