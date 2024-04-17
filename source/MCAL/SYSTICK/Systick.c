/*
 * Systick.c
 *
 *  Created on: Mar 23, 2024
 *      Author: Menna Ashraf
 */

#include"STD_TYPES.h"
#include"GPIO/GPIO.h"
#include"SYSTICK/Systick.h"
#include"SYSTICK/Systick_Config.h"

#define ENABLE_MASK              0x1
#define TICK_INT_MASK            0x2
#define CLK_SOURCE_MASK          0x4
#define COUNT_FLAG_MASK          0x10000
#define MAX_LOAD_VALUE           0xFFFFFF  /*24 bits*/

#define INTERRUPT_CLEAR_MASK_FLAG     0x2

#define MS_TO_US(ms_Time)        ms_Time*1000
#define US_TO_MS(us_time)        us_time/1000

typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}Systick_Registers_t;

#define SYSTICK_BASE_ADDRESS     0xE000E010
#define SYSTICK                 ((volatile Systick_Registers_t*)SYSTICK_BASE_ADDRESS)



static SystickCBF_t GLOBAL_AppCBF;

u8 GLOBAL_MODE;
COM_ErrorStatus_t Systick_Start(u8 MODE) /*Enable Systick*/
{
	COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_NOK;
	if(MODE > SYSTICK_MODE_PERIODIC)
	{
		RET_ErorrStatus = SYSTICK_NOK;
	}
	else
	{
		SYSTICK->CTRL |= ENABLE_MASK;
		SYSTICK->CTRL |= 2;
		GLOBAL_MODE =MODE;
		RET_ErorrStatus = SYSTICK_OK;
	}
	return RET_ErorrStatus;
}

COM_ErrorStatus_t Systick_Stop() /*disable Systick*/
{
	COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_OK;
	SYSTICK->CTRL &= ~ ENABLE_MASK;
		RET_ErorrStatus = SYSTICK_OK;
	return RET_ErorrStatus;
}
	


COM_ErrorStatus_t Systick_ConfigureClockSource(u8 Clock_Source)
{
	COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_OK;
	if(Clock_Source > SYSTICK_CLOCK_SOURCE_PROCESSOR_AHB)
	{
		RET_ErorrStatus = SYSTICK_NOK;
	}
	else
	{
		switch(Clock_Source)
		{
		case SYSTICK_CLOCK_SOURCE_EXTERNAL_AHBdiv8:
			SYSTICK->CTRL &= ~CLK_SOURCE_MASK;
			break;
		case SYSTICK_CLOCK_SOURCE_PROCESSOR_AHB:
			SYSTICK->CTRL |= CLK_SOURCE_MASK;
			break;
		default:
			RET_ErorrStatus = SYSTICK_NOK;
		}
	}
	return RET_ErorrStatus;
}

COM_ErrorStatus_t Systick_SetTimeMS(u32 Time)
{
	f32 LOC_Prescaller;
	f32 LOC_SystemClock = 16;
	COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_OK;
	if((SYSTICK->CTRL & CLK_SOURCE_MASK) == SYSTICK_CLOCK_SOURCE_PROCESSOR_AHB)
		{
			LOC_Prescaller = 1;
		}
		else
		{
			LOC_Prescaller = 8;
		}
	
	
	f32 LOC_TimeTicks_US = LOC_Prescaller/LOC_SystemClock;
	u32 LOC_Time_Overflow_MS = US_TO_MS(MAX_LOAD_VALUE * LOC_TimeTicks_US);

	
	if(Time > LOC_Time_Overflow_MS)
	{
		RET_ErorrStatus = SYSTICK_NOK;
	}
	else
	{
		
		SYSTICK->LOAD = (MS_TO_US(Time) / LOC_TimeTicks_US) - 1;
	}
	return RET_ErorrStatus;
}

void Systick_IsExbired(void) //disable systick
{
	SYSTICK->CTRL &=~ ENABLE_MASK;
}

void Systick_EnbaleInterrupt(void)
{
	u8 LOCAL_TEMP = SYSTICK->CTRL;
	LOCAL_TEMP &= ~INTERRUPT_CLEAR_MASK_FLAG;
	LOCAL_TEMP |= TICK_INT_MASK;
	SYSTICK->CTRL = LOCAL_TEMP;
}
void Systick_DisableInterrupt(void)
{
	SYSTICK->CTRL &=~ TICK_INT_MASK;
}

COM_ErrorStatus_t Systick_SetCallBack(SystickCBF_t CBF)
{
	COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_OK;
	if(CBF == NULL)
	{
		RET_ErorrStatus = Error_NULLPointer;
	}
	else
	{
		GLOBAL_AppCBF = CBF;
	}
	return RET_ErorrStatus;
}

void SysTick_Handler(void)
{
	if(GLOBAL_AppCBF)
	{
		GLOBAL_AppCBF();
		if(GLOBAL_MODE == SYSTICK_MODE_ONE_SHOT)
		{
			Systick_Stop();
		}else{

		}
	}
}


COM_ErrorStatus_t SYSTICK_SET_CurrentVal(u32 Current_Val)
{
    COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_NOK;
    u32 LOCAL_VAL = 0;

    if (Current_Val > MAX_LOAD_VALUE)
    {
        RET_ErorrStatus = Error_InvalidInput;
    }
    else
    {
        RET_ErorrStatus = SYSTICK_OK;
        LOCAL_VAL = Current_Val;
        SYSTICK->VAL = LOCAL_VAL;
    }

    return RET_ErorrStatus;
}

COM_ErrorStatus_t SYSTICK_GET_CurrentVal(u32 *Current_Val)
{
    COM_ErrorStatus_t RET_ErorrStatus = SYSTICK_NOK;

    if (Current_Val == NULL)
    {
        RET_ErorrStatus = Error_NULLPointer;
    }
    else
    {
        RET_ErorrStatus = SYSTICK_OK;
        *Current_Val = SYSTICK->VAL;
    }

    return RET_ErorrStatus;
}