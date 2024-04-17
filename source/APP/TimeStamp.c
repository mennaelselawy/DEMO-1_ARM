#include <LIB/std_types.h>
#include <CFG/SW_cfg.h>
typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;

extern u8 GLOBAL_STOP_WATCH_STATE;
extern volatile u8 Clock_SECONDS; 
extern volatile u8 StopWatch_SECONDS;
extern Mode_t currentMode;

void Runnable_TimeStamp() {
    if (currentMode != DATE_TIME_MODE ) {
        Clock_SECONDS++; // Increment seconds for Clock mode
    }
    if (currentMode != STOPWATCH_MODE && GLOBAL_STOP_WATCH_STATE==1) {
        StopWatch_SECONDS++; // Increment seconds for Stopwatch mode
    }
}
