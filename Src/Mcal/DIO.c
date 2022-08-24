/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.c
 *       Module:  DIO
 *
 *  Description:  header file for Dio Module    
 *  
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_REGISTERS.h"
#include "Dio.h"



/**********************************************************************************************************************
 *  FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Dio_ReadChannel(Dio_ChannelType ChannelId)                                      
* \Description     : return the data in specified bin in the specified register                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                    
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    // getting which port do you want to read this bin from by divide the value of the channelId by 8 as each port has 8 channels 
    uint8 PortType = ChannelId / 8; 
    // getting which bin in the port( 0 t0 7 ) by get the reminder of the channel id by 8  
    uint8 ChannelNumber = ChannelId % 8; 
    return GPIO_DATA(ChannelNumber, PortType); // return the data in specified bin in the specified register
}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)                                      
* \Description     : to write a specific level to a specific channel in a port                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId, Dio_LevelType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    // getting which port do you want to read this bin from by divide the value of the channelId by 8 as each port has 8 channels 
    uint8 PortType = ChannelId / 8; 
    // getting which bin in the port( 0 t0 7 ) by get the reminder of the channel id by 8  
    uint8 ChannelNumber = ChannelId % 8; 

    GPIO_DATA(ChannelNumber, PortType) = Level;
}

/******************************************************************************
* \Syntax          : void Dio_ReadPort(Dio_PortType PortType)                                    
* \Description     : get the value in the data register in specefied port                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_PortType PortType                     
* \Parameters (out): Dio_PortLevelType                                                     
* \Return value:   : Dio_PortLevelType
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortType)
{
    
    return GPIO_PORT_DATA(PortType);// get the value in the data register in specefied port
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)                                      
* \Description     : write a specific value in the in the specified data port register                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_PortType PortId, Dio_PortLevelType Level                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{

    GPIO_PORT_DATA(PortId) = Level;//write a specific value in the in the specified data port register 
}

/******************************************************************************
* \Syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelId)                                      
* \Description     : change the value of a specified bit from high to low or low to high                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Dio_ChannelType ChannelId                     
* \Parameters (out): Dio_LevelType                                                      
* \Return value:   : Dio_LevelType
*******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{

     // getting which port do you want to read this bin from by divide the value of the channelId by 8 as each port has 8 channels 
    uint8 PortType = ChannelId / 8; 
    // getting which bin in the port( 0 t0 7 ) by get the reminder of the channel id by 8  
    uint8 ChannelNumber = ChannelId % 8; 
    Dio_LevelType Level = GPIO_DATA(ChannelNumber, PortType);
    Level ^= Level;
    GPIO_DATA(ChannelNumber, PortType) = Level;
    return Level ;

}





/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/ 