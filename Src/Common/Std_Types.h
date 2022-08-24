/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Std_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  standard data types used 
 *
 *********************************************************************************************************************/



#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "Platform_Types.h"
# include "Compiler.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

# define STD_HIGH     1u /* Physical state 5V or 3.3V */
# define STD_LOW      0u /* Physical state 0V */

# define STD_ACTIVE   1u /* Logical state active */
# define STD_IDLE     0u /* Logical state idle */

# define STD_ON       1u
# define STD_OFF      0u

/*
            data types 
*/

typedef unsigned char         boolean;       /*        TRUE -> FALSE           */

typedef signed char           sint8;         /*        -128 -> +127            */
typedef unsigned char         uint8;         /*           0 -> 255             */
typedef signed short          sint16;        /*      -32768 -> +32767          */
typedef unsigned short        uint16;        /*           0 -> 65535           */
typedef signed long           sint32;        /* -2147483648 -> +2147483647     */
typedef unsigned long         uint32;        /*           0 -> 4294967295      */

typedef float                 float32;
typedef double                float64;


#define SETBIT(REG,BIT) ((REG)|= (1<<(BIT))) // to set register bin bit to high
#define CLEARBIT(REG,BIT) ((REG)&= (~(1<<(BIT)))) //to set register bin bit to low
#define GETBIT(REG,BIT) ((REG) & (1<<(BIT))) // to read the value of a specific bit in a specific register
#define TOGLBIT(REG,BIT) ((REG)^= (1<<(BIT))) // to togle value of a specific bit in a specific register
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Std_ReturnType;
#define E_OK          0u
#define E_NOT_OK      1u



#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/