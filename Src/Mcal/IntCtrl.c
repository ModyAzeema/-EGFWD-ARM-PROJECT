/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_REGISTERS.h"
#include "IntCtrl.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
	*  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCtrl_Init(void)
{
	uint8 numOfGpPri 							= NUM_OF_GROUP_PRI_SELECTOR;
	uint8 i 									= 0;
	uint8 PriValue								= 0;
	uint8 RegIndex 								= 0;
	uint8 BitOffset 							= 0;
	uint8 IRQ_Num 								= 0;
	IntCtrl_InterruptType IntName 				= 0;
	uint8 GroupPri 								= 0;
	uint8 SubGroupPri 							= 0;
	
	/*Enable/Disable Global Interrupt*/
	#if(ENABLE_GLOBAL_INTERRUPT == 1)
		__asm
			(
				"CPSIE i \n"
			);
	#else
		__asm
			(
				"CPSID i \n"
			);
	#endif
	
	/*Configure Grouping\SubGrouping (NUM_OF_GROUP_PRI_SELECTOR) System in APINT register in SCB*/
	switch(numOfGpPri)
	{
		case 1:
			APINT = APINT_VECTKEY|(0x7<<8);
			break;
		case 2:
			APINT = APINT_VECTKEY|(0x6<<8);
			break;
		case 4:
			APINT = APINT_VECTKEY|(0x5<<8);
			break;
		case 8:
			APINT = APINT_VECTKEY|(0x0<<8);
			break;

		/*if the user set invalid number then the default will be set to 8 GP and 0 SubGP*/
		default:
			APINT = APINT_VECTKEY|(0x0<<8);
			break;
	}
	
	/*##############################################################################
			looping through the number of interrupts needed to set their configrations 
	################################################################################*/

	for(i=0; i<NUM_OF_ACTIVE_INTERRUPT; i++)
	{
		IntName = IntCtrl_Cfg_UserArray[i].IntCtrl_Name; // getting the interrupt name 
		GroupPri = IntCtrl_Cfg_UserArray[i].IntCtrl_GroupPri; // getting the value of group periority
		SubGroupPri = IntCtrl_Cfg_UserArray[i].IntCtrl_SubGroupPri; // getting the value of the subgroup periority
		
		/*******************************************************
				check for valid Group and Sub-Group Priorities
		******************************************************/
		if((numOfGpPri == 8)) 
		{
			if(GroupPri > 7)
			{
				SubGroupPri = 0;
				GroupPri = 7;
			}
			PriValue = (GroupPri << 5);
		}
		else if(numOfGpPri == 4)
		{
			if(GroupPri > 3)
			{
				GroupPri = 3;
			}
			if(SubGroupPri > 1)
			{
				SubGroupPri = 1;
			}
			PriValue = (GroupPri << 6)|(SubGroupPri << 5);
		}
		else if(numOfGpPri == 2) 
		{
			if(GroupPri > 1)
			{
				GroupPri = 1;
			}
			if(SubGroupPri > 3)
			{
				SubGroupPri = 3;
			}
			PriValue = (GroupPri << 7)|(SubGroupPri << 5);
		}
		else if(numOfGpPri == 1)
		{
			if(SubGroupPri > 7)
			{
				SubGroupPri = 7;
				GroupPri = 0;
			}
			PriValue = (SubGroupPri << 5);
		}
		else
		{
			/*INVALID Number of Group priority */
		}
		
		if(IntName < 16)
		{
			/*Set Priority for Exceptions and Faults and then Enable it*/
			switch(IntName)
			{
				case IntCtrl_USAGE_FAULT:
					SYSPRI1 |= (PriValue << 16); 
					SETBIT(SYSHNDCTRL,18);
					break;
				case IntCtrl_BUS_FAULT:
					SYSPRI1 |= (PriValue << 8); 
					SETBIT(SYSHNDCTRL,17);
					break;
				case IntCtrl_MEM_MANAGE:
					SYSPRI1 |= PriValue; 
					SETBIT(SYSHNDCTRL,16);
					break;
				case IntCtrl_SVCALL:
					SYSPRI2 |= (PriValue << 24);
					break;
				case IntCtrl_SYSTICK:
					SYSPRI3 |= (PriValue << 24);
					break;
				case IntCtrl_PENDSV:
					SYSPRI3 |= (PriValue << 16);
					break;
				case IntCtrl_DEBUG_MONITOR:
					SYSPRI3 |= PriValue;
					break;
				default:
					break;
			}
		}
		
		else
		{
			IRQ_Num = (uint8)IntName - 16; /*get the interrupt request number "IRQ" */
			/*Set interrupt Priority*/
			RegIndex = IRQ_Num / 4;
			BitOffset = ((IRQ_Num % 4) * 8); /*there is no need to add 5 as I already shifted the value by 5 previously*/
			PRI(RegIndex) |= PriValue << BitOffset ;
	
			/*Enable Interrupts*/
			RegIndex = IRQ_Num / 32;
			BitOffset = IRQ_Num % 32;
			SETBIT(EN(RegIndex),BitOffset); 
		}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/