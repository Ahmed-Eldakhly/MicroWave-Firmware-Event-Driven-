/*******************************************************************************
 *  
 * File:                ADC.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of ADC peripheral.
 * 
 * Revision history:    26/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "ADC.h"
#include "ADC_MemMap.h"
#include "helped_macros.h"

/*******************************************************************************
 *                      Functions implementation                               *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	ADC_Initialization
 *
 * Description: 	initialize ADC module with specific channel that is selected
 *                  by the user.
 *
 * Inputs:			a_ADC_channel_t (typedef for all ADC channels : EnumADC_channels_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t)
{
    /* reset channel selection bits in control register 0 */
    ADC_CONTROL_REG_0 &= 0xC3;
    /* select the ADC channel by control register 0 */
    ADC_CONTROL_REG_0 |= a_ADC_channel_t << 2;
    /* enable selected channel pins for ADC module and set the direction of this
     *  pin as input*/
    ADC_CONTROL_REG_1 &= 0xF0;
    switch(a_ADC_channel_t)
    {
        case ADC_CHANNEL_0:
            ADC_CONTROL_REG_1 |= 0x0E;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN0);
            break;   
        case ADC_CHANNEL_1:
            ADC_CONTROL_REG_1 |= 0x0D;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN1);
            break;
        case ADC_CHANNEL_2:
            ADC_CONTROL_REG_1 |= 0x0C;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN2);             
            break;
        case ADC_CHANNEL_3:
            ADC_CONTROL_REG_1 |= 0x0B;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN3);
            break;
        case ADC_CHANNEL_4:
            ADC_CONTROL_REG_1 |= 0x0A;
            SET_BIT(GPIO_DIRECTION_PORTA , GPIO_PIN5);
            break;
        case ADC_CHANNEL_5:
            ADC_CONTROL_REG_1 |= 0x09;
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN0);
            break;
        case ADC_CHANNEL_6:
            ADC_CONTROL_REG_1 |= 0x08;
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN1);
            break;
        case ADC_CHANNEL_7:
            ADC_CONTROL_REG_1 |= 0x07;
            SET_BIT(GPIO_DIRECTION_PORTE , GPIO_PIN2);
            break;
        case ADC_CHANNEL_8:
            ADC_CONTROL_REG_1 |= 0x06;
            SET_BIT(GPIO_DIRECTION_PORTB , GPIO_PIN2);
            break;
        case ADC_CHANNEL_9:
            ADC_CONTROL_REG_1 |= 0x05;
            SET_BIT(GPIO_DIRECTION_PORTB , GPIO_PIN3);
            break;
        case ADC_CHANNEL_10:
            ADC_CONTROL_REG_1 |= 0x04;
            SET_BIT(GPIO_DIRECTION_PORTB , GPIO_PIN1);
            break;
        case ADC_CHANNEL_11:
            ADC_CONTROL_REG_1 |= 0x03;
            SET_BIT(GPIO_DIRECTION_PORTB , GPIO_PIN4);
            break;
        case ADC_CHANNEL_12:
            ADC_CONTROL_REG_1 |= 0x02;
            SET_BIT(GPIO_DIRECTION_PORTB , GPIO_PIN0);
            break;
        default:
            /*Do nothing */
            break;                                                   
    } 
}

/*******************************************************************************
 * Function Name:	ADC_Select_acquisition_time
 *
 * Description: 	this function allow the user to select the acquisition time to 
 *                  invoke automatically or set by user calculated delay function.
 *
 * Inputs:			a_ADC_acquisition_Time_t (typedef for all avaliable ADC
 *                  acquisition values : EnumADC_channels_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Select_acquisition_time(EnumADC_acquisition_Time_t a_ADC_acquisition_Time_t)
{
    /* reset acquisition selection bits */
    ADC_CONTROL_REG_2 &= 0xC7;
    /* set selected acquisition time */
    ADC_CONTROL_REG_2 |= a_ADC_acquisition_Time_t << 3;
}

/*******************************************************************************
 * Function Name:	ADC_Select_prescaler
 *
 * Description: 	this function allow the user to select the clock frequency for  
 *                  ADC module by devision system clock on selected pre_scaler value.
 *
 * Inputs:			EnumADC_prescaler_t (typedef for all avaliable ADC
 *                  pre_scaler values : EnumADC_prescaler_t)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t)
{
    /* reset pre_scaler selection bits */
    ADC_CONTROL_REG_2 &= 0xF8;
    /* set the selected pre_scaler */
    ADC_CONTROL_REG_2 |= a_ADC_prescaler_t;
    /* enable ADC  peripheral */
    SET_BIT(ADC_CONTROL_REG_0 , ADC_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Read_value
 *
 * Description: 	this function return the value of signal that is converted by ADC.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			uint16 (result value will be in 10 bits)
 *******************************************************************************/
uint16 ADC_Read_value(void)
{
    uint16 retVal = 5;
    /* polling until the conversion finishes */
    while((GET_BIT(ADC_CONTROL_REG_0 , ADC_START_CONVERSION_BIT)));
    /* chick on the justification format of ADC conversion result in ADC high and low registers */
    if(GET_BIT(ADC_CONTROL_REG_2 , ADC_SELECT_RESULT_FORMAT))
    {
        /* get result from right justification format */
        retVal = (uint16)ADC_VALUE_HIGH << 8 | ADC_VALUE_LOW;
    }
    else
    {
        /* get result from left justification format */
        retVal = (uint16)ADC_VALUE_HIGH << 2 | ADC_VALUE_LOW >> 6;
    }
    return retVal;
}

/*******************************************************************************
 * Function Name:	ADC_Start_conversion
 *
 * Description: 	start the ADC sampling process on initialized channel.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Start_conversion(void)
{
    SET_BIT(ADC_CONTROL_REG_0 , ADC_START_CONVERSION_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Disable
 *
 * Description: 	Disable ADC module.
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Disable()
{
    CLEAR_BIT(ADC_CONTROL_REG_0 , ADC_ENABLE_BIT);
}

/*******************************************************************************
 * Function Name:	ADC_Set_result_format
 *
 * Description: 	select the result justification format left justification or
 *                  right justification.
 *
 * Inputs:			EnumADC_result_format_t (typedef for avaliable justification 
 *                  for result of ADC conversion).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t)
{
    /* check what is the type of format of result */
    if(a_ADC_result_format_t == ADC_RESULT_LEFT_JUSTIFIED)
    {
        CLEAR_BIT(ADC_CONTROL_REG_2 , ADC_SELECT_RESULT_FORMAT);
    }
    else
    {
        SET_BIT(ADC_CONTROL_REG_2 , ADC_SELECT_RESULT_FORMAT);
    }
}

/*******************************************************************************
 * Function Name:	ADC_Set_Vref
 *
 * Description: 	allow the user to select the reference voltage for ADC conversion
 *                  process (max. and min. voltage) from input source on two channels 
 *                  of ADC module.
 *
 * Inputs:			EnumADC_Vref_type_t (typedef to which voltage is set(max. or min.)).
 * 
 *                  EnumADC_Vref_value_t (typedef to select the source of voltage will be
 *                  the default value on micro_controller or input on specific ADC channel).
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void ADC_Set_Vref(EnumADC_Vref_type_t a_ADC_Vref_type_t , EnumADC_Vref_value_t a_ADC_Vref_value_t)
{
    /* check if the reference voltage is high or low */
    if(a_ADC_Vref_type_t == ADC_V_REF_HIGH)
    {
        /* check if the high reference voltage is default or input to ADC channel 3 */
        if(a_ADC_Vref_value_t == ADC_V_REF_INPUT_PIN)
        {
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_HIGH_VOLTAGE_REF);
        }
        else
        {
            CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_HIGH_VOLTAGE_REF);
        }
    }
    else
    {
        /* check if the low reference voltage is default or input to ADC channel 2 */
        if(a_ADC_Vref_value_t == ADC_V_REF_INPUT_PIN)
        {
            SET_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_LOW_VOLTAGE_REF);
        }
        else
        {
            CLEAR_BIT(ADC_CONTROL_REG_1 , ADC_SELECT_LOW_VOLTAGE_REF);
        }        
    }
}