/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        file: Timer.c
 *        brief: containing all funcrions needed to set the timer 
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "TM4C123GH6PM_REGISTERS.h"
#include "Timer.h"
#include "DIO.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/*################################################
			define all possible states of the timer
###################################################*/

#define GPT_UNINT_STATE							0
#define GPT_INIT_STATE							1
#define GPT_RUNNING_STATE						2
#define GPT_STOPPED_STATE						3
#define GPT_EXPIRED_STATE						4

/*#######################################
	system features 
*###################################/

#define DEFAULT_SYS_FREQ 						16
#define NUM_OF_AVAILABLE_CHANNELS	        	12


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static uint8 TimerState[NUM_OF_AVAILABLE_CHANNELS] = {GPT_UNINT_STATE};// to strore the sttate of the timer 
static uint8 PreScalVal[NUM_OF_AVAILABLE_CHANNELS]; // prescale value to every timer channel
static const Gpt_ConfigType* LocalConfigPtr = NULL_PTR ; // pointer to the stract of the congigrations 


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static uint8 Gpt_GetPreScalerValue(uint32 DivVal);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : to init the specified timer with the specified configrations                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{
	LocalConfigPtr = ConfigPtr; 
	uint8 i = 0;
	Gpt_ChannelType ChId = 0;
	Gpt_ModeType Mode = GPT_CH_MODE_CONTINUOUS;
	Gpt_ValueType MaxVal = 0;
	uint8 TimerFreq = 0;
	
	/*Predefined Timers WT0_B --> Channel 6*/
	#if((GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON) || (GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON) || (GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON) || (GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON))
		
		/*Ensure the timer is disabled 
		(the TnEN bit in the GPTMCTL register is cleared) before makingany changes*/

		//1- Disable Timer B --> CLR TBEN
		CLRBIT(GPTMCTL(6), 8);

		//2- Individual Mode --> GPTMCFG = 0x4
		GPTMCFG(6) |= 0x4;

		//3- Configure Timer Mode --> TAMR = 0x1 for One Shot and 0x2 for Periodic
		GPTMTBMR(6) |= GPT_CH_MODE_CONTINUOUS;

		
		/*4- Choose Countup --> SET TBCDIR*/
		/*Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).*/
		SETBIT(GPTMTBMR(6), 4);

		/*5- Diable Time Out Interrupt (Interrupt Masking)  CLR TBTOIM*/
		CLRBIT(GPTMIMR(6),	8);

		/*6- Load Timer Value with Max Value*/
		GPTMTBILR(6) = 0xFFFFFFFF;
		/*7- Start Timer B -- > SET TBEN*/
		SETBIT(GPTMCTL(6), 8);
	#endif
	
	if(LocalConfigPtr != NULL_PTR)
	{
		/*Start Timers Configuration*/
		for(i = 0; i < NUM_OF_ACTIVATED_TIMERS; i++)
		{
			
			
			/*Extract config Data of Struct i*/
			ChId 					= 	LocalConfigPtr[i].GptChannelId;
			Mode		 			= 	LocalConfigPtr[i].ChannelMode;
			MaxVal	 			= 	LocalConfigPtr[i].GptChannelTickValueMax;
			TimerFreq 		= 	LocalConfigPtr[i].GptGptChannelTickFrequency;
			PreScalVal[ChId] = 	Gpt_GetPreScalerValue ((DEFAULT_SYS_FREQ/TimerFreq));
			
			/*Update Timer State*/
			TimerState[ChId] = GPT_INIT_STATE;
			
			/*1.Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared)
			 before makingany changes  Disable Timer A --> CLR TAEN*/
			CLRBIT(GPTMCTL(ChId), 0);

			/*2- Individual Mode --> GPTMCFG = 0x4*/
			GPTMCFG(ChId) |= 0x4;
			
			/*
			3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR):
								a. Write a value of 0x1 for One-Shot mode.
								b. Write a value of 0x2 for Periodic mode.
			*/
			GPTMTAMR(ChId) |= Mode;


			/*4. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR).
				 Choose Countup --> SET TACDIR*/
			SETBIT(GPTMTAMR(ChId), 4);

			/*5. Diable Time Out Interrupt (Interrupt Masking)  CLR TATOIM*/
			CLRBIT(GPTMIMR(ChId),	0);
			
		}
	}
}


