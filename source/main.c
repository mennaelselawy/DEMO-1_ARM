#include"STD_TYPES.h"

#include"SCHEDULER/Scheduler.h"
#include"SCHEDULER/Scheduler_Config.h"

#include"RCC/RCC.h"

#include"GPIO/GPIO.h"

#include"NVIC/STM32F401CC_VectorTable.h"
#include"NVIC/NVIC.h"

#include"SYSTICK/Systick.h"
#include"SYSTICK/Systick_Config.h"

#include"USART.h"

#include"SWITCH/SWITCH.h"
#include"SWITCH/SWITCH_CONFIG.h"

#include"LCD/LCD.h"
#include"LCD/LCD_Config.h"
#include"LCD/LCD_Private.h"

int main()
{
    RCC_EnablePeriphera(BUS_AHB1, PERIPHERAL_GPIOA_AHB1);
    RCC_enuEnablePreipheral(BUS_AHB1, PERIPHERAL_GPIOB_AHB1);
    RCC_enuEnablePreipheral(BUS_APB2, PERIPHERAL_USART1_APB2);

    LCD_Init_Asynch();
    Switch_Init();

    Scheduler_Init();
    Scheduler_StartOS();
}