/********************************************************************************** 
 * File:                timers.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes and enums of all timers peripherals.
 * 
 * Revision history:    25/2/2020
 * 
 **********************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once.*/  
#ifndef TIMERS_H
#define	TIMERS_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"
#include "timers_config.h"

/* check if timer 0 or timer 1 or timer 3 will used */
#if TIMER0 == TIMER_ENABLE || TIMER1 == TIMER_ENABLE || TIMER3 == TIMER_ENABLE

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/************************** EnumTimer_regesterSize_t ***************************/
typedef enum{
            TIMER_8BIT_SIZE,
            TIMER_16BIT_SIZE
}EnumTimer_regesterSize_t;

/************************** EnumTimer_clockSource_t ****************************/
typedef enum{
            TIMER_INTERNAL_CLOCK,
            TIMER_TRANSITION_ON_TCKI_PIN
}EnumTimer_clockSource_t;

#endif

/* check if timer 0 will used */
#if TIMER0 == TIMER_ENABLE

/*************************** EnumTimer0_prescaler_t ****************************/
typedef enum{
            TIMER0_PRESCALER_2,
            TIMER0_PRESCALER_4,
            TIMER0_PRESCALER_8,
            TIMER0_PRESCALER_16,
            TIMER0_PRESCALER_32,
            TIMER0_PRESCALER_64,
            TIMER0_PRESCALER_128,
            TIMER0_PRESCALER_256,
            TIMER0_NO_PRESCALER
}EnumTimer0_prescaler_t;

/************************ EnumTimer0_edgeTypeOn_TCKI_t *************************/
typedef enum{
            TIMER0_RISING_EDGE_CLOCK_ON_TCKI,
            TIMER0_FALLING_EDGE_CLOCK_ON_TCKI,
            TIMER0_NO_TRANSITION_ON_TCKI
}EnumTimer0_edgeTypeOn_TCKI_t;

/***************************** StrTimer0_config_t ******************************/
typedef struct{
            EnumTimer0_prescaler_t          timer_prescaler_t;
            EnumTimer_regesterSize_t        timer_size_t;
            EnumTimer_clockSource_t         timer_clock_source_t;
            EnumTimer0_edgeTypeOn_TCKI_t    timer_edge_type_on_TCKI_t;
}StrTimer0_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 0 configuration that the user will set */
extern StrTimer0_config_t Timer0_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	Timer0_Initialization
 *
 * Description: 	Initialize timer 0 with specified configuration in 
 *                  configuration structure.Initialize timer 0 with specified configuration in configuration structure. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Timer0_Initialization(void);

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
extern void Timer0_enable(void);

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
extern void Timer0_disable(void);

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
extern uint16 Timer0_read_counter(void);

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
extern void Timer0_write_counter(uint16 a_u16init_value_for_timer);
#endif

/* check if timer 1 will used */
#if TIMER1 == TIMER_ENABLE

/*******************************************************************************
 *                           Types Declaration                                 *
 *******************************************************************************/

/*************************** EnumTimer1_prescaler_t ****************************/
typedef enum{
            TIMER1_NO_PRESCALER,
            TIMER1_PRESCALER_2,
            TIMER1_PRESCALER_4,
            TIMER1_PRESCALER_8
}EnumTimer1_prescaler_t;

/******************** EnumTimer1_sync_with_external_clock_t ********************/
typedef enum{
            TIMER1_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NOT_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER1_NO_EXTERNAL_CLOCK
}EnumTimer1_sync_with_external_clock_t;

/***************************** StrTimer1_config_t ******************************/
typedef struct{
            EnumTimer1_prescaler_t                  timer_prescaler_t;
            EnumTimer_regesterSize_t                timer_size_t;
            EnumTimer_clockSource_t                 timer_clock_source_t;
            EnumTimer1_sync_with_external_clock_t   timer_sync_with_external_clock;
}StrTimer1_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 1 configuration that the user will set */
extern StrTimer1_config_t Timer1_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

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
extern void Timer1_Initialization(void);

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
extern void Timer1_enable(void);

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
extern void Timer1_disable(void);

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
extern uint16 Timer1_read_counter(void);

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
extern void Timer1_write_counter(uint16 a_u16init_value_for_timer);

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
extern void Timer1_used_for_both_CCP_modules(void);

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
extern void Timer1_used_for_CCP1_module(void);

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
extern void Timer1_oscillator_enable(void);

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
extern void Timer1_oscillator_disable(void);

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
extern void DeviceUse_Timer1_oscillator_enable(void);

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
extern void DeviceNotUse_Timer1_oscillator_disable(void);
#endif

