#include "test.h"
#include "lvgl.h"
#include "key.h"
#include "stdio.h"
#include "pwm.h"
#include "delay.h"
lv_obj_t* arc;

static uint16_t pwm_valu;

void task_test_start()
{
	arc = lv_arc_create(lv_scr_act());
	lv_arc_set_range(arc,0,180);
	lv_arc_set_value(arc,23);
	lv_obj_set_size(arc,200,200);
	lv_obj_align_to(arc,NULL,LV_ALIGN_CENTER,0,0);	
	
}
	
 void key_run()
 {
	 TIM_SetCompare1(TIM14,500+(lv_arc_get_value(arc)*11.1));
//	 u8 key_valu;

//	 key_valu = KEY_Scan(0);
//	 
//	 if(key_valu == KEY0_PRES)
//	 { 
//		 
//		 printf("%d\r\n",lv_arc_get_value(arc));
//	 }
//	 else if(key_valu == KEY1_PRES)
//	 {

//	 }
//	 else if(key_valu == KEY2_PRES)
//	 {

//	 }
//	 else if(key_valu == WKUP_PRES)
//	 {

//	 }
  
 }
 
 