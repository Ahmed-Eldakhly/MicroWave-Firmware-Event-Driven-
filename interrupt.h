/*******************************************************************************
 * 
 * File:                interrupt.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes and enums of all interrupts in
 *                      this micro_controller.
 * 
 * Revision history:    19/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef INTERRUPT_H
#define	INTERRUPT_H
 
/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "interrupt_config.h"
#include "stdtypes.h"

/* check if user use one level for interrupts or two levels for interrupts(high-low). */
/* if user select one level for all interrupts this function will be used. */
#if INTERRUPT_LEVELS_NUMBERS == ONE_INTERRUPT_LEVEL

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Global_interrupt_enable
 *
 * Description: 	enable all masked interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Global_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Global_interrupt_disable
 *
 * Description: 	disable all masked interrupts to prevent any interrupt to occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Global_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Peripherals_interrupt_enable
 *
 * Description: 	enable all peripherals interrupts when their flags equal to 1 
 *                  and the global interrupt is enabled.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Peripherals_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Peripherals_interrupt_disable
 *
 * Description: 	disable all peripherals interrupts to prevent any peripherals
 *                  interrupt to occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Peripherals_interrupt_disable(void);

/* if user select two levels for interrupts this function will be used. and priority enumeration */
#elif INTERRUPT_LEVELS_NUMBERS == TWO_INTERRUPT_LEVELS
/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/************************** EnumInterrupt_priority_t ***************************/
typedef enum{
            TIMER0_INTERRUPT_PRIORITY,
            TIMER1_INTERRUPT_PRIORITY,           
            TIMER2_INTERRUPT_PRIORITY,
            TIMER3_INTERRUPT_PRIORITY,
            EXTERNAL_INTERRUPT_1_PRIORITY,
            EXTERNAL_INTERRUPT_2_PRIORITY,  
            PORT_CHANGE_INTERRUPT_PRIORITY,
            USART_RECEIVE_INTERRUPT_PRIORITY,        
            USART_TRANSMIT_INTERRUPT_PRIORITY,
            ADC_INTERRUPT_PRIORITY,
            SPI_MASTER_INTERRUPT_PRIORITY,
            PARALLEL_SLAVE_INTERRUPT_PRIORITY,
            CAPTURE_COMPARE_1_INTERRUPT_PRIORITY,
            CAPTURE_COMPARE_2_INTERRUPT_PRIORITY,
            COMPARETOR_INTERRUPT_PRIORITY,
            OSCILLATOR_FAIL_INTERRUPT_PRIORITY,
            BUS_COLLISION_INTERRUPT_PRIORITY,
            EEPROM_WRITE_INTERRUPT_PRIORITY,
            HIGH_LOW_VOLTAGE_INTERRUPT_PRIORITY            
}EnumInterrupt_priority_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	High_priority_interrupts_enable
 *
 * Description: 	enable all High priority interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void High_priority_interrupts_enable(void);

