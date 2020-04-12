# 1 "PWM.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "PWM.c" 2
# 16 "PWM.c"
# 1 "./PWM.h" 1
# 21 "./PWM.h"
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
# 21 "./PWM.h" 2

# 1 "./PWM_config.h" 1
# 22 "./PWM.h" 2







typedef enum{
    PWM_CHANNEL_1,
    PWM_CHANNEL_2
}EnumPWM_channel_t;
# 51 "./PWM.h"
extern void PWM_Initialization(EnumPWM_channel_t a_PWM_channel_t);
# 65 "./PWM.h"
extern void PWM_Start(EnumPWM_channel_t a_PWM_channel_t);
# 79 "./PWM.h"
extern void PWM_Stop(EnumPWM_channel_t a_PWM_channel_t);
# 92 "./PWM.h"
extern void PWM_Frequency(uint32 a_u32PWM_frequency);
# 107 "./PWM.h"
extern void PWM_DutyCycle(EnumPWM_channel_t a_PWM_channel_t , uint8 a_u16PWM_duty_cycle);
# 16 "PWM.c" 2

# 1 "./PWM_MemMap.h" 1
# 17 "PWM.c" 2

# 1 "./timers.h" 1
# 21 "./timers.h"
# 1 "./timers_config.h" 1
# 21 "./timers.h" 2
# 31 "./timers.h"
typedef enum{
            TIMER_8BIT_SIZE,
            TIMER_16BIT_SIZE
}EnumTimer_regesterSize_t;


typedef enum{
            TIMER_INTERNAL_CLOCK,
            TIMER_TRANSITION_ON_TCKI_PIN
}EnumTimer_clockSource_t;







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


typedef enum{
            TIMER0_RISING_EDGE_CLOCK_ON_TCKI,
            TIMER0_FALLING_EDGE_CLOCK_ON_TCKI,
            TIMER0_NO_TRANSITION_ON_TCKI
}EnumTimer0_edgeTypeOn_TCKI_t;


typedef struct{
            EnumTimer0_prescaler_t timer_prescaler_t;
            EnumTimer_regesterSize_t timer_size_t;
            EnumTimer_clockSource_t timer_clock_source_t;
            EnumTimer0_edgeTypeOn_TCKI_t timer_edge_type_on_TCKI_t;
}StrTimer0_config_t;





extern StrTimer0_config_t Timer0_config_t;
# 97 "./timers.h"
extern void Timer0_Initialization(void);
# 110 "./timers.h"
extern void Timer0_enable(void);
# 123 "./timers.h"
extern void Timer0_disable(void);
# 136 "./timers.h"
extern uint16 Timer0_read_counter(void);
# 150 "./timers.h"
extern void Timer0_write_counter(uint16 a_u16init_value_for_timer);
# 349 "./timers.h"
typedef enum{
            TIMER2_NO_PRESCALER,
            TIMER2_PRESCALER_4,
            TIMER2_PRESCALER_16
}EnumTimer2_prescaler_t;


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


typedef struct{
            EnumTimer2_prescaler_t timer_prescaler_t;
            EnumTimer2_postscaler_t timer_postscaler_t;
}StrTimer2_config_t;





extern StrTimer2_config_t Timer2_config_t;
# 403 "./timers.h"
extern void Timer2_Initialization(void);
# 416 "./timers.h"
extern void Timer2_enable(void);
# 429 "./timers.h"
extern void Timer2_disable(void);
# 442 "./timers.h"
extern uint8 Timer2_read_counter(void);
# 456 "./timers.h"
extern void Timer2_write_counter(uint8 a_u8init_value_for_timer);
# 470 "./timers.h"
extern uint8 Timer2_read_period_register(void);
# 483 "./timers.h"
extern void Timer2_write_period_register(uint8 a_u8init_value_for_period_register);
# 18 "PWM.c" 2

# 1 "./helped_macros.h" 1
# 19 "PWM.c" 2






