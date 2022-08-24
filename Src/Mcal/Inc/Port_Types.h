/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  	Port_Types.h
 *       Module: 	Port Driver
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"


/***********************************************************************************************
 * 		definations of pins configration parameters 
***************************************************************************/

#define PIN_DIR_IN							0x0
#define PIN_DIR_OUT							0x1
#define PIN_DIR_DEFAULT						0x2

#define PIN_ATTATCH_PUR						0x0
#define PIN_ATTATCH_PDR						0x1
#define PIN_ATTATCH_ODR						0x2
#define PIN_ATTATCH_DEFAULT					0x3

#define PIN_CURRENT_2mA						0x0
#define PIN_CURRENT_4mA						0x1
#define PIN_CURRENT_8mA						0x2
#define PIN_CURRENT_DEFAULT					0x3

#define PIN_LEVEL_DEFAULT					0x2


/*PORTA_PIN0*/		
#define PINA0_MODE_U0RX						0x1
#define PINA0_MODE_CAN1RX					0x8

/*PORTA_PIN1*/		
#define PINA1_MODE_U0TX						0x1				
#define PINA1_MODE_CAN1TX           		0x8

/*PORTA_PINA2*/                     	
#define PINA2_MODE_SSI0CLK          	  	0x2

/*PORTA_PINA3*/                     	
#define PINA3_MODE_SSI0FSS          	  	0x2

/*PORTA_PIN4*/		
#define PINA4_MODE_SSI0RX           	  	0x2

/*PORTA_PIN5*/                    		
#define PINA5_MODE_SSI0TX           	  	0x2

/*PORTA_PIN6*/		
#define PINA6_MODE_I2C1SCL          	  	0x3
#define PINA6_MODE_M1PWM2           	  	0x5

/*PORTA_PIN7*/		
#define PINA7_MODE_I2C1SDA          	  	0x3
#define PINA7_MODE_M1PWM3           	  	0x5

/*PORTB_PIN0*/		
#define PINB0_MODE_USB0ID           	  	0x0 /*Give 0 for any analog Functionality and check for DEN value first*/
#define PINB0_MODE_U1RX             	  	0x1
#define PINB0_MODE_T2CCP0           	  	0x7

/*PORTB_PIN1*/		
#define PINB1_MODE_USB0VBUS         	  	0x0
#define PINB1_MODE_U1TX             	  	0x1
#define PINB1_MODE_T2CCP1           	  	0x7

/*PORTB_PIN2*/                     		
#define PINB2_MODE_I2C0SCL          	  	0x3
#define PINB2_MODE_T2CCP0           	  	0x7

/*PORTB_PIN3*/                      		
#define PINB3_MODE_I2C0SDA          	  	0x3
#define PINB3_MODE_T2CCP1           	  	0x7

/*PORTB_PIN4*/                      		
#define PINB4_MODE_AIN10            	  	0x0
#define PINB4_MODE_SSI2CLK          	  	0x2
#define PINB4_MODE_M0PWM2           	  	0x4
#define PINB4_MODE_T1CCP0           	  	0x7
#define PINB4_MODE_CAN0RX           	  	0x8

/*PORTB_PIN5*/                     		
#define PINB5_MODE_AIN11            	  	0x0
#define PINB5_MODE_SSI2FSS          	  	0x2
#define PINB5_MODE_M0PWM3           	  	0x4
#define PINB5_MODE_T1CCP1           	  	0x7
#define PINB5_MODE_CAN0TX           	  	0x8

/*PORTB_PIN6*/                    		
#define PINB6_MODE_SSI2RX           	  	0x2
#define PINB6_MODE_M0PWM0           	  	0x4
#define PINB6_MODE_T0CCP0           	  	0x7

/*PORTB_PIN7*/                     		
#define PINB7_MODE_SSI2TX           	  	0x2
#define PINB7_MODE_M0PWM1           	  	0x4
#define PINB7_MODE_T0CCP1           	  	0x7

