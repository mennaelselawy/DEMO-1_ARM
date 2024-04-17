
#include<HAL/LCD.h>
#include<LIB/std_types.h>
typedef enum {
    DATE_TIME_MODE,
    STOPWATCH_MODE,
    EDIT_MODE
} Mode_t;
extern u8 StopWatch_HOURS ;
extern u8 StopWatch_MINUTES;
extern u8 StopWatch_SECONDS;

extern u8 Date_day ;
extern u8 Date_months ;
extern u8 Date_year ;

extern u8 Clock_HOURS ;
extern u8 Clock_MINUTES ;
extern u8 Clock_SECONDS ;

u8 edited_date[11] = "17/04/2024"; // "DD/MM/YYYY\0"
u8 edited_time[9]  = "00:00:00"; 

Mode_t currentMode=DATE_TIME_MODE;

void Display_DateTimeMode();
void Display_EditMode();
void Display_StopWatchMode();



void Display_DateTimeMode() {
    // Clear the LCD screen
    LCD_ClearScreenAsync(NULL);

    // Display the edited date
    LCD_WriteStringAsync(edited_date, 10, NULL);

    // Display the edited time
    LCD_WriteStringAsync(edited_time, 5, NULL);
}

void Display_EditMode(){

    // Populate edited_date array
    edited_date[0] = (Date_day / 10) + '0';
    edited_date[1] = (Date_day % 10) + '0';
    edited_date[2] = '/';
    edited_date[3] = (Date_months / 10) + '0';
    edited_date[4] = (Date_months % 10) + '0';
    edited_date[5] = '/';
    edited_date[6] = (Date_year / 1000) + '0';
    edited_date[7] = (Date_year / 100 % 10) + '0';
    edited_date[8] = (Date_year / 10 % 10) + '0';
    edited_date[9] = (Date_year % 10) + '0';
    edited_date[10] = '\0';

    // Populate edited_time array
    edited_time[0] = (Clock_HOURS / 10) + '0';
    edited_time[1] = (Clock_HOURS % 10) + '0';
    edited_time[2] = ':';
    edited_time[3] = (Clock_MINUTES / 10) + '0';
    edited_time[4] = (Clock_MINUTES % 10) + '0';
    edited_time[5] = ':';
    edited_time[6] = (Clock_SECONDS / 10) + '0';
    edited_time[7] = (Clock_SECONDS % 10) + '0';
    edited_time[8] = '\0';

    
    
    LCD_WriteStringAsync(edited_date, 0, NULL);
    LCD_WriteStringAsync(edited_time, 12, NULL);
}

void Display_StopWatchMode() {
    // Clear the LCD screen
    LCD_ClearScreenAsync(NULL);

    // Create variables to hold the stopwatch time
    u8 hours = StopWatch_HOURS;
    u8 minutes = StopWatch_MINUTES;
    u8 seconds = StopWatch_SECONDS;

    // Convert hours, minutes, and seconds to strings
    u8 hours_str[3];
    u8 minutes_str[3];
    u8 seconds_str[3];
    hours_str[0] = hours / 10 + '0';
    hours_str[1] = hours % 10 + '0';
    hours_str[2] = '\0';
    minutes_str[0] = minutes / 10 + '0';
    minutes_str[1] = minutes % 10 + '0';
    minutes_str[2] = '\0';
    seconds_str[0] = seconds / 10 + '0';
    seconds_str[1] = seconds % 10 + '0';
    seconds_str[2] = '\0';

    // Display the stopwatch time on the LCD
    LCD_WriteStringAsync(hours_str, 2, NULL);
    LCD_WriteStringAsync(":", 1, NULL);
    LCD_WriteStringAsync(minutes_str, 2, NULL);
    LCD_WriteStringAsync(":", 1, NULL);
    LCD_WriteStringAsync(seconds_str, 2, NULL);
}




void LCD_Update() {
    // Clear the LCD screen
    LCD_ClearScreenAsync(NULL);

    // Set cursor position to the beginning
    LCD_SetCursorPositionAsync(1, 0, NULL);

    // Display content based on current mode
    switch (currentMode) {
        case DATE_TIME_MODE:
            Display_DateTimeMode();
            break;
        case STOPWATCH_MODE:
            Display_StopWatchMode();
            break;
        case EDIT_MODE:
            Display_EditMode();
            break;
        default:
            // Handle invalid mode
            break;
    }
}

