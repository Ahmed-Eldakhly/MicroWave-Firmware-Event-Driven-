# 1 "ADC.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ADC.c" 2
# 16 "ADC.c"
# 1 "./ADC.h" 1
# 22 "./ADC.h"
# 1 "./stdtypes.h" 1
# 52 "./stdtypes.h"
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short int uint16;
typedef signed short int sint16;
typedef unsigned long int uint32;
typedef signed long int sint32;
typedef unsigned long long int uint64;
typedef signed long long int sint64;
# 22 "./ADC.h" 2







typedef enum{
    ADC_CHANNEL_0,
    ADC_CHANNEL_1,
    ADC_CHANNEL_2,
    ADC_CHANNEL_3,
    ADC_CHANNEL_4,
    ADC_CHANNEL_5,
    ADC_CHANNEL_6,
    ADC_CHANNEL_7,
    ADC_CHANNEL_8,
    ADC_CHANNEL_9,
    ADC_CHANNEL_10,
    ADC_CHANNEL_11,
    ADC_CHANNEL_12
}EnumADC_channels_t;


typedef enum{
    ADC_ACQUISITION_TIME_0,
    ADC_ACQUISITION_TIME_2,
    ADC_ACQUISITION_TIME_4,
    ADC_ACQUISITION_TIME_6,
    ADC_ACQUISITION_TIME_8,
    ADC_ACQUISITION_TIME_12,
    ADC_ACQUISITION_TIME_16,
    ADC_ACQUISITION_TIME_20
}EnumADC_acquisition_Time_t;


typedef enum{
    ADC_PRESCALER_2,
    ADC_PRESCALER_8,
    ADC_PRESCALER_32,
    ADC_OSCILLATOR_CLOCK,
    ADC_PRESCALER_4,
    ADC_PRESCALER_16,
    ADC_PRESCALER_64
}EnumADC_prescaler_t;


typedef enum{
    ADC_RESULT_LEFT_JUSTIFIED,
    ADC_RESULT_RIGHT_JUSTIFIED
}EnumADC_result_format_t;


typedef enum{
    ADC_V_REF_HIGH,
    ADC_V_REF_LOW
}EnumADC_Vref_type_t;


typedef enum{
    ADC_V_REF_INPUT_PIN,
    ADC_V_REF_DEFAULT_VALUE
}EnumADC_Vref_value_t;
# 102 "./ADC.h"
extern void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t);
# 117 "./ADC.h"
extern void ADC_Select_acquisition_time(EnumADC_acquisition_Time_t a_ADC_acquisition_Time_t);
# 132 "./ADC.h"
extern void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t);
# 145 "./ADC.h"
extern uint16 ADC_Read_value(void);
# 158 "./ADC.h"
extern void ADC_Start_conversion(void);
# 171 "./ADC.h"
extern void ADC_Disable(void);
# 186 "./ADC.h"
extern void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t);
# 204 "./ADC.h"
extern void ADC_Set_Vref(EnumADC_Vref_type_t a_ADC_Vref_type_t , EnumADC_Vref_value_t a_ADC_Vref_value_t);
# 16 "ADC.c" 2

# 1 "./ADC_MemMap.h" 1
# 17 "ADC.c" 2

# 1 "./helped_macros.h" 1
# 18 "ADC.c" 2
# 36 "ADC.c"
void ADC_Initialization(EnumADC_channels_t a_ADC_channel_t)
{

    *(volatile uint8*)0xFC2 &= 0xC3;

    *(volatile uint8*)0xFC2 |= a_ADC_channel_t << 2;


    *(volatile uint8*)0xFC1 &= 0xF0;
    switch(a_ADC_channel_t)
    {
        case ADC_CHANNEL_0:
            *(volatile uint8*)0xFC1 |= 0x0E;
            *(volatile uint8*)0xF92 |= 1 << 0u;
            break;
        case ADC_CHANNEL_1:
            *(volatile uint8*)0xFC1 |= 0x0D;
            *(volatile uint8*)0xF92 |= 1 << 1u;
            break;
        case ADC_CHANNEL_2:
            *(volatile uint8*)0xFC1 |= 0x0C;
            *(volatile uint8*)0xF92 |= 1 << 2u;
            break;
        case ADC_CHANNEL_3:
            *(volatile uint8*)0xFC1 |= 0x0B;
            *(volatile uint8*)0xF92 |= 1 << 3u;
            break;
        case ADC_CHANNEL_4:
            *(volatile uint8*)0xFC1 |= 0x0A;
            *(volatile uint8*)0xF92 |= 1 << 5u;
            break;
        case ADC_CHANNEL_5:
            *(volatile uint8*)0xFC1 |= 0x09;
            *(volatile uint8*)0xF96 |= 1 << 0u;
            break;
        case ADC_CHANNEL_6:
            *(volatile uint8*)0xFC1 |= 0x08;
            *(volatile uint8*)0xF96 |= 1 << 1u;
            break;
        case ADC_CHANNEL_7:
            *(volatile uint8*)0xFC1 |= 0x07;
            *(volatile uint8*)0xF96 |= 1 << 2u;
            break;
        case ADC_CHANNEL_8:
            *(volatile uint8*)0xFC1 |= 0x06;
            *(volatile uint8*)0xF93 |= 1 << 2u;
            break;
        case ADC_CHANNEL_9:
            *(volatile uint8*)0xFC1 |= 0x05;
            *(volatile uint8*)0xF93 |= 1 << 3u;
            break;
        case ADC_CHANNEL_10:
            *(volatile uint8*)0xFC1 |= 0x04;
            *(volatile uint8*)0xF93 |= 1 << 1u;
            break;
        case ADC_CHANNEL_11:
            *(volatile uint8*)0xFC1 |= 0x03;
            *(volatile uint8*)0xF93 |= 1 << 4u;
            break;
        case ADC_CHANNEL_12:
            *(volatile uint8*)0xFC1 |= 0x02;
            *(volatile uint8*)0xF93 |= 1 << 0u;
            break;
        default:

            break;
    }
}
# 118 "ADC.c"
void ADC_Select_acquisition_time(EnumADC_acquisition_Time_t a_ADC_acquisition_Time_t)
{

    *(volatile uint8*)0xFC0 &= 0xC7;

    *(volatile uint8*)0xFC0 |= a_ADC_acquisition_Time_t << 3;
}
# 139 "ADC.c"
void ADC_Select_prescaler(EnumADC_prescaler_t a_ADC_prescaler_t)
{

    *(volatile uint8*)0xFC0 &= 0xF8;

    *(volatile uint8*)0xFC0 |= a_ADC_prescaler_t;

    *(volatile uint8*)0xFC2 |= 1 << 0u;
}
# 160 "ADC.c"
uint16 ADC_Read_value(void)
{
    uint16 retVal = 5;

    while(((*(volatile uint8*)0xFC2 >> 1u) & 0x01));

    if((*(volatile uint8*)0xFC0 >> 7u) & 0x01)
    {

        retVal = (uint16)*(volatile uint8*)0xFC4 << 8 | *(volatile uint8*)0xFC3;
    }
    else
    {

        retVal = (uint16)*(volatile uint8*)0xFC4 << 2 | *(volatile uint8*)0xFC3 >> 6;
    }
    return retVal;
}
# 190 "ADC.c"
void ADC_Start_conversion(void)
{
    *(volatile uint8*)0xFC2 |= 1 << 1u;
}
# 206 "ADC.c"
void ADC_Disable()
{
    *(volatile uint8*)0xFC2 &= ~(1 << 0u);
}
# 224 "ADC.c"
void ADC_Set_result_format(EnumADC_result_format_t a_ADC_result_format_t)
{

    if(a_ADC_result_format_t == ADC_RESULT_LEFT_JUSTIFIED)
    {
        *(volatile uint8*)0xFC0 &= ~(1 << 7u);
    }
    else
    {
        *(volatile uint8*)0xFC0 |= 1 << 7u;
    }
}
# 253 "ADC.c"
void ADC_Set_Vref(EnumADC_Vref_type_t a_ADC_Vref_type_t , EnumADC_Vref_value_t a_ADC_Vref_value_t)
{

    if(a_ADC_Vref_type_t == ADC_V_REF_HIGH)
    {

        if(a_ADC_Vref_value_t == ADC_V_REF_INPUT_PIN)
        {
            *(volatile uint8*)0xFC1 |= 1 << 4u;
        }
        else
        {
            *(volatile uint8*)0xFC1 &= ~(1 << 4u);
        }
    }
    else
    {

        if(a_ADC_Vref_value_t == ADC_V_REF_INPUT_PIN)
        {
            *(volatile uint8*)0xFC1 |= 1 << 5u;
        }
        else
        {
            *(volatile uint8*)0xFC1 &= ~(1 << 5u);
        }
    }
}