void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
	/*
	Diable Time Out Interrupt (Interrupt Masking)  CLR TATOIM*/
	
	/*CLR TATOIM in IM Register*/
	CLRBIT(GPTMIMR(Channel),	0);
	
}


void Gpt_EnableNotification(Gpt_ChannelType Channel  )
{
	/*set the appropriate bits in the GPTM Interrupt Mask Register(GPTMIMR)
											Set TATOIM in IM Register*/
	SETBIT(GPTMIMR(Channel),	0);
}


void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
	uint8 ConfigStructIndex = 0;
	/*check if the timer is already running*/
	if(TimerState[Channel] != GPT_RUNNING_STATE)
	{
		/*Update Timer State*/
		TimerState[Channel] = GPT_RUNNING_STATE;
		/*Get Index*/
		while(Channel != LocalConfigPtr[ConfigStructIndex].GptChannelId)
		{
			ConfigStructIndex++;
			if(ConfigStructIndex > 11)
			{
				/*INVALID Channel Number*/
				break;
			}
		}
		
		if((ConfigStructIndex < 12) && (Value <= LocalConfigPtr[ConfigStructIndex].GptChannelTickValueMax))
		{	
			//Set Target Counts
			GPTMTAILR(Channel) = Value;

			///Start Timer --> SET TAEN
			SETBIT(GPTMCTL(Channel), 0);
		}
		else
		{
			/*INVALID Channel Number or Value Exceeds Configures Max Value*/
		}
	}
	else
	{
		/*Can't Rerun a Running Channel*/
	}
	
}


void Gpt_StopTimer(Gpt_ChannelType Channel)
{
	if(TimerState[Channel] == GPT_RUNNING_STATE)
	{
		TimerState[Channel] = GPT_STOPPED_STATE;
		/*1. Disable Timer A --> CLR TAEN*/
			CLRBIT(GPTMCTL(Channel), 0);
	}
	else
	{
		//Try To Stop Timer From INVALID State
	}
	
}


Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
	Gpt_ValueType CurrentCount = 0;
	uint8 ShiftValue = 0;
	/*16-bit Channels --> PreScaler up to 2^8 */
	if((Channel >= 0)  && (Channel < 5))
	{
		if(PreScalVal[Channel] <= 8)
		{
			/*GPTMTAV(0:15) --> Timer_A and GPTMTAV(16:23) --> Pre-scaler*/
			/*1.Shift Right Timer_A, 2. Take firt 16 bits*/
			CurrentCount = (GPTMTAV(Channel)>> PreScalVal[Channel]) & (0x0000FFFF);
		}
		else
		{
			/*Prescaler exceeds 8 bits */
			CurrentCount = (GPTMTAV(Channel) &(0x0000FFFF));
		}
	}
	/*32-bit Channels --> Prescaler up to 2^16*/
	else if ((Channel > 5) && (Channel <12) )
	{
		/*GPTMTAV(0:31) --> Timer_A and GPTMTAPV(0:16) --> Pre-Scaler*/
		/*1. Shift Right Timer_A, 2. Git the required prescaler bits, 3. Correct the prescaler bits positions, 4. Concatenate the two registers*/
		CurrentCount = (PreScalVal[Channel]!=0)?(GPTMTAV(Channel) >> PreScalVal[Channel]) | ((GPTMTAPV(Channel) & PreScalVal[Channel]) << (31-PreScalVal[Channel])):GPTMTAV(Channel);
	}
	else
	{
		/*INVALID Channel Number*/
	}
	return CurrentCount;
}


Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
	Gpt_ValueType RemaingCount = 0;
	if((Channel >= 0) && (Channel < 12))
	{
		RemaingCount = GPTMTAILR(Channel) - Gpt_GetTimeElapsed(Channel);
	}
	else
	{
		/*INVALID Channel Number*/
	}
	return RemaingCount;
}


Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr)
{
	uint8 preScaler = 4; /*for 1us Using DEFAULT_SYS_FREQ = 16 MHz*/
	Std_ReturnType RetVal = E_OK;
	switch (PredefTimer)
	{
		case GPT_PREDEF_TIMER_1US_16BIT:
			#if(GPT_PREDEF_TIMER_1US_16BIT_ENABLE == STD_ON)
				*(TimeValuePtr) = ((GPTMTBV(6) >> preScaler) | ((GPTMTBPV(6) & preScaler << (31 - preScaler))) & (0x0000FFFF));
			#else
				RetVal = E_NOT_OK;
			#endif
			break;
		case GPT_PREDEF_TIMER_1US_24BIT:
			#if(GPT_PREDEF_TIMER_1US_24BIT_ENABLE == STD_ON)
				*(TimeValuePtr) = ((GPTMTBV(6) >> preScaler) | ((GPTMTBPV(6) & preScaler << (31 - preScaler))) & (0x00FFFFFF));
			#else
				RetVal = E_NOT_OK;
			#endif
			break;
		case GPT_PREDEF_TIMER_1US_32BIT:
			#if(GPT_PREDEF_TIMER_1US_32BIT_ENABLE == STD_ON)
				*(TimeValuePtr) = ((GPTMTBV(6) >> preScaler) | ((GPTMTBPV(6) & preScaler << (31 - preScaler))));
			#else
				RetVal = E_NOT_OK;
			#endif
			break;
		case GPT_PREDEF_TIMER_100US_32BIT:
			#if(GPT_PREDEF_TIMER_100US_32BIT_ENABLE == STD_ON)
				preScaler = 14; /*16384 counts -- > 1 count */
				*(TimeValuePtr) = ((GPTMTBV(6) >> preScaler) | ((GPTMTBPV(6) & preScaler << (31 - preScaler))));
			#else
				RetVal = E_NOT_OK;
			#endif
			break;
		default:
			/*INVALID Pre-defined Timer*/
			RetVal = E_NOT_OK;
			break;
		
	}
	
	return RetVal;
}


