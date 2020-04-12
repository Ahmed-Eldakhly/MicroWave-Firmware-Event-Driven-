/******************************************************************************* 
 * File:                timers_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping for all timers registers in
 *                      micro1-controller.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TIMERS_MEM_MAP_H
#define	TIMERS_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define TIMER_0_HIGH_REG                            *(volatile uint8*)0xFD7
#define TIMER_0_LOW_REG                             *(volatile uint8*)0xFD6
#define TIMER_0_CONTROL_REG                         *(volatile uint8*)0xFD5
#define TIMER_0_ON_OFF_BIT                          7u
#define TIMER_0_8BIT_16BIT_SELECT                   6u
#define TIMER_0_CLOCK_SOURCE_SELECT                 5u
#define TIMER_0_SOURCE_EDGE_SELECT                  4u
#define TIMER_0_PRESCALER_ENABLE_BIT                3u
#define TIMER_0_PRESCALER_SELECT_BIT_2              2u
#define TIMER_0_PRESCALER_SELECT_BIT_1              1u
#define TIMER_0_PRESCALER_SELECT_BIT_0              0u

#define TIMER_1_HIGH_REG                            *(volatile uint8*)0xFCF
#define TIMER_1_LOW_REG                             *(volatile uint8*)0xFCE
#define TIMER_1_CONTROL_REG                         *(volatile uint8*)0xFCD
#define TIMER_1_8BIT_16BIT_SELECT                   7u
#define TIMER_1_SYSTEM_CLOCK_STATUS                 6u
#define TIMER_1_PRESCALER_SELECT_BIT_1              5u
#define TIMER_1_PRESCALER_SELECT_BIT_0              4u
#define TIMER_1_OSCILLATOR_ENABLE_BIT               3u
#define TIMER_1_EXTERNAL_CLOCK_SYNC_BIT_ACTIVE_LOW  2u
#define TIMER_1_CLOCK_SOURCE_SELECT                 1u
#define TIMER_1_ON_OFF_BIT                          0u

#define TIMER_2_REG                                 *(volatile uint8*)0xFCC
#define TIMER_2_PERIOD_REG                          *(volatile uint8*)0xFCB
#define TIMER_2_CONTROL_REG                         *(volatile uint8*)0xFCA
#define TIMER_2_POSTSCALER_SELECT_BIT_3             6u
#define TIMER_2_POSTSCALER_SELECT_BIT_2             5u
#define TIMER_2_POSTSCALER_SELECT_BIT_1             4u
#define TIMER_2_POSTSCALER_SELECT_BIT_0             3u
#define TIMER_2_ON_OFF_BIT                          2u
#define TIMER_2_PRESCALER_SELECT_BIT_1              1u
#define TIMER_2_PRESCALER_SELECT_BIT_0              0u

#define TIMER_3_HIGH_REG                            *(volatile uint8*)0xFB3
#define TIMER_3_LOW_REG                             *(volatile uint8*)0xFB2
#define TIMER_3_CONTROL_REG                         *(volatile uint8*)0xFB1
#define TIMER_3_8BIT_16BIT_SELECT                   7u
#define TIMER_3_TIMER_1_CCP_ENABLE_BIT_2            6u
#define TIMER_3_PRESCALER_SELECT_BIT_1              5u
#define TIMER_3_PRESCALER_SELECT_BIT_0              4u
#define TIMER_3_TIMER_1_CCP_ENABLE_BIT_1            3u
#define TIMER_3_EXTERNAL_CLOCK_SYNC_BIT_ACTIVE_LOW  2u
#define TIMER_3_CLOCK_SOURCE_SELECT                 1u
#define TIMER_3_ON_OFF_BIT                          0u

#endif	/* TIMERS_MEM_MAP_H */

