/*******************************************************************************
 *  
 * File:                PWM_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping for PWM peripheral.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_MEM_MAP_H
#define	PWM_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define CAPTURE_COMPARE_PWM_1_HIGH_REG              *(volatile uint8*)0xFBF
#define CAPTURE_COMPARE_PWM_1_LOW_REG               *(volatile uint8*)0xFBE
#define CAPTURE_COMPARE_PWM_1_CONTROL_REG           *(volatile uint8*)0xFBD
#define PWM_1_SELECT_MODE_BIT_1                     7u
#define PWM_1_SELECT_MODE_BIT_2                     6u
#define PWM_1_DUTY_CYCLE_BIT_1                      5u
#define PWM_1_DUTY_CYCLE_BIT_0                      4u
#define CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_3     3u
#define CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_2     2u
#define CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_1     1u
#define CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_0     0u

#define CAPTURE_COMPARE_PWM_2_HIGH_REG              *(volatile uint8*)0xFBC
#define CAPTURE_COMPARE_PWM_2_LOW_REG               *(volatile uint8*)0xFBB
#define CAPTURE_COMPARE_PWM_2_CONTROL_REG           *(volatile uint8*)0xFBA
#define PWM_2_SELECT_MODE_BIT_1                     7u
#define PWM_2_SELECT_MODE_BIT_2                     6u
#define PWM_2_DUTY_CYCLE_BIT_1                      5u
#define PWM_2_DUTY_CYCLE_BIT_0                      4u
#define CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_3     3u
#define CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_2     2u
#define CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_1     1u
#define CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_0     0u

#define PWM_1_PIN_DIRECTION_REG                     *(volatile uint8*)0xF94
#define PWM_2_PIN_DIRECTION_REG                     *(volatile uint8*)0xF93
#define PWM_1_PIN_VALUE_REG                         *(volatile uint8*)0xF8B
#define PWM_2_PIN_VALUE_REG                         *(volatile uint8*)0xF8A

#endif	/* PWM_MEM_MAP_H */

