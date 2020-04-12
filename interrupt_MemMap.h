/*******************************************************************************
 *  
 * File:                interrupt_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping of interrupt registers in 
 *                      micro1-controller.
 * 
 * Revision history:    19/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPT_MEM_MAP_H
#define	INTERRUPT_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define INTERRUPT_CONTROL_REG_1                         *(volatile uint8*)0xFF2
#define GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT      7u  
#define PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT   6u  
#define TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT            5u  
#define EXTERNAL_INTERRUPT_0_ENABLE_BIT                 4u  
#define PORTB_CHANGE_INTERRUPT__ENABLE_BIT              3u  
#define TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT              2u  
#define EXTERNAL_INTERRUPT_0_FLAG_BIT                   1u  
#define PORTB_CHANGE_INTERRUPT__FLAG_BIT                0u  

#define INTERRUPT_CONTROL_REG_2                         *(volatile uint8*)0xFF1
#define EXTERNAL_INTERRUPT_0_EDGE_SELECT_BIT            6u  
#define EXTERNAL_INTERRUPT_1_EDGE_SELECT_BIT            5u  
#define EXTERNAL_INTERRUPT_2_EDGE_SELECT_BIT            4u  
#define TIMER0_OVERFLOW_INTERRUPT_PRIORITY_BIT          2u  
#define PORTB_CHANGE_INTERRUPT__PRIORITY_BIT            0u  

#define INTERRUPT_CONTROL_REG_3                          *(volatile uint8*)0xFF0
#define EXTERNAL_INTERRUPT_2_PRIORITY_BIT               7u  
#define EXTERNAL_INTERRUPT_1_PRIORITY_BIT               6u  
#define EXTERNAL_INTERRUPT_2_ENABLE_BIT                 4u  
#define EXTERNAL_INTERRUPT_1_ENABLE_BIT                 3u  
#define EXTERNAL_INTERRUPT_2_FLAG_BIT                   1u  
#define EXTERNAL_INTERRUPT_1_FLAG_BIT                   0u  

#define RESET_CONTROL_REG1                              *(volatile uint8*)0xFD0
#define INTERRUPT_PRIORITY_ENABLE_BIT                   7u  
#define SOFTWARE_BOR_ENABLE_BIT                         6u   
#define RESET_INSTRUCTION_FLAG_BIT                      4u  
#define WATCH_DOG_TIME_OUT_FLAG_BIT                     3u  
#define POWER_DOWN_DETECTION_FLAG_BIT                   2u  
#define POWER_ON_RESET_STATUS_BIT                       1u  
#define BROWN_OUT_RESET_STATUS_BIT                      0u 

#define INTERRUPT_PERIPHERAL_ENABLE_1                   *(volatile uint8*)0xF9D
#define PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT             7u  
#define ADC_CONVERTER_INTERRUPT_ENABLE_BIT              6u  
#define USART_RECEIVE_INTERRUPT_ENABLE_BIT              5u  
#define USART_TRANSMIT_INTERRUPT_ENABLE_BIT             4u  
#define SPI_MASTER_INTERRUPT_ENABLE_BIT                 3u  
#define CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT      2u  
#define TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT        1u  
#define TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT            0u  

#define INTERRUPT_PERIPHERAL_ENABLE_2                   *(volatile uint8*)0xFA0
#define OSCILLATOR_FAIL_INTERRUPT_ENABLE_BIT            7u  
#define COMPARATOR_INTERRUPT_ENABLE_BIT                 6u   
#define EEPROM_WRITE_INTERRUPT_ENABLE_BIT               4u  
#define BUS_COLLISION_INTERRUPT_ENABLE_BIT              3u  
#define H_L_VOLTAGE_DETECT_INTERRUPT_ENABLE_BIT         2u  
#define TIMER3_OVERFLOW_INTERRUPT_ENABLE_BIT            1u  
#define CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT      0u  

#define INTERRUPT_PERIPHERAL_FLAGS_1                    *(volatile uint8*)0xF9E
#define PARALLEL_SLAVE_INTERRUPT_FLAG_BIT               7u  
#define ADC_CONVERTER_INTERRUPT_FLAG_BIT                6u  
#define USART_RECEIVE_INTERRUPT_FLAG_BIT                5u  
#define USART_TRANSMIT_INTERRUPT_FLAG_BIT               4u  
#define SPI_MASTER_INTERRUPT_FLAG_BIT                   3u  
#define CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT        2u  
#define TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT          1u  
#define TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT              0u  

#define INTERRUPT_PERIPHERAL_FLAGS_2                    *(volatile uint8*)0xFA1
#define OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT              7u  
#define COMPARATOR_INTERRUPT_FLAG_BIT                   6u 
#define EEPROM_WRITE_INTERRUPT_FLAG_BIT                 4u  
#define BUS_COLLISION_INTERRUPT_FLAG_BIT                3u  
#define H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT           2u  
#define TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT              1u  
#define CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT        0u   

#define INTERRUPT_PERIPHERAL_PRIORITY_1                 *(volatile uint8*)0xF9F
#define PARALLEL_SLAVE_INTERRUPT_PRIORITY_BIT           7u  
#define ADC_CONVERTER_INTERRUPT_PRIORITY_BIT            6u  
#define USART_RECEIVE_INTERRUPT_PRIORITY_BIT            5u  
#define USART_TRANSMIT_INTERRUPT_PRIORITY_BIT           4u  
#define SPI_MASTER_INTERRUPT_PRIORITY_BIT               3u  
#define CAPTURE_COMPARE_PWM_1_INTERRUPT_PRIORITY_BIT    2u  
#define TIMER2_TO_PR2_MATCH_INTERRUPT_PRIORITY_BIT      1u  
#define TIMER1_OVERFLOW_INTERRUPT_PRIORITY_BIT          0u 

#define INTERRUPT_PERIPHERAL_PRIORITY_2                 *(volatile uint8*)0xFA2
#define OSCILLATOR_FAIL_INTERRUPT_PRIORITY_BIT          7u  
#define COMPARATOR_INTERRUPT_PRIORITY_BIT               6u   
#define EEPROM_WRITE_INTERRUPT_PRIORITY_BIT             4u  
#define BUS_COLLISION_INTERRUPT_PRIORITY_BIT            3u  
#define H_L_VOLTAGE_DETECT_INTERRUPT_PRIORITY_BIT       2u  
#define TIMER3_OVERFLOW_INTERRUPT_PRIORITY_BIT          1u  
#define CAPTURE_COMPARE_PWM_2_INTERRUPT_PRIORITY_BIT    0u  


#endif	/* INTERRUPT_MEM_MAP_H */

