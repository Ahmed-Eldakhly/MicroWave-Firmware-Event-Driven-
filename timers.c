/*******************************************************************************
 *  
 * File:                timers.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of all timers
 *                      peripherals.
 * 
 * Revision history:    25/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "timers.h"
#include "timers_MemMap.h"
#include "helped_macros.h"

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/
/* check if timer 0 will used */
#if TIMER0 == TIMER_ENABLE

/********************************************************************************
 * Function Name:	Timer0_Initialization
 *
 * Description: 	Initialize timer 0 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_Initialization(void)
{   /* select the timer counter will be 8 bits or 16 bits */
    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        SET_BIT(TIMER_0_CONTROL_REG , TIMER_0_8BIT_16BIT_SELECT);
    }
    else
    {
        CLEAR_BIT(TIMER_0_CONTROL_REG , TIMER_0_8BIT_16BIT_SELECT);
    }
    /* select the timer clock source will be internal from micro_controller or input to T0CKI pin */
    if(Timer0_config_t.timer_clock_source_t == TIMER_INTERNAL_CLOCK)
    {
        CLEAR_BIT(TIMER_0_CONTROL_REG , TIMER_0_CLOCK_SOURCE_SELECT);
    }
    else
    {
        SET_BIT(TIMER_0_CONTROL_REG , TIMER_0_CLOCK_SOURCE_SELECT);
    }
    /* select the edge of new count of timer when the timer clock is input pulses on T0CKI */
    if(Timer0_config_t.timer_clock_source_t != TIMER_INTERNAL_CLOCK)
    {
        TIMER_0_CONTROL_REG &= 0xEF;
        TIMER_0_CONTROL_REG |= Timer0_config_t.timer_edge_type_on_TCKI_t << 4;
    }
    else
    {
        /*Do nothing*/;
    }
    /* select timer pre scaler */
    if(Timer0_config_t.timer_prescaler_t != TIMER0_NO_PRESCALER)
    {
        TIMER_0_CONTROL_REG &= 0xF0;
        TIMER_0_CONTROL_REG |= Timer0_config_t.timer_prescaler_t;
    }
    else
    {
        TIMER_0_CONTROL_REG |= 0x08;
    }
}

/********************************************************************************
 * Function Name:	Timer0_enable
 *
 * Description: 	enable timer 0 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_enable(void)
{
    SET_BIT(TIMER_0_CONTROL_REG , TIMER_0_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer0_disable
 *
 * Description: 	disable timer 0 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_disable(void)
{
    CLEAR_BIT(TIMER_0_CONTROL_REG , TIMER_0_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer0_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 0. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16       number of counts
 *******************************************************************************/
uint16 Timer0_read_counter(void)
{
    uint16 retVal;
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        retVal = TIMER_0_LOW_REG;
    }
    else
    {
        retVal = TIMER_0_LOW_REG;
        retVal |= ((uint16)TIMER_0_HIGH_REG) << 8;
    }
    return retVal;
}

/********************************************************************************
 * Function Name:	Timer0_write_counter
 *
 * Description: 	write user value in timer 0 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint16       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer0_write_counter(uint16 a_u16init_value_for_timer)
{
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        TIMER_0_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
    else
    {
        TIMER_0_HIGH_REG = a_u16init_value_for_timer >> 8;
        TIMER_0_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
}
#endif

/* check if timer 1 will used */
#if TIMER1 == TIMER_ENABLE

/********************************************************************************
 * Function Name:	Timer1_Initialization
 *
 * Description: 	Initialize timer 1 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_Initialization(void)
{
    /* select the timer counter will be 8 bits or 16 bits */
    if(Timer1_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_8BIT_16BIT_SELECT);
    }
    else
    {
        CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_8BIT_16BIT_SELECT);
    }
    /* select the timer clock source will be internal from micro_controller or input to T13CKI pin */
    if(Timer1_config_t.timer_clock_source_t == TIMER_INTERNAL_CLOCK)
    {
        CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_CLOCK_SOURCE_SELECT);
    }
    else
    {
        SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_CLOCK_SOURCE_SELECT);
    }
    /* choose if the clock will Synchronize or not when the timer clock is input pulses on T13CKI */
    if(Timer1_config_t.timer_clock_source_t != TIMER_INTERNAL_CLOCK)
    {
        TIMER_1_CONTROL_REG &= 0xFB;
        TIMER_1_CONTROL_REG |= Timer1_config_t.timer_sync_with_external_clock << 2;
    }
    else
    {
        /*Do nothing*/;
    }
    /* select timer pre scaler */
    switch(Timer1_config_t.timer_prescaler_t)
    {
        case TIMER1_NO_PRESCALER:
            CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_1);
            CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER1_PRESCALER_2:
            CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_1);
            SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER1_PRESCALER_4:
            SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_1);
            CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER1_PRESCALER_8:
            SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_1);
            SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_PRESCALER_SELECT_BIT_0);
            break;
        default:
            /*Do nothing*/
            break;
    }
}

