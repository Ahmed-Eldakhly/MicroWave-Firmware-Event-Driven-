/*********************************************************************************
 *  
 * File:                microwave.c 
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of microwave Module.
 * 
 * Revision history:    28/2/2020
 * 
 ********************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "microwave.h"
#include "KeyPad.h"
#include <xc.h>

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/**************************** EnumDoor_sensor_t ********************************/
typedef enum{
            DOOR_IS_OPENED,
            DOOR_IS_CLOSED
}EnumDoor_sensor_t;

/**************************** EnumWeight_sensor_t ******************************/
typedef enum{
            MICROWAVE_IS_EMPTY,
            MICROWAVE_HAS_SOMETHING_INSIDE
}EnumWeight_sensor_t;

/*******************************************************************************
 *                             global variables                                *
 *******************************************************************************/
/* inserted time in seconds to count down when the heating begin */
uint16 g_u16MicrowaveTime = 0;
/* System state variable that used to make system state machine */
EnumSystem_states_t g_system_state_var_t = SYSTEM_IDLE_STATE;

/*******************************************************************************
 *                           Static Variables                                  *
 *******************************************************************************/
/* flag to check if the heating finish */
static uint8 g_u8heating_finished_flag = 0;
/* Door state that used to show reading of door sensor */
static EnumDoor_sensor_t g_door_state_t = DOOR_IS_CLOSED;
/* inside microwave state that used to show reading of weight sensor */
static EnumWeight_sensor_t g_inside_microwave = MICROWAVE_IS_EMPTY;
/* array of 6 elements to save inserted time */
static uint8 g_u8timer_arr[6] = {ASCII_ZERO_NUMBER , ASCII_ZERO_NUMBER , ':' , ASCII_ZERO_NUMBER , ASCII_ZERO_NUMBER , '\0'};
/* variable is used to determine which time digit is inserted */
static uint8 g_u8time_digits = 0;
/* variable used to read pressed key on KeyPad */
static uint8 g_u8keypad_button_val = 10;
/* value of user selected temperature of microwave */
static uint8 g_u8temperature = 0;
/* variable used to check if user change selected temperature to display new value on LCD*/
static uint8 g_u8old_temp_reading = 100;

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

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
void Display_remind_time (void)
{
    /* check if one second passed to update timer and display the new value on LCD*/
    if(g_u8heating_finished_flag == 1)
    {
        g_u8heating_finished_flag = 0;
        /* go to specific position on LCD to display the reminding time*/
        LCD_SetDisplayPosition(11,1);
        LCD_SendDataByte((g_u16MicrowaveTime / 600) + ASCII_ZERO_NUMBER);       /* Display second digits of minutes */
        LCD_SendDataByte(((g_u16MicrowaveTime / 60) % 10) + ASCII_ZERO_NUMBER); /* Display first digits of minutes */
        LCD_SendDataByte(':');
        LCD_SendDataByte(((g_u16MicrowaveTime % 60) / 10) + ASCII_ZERO_NUMBER); /* Display second digits of seconds */
        LCD_SendDataByte(((g_u16MicrowaveTime % 60) % 10) + ASCII_ZERO_NUMBER); /* Display first digits of seconds */
    }
}

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
void TIMER0_ISR(void)
{
    /* calculated number to get overflow interrupt every one second */
    Timer0_write_counter(3037);
    /* decrement timer counter */
    g_u16MicrowaveTime--;
    /* set flag to refer one second passed */
    g_u8heating_finished_flag = 1;
}

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
void Set_and_Display_desired_temp(void)
{
    /* start ADC sampling to get user selected temperature from potentiometer device */
    ADC_Start_conversion();
    /* difference between max. and min. temperature can we get by our microwave is 50 degree*/
    g_u8temperature = ADC_Read_value() * MAX_DEF_TEMPERATURE / 1023;
    /* check if user inserted new value for the temperature to change duty cycle and LCD screen*/
    if(g_u8old_temp_reading != g_u8temperature)
    {
        /* update duty cycle for fan to get specified temperature */
        PWM_DutyCycle(PWM_CHANNEL_1 , 100 - g_u8temperature * 2);
        /* Display the new temperature on the screen */
        LCD_SetDisplayPosition(13,2);
        /* when user insert zero it mean 27c */
        LCD_DisplaNumber(g_u8temperature + MIN_TEMPERATURE);
        /* update the old value to another check next time this function will be called */
        g_u8old_temp_reading = g_u8temperature;
    }
    else
    {
        /* Do nothing*/
    }
}

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
void Door_sensor_function(void)
{
    /* check if sensor change its state (if push button toggle) */
    if(GPIO_ReadFromPin(GPIO_PORTB , GPIO_PIN4) == LOW)
    {
        /* to avoid de_bouncing problem */
        __delay_ms(10);
        /* to not get more than one signal because the the user presses to long time */
        while(GPIO_ReadFromPin(GPIO_PORTB , GPIO_PIN4) == LOW);
        /* change the state of door and show this state on LCD */
        if(g_door_state_t == DOOR_IS_CLOSED)
        {
            g_door_state_t = DOOR_IS_OPENED;
            LCD_SetDisplayPosition(10,3);
            LCD_SendDataString("Opened");
        }
        else
        {
            g_door_state_t = DOOR_IS_CLOSED;
            LCD_SetDisplayPosition(10,3);
            LCD_SendDataString("Closed");
        }
    }
}

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
void Weight_sensor_function(void)
{
    /* check if sensor change its state (if push button toggle) when the door is opened */
    if(g_door_state_t == DOOR_IS_OPENED && GPIO_ReadFromPin(GPIO_PORTB , GPIO_PIN5) == LOW)
    {
        /* to avoid de_bouncing problem */
        __delay_ms(10);
        /* to not get more than one signal because the the user presses to long time */
        while(GPIO_ReadFromPin(GPIO_PORTB , GPIO_PIN5) == LOW);
        /* change the state of inside microwave when the door is opened and show this state on LCD */
        if(g_inside_microwave == MICROWAVE_IS_EMPTY)
        {
            g_inside_microwave = MICROWAVE_HAS_SOMETHING_INSIDE;
            LCD_SetDisplayPosition(10 , 4);
            LCD_SendDataString("  Food");
        }
        else
        {
            g_inside_microwave = MICROWAVE_IS_EMPTY;
            LCD_SetDisplayPosition(10 , 4);
            LCD_SendDataString("N_Food");
        }
    }
    else
    {
        /* Do nothing */
    }
}

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
void User_insert_time_and_start_heating_function(void)
{
    /* initialize KeyPad every function calling because when ADC module corrupt Direction of pins*/
    KeyPad_Initialization();
    /* get pressed key value */
    g_u8keypad_button_val = KeyPad_getPressedKey();
    /* check if key is pressed and the key value is number from 0 to 9 to set timer */
    if(g_u8keypad_button_val >= 0 && g_u8keypad_button_val < 10)
    {
        /* check this value for which digit in the timer value */
        switch(g_u8time_digits)
        {
            case 0:
                /* if user don't insert other digit, this value will be seconds value */
                g_u8timer_arr[4] = g_u8keypad_button_val + ASCII_ZERO_NUMBER;
                /* increment the number of digits in inserted number */
                g_u8time_digits++;
                /* Display the inserted number on LCD */
                LCD_SetDisplayPosition(11,1);
                LCD_SendDataString(g_u8timer_arr);
                /* update timer counter with inserted key value */
                g_u16MicrowaveTime = g_u8keypad_button_val;
                break;
            case 1:
                /* set the previous inserted number as second digits for seconds */
                g_u8timer_arr[3] = g_u8timer_arr[4];
                /* set the current inserted number as first digits for seconds */
                g_u8timer_arr[4] = g_u8keypad_button_val + ASCII_ZERO_NUMBER;
                /* increment the number of digits in inserted number */
                g_u8time_digits++;
                /* Display the inserted number on LCD */
                LCD_SetDisplayPosition(13,1);
                LCD_SendDataByte(g_u8timer_arr[3]);
                LCD_SendDataByte(g_u8timer_arr[4]);
                /* update timer counter with inserted key value */
                g_u16MicrowaveTime = g_u16MicrowaveTime * 10 + g_u8keypad_button_val;
                break;
            case 2:
                /* set the first inserted number as first digits for minutes */
                g_u8timer_arr[1] = g_u8timer_arr[3];
                /* set the previous inserted number as second digits for seconds*/
                g_u8timer_arr[3] = g_u8timer_arr[4];
                /* set the current inserted number as first digits for seconds */
                g_u8timer_arr[4] = g_u8keypad_button_val + ASCII_ZERO_NUMBER;
                /* increment the number of digits in inserted number */
                g_u8time_digits++;
                /* Display the inserted number on LCD */
                LCD_SetDisplayPosition(11,1);
                LCD_SendDataString(g_u8timer_arr);
                /* update timer counter with inserted key value */
                g_u16MicrowaveTime = (g_u8timer_arr[1] - ASCII_ZERO_NUMBER) * 60 +
                        (g_u8timer_arr[3] - ASCII_ZERO_NUMBER) * 10 + g_u8keypad_button_val;
                break;
            case 3:
                /*check if the insertion for the Timer value didn't exceed the max value (99:59).*/
                if(!(g_u8timer_arr[1] == 57 && g_u8timer_arr[3] == 57 && g_u8timer_arr[4] >= 54 ))
                {
                    /* set the first inserted number as second digits for minutes */
                    g_u8timer_arr[0] = g_u8timer_arr[1];
                    /* set the second inserted number as first digits for minutes */
                    g_u8timer_arr[1] = g_u8timer_arr[3];
                    /* set the previous inserted number as second digits for seconds*/
                    g_u8timer_arr[3] = g_u8timer_arr[4];
                    /* set the current inserted number as first digits for seconds */
                    g_u8timer_arr[4] = g_u8keypad_button_val + ASCII_ZERO_NUMBER;
                    /* increment the number of digits to prevent any other number insertion */
                    g_u8time_digits++;
                    /* Display the inserted number on LCD */
                    LCD_SetDisplayPosition(11,1);
                    LCD_SendDataString(g_u8timer_arr);
                    /* update timer counter with inserted key value */
                    g_u16MicrowaveTime = (g_u8timer_arr[0] - ASCII_ZERO_NUMBER) * 600 +
                            (g_u8timer_arr[1] - ASCII_ZERO_NUMBER) * 60 +
                            (g_u8timer_arr[3] - ASCII_ZERO_NUMBER) * 10 + g_u8keypad_button_val;
                }
                else
                {
                    /* Do nothing */
                }
                break;
            default:
                /* Do nothing */
                break;
        }
    }
    /* check if user pressed on the start heating key */
    else if(g_u8keypad_button_val == '*')
    {
        /* check if microwave has something inside itself, door is closed and timer not 
         * equal zero when the user pressed on the start heating key */
        if(g_u16MicrowaveTime != 0 && g_door_state_t == DOOR_IS_CLOSED && g_inside_microwave == MICROWAVE_HAS_SOMETHING_INSIDE)
        {
            /* update digits of timer to prevent any modify in timer when the heating is paused */
            g_u8time_digits = 4;
            /* convert system state to the heating process and start count down the inserted timer */
            g_system_state_var_t = SYSTEM_HEATING_STATE;
            /* Display the reminding time */ 
            LCD_ClearScreen();
            LCD_SendDataString("Timer:");
            LCD_SetDisplayPosition(11,1);
            LCD_SendDataByte((g_u16MicrowaveTime / 600) + ASCII_ZERO_NUMBER);       /* Display second digits of minutes */
            LCD_SendDataByte(((g_u16MicrowaveTime / 60) % 10) + ASCII_ZERO_NUMBER); /* Display first digits of minutes */
            LCD_SendDataByte(':');
            LCD_SendDataByte(((g_u16MicrowaveTime % 60) / 10) + ASCII_ZERO_NUMBER); /* Display second digits of seconds */
            LCD_SendDataByte(((g_u16MicrowaveTime % 60) % 10) + ASCII_ZERO_NUMBER); /* Display first digits of seconds */
            /* Display current selected temperature*/
            LCD_SetDisplayPosition(0 , 2);
            LCD_SendDataString("Temperature:");
            LCD_SetDisplayPosition(13,2);
            LCD_DisplaNumber(g_u8temperature + MIN_TEMPERATURE);
            LCD_SetDisplayPosition(15,2);
            LCD_SendDataByte('c');
            LCD_SetDisplayPosition(0,3);
            /* Display State of system and options for the user in this state */
            LCD_SendDataString("Heating Process ");
            LCD_SendDataString("#:Pause ##:Stop");
            /* start PWM to turn on the fan to get selected temperature*/
            PWM_Start(PWM_CHANNEL_1);
            /* turn on the heater */
            GPIO_WriteOnPin(HEATER_PORT , HEATER_PIN , HIGH);
            /* turn on the LED */
            GPIO_WriteOnPin(LED_PORT , LED_PIN , HIGH);
            /* enable timer 0, global interrupt and timer 0 interrupt to make timer 
             * count down every one second */
            Global_interrupt_enable();
            Timer0_enable_overflow_interrupt();
            Timer0_enable();
        }
        else
        {
            /* Do nothing */
        }
    }
    /* check if the user wants to clear the inserted number to reset the timer again from beginning */
    else if(g_u8keypad_button_val == '#')
    {
        /* change the old value of temp when user cancel the heating without change temperature
         to make the user see the current selected temperature */
        g_u8old_temp_reading = 100;
        /* return to home screen to reenter the time again */
        Home_screen_display();
        /* return the timer array elements to zero to reset them again */
        g_u8timer_arr[0] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[1] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[3] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[4] = ASCII_ZERO_NUMBER;
        /* to allow the user accessing on timer setting */
        g_u8time_digits = 0;
        /* return timer zero counter to zero */
        g_u16MicrowaveTime = 0;
    }
}

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
void If_heating_is_canceled_function(void)
{
    /* initialize KeyPad every function calling because 
     * when ADC module corrupt Direction of pins*/
    KeyPad_Initialization();
    /* get pressed key value */
    g_u8keypad_button_val = KeyPad_getPressedKey();
    /* check if the user pressed on pause_cancel key*/
    if(g_u8keypad_button_val == '#')
    {
        /* return system to Idle state as a pause condition without ability to modify timer time
         * before cancel the previous process by pressing on '#' again */
        g_system_state_var_t = SYSTEM_IDLE_STATE;
        /* turn of the heater */
        GPIO_WriteOnPin(HEATER_PORT , HEATER_PIN , LOW);
        /* turn off the LED */
        GPIO_WriteOnPin(LED_PORT , LED_PIN , LOW);
        /* disable timer 0, global interrupt and timer 0 interrupt */
        Global_interrupt_disable();
        Timer0_disable_overflow_interrupt();
        Timer0_disable();
        /* Stop PWM to stop the fan */
        PWM_Stop(PWM_CHANNEL_1);
        /* Display Door and weight sensors states */
        LCD_SetDisplayPosition(0,3);
        LCD_SendDataString("Door_St:  Closed");
        LCD_SetDisplayPosition(0,4);
        LCD_SendDataString("Inside_St:  Food");
    }
}

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
void Heating_process_has_done_function(void)
{
    /* counter to blank LCD and Buzzer */
    static uint16 u8counter = 0;
    /* turn on the Buzzer */
    GPIO_WriteOnPin(BUZZER_PORT, BUZZER_PIN , LOW);
    /* turn off the heater */
    GPIO_WriteOnPin(HEATER_PORT , HEATER_PIN , LOW);
    /* turn off the LED */
    GPIO_WriteOnPin(LED_PORT , LED_PIN , LOW);
    /* Stop PWM to stop the fan */
    PWM_Stop(PWM_CHANNEL_1);
    /* disable timer 0, global interrupt and timer 0 interrupt */
    Global_interrupt_disable();
    Timer0_disable_overflow_interrupt();
    Timer0_disable();
    /* Blank the finishing process message on LCD and the buzzer alarm */
    if(u8counter == 0)
    {
        LCD_SetDisplayPosition(0 , 1);
        LCD_SendDataString("Timer:");
        LCD_SetDisplayPosition(11 , 1);
        LCD_SendDataString("00:00");
        LCD_SendDataString("Heating finished");
        LCD_SetDisplayPosition(0 , 3);
        LCD_SendDataString("PRESS '#' to");
        LCD_SetDisplayPosition(5 , 4);
        LCD_SendDataString("return home");
        LCD_SetDisplayPosition(11 , 1);
        LCD_SendDataString("00:00");
        u8counter++;
    }
    else if(u8counter < 250)
    {
        u8counter++;
        GPIO_WriteOnPin(BUZZER_PORT , BUZZER_PIN , LOW);
    }
    else if(u8counter == 250)
    {
        LCD_ClearScreen();
        u8counter++;
    }
    else if(u8counter < 500)
    {
        u8counter++;
        GPIO_WriteOnPin(BUZZER_PORT , BUZZER_PIN , HIGH);
    }
    else
    {
        u8counter = 0;
    }
}

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
void Reset_to_idle_state(void)
{
    /* check if Door is opened, 
     * that refer to the user knew the selected time of the heating finished */
    Door_sensor_function();
    /* initialize KeyPad every function calling because 
     * when ADC module corrupt Direction of pins*/
    KeyPad_Initialization();
    /* if the user pressed on '#' or the door is opened after finishing heating
     * the buzzer alarm will stop and system return to idle state to get new operation */
    if(KeyPad_getPressedKey() == '#' || g_door_state_t == DOOR_IS_OPENED)
    {
        g_system_state_var_t = SYSTEM_IDLE_STATE;
        /* turn off the Buzzer */
        GPIO_WriteOnPin(BUZZER_PORT , BUZZER_PIN , HIGH);
        LCD_ClearScreen();
        /* change the old value of temp to make the user see the current selected temperature */
        g_u8old_temp_reading = 100;
        /* return to home screen to start new heating process */
        Home_screen_display();
        /* return the timer array elements to zero to reset them again */
        g_u8timer_arr[0] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[1] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[3] = ASCII_ZERO_NUMBER;
        g_u8timer_arr[4] = ASCII_ZERO_NUMBER;
        /* to allow the user accessing on timer setting */
        g_u8time_digits = 0;
    } 
}

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
void Welcome_screen_display(void)
{
    /* Display Welcome Screen on LCD when the microwave starts */
    LCD_SetDisplayPosition(3,1);
    LCD_SendDataString("Welcome to");
    LCD_SetDisplayPosition(0,2);
    LCD_SendDataString("----------------");
    LCD_SetDisplayPosition(0,3);
    LCD_SendDataString("SWIFT ACT");
    LCD_SetDisplayPosition(7,4);
    LCD_SendDataString("MicroWave");
    __delay_ms(2000);
}

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
void Home_screen_display(void)
{
    /* Display home Screen on LCD after welcome message screen or at idle state of the system */
    LCD_ClearScreen();
    LCD_SendDataString("Time:");
    LCD_SetDisplayPosition(11,1);
    LCD_SendDataString("__:__");
    LCD_SetDisplayPosition(0,2);
    LCD_SendDataString("Temperature:");
    LCD_SetDisplayPosition(15,2);
    LCD_SendDataByte('c');
    /* display state of door sensor at start or when the heating is paused */
    LCD_SetDisplayPosition(0,3);
    if(g_door_state_t == DOOR_IS_CLOSED)
    {
        LCD_SendDataString("Door_St:  Closed");
    }
    else
    {
        LCD_SendDataString("Door_St:  Opened");
    }
    /* display state of weight sensor at start or when the heating is paused */
    LCD_SetDisplayPosition(0,4);
    if(g_inside_microwave == MICROWAVE_IS_EMPTY)
    {
        LCD_SendDataString("Inside_St:N_Food");
    }
    else
    {
        LCD_SendDataString("Inside_St:  Food");
    }
}

