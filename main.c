/*******************************************************************************
 *  
 * File:                main.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            the application code.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "general_bitConfig.h"
#include "microwave.h"

/* main application code */
void main(void) 
{
    /* Disable all ADC Channels Pins except Channel 0 */
    GPIO_Disable_ADC_On_Pins(GPIO_PORTA , GPIO_PIN1);
    /* Disable comparator module on PORT A */
    GPIO_Disable_Comparator_On_PORTA();
    /* enable weak internal Pull up resistors on input pins on PORT B */
    GPIO_Enable_Pull_Up_On_PortB();
    /* Set Heater pin as output pin */
    GPIO_SetPinDirection(HEATER_PORT , HEATER_PIN , OUTPUT);
    /* Set Buzzer pin as output pin */
    GPIO_SetPinDirection(BUZZER_PORT , BUZZER_PIN , OUTPUT);
    /* Disable Buzzer */
    GPIO_WriteOnPin(BUZZER_PORT , BUZZER_PIN , HIGH);
    /* Set LED pin as output pin */
    GPIO_SetPinDirection(LED_PORT , LED_PIN , OUTPUT);
    /* Disable LED */
    GPIO_WriteOnPin(LED_PORT , LED_PIN , LOW);
    /* Set Door sensor pin as input pin */
    GPIO_SetPinDirection(DOOR_SENSOR_PORT , DOOR_SENSOR_PIN , INPUT);
    /* Set weight sensor pin as input pin */
    GPIO_SetPinDirection(WEIGHT_SENSOR_PORT , WEIGHT_SENSOR_PIN , INPUT);
    /* initialize LCD module */
    LCD_Initialization();
    /* initialize PWM module on Channel 1 "PORT C - PIN 2" to make fan 
     * work to set the user desired temperature for heating operation. */
    PWM_Initialization(PWM_CHANNEL_1);
    /* Select frequency of PWM module */
    PWM_Frequency(3000);
    /* initialize ADC module on Channel 1 "PORT A - PIN 0" to allow user 
     * select temperature for heating operation by potentiometer device. */
    ADC_Initialization(ADC_CHANNEL_0);
    /* Select Auto acquisition feature for ADC channel 1 with mapped time = 4 */
    ADC_Select_acquisition_time(ADC_ACQUISITION_TIME_4);
    /* Select ADC clock by devision system clock on the selected 
     * number "16" to determine time of conversion on ADC channel 1. */
    ADC_Select_prescaler(ADC_PRESCALER_16);
    /* initialize Timer 0 module */
    Timer0_Initialization();
    /* Set Timer 0 call_back function to run when overflow interrupt occur  */
    Timer0_set_callback_function(TIMER0_ISR);
    /* Display Welcome message when turn device on */
    Welcome_screen_display();
    /* Display home screen or idle state screen */
    Home_screen_display();
    /* loop to make program is worked as long the power is on */
    while(1)
    {
        /* check on device states to move from state to another depend on user choices */
        switch(g_system_state_var_t)
        {
            /* idle state that make user select heating time, open door, put food
             *  inside microwave and set suitable temperature from 27c to 78c */
            case SYSTEM_IDLE_STATE:
                /* user selects temperature by potentiometer and Display this temp. on screen. */
                Set_and_Display_desired_temp();
                /* user can open the door to put the food and close the door again */
                Door_sensor_function();
                /* user can put the food inside microwave or take it out if the door is opened. */
                Weight_sensor_function();
                /* user can insert the heating time that he want and 
                 * this time display on screen while the user insert it*/
                User_insert_time_and_start_heating_function();
                break;
            /* the microwave is heating the food when the time is selected 
             * and the door is closed and the food is inside the microwave */    
            case SYSTEM_HEATING_STATE:
                /* user selects temperature by potentiometer and Display this temp. on screen. */
                Set_and_Display_desired_temp();
                /* Display the reminding time to finish heating process*/
                Display_remind_time();
                /* check if user canceled the heating process */
                If_heating_is_canceled_function();
                /* check if the heating process finished */
                if (g_u16MicrowaveTime == 0)
                {
                    g_system_state_var_t = SYSTEM_END_TIME;
                    LCD_ClearScreen();
                }
                break;
            /* state after the heating process finished, in this state the system alarm the user*/
            case SYSTEM_END_TIME:
                /* disable the heating devices and enable alarm */
                Heating_process_has_done_function();
                /* return the system to idle state and reset time array and clear LCD*/
                Reset_to_idle_state();
                break;
            default:
                /* Do nothing*/
                break;
        }
    }
}

