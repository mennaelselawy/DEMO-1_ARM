#include <LIB/std_types.h>

typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;

volatile u8 StopWatch_HOURS = 0;
volatile u8 StopWatch_MINUTES = 0;
volatile u8 StopWatch_SECONDS = 0;
volatile u8 GLOBAL_STOP_WATCH_STATE = 0;

extern u8 Switch_UP_START_FLAG;
extern u8 Switch_DOWN_PAUSE_FLAG;
extern u8 Switch_RIGHT_RESUME_FLAG;
extern u8 Switch_LEFT_STOP_FLAG;
extern u8 Switch_StopWatch_FLAG;

extern Mode_t currentMode;
void Runnable_StopWatchMode()
{
    if(Switch_StopWatch_FLAG)

 {
     Switch_StopWatch_FLAG=0;
     currentMode=STOPWATCH_MODE;
    if (GLOBAL_STOP_WATCH_STATE)
    {
        StopWatch_SECONDS++;
        if (StopWatch_SECONDS >= 60)
        {
            StopWatch_SECONDS = 0;
            StopWatch_MINUTES++;
            if (StopWatch_MINUTES >= 60)
            {
                StopWatch_MINUTES = 0;
                StopWatch_HOURS++;
                if (StopWatch_HOURS > 24)
                {
                    StopWatch_HOURS = 0;
                }
            }
        }
    }

    if (Switch_UP_START_FLAG)
    {
        Switch_UP_START_FLAG = 0;
        GLOBAL_STOP_WATCH_STATE = 1;
    }

    if (Switch_DOWN_PAUSE_FLAG)
    {
        Switch_DOWN_PAUSE_FLAG = 0;
        GLOBAL_STOP_WATCH_STATE = 0;
    }

    if (Switch_RIGHT_RESUME_FLAG)
    {
        Switch_RIGHT_RESUME_FLAG = 0;
        GLOBAL_STOP_WATCH_STATE = 1;
    }

    if (Switch_LEFT_STOP_FLAG)
    {
        Switch_LEFT_STOP_FLAG = 0;
        GLOBAL_STOP_WATCH_STATE = 0;
    }
  }
}