/*PORTC_PIN0*/                     		
#define PINC0_MODE_TCK_SWCLK        	  	0x1
#define PINC0_MODE_T4CCP1           	  	0x7

/*PORTC_PIN1*/ 		
#define PINC1_MODE_TMS_SWDIO        	  	0x1
#define PINC1_MODE_T4CCP0           	  	0x7

/*PORTC_PIN2*/                      		
#define PINC2_MODE_TDI              	  	0x1
#define PINC2_MODE_T5CCP0           	  	0x7

/*PORTC_PIN3*/                      		
#define PINC3_MODE_TD0_SW0          	  	0x1
#define PINC3_MODE_T5CCP1           	  	0x7

/*PORTC_PIN4*/                     		
#define PINC4_MODE_C1_NEG           	  	0x0
#define PINC4_MODE_U4RX             	  	0x1
#define PINC4_MODE_U1RX             	  	0x2
#define PINC4_MODE_M0PWM6           	  	0x4
#define PINC4_MODE_IDX1             	  	0x6
#define PINC4_MODE_WT0CCP0          	  	0x7
#define PINC4_MODE_U1RTS            	  	0x8

/*PORTC_PIN5*/                     		
#define PINC5_MODE_C1_POS           	  	0x0
#define PINC5_MODE_U4TX             	  	0x1
#define PINC5_MODE_U1TX             	  	0x2
#define PINC5_MODE_M0PWM7           	  	0x4
#define PINC5_MODE_PhA1             	  	0x6
#define PINC5_MODE_WT0CCP1          	  	0x7
#define PINC5_MODE_U1CTS            	  	0x8

/*PORTC_PIN6*/                    		
#define PINC6_MODE_C0_POS           	  	0x0
#define PINC6_MODE_U3RX             	  	0x1
#define PINC6_MODE_PhB1             	  	0x6
#define PINC6_MODE_WT1CCP0          	  	0x7
#define PINC6_MODE_USB0EPEN         	  	0x8
		
/*PORTC_PIN7*/                      		
#define PINC7_MODE_C0_NEG           	  	0x0
#define PINC7_MODE_U3TX             	  	0x1
#define PINC7_MODE_WT1CCP1          	  	0x7
#define PINC7_MODE_USB0PFLT         	  	0x8

/*PORTD_PIN0*/                      		
#define PIND0_MODE_AIN7             	  	0x0
#define PIND0_MODE_SSI3CLK          	  	0x1
#define PIND0_MODE_SSI1CLK          	  	0x2
#define PIND0_MODE_I2C3SCL          	  	0x3
#define PIND0_MODE_M0PWM6           	  	0x4
#define PIND0_MODE_M1PWM0           	  	0x5
#define PIND0_MODE_WT2CCP0          	  	0x7

/*PORTD_PIN1*/                      		
#define PIND1_MODE_AIN6             	  	0x0
#define PIND1_MODE_SSI3FSS          	  	0x1
#define PIND1_MODE_SSI1FSS          	  	0x2
#define PIND1_MODE_I2CSDA           	  	0x3
#define PIND1_MODE_M0PMW7           	  	0x4
#define PIND1_MODE_M1PMW1           	  	0x5
#define PIND1_MODE_WT2CCP1          	  	0x7

/*PORTD_PIN2*/                      		
#define PIND2_MODE_AIN5             	  	0x0
#define PIND2_MODE_SSI3RX           	  	0x1
#define PIND2_MODE_SSI1RX           	  	0x2
#define PIND2_MODE_M0FAULT0         	  	0x4
#define PIND2_MODE_WT3CCP0          	  	0x7
#define PIND2_MODE_UDB0EPEN         	  	0x8

