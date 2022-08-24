/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MCU_PLL_STATE_LOCKED		0x1
#define MCU_PLL_STATE_UNLOCKED		0x0

#define	EXT_RESET                   0x0
#define MCU_POR_RESET				0x1
#define MCU_BORWN_OUT_RESET         0x2
#define MCU_WD0_RESET               0x3
#define MCU_SW_RESET                0x4
#define MCU_WD1_RESET               0x5
#define MOSC_FAIL_RESET             0x16

#define MOSC						0x0
#define PIOSC						0x1

#define PLL_DISABLED				0x0
#define PLL_ENABLED					0x1


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Mcu_PllStatusType;   /*LOCKED or UNLOCKED*/
typedef uint8 Mcu_RawResetType;
typedef uint8 Mcu_ClockType;       /*Index of Mcu_ClockSettingsCfgType array of structure*/


/*Configuration Data types*/
typedef struct
{
	uint8 Mcu_ClockSource;
	uint8 Mcu_PllState;
	uint8 Mcu_Freq;
	
}Mcu_ClockSettingsCfgType;

typedef enum
{
	Mcu_WDT0 = 0,
	Mcu_WDT1,
	
	Mcu_TIMER0 = 8,
	Mcu_TIMER1,
	Mcu_TIMER2,
	Mcu_TIMER3,
	Mcu_TIMER4,
	Mcu_TIMER5,
	
	Mcu_GPIO_A = 16,
	Mcu_GPIO_B,
	Mcu_GPIO_C,
	Mcu_GPIO_D,
	Mcu_GPIO_E,
	Mcu_GPIO_F,
	
	Mcu_DMA = 24,
	
	Mcu_HIB = 40,
	
	Mcu_UART0 = 48,
	Mcu_UART1,
	Mcu_UART2,
	Mcu_UART3,
	Mcu_UART4,
	Mcu_UART5,
	Mcu_UART6,
	Mcu_UART7,
	
	Mcu_SSI0 = 56,
	Mcu_SSI1,
	Mcu_SSI2,
	Mcu_SSI3,
	
	Mcu_I2C0 = 64,
	Mcu_I2C1,
	Mcu_I2C2,
	Mcu_I2C3,
	
	Mcu_USB = 80,
	
	Mcu_CAN0 = 104,
	Mcu_CAN1,
	
	Mcu_ADC0 = 112,
	Mcu_ADC1,
	
	Mcu_ACMP = 120,
	
	Mcu_PWM0 = 128,
	Mcu_PWM1,
	
	Mcu_QEI0 = 136,
	Mcu_QEI1,
	
	Mcu_EEPROM = 176,
	
	Mcu_WTIMER0 = 184,
	Mcu_WTIMER1,
	Mcu_WTIMER2,
	Mcu_WTIMER3,
	Mcu_WTIMER4,
	Mcu_WTIMER5,
	
}Mcu_ClockGatesCfgType;


/*typedef struct
{
	Mcu_ClockSettingsCfgType 	Mcu_ClockSettingsCfg[2];
	Mcu_ClockGatesCfgType 			Mcu_ClockGates[2];
	
}Mcu_ConfigType;*/
typedef struct
{
	Mcu_ClockSettingsCfgType* 	Mcu_ClockSettingsCfg_Ptr;
	Mcu_ClockGatesCfgType* 			Mcu_ClockGates_Ptr;
	
}Mcu_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/