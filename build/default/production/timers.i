# 1 "timers.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "timers.c" 2
# 17 "timers.c"
# 1 "./timers.h" 1
# 20 "./timers.h"
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
# 20 "./timers.h" 2

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
# 17 "timers.c" 2

# 1 "./timers_MemMap.h" 1
# 18 "timers.c" 2

# 1 "./helped_macros.h" 1
# 19 "timers.c" 2
# 39 "timers.c"
void Timer0_Initialization(void)
{
    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        *(volatile uint8*)0xFD5 |= 1 << 6u;
    }
    else
    {
        *(volatile uint8*)0xFD5 &= ~(1 << 6u);
    }

    if(Timer0_config_t.timer_clock_source_t == TIMER_INTERNAL_CLOCK)
    {
        *(volatile uint8*)0xFD5 &= ~(1 << 5u);
    }
    else
    {
        *(volatile uint8*)0xFD5 |= 1 << 5u;
    }

    if(Timer0_config_t.timer_clock_source_t != TIMER_INTERNAL_CLOCK)
    {
        *(volatile uint8*)0xFD5 &= 0xEF;
        *(volatile uint8*)0xFD5 |= Timer0_config_t.timer_edge_type_on_TCKI_t << 4;
    }
    else
    {
                      ;
    }

    if(Timer0_config_t.timer_prescaler_t != TIMER0_NO_PRESCALER)
    {
        *(volatile uint8*)0xFD5 &= 0xF0;
        *(volatile uint8*)0xFD5 |= Timer0_config_t.timer_prescaler_t;
    }
    else
    {
        *(volatile uint8*)0xFD5 |= 0x08;
    }
}
# 91 "timers.c"
void Timer0_enable(void)
{
    *(volatile uint8*)0xFD5 |= 1 << 7u;
}
# 107 "timers.c"
void Timer0_disable(void)
{
    *(volatile uint8*)0xFD5 &= ~(1 << 7u);
}
# 123 "timers.c"
uint16 Timer0_read_counter(void)
{
    uint16 retVal;

    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        retVal = *(volatile uint8*)0xFD6;
    }
    else
    {
        retVal = *(volatile uint8*)0xFD6;
        retVal |= ((uint16)*(volatile uint8*)0xFD7) << 8;
    }
    return retVal;
}
# 151 "timers.c"
void Timer0_write_counter(uint16 a_u16init_value_for_timer)
{

    if(Timer0_config_t.timer_size_t == TIMER_8BIT_SIZE)
    {
        *(volatile uint8*)0xFD6 = (uint8)a_u16init_value_for_timer;
    }
    else
    {
        *(volatile uint8*)0xFD7 = a_u16init_value_for_timer >> 8;
        *(volatile uint8*)0xFD6 = (uint8)a_u16init_value_for_timer;
    }
}
# 437 "timers.c"
void Timer2_Initialization(void)
{

    *(volatile uint8*)0xFCA = Timer2_config_t.timer_postscaler_t << 3;

    *(volatile uint8*)0xFCA |= Timer2_config_t.timer_prescaler_t;
}
# 456 "timers.c"
void Timer2_enable(void)
{
    *(volatile uint8*)0xFCA |= 1 << 2u;
}
# 472 "timers.c"
void Timer2_disable(void)
{
    *(volatile uint8*)0xFCA &= ~(1 << 2u);
}
# 488 "timers.c"
uint8 Timer2_read_counter(void)
{
    return *(volatile uint8*)0xFCC;
}
# 505 "timers.c"
void Timer2_write_counter(uint8 a_u8init_value_for_timer)
{
    *(volatile uint8*)0xFCC = a_u8init_value_for_timer;
}
# 522 "timers.c"
uint8 Timer2_read_period_register(void)
{
    return *(volatile uint8*)0xFCB;
}
# 539 "timers.c"
void Timer2_write_period_register(uint8 a_u8init_value_for_period_register)
{
    *(volatile uint8*)0xFCB = a_u8init_value_for_period_register;
}
