#include "scheduler.h"

// Đổi tên list và list_run thành taskList và taskRunList
sList taskList;


void SCH_Init(void) {
	taskList.head = NULL;
	taskList.tail = NULL;
    taskList.numTask = 0;

    taskRunList.head = NULL;
    taskRunList.tail = NULL;
    taskRunList.numTask = 0;
}

void SCH_Add_Task(void (*function)(), uint32_t Delay, uint32_t Period){
	if(SCH_Is_Task_Exist(function) == 1)
		return;
	sTask * newTask = (sTask *) malloc (sizeof(sTask));
	if (newTask == NULL)
		return;

	newTask->pTask = function;
	newTask->Delay = Delay/10; // scale for TIM2 10ms run
	newTask->Period = Period/10;
	newTask->next = NULL;
	newTask->prev = NULL;

	if(taskList.head == NULL){
		taskList.head = newTask;
		taskList.tail = newTask;
	}
	else{
		newTask->prev = taskList.tail;
		taskList.tail->next = newTask;
		taskList.tail = newTask;
	}
	taskList.numTask++;
}

void SCH_Update(void){
	sTask * temp = taskList.head;
	while(temp != NULL){
		if(temp->Delay > 0){
			temp->Delay --;
		}
		else{
			//temp->RunMe++;
			add_TaskToRunList(temp->pTask);
			temp->Delay = temp->Period;
			if(temp->Period == 0){
				sTask * del = temp;
				temp = temp->next;
				SCH_Delete_Task(del->pTask);
				continue;
			}
		}
		temp = temp->next;
	}
}

void SCH_Dispatch_Task(void){
	sTask * temp = taskRunList.head;
	while(temp != NULL){
		temp->pTask();
		sTask* del = temp;
		temp = temp->next;
		delete_TaskFromRunList(del->pTask);
	}
}



uint8_t SCH_Delete_Task(void (*function)()){
	if(taskList.numTask == 0)
		return 0;
	sTask * temp = taskList.head;
	while(temp != 0){
		if(temp->pTask == function){
			if(temp->prev == NULL){ // delete head
				temp->next->prev = NULL;
				taskList.head = temp->next;
			}
			else if (temp->next == NULL){ //delete tail
				temp->prev->next = NULL;
				taskList.tail = temp->prev;
			}
			else{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			taskList.numTask--;
			free(temp);
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

uint8_t SCH_Is_Task_Exist(void (*function)()){
	if(taskList.numTask == 0) return 0;
	sTask * temp = taskList.head;
	while(temp != NULL){
		if(temp->pTask == function)
			return 1;
		temp = temp->next;
	}
	return 0;
}
