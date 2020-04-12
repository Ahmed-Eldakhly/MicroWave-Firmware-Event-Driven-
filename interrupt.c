/*******************************************************************************
 *  
 * File:                interrupt.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains implementation of all interrupts in
 *                      this micro_controller.
 * 
 * Revision history:    19/2/2020
 * 
 ******************************************************************************/
 
/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/           
#include "interrupt.h"
#include "interrupt_MemMap.h"
#include "helped_macros.h"

/*******************************************************************************
 *                      Functions implementation                               *
 *******************************************************************************/

/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED

/* static variable used to call user interrupt function in interrupt handler */
static void (*timer0_callback_ptr)(void) = NULL_PTR;

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
void Timer0_enable_overflow_interrupt(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer0_disable_overflow_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer0_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer0_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if TIMER_1_INTERRUPT == INTERRUPT_USED 
/* static variable used to call user interrupt function in interrupt handler */
static void (*timer1_callback_ptr)(void) = NULL_PTR;

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
void Timer1_enable_overflow_interrupt(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer1_disable_overflow_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER1_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer1_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer1_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if TIMER_2_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*timer2_callback_ptr)(void) = NULL_PTR;

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
void Timer2_enable_match_interrupt(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT);
}

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
void Timer2_disable_match_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_ENABLE_BIT);
}

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
void Timer2_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer2_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*timer3_callback_ptr)(void) = NULL_PTR;

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
void Timer3_enable_overflow_interrupt(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , TIMER3_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer3_disable_overflow_interrupt(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , TIMER3_OVERFLOW_INTERRUPT_ENABLE_BIT);
}

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
void Timer3_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    timer3_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_0_ == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*external_interrupt_0_callback_ptr)(void) = NULL_PTR;

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
void External_interrupt_0_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_ENABLE_BIT);
}

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
void External_interrupt_0_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_ENABLE_BIT);
}

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
void External_interrupt_0_select_rising_edge(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_0_EDGE_SELECT_BIT);
}

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
void External_interrupt_0_select_falling_edge(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_0_EDGE_SELECT_BIT);
}

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
void External_interrupt_0_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    external_interrupt_0_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*external_interrupt_1_callback_ptr)(void) = NULL_PTR;

