/*
 * Scheduler.h
 *
 *  Created on: Mar 31, 2024
 *      Author: Menna Ashraf
 */
#ifndef SCHEDULER_CONFIG_H
#define SCHEDULER_CONFIG_H



typedef enum{
RUNNABLE_1_eachSwitch,
RUNNABLE_2_SendSwitchesTask,
RUNNABLE_3_ReceiveSwitchesTask,
RUNNABLE_4_LCD_Runnable,
RUNNABLE_5_LCD_Write,
RUNNABLE_6_LCD_Update,
RUNNABLE_7_TimeStamp,
RUNNABLE_8_StopWatchMode,
RUNNABLE_9_EditMode,
RUNNABLE_10_DateTimeMode,
	Num_Of_Runnables
}RUNNABLES_t;

#define  SCHEDULER_TickTime_MS  500

#endif
