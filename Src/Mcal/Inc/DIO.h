/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO Module   
 *  
 *********************************************************************************************************************/
#ifndef Dio_H
#define Dio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Types.h"

/**********************************************************************************************************************
 *   FUNCTION PROTOTYPES
 *********************************************************************************************************************/

//read the data in specified bin in the specified register
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

//to write a specific level to a specific channel in a port
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

//get the value in the data register in specefied port   
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

//write a specific value in the in the specified data port register 
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

//change the value of a specified bit from high to low or low to high  
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);




#endif  /* Dio_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/