/*Considered to be the Timer ISR*/
void Gpt_Notification_0(void)
{
	Dio_FlipChannel(GPIO_F_CHANNEL_1);
} 
void Gpt_Notification_1(void)
{
	
} 
void Gpt_Notification_2(void)
{
	
} 
void Gpt_Notification_3(void)
{
	
} 
void Gpt_Notification_4(void)
{
	
} 
void Gpt_Notification_5(void)
{
	
} 
void Gpt_Notification_6(void)
{
	
} 
void Gpt_Notification_7(void)
{
	
} 
void Gpt_Notification_8(void)
{
	
} 
void Gpt_Notification_9(void)
{
	
} 
void Gpt_Notification_10(void)
{
	
} 
void Gpt_Notification_11(void)
{
	
} 

static uint8 Gpt_GetPreScalerValue(uint32 DivVal)
{
	uint8 PreVal = 0;
	switch (DivVal)
	{
		case 0:
		case 1:
			PreVal = 0;
			break;
		case 2:
			PreVal = 1;
			break;
		case 4:
			PreVal = 2;
			break;
		case 8:
			PreVal = 3;
			break;
		case 16:
			PreVal = 4;
			break;
		case 32:
			PreVal = 5;
			break;
		case 64:
			PreVal = 6;
			break;
		case 128:
			PreVal = 7;
			break;
		case 256:
			PreVal = 8;
			break;
		case 512:
			PreVal = 9;
			break;
		case 1024:
			PreVal = 10;
			break;
		case 2048:
			PreVal = 11;
			break;
		case 4096:
			PreVal = 12;
			break;
		case 8192:
			PreVal = 13;
			break;
		case 16384:
			PreVal = 14;
			break;
		case 32768:
			PreVal = 15;
			break;
		case 65536:
			PreVal = 16;
			break;
		default:
			break;
	}
	return PreVal;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/