/* check if timer 2 will used */
#if TIMER2 == TIMER_ENABLE

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/*************************** EnumTimer2_prescaler_t ****************************/
typedef enum{
            TIMER2_NO_PRESCALER,
            TIMER2_PRESCALER_4,
            TIMER2_PRESCALER_16
}EnumTimer2_prescaler_t;

/*************************** EnumTimer2_postscaler_t ***************************/
typedef enum{
            TIMER2_POSTSCALER_1,
            TIMER2_POSTSCALER_2,
            TIMER2_POSTSCALER_3,
            TIMER2_POSTSCALER_4,
            TIMER2_POSTSCALER_5,
            TIMER2_POSTSCALER_6,
            TIMER2_POSTSCALER_7,
            TIMER2_POSTSCALER_8,
            TIMER2_POSTSCALER_9,
            TIMER2_POSTSCALER_10,
            TIMER2_POSTSCALER_11,
            TIMER2_POSTSCALER_12,
            TIMER2_POSTSCALER_13,
            TIMER2_POSTSCALER_14,
            TIMER2_POSTSCALER_15,
            TIMER2_POSTSCALER_16
}EnumTimer2_postscaler_t;

/***************************** StrTimer2_config_t ******************************/
typedef struct{
            EnumTimer2_prescaler_t                  timer_prescaler_t;
            EnumTimer2_postscaler_t                 timer_postscaler_t;
}StrTimer2_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 2 configuration that the user will set */
extern StrTimer2_config_t Timer2_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

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
extern void Timer2_Initialization(void);

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
extern void Timer2_enable(void);

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
extern void Timer2_disable(void);

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
extern uint8 Timer2_read_counter(void);

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
extern void Timer2_write_counter(uint8 a_u8init_value_for_timer);

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
extern uint8 Timer2_read_period_register(void);
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
extern void Timer2_write_period_register(uint8 a_u8init_value_for_period_register);
#endif

/* check if timer 3 will used */
#if TIMER3 == TIMER_ENABLE

/*******************************************************************************
 *                              Types Declaration                              *
 *******************************************************************************/

/*************************** EnumTimer3_prescaler_t ****************************/
typedef enum{
            TIMER3_NO_PRESCALER,
            TIMER3_PRESCALER_2,
            TIMER3_PRESCALER_4,
            TIMER3_PRESCALER_8
}EnumTimer3_prescaler_t;

/******************** EnumTimer3_sync_with_external_clock_t ********************/
typedef enum{
            TIMER3_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER3_NOT_SYNC_WITH_EXTERNAL_CLOCK,
            TIMER3_NO_EXTERNAL_CLOCK
}EnumTimer3_sync_with_external_clock_t;

/***************************** StrTimer3_config_t ******************************/
typedef struct{
            EnumTimer3_prescaler_t                  timer_prescaler_t;
            EnumTimer_regesterSize_t                timer_size_t;
            EnumTimer_clockSource_t                 timer_clock_source_t;
            EnumTimer3_sync_with_external_clock_t   timer_sync_with_external_clock;
}StrTimer3_config_t;

/*******************************************************************************
 *                           extern Variables                                  *
 *******************************************************************************/
/* structure of timer 3 configuration that the user will set */
extern StrTimer3_config_t Timer3_config_t;

/********************************************************************************
 *                          Functions implementation							*
 *******************************************************************************/

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
extern void Timer3_Initialization(void);

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
extern void Timer3_enable(void);

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
extern void Timer3_disable(void);

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
extern uint16 Timer3_read_counter(void);

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
extern void Timer3_write_counter(uint16 a_u16init_value_for_timer);

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
extern void Timer3_used_for_both_CCP_modules(void);

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
extern void Timer3_used_for_CCP2_module(void);
#endif

#endif	/* TIMERS_H */

