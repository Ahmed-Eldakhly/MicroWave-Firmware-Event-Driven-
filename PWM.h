/*******************************************************************************
 *  
 * File:                PWM.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes and enums of PWM peripheral.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_H
#define	PWM_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"
#include "PWM_config.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*************************** EnumPWM_channel_t ********************************/
typedef enum{
    PWM_CHANNEL_1,
    PWM_CHANNEL_2        
}EnumPWM_channel_t;

/********************************************************************************
 *                              Functions Prototypes							*
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
extern void PWM_Initialization(EnumPWM_channel_t a_PWM_channel_t);

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
extern void PWM_Start(EnumPWM_channel_t a_PWM_channel_t);

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
extern void PWM_Stop(EnumPWM_channel_t a_PWM_channel_t);

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
extern void PWM_Frequency(uint32 a_u32PWM_frequency);

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
extern void PWM_DutyCycle(EnumPWM_channel_t a_PWM_channel_t , uint8 a_u16PWM_duty_cycle);

#endif	/* PWM */

