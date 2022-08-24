/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	IntCtrl_MEM_MANAGE=4,
	IntCtrl_BUS_FAULT,
	IntCtrl_USAGE_FAULT,
	IntCtrl_SVCALL=11,
	IntCtrl_DEBUG_MONITOR,
	IntCtrl_PENDSV=14,
	IntCtrl_SYSTICK,
	IntCtrl_GPIO_A,
	IntCtrl_GPIO_B,
	IntCtrl_GPIO_C,
	IntCtrl_GPIO_D,
	IntCtrl_GPIO_E,
	IntCtrl_UART0,
	IntCtrl_UART1,
	IntCtrl_SSI0,
	IntCtrl_I2C0,
	IntCtrl_PWM0_FAULT,
	IntCtrl_PWM0_G0,
	IntCtrl_PWM0_G1,
	IntCtrl_PWM0_G2,
	IntCtrl_QEI0,
	IntCtrl_ADC0_SEQ0,
	IntCtrl_ADC0_SEQ1,
	IntCtrl_ADC0_SEQ2,
	IntCtrl_ADC0_SEQ3,
	IntCtrl_WATCHDOG_TIMER,
	IntCtrl_TIMER0_A,
	IntCtrl_TIMER0_B,
	IntCtrl_TIMER1_A,
	IntCtrl_TIMER1_B,
	IntCtrl_TIMER2_A,
	IntCtrl_TIMER2_B,
	IntCtrl_ANALOG_COMP0,
	IntCtrl_ANALOG_COMP1,
	IntCtrl_SYSTEM_CONTROL=44,
	IntCtrl_FLASH_CONTROL,
	IntCtrl_GPIO_F,
	IntCtrl_UART2=49,
	IntCtrl_SSI1,
	IntCtrl_TIMER3_A,
	IntCtrl_TIMER3_B,
	IntCtrl_I2C1,
	IntCtrl_QEI1,
	IntCtrl_CAN0,
	IntCtrl_CAN1,
	IntCtrl_HIBERNATION_MODE=59,
	IntCtrl_USB,
	IntCtrl_PWM_G3,
	IntCtrl_uDMA_SW,
	IntCtrl_uDMA_ERROR,
	IntCtrl_ADC1_SEQ0,
	IntCtrl_ADC1_SEQ1,
	IntCtrl_ADC1_SEQ2,
	IntCtrl_ADC1_SEQ3,
	IntCtrl_SSI2=73,
	IntCtrl_SSI3,
	IntCtrl_UART3,
	IntCtrl_UART4,
	IntCtrl_UART5,
	IntCtrl_UART6,
	IntCtrl_UART7,
	IntCtrl_I2C2=84,
	IntCtrl_I2C3,
	IntCtrl_TIMER4_A,
	IntCtrl_TIMER4_B,
	IntCtrl_TIMER5_A=108,
	IntCtrl_TIMER5_B,
	IntCtrl_WTIMER0_A,
	IntCtrl_WTIMER0_B,
	IntCtrl_WTIMER1_A,
	IntCtrl_WTIMER1_B,
	IntCtrl_WTIMER2_A,
	IntCtrl_WTIMER2_B,
	IntCtrl_WTIMER3_A,
	IntCtrl_WTIMER3_B,
	IntCtrl_WTIMER4_A,
	IntCtrl_WTIMER4_B,
	IntCtrl_WTIMER5_A,
	IntCtrl_WTIMER5_B,
	IntCtrl_SYSTEM_EXCEPTION,
	IntCtrl_PWM1_G0=150,
	IntCtrl_PWM1_G1,
	IntCtrl_PWM1_G2,
	IntCtrl_PWM1_G3,
	IntCtrl_PWM1_FAULT
	
}IntCtrl_InterruptType;

 typedef struct 
{
	IntCtrl_InterruptType	 	IntCtrl_Name;         /*value from IntCtrl_InterruptType enum*/
	uint8					    IntCtrl_GroupPri; 		/*value from 0 to 7 and it depends on NUM_OF_GROUP_PRI_SELECTOR*/
	uint8 						IntCtrl_SubGroupPri; 	/*value from 0 to 7 and it depends on NUM_OF_GROUP_PRI_SELECTOR*/
	
}IntCtrl_CfgTpe;

#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/