/*PORTD_PIN3*/                      		
#define PIND3_MODE_AIN4             	  	0x0
#define PIND3_MODE_SSI3TX           	  	0x1
#define PIND3_MODE_SSI1TX           	  	0x2
#define PIND3_MODE_IDX0             	  	0x6
#define PIND3_MODE_WT3CCP1          	  	0x7
#define PIND3_MODE_USB0PFLT         	  	0x8

/*PORTD_PIN4*/                    	  	
#define PIND4_MODE_USB0DM           	  	0x0
#define PIND4_MODE_U6RX             	  	0x1
#define PIND4_MODE_WT4CCP0          	  	0x7

/*PORTD_PIN5*/                    	 	
#define PIND5_MODE_USB0DP           	  	0x0
#define PIND5_MODE_U6TX             	  	0x1
#define PIND5_MODE_WT4CCP1          	  	0x7

/*PORTD_PIN6*/                      		
#define PIND6_MODE_U2RX             	  	0x1
#define PIND6_MODE_M0FAULT0         	  	0x4
#define PIND6_MODE_PhA0             	  	0x6
#define PIND6_MODE_WT5CCP0          	  	0x7

/*PORTD_PIN7*/                      		
#define PIND7_MODE_U2TX             	  	0x1
#define PIND7_MODE_PhB0             	  	0x6
#define PIND7_MODE_WT5CCP1          	  	0x7
#define PIND7_MODE_NMI              	  	0x8

/*PORTE_PIN0*/                      		
#define PINE0_MODE_AIN3             	  	0x0
#define PINE0_MODE_U7RX             	  	0x1

/*PORTE_PIN1*/                      		
#define PINE1_MODE_AIN2             	  	0x0
#define PINE1_MODE_U7TX             	  	0x1

/*PORTE_PIN2*/                      		
#define PINE2_MODE_AIN1             	  	0x0

/*PORTE_PIN3*/                    	  	
#define PINE3_MODE_AIN0             	  	0x0

/*PORTE_PIN4*/                      		
#define PINE4_MODE_AIN9             	  	0x0
#define PINE4_MODE_U5RX             	  	0x1
#define PINE4_MODE_I2C2SCL          	  	0x3
#define PINE4_MODE_M0PWM4           	  	0x4
#define PINE4_MODE_M1PWM2           	  	0x5
#define PINE4_MODE_CAN0RX           	  	0x8

/*PORTE_PIN5*/                      		
#define PINE5_MODE_AIN8             	  	0x0
#define PINE5_MODE_U5TX             	  	0x1
#define PINE5_MODE_I2C2SDA          	  	0x3
#define PINE5_MODE_M0PWM5           	  	0x4
#define PINE5_MODE_M1PWM3           	  	0x5
#define PINE5_MODE_CAN0TX           	  	0x8

/*PORTF_PIN0*/                      		
#define PINF0_MODE_U1RTS            	  	0x1
#define PINF0_MODE_SSI1RX           	  	0x2
#define PINF0_MODE_CAN0RX           	  	0x3
#define PINF0_MODE_M1PWM4           	  	0x5
#define PINF0_MODE_PhA0             	  	0x6
#define PINF0_MODE_T0CCP0           	  	0x7
#define PINF0_MODE_NMI              	  	0x8
#define PINF0_MODE_C0o              	  	0x9

/*PORTF_PIN1*/                      		
#define PINF1_MODE_U1CTS            	  	0x1
#define PINF1_MODE_SSI1TX           	  	0x2
#define PINF1_MODE_M1PWM5           	  	0x5
#define PINF1_MODE_PhB0             	  	0x6
#define PINF1_MODE_T0CCP1           	  	0x7
#define PINF1_MODE_C1o              	  	0x9
#define PINF1_MODE_TRD0             	  	0xE
	
/*PORTF_PIN2*/                      		
#define PINF2_MODE_SSI1CLK          	  	0x2
#define PINF2_MODE_M0FAULT0         	  	0x4
#define PINF2_MODE_M1PWM6           	  	0x5
#define PINF2_MODE_T1CCP0           	  	0x7
#define PINF2_MODE_TRD0             	  	0xE

