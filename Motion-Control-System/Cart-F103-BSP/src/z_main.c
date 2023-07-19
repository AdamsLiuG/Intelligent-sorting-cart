/***************************************************************
	*	@功能	：	ZL-KPZ32控制板
	
	实现的功能：
	1、手柄按钮控制0-5号舵机，摇杆控制6-7号电机；
	2、zide图形化控制舵机
	3、可脱机存储控制
	
	传感器引脚:
		循迹（S1-PA0 PA1） 
		超声波(S3-PB0 PA2) 
		声音(S4-PB1) 
		颜色识别(S6-PA7 PA5)
	舵机引脚：
		DJ0-PB3
		DJ1-PB8
		DJ2-PB9
		DJ3-PB6
		DJ4-PB7
		DJ5-PB4
	蜂鸣器引脚：
		BEEP-PB5
		LED引脚：（不需要）
		NLED-PB13
		PS2手柄引脚：（不需要）	
	  PS1-DAT-PA15
	  PS2-CMD-PA14
	  PS6-ATT-PA13
	  PS7-CLK-PA12
	按键引脚：
	  KEY1-PA8 KEY2-PA11
	
	统一总线口： TX3 RX3
	
	主频：72M
	单片机型号：STM32F103C8T6
	
***************************************************************/

#include "z_rcc.h"			//配置时钟文件
#include "z_gpio.h"			//配置IO口文件
#include "z_global.h"		//存放全局变量
#include "z_delay.h"		//存放延时函数
#include "z_type.h"			//存放类型定义
#include "z_usart.h"		//存放串口功能文件
#include "z_timer.h"		//存放定时器功能文件
#include "z_w25q64.h"		//存储芯片的操作
#include "z_sensor.h"		//传感器初始化
#include "z_adc.h"			//ADC初始化
#include <stdio.h>			//标准库文件
#include <string.h>			//标准库文件
#include <math.h>			//标准库文件

/*
	全局变量定义
*/
int i;								    //常用的一个临时变量
int do_start_index;				//动作组执行 起始序号
int do_time;						  //动作组执行 执行次数
int group_num_start;			//动作组执行 起始序号
int group_num_end;				//动作组执行 终止序号
int group_num_times;			//动作组执行 起始变量
//u32 dj_record_time = 1000;//学习时间默认1000

u8 needSaveFlag = 0;		    //偏差保存标志
u32 bias_systick_ms_bak = 0;//偏差保存标志时间
u32 action_time = 0;


/*-------------------------------------------------------------------------------------------------------
*  程序从这里执行				
*  这个启动代码 完成时钟配置 使用外部晶振作为STM32的运行时钟 并倍频到72M
-------------------------------------------------------------------------------------------------------*/

int main(void) {	
	setup_rcc();		//初始化时钟
	setup_global();		//初始化全局变量
	setup_gpio();		//初始化IO口
	setup_nled();		//初始化工作指示灯
	setup_beep();		//初始化定时器
	setup_djio();		//初始化舵机IO口
	setup_w25q64();		//初始化存储器W25Q64，用于储存动作组
	setup_systick();	//初始化滴答时钟，1S增加一次millis()的值
	setup_uart1();		//初始化串口1 用于下载动作组
	setup_uart3();		//初始化串口3 用于底板总线、蓝牙、lora
	setup_others();		//初始化其他
	setup_dj_timer();	//初始化定时器2 处理舵机PWM输出
	setup_start();		//初始化启动信号
	setup_interrupt();	//初始化总中断，开启中断

	setup_sensor();		//初始化传感器

	
	//kinematics 90mm 105mm 98mm 150mm
	//setup_kinematics(90, 105, 98, 150, &kinematics);
	
	while(1) {
		loop_nled();		//循环执行工作指示灯，500ms跳动一次 和声音公用一个IO口 这里在声音功能启用的时候就关闭nled
		loop_uart();		//串口数据接收处理
		loop_action();		//动作组批量执行
		loop_sensor();		//循环处理传感器	
		loop_monitor();   //定时保存一些变量
	}
}

//--------------------------------------------------------------------------------
/*
	初始化函数实现
*/

void setup_rcc(void) {   //初始化时钟
	tb_rcc_init();	  	   //时钟初始化
}

