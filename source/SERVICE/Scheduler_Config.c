/*
 * Scheduler_Config.c
 *
 *  Created on: Mar 31, 2024
 *      Author: Menna Ashraf
 */

#include"STD_TYPES.h"
#include"SCHEDULER/Scheduler.h"
#include"SCHEDULER/Scheduler_Config.h"
#include"Runnable_prototypes.h"


const RUNNABLE_t  RUNNABLES[Num_Of_Runnables] = {
		[RUNNABLE_1_eachSwitch] = {.name="RUNNABLE_1_eachSwitch", .priority = RUNNABLE_1_eachSwitch, .priodicity = 5, .FirstDelay = 0, .CallBack = SW_Runnable, .TaskRunState = Running},
		[RUNNABLE_2_SendSwitchesTask] = {.name="RUNNABLE_2_SendSwitchesTask", .priority = RUNNABLE_2_SendSwitchesTask, .priodicity = 10, .FirstDelay = 1, .CallBack = SendSwitchesTask, .TaskRunState = Running},
		[RUNNABLE_3_ReceiveSwitchesTask] = { .name="RUNNABLE_3_ReceiveSwitchesTask", .priority = RUNNABLE_3_ReceiveSwitchesTask,	.priodicity = 10, .FirstDelay = 2, .CallBack = ReceiveSwitchesTask, .TaskRunState = Running},
		[RUNNABLE_4_LCD_Runnable] = { .name="RUNNABLE_4_LCD_Runnable", .priority = RUNNABLE_4_LCD_Runnable,	.priodicity = 1000, .FirstDelay = 0, .CallBack = LCD_Runnable , .TaskRunState = Running},
		[RUNNABLE_5_LCD_Write] = {.name="RUNNABLE_5_LCD_Write", .priority = RUNNABLE_5_LCD_Write, .priodicity = 1000, .FirstDelay = 1, .CallBack = LCD_Write, .TaskRunState = Running},
		[RUNNABLE_6_LCD_Update] = {.name="RUNNABLE_6_LCD_Update", .priority = RUNNABLE_6_LCD_Update, .priodicity = 1000, .FirstDelay = 2, .CallBack = LCD_Update, .TaskRunState = Running},
		[RUNNABLE_7_TimeStamp] = { .name="RUNNABLE_7_TimeStamp", .priority = RUNNABLE_7_TimeStamp,	.priodicity = 1000, .FirstDelay = 0, .CallBack = Runnable_TimeStamp, .TaskRunState = Running},
		[RUNNABLE_8_StopWatchMode] = { .name="RUNNABLE_8_StopWatchMode", .priority = RUNNABLE_8_StopWatchMode,	.priodicity = 500, .FirstDelay = 0, .CallBack = Runnable_StopWatchMode, .TaskRunState = Running},
		[RUNNABLE_9_EditMode] = { .name="RUNNABLE_9_EditMode", .priority = RUNNABLE_9_EditMode,	.priodicity = 1000, .FirstDelay = 0, .CallBack = Runnable_EditMode, .TaskRunState = Running},
                [RUNNABLE_10_DateTimeMode] = { .name="RUNNABLE_10_DateTimeMode", .priority = RUNNABLE_10_DateTimeMode,	.priodicity = 1000, .FirstDelay = 0, .CallBack = Runnable_DateTimeMode, .TaskRunState = Running},

};



