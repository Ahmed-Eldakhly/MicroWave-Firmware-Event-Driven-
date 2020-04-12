/*******************************************************************************
 *  
 * File:                PWM_config.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations of PWM peripheral.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PWM_CONFIG
#define	PWM_CONFIG

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define PINB3                                   0u
#define PINC1                                   1u
/*-----------------------------------------------------------------------------*/
#define SYSTEM_CLOCK_USED_IN_PWM_MODULE         8000000u
#define CAPTURE_COMPARE_PWM_2_PIN               PINC1

#endif	/* PWM_CONFIG */

