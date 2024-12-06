/*
 * fsm_automatic.h
 *
 *  Created on: Oct 20, 2024
 *      Author: Admin
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_


#include "scheduler.h"
void task_display_time_1(void) ;
void task_display_time_0(void) ;
void fsm_automatic_run(int lane);
void displayDuration(int mode, int duration);
void changeMode(int mode);
void counttime0(void);
void counttime1(void);
void task_display_time(int lane);      // Hiển thị thời gian cho lane (có tham số lane)
void task_display_time_wrapper(void);  // Wrapper không tham số cho hàm hiển thị
void task_update_time_lane_0(void);    // Cập nhật thời gian cho lane 0
void task_update_time_lane_1(void);    // Cập nhật thời gian cho lane 1

// Các hàm quản lý trạng thái FSM cho lane 0 và lane 1
void task_fsm_lane_0(void);   // Quản lý trạng thái cho lane 0
void task_fsm_lane_1(void);   // Quản lý trạng thái cho lane 1

// Các hàm chuyển trạng thái cho lane 0 (RED -> GREEN -> YELLOW)
void task_red_state_lane_0(void);
void task_green_state_lane_0(void);
void task_yellow_state_lane_0(void);

// Các hàm chuyển trạng thái cho lane 1 (GREEN -> YELLOW -> RED)
void task_green_state_lane_1(void);
void task_yellow_state_lane_1(void);
void task_red_state_lane_1(void);


#endif /* INC_FSM_AUTOMATIC_H_ */
