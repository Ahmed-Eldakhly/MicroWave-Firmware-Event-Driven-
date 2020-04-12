/*******************************************************************************
 *  
 * File:                LCD.c
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions implementation of LCD module.
 * 
 * Revision history:    24/2/2020
 * 
 ******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "GPIO.h"
#include "LCD.h"
#define _XTAL_FREQ 8000000
#include <xc.h>

/*******************************************************************************
 *                             Static variables                                *
 *******************************************************************************/
/* used to make data display line by line automatically */
static uint8 g_u8position=0;

/********************************************************************************
 *                          Functions implementation							*
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
void LCD_Initialization (void)
{
/* check the mode of LCD 8 pins or 4 pins to send the data */
#if LCD_MODE == LCD_8BITS_MODE
    GPIO_SetPortDirection(LCD_DATA_PORT , OUTPUT);
#elif LCD_MODE == LCD_4BITS_MODE
    GPIO_SetPinDirection(LCD_DATA_PORT , GPIO_PIN4 , OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT , GPIO_PIN5 , OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT , GPIO_PIN6 , OUTPUT);
    GPIO_SetPinDirection(LCD_DATA_PORT , GPIO_PIN7 , OUTPUT);
#endif
    GPIO_SetPinDirection(LCD_ORDER_PORT , LCD_RS_PIN , OUTPUT);
    GPIO_SetPinDirection(LCD_ORDER_PORT , LCD_RW_PIN , OUTPUT);
    GPIO_SetPinDirection(LCD_ORDER_PORT , LCD_E_PIN , OUTPUT);
/* send some commands to initialize LCD */
#if LCD_MODE == LCD_8BITS_MODE
    LCD_SendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE);
    __delay_ms(5);
    LCD_SendCommand(TWO_LINE_LCD_EIGHT_BIT_MODE);
#elif LCD_MODE == LCD_4BITS_MODE
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RS_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RW_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
    GPIO_WriteOnPort(LCD_DATA_PORT , TWO_LINE_LCD_FOUR_BIT_MODE);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , LOW);
	__delay_us(5);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
	__delay_us(10);
    LCD_SendCommand(TWO_LINE_LCD_FOUR_BIT_MODE);
#endif
    __delay_us(1);
    LCD_SendCommand(DISPLAY_ON_CURSOR_OFF);
    __delay_us(1);
    LCD_SendCommand(CLEAR_COMMAND);
    __delay_us(15);
    LCD_SendCommand(INCREASE_MEMORY_ADDRESS_NO_SHIFT);
    __delay_us(2);
}

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
void LCD_SendCommand(uint8 a_u8command)
{ 
    /* steps to send commands depend on data sheet instructions */
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RS_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RW_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
    GPIO_WriteOnPort(LCD_DATA_PORT , a_u8command);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , LOW);
	__delay_us(5);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
	__delay_us(10);
/* send the command twice when the LCD on 4BITS mode with
*  shift the command right with 4 steps in second time */
#if LCD_MODE == LCD_4BITS_MODE
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RS_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RW_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
    GPIO_WriteOnPort(LCD_DATA_PORT , a_u8command << 4);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , LOW);
	__delay_us(5);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
	__delay_us(10); 
#endif
}

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
void LCD_SendDataByte(uint8 a_u8data)
{
    /* check if the first line end*/
    if(g_u8position == 16)
    {
        /* go to start of second line */
        LCD_SetDisplayPosition(0,2);
    }
    /* check if the second line end*/
    else if (g_u8position == 32)
    {
/* check if LCD has 2 lines */
#if LCD_TYPE == LCD_16x2_TYPE
        /* reset the position flag to start from zero */
        g_u8position = 0;
        /* go to start of first line */
        LCD_SetDisplayPosition(0,1);
/* check if LCD has 4 lines */
#elif LCD_TYPE == LCD_16x4_TYPE
        /* go to start of third line */
        LCD_SetDisplayPosition(0,3);
#endif
    }
/* check if LCD has 4 lines */
#if LCD_TYPE == LCD_16x4_TYPE
    /* check if the third line end*/
    else if (g_u8position == 48)
    {
        /* go to start of fourth line */
        LCD_SetDisplayPosition(0,4);
    }
    /* check if the fourth line end*/
    else if (g_u8position == 64)
    {
        /* reset the position flag to start from zero */
        g_u8position = 0;
        /* go to start of first line */
        LCD_SetDisplayPosition(0,1);
    }
#endif
    else
    {
        /* D0 nothing */
    }
    /* steps to send data byte depend on data sheet instructions */
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RS_PIN , HIGH);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RW_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
    GPIO_WriteOnPort(LCD_DATA_PORT , a_u8data);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , LOW);
	__delay_us(5);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
	__delay_us(10);
/* send the data byte twice when the LCD on 4BITS mode with
 *  shift the data right with 4 steps in second time */