void setup_global(void) {//初始化全局变量
	tb_global_init();	
}

void setup_gpio(void) {  //初始化IO口
	tb_gpio_init();		    
}

void setup_nled(void) {  //初始化工作指示灯
	nled_init();		
	nled_off();		         //工作指示灯关闭
}

void setup_beep(void) {  //初始化定时器蜂鸣器
	beep_init();		
	beep_off();			       //关闭蜂鸣器
}			

void setup_djio(void) {  //初始化舵机IO口
	dj_io_init();		
}	



void setup_w25q64(void) {//初始化存储器W25Q64，用来储存动作组
	spiFlahsOn(1);
	w25x_init();				   //动作组存储芯片初始化
	w25x_read((u8 *)(&eeprom_info), W25Q64_INFO_ADDR_SAVE_STR, sizeof(eeprom_info));//读取全局变量
	
	if(eeprom_info.version != VERSION) {//判断版本是否是当前版本
		eeprom_info.version = VERSION;		//复制当前版本
		eeprom_info.dj_record_num = 0;		//学习动作组变量赋值0
	}
	
	if(eeprom_info.dj_bias_pwm[DJ_NUM] != FLAG_VERIFY) {
		for(i=0;i<DJ_NUM;i++) {
			eeprom_info.dj_bias_pwm[i] = 0;
		}
		eeprom_info.dj_bias_pwm[DJ_NUM] = FLAG_VERIFY;
	}
	
	for(i=0;i<DJ_NUM;i++) {
		duoji_doing[i].aim = 1500 + eeprom_info.dj_bias_pwm[i];
		duoji_doing[i].cur = 1500 + eeprom_info.dj_bias_pwm[i];
		duoji_doing[i].inc = 0;
	}
	spiFlahsOn(0);
}


void setup_adc(void) {//初始化ADC采集 使用DMA初始化
	ADC_init();
}


void setup_dj_timer(void) {//初始化定时器2 处理舵机PWM输出
	TIM2_Int_Init(20000, 71);	
}

void setup_uart1(void) {
  //串口1初始化
	tb_usart1_init(115200);
	//串口1打开
	uart1_open();
	//串口发送测试字符
	uart1_send_str((u8 *)"uart1 check ok!");
}

//初始化串口3
void setup_uart3(void) {
	//串口3初始化
	tb_usart3_init(115200);
	//串口3打开
	uart3_open();
	//串口发送测试字符
	uart3_send_str((u8 *)"uart3 check ok!");
	//总线输出 复位总线舵机 串口3即为总线串口
}	
//初始化滴答时钟，1S增加一次millis()的值
void setup_systick(void) {
	//系统滴答时钟初始化	
	SysTick_Int_Init();
}	
//初始化启动信号
void setup_start(void) {
	//蜂鸣器LED 名叫闪烁 示意系统启动
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
	beep_on();nled_on();tb_delay_ms(100);beep_off();nled_off();tb_delay_ms(100);
	tb_delay_ms(1000);
	zx_uart_send_str((u8 *)"#010P1501T0000!");
}	
//初始化其他
void setup_others(void) {	
	
	//将偏差带入初始值
	for(i=0;i<DJ_NUM;i++) {
		duoji_doing[i].aim = 1500+eeprom_info.dj_bias_pwm[i];
		duoji_doing[i].cur = duoji_doing[i].aim;
		duoji_doing[i].inc = 0;		
	}
	
	//执行预存命令 {G0000#000P1500T1000!#000P1500T1000!}
	if(eeprom_info.pre_cmd[PRE_CMD_SIZE] == FLAG_VERIFY) {
		strcpy((char *)uart_receive_buf, (char *)eeprom_info.pre_cmd);
		if(eeprom_info.pre_cmd[0] == '$') {
			parse_cmd(eeprom_info.pre_cmd);
		} else {
			for(i=16;i<strlen((char *)uart_receive_buf);i+=15) {
				uart_receive_buf[i] = '0';
				uart_receive_buf[i+1] = '0';
				uart_receive_buf[i+2] = '0';
				uart_receive_buf[i+3] = '0';
			}
			parse_action(uart_receive_buf);
		}
	}
}
//初始化总中断
void setup_interrupt(void) {
	//总中断打开
	tb_interrupt_open();//打开中断，包括UART中断，只有开启总中断，才能开启UART中断--只有当总中断打开的同时,串口中断被配置,串口中断才真正生效。
}	
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
/*
	主循环函数实现
*/
//循环执行工作指示灯，500ms跳动一次
void loop_nled(void) {
	static u32 time_count=0;
	static u8 flag = 0;
	if(millis()-time_count > 1000)  {
		time_count = millis();
		if(flag) {
			nled_on();
		} else {
			nled_off();
		}
		flag= ~flag;
	}
}		
//串口数据接收处理
void loop_uart(void) {
	if(uart1_get_ok) {
		if(uart1_mode == 1) {					    //命令模式
			parse_cmd(uart_receive_buf);			
		} else if(uart1_mode == 2) {			//单个舵机调试
			parse_action(uart_receive_buf);
		} else if(uart1_mode == 3) {		  //多路舵机调试
			parse_action(uart_receive_buf);
		} else if(uart1_mode == 4) {		  //存储模式
			save_action(uart_receive_buf);
		} 
		uart1_mode = 0;
		uart1_get_ok = 0;
		uart1_open();
	}
	return;
}	

