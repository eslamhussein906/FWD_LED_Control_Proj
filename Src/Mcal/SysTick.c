/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "SysTick.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (*SYSTICK_CBFuncPtr)(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

#define SYSTICK_USE_PIOSC								(uint8)0
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void SysTick_init(uint32 STRELOAD_Val)
{

	SYSTICK_STCTRL->BF.EN=0;           /*The counter is disabled*/
	SYSTICK->STRELOAD =STRELOAD_Val-1 ;  /*Program the value in the STRELOAD register*/
	SYSTICK->STCURRENT=0x01;           /*Clear the STCURRENT register by writing to it with any value , it also clears COUNT reg*/
	/*Configure the STCTRL register for the required operation.*/
	if(SYSTICK_USE_PIOSC)						 
	{
		SYSTICK_STCTRL->BF.CLK_SRC =0;	/*Use Precision internal oscillator (PIOSC) divided by 4*/
	}		
	else
	{
		SYSTICK_STCTRL->BF.CLK_SRC =1;  /*Use System clock*/
	}
	SYSTICK_STCTRL->BF.INTEN=1;				/*Enable interrupt */
		
}
void SysTick_Start(void)
{
	SYSTICK_STCTRL->BF.EN=1;	/*The counter is enabled */	
}
void SysTick_Stop(void)
{
	SYSTICK_STCTRL->BF.EN=0; /*The counter is disabled*/
}
	
void SysTick_SetCBFunc(void(*CB_FuncPtr)(void))
{
	SYSTICK_CBFuncPtr = CB_FuncPtr;
}

void SysTick_Reload(uint32 STRELOAD_Val)
{
	SYSTICK->STRELOAD =STRELOAD_Val;   /*Program the value in the STRELOAD register*/
	SYSTICK_STCTRL->BF.EN=0; /*The counter is disabled*/
	SYSTICK_STCTRL->BF.EN=1;	/*The counter is enabled */	
}

void SysTick_Handler(void)
{
	SYSTICK_CBFuncPtr(); 							/*Calling back the function of the main file*/
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
