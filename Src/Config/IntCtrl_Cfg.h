/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  NVIC PERIORITY GROUP AND SUPGROUP CONFIGRATIONS     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ENABLE_GLOBAL_INTERRUPT				1

/* NVIC PERIORITY GROUP AND SUPGROUP CONFIGRATIONS 
    "You can choose a number from 1, 2, 4, and 8"...
                        1 --> 1 GP_PRI and 8 SubGP_PRI, 
                        2 --> 2 GP_PRI and 4 SubGP_PRI, 
                        4 --> 4 GP_PRI and 2 SubGP_PRI, 
                        8 --> 8 GP_PRI and 1 SubGP_PRI 
                        X --> Group and Y --> SubGroup*/

#define NUM_OF_GROUP_PRI_YYY					1		
#define NUM_OF_GROUP_PRI_XYY					2		
#define NUM_OF_GROUP_PRI_XXY					4		
#define NUM_OF_GROUP_PRI_XXX					8
#define NUM_OF_GROUP_PRI_SELECTOR			NUM_OF_GROUP_PRI_XXY	

/*number of programmable exceptions from 1 to 85: 
                                            7 system exceptions and faults,
                                            78 peripherals interrupts*/
#define NUM_OF_ACTIVE_INTERRUPT 		1


 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/