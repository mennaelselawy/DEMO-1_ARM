#include <LIB/std_types.h>
#include <CFG/SW_cfg.h>
#include <CFG/usart_cfg.h>
#include <MCAL/usart.h>

typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;

extern u8 Switch_DateTimeMode_FLAG;
extern Mode_t currentMode;

void Runnable_DateTimeMode() {
    if (Switch_DateTimeMode_FLAG) {
         Switch_DateTimeMode_FLAG = 0; // Clear the flag
        currentMode = DATE_TIME_MODE;
       
    }
}