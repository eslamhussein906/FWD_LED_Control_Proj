/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  GPIO port Driver
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//const uint32 PortsBaseAddressLut[PORTS_NUMBER] =
//{ 
//	GPIOA_BASE,
//	GPIOB_BASE,
//	GPIOC_BASE,
//	GPIOD_BASE,
//	GPIOE_BASE,
//	GPIOF_BASE,	
//};

const GPIOA_Type* PortsBaseAddressLut[PORTS_NUMBER] =
{ 
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,	
};

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define GPIO_GET_REG_ADDRESS(PORT_ID)						 			 (GPIOA_Type*)(PortsBaseAddressLut[PORT_ID])
#define GPIO_GET_PORT_FROM_CHANNEL_ID(CHANNEL_ID)      (CHANNEL_ID/8)
#define GPIO_GET_BIT_FROM_CHANNEL_ID(CHANNEL_ID)			 (1<<(CHANNEL_ID%8))
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          :                                       
* \Description     :                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : The type Port_ConfigType is a type for the external data structure containing 
*										 the initialization data for the PORT Driver.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const Port_configType* CnfgPtr)
{
	Port_configType* CurPtr;
	for(uint8 loopcnt=0;loopcnt<GPIOS_PIN_NUMBER; loopcnt++)
	{
		Port_PinType PinName = CurPtr->PinName;
		Port_PinModeType PinMode = CurPtr->pinMode;
		Port_PinLevelType PinLvl = CurPtr->PinLvl;
		Port_PinDirectionType PinDir = CurPtr->PinDir;
		Port_PinInternalAttachType PinAttach = CurPtr->PinAttach;
		Port_PinOutputCurrentType PinCur = CurPtr->PinCur;
		
		PortType PortNum     = GPIO_GET_PORT_FROM_CHANNEL_ID(PinName);
		uint8 PinNum		 		 = GPIO_GET_BIT_FROM_CHANNEL_ID(PinName);
		GPIOA_Type* PortAdd  = GPIO_GET_REG_ADDRESS(PortNum);
		
		/*GPIO Pins With Special Considerations*/
//		if((PinName==PA0 && PinMode==PA0_U0Rx)||(PinName==PA1 &&PinMode==PA1_U0Tx))
		
		
		/* Set Pin Direction */
		switch(PinDir)
		{
			case PORT_PIN_OUT: SET_BIT(*((uint32*)PortAdd->DIR),PinNum);
													break;
			case PORT_PIN_IN:  CLR_BIT(*((uint32*)PortAdd->DIR),PinNum);
													break;			
		}
		
		/*Set Mode configuarions */
		*(uint32*)(PortAdd->LOCK) = GPIO_LOCK_KEY;							 /*write 0x4C4F434B unlocks the GPIO Commit (GPIOCR) register for write access*/
		SET_BIT(*((uint32*)PortAdd->CR) , PinNum);     					 /*Enable committing */
		
		if(PinMode==PIN_Analog) //Analog Pin
		{
			SET_BIT(*((uint32*)PortAdd->AMSEL),PinNum);  					 /*Enable analog function */
		}
		else // GPIO Pin OR alternative PIN
		{
			SET_BIT(*((uint32*)PortAdd->DEN) , PinNum);    					/*Enable Digital function */
			
			if(PinMode==PIN_GPIO)		// GPIO Pin
			{
				CLR_BIT(*((uint32*)PortAdd->AFSEL) , PinNum);    			/*Pin is used as a GPIO */
			}
			else
			{
				SET_BIT(*((uint32*)PortAdd->AFSEL) , PinNum);    			/*Pin is used as an alternative function */
				switch(PinNum)
				{
					case 0: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC0 = PinMode;
									 break;
					case 1: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC1 = PinMode;
									 break;
					case 2: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC2 = PinMode;
									 break;
					case 3: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC3 = PinMode;
									 break;
					case 4: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC4 = PinMode;
									 break;
					case 5: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC5 = PinMode;
									 break;
					case 6: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC6 = PinMode;
									 break;
					case 7: (GPIOPCTL(PortAdd->AFSEL)).BF.PMC7 = PinMode;
									 break;
				}
				
			}
			
			/*Set Pin Attach Type*/
			switch(PinAttach)
			{
				case PUR: SET_BIT(*((uint32*)PortAdd->PUR),PinNum);   /*Enable Pull-up resistor */
									break;
				case PDR: SET_BIT(*((uint32*)PortAdd->PDR),PinNum);   /*Enable Pull-down resistor */
									break;
				case ODR: SET_BIT(*((uint32*)PortAdd->ODR),PinNum);   /*Enable Pull-down resistor */
									break;
			}
			/*Set Pin Current Type*/
			switch(PinCur)
			{
				case CURRENT_2MA: SET_BIT(*((uint32*)PortAdd->DR2R),PinNum);   /*Output Pad 2-mA Drive Enable */
						 break;
				case CURRENT_4MA: SET_BIT(*((uint32*)PortAdd->DR4R),PinNum);   /*Output Pad 4-mA Drive Enable */
						 break;
				case CURRENT_8MA: SET_BIT(*((uint32*)PortAdd->DR8R),PinNum);   /*Output Pad 8-mA Drive Enable */
						 break;
			}		
		}		
	}
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
