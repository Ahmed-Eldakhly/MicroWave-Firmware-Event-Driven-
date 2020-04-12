/*******************************************************************************
 *  
 * File:                LCD.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototype of LCD module.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

/* This is a guard condition so that contents of this file are not included
 * more than once. */ 
#ifndef LCD_H
#define	LCD_H

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "stdtypes.h"
#include "LCD_config.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD Commands */
#define CLEAR_COMMAND                       0x01
#define RETURN_HOME_COMMAND                 0x02
#define TWO_LINE_LCD_FOUR_BIT_MODE          0x28
#define TWO_LINE_LCD_EIGHT_BIT_MODE         0x38
#define ONE_LINE_LCD_FOUR_BIT_MODE          0x20
#define ONE_LINE_LCD_EIGHT_BIT_MODE         0x30
#define DISPLAY_ON_CURSOR_OFF 				0x0C
#define DISPLAY_ON_CURSOR_ON_BLANK_OFF 		0x0E
#define DISPLAY_ON_CURSOR_ON_BLANK_ON       0x0F
#define SET_DISPLAY_LOCATION                0x80
#define SELECT_CHAR_FROM_MEMORY             0x40
#define INCREASE_MEMORY_ADDRESS_NO_SHIFT    0x06
#define LCD_ACCESS_CG_ROM                   0x40
#define LCD_ACCESS_FIRST_ROW_DD_RAM         0x80
#define LCD_ACCESS_SECOND_ROW_DD_RAM        0xC0
#define LCD_ACCESS_THIRD_ROW_DD_RAM         0x90
#define LCD_ACCESS_FOURTH_ROW_DD_RAM        0xD0
#define ASCII_ZERO_NUMBER                   0x30
/*******************************************************************************/       

/********************************************************************************
 *                          Functions prototypes      							*
 *******************************************************************************/

/********************************************************************************
 * Function Name:	LCD_Initialization
 *
 * Description: 	Initialize LCD by set directions of LCD pins 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_Initialization (void);

/********************************************************************************
 * Function Name:	LCD_SendCommand
 *
 * Description: 	send commands to LCD 
 *
 * Inputs:			uint8       (the command)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_SendCommand(uint8 a_u8command);

/********************************************************************************
 * Function Name:	LCD_SendDataByte
 *
 * Description: 	send one data byte to display on LCD 
 *
 * Inputs:			uint8       (data byte)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_SendDataByte(uint8 a_u8data);

/********************************************************************************
 * Function Name:	LCD_SendDataString
 *
 * Description: 	send string to display on LCD 
 *
 * Inputs:			uint8*       (pointer to string)
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_SendDataString(uint8* a_u8data_ptr);

/********************************************************************************
 * Function Name:	LCD_SetDisplayPosition
 *
 * Description: 	set the position for next character which will display on LCD. 
 *
 * Inputs:			uint8 a_u8position_X      (column position from 0 to 15)
 *                  uint8 a_u8position_Y      (row position from 1 to 2 (or) to 4)
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_SetDisplayPosition(uint8 a_u8position_X , uint8 a_u8position_Y);

/********************************************************************************
 * Function Name:	LCD_SetUserCharacter
 *
 * Description: 	display new character on LCD which isn't exist in LCD CG_ROM . 
 *
 * Inputs:			uint8* a_u8arr_ptr        array of elements that form the new characters.
 *                  uint8  a_u8size           size of array  
 *                  uint8  a_u8position_X     (column position from 0 to 15)
 *                  uint8  a_u8position_Y     (row position from 1 to 2 (or) to 4)
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_SetUserCharacter(uint8* a_u8arr_ptr , uint8 a_u8size , uint8 a_u8position_X , uint8 a_u8position_Y);

/********************************************************************************
 * Function Name:	LCD_DisplaNumber
 *
 * Description: 	display number not string on LCD.
 *                  note: the number limit is limit of uint32 
 *
 * Inputs:			uint32      the number that will be displayed.
 * 
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_DisplaNumber(sint32 a_s32number);

/********************************************************************************
 * Function Name:	LCD_ClearScreen
 *
 * Description: 	clean LCD screen 
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void LCD_ClearScreen(void);

#endif	/* LCD_H */

