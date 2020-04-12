# 1 "interrupt.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "interrupt.c" 2
# 17 "interrupt.c"
# 1 "./interrupt.h" 1
# 22 "./interrupt.h"
# 1 "./interrupt_config.h" 1
# 22 "./interrupt.h" 2

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
# 23 "./interrupt.h" 2
# 44 "./interrupt.h"
extern void Global_interrupt_enable(void);
# 57 "./interrupt.h"
extern void Global_interrupt_disable(void);
# 71 "./interrupt.h"
extern void Peripherals_interrupt_enable(void);
# 85 "./interrupt.h"
extern void Peripherals_interrupt_disable(void);
# 242 "./interrupt.h"
extern void Timer0_enable_overflow_interrupt(void);
# 255 "./interrupt.h"
extern void Timer0_disable_overflow_interrupt(void);
# 268 "./interrupt.h"
extern void Timer0_set_callback_function(void(*a_function_ptr)(void));
# 17 "interrupt.c" 2

# 1 "./interrupt_MemMap.h" 1
# 18 "interrupt.c" 2

# 1 "./helped_macros.h" 1
# 19 "interrupt.c" 2
# 29 "interrupt.c"
static void (*timer0_callback_ptr)(void) = (void*)0x00;
# 42 "interrupt.c"
void Timer0_enable_overflow_interrupt(void)
{
    *(volatile uint8*)0xFF2 |= 1 << 5u;
}
# 58 "interrupt.c"
void Timer0_disable_overflow_interrupt(void)
{
    *(volatile uint8*)0xFF2 &= ~(1 << 5u);
}
# 74 "interrupt.c"
void Timer0_set_callback_function(void(*a_function_ptr)(void))
{

    timer0_callback_ptr = a_function_ptr;
}
# 1266 "interrupt.c"
void Global_interrupt_enable(void)
{
    *(volatile uint8*)0xFF2 |= 1 << 7u;
}
# 1283 "interrupt.c"
void Global_interrupt_disable(void)
{
    *(volatile uint8*)0xFF2 &= ~(1 << 7u);
}
# 1300 "interrupt.c"
void Peripherals_interrupt_enable(void)
{
    *(volatile uint8*)0xFF2 |= 1 << 6u;
}
# 1317 "interrupt.c"
void Peripherals_interrupt_disable(void)
{
    *(volatile uint8*)0xFF2 &= ~(1 << 6u);
}
# 1335 "interrupt.c"
void __attribute__((picinterrupt(("")))) ISR(void)
{



    if((*(volatile uint8*)0xFF2 >> 2u) & 0x01)
    {

        if(timer0_callback_ptr != (void*)0x00)
        {

            timer0_callback_ptr();
        }
        else
        {

        }

        *(volatile uint8*)0xFF2 &= ~(1 << 2u);
    }
    else
    {

    }
# 1811 "interrupt.c"
}
