#include <LIB/std_types.h>
#include <CFG/SW_cfg.h>

typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;

volatile u8 Clock_HOURS = 0;
volatile u8 Clock_MINUTES = 0;
volatile u8 Clock_SECONDS = 0;

volatile u8 Date_day = 0;
volatile u8 Date_months = 0;
volatile u8 Date_year = 0;

extern u8 Switch_UP_START_FLAG;
extern u8 Switch_DOWN_PAUSE_FLAG;
extern u8 Switch_RIGHT_RESUME_FLAG;
extern u8 Switch_LEFT_STOP_FLAG;
extern u8 Switch_EditMode_FLAG;

extern Mode_t currentMode;

void Runnable_EditMode() 
{
    if(Switch_EditMode_FLAG)
 {
    Switch_EditMode_FLAG=0;
    currentMode=EDIT_MODE;
    u8 current_column =0;
    u8 current_row = 1;

       // Check for switch presses to move cursor or adjust value
     
        if(Switch_RIGHT_RESUME_FLAG) 
        {
            Switch_RIGHT_RESUME_FLAG = 0;
            current_column += 2;

             if (current_column >= 16) 
             {
                current_column = 0; // Reset column to 0 for the second row
                current_row = 2;    // Move to the second row
             }
            
            LCD_SetCursorPositionAsync(current_row, current_column, NULL);
        }
        else if (Switch_LEFT_STOP_FLAG) 
        {
            Switch_LEFT_STOP_FLAG=0;
            current_column -=2;

            if (current_column < 0)
             {
                current_column = 15; // Wrap around to the end of the first row
                current_row = 1;     // Move back to the first row
            }
            LCD_SetCursorPositionAsync(current_row, current_column, NULL);

           
        } 
        else if (Switch_UP_START_FLAG) 
        {
             Switch_UP_START_FLAG = 0; 
            switch(current_column)
            {
                case 0:
                    Date_day ++;
                break;
                case 2:
                    Date_months ++;
                break;
                case 4:
                    Date_year++;
                break;
                case 17:
                    Clock_HOURS ++;
                break;
                case 19:
                    Clock_MINUTES ++;
                break;
                case 20:
                    Clock_SECONDS ++;
                break;
                default:
                 //do nothing
                break; 
            }
       
        } 
        else if (Switch_DOWN_PAUSE_FLAG) 
        {
            switch(current_column)
            {
                case 0:
                    Date_day --;
                break;
                case 2:
                    Date_months --;
                break;
                case 4:
                    Date_year --;
                break;
                case 17:
                    Clock_HOURS --;
                break;
                case 19:
                    Clock_MINUTES --;
                break;
                case 20:
                    Clock_SECONDS --;
                break;
                default:
                 //do nothing
                break; 
            }
            Switch_DOWN_PAUSE_FLAG = 0;
         }    
 
    }
}