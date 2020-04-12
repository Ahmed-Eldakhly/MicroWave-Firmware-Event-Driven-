/*******************************************************************************
 *  
 * File:                KeyPad.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains functions prototypes of Keypad module.
 * 
 * Revision history:    21/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef KEYPAD_H
#define	KEYPAD_H

/*******************************************************************************
 *                             Included libraries
 /******************************************************************************/
#include "stdtypes.h"

/*******************************************************************************
 *                            Functions Prototype
 /******************************************************************************/

/*******************************************************************************
 * Function Name:	KeyPad_Initialization
 *
 * Description: 	Initialize KeyPad with Configured mode
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
extern void KeyPad_Initialization(void);

/*******************************************************************************
 * Function Name:	KeyPad_getPressedKey
 *
 * Description: 	Return value of pressed key
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			pressed key (uint8)
 *******************************************************************************/
extern uint8 KeyPad_getPressedKey(void);

#endif	/* KEYPAD_H */

