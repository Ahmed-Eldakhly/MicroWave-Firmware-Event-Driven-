/****************************************************************************************
 * 
 * File:                interrupt_config.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configuration of interrupts:
 *                          -the interrupt on one or two levels.
 *                          -which interrupts will use to make their functions avaliable.
 * 
 * Revision history:    19/2/2020
 * 
 ****************************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPT_CONFIG_H
#define	INTERRUPT_CONFIG_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define ONE_INTERRUPT_LEVEL                     1u
#define TWO_INTERRUPT_LEVELS                    2u

#define INTERRUPT_USED                          0u
#define INTERRUPT_NON_USED                      1u
/*-------------------------------------------------------------------------------*/
#define INTERRUPT_LEVELS_NUMBERS                ONE_INTERRUPT_LEVEL

#define EXTERNAL_INTERRUPT_0_                   INTERRUPT_NON_USED
#define EXTERNAL_INTERRUPT_1_                   INTERRUPT_NON_USED
#define EXTERNAL_INTERRUPT_2_                   INTERRUPT_NON_USED
#define TIMER_0_INTERRUPT                       INTERRUPT_USED
#define TIMER_1_INTERRUPT                       INTERRUPT_NON_USED
#define TIMER_2_INTERRUPT                       INTERRUPT_NON_USED
#define TIMER_3_INTERRUPT                       INTERRUPT_NON_USED
#define PORT_CHANGE_INTERRUPT                   INTERRUPT_NON_USED
#define USART_RECEIVE_INTERRUPT                 INTERRUPT_NON_USED
#define USART_TRANSMIT_INTERRUPT                INTERRUPT_NON_USED
#define ADC_INTERRUPT                           INTERRUPT_NON_USED
#define SPI_MASTER_INTERRUPT                    INTERRUPT_NON_USED
#define PARALLEL_SLAVE_INTERRUPT                INTERRUPT_NON_USED
#define CAPTURE_COMPARE_1_INTERRUPT             INTERRUPT_NON_USED
#define CAPTURE_COMPARE_2_INTERRUPT             INTERRUPT_NON_USED
#define COMPARETOR_INTERRUPT                    INTERRUPT_NON_USED
#define OSCILLATOR_FAIL_INTERRUPT               INTERRUPT_NON_USED
#define BUS_COLLISION_INTERRUPT                 INTERRUPT_NON_USED
#define EEPROM_WRITE_INTERRUPT                  INTERRUPT_NON_USED
#define HIGH_LOW_VOLTAGE_INTERRUPT              INTERRUPT_NON_USED

#endif	/* INTERRUPT_CONFIG_H */

