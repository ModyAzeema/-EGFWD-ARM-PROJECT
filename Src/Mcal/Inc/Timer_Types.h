/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_TYPES_H
#define TIMER_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPT_CH_MODE_ONESHOT				0x1
#define GPT_CH_MODE_CONTINUOUS 			0x2
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint32 	Gpt_ValueType;			/*number of ticks reading/writing*/
typedef uint8 	Gpt_ModeType;			/*GPT_CH_MODE_CONTINUOUS or GPT_CH_MODE_ONESHOT*/
 
typedef enum
{
	Gpt_Channel_0,
	Gpt_Channel_1,
	Gpt_Channel_2,
	Gpt_Channel_3,
	Gpt_Channel_4,
	Gpt_Channel_5,
	Gpt_Channel_6,
	Gpt_Channel_7,
	Gpt_Channel_8,
	Gpt_Channel_9,
	Gpt_Channel_10,
	Gpt_Channel_11
}Gpt_ChannelType;

typedef enum 
{
	GPT_PREDEF_TIMER_1US_16BIT,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT	
}Gpt_PredefTimerType;

typedef struct
{
	Gpt_ChannelType			GptChannelId;
	uint8					GptGptChannelTickFrequency; /*It should depend on the System Freq Value from MCU dirver settings*/
	Gpt_ValueType			GptChannelTickValueMax;			
	Gpt_ModeType			ChannelMode;
	void(*GptNotification)(void);
	
}Gpt_ConfigType;


 
#endif  /* TIMER_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/