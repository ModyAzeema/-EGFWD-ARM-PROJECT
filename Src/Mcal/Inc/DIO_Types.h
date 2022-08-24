/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_TYPES_H
 *       Module:  DIO
 *
 *  Description:  have defination of all DIO Channels and ports   
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"




/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Dio_LevelType;				/*LOW or HIGH*/
typedef uint8 Dio_PortLevelType;			/*value from 0 --> 255*/




/********************************************************************************************
                  enum of all bins in each port
 ********************************************************************************************/ 

typedef enum 
{
    GPIO_A_CHANNEL_0,
    GPIO_A_CHANNEL_1,
    GPIO_A_CHANNEL_2,
    GPIO_A_CHANNEL_3,
    GPIO_A_CHANNEL_4,
    GPIO_A_CHANNEL_5,
    GPIO_A_CHANNEL_6,
    GPIO_A_CHANNEL_7,

    GPIO_B_CHANNEL_0,
    GPIO_B_CHANNEL_1,
    GPIO_B_CHANNEL_2,
    GPIO_B_CHANNEL_3,
    GPIO_B_CHANNEL_4,
    GPIO_B_CHANNEL_5,
    GPIO_B_CHANNEL_6,
    GPIO_B_CHANNEL_7,

    GPIO_C_CHANNEL_0,
    GPIO_C_CHANNEL_1,
    GPIO_C_CHANNEL_2,
    GPIO_C_CHANNEL_3,
    GPIO_C_CHANNEL_4,
    GPIO_C_CHANNEL_5,
    GPIO_C_CHANNEL_6,
    GPIO_C_CHANNEL_7,

    GPIO_D_CHANNEL_0,
    GPIO_D_CHANNEL_1,
    GPIO_D_CHANNEL_2,
    GPIO_D_CHANNEL_3,
    GPIO_D_CHANNEL_4,
    GPIO_D_CHANNEL_5,
    GPIO_D_CHANNEL_6,
    GPIO_D_CHANNEL_7,

    GPIO_E_CHANNEL_0,
    GPIO_E_CHANNEL_1,
    GPIO_E_CHANNEL_2,
    GPIO_E_CHANNEL_3,
    GPIO_E_CHANNEL_4,
    GPIO_E_CHANNEL_5,


    GPIO_F_CHANNEL_0=40,
    GPIO_F_CHANNEL_1,
    GPIO_F_CHANNEL_2,
    GPIO_F_CHANNEL_3,
    GPIO_F_CHANNEL_4, 
}Dio_ChannelType;

/********************************************************************************************
                                 enum of all ports names
 ********************************************************************************************/ 

typedef enum 
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
}Dio_PortType;




#endif  /* Dio_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Types.h
 *********************************************************************************************************************/