/*******************************************************************************
 * Function Name:	High_priority_interrupts_disable
 *
 * Description: 	disable all High priority interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void High_priority_interrupts_disable(void);

/*******************************************************************************
 * Function Name:	Low_priority_interrupts_enable
 *
 * Description: 	enable all Low priority interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Low_priority_interrupts_enable(void);

/*******************************************************************************
 * Function Name:	Low_priority_interrupts_disable
 *
 * Description: 	disable all Low priority interrupts when their flags equal to 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Low_priority_interrupts_disable(void);

/*******************************************************************************
 * Function Name:	Interrupt_in_two_levels_enable
 *
 * Description: 	make interrupts classify in two levels of priority.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Interrupt_in_two_levels_enable(void);

/*******************************************************************************
 * Function Name:	Interrupt_in_two_levels_disable
 *
 * Description: 	make all interrupts in the same level.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Interrupt_in_two_levels_disable(void);

/*******************************************************************************
 * Function Name:	Set_interrupts_high_priority
 *
 * Description: 	set the interrupt as high level priority.
 *
 * Inputs:			EnumInterrupt_priority_t (typedef for all interrupt in 
 *                  micro_controller : EnumInterrupt_priority_t) 
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Set_interrupts_high_priority(EnumInterrupt_priority_t a_interrupt_type);

/*******************************************************************************
 * Function Name:	Set_interrupts_low_priority
 *
 * Description: 	set the interrupt as low level priority.
 *
 * Inputs:			EnumInterrupt_priority_t (typedef for all interrupt in 
 *                  micro_controller : EnumInterrupt_priority_t) 
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Set_interrupts_low_priority(EnumInterrupt_priority_t a_interrupt_type);

#endif

/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED

/*******************************************************************************
 * Function Name:	Timer0_enable_overflow_interrupt
 *
 * Description: 	enable timer 0 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_enable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer0_disable_overflow_interrupt
 *
 * Description: 	disable timer 0 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_disable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer0_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if TIMER_1_INTERRUPT == INTERRUPT_USED

/*******************************************************************************
 * Function Name:	Timer1_enable_overflow_interrupt
 *
 * Description: 	enable timer 1 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_enable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer1_disable_overflow_interrupt
 *
 * Description: 	disable timer 1 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_disable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer1_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer1_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if TIMER_2_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Timer2_enable_match_interrupt
 *
 * Description: 	enable timer 2 interrupt when match occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_enable_match_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer2_disable_match_interrupt
 *
 * Description: 	disable timer 2 interrupt when match occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_disable_match_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer2_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer2_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Timer3_enable_overflow_interrupt
 *
 * Description: 	enable timer 3 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer3_enable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer3_disable_overflow_interrupt
 *
 * Description: 	disable timer 3 interrupt when overflow occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer3_disable_overflow_interrupt(void);

/*******************************************************************************
 * Function Name:	Timer3_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer3_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_0_ == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	External_interrupt_0_enable
 *
 * Description: 	enable external interrupt 0 when event occur on pin 0 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_0_enable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_0_disable
 *
 * Description: 	disable external interrupt 0 when event occur on pin 0 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_0_disable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_0_select_rising_edge
 *
 * Description: 	set the rising edge as the reason of external interrupt 0.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_0_select_rising_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_0_select_falling_edge
 *
 * Description: 	set the falling edge as the reason of external interrupt 0.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_0_select_falling_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_0_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_0_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED

/*******************************************************************************
 * Function Name:	External_interrupt_1_enable
 *
 * Description: 	enable external interrupt 1 when event occur on pin 1 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_1_enable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_1_disable
 *
 * Description: 	disable external interrupt 1 when event occur on pin 1 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_1_disable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_1_select_rising_edge
 *
 * Description: 	set the rising edge as the reason of external interrupt 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_1_select_rising_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_1_select_falling_edge
 *
 * Description: 	set the falling edge as the reason of external interrupt 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_1_select_falling_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_1_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_1_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	External_interrupt_2_enable
 *
 * Description: 	enable external interrupt 2 when event occur on pin 2 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_2_enable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_2_disable
 *
 * Description: 	disable external interrupt 2 when event occur on pin 2 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_2_disable(void);

/*******************************************************************************
 * Function Name:	External_interrupt_2_select_rising_edge
 *
 * Description: 	set the rising edge as the reason of external interrupt 2.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_2_select_rising_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_2_select_rising_edge
 *
 * Description: 	set the falling edge as the reason of external interrupt 2.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_2_select_falling_edge(void);

/*******************************************************************************
 * Function Name:	External_interrupt_2_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void External_interrupt_2_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Port_change_interrupt_enable
 *
 * Description: 	enable interrupt when signal change on pin 4,5,6 and 7 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Port_change_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Port_change_interrupt_disable
 *
 * Description: 	disable interrupt when signal change on pin 4,5,6 and 7 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Port_change_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Port_change_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Port_change_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	USART_receive_interrupt_enable
 *
 * Description: 	enable interrupt when USART receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_receive_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	USART_receive_interrupt_disable
 *
 * Description: 	disable interrupt when USART receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_receive_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	USART_receive_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_receive_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	USART_transmit_interrupt_enable
 *
 * Description: 	enable interrupt when USART finish sending data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_transmit_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	USART_transmit_interrupt_disable
 *
 * Description: 	disable interrupt when USART finish sending data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_transmit_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	USART_transmit_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void USART_transmit_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if ADC_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	ADC_converter_interrupt_enable
 *
 * Description: 	enable interrupt when ADC finish conversion.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_converter_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	ADC_converter_interrupt_disable
 *
 * Description: 	disable interrupt when ADC finish conversion.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_converter_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	ADC_converter_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void ADC_converter_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	SPI_master_interrupt_enable
 *
 * Description: 	enable interrupt when SPI master finish send and receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void SPI_master_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	SPI_master_interrupt_disable
 *
 * Description: 	disable interrupt when SPI master finish send and receive data.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void SPI_master_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	SPI_master_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void SPI_master_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Parallel_slave_interrupt_enable
 *
 * Description: 	enable interrupt when Port D in mode parallel slave when 
 *                  micro_controller receive write or read signal.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Parallel_slave_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Parallel_slave_interrupt_disable
 *
 * Description: 	disable interrupt when Port D in mode parallel slave when 
 *                  micro_controller receive write or read signal.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Parallel_slave_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Parallel_slave_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Parallel_slave_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED

/*******************************************************************************
 * Function Name:	Capture_Compare_1_interrupt_enable
 *
 * Description: 	enable interrupt when the micro_controller capture determined
 *                  signal on Pin 2 on Port C.
 *                  enable interrupt when timer 1 or timer 3 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_1_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Capture_Compare_1_interrupt_disable
 *
 * Description: 	disable interrupt when the micro_controller capture determined
 *                  signal on Pin 2 on Port C.
 *                  disable interrupt when timer 1 or timer 3 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_1_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Capture_Compare_1_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_1_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Capture_Compare_2_interrupt_enable
 *
 * Description: 	enable interrupt when the micro_controller capture determined
 *                  signal on Pin 1 on Port C or Pin 3 Port B.
 *                  enable interrupt when timer 1 or timer 3 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_2_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Capture_Compare_2_interrupt_disable
 *
 * Description: 	disable interrupt when the micro_controller capture determined
 *                  signal on Pin 1 on Port C or Pin 3 Port B.
 *                  disable interrupt when timer 1 or timer 3 match the determined.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_2_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Capture_Compare_2_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Capture_Compare_2_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Oscillator_fail_interrupt_enable
 *
 * Description: 	enable interrupt when external oscillator fail or stop its 
 *                  pulses.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Oscillator_fail_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Oscillator_fail_interrupt_disable
 *
 * Description: 	disable interrupt when external oscillator fail or stop its 
 *                  pulses.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Oscillator_fail_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Oscillator_fail_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Oscillator_fail_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Comparator_interrupt_enable
 *
 * Description: 	enable interrupt when comparator input has changed.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Comparator_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Comparator_interrupt_disable
 *
 * Description: 	disable interrupt when comparator input has changed.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Comparator_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Comparator_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Comparator_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	EEPROM_write_interrupt_enable
 *
 * Description: 	enable interrupt when the EEPROM writing operation.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_write_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	EEPROM_write_interrupt_disable
 *
 * Description: 	disable interrupt when the EEPROM writing operation.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_write_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	EEPROM_write_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void EEPROM_write_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	Bus_collision_interrupt_enable
 *
 * Description: 	enable interrupt when Bus collision occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Bus_collision_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	Bus_collision_interrupt_disable
 *
 * Description: 	disable interrupt when Bus collision occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Bus_collision_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	Bus_collision_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Bus_collision_set_callback_function(void(*a_function_ptr)(void));
#endif

/* check if this interrupt will use in program or not */
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED 

/*******************************************************************************
 * Function Name:	High_Low_voltage_interrupt_enable
 *
 * Description: 	enable interrupt when A high/low-voltage condition occurred 
 *                  (direction determined by other bits).
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void High_Low_voltage_interrupt_enable(void);

/*******************************************************************************
 * Function Name:	High_Low_voltage_interrupt_disable
 *
 * Description: 	disable interrupt when A high/low-voltage condition occurred 
 *                  (direction determined by other bits).
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void High_Low_voltage_interrupt_disable(void);

/*******************************************************************************
 * Function Name:	High_Low_voltage_set_callback_function
 *
 * Description: 	set call_back function for interrupt .
 *
 * Inputs:			pointer to function : a_function_ptr.
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void High_Low_voltage_set_callback_function(void(*a_function_ptr)(void));
#endif

#endif	/* INTERRUPT_H */

