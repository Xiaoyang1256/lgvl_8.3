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

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);		//��ʼ�����ڲ�����Ϊ115200
	
	LED_Init();					//��ʼ��LED 
 	LCD_Init();					//LCD��ʼ�� 
	KEY_Init(); 				//������ʼ��
	TIM3_Int_Init(10-1,8400-1);
	TIM14_PWM_Init(20000-1,84-1);
	FSMC_SRAM_Init();
	tp_dev.init();				//��������ʼ�� 
	lv_init();			  // lvglϵͳ��ʼ��
	lv_port_disp_init();  // lvgl��ʾ�ӿڳ�ʼ��,����lv_init()�ĺ���
	lv_port_indev_init(); // lvgl����ӿڳ�ʼ��,����lv_init()�ĺ���                  
//	lv_demo_keypad_encoder();
	
	
	task_test_start();
	
	
	
	while (1)
	{
		tp_dev.scan(0);	
		lv_task_handler(); // lvgl��������
		key_run();
    delay_ms(1);                           
	}
}  
