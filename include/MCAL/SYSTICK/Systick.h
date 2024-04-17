/*
 * Systick.h
 *
 *  Created on: Mar 23, 2024
 *      Author: Menna Ashraf
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include"STD_TYPES.h"

#define SYSTICK_CLOCK_SOURCE_EXTERNAL_AHBdiv8      0x0
#define SYSTICK_CLOCK_SOURCE_PROCESSOR_AHB         0x4

#define SYSTICK_MODE_ONE_SHOT                      0x0
#define SYSTICK_MODE_PERIODIC                      0x2


typedef void(*SystickCBF_t)(void);

/*options:
SYSTICK_MODE_ONE_SHOT
SYSTICK_MODE_PERIODIC
*/
COM_ErrorStatus_t Systick_Start(u8 MODE); /*Enable Systick*/

/*options:
SYSTICK_CLOCK_SOURCE_EXTERNAL_AHBdiv8
SYSTICK_CLOCK_SOURCE_PROCESSOR_AHB
*/
COM_ErrorStatus_t Systick_ConfigureClockSource(u8 Clock_Source);
COM_ErrorStatus_t Systick_SetTimeMS(u32 Time);
void Systick_IsExbired(void); /*Disable Systick*/
void Systick_EnbaleInterrupt(void);
void Systick_DisableInterrupt(void);
COM_ErrorStatus_t Systick_SetCallBack(SystickCBF_t CBF);
void Systick_Handler(void);

COM_ErrorStatus_t Systick_Stop();

COM_ErrorStatus_t SYSTICK_SET_CurrentVal(u32 Current_Val);
COM_ErrorStatus_t SYSTICK_GET_CurrentVal(u32 *Current_Val);

#endif
