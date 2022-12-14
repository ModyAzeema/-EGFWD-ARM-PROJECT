/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_Lcfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Gpt_ConfigType Gpt_Config[NUM_OF_ACTIVATED_TIMERS] = 
{
	{Gpt_Channel_0,		4,		4000,	GPT_CH_MODE_ONESHOT }
	
};




/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/