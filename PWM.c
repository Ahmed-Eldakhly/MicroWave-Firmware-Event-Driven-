/******************************************************************************* 
 * 
 * File:                PWM.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of PWM peripheral.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "PWM.h"
#include "PWM_MemMap.h"
#include "timers.h"
#include "helped_macros.h"

/*******************************************************************************
 *                             Static variables                                *
 *******************************************************************************/
/* used to change duty cycle in duty cycle function */
static uint16 g_u16PWM_reg_value_at_100DutyCycle = 0;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	PWM_Initialization
 *
 * Description: 	Initialize PWM by configure timer 2 and set direction of
 *                  selected channal as output pin. 
 *
 * Inputs:			EnumPWM_channel_t      (typedef for available channels in
 *                                               this micro_controller).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PWM_Initialization(EnumPWM_channel_t a_PWM_channel_t)
{
    /* not use post scale for timer 2 when it use for PWM operations */
    Timer2_config_t.timer_postscaler_t = TIMER2_POSTSCALER_1;
    /* check which PWM channel will use to set the pin that belongs the channel as output pin*/
    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {    
        CLEAR_BIT(PWM_1_PIN_DIRECTION_REG , 2);
    }
    else
    {
        /* check which pin used with channel 2 of PWM module (Pin 1 - Port C (or) Pin 3 - Port B) */
        if(CAPTURE_COMPARE_PWM_2_PIN == PINC1)
        {
            CLEAR_BIT(PWM_1_PIN_DIRECTION_REG , 1);
        }
        else
        {
            CLEAR_BIT(PWM_2_PIN_DIRECTION_REG , 3);
        }
    }
}

/********************************************************************************
 * Function Name:	PWM_Start
 *
 * Description: 	make PWM start working. 
 *
 * Inputs:			EnumPWM_channel_t      (typedef for available channels in
 *                                               this micro_controller).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PWM_Start(EnumPWM_channel_t a_PWM_channel_t)
{
    /* check which PWM channel will use to enable it*/
    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {
        /* enable PWM module */
        SET_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_3);
        SET_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_2);
    }
    else
    {
        /* enable PWM module */
        SET_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_3);
        SET_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_2);
    }
    
}

/********************************************************************************
 * Function Name:	PWM_Stop
 *
 * Description: 	make PWM stop working. 
 *
 * Inputs:			EnumPWM_channel_t      (typedef for available channels in
 *                                               this micro_controller).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PWM_Stop(EnumPWM_channel_t a_PWM_channel_t)
{
    /* check which PWM channel will stop */
    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {
        /* disable PWM module */
        CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_3);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_2);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_1);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , CAPTURE_COMPARE_PWM_1_SELECT_MODE_BIT_0);
        /* drive PWM pin to zero value */
        CLEAR_BIT(PWM_1_PIN_VALUE_REG , 2);
    }
    else
    {
        /* disable PWM module */
        CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_3);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_2);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_1);
        CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , CAPTURE_COMPARE_PWM_2_SELECT_MODE_BIT_0);
        /* check which pin used for channel 2 of PWM */
        if(CAPTURE_COMPARE_PWM_2_PIN == PINC1)
        {
            /* drive PWM pin to zero value */
            CLEAR_BIT(PWM_1_PIN_VALUE_REG , 1);
        }
        else
        {
            /* drive PWM pin to zero value */
            CLEAR_BIT(PWM_2_PIN_VALUE_REG , 3);
        }
    }   
}

