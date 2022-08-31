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
volatile uint32 *ENx_address= NULL_PTR;
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
		__asm("cpsie i"); /*Enable the activation of all exceptions using PRIMASK.*/
		__asm("cpsie f"); /*Enable the activation of all exceptions using FAULTMASK. */
	
		/* Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = (APINT_VECTKEY|(IntrCtrl_cfg.Intr_Group_SubGroup << INTR_PRIGROUP_BIT));
    
    /*  Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
		for(uint8 loopCnt=0;loopCnt<INT_NUMBERS;loopCnt++)
		{
			if(IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_Enable == INTR_ENABLED)
			{
				uint8 index 	= IntrCtrl_cfg.IntrCtrlArray[loopCnt].IRQ_Type;
				if(index<16) /* Configuring the Exceptions*/
				{
					/*Set sub priority of each exception , Then Enable the Exception*/
					/*By default all the exception in Group zero */
					switch(index)
					{
						case 4: SYSPRI1->BF.MEM = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; /*Memory management fault Perioty*/
										SYSHNDCTRL->BF.MEM =1;
										break;
						case 5: SYSPRI1->BF.BUS = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; /*Bus fault Perioty*/
										SYSHNDCTRL->BF.BUS =1;
										break;
						case 6: SYSPRI1->BF.USAGE = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; /*Usage fault Perioty*/
										SYSHNDCTRL->BF.USAGE =1;
										break;
						case 11:SYSPRI2->BF.SVC = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; 	/*SVCall fault Perioty*/
										/*SVCALL enabled by default*/
										break;
						case 12:SYSPRI3->BF.DEBUG = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; 	/*DebugMonitor fault Perioty*/
										break;
						case 14:SYSPRI3->BF.PENDSV = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; /*Pendable request fault Perioty*/
										/*PENDSV enabled by default*/
										break;
						case 15:SYSPRI3->BF.TICK = IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority; 	/*System Tick fault Perioty*/
										/*SYSTICK enabled by default*/				
										break;
						default:break;
					}
					
				}
				else		/* Configuring the IRQs*/
				{
					index=index-16; /*Map Exception munber to IRQ number*/
					Int_PRIGROUP_val = IntrCtrl_cfg.Intr_Group_SubGroup;
					Priority_Val = ((IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_group_Priority)<<(Int_PRIGROUP_val+1))|\
															(IntrCtrl_cfg.IntrCtrlArray[loopCnt].Intr_SubGroup_Priority << INTR_SUBG_START_BIT);
				  /*Get Address of PRIx register to set the Priority_Val */
					PRIx_address = (volatile uint32*)((CORTEXM4_PERI_BASE_ADDRESS + PRI_OFFSET + index)-(index%4));
					PRIx_value=Priority_Val<<((index%4)*8);
					*(volatile uint32*)PRIx_address |= PRIx_value;	
					/*Get Address of ENx register to enable the IRQ*/
					ENx_address = (volatile uint32*)((CORTEXM4_PERI_BASE_ADDRESS + ENX_OFFSET + index)-(index%32));
					*(volatile uint32*)ENx_address |= (1<<index%32);
				}
			}	
		}

		
}



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

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
