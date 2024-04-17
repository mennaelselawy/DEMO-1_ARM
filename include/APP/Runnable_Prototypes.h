#ifndef RUNNABLE_PROTOTYPES_H_
#define RUNNABLE_PROTOTPES_H_


// extern void Runnable_LED_Toggle(void);
// extern void Runnable_LED_SW_ON_OFF(void);
// extern void SW_Runnable(void);
// extern void Runnable_LED_StateMachine(void);
extern void LCD_Runnable(void);
extern void LCD_Write(void);
extern void LCD_Update();
extern void Runnable_TimeStamp();
extern void SendSwitchesTask(void);
extern void ReceiveSwitchesTask();
extern void Runnable_StopWatchMode();
extern void Runnable_EditMode() ;
extern void Runnable_DateTimeMode();
#endif