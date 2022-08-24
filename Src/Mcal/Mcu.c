/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_REGISTERS.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define CLOCK_SOURCE_FREQ       					16
#define PLL_FREQ									400
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* LocalConfigPtr = NULL_PTR ;
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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType * ConfigPtr)        
* \Description     : Initialize local configuration pointe                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mcu_ConfigType   Pointer to the configuration structure                 
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Mcu_Init(const Mcu_ConfigType* ConfigPtr)
{
	/*set the Local Configuration Pointer*/
	LocalConfigPtr = ConfigPtr;
}
/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue(void)        
* \Description     : Get the Reset Caues                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                 
* \Parameters (out): Mcu_RawResetType                                                      
* \Return value:   : Mcu_RawResetType EXT_RESET             
                                      MCU_POR_RESET		
                                      MCU_BORWN_OUT_RESET 
                                      MCU_WD0_RESET       
                                      MCU_SW_RESET        
                                      MCU_WD1_RESET       
                                      MOSC_FAIL_RESET     
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	Mcu_RawResetType Mcu_ResetCause = 0x0;
	switch (RESC)
	{
		case 0x1:
		Mcu_ResetCause = EXT_RESET;
		break;
		case 0x2:
		Mcu_ResetCause = MCU_POR_RESET;
		break;
		case 0x4:
		Mcu_ResetCause = MCU_BORWN_OUT_RESET;
		break;
		case 0x8:
		Mcu_ResetCause = MCU_WD0_RESET;
		break;
		case 0x10:
		Mcu_ResetCause = MCU_SW_RESET;
		break;
		case 0x20:
		Mcu_ResetCause = MCU_WD1_RESET;
		break;
		case 0x10000:
		Mcu_ResetCause = MOSC_FAIL_RESET;
		break;
		default:
		/*More than one reset happened without clearing the register*/
		/*Clear all the register*/
		RESC = 0x0;
		break;
	}
	CLRBIT(RESC,Mcu_ResetCause);
	return Mcu_ResetCause;
}


/******************************************************************************
* \Syntax          : void Mcu_PerformReset(void)        
* \Description     : Perform Software System Reset                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): Std_ReturnType                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void Mcu_PerformReset(void)
{
	/*Set SYSRESREQ in APINT*/
	APINT = (APINT_VECTKEY)|(0x1<<2);
	
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)       
* \Description     : choose the Clock Configuration Type                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mcu_ClockType   Configured clockType                     
* \Parameters (out): Std_ReturnType                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting)
{	
	Std_ReturnType retVal = E_OK;
	uint8 ClockSource =  LocalConfigPtr->Mcu_ClockSettingsCfg_Ptr[ClockSetting].Mcu_ClockSource;
	uint8 PLLState = LocalConfigPtr->Mcu_ClockSettingsCfg_Ptr[ClockSetting].Mcu_PllState;
	uint8 FreqVal = LocalConfigPtr->Mcu_ClockSettingsCfg_Ptr[ClockSetting].Mcu_Freq;
	uint8 DivVal = 1;
	/*Check for valid ClockSetting Mode*/
	if(ClockSetting < NUM_OF_CLOCK_CONFIG_MODES)
	{
		/*Overwrite on RCC using RCC2*/
		RCC2->B.USERCC2 = 0x1;
		/*Get Clock Source PIOSC or MOSC*/
		RCC->B.OSCSRC = ClockSource;
		RCC2->B.OSCSRC2 = ClockSource;
		/*PLL use*/
		switch(PLLState)
		{
			case PLL_ENABLED:
				/*1. Disable PLL*/
				RCC->B.BYPASS = 0x1;
				RCC2->B.BYPASS2 = 0x1;
				RCC->B.PWRDN = 0x1;
				RCC2->B.PWRDN2 = 0x1;
				RCC->B.USESYSDIV = 0x0;
				/*2. Set XTAL and Power PLL*/
				RCC->B.PWRDN = 0x0;
				RCC2->B.PWRDN2 = 0x0;
				/*3. Set System Freq*/
				if(FreqVal <= 80)
				{
					RCC2->B.DIV400 =0x1; 				/*to extended the division field*/
					DivVal = PLL_FREQ / FreqVal;			
					RCC2->B.SYSDIV2LSB = 0x0;			/*Clear 7-bit SysDiv*/
					RCC2->B.SYSDIV2 = 0x0;
					RCC2->R |= ((DivVal-1) << 22 );
					RCC->B.USESYSDIV = 0x1;
				}
				else
				{
					/*INVALID INPUT FREQ*/
					FreqVal = 80;
					RCC2->B.DIV400 =0x1;					/*to extended the division field*/
					RCC2->B.SYSDIV2LSB = 0x0;				/*Clear 7-bit SysDiv*/
					RCC2->B.SYSDIV2 = 0x0;
					RCC2->R |= (4 << 22); 					/*((400/5) - 1)*/
					RCC->B.USESYSDIV = 0x1;
					retVal = E_NOT_OK;
				}
				/*4. Enable PLL*/
				while(GETBIT(RIS,6) == 0); /*wait for PLL to reach Lock State*/
				RCC->B.BYPASS = 0x0;
				RCC2->B.BYPASS2 = 0x0;
				break;
			case PLL_DISABLED:
				/*1. Disable PLL*/
				RCC->B.BYPASS = 0x1;
				RCC2->B.BYPASS2 = 0x1;
				RCC->B.PWRDN = 0x1;
				RCC2->B.PWRDN2 = 0x1;
				/*2. Set System Freq*/
				DivVal = CLOCK_SOURCE_FREQ / FreqVal;
				DivVal = (DivVal == 0) ? DivVal : DivVal-1;/*for Freq Less than 16 it will be automatically set to 0 -- > the same clock source*/
				RCC->B.SYSDIV = DivVal; 
				RCC2->B.SYSDIV2 = DivVal; 
				RCC->B.USESYSDIV = 0x1;
				break;
			default:
				/*INVALID PLL STATE*/
				retVal = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*INVALID Clock Setting Mode*/
		retVal = E_NOT_OK;
	}
	return retVal;
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock(void)       
* \Description     : Set Corresponding Pripheral Clock                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock(void)
{
	uint8 RegIndex = 0x0;
	uint8 BitOffset = 0x0;
	uint8 i = 0;
	for(i = 0; i < NUM_OF_ACTIVATED_PRIPHERALS; i++)
	{
		/*As the Mcu_ClockGatesCfgType enum is aligned at 8*/
		RegIndex = (LocalConfigPtr->Mcu_ClockGates_Ptr[i]) / 8;
		BitOffset = (LocalConfigPtr->Mcu_ClockGates_Ptr[i]) % 8;
		SETBIT(RCGC_PRIPH(RegIndex),BitOffset);
	}
	return E_OK;
}
/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus(void)        
* \Description     : Get PLL State (the user should pool on until lock before distribute the Pripherals clock)                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): Mcu_PllStatusType                                                      
* \Return value:   : Mcu_PllStatusType  MCU_PLL_STATE_LOCKED
										MCU_PLL_STATE_UNLOCKED
*                                                                    
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
	uint8 PllStateVal = GETBIT(PLLSTAT,0);
	return PllStateVal;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/