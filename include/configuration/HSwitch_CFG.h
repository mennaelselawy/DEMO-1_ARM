#ifndef HSwitch_CFG_H_
#define HSwitch_CFG_H_
/*******************************************************************************
 *                        	  Types Declaration                                 *
 *******************************************************************************/
/* Configure The HSwitchs Namein this Enum */
typedef enum 
{
	Switch_mode,
	Switch_UP_START,
	Switch_DOWN_PAUSE,
	Switch_RIGHT_RESUME,
	Switch_LEFT_STOP,
    Switch_EditMode,
    Switch_Date_TimeMode,
    Switch_StopWatchMode,
    _Switch_Num
}Switches_t;

#endif