/********************************************************************************
 * Function Name:	PWM_Frequency
 *
 * Description: 	set the frequency of PWM signal. 
 *
 * Inputs:			uint32      PWM frequency
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PWM_Frequency(uint32 a_u32PWM_frequency)
{
    /* select suitable pre scaler of timer 2 to get specified frequency */
    if((SYSTEM_CLOCK_USED_IN_PWM_MODULE / (a_u32PWM_frequency * 64)) < 256)
    {
        /* equation from data sheet to get time of one period without timer 2 pre scaler*/
        uint16 u8period_register_val = (SYSTEM_CLOCK_USED_IN_PWM_MODULE / (a_u32PWM_frequency * 4)) - 1;
        /* equation from data sheet to get the max value that will be inserted in 
         * PWM register to get 100 % duty cycle */
        g_u16PWM_reg_value_at_100DutyCycle = SYSTEM_CLOCK_USED_IN_PWM_MODULE / a_u32PWM_frequency;
        /* check if no pre scaler option get number with limits */
        if(u8period_register_val <= 255)
        {
            /* select no pre scaler to timer 2 */
            Timer2_config_t.timer_prescaler_t = TIMER2_NO_PRESCALER;
            /* set match value that timer counter will reset when get this value */
            Timer2_write_period_register(u8period_register_val);
        }
        /* check if pre scaler (4) option get number with limits */
        else if(u8period_register_val / 4 <= 255)
        {
            /* calculate the max value that will be inserted i PWM register 
             * to get 100 % duty cycle*/
            g_u16PWM_reg_value_at_100DutyCycle /= 4;
            /* select pre scaler to timer 2 (division system clock by 4) */
            Timer2_config_t.timer_prescaler_t = TIMER2_PRESCALER_4;
            /* set match value that timer counter will reset when get this value */
            Timer2_write_period_register(u8period_register_val / 4);
        }
        /* check if pre scaler (16) option get number with limits */
        else
        {
            /* calculate the max value that will be inserted i PWM register 
             * to get 100 % duty cycle*/
            g_u16PWM_reg_value_at_100DutyCycle /= 16;
            /* select pre scaler to timer 2 (division system clock by 16) */
            Timer2_config_t.timer_prescaler_t = TIMER2_PRESCALER_16;
            /* set match value that timer counter will reset when get this value */
            Timer2_write_period_register(u8period_register_val / 16);
        }
        /* initialize timer 2 with right configurations with inserted frequency */
        Timer2_Initialization();
    }
    else
    {
        /* inserted frequency can't met the limits of timer 2 counter register */
        g_u16PWM_reg_value_at_100DutyCycle = 0;
    }
}

/********************************************************************************
 * Function Name:	PWM_DutyCycle
 *
 * Description: 	make PWM pin for specified channel work with specified duty cycle. 
 *
 * Inputs:			EnumPWM_channel_t      (typedef for available channels in
 *                                               this micro_controller).
 *                  uint8                   duty cycle (from zero to 100)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void PWM_DutyCycle(EnumPWM_channel_t a_PWM_channel_t , uint8 a_u16PWM_duty_cycle)
{
    /* equation to get the value of PWM register to get specified duty cycle*/
    uint16 u16PWM_register_val = (uint16)((uint32)g_u16PWM_reg_value_at_100DutyCycle *
                                                                    a_u16PWM_duty_cycle /100);
    /* check which PWM channel will be used with this duty cycle */
    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {
        /* set the first bit of PWM value in PWM control register 
         * because the value is 10 bits not 8 bits*/
        if(u16PWM_register_val & 0x0001)
        {
            SET_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , PWM_1_DUTY_CYCLE_BIT_0);
        }
        else
        {
            CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , PWM_1_DUTY_CYCLE_BIT_0);
        }
        /* set the second bit of PWM value in PWM control register 
         * because the value is 10 bits not 8 bits*/
        if(u16PWM_register_val & 0x0002)
        {
            SET_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , PWM_1_DUTY_CYCLE_BIT_1);
        }
        else
        {
            CLEAR_BIT(CAPTURE_COMPARE_PWM_1_CONTROL_REG , PWM_1_DUTY_CYCLE_BIT_1);
        }
        /* set the reminding bits in PWM register */
        CAPTURE_COMPARE_PWM_1_LOW_REG = u16PWM_register_val >> 2;
    }
    else
    {
        /* set the first bit of PWM value in PWM control register 
         * because the value is 10 bits not 8 bits*/
        if(u16PWM_register_val & 0x0001)
        {
            SET_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , PWM_2_DUTY_CYCLE_BIT_0);
        }
        else
        {
            CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , PWM_2_DUTY_CYCLE_BIT_0);
        }
        /* set the second bit of PWM value in PWM control register 
         * because the value is 10 bits not 8 bits*/
        if(u16PWM_register_val & 0x0002)
        {
            SET_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , PWM_2_DUTY_CYCLE_BIT_1);
        }
        else
        {
            CLEAR_BIT(CAPTURE_COMPARE_PWM_2_CONTROL_REG , PWM_2_DUTY_CYCLE_BIT_1);
        }
        /* set the reminding bits in PWM register */
        CAPTURE_COMPARE_PWM_2_LOW_REG = u16PWM_register_val >> 2;
    }
    /* start timer 2 to use as timer for PWM to change the output on the PWM pin
     *  with specified duty cycle */
   Timer2_enable();
}