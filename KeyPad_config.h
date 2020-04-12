/*******************************************************************************
 *  
 * File:                KeyPad.h
 * 
 * Author:              Ahmed Eldakhly
 * 
 * Comments:            it contains configuration of Keypad module.
 * 
 * Revision history:    21/2/2020
 * 
 ******************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef KEYPAD_CONFIG_H
#define	KEYPAD_CONFIG_H

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define KEYPAD_3x3_TYPE             0u
#define KEYPAD_3x4_TYPE             1u
#define KEYPAD_4x3_TYPE             2u
#define KEYPAD_4x4_TYPE             3u
/*-----------------------------------------------------------------------------*/
#define KEYPAD_TYPE                 KEYPAD_4x3_TYPE
#define KEYPAD_PORT_OUT_ROW         GPIO_PORTD
#define KEYPAD_PORT_IN_COL          GPIO_PORTB

/*check the type of the keypad 3x3 */
#if KEYPAD_TYPE == KEYPAD_3x3_TYPE

#define N_ROW                       3u
#define N_COL                       3u
#define START_ROW                   2u
#define END_ROW                     START_ROW + 2u
#define START_COL                   2u
#define END_COL                     START_COL + 2u

/* key values */
#define R1_C1                       1
#define R1_C2                       2
#define R1_C3                       3

#define R2_C1                       4
#define R2_C2                       5
#define R2_C3                       6

#define R3_C1                       7
#define R3_C2                       8
#define R3_C3                       9

/*check the type of the keypad 3x4 */
#elif KEYPAD_TYPE == KEYPAD_3x4_TYPE

#define N_ROW                       3u
#define N_COL                       4u
#define START_ROW                   2u
#define END_ROW                     START_ROW + 2u
#define START_COL                   2u
#define END_COL                     START_COL + 3u

/* key values */
#define R1_C1                       1
#define R1_C2                       2
#define R1_C3                       3
#define R1_C4                       '/'

#define R2_C1                       4
#define R2_C2                       5
#define R2_C3                       6
#define R2_C4                       '*'

#define R3_C1                       7
#define R3_C2                       8
#define R3_C3                       9
#define R3_C4                       '-'

/*check the type of the keypad 4x3 */
#elif KEYPAD_TYPE == KEYPAD_4x3_TYPE

#define N_ROW                       4u
#define N_COL                       3u
#define START_ROW                   0u
#define END_ROW                     START_ROW + 3u
#define START_COL                   0u
#define END_COL                     START_COL + 2u

/* key values */
#define R1_C1                       '*'
#define R1_C2                       0
#define R1_C3                       '#'

#define R2_C1                       7
#define R2_C2                       8
#define R2_C3                       9

#define R3_C1                       4
#define R3_C2                       5
#define R3_C3                       6

#define R4_C1                       1
#define R4_C2                       2
#define R4_C3                       3

/*check the type of the keypad 4x4 */
#elif KEYPAD_TYPE == KEYPAD_4x4_TYPE

#define N_ROW                       4u
#define N_COL                       4u
#define START_ROW                   2u
#define END_ROW                     START_ROW + 3u
#define START_COL                   2u
#define END_COL                     START_COL + 3u

/* key values */
#define R1_C1                       1
#define R1_C2                       2
#define R1_C3                       3
#define R1_C4                       '/'

#define R2_C1                       4
#define R2_C2                       5
#define R2_C3                       6
#define R2_C4                       '*'

#define R3_C1                       7
#define R3_C2                       8
#define R3_C3                       9
#define R3_C4                       '-'

#define R4_C1                       13
#define R4_C2                       0
#define R4_C3                       '='
#define R4_C4                       '+'

#endif
#endif	/* KEYPAD_CONFIG_H */