//动作组批量执行
void loop_action(void) {
	//通过判断舵机是否全部执行完毕 并且是执行动作组group_do_ok尚未结束的情况下进入处理
	static long long systick_ms_bak = 0;
	if(group_do_ok == 0) {
		if(millis() - systick_ms_bak > action_time) {
			systick_ms_bak =  millis();
			if(group_num_times != 0 && do_time == 0) {
			  group_do_ok = 1;
			  uart1_send_str((u8 *)"@GroupDone!");
			  return;
			}
			//调用do_start_index个动作
			do_group_once(do_start_index);
			
			if(group_num_start<group_num_end) {
				if(do_start_index == group_num_end) {
					do_start_index = group_num_start;
					if(group_num_times != 0) {
						do_time--;
					}
					return;
				}
				do_start_index++;
			} else {
				if(do_start_index == group_num_end) {
					do_start_index = group_num_start;
					if(group_num_times != 0) {
						do_time--;
					}
					return;
				}
				do_start_index--;
			}
		}
	} else {
      action_time = 10;
	}
}

//--------------------------------------------------------------------------------
//定时保存一些变量
void loop_monitor(void) {
	static u32 saveTime = 3000;
	if((needSaveFlag == 1) || (millis() - bias_systick_ms_bak > saveTime)) {
		needSaveFlag = 0;
		bias_systick_ms_bak = millis();
		rewrite_eeprom();
	}	
	return;
}	

//软件复位函数，调用后单片机自动复位
void soft_reset(void) {
	__set_FAULTMASK(1);     
	NVIC_SystemReset();
}


//小车控制函数
//参数 左轮速度和右轮速度 范围 -1000 到 1000

//下面两段函数主要是T有差别
//car_set 用于小车固定速度一直运行
void car_set(int car_left1,int car_right1,int car_left2,int car_right2) {
	//总线马达设置	
	sprintf((char *)cmd_return, "{#006P%04dT0000!#007P%04dT0000!#008P%04dT0000!#009P%04dT0000!}", 
		(int)(1500+car_left1), (int)(1500-car_right1),(int)(1500+car_left2), (int)(1500-car_right2));
	zx_uart_send_str(cmd_return);
	return;
}
////car_set 用于小车固定速度运行一段时间
void car_set1(int car_left1,int car_right1,int car_left2,int car_right2) {
	//总线马达设置	
	sprintf((char *)cmd_return, "{#006P%04dT1500!#007P%04dT1500!#008P%04dT1500!#009P%04dT1500!}", 
		(int)(1500+car_left1), (int)(1500-car_right1),(int)(1500+car_left2), (int)(1500-car_right2));
	zx_uart_send_str(cmd_return);
	return;
}


