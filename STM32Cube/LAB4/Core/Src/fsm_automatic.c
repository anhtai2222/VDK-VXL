/*
 * fsm_automatic.c
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"
#include "global.h"


// Khai báo biến toàn cục
  // Biến này lưu giá trị của lane hiện tại


// Wrapper hàm không tham số, chuyển tham số lane vào hàm chính
void task_display_time_1(void) {
    task_display_time(1);  // Gọi hàm chính với tham số là lane
}
void task_display_time_0(void) {
    task_display_time(0);  // Gọi hàm chính với tham số là lane
}
void counttime0(void){
	if (remaining_time_lane_0 >0) {
	    remaining_time_lane_0--; // Giảm thời gian còn lại
	  }
}
void counttime1(void){
	if (remaining_time_lane_1> 0) {
		    remaining_time_lane_1--;
		  }
}
// Hàm hiển thị thời gian còn lại cho từng lane
void task_display_time(int lane) {
    if (lane == 0) {

        display7SEG(0, remaining_time_lane_0 % 10);  // Hiển thị hàng đơn vị
        display7SEG(1,(int) remaining_time_lane_0 / 10);// Hiển thị hàng chục
       counttime0();
    } else {

        display7SEG(2, remaining_time_lane_1 % 10);  // Hiển thị hàng đơn vị
        display7SEG(3,(int) remaining_time_lane_1 / 10);  // Hiển thị hàng chục
        counttime1();
    }
}
// Quản lý trạng thái cho lane 0
void task_fsm_lane_0(void) {
    switch (LED_STATE[0]) {
        case INIT_STATE:
            setTrafficLightDefault(0);
            remaining_time_lane_0 = RED_DURATION;
            LED_STATE[0] = RED_STATE;
            break;
        case RED_STATE:
        	setTrafficLightRed(0);
        	SCH_Add_Task(task_red_state_lane_0,RED_DURATION*500,0);
            break;
        case YELLOW_STATE:
        	setTrafficLightAmber(0);
        	SCH_Add_Task(task_yellow_state_lane_0,YELLOW_DURATION*500,0);
            break;
        case GREEN_STATE:
        	setTrafficLightGreen(0);
              	SCH_Add_Task(task_green_state_lane_0,GREEN_DURATION*500,0);
                  break;
        default:
            break;
    }
}

// Quản lý trạng thái cho lane 1
void task_fsm_lane_1(void) {
    switch (LED_STATE[1]) {
        case INIT_STATE:
            setTrafficLightDefault(1);
            remaining_time_lane_1 = GREEN_DURATION;
            LED_STATE[1] = GREEN_STATE;
            break;
        case RED_STATE:
        	setTrafficLightRed(1);
        	SCH_Add_Task(task_red_state_lane_1,RED_DURATION*500,0);

        	break;
        case YELLOW_STATE:
        	setTrafficLightAmber(1);
        	SCH_Add_Task(task_yellow_state_lane_1,YELLOW_DURATION*500,0);
             break;
        case GREEN_STATE:
        	setTrafficLightGreen(1);
        	SCH_Add_Task(task_green_state_lane_1,GREEN_DURATION*500,0);
        	break;
        default:
        	break;
            }
    }

void task_red_state_lane_0(void) {
	 //setTrafficLightRed(0);
	   LED_STATE[0] = GREEN_STATE;
	   remaining_time_lane_0 = GREEN_DURATION;
	 //  SCH_Add_Task(task_display_time_0,0,500);

	}
	void task_yellow_state_lane_0(void) {
	   // setTrafficLightAmber(0);
	    LED_STATE[0] = RED_STATE;
	    remaining_time_lane_0 = RED_DURATION;
	   // SCH_Add_Task(task_display_time_0,0,500);

	}
	void task_green_state_lane_0(void) {
		//setTrafficLightGreen(0);
	      remaining_time_lane_0 = YELLOW_DURATION;

	      LED_STATE[0] = YELLOW_STATE;
	     // SCH_Add_Task(task_display_time_0,0,500);
	}

void task_red_state_lane_1(void) {
	//setTrafficLightRed(1);
   LED_STATE[1] = GREEN_STATE;
   remaining_time_lane_1 = GREEN_DURATION;
 //  SCH_Add_Task(task_display_time_1,0,500);


}
void task_yellow_state_lane_1(void) {
   // setTrafficLightAmber(1);
    LED_STATE[1] = RED_STATE;
    remaining_time_lane_1 = RED_DURATION;
  // SCH_Add_Task(task_display_time_1,0,500);

}
void task_green_state_lane_1(void) {
	// setTrafficLightGreen(1);
      remaining_time_lane_1 = YELLOW_DURATION;
      LED_STATE[1] = YELLOW_STATE;
    //  SCH_Add_Task(task_display_time_1,0,500);
}
