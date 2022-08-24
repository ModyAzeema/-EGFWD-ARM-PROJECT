/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TM4C123GH6PM_REGISTERS.h
 *       Module:  TM4C123GH6PM_REGISTERS
 *
 *  Description:  header file for Registers definition    
 *  TM4C123GH6PM_REGISTERS
 *********************************************************************************************************************/
#ifndef TM4C123GH6PM_REGISTERS
#define TM4C123GH6PM_REGISTERS

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	uint32	MOSCDIS		:1;
	uint32				:3;
	uint32	OSCSRC		:2;
	uint32	XTAL		:5;
	uint32	BYPASS		:1;
	uint32				:1;
	uint32	PWRDN		:1;
	uint32				:3;
	uint32	PWMDIV		:3;
	uint32	USEPWMDIV	:1;
	uint32				:1;
	uint32	USESYSDIV	:1;
	uint32	SYSDIV		:4;
	uint32	ACG			:1;
	uint32				:4;
	
}RCC_BF;

typedef union
{
	uint32 R;
	RCC_BF B;
}RCC_Tag;
typedef struct
{
	uint32				:4;
	uint32	OSCSRC2		:3;
	uint32				:4;
	uint32	BYPASS2		:1;
	uint32				:1;
	uint32	PWRDN2		:1;
	uint32	USBPWRDN	:1;
	uint32				:7;
	uint32	SYSDIV2LSB	:1;
	uint32	SYSDIV2		:6;
	uint32				:1;
	uint32	DIV400		:1;
	uint32	USERCC2		:1;
	
}RCC2_BF;

typedef union
{
	uint32 R;
	RCC2_BF B;
}RCC2_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/***************************************** Interrupt Controller Registers ********************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             				0xE000E000
#define ENx_BASE_ADDRESS									0xE000E100
#define DISx_BASE_ADDRESS									0xE000E180
#define PENDx_BASE_ADDRESS									0xE000E200	
#define UNPENDx_BASE_ADDRESS								0xE000E280	
#define ACTIVEx_BASE_ADDRESS								0xE000E300	
#define PRIx_BASE_ADDRESS									0xE000E400
#define APINT_VECTKEY 										0x05FA0000
	
#define EN(n)												*((volatile uint32*)(ENx_BASE_ADDRESS+0x4*(n)))
#define DIS(n)								  	 			*((volatile uint32*)(DISx_BASE_ADDRESS+0x4*(n)))
#define PEND(n)								 	  			*((volatile uint32*)(PENDx_BASE_ADDRESS+0x4*(n)))
#define UNPEND(n)								 	  		*((volatile uint32*)(UNPENDx_BASE_ADDRESS+0x4*(n)))
#define ACTIVE(n)								 	  		*((volatile uint32*)(ACTIVE_BASE_ADDRESS+0x4*(n)))
#define PRI(n)												*((volatile uint32*)(PRIx_BASE_ADDRESS+0x4*n))
#define SWTRIG												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xF00))
		
#define ACTLR												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x008))
#define CPUID												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD00))
#define INTCTRL												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define VTABLE 												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD08))
#define APINT  												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define SYSCTRL												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD10))
#define CFGCTRL												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD14))
#define SYSPRI1												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
#define SYSPRI2												*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
#define SYSPRI3                                				*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
#define SYSHNDCTRL											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
#define FAULTSTAT 											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD28))
#define HFAULTSTAT											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD2C))
#define MMADDR    											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD34))
#define FAULTADDR 											*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD38))
	
/*************************************************** MCU Registers ***************************************************/
#define SYS_CTRL_BASE_ADDRESS								0X400FE000
#define RCGC_PERPH_BASE_ADDRESS								0x400FE600
#define RIS													*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x050))
#define RESC												*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x05C))
#define RCC													((volatile RCC_Tag*)(SYS_CTRL_BASE_ADDRESS+0x060))
#define RCC2												((volatile RCC2_Tag*)(SYS_CTRL_BASE_ADDRESS+0x070))
#define PLLFREQ0											*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x160))
#define PLLFREQ1											*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x164))
#define PLLSTAT												*((volatile uint32*)(SYS_CTRL_BASE_ADDRESS+0x168))
#define RCGC_PRIPH(n)										*((volatile uint32*)(RCGC_PERPH_BASE_ADDRESS+0x4*(n)))

