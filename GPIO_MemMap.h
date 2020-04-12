/*******************************************************************************
 * 
 * File:                GPIO_MemMap.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains memory mapping for GPIO registers in 
 *                      micro1-controller.
 * 
 * Revision history:    12/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */
#ifndef GPIO_MEM_MAP_H
#define	GPIO_MEM_MAP_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define GPIO_DIRECTION_PORTA                    *(volatile uint8*)0xF92
#define GPIO_DIRECTION_PORTB                    *(volatile uint8*)0xF93
#define GPIO_DIRECTION_PORTC                    *(volatile uint8*)0xF94
#define GPIO_DIRECTION_PORTD                    *(volatile uint8*)0xF95
#define GPIO_DIRECTION_PORTE                    *(volatile uint8*)0xF96

#define GPIO_READ_VALUE_PORTA                   *(volatile uint8*)0xF80
#define GPIO_READ_VALUE_PORTB                   *(volatile uint8*)0xF81
#define GPIO_READ_VALUE_PORTC                   *(volatile uint8*)0xF82
#define GPIO_READ_VALUE_PORTD                   *(volatile uint8*)0xF83
#define GPIO_READ_VALUE_PORTE                   *(volatile uint8*)0xF84

#define GPIO_WRITE_VALUE_PORTA                  *(volatile uint8*)0xF89
#define GPIO_WRITE_VALUE_PORTB                  *(volatile uint8*)0xF8A
#define GPIO_WRITE_VALUE_PORTC                  *(volatile uint8*)0xF8B
#define GPIO_WRITE_VALUE_PORTD                  *(volatile uint8*)0xF8C
#define GPIO_WRITE_VALUE_PORTE                  *(volatile uint8*)0xF8D

#define ADC_CONTROL_REGISTER_1                  *(volatile uint8*)0xFC1
#define COMPARATOR_CONTROL_REGISTER             *(volatile uint8*)0xFB4
#define INTERRUPT_CONTROL_REGISTER              *(volatile uint8*)0xFF1
#define ENABLE_PULL_UP_RESISTOR_ON_PORTB_BIT    7u

#endif	/* GPIO_MEM_MAP_H */