/*******************************************************************************
 * Function Name:	External_interrupt_1_enable
 *
 * Description: 	enable external interrupt 0 when event occur on pin 1 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_1_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	External_interrupt_1_disable
 *
 * Description: 	disable external interrupt 0 when event occur on pin 1 in portB.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void External_interrupt_1_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_ENABLE_BIT);
}

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
void External_interrupt_1_select_rising_edge(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_1_EDGE_SELECT_BIT);
}

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
void External_interrupt_1_select_falling_edge(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_1_EDGE_SELECT_BIT);
}

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
void External_interrupt_1_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    external_interrupt_1_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED 
/* static variable used to call user interrupt function in interrupt handler */
static void (*external_interrupt_2_callback_ptr)(void) = NULL_PTR;

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
void External_interrupt_2_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_ENABLE_BIT);
}

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
void External_interrupt_2_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_ENABLE_BIT);
}

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
void External_interrupt_2_select_rising_edge(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_2_EDGE_SELECT_BIT);
}

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
void External_interrupt_2_select_falling_edge(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_2 , EXTERNAL_INTERRUPT_2_EDGE_SELECT_BIT);
}

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
void External_interrupt_2_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    external_interrupt_2_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*port_change_interrupt_callback_ptr)(void) = NULL_PTR;

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
void Port_change_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__ENABLE_BIT);
}

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
void Port_change_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__ENABLE_BIT);
}

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
void Port_change_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    port_change_interrupt_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*USART_recieve_callback_ptr)(void) = NULL_PTR;

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
void USART_receive_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_RECEIVE_INTERRUPT_ENABLE_BIT);
}

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
void USART_receive_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_RECEIVE_INTERRUPT_ENABLE_BIT);
}

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
void USART_receive_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    USART_recieve_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*USART_transmit_callback_ptr)(void) = NULL_PTR;

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
void USART_transmit_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_TRANSMIT_INTERRUPT_ENABLE_BIT);
}

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
void USART_transmit_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , USART_TRANSMIT_INTERRUPT_ENABLE_BIT);
}

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
void USART_transmit_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    USART_transmit_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if ADC_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*ADC_converter_callback_ptr)(void) = NULL_PTR;

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
void ADC_converter_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , ADC_CONVERTER_INTERRUPT_ENABLE_BIT);
}

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
void ADC_converter_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , ADC_CONVERTER_INTERRUPT_ENABLE_BIT);
}

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
void ADC_converter_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    ADC_converter_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*spi_master_callback_ptr)(void) = NULL_PTR;

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
void SPI_master_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , SPI_MASTER_INTERRUPT_ENABLE_BIT);
}

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
void SPI_master_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , SPI_MASTER_INTERRUPT_ENABLE_BIT);
}

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
void SPI_master_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    spi_master_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*parallel_slave_callback_ptr)(void) = NULL_PTR;

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
void Parallel_slave_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT);
}

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
void Parallel_slave_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , PARALLEL_SLAVE_INTERRUPT_ENABLE_BIT);
}

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
void Parallel_slave_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    parallel_slave_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*capture_compare_1_callback_ptr)(void) = NULL_PTR;

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
void Capture_Compare_1_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT);
}

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
void Capture_Compare_1_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_ENABLE_BIT);
}

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
void Capture_Compare_1_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    capture_compare_1_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*capture_compare_2_callback_ptr)(void) = NULL_PTR;

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
void Capture_Compare_2_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT);
}

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
void Capture_Compare_2_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_ENABLE_BIT);
}

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
void Capture_Compare_2_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    capture_compare_2_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*oscillator_fail_callback_ptr)(void) = NULL_PTR;

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
void Oscillator_fail_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , OSCILLATOR_FAIL_INTERRUPT_ENABLE_BIT);
}

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
void Oscillator_fail_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , OSCILLATOR_FAIL_INTERRUPT_ENABLE_BIT);
}

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
void Oscillator_fail_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    oscillator_fail_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED 
/* static variable used to call user interrupt function in interrupt handler */
static void (*comarator_callback_ptr)(void) = NULL_PTR;

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
void Comparator_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , COMPARATOR_INTERRUPT_ENABLE_BIT);
}

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
void Comparator_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , COMPARATOR_INTERRUPT_ENABLE_BIT);
}

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
void Comparator_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    comarator_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*EEPROM_write_callback_ptr)(void) = NULL_PTR;

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
void EEPROM_write_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , EEPROM_WRITE_INTERRUPT_ENABLE_BIT);
}

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
void EEPROM_write_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , EEPROM_WRITE_INTERRUPT_ENABLE_BIT);
}

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
void EEPROM_write_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    EEPROM_write_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*bus_collision_callback_ptr)(void) = NULL_PTR;

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
void Bus_collision_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , BUS_COLLISION_INTERRUPT_ENABLE_BIT);
}

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
void Bus_collision_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , BUS_COLLISION_INTERRUPT_ENABLE_BIT);
}

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
void Bus_collision_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    bus_collision_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt will use in program or not */
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED 

/* static variable used to call user interrupt function in interrupt handler */
static void (*high_low_voltage_callback_ptr)(void) = NULL_PTR;

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
void High_Low_voltage_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , H_L_VOLTAGE_DETECT_INTERRUPT_ENABLE_BIT);
}

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
void High_Low_voltage_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_PERIPHERAL_ENABLE_2 , H_L_VOLTAGE_DETECT_INTERRUPT_ENABLE_BIT);
}

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
void High_Low_voltage_set_callback_function(void(*a_function_ptr)(void))
{
    /* sign the executed function when the interrupt occur with the function of the user */
    high_low_voltage_callback_ptr = a_function_ptr;
}
#endif

/* check if this interrupt occur in one level for priority or in two levels */
#if INTERRUPT_LEVELS_NUMBERS == ONE_INTERRUPT_LEVEL

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
void Global_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	Global_interrupt_disable
 *
 * Description: 	disable all masked interrupts to prevent any interrupt to 
 *                  occur.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Global_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void Peripherals_interrupt_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void Peripherals_interrupt_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ISR
 *
 * Description: 	interrupt handler function in this function all interrupt 
 *                  functions will execute when the interrupt flag, global interrupt
 *                  and the peripherals interrupt in some cases are equal 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void __interrupt () ISR(void)
{
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer3_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer3_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_0_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(port_change_interrupt_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            port_change_interrupt_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_RECEIVE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_recieve_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_recieve_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_TRANSMIT_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_transmit_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_transmit_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if ADC_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(ADC_converter_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            ADC_converter_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
    
/* check if this interrupt will use in program or not */   
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(spi_master_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            spi_master_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(parallel_slave_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            parallel_slave_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
 
/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(oscillator_fail_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            oscillator_fail_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(comarator_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            comarator_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(EEPROM_write_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            EEPROM_write_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
 
/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(bus_collision_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            bus_collision_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif
 
/* check if this interrupt will use in program or not */
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(high_low_voltage_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            high_low_voltage_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /*CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT);*/
    }
    else
    {
        /*Do nothing*/
    }
#endif
}
#elif INTERRUPT_LEVELS_NUMBERS == TWO_INTERRUPT_LEVELS

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
void High_priority_interrupts_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void High_priority_interrupts_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , GLOBAL__HIGH_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void Low_priority_interrupts_enable(void)
{
    SET_BIT(INTERRUPT_CONTROL_REG_1 , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void Low_priority_interrupts_disable(void)
{
    CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PERIPHERAL__LOW_PRIORTY__INTERRUPT_ENABLE_BIT);
}

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
void Interrupt_in_two_levels_enable(void)
{
    SET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT);
}

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
void Interrupt_in_two_levels_disable(void)
{
    CLEAR_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT);
}

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
void Set_interrupts_high_priority(EnumInterrupt_priority_t a_interrupt_type)
{
    /* check on the selected interrupt */
    switch(a_interrupt_type)
    {
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
        case TIMER0_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_CONTROL_REG_2 , TIMER0_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
 /* check if this interrupt will use in program or not */   
#if TIMER_1_INTERRUPT == INTERRUPT_USED 
        case TIMER1_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER1_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
 /* check if this interrupt will use in program or not */
#if TIMER_2_INTERRUPT == INTERRUPT_USED
        case TIMER2_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
 /* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED 
        case TIMER3_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , TIMER3_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
 
/* check if this interrupt will use in program or not */            
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED 
        case EXTERNAL_INTERRUPT_1_PRIORITY:
            SET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_PRIORITY_BIT);
            break;
#endif

 /* check if this interrupt will use in program or not */           
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED
        case EXTERNAL_INTERRUPT_2_PRIORITY:
            SET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_PRIORITY_BIT);
            break;
#endif
            
 /* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED 
        case PORT_CHANGE_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_CONTROL_REG_2 , PORTB_CHANGE_INTERRUPT__PRIORITY_BIT);
            break;
#endif
            
 /* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
        case USART_RECEIVE_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_RECEIVE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED 
        case USART_TRANSMIT_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_TRANSMIT_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if ADC_INTERRUPT == INTERRUPT_USED 
        case ADC_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , ADC_CONVERTER_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED 
        case SPI_MASTER_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , SPI_MASTER_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED 
        case PARALLEL_SLAVE_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , PARALLEL_SLAVE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED 
        case CAPTURE_COMPARE_1_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED 
        case CAPTURE_COMPARE_2_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED 
        case OSCILLATOR_FAIL_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , OSCILLATOR_FAIL_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED 
        case COMPARETOR_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , COMPARATOR_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED 
        case EEPROM_WRITE_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , EEPROM_WRITE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED 
        case BUS_COLLISION_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , BUS_COLLISION_INTERRUPT_PRIORITY_BIT);
            break;
#endif
 
/* check if this interrupt will use in program or not */
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED 
        case HIGH_LOW_VOLTAGE_INTERRUPT_PRIORITY:
            SET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , H_L_VOLTAGE_DETECT_INTERRUPT_PRIORITY_BIT);
            break;
#endif
    }
}

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
void Set_interrupts_low_priority(EnumInterrupt_priority_t a_interrupt_type)
{
    /* check on the selected interrupt */
    switch(a_interrupt_type)
    {
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
        case TIMER0_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_CONTROL_REG_2 , TIMER0_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */    
#if TIMER_1_INTERRUPT == INTERRUPT_USED 
        case TIMER1_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER1_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if TIMER_2_INTERRUPT == INTERRUPT_USED
        case TIMER2_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if TIMER_3_INTERRUPT == INTERRUPT_USED 
        case TIMER3_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , TIMER3_OVERFLOW_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED 
        case EXTERNAL_INTERRUPT_1_PRIORITY:
            CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED
        case EXTERNAL_INTERRUPT_2_PRIORITY:
            CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED 
        case PORT_CHANGE_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_CONTROL_REG_2 , PORTB_CHANGE_INTERRUPT__PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
        case USART_RECEIVE_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_RECEIVE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED 
        case USART_TRANSMIT_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_TRANSMIT_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if ADC_INTERRUPT == INTERRUPT_USED 
        case ADC_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , ADC_CONVERTER_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED 
        case SPI_MASTER_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , SPI_MASTER_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED 
        case PARALLEL_SLAVE_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , PARALLEL_SLAVE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED 
        case CAPTURE_COMPARE_1_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED 
        case CAPTURE_COMPARE_2_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED 
        case OSCILLATOR_FAIL_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , OSCILLATOR_FAIL_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if COMPARETOR_INTERRUPT == INTERRUPT_USED 
        case COMPARETOR_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , COMPARATOR_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED 
        case EEPROM_WRITE_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , EEPROM_WRITE_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED 
        case BUS_COLLISION_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , BUS_COLLISION_INTERRUPT_PRIORITY_BIT);
            break;
#endif
            
/* check if this interrupt will use in program or not */ 
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED 
        case HIGH_LOW_VOLTAGE_INTERRUPT_PRIORITY:
            CLEAR_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , H_L_VOLTAGE_DETECT_INTERRUPT_PRIORITY_BIT);
            break;
#endif
    }
}

/*******************************************************************************
 * Function Name:	(high priority) ISR
 *
 * Description: 	high priority interrupt handler function in this function all 
 *                  high priority interrupt functions will execute when the 
 *                  interrupt flag and high interrupts are equal 1..
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void __interrupt (high_priority) ISR(void)
{
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_CONTROL_REG_2 , TIMER0_OVERFLOW_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER1_OVERFLOW_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if TIMER_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT)
        && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , TIMER3_OVERFLOW_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer3_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer3_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_0_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       this interrupt can't be in Low level priority. */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_FLAG_BIT))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , EXTERNAL_INTERRUPT_0_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT)
            && (GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT)
            && (GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT)
            && (GET_BIT(INTERRUPT_CONTROL_REG_2 , PORTB_CHANGE_INTERRUPT__PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(port_change_interrupt_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            port_change_interrupt_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_RECEIVE_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_RECEIVE_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_recieve_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_recieve_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_TRANSMIT_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_TRANSMIT_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_transmit_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_transmit_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if ADC_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , ADC_CONVERTER_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(ADC_converter_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            ADC_converter_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , SPI_MASTER_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(spi_master_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            spi_master_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , PARALLEL_SLAVE_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(parallel_slave_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            parallel_slave_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , OSCILLATOR_FAIL_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(oscillator_fail_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            oscillator_fail_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if COMPARETOR_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , COMPARATOR_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(comarator_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            comarator_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , EEPROM_WRITE_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(EEPROM_write_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            EEPROM_write_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , BUS_COLLISION_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(bus_collision_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            bus_collision_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in high level priority.
       and the two levels priority feature enabled because if it is disabled, all interrupts
     * will be in one level(high level) */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , H_L_VOLTAGE_DETECT_INTERRUPT_PRIORITY_BIT)
             || (!GET_BIT(RESET_CONTROL_REG1 , INTERRUPT_PRIORITY_ENABLE_BIT))))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(high_low_voltage_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            high_low_voltage_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /*CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT);*/
    }
    else
    {
        /*Do nothing*/
    }
#endif
}

/*******************************************************************************
 * Function Name:	(low priority) ISR
 *
 * Description: 	low priority interrupt handler function in this function all 
 *                  low priority interrupt functions will execute when the 
 *                  interrupt flag and low interrupts are equal 1.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void __interrupt (low_priority)   ISRL(void)
{
/* check if this interrupt will use in program or not */
#if TIMER_0_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_CONTROL_REG_2 , TIMER0_OVERFLOW_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer0_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer0_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , TIMER0_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if TIMER_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER1_OVERFLOW_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER1_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if TIMER_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT)
        && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , TIMER2_TO_PR2_MATCH_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if TIMER_3_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , TIMER3_OVERFLOW_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(timer3_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            timer3_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , TIMER3_OVERFLOW_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if EXTERNAL_INTERRUPT_1_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_1_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if EXTERNAL_INTERRUPT_2_ == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(external_interrupt_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            external_interrupt_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_3 , EXTERNAL_INTERRUPT_2_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */
#if PORT_CHANGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT)
            && (!GET_BIT(INTERRUPT_CONTROL_REG_2 , PORTB_CHANGE_INTERRUPT__PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(port_change_interrupt_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            port_change_interrupt_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_CONTROL_REG_1 , PORTB_CHANGE_INTERRUPT__FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if USART_RECEIVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_RECEIVE_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_RECEIVE_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_recieve_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_recieve_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if USART_TRANSMIT_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , USART_TRANSMIT_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , USART_TRANSMIT_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(USART_transmit_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            USART_transmit_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if ADC_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , ADC_CONVERTER_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(ADC_converter_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            ADC_converter_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , ADC_CONVERTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if SPI_MASTER_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , SPI_MASTER_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(spi_master_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            spi_master_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , SPI_MASTER_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if PARALLEL_SLAVE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , PARALLEL_SLAVE_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(parallel_slave_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            parallel_slave_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , PARALLEL_SLAVE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_1_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_1_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_1_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_1 , CAPTURE_COMPARE_PWM_1_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if CAPTURE_COMPARE_2_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(capture_compare_2_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            capture_compare_2_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , CAPTURE_COMPARE_PWM_2_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if OSCILLATOR_FAIL_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , OSCILLATOR_FAIL_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(oscillator_fail_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            oscillator_fail_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , OSCILLATOR_FAIL_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if COMPARETOR_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , COMPARATOR_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(comarator_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            comarator_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , COMPARATOR_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if EEPROM_WRITE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , EEPROM_WRITE_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(EEPROM_write_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            EEPROM_write_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , EEPROM_WRITE_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if BUS_COLLISION_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT)
            && (!GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , BUS_COLLISION_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(bus_collision_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            bus_collision_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /* clear interrupt flag to finish interrupt execution till a new interrupt */
        CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , BUS_COLLISION_INTERRUPT_FLAG_BIT);
    }
    else
    {
        /*Do nothing*/
    }
#endif

/* check if this interrupt will use in program or not */    
#if HIGH_LOW_VOLTAGE_INTERRUPT == INTERRUPT_USED
    /* check if this interrupt happened and flag is set or not. 
       and if the interrupt in low level priority. */
    if(!GET_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT)
            && (GET_BIT(INTERRUPT_PERIPHERAL_PRIORITY_2 , H_L_VOLTAGE_DETECT_INTERRUPT_PRIORITY_BIT)))
    {
        /* check if the user set interrupt function by call_back function or not */
        if(high_low_voltage_callback_ptr != NULL_PTR)
        {
            /* call the user interrupt function*/
            high_low_voltage_callback_ptr();
        }
        else
        {
            /*Do nothing*/
        }
        /*CLEAR_BIT(INTERRUPT_PERIPHERAL_FLAGS_2 , H_L_VOLTAGE_DETECT_INTERRUPT_FLAG_BIT);*/
    }
    else
    {
        /*Do nothing*/
    }
#endif
}
#endif