/*************************************************** GPIO Registers ***************************************************/
#define GPIOs_APB_BASE_ADDRESS								0X40004000UL
#define GPIO_DATA_OFFSET     								0x000003FCUL
#define GPIO_DATA_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS 
#define GPIO_DIR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x400)
#define GPIO_IS_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x404)
#define GPIO_IBE_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x408)
#define GPIO_IEV_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x40C)
#define GPIO_IM_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x410)
#define GPIO_RIS_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x414)
#define GPIO_MIS_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x418)
#define GPIO_ICR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x41C)
#define GPIO_AFSEL_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x420)
#define GPIO_DR2R_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x500)
#define GPIO_DR4R_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x504)
#define GPIO_DR8R_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x508)
#define GPIO_ODR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x50C)
#define GPIO_PUR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x510)
#define GPIO_PDR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x514)
#define GPIO_SLR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x518)
#define GPIO_DEN_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x51C)
#define GPIO_LOCK_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x520)
#define GPIO_CR_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x524)
#define GPIO_AMSEL_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x528)
#define GPIO_PCTL_BASE_ADDRESS								GPIOs_APB_BASE_ADDRESS+(0x52C)
#define GPIO_ADCCTL_BASE_ADDRESS							GPIOs_APB_BASE_ADDRESS+(0x530)
#define GPIO_DMACTL_BASE_ADDRESS							GPIOs_APB_BASE_ADDRESS+(0x534)

#define GPIO_PORTx_DATA(n)									*((volatile uint32*)(GPIO_DATA_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_DATA(n, m)										*((volatile uint32*)(GPIO_PORTx_DATA(n)+(4<<m)))
#define GPIO_PORT_DATA(n)									*((volatile uint32*)(GPIO_DATA_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))+GPIO_DATA_OFFSET))
#define GPIO_PORT_DIR(n)									*((volatile uint32*)(GPIO_DIR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_IS(n)										*((volatile uint32*)(GPIO_IS_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_IBE(n)									*((volatile uint32*)(GPIO_IBE_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_IEV(n)									*((volatile uint32*)(GPIO_IEV_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_IM(n)										*((volatile uint32*)(GPIO_IM_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_RIS(n)									*((volatile uint32*)(GPIO_RIS_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_MIS(n)									*((volatile uint32*)(GPIO_MIS_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_ICR(n)									*((volatile uint32*)(GPIO_ICR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_AFSEL(n)									*((volatile uint32*)(GPIO_AFSEL_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_DR2R(n)									*((volatile uint32*)(GPIO_DR2R_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_DR4R(n)									*((volatile uint32*)(GPIO_DR4R_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_DR8R(n)									*((volatile uint32*)(GPIO_DR8R_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_ODR(n)									*((volatile uint32*)(GPIO_ODR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_PUR(n)									*((volatile uint32*)(GPIO_PUR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_PDR(n)									*((volatile uint32*)(GPIO_PDR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_SLR(n)									*((volatile uint32*)(GPIO_SLR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_DEN(n)									*((volatile uint32*)(GPIO_DEN_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_LOCK(n)									*((volatile uint32*)(GPIO_LOCK_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_CR(n)										*((volatile uint32*)(GPIO_CR_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_AMSEL(n)									*((volatile uint32*)(GPIO_AMSEL_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_PCTL(n)									*((volatile uint32*)(GPIO_PCTL_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_ADCCTL(n)									*((volatile uint32*)(GPIO_ADCCTL_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))
#define GPIO_PORT_DMACTL(n)									*((volatile uint32*)(GPIO_DMACTL_BASE_ADDRESS+(0x1000*(n%4))+(0x20000*(n/4))))

/*************************************************** GPT Registers ***************************************************/
#define GPTM_BASE_ADDRESS(n)								(0x40030000UL+(0x1000*(n))+(0x14000*(n/8)))
#define GPTMCFG(n)											*((volatile uint32*)(GPTM_BASE_ADDRESS(n)))
#define GPTMTAMR(n)                              			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x004)))
#define	GPTMTBMR(n)                              			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x008)))
#define	GPTMCTL(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x00C)))
#define GPTMSYNC(n)											*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x010)))
#define	GPTMIMR(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x018)))
#define	GPTMRIS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x01C)))
#define	GPTMMIS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x020)))
#define	GPTMICR(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x024)))
#define GPTMTAILR(n)                             			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x028)))
#define GPTMTBILR(n)                               			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x02C)))
#define GPTMTAMATCHR(n)                          			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x030)))
#define GPTMTBMATCHR(n)                          			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x034)))
#define GPTMTAPR(n)                            				*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x038)))
#define GPTMTBPR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x03C)))
#define GPTMTAPMR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x040)))
#define GPTMTBPMR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x044)))
#define GPTMTAR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x048)))
#define GPTMTBR(n)                           			    *((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x04C)))
#define GPTMTAV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x050)))
#define GPTMTBV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x054)))
#define GPTMRTCPD(n)                                		*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x058)))
#define GPTMTAPS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x05C)))
#define GPTMTBPS(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x060)))
#define GPTMTAPV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x064)))
#define GPTMTBPV(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0x068)))
#define GPTMPP(n)                                			*((volatile uint32*)(GPTM_BASE_ADDRESS(n)+(0xFC0)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  