#if LCD_MODE == LCD_4BITS_MODE
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RS_PIN , HIGH);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_RW_PIN , LOW);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
    GPIO_WriteOnPort(LCD_DATA_PORT , a_u8data << 4);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , LOW);
	__delay_us(5);
    GPIO_WriteOnPin(LCD_ORDER_PORT , LCD_E_PIN , HIGH);
	__delay_us(10);
#endif
    /* increment the position flag to check on it to display data line by line */
    g_u8position++;
}

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
void LCD_SendDataString(uint8 * a_u8data_ptr)
{
    /* check if the string is end */
	while(*a_u8data_ptr != '\0')
	{
        /* send character from string to display on LCD */
		LCD_SendDataByte(*a_u8data_ptr);
        /* move to next character */
		a_u8data_ptr++;
	}
}

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
void LCD_SetDisplayPosition(uint8 a_u8position_X , uint8 a_u8position_Y)
{
    /* check if the column position in the allowable limits */
	if((a_u8position_X >= 0)&&(a_u8position_X < 16))
	{
        /* check on row position */
		switch(a_u8position_Y)
		{
		case 1:
			LCD_SendCommand(a_u8position_X + LCD_ACCESS_FIRST_ROW_DD_RAM);
            /* update position flag with new position */
            g_u8position = a_u8position_X;
			break;
		case 2:
			LCD_SendCommand(a_u8position_X + LCD_ACCESS_SECOND_ROW_DD_RAM);
            /* update position flag with new position */
            g_u8position = 16 + a_u8position_X;
			break;
/* check if LCD has 4 lines */
#if LCD_TYPE == LCD_16x4_TYPE
		case 3:
			LCD_SendCommand(a_u8position_X + LCD_ACCESS_THIRD_ROW_DD_RAM);
            /* update position flag with new position */
            g_u8position = 32 + a_u8position_X;
			break;
		case 4:
			LCD_SendCommand(a_u8position_X + LCD_ACCESS_FOURTH_ROW_DD_RAM);
            /* update position flag with new position */
            g_u8position = 48 + a_u8position_X;
			break; 
#endif
        default:
            /* Do nothing */
            break;
		}
	}
}

/********************************************************************************
 * Function Name:	LCD_SetUserCharacter
 *
 * Description: 	display new characters on LCD which isn't exist in LCD CG_ROM.
 *                  note: max characters per call function is 8 characters. 
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
void LCD_SetUserCharacter(uint8* a_u8arr_ptr , uint8 a_u8size , uint8 a_u8position_X , uint8 a_u8position_Y)
{
    /* access CG_RAM */
    LCD_SendCommand(LCD_ACCESS_CG_ROM);
    /* insert the new character by insert the array elements inside LCD CG_RAM */
    for(uint8 u8counter = 0 ; u8counter < a_u8size ; u8counter++)
    {
        LCD_SendDataByte(a_u8arr_ptr[u8counter]);
    }
    /* return to LCD DD_RAM to display inserted characters */
    LCD_SendCommand(LCD_ACCESS_FIRST_ROW_DD_RAM);
    /* go to specified Location*/
    LCD_SetDisplayPosition(a_u8position_X , a_u8position_Y);
    /* display the new characters on LCD */
    for(uint8 u8counter = 0 ; u8counter < a_u8size / 8 ; u8counter++)
    {
        LCD_SendDataByte(u8counter);
    }
}

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
void LCD_DisplaNumber(sint32 a_s32number)
{
    /* check if the number equal zero */
	if(a_s32number == 0)
	{
		LCD_SendDataByte(ASCII_ZERO_NUMBER);
		return;
	}
    /* check if the number is less than zero to display minus sign */
	if(a_s32number<0)
	{
		a_s32number = - a_s32number;
		LCD_SendDataByte('-');
	}
    /* number of digits in the number */
    uint8 DigitNo = 0;
    /* this two variables use to calculate number of digits */
    uint32 check = a_s32number;
    uint32 div = 1;
    /* calculations to get number of digits */
    while(check != 0)
    {
        check /= 10;
        DigitNo++;
    }
    /* loop to get the number which that the number division on it to get the max digit in the number */
    for(uint8 u8counter = 0 ; u8counter < DigitNo - 1 ; u8counter++)
    {
        div *= 10;
    }
    /* loop to display the number digit by digit */
    while(DigitNo != 0)
    {
        /* display the max. digit in the number */
        LCD_SendDataByte(((a_s32number / div) + ASCII_ZERO_NUMBER));
        /* get reminding number */
        a_s32number %= div;
        /* update helper number that use to get the new max digit in the reminding number */
        div /= 10;
        /* increment number of digits to stop when the whole number has been displayed */
        DigitNo--;
    }	
}

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
void LCD_ClearScreen(void)
{
    LCD_SendCommand(CLEAR_COMMAND);
    /* reset the position flag to start from zero */
    g_u8position = 0;
}
