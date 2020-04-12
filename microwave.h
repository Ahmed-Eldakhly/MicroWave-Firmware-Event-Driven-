/*******************************************************************************
 *  
 * File:                microwave.h 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains prototypes, enums and definitions of
 *                      microwave Module.
 * 
 * Revision history:    28/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MICROWAVE_H
#define	MICROWAVE_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "GPIO.h"
#include "LCD.h"
#include "PWM.h"
#include "timers.h"
#include "interrupt.h"
#include "ADC.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define _XTAL_FREQ              8000000u
#define ASCII_ZERO_NUMBER       48u
#define MAX_DEF_TEMPERATURE     50u
#define MIN_TEMPERATURE         27u
#define LED_PIN                 GPIO_PIN7
#define LED_PORT                GPIO_PORTB
#define BUZZER_PIN              GPIO_PIN1
#define BUZZER_PORT             GPIO_PORTC
#define HEATER_PIN              GPIO_PIN5
#define HEATER_PORT             GPIO_PORTC
#define DOOR_SENSOR_PIN         GPIO_PIN4
#define DOOR_SENSOR_PORT        GPIO_PORTB
#define WEIGHT_SENSOR_PIN       GPIO_PIN5
#define WEIGHT_SENSOR_PORT      GPIO_PORTB

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/************************** EnumSystem_states_t ********************************/
typedef enum {
            SYSTEM_IDLE_STATE,
            SYSTEM_HEATING_STATE,
            SYSTEM_END_TIME
}EnumSystem_states_t;

/*******************************************************************************
 *                             extern variables                                *
 *******************************************************************************/
/* inserted time in seconds to count down when the heating begin */
extern uint16 g_u16MicrowaveTime;
/* System state variable that used to make system state machine */
extern EnumSystem_states_t g_system_state_var_t;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	Set_and_Display_desired_temp
 *
 * Description: 	make user select temperature by using ADC module which 
 *                  its channel connected with potentiometer device and 
 *                  reading value on ADC is input to PWM module to drive fan
 *                  to produce user specific temperature from 27C to 78C and
 *                  this temperature display on LCD.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Set_and_Display_desired_temp(void);

/*******************************************************************************
 * Function Name:	Display_remind_time
 *
 * Description: 	when heating process occur the reminding time for this
 *                  process displays on LCD by this function.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Display_remind_time (void);

/*******************************************************************************
 * Function Name:	TIMER0_ISR
 *
 * Description: 	the function that send as call_back function to Timer0 interrupt
 *                  to make timer for heating process and make update to the reminding
 *                  time of the heating process to be displayed on LCD.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void TIMER0_ISR(void);

/*******************************************************************************
 * Function Name:	Door_sensor_function
 *
 * Description: 	read door sensor which connected with micro_controller pin and
 *                  display state of the door on the screen when the heating process 
 *                  doesn't occur
 *                  note: during the heating process the door must be closed and we
 *                        can't open it before finishing or pause the process.
 *                  note: in this application, the push button work as door sensor.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Door_sensor_function(void);

/*******************************************************************************
 * Function Name:	Weight_sensor_function
 *
 * Description: 	read weight sensor which connected with micro_controller pin and
 *                  display state of the inside microwave status on the screen when 
 *                  the heating process doesn't occur.
 *                  note: we can't put or remove anything inside microwave when reading
 *                        of door sensor say the door is closed.
 *                  note: in this application, the push button work as weight sensor.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Weight_sensor_function(void);

/*******************************************************************************
 * Function Name:	User_insert_time_and_start_heating_function
 *
 * Description: 	by this function user can insert the time of the heating process,
 *                  clear the wrong insertion and finally start the heating process
 *                  by KeyPad module and when the user write the time, the time displays
 *                  immediately on the LCD.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void User_insert_time_and_start_heating_function(void);

/*******************************************************************************
 * Function Name:	If_heating_is_canceled_function
 *
 * Description: 	this function make the user can pause or cancel the heating  
 *                  process when '#' is pressed for pause and then if the user 
 *                  presses on '#' again the heating process will cancel or presses
 *                  on '*' to continue the reminding time of the heating process.
 *                  note: when the heating process is paused the user can open the 
 *                        door and take the food out and if he want to continue he 
 *                        should return the food and close the door again, and those
 *                        things will be checked by door and weight sensors.
 *                  note: when the heating process is paused, the user cant modify
 *                        the reminding time, for modify it,the user should cancel 
 *                        the heating process
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void If_heating_is_canceled_function(void);

/*******************************************************************************
 * Function Name:	Heating_process_has_done_function
 *
 * Description: 	this function occurs when the heating process finished and
 *                  the reminding time equal to zero.
 *                  this function close the heater and the fan and the LED and 
 *                  invokes the Buzzer to alarm the user.
 *                  note: the user should presses on # or open the door to return 
 *                        to idle state and exit from the heating finished state. 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Heating_process_has_done_function(void);

/*******************************************************************************
 * Function Name:	Reset_to_idle_state
 *
 * Description: 	this function checks if '#' key was pressed or door is opened 
 *                  at end state to return to idle state and stop the Buzzer.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Reset_to_idle_state(void);

/*******************************************************************************
 * Function Name:	Home_screen_display
 *
 * Description: 	Display home screen or the state of door and weight and time 
 *                  and temperature insertion before start of the heating process.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Home_screen_display(void);

/*******************************************************************************
 * Function Name:	Welcome_screen_display
 *
 * Description: 	Display the welcome message.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void Welcome_screen_display(void);

#endif	/* MICROWAVE_H */