/*
	所有舵机停止命令：    $DST!
	第x个舵机停止命令：   $DST:x!
	单片机重启命令：$RST!
	检查动作组x到y组命令：$CGP:x-y!
	执行第x个动作：       $DGS:x!
	执行第x到y组动作z次： $DGT:x-y,z!
	小车左x、右轮y速度:   $DCR:x,y!
	所有舵机复位命令：    $DJR!
	获取应答信号：        $GETA!
	获取智能信号：        $SMODE1!

	$KMS:x,y,z,time! //坐标单位mm，时间单位ms 测试点(0,120,30,1000) -> $KMS:0,120,20,2000!
*/
//命令解析函数
void parse_cmd(u8 *cmd) {
	int pos, i, index, int1, int2, int3, int4;
	
	//uart1_send_str(cmd);

	if(pos = str_contain_str(cmd, (u8 *)"$DRS!"), pos) 
	{
		uart1_send_str((u8 *)"Hello RT-thread!");
	} 
	else if(pos = str_contain_str(cmd, (u8 *)"$DST!"), pos) 
	{
		group_do_ok  = 1;
		for(i=0;i<DJ_NUM;i++) 
		{
			duoji_doing[i].inc = 0;	
			duoji_doing[i].aim = duoji_doing[i].cur;
		}
		zx_uart_send_str((u8 *)"#255PDST!");//总线停止
		car_set(0,0,0,0);	//车停
		AI_mode = 255;
	} 
	else if(pos = str_contain_str(cmd, (u8 *)"$DST:"), pos) 
	{
		if(sscanf((char *)cmd, "$DST:%d!", &index)) 
		{
			duoji_doing[index].inc = 0;	
			duoji_doing[index].aim = duoji_doing[index].cur;
			sprintf((char *)cmd_return, "#%03dPDST!\r\n", (int)index);
			zx_uart_send_str(cmd_return);
			memset(cmd_return, 0, sizeof(cmd_return));
		}
	} 
	else if(pos = str_contain_str(cmd, (u8 *)"$RST!"), pos) 
	{		
		soft_reset();
	} else if(pos = str_contain_str(cmd, (u8 *)"$PTG:"), pos) {		
		if(sscanf((char *)cmd, "$PTG:%d-%d!", &int1, &int2)) {
			print_group(int1, int2);
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DGS:"), pos) {		
		if(sscanf((char *)cmd, "$DGS:%d!", &int1)) {
			group_do_ok = 1;
			do_group_once(int1);
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DGT:"), pos) 
	{		
		if(sscanf((char *)cmd, "$DGT:%d-%d,%d!", &group_num_start, &group_num_end, &group_num_times)) {	
			group_do_ok = 1;			
			if(group_num_start != group_num_end) {
				do_start_index = group_num_start;
				do_time = group_num_times;
				group_do_ok = 0;
			} else {
				do_group_once(group_num_start);
			}
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DCR:"), pos) {		
		if(sscanf((char *)cmd, "$DCR:%d,%d,%d,%d!", &int1, &int2, &int3, &int4)) {
			car_set(int1, int2, int3, int4);			
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$DJR!"), pos) {	
		zx_uart_send_str((u8 *)"#255P1500T2000!\r\n");
		car_set(0,0,0,0);	
		AI_mode = 255;
		for(i=0;i<DJ_NUM;i++) {
			duoji_doing[i].aim = 1500+eeprom_info.dj_bias_pwm[i];
			duoji_doing[i].time = 2000;
			duoji_doing[i].inc = (duoji_doing[i].aim -  duoji_doing[i].cur) / (duoji_doing[i].time/20.000);
		}		
	}else if(pos = str_contain_str(cmd, (u8 *)"$QJ!"), pos) { //前进
	  car_set(1000,1000,1000,1000);	
	  zx_uart_send_str((u8 *)"#010P1502T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$HT!"), pos) { //后退		
		car_set(-1000,-1000,-1000,-1000);	
		zx_uart_send_str((u8 *)"#010P1503T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$ZZ!"), pos) {	//左转		
		car_set(-1000,1000,-1000,1000);	
		zx_uart_send_str((u8 *)"#010P1504T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$YZ!"), pos) {	//右转	
		car_set(1000,-1000,1000,-1000);	
		zx_uart_send_str((u8 *)"#010P1505T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$ZPY!"), pos) {	//左平移	
		car_set(-1000,1000,1000,-1000);
    zx_uart_send_str((u8 *)"#010P1506T0000!");
  }else if(pos = str_contain_str(cmd, (u8 *)"$YPY!"), pos) {	//右平移		
		car_set(1000,-1000,-1000,1000);
    zx_uart_send_str((u8 *)"#010P1507T0000!");
  }else if(pos = str_contain_str(cmd, (u8 *)"$TZ!"), pos) {	//停止	
		car_set(0,0,0,0);	
		zx_uart_send_str((u8 *)"#010P15013T0000!");
		AI_mode = 255;
  }else if(pos = str_contain_str(cmd, (u8 *)"$QJ1!"), pos) { //前进
	  car_set1(1000,1000,1000,1000);	
	  zx_uart_send_str((u8 *)"#010P1502T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$HT1!"), pos) { //后退		
		car_set1(-1000,-1000,-1000,-1000);	
		zx_uart_send_str((u8 *)"#010P1503T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$ZZ1!"), pos) {	//左转		
		car_set1(-1000,1000,-1000,1000);	
		zx_uart_send_str((u8 *)"#010P1504T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$YZ1!"), pos) {	//右转	
		car_set1(1000,-1000,1000,-1000);	
		zx_uart_send_str((u8 *)"#010P1505T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$ZPY1!"), pos) {	//左平移	
		car_set1(-1000,1000,1000,-1000);
    zx_uart_send_str((u8 *)"#010P1506T0000!");
  }else if(pos = str_contain_str(cmd, (u8 *)"$YPY1!"), pos) {	//右平移		
		car_set1(1000,-1000,-1000,1000);	
		zx_uart_send_str((u8 *)"#010P1507T0000!");
	}else if(pos = str_contain_str(cmd, (u8 *)"$GETA!"), pos) {		
		uart1_send_str((u8 *)"AAA");
	} 
	else if (pos = str_contain_str(cmd, (u8*)"$SMODE"), pos) 
	{
		if(sscanf((char *)uart_receive_buf, "$SMODE%d!", &int1)) 
		{
			AI_mode = int1;
			if(int1==0)zx_uart_send_str((u8 *)"#010P1512T0000!");
			if(int1==2)zx_uart_send_str((u8 *)"#010P1511T0000!");
			
			//uart1_send_str((u8 *)"@OK!");
			beep_on_times(1,100);
		}
	} else if(pos = str_contain_str(cmd, (u8 *)"$SMART_STOP!"), pos) {		
		AI_mode = 255;
		mdelay(10);
		parse_action((u8 *)"#255PDST!");
		mdelay(10);
		uart1_send_str((u8 *)"#006P1500T0000!#007P1500T0000!");
		mdelay(10);
		uart1_send_str((u8 *)"@OK!");
		mdelay(10);
		beep_on_times(1,100);
	}
}


//动作组保存函数
//只有用<>包含的字符串才能在此函数中进行解析
void save_action(u8 *str) {
	s32 action_index = 0;
	//预存命令处理
	spiFlahsOn(1);
	
	if(str[1] == '$' && str[2] == '!') {
		eeprom_info.pre_cmd[PRE_CMD_SIZE] = 0;
		rewrite_eeprom();
		uart1_send_str((u8 *)"@CLEAR PRE_CMD OK!");
		return;
	} else if(str[1] == '$') {
		if(sscanf((char *)str, "<$DGT:%d-%d,%d!>", &group_num_start, &group_num_end, &group_num_times)) {
			if(group_num_start == group_num_end) {
				w25x_read(eeprom_info.pre_cmd, group_num_start*ACTION_SIZE, ACTION_SIZE);	
			} else {
				memset(eeprom_info.pre_cmd, 0, sizeof(eeprom_info.pre_cmd));
				strcpy((char *)eeprom_info.pre_cmd, (char *)str+1);
				eeprom_info.pre_cmd[strlen((char *)str) - 2] = '\0';
			}
			eeprom_info.pre_cmd[PRE_CMD_SIZE] = FLAG_VERIFY;
			rewrite_eeprom();
			//uart1_send_str(eeprom_info.pre_cmd);
			uart1_send_str((u8 *)"@SET PRE_CMD OK!");
		}
		return;
	}
	//获取动作的组号如果不正确，或是第6个字符不是#则认为字符串错误
	action_index = get_action_index(str);
	
	//<G0000#000P1500T1000!>
	if((action_index == -1) || str[6] != '#'){
		uart1_send_str((u8 *)"E");
		return;
	}
	//把尖括号替换成大括号直接存储到存储芯片里面去，则在执行动作组的时候直接拿出来解析就可以了
	replace_char(str, '<', '{');
	replace_char(str, '>', '}');
	
	if((action_index*ACTION_SIZE % 4096) == 0){w25x_erase_sector(action_index*ACTION_SIZE/4096);}
	
	w25x_write(str, action_index*ACTION_SIZE, strlen((char *)str)+1);

//	memset(str, 0, sizeof((char *)str));
//	w25x_read(str, action_index*ACTION_SIZE, ACTION_SIZE);
//	uart1_send_str(str);
	
	//反馈一个A告诉上位机我已经接收到了
	uart1_send_str((u8 *)"A");
	uart3_send_str((u8 *)"A");
	
	spiFlahsOn(0);	
	return;	
}

//获取动作组的组号，字符串中有组号返回组号，否则返回-1
int get_action_index(u8 *str) {
	u16 index = 0;
	//uart_send_str(str);
	while(*str) {
		if(*str == 'G') {
			str++;
			while((*str != '#') && (*str != '$')) {
				index = index*10 + *str-'0';
				str++;	
			}
			return index;
		} else {
			str++;
		}
	}
	return -1;
}


//打印存储在芯片里的动作组，从串口1中发送出来 $CGP:x-y!这个命令调用
void print_group(int start, int end) {
	spiFlahsOn(1);
	
	if(start > end) {
		int_exchange(&start, &end);
	}
	
	for(;start<=end;start++) {
		memset(uart_receive_buf, 0, sizeof(uart_receive_buf));
		w25x_read(uart_receive_buf, start*ACTION_SIZE, ACTION_SIZE);
		uart1_send_str(uart_receive_buf);
		uart1_send_str((u8 *)"\r\n");
		
		uart3_send_str(uart_receive_buf);
		uart3_send_str((u8 *)"\r\n");
	}
	
	spiFlahsOn(0);
}

//两个int变量交换
void int_exchange(int *int1, int *int2) {
	int int_temp;
	int_temp = *int1;
	*int1 = *int2;
	*int2 = int_temp;
}

//获取最大时间
int getMaxTime(u8 *str) {
   int i = 0, max_time = 0, tmp_time = 0;
   while(str[i]) {
      if(str[i] == 'T') {
          tmp_time = (str[i+1]-'0')*1000 + (str[i+2]-'0')*100 + (str[i+3]-'0')*10 + (str[i+4]-'0');
          if(tmp_time>max_time)max_time = tmp_time;
          i = i+4;
          continue;
      }
      i++;
   }
   return max_time;
}

//执行动作组1次
//参数是动作组序号
void do_group_once(int group_num) {
	spiFlahsOn(1);
	memset(uart_receive_buf, 0, sizeof(uart_receive_buf));
	//从存储芯片中读取第group_num个动作组
	w25x_read(uart_receive_buf, group_num*ACTION_SIZE, ACTION_SIZE-1);	
	//获取最大的组时间
	action_time = getMaxTime(uart_receive_buf);
	
	//把读取出来的动作组传递到parse_action执行
	parse_action(uart_receive_buf);
	
	sprintf((char *)cmd_return, "@DoGroup %d OK!\r\n", group_num);
	uart1_send_str(cmd_return);
	spiFlahsOn(0);
	
}


//处理 #000P1500T1000! 类似的字符串
void parse_action(u8 *uart_receive_buf) {
	u16 index,  time, i = 0;
	int bias;
	float pwm;
	float aim_temp;
	zx_uart_send_str(uart_receive_buf);
	
	if(uart_receive_buf[0] == '#' && uart_receive_buf[4] == 'P' && uart_receive_buf[5] == 'S' && uart_receive_buf[6] == 'C' && uart_receive_buf[7] == 'K' && uart_receive_buf[12] == '!') {
		index = (uart_receive_buf[1] - '0')*100 + (uart_receive_buf[2] - '0')*10 + (uart_receive_buf[3] - '0');
		bias = (uart_receive_buf[9] - '0')*100 + (uart_receive_buf[10] - '0')*10 + (uart_receive_buf[11] - '0');
		if((bias >= -500) && (bias <= 500) && (index < DJ_NUM)) {
			if(uart_receive_buf[8] == '+') {
			} else if(uart_receive_buf[8] == '-') {
				bias = -bias;
			}
			aim_temp = duoji_doing[index].cur - eeprom_info.dj_bias_pwm[index] + bias;
			eeprom_info.dj_bias_pwm[index] = bias;			
			if(aim_temp > 2497){
				aim_temp = 2497;
			} else if(aim_temp < 500) {
				aim_temp = 500;
			}
			
			duoji_doing[index].aim = aim_temp;
			duoji_doing[index].cur = aim_temp;
			duoji_doing[index].inc = 0;
			bias_systick_ms_bak = millis();
			needSaveFlag = 1;
		}
		return;
	} else if(uart_receive_buf[0] == '#' && uart_receive_buf[4] == 'P' && uart_receive_buf[5] == 'D' && uart_receive_buf[6] == 'S' && uart_receive_buf[7] == 'T' && uart_receive_buf[8] == '!') {
		index = (uart_receive_buf[1] - '0')*100 + (uart_receive_buf[2] - '0')*10 + (uart_receive_buf[3] - '0');		
		if(index < DJ_NUM) {
			duoji_doing[index].inc = 0;	
			duoji_doing[index].aim = duoji_doing[index].cur;
		} else if(index == 255) {
			for(index=0;index<DJ_NUM;index++) {
				duoji_doing[index].inc = 0;	
				duoji_doing[index].aim = duoji_doing[index].cur;
			}
		}
		return;
	}
	
	while(uart_receive_buf[i]) {
		if(uart_receive_buf[i] == '#') {
			index = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != 'P') {
				index = index*10 + uart_receive_buf[i]-'0';i++;
			}
		} else if(uart_receive_buf[i] == 'P') {
			pwm = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != 'T') {
				pwm = pwm*10 + uart_receive_buf[i]-'0';i++;
			}
		} else if(uart_receive_buf[i] == 'T') {
			time = 0;i++;
			while(uart_receive_buf[i] && uart_receive_buf[i] != '!') {
				time = time*10 + uart_receive_buf[i]-'0';i++;
			}
			
			if(index < DJ_NUM && (pwm<=2500)&& (pwm>=500) && (time<=10000)) {
				//duoji_doing[index].inc = 0;
//				if(duoji_doing[index].cur == pwm) {
//					duoji_doing[index].cur -= 0.135;
//				}
				pwm += eeprom_info.dj_bias_pwm[index];
				
				if(pwm>2497)pwm=2497;
				if(pwm<500)pwm=500;
				
				if(time < 20) {
					duoji_doing[index].aim = pwm;
					duoji_doing[index].cur = pwm;
					duoji_doing[index].inc = 0;
				} else {
					duoji_doing[index].aim = pwm;
					duoji_doing[index].time = time;
					duoji_doing[index].inc = (duoji_doing[index].aim -  duoji_doing[index].cur) / (duoji_doing[index].time/20.000);
				}

				//sprintf(cmd_return, "#%03dP%04dT%04d! %f \r\n", index, pwm, time, duoji_doing[index].inc);
				//uart1_send_str(cmd_return);
			} 
			
			if(index == 255) {
				for(index=0;index<DJ_NUM;index++) {
					pwm =1500 + eeprom_info.dj_bias_pwm[index];
					duoji_doing[index].aim = pwm;
					duoji_doing[index].time = time;
					duoji_doing[index].inc = (duoji_doing[index].aim -  duoji_doing[index].cur) / (duoji_doing[index].time/20.000);
				}
			}
		} else {
			i++;
		}
	}	
}

//字符串中的字符替代函数 把str字符串中所有的ch1换成ch2
void replace_char(u8*str, u8 ch1, u8 ch2) {
	while(*str) {
		if(*str == ch1) {
			*str = ch2;
		} 
		str++;
	}
	return;
}

//把eeprom_info写入到W25Q64_INFO_ADDR_SAVE_STR位置
void rewrite_eeprom(void) {
	spiFlahsOn(1);
	w25x_erase_sector(W25Q64_INFO_ADDR_SAVE_STR/4096);
	w25x_writeS((u8 *)(&eeprom_info), W25Q64_INFO_ADDR_SAVE_STR, sizeof(eeprom_info));
	spiFlahsOn(0);
}
