/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*File:  Port.c
 *       Module:  Port driver
 *
 *  	Description:  port driver that have the init function that take an array of structs to initialize specific ports
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_REGISTERS.h"
#include "Port.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define COMMIT_UNLOCK									0x4C4F434B

/**********************************************************************************************************************
 *   FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     :function to initialize a specific port with parameters in an array os structs
                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : const Port_ConfigType* ConfigPtr
					 array of structs that have specific parameters to initialize the port 
* \Parameters (out): None                                                      
*                                  
*******************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
	Port_PinType Port_Pin = 0;
	uint8 RegOffset 	  = 0;
	uint8 BitOffset 	  = 0;
	uint8 i 			  = 0;
	Port_PinModeType	PinMode = 0;

	/*
			loop through the number of pins to be initialized 
	*/
	for(i = 0; i < NUM_OF_ACTIVATED_PINS; i++)
	{
		Port_Pin = ConfigPtr[i].Port_PinNum; // get the pin number and which port it belong
		PinMode = ConfigPtr[i].PortPinMode; // which function to do 
		RegOffset = Port_Pin / 8;           // whith port it belong to
		BitOffset  =  Port_Pin % 8;         // which pin 
		
				/*#################################################
							if it has Analog Functionality
				#################################################*/

		if(PinMode == 0) // 0 -> means it is an analog pin
		{
			/*1. Clear DEN Reqister*/
			CLRBIT(GPIO_PORT_DEN(RegOffset),BitOffset);
			/*2. SET AMSEL*/
			SETBIT(GPIO_PORT_DEN(RegOffset),0);
		}

				/*###################################################
						if it has different digital functionality than DIO
				########################################################*/
			
		else if((PinMode > 0)  && (PinMode <= 0xF))
		{
			/*
				GPIOPCTL register is used in conjunction with the GPIOAFSEL register and selects the specific
                peripheral signal for each GPIO pin when using the alternate function mode
			*/
			SETBIT(GPIO_PORT_AFSEL(RegOffset),BitOffset);
			// clear the bits according the pin needed then set it
			GPIO_PORT_PCTL(RegOffset) &= ~(0xF <<(BitOffset*4));
			GPIO_PORT_PCTL(RegOffset) |= ((ConfigPtr[i].PortPinMode)<<(BitOffset*4));
		}

				/*###################################################
							if its DIO or external inturupt
				*##################################################*/

		else if((PinMode > 0xF) && (PinMode < 0x15))
		{
			/*1- Commit Control (Unlock Ports if needed)*/
			if((Port_Pin == PortC_Pin0) || (Port_Pin == PortC_Pin1) || (Port_Pin == PortC_Pin2) || (Port_Pin == PortC_Pin3) || (Port_Pin == PortD_Pin7) || (Port_Pin == PortF_Pin0))
			{
				GPIO_PORT_LOCK(RegOffset) = COMMIT_UNLOCK;
				SETBIT(GPIO_PORT_CR(RegOffset),BitOffset);
			}
			/*2- Enabl Digital Functionality*/
			SETBIT(GPIO_PORT_DEN(RegOffset),BitOffset);
			/*3- Set DIO Direction*/
			if(ConfigPtr[i].PortPinDirection != PIN_DIR_DEFAULT)
			{
				GPIO_PORT_DIR(RegOffset) |= ((ConfigPtr[i].PortPinDirection) << BitOffset);
			}
			/*4- Set Initial Level Value*/
			if(ConfigPtr[i].PortPinLevelValue != PIN_LEVEL_DEFAULT)
			{
				GPIO_PORT_DATA(RegOffset) |= ((ConfigPtr[i].PortPinLevelValue) << BitOffset);
			}
			/*5- Set Pad Control*/

			/*if it is 
						pull up 
						or pull down 
						or open drain */

			switch(ConfigPtr[i].PortPinInternalAttach)
			{
				case PIN_ATTATCH_PDR:
					SETBIT(GPIO_PORT_PDR(RegOffset),BitOffset);
					break;
				case PIN_ATTATCH_PUR:
					SETBIT(GPIO_PORT_PUR(RegOffset),BitOffset);
					break;
				case PIN_ATTATCH_ODR:
					SETBIT(GPIO_PORT_ODR(RegOffset),BitOffset);
					break;
				default:
					break;
			}
			// set ammount of current to be on the pin 
			switch(ConfigPtr[i].PortPinOutputCurrent)
			{
				case PIN_CURRENT_2mA:
					SETBIT(GPIO_PORT_DR2R(RegOffset),BitOffset);
					break;
				case PIN_CURRENT_4mA:
					SETBIT(GPIO_PORT_DR4R(RegOffset),BitOffset);
					break;
				case PIN_CURRENT_8mA:
					SETBIT(GPIO_PORT_DR8R(RegOffset),BitOffset);
					break;
					default:
					break;
			}

			/*6- Configure AFSEL and PCTL*/
			CLRBIT(GPIO_PORT_AFSEL(RegOffset),BitOffset);
			GPIO_PORT_PCTL(RegOffset) &= ~(0xF <<(BitOffset*4)); /*CLR PCTL*/


			/******************************************************
							Handeling Eternal Interrupt 
			************************************************/
			if(PinMode > 0x10)
			{
			GPIO_PORT_PCTL(RegOffset) |= ((0xF)<<(BitOffset*4));
				switch(PinMode)
				{
					case PIN_MODE_EXTINT_LEVEL: 
						SETBIT(GPIO_PORT_IS(RegOffset),BitOffset);
						break;
					case PIN_MODE_EXTINT_RAISING_EDGE:
					case PIN_MODE_EXTINT_FALLING_EDGE:
						CLRBIT(GPIO_PORT_IS(RegOffset),BitOffset);
						CLRBIT(GPIO_PORT_IBE(RegOffset),BitOffset);
						if(PinMode == PIN_MODE_EXTINT_RAISING_EDGE)
						{
							SETBIT(GPIO_PORT_IEV(RegOffset),BitOffset);
						}
						else
						{
							CLRBIT(GPIO_PORT_IEV(RegOffset),BitOffset);
						}
						break;
					case PIN_MODE_EXTINT_BOTH_EDGES:
						CLRBIT(GPIO_PORT_IS(RegOffset),BitOffset);
						SETBIT(GPIO_PORT_IBE(RegOffset),BitOffset);
						break;
					default:
						break;
				}
			}
		}
		else
		{
			/*INVALID MODE VALUE*/
		}
			
				
	}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/