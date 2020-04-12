/*******************************************************************************
 *  
 * File:                LCD_config.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configurations of LCD module.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LCD_CONFIG_H
#define	LCD_CONFIG_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define LCD_4BITS_MODE                  0u
#define LCD_8BITS_MODE                  1u

#define LCD_16x2_TYPE                   0u
#define LCD_16x4_TYPE                   1u
/*-----------------------------------------------------------------------------*/
#define LCD_DATA_PORT                   GPIO_PORTD
#define LCD_ORDER_PORT                  GPIO_PORTE
#define LCD_RS_PIN                      GPIO_PIN2
#define LCD_RW_PIN                      GPIO_PIN0
#define LCD_E_PIN                       GPIO_PIN1
#define LCD_MODE                        LCD_4BITS_MODE
#define LCD_TYPE                        LCD_16x4_TYPE

#endif	/* LCD_CONFIG_H */

