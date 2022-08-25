#include "sys.h"
#include "delay.h"  
#include "usart.h"   
#include "led.h"
#include "lcd.h"
#include "key.h"  
#include "touch.h" 
#include "timer.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"
#include "demo_test.h"
#include "sram.h"
#include "test.h"
#include "pwm.h"

void TIM14_PWM_Init(u32 arr,u32 psc);


int main(void)
{ 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  //初始化延时函数
	uart_init(115200);		//初始化串口波特率为115200
	
	LED_Init();					//初始化LED 
 	LCD_Init();					//LCD初始化 
	KEY_Init(); 				//按键初始化
	TIM3_Int_Init(10-1,8400-1);
	TIM14_PWM_Init(20000-1,84-1);
	FSMC_SRAM_Init();
	tp_dev.init();				//触摸屏初始化 
	lv_init();			  // lvgl系统初始化
	lv_port_disp_init();  // lvgl显示接口初始化,放在lv_init()的后面
	lv_port_indev_init(); // lvgl输入接口初始化,放在lv_init()的后面                  
//	lv_demo_keypad_encoder();
	
	
	task_test_start();
	
	
	
	while (1)
	{
		tp_dev.scan(0);	
		lv_task_handler(); // lvgl的事务处理
		key_run();
    delay_ms(1);                           
	}
}  
