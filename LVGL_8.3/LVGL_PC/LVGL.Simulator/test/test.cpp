#include "test.h"
#include "lvgl/lvgl.h"

lv_obj_t* arc;

void test(void)
{
    arc = lv_arc_create(lv_scr_act());
    lv_arc_set_range(arc, 0, 180); //设置最大值和最小值
    lv_arc_set_value(arc, 0);//设置起始值
//	lv_arc_set_angles(arc ,0,180); //设置开始结束角度
//	lv_arc_set_bg_start_angle(arc,0);
    lv_obj_set_size(arc, 200, 200);//设置大小
    lv_obj_align_to(arc, NULL, LV_ALIGN_CENTER, 0, 0);//设置对齐方式--居中 
}
