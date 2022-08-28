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
#include "Std_Types.h"
#include "IntCtrl.h"
#include "Mcu_Hw.h"

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

//volatile PRIx_Tag *PRIx_address=NULL_PTR;
volatile uint32 *PRIx_address=NULL_PTR;
volatile uint32 PRIx_offset=0;
volatile uint8 Priority_Val=0;
volatile uint8 Int_PRIGROUP_val=0;
volatile uint32 PRIx_value=0;
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
void IntCrtl_Init(void)
{

		/* Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = (APINT_VECTKEY|(IntrCtrl_cfg.Intr_Group_SubGroup << INTR_PRIGROUP_BIT));
    
    /*  Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
		for(uint8 loopCnt=0;loopCnt<INT_NUMBERS;loopCnt++)
		{
			if(IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_Enable == INTR_ENABLED)
			{
				uint8 index 	= IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_Index;
				Int_PRIGROUP_val = IntrCtrl_cfg.Intr_Group_SubGroup;
				Priority_Val = ((IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority)<<(Int_PRIGROUP_val+1))|\
															(IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority << INTR_SUBG_START_BIT);
				
				PRIx_address = (volatile uint32*)((CORTEXM4_PERI_BASE_ADDRESS + PRI_OFFSET + index)-(index%4));
				PRIx_value=Priority_Val<<(((index%4)*8));
				*(volatile uint32*)PRIx_address |= PRIx_value;
				
			
//				switch(index%4)
//				{
//					case 0: *(uint8 *)(PRIx_address->BF.INTA)= IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority;
//									break;
//					case 1: *(uint8 *)(PRIx_address->BF.INTB)= IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority;
//									break;
//					case 2: *(uint8 *)(PRIx_address->BF.INTC)= IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority;
//									break;
//					case 3: *(uint8 *)(PRIx_address->BF.INTD)= IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority;
//									break;
//				}
			
			}
			
			
			
			
		}

		/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */


	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
