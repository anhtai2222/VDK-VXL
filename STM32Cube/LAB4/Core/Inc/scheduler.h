/*
 * scheduler.h
 *
 *  Created on: Nov 19, 2024
 *      Author: HOME
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"
#include <stdlib.h>

// Định nghĩa cấu trúc sTask để lưu trữ các thông tin về task
typedef struct sTask{
	void (*pTask)(void);    // Hàm con cần chạy
	uint32_t Delay;         // Độ trễ của task (trong ms)
	uint32_t Period;        // Chu kỳ của task (trong ms)
	struct sTask * next;    // Con trỏ đến task kế tiếp trong danh sách
	struct sTask * prev;    // Con trỏ đến task trước đó trong danh sách
}sTask;

// Định nghĩa cấu trúc List cho danh sách các task
typedef struct sList{
	sTask * head;           // Con trỏ đến task đầu tiên trong danh sách
	sTask * tail;           // Con trỏ đến task cuối cùng trong danh sách
	uint8_t numTask;        // Số lượng task hiện tại trong danh sách
}sList;

// Khai báo hai danh sách: taskList và taskRunList
extern sList taskList;      // Danh sách các task đang chờ thực thi
extern sList taskRunList;   // Danh sách các task đang được thực thi

// Các hàm xử lý các tác vụ trong scheduler
void SCH_Init(void);                   // Khởi tạo scheduler
void SCH_Add_Task(void (*function)(), uint32_t Delay, uint32_t Period);  // Thêm task vào danh sách
void SCH_Update(void);                 // Cập nhật trạng thái của các task (giảm delay)
void SCH_Dispatch_Task(void);          // Thực thi các task trong danh sách chạy
uint8_t SCH_Is_Task_Exist(void (*function)());  // Kiểm tra task có tồn tại hay không
uint8_t SCH_Delete_Task(void (*function)());    // Xóa task khỏi danh sách

// Các hàm xử lý task trong danh sách chạy (taskRunList)
void add_TaskToRunList(void (*function)());  // Thêm task vào danh sách chạy
void delete_TaskFromRunList(void (*function)());  // Xóa task khỏi danh sách chạy

#endif /* INC_SCHEDULER_H_ */
