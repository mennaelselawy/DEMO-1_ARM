#include<HAL/SW.h>
#include <CFG/SW_cfg.h>
#include <MCAL/usart.h>
#include <CFG/usart_cfg.h>
#include<LIB/std_types.h>


typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;

#define NOT_PRESSED       0
#define PRESSED           1

 u8 Switch_UP_START_FLAG;
 u8 Switch_DOWN_PAUSE_FLAG;
 u8 Switch_RIGHT_RESUME_FLAG;
 u8 Switch_LEFT_STOP_FLAG;
 u8 Switch_EditMode_FLAG ;
 u8 Switch_DateTimeMode_FLAG;
 u8 Switch_StopWatch_FLAG; 

 u8 RecievedSwitch;

u8 SendBuffer[1];
u8 ReceiveBuffer[1];

extern Mode_t currentMode;
extern u8 current_pressedswitch;

void SendSwitchesTask(void)
{
    u8 switch_state;
    u8 i;
    for ( i = 0; i < _SW_Num; i++)
    {
        SW_GetState(i, &switch_state);
        if (switch_state ==PRESSED)
        {

        	 current_pressedswitch=i;
        	
        	 SendBuffer[0] = current_pressedswitch;
             Uart_TxBufferAsync(SendBuffer,1,UART_1,NULL);
                break;
        }
    }

}

void ReceiveSwitchesTask(){

    Uart_RxBufferAsync(ReceiveBuffer, 1, UART_1,NULL);
    

    RecievedSwitch = ReceiveBuffer[0];
    switch (RecievedSwitch)
    {
    case Switch_UP_START:
        Switch_UP_START_FLAG = 1;
        break;
    case Switch_DOWN_PAUSE:
        Switch_DOWN_PAUSE_FLAG = 1;
        break;
    case Switch_RIGHT_RESUME:
        Switch_RIGHT_RESUME_FLAG = 1;
        break;
    case Switch_LEFT_STOP:
        Switch_LEFT_STOP_FLAG = 1;
        break;
    case Switch_EditMode:
        Switch_EditMode_FLAG = 1;
        break;
    case Switch_Date_TimeMode:
       Switch_DateTimeMode_FLAG = 1;
        break;
        case Switch_StopWatchMode:
        Switch_StopWatch_FLAG = 1;
        break;
    default:
        // Handle other switches if needed
        break;
    }
}




