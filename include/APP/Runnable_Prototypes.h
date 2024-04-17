#ifndef RUNNABLE_PROTOTYPES_H_
#define RUNNABLE_PROTOTPES_H_


extern void SW_Runnable(void);
extern void SendSwitchesTask(void);
extern void ReceiveSwitchesTask();
extern void LCD_Runnable(void);
extern void LCD_Write(void);
extern void LCD_Update();
extern void Runnable_TimeStamp();
extern void Runnable_StopWatchMode();
extern void Runnable_EditMode() ;
extern void Runnable_DateTimeMode();
#endif