/*PORTF_PIN3*/                      		
#define PINF3_MODE_SSI1FSS          	  	0x2
#define PINF3_MODE_CAN0TX           	  	0x3
#define PINF3_MODE_M1PWM7           	  	0x5
#define PINF3_MODE_T1CCP1           	  	0x7
#define PINF3_MODE_TRCLK            	  	0xE

/*PORTF_PIN4*/                      		
#define PINF4_MODE_M1FAULT0         	  	0x5
#define PINF4_MODE_IDX0             	  	0x6
#define PINF4_MODE_T2CCP0           	  	0x7
#define PINF4_MODE_USB0EPEN         	  	0x8

/*PORTx_PINx*/
#define PIN_MODE_DIO						0x10
#define PIN_MODE_EXTINT_RAISING_EDGE		0x11
#define PIN_MODE_EXTINT_FALLING_EDGE		0x12
#define PIN_MODE_EXTINT_BOTH_EDGES			0x13
#define PIN_MODE_EXTINT_LEVEL				0x14


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  Enum that contain names of all pins in the TM4c123
 ************************************************************/
typedef enum
{
	PortA_Pin0,
	PortA_Pin1,
	PortA_Pin2,
	PortA_Pin3,
	PortA_Pin4,
	PortA_Pin5,
	PortA_Pin6,
	PortA_Pin7,
	
	PortB_Pin0,
	PortB_Pin1,
	PortB_Pin2,
	PortB_Pin3,
	PortB_Pin4,
	PortB_Pin5,
	PortB_Pin6,
	PortB_Pin7,
	
	PortC_Pin0,
	PortC_Pin1,
	PortC_Pin2,
	PortC_Pin3,
	PortC_Pin4,
	PortC_Pin5,
	PortC_Pin6,
	PortC_Pin7,
	
	PortD_Pin0,
	PortD_Pin1,
	PortD_Pin2,
	PortD_Pin3,
	PortD_Pin4,
	PortD_Pin5,
	PortD_Pin6,
	PortD_Pin7,
	
	PortE_Pin0,
	PortE_Pin1,
	PortE_Pin2,
	PortE_Pin3,
	PortE_Pin4,
	PortE_Pin5,
	
	PortF_Pin0=40,
	PortF_Pin1,
	PortF_Pin2,
	PortF_Pin3,
	PortF_Pin4
	
}Port_PinType;

/**********************************************************************************************************************
 *  data types used in the configrations 
 ************************************************************/

typedef uint8 Port_PinModeType;					/*PINX_MODE_X*/
typedef uint8 Port_PinDirectionType;			/*PIN_DIR_IN, PIN_DIR_OUT or PIN_DIR_DEFAULT*/
typedef uint8 Port_PinLevelType;				/*STD_LOW, STD_HIGH or PIN_LEVEL_DEFAULT*/
typedef uint8 Port_PinInternalAttachType;		/*PIN_ATTATCH_PUR, PIN_ATTATCH_PDR, PIN_ATTATCH_ODR, or PIN_ATTATCH_DEFAULT*/	
typedef uint8 Port_PinOutputCurrentType; 		/*PIN_CURRENT_2mA, PIN_CURRENT_4mA, PIN_CURRENT_8mA, or PIN_CURRENT_DEFAULT*/

/**********************************************************************************************************************
 *  struct of parameters to initaialize the port with 
 ************************************************************/
typedef struct
{
	Port_PinType					Port_PinNum;
	Port_PinModeType				PortPinMode;
	Port_PinDirectionType			PortPinDirection;
	Port_PinLevelType				PortPinLevelValue;
	Port_PinInternalAttachType		PortPinInternalAttach;
	Port_PinOutputCurrentType		PortPinOutputCurrent;
	
}Port_ConfigType;


#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/