/********************************************************************************
 * Function Name:	Timer1_enable
 *
 * Description: 	enable timer 1 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_enable(void)
{
    SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer1_disable
 *
 * Description: 	disable timer 1 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_disable(void)
{
    CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer1_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 1. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16       number of counts
 *******************************************************************************/
uint16 Timer1_read_counter(void)
{
    uint16 retVal;
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer1_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        retVal = TIMER_1_LOW_REG;
    }
    else
    {
        retVal = TIMER_1_LOW_REG;
        retVal |= ((uint16)TIMER_1_HIGH_REG) << 8;
    }
    return retVal;
}

/********************************************************************************
 * Function Name:	Timer1_write_counter
 *
 * Description: 	write user value in timer 1 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint16       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_write_counter(uint16 a_u16init_value_for_timer)
{
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer1_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        TIMER_1_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
    else
    {
        TIMER_1_HIGH_REG = a_u16init_value_for_timer >> 8;
        TIMER_1_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
}

/********************************************************************************
 * Function Name:	Timer1_used_for_both_CCP_modules
 *
 * Description: 	use timer 1 with capture or compare module for the two avaliable
 *                  modules in this micro_controller. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_used_for_both_CCP_modules(void)
{
    CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_2);
    SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_1);
}

/********************************************************************************
 * Function Name:	Timer1_used_for_CCP1_module
 *
 * Description: 	use timer 1 with capture or compare module number 1 only. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_used_for_CCP1_module(void)
{
    CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_2);
    CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_1);
}

/********************************************************************************
 * Function Name:	Timer1_oscillator_enable
 *
 * Description: 	enable timer 1 oscillator to use. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_oscillator_enable(void)
{
    SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_OSCILLATOR_ENABLE_BIT);
}

/********************************************************************************
 * Function Name:	Timer1_oscillator_disable
 *
 * Description: 	disable timer 1 oscillator. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer1_oscillator_disable(void)
{
    CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_OSCILLATOR_ENABLE_BIT);
}

/********************************************************************************
 * Function Name:	DeviceUse_Timer1_oscillator_enable
 *
 * Description: 	the micro_controller clock is derived from Timer1 oscillator. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void DeviceUse_Timer1_oscillator_enable(void)
{
    SET_BIT(TIMER_1_CONTROL_REG , TIMER_1_SYSTEM_CLOCK_STATUS);
}

/********************************************************************************
 * Function Name:	DeviceNotUse_Timer1_oscillator_disable
 *
 * Description: 	the micro_controller clock is not derived from Timer1 oscillator
 *                  but from another source. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void DeviceNotUse_Timer1_oscillator_disable(void)
{
    CLEAR_BIT(TIMER_1_CONTROL_REG , TIMER_1_SYSTEM_CLOCK_STATUS);
}
#endif

/* check if timer 2 will used */
#if TIMER2 == TIMER_ENABLE

/********************************************************************************
 * Function Name:	Timer2_Initialization
 *
 * Description: 	Initialize timer 2 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_Initialization(void)
{
    /* select timer post scaler */
    TIMER_2_CONTROL_REG = Timer2_config_t.timer_postscaler_t << 3;
    /* select timer pre scaler */
    TIMER_2_CONTROL_REG |= Timer2_config_t.timer_prescaler_t;
}

/********************************************************************************
 * Function Name:	Timer2_enable
 *
 * Description: 	enable timer 2 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_enable(void)
{
    SET_BIT(TIMER_2_CONTROL_REG , TIMER_2_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer2_disable
 *
 * Description: 	disable timer 2 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_disable(void)
{
    CLEAR_BIT(TIMER_2_CONTROL_REG , TIMER_2_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer2_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 2. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint8       number of counts
 *******************************************************************************/
uint8 Timer2_read_counter(void)
{
    return TIMER_2_REG;
}

/********************************************************************************
 * Function Name:	Timer2_write_counter
 *
 * Description: 	write user value in timer 2 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint8       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_write_counter(uint8 a_u8init_value_for_timer)
{
    TIMER_2_REG = a_u8init_value_for_timer;
}

/********************************************************************************
 * Function Name:	Timer2_read_period_register
 *
 * Description: 	read the match value that the timer 2 counter will reset when
 *                  matching with it. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint8       number of counts
 *******************************************************************************/
uint8 Timer2_read_period_register(void)
{
    return TIMER_2_PERIOD_REG;
}

/********************************************************************************
 * Function Name:	Timer2_write_period_register
 *
 * Description: 	write the match value that the timer 2 counter will reset when
 *                  matching with it.
 *
 * Inputs:			uint8       match value to reset the timer 2 counter.
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer2_write_period_register(uint8 a_u8init_value_for_period_register)
{
    TIMER_2_PERIOD_REG = a_u8init_value_for_period_register;
}
#endif

/* check if timer 3 will used */
#if TIMER3 == TIMER_ENABLE

/********************************************************************************
 * Function Name:	Timer3_Initialization
 *
 * Description: 	Initialize timer 3 with specified configuration in 
 *                  configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_Initialization(void)
{
    /* select the timer counter will be 8 bits or 16 bits */
    if(Timer3_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_8BIT_16BIT_SELECT);
    }
    else
    {
        CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_8BIT_16BIT_SELECT);
    }
    /* select the timer clock source will be internal from micro_controller or input to T13CKI pin */
    if(Timer3_config_t.timer_clock_source_t == TIMER_INTERNAL_CLOCK)
    {
        CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_CLOCK_SOURCE_SELECT);
    }
    else
    {
        SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_CLOCK_SOURCE_SELECT);
    }
    /* choose if the clock will Synchronize or not when the timer clock is input pulses on T13CKI */
    if(Timer3_config_t.timer_clock_source_t != TIMER_INTERNAL_CLOCK)
    {
        TIMER_3_CONTROL_REG &= 0xFB;
        TIMER_3_CONTROL_REG |= Timer3_config_t.timer_sync_with_external_clock << 2;
    }
    else
    {
        /*Do nothing*/;
    }
    /* select timer pre scaler */
    switch(Timer3_config_t.timer_prescaler_t)
    {
        case TIMER3_NO_PRESCALER:
            CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_1);
            CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER3_PRESCALER_2:
            CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_1);
            SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER3_PRESCALER_4:
            SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_1);
            CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_0);
            break;
        case TIMER3_PRESCALER_8:
            SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_1);
            SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_PRESCALER_SELECT_BIT_0);
            break;
        default:
            /*Do nothing*/
            break;
    }
}

/********************************************************************************
 * Function Name:	Timer3_enable
 *
 * Description: 	enable timer 3 to start counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_enable(void)
{
    SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer3_disable
 *
 * Description: 	disable timer 3 to stop counting. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_disable(void)
{
    CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_ON_OFF_BIT);
}

/********************************************************************************
 * Function Name:	Timer3_read_counter
 *
 * Description: 	read the number has been counted from zero by timer 3. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16       number of counts
 *******************************************************************************/
uint16 Timer3_read_counter(void)
{
    uint16 retVal;
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer3_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        retVal = TIMER_3_LOW_REG;
    }
    else
    {
        retVal = TIMER_3_LOW_REG;
        retVal |= ((uint16)TIMER_3_HIGH_REG) << 8;
    }
    return retVal;
}

/********************************************************************************
 * Function Name:	Timer3_write_counter
 *
 * Description: 	write user value in timer 3 counter to start count from this
 *                  number. 
 *
 * Inputs:			uint16       user number to put in timer counter
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_write_counter(uint16 a_u16init_value_for_timer)
{
    /* check if timer counter size 8 bits or 16 bits */
    if(Timer3_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        TIMER_3_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
    else
    {
        TIMER_3_HIGH_REG = a_u16init_value_for_timer >> 8;
        TIMER_3_LOW_REG = (uint8)a_u16init_value_for_timer;
    }
}

/********************************************************************************
 * Function Name:	Timer3_used_for_both_CCP_modules
 *
 * Description: 	use timer 3 with capture or compare module for the two avaliable
 *                  modules in this micro_controller. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_used_for_both_CCP_modules(void)
{
    SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_2);
}

/********************************************************************************
 * Function Name:	Timer3_used_for_CCP2_module
 *
 * Description: 	use timer 3 with capture or compare module number 2 only. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void Timer3_used_for_CCP2_module(void)
{
    CLEAR_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_2);
    SET_BIT(TIMER_3_CONTROL_REG , TIMER_3_TIMER_1_CCP_ENABLE_BIT_1);
}
#endif