static uint16 g_u16PWM_reg_value_at_100DutyCycle = 0;
# 44 "PWM.c"
void PWM_Initialization(EnumPWM_channel_t a_PWM_channel_t)
{

    Timer2_config_t.timer_postscaler_t = TIMER2_POSTSCALER_1;

    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {
        *(volatile uint8*)0xF94 &= ~(1 << 2);
    }
    else
    {

        if(1u == 1u)
        {
            *(volatile uint8*)0xF94 &= ~(1 << 1);
        }
        else
        {
            *(volatile uint8*)0xF93 &= ~(1 << 3);
        }
    }
}
# 79 "PWM.c"
void PWM_Start(EnumPWM_channel_t a_PWM_channel_t)
{

    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {

        *(volatile uint8*)0xFBD |= 1 << 3u;
        *(volatile uint8*)0xFBD |= 1 << 2u;
    }
    else
    {

        *(volatile uint8*)0xFBA |= 1 << 3u;
        *(volatile uint8*)0xFBA |= 1 << 2u;
    }

}
# 109 "PWM.c"
void PWM_Stop(EnumPWM_channel_t a_PWM_channel_t)
{

    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {

        *(volatile uint8*)0xFBD &= ~(1 << 3u);
        *(volatile uint8*)0xFBD &= ~(1 << 2u);
        *(volatile uint8*)0xFBD &= ~(1 << 1u);
        *(volatile uint8*)0xFBD &= ~(1 << 0u);

        *(volatile uint8*)0xF8B &= ~(1 << 2);
    }
    else
    {

        *(volatile uint8*)0xFBA &= ~(1 << 3u);
        *(volatile uint8*)0xFBA &= ~(1 << 2u);
        *(volatile uint8*)0xFBA &= ~(1 << 1u);
        *(volatile uint8*)0xFBA &= ~(1 << 0u);

        if(1u == 1u)
        {

            *(volatile uint8*)0xF8B &= ~(1 << 1);
        }
        else
        {

            *(volatile uint8*)0xF8A &= ~(1 << 3);
        }
    }
}
# 154 "PWM.c"
void PWM_Frequency(uint32 a_u32PWM_frequency)
{

    if((8000000u / (a_u32PWM_frequency * 64)) < 256)
    {

        uint16 u8period_register_val = (8000000u / (a_u32PWM_frequency * 4)) - 1;


        g_u16PWM_reg_value_at_100DutyCycle = 8000000u / a_u32PWM_frequency;

        if(u8period_register_val <= 255)
        {

            Timer2_config_t.timer_prescaler_t = TIMER2_NO_PRESCALER;

            Timer2_write_period_register(u8period_register_val);
        }

        else if(u8period_register_val / 4 <= 255)
        {


            g_u16PWM_reg_value_at_100DutyCycle /= 4;

            Timer2_config_t.timer_prescaler_t = TIMER2_PRESCALER_4;

            Timer2_write_period_register(u8period_register_val / 4);
        }

        else
        {


            g_u16PWM_reg_value_at_100DutyCycle /= 16;

            Timer2_config_t.timer_prescaler_t = TIMER2_PRESCALER_16;

            Timer2_write_period_register(u8period_register_val / 16);
        }

        Timer2_Initialization();
    }
    else
    {

        g_u16PWM_reg_value_at_100DutyCycle = 0;
    }
}
# 217 "PWM.c"
void PWM_DutyCycle(EnumPWM_channel_t a_PWM_channel_t , uint8 a_u16PWM_duty_cycle)
{

    uint16 u16PWM_register_val = (uint16)((uint32)g_u16PWM_reg_value_at_100DutyCycle *
                                                                    a_u16PWM_duty_cycle /100);

    if(a_PWM_channel_t == PWM_CHANNEL_1)
    {


        if(u16PWM_register_val & 0x0001)
        {
            *(volatile uint8*)0xFBD |= 1 << 4u;
        }
        else
        {
            *(volatile uint8*)0xFBD &= ~(1 << 4u);
        }


        if(u16PWM_register_val & 0x0002)
        {
            *(volatile uint8*)0xFBD |= 1 << 5u;
        }
        else
        {
            *(volatile uint8*)0xFBD &= ~(1 << 5u);
        }

        *(volatile uint8*)0xFBE = u16PWM_register_val >> 2;
    }
    else
    {


        if(u16PWM_register_val & 0x0001)
        {
            *(volatile uint8*)0xFBA |= 1 << 4u;
        }
        else
        {
            *(volatile uint8*)0xFBA &= ~(1 << 4u);
        }


        if(u16PWM_register_val & 0x0002)
        {
            *(volatile uint8*)0xFBA |= 1 << 5u;
        }
        else
        {
            *(volatile uint8*)0xFBA &= ~(1 << 5u);
        }

        *(volatile uint8*)0xFBB = u16PWM_register_val >> 2;
    }


   Timer2_enable();
}
