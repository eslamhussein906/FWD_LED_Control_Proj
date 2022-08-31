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

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
#define GPIO_GET_PORT_FROM_CHANNEL_ID(CHANNEL_ID)      (CHANNEL_ID/8)
#define GPIO_GET_BIT_FROM_CHANNEL_ID(CHANNEL_ID)			 (CHANNEL_ID%8)
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
	const Port_configType* CurPtr = CnfgPtr;
	volatile GPIOA_Type* PortAdd;
	
	for(uint8 loopcnt=0;loopcnt<GPIOS_PIN_NUMBER; loopcnt++)
	{
		Port_PinType PinName = CurPtr->PinName;
		Port_PinModeType PinMode = CurPtr->pinMode;
		Port_PinLevelType PinLvl = CurPtr->PinLvl;
		Port_PinDirectionType PinDir = CurPtr->PinDir;
		Port_PinInternalAttachType PinAttach = CurPtr->PinAttach;
		Port_PinOutputCurrentType PinCur = CurPtr->PinCur;
		
		PortType PortNum  = GPIO_GET_PORT_FROM_CHANNEL_ID(PinName);	/* Get Port Number from Pin Name*/
		uint8 PinNum	 = GPIO_GET_BIT_FROM_CHANNEL_ID(PinName);		/* Get Pin number from Pin Name*/
		switch(PortNum)
		{
			case PORTA: PortAdd=GPIOA;
									break;
			case PORTB: PortAdd=GPIOB;
									break;
			case PORTC: PortAdd=GPIOC;
									break;
			case PORTD: PortAdd=GPIOD;
									break;
			case PORTE: PortAdd=GPIOE;
									break;
			case PORTF: PortAdd=GPIOF;
									break;
		}
		/*1-Enable and provide a clock to GPIO Port*/
		SET_BIT(RCGCGPIO,PortNum);
		/*2-Set Pin Direction */
		switch(PinDir)
		{
			case PORT_PIN_OUT: SET_BIT(PortAdd->DIR,PinNum);	/*Set Pin as Output pin*/
													break;
			case PORT_PIN_IN:  CLR_BIT(PortAdd->DIR,PinNum);	/*Set Pin as IN pin*/
													break;			
		}		

		PortAdd->LOCK = GPIO_LOCK_KEY;							 /*Write 0x4C4F434B unlocks the GPIO Commit (GPIOCR) register for write access*/
		SET_BIT(PortAdd->CR , PinNum);     					 /*Enable committing */
		
		/*3-Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin*/
		if(PinMode==PIN_GPIO)	// GPIO Pin
		{
			CLR_BIT(PortAdd->AFSEL , PinNum);    			/*Pin is used as a GPIO */
		}
		else
		{
			SET_BIT(PortAdd->AFSEL , PinNum);    			/*Pin is used as an alternative function */
			/*Select the required specific peripheral*/
			switch(PinNum)
			{
				case 0: (GPIOPCTL(PortAdd->PCTL))->BF.PMC0 = PinMode;
								 break;
				case 1: (GPIOPCTL(PortAdd->PCTL))->BF.PMC1 = PinMode;
								 break;
				case 2: (GPIOPCTL(PortAdd->PCTL))->BF.PMC2 = PinMode;
								 break;
				case 3: (GPIOPCTL(PortAdd->PCTL))->BF.PMC3 = PinMode;
								 break;
				case 4: (GPIOPCTL(PortAdd->PCTL))->BF.PMC4 = PinMode;
								 break;
				case 5: (GPIOPCTL(PortAdd->PCTL))->BF.PMC5 = PinMode;
								 break;
				case 6: (GPIOPCTL(PortAdd->PCTL))->BF.PMC6 = PinMode;
								 break;
				case 7: (GPIOPCTL(PortAdd->PCTL))->BF.PMC7 = PinMode;
								 break;
			}
			
		}
		/*4-Set the drive strength for each of the pins*/
		switch(PinCur)
		{
			case CURRENT_2MA: SET_BIT(PortAdd->DR2R,PinNum);   /*Output Pad 2-mA Drive Enable */
					 break;
			case CURRENT_4MA: SET_BIT(PortAdd->DR4R,PinNum);   /*Output Pad 4-mA Drive Enable */
					 break;
			case CURRENT_8MA: SET_BIT(PortAdd->DR8R,PinNum);   /*Output Pad 8-mA Drive Enable */
					 break;
		}
		/*5-Program each pad in the port to have either pull-up, pull-down, or open drain*/
		switch(PinAttach)
		{
			case PUR: SET_BIT(PortAdd->PUR,PinNum);   /*Enable Pull-up resistor */
								break;
			case PDR: SET_BIT(PortAdd->PDR,PinNum);   /*Enable Pull-down resistor */
								break;
			case ODR: SET_BIT(PortAdd->ODR,PinNum);   /*Enable Pull-down resistor */
								break;
		}
		/*Set lvl of each pin*/
		switch(PinLvl)
		{
			case PORT_PIN_HIGH:SET_BIT(PortAdd->DATA,PinNum);
					 break;
			case PORT_PIN_LOW: CLR_BIT(PortAdd->DATA,PinNum);
					 break;
		}
		/*6-Enable Analog/Digital function of the Pin*/
		if(PinMode==PIN_ANALOG) //Analog Pin
		{
			SET_BIT(PortAdd->AMSEL,PinNum);  					 /*Enable Analog function */
		}
		else
		{
			SET_BIT(PortAdd->DEN , PinNum);    				/*Enable Digital function */
		}
		
		
		/*GPIO Pins With Special Considerations*/
		if((PinName==PA0 && PinMode==PA0_U0Rx)||(PinName==PA1 &&PinMode==PA1_U0Tx)||\
			 (PinName==PA2 && PinMode==PA2_SSI0Clk)||(PinName==PA3 &&PinMode==PA3_SSI0Fss)||\
			 (PinName==PA4 &&PinMode==PA4_SSI0Rx)||(PinName==PA5 &&PinMode==PA5_SSI0Tx)||\
			 (PinName==PB2 && PinMode==PB2_I2C0SCL)||(PinName==PB3 &&PinMode==PB3_I2C0SDA))
		{
			SET_BIT(PortAdd->CR , PinNum);    /*GPIOCR =1	  */
			CLR_BIT(PortAdd->AFSEL , PinNum);	/*GPIOAFSEL =0*/
			CLR_BIT(PortAdd->DEN , PinNum);		/*GPIODEN =0  */
			CLR_BIT(PortAdd->DIR , PinNum);		/*GPIOPDR =0  */
			CLR_BIT(PortAdd->PUR , PinNum);		/*GPIOPUR =0  */
		}
		else if((PinName==PC0 && PinMode==PC0_TCK_SWCLK)||(PinName==PC1 &&PinMode==PC1_TMS_SWDIO)||\
						(PinName==PC2 &&PinMode==PC2_TDI)||(PinName==PC3 &&PinMode==PC3_TDO_SWO))
		{
			
			SET_BIT(PortAdd->AFSEL , PinNum);	/*GPIOAFSEL =1*/
			SET_BIT(PortAdd->DEN , PinNum);		/*GPIODEN =1  */
			CLR_BIT(PortAdd->DIR , PinNum);		/*GPIOPDR =0  */
			SET_BIT(PortAdd->PUR , PinNum);		/*GPIOPUR =1  */
			CLR_BIT(PortAdd->CR , PinNum);    /*GPIOCR  =0	*/			
		}
		else if((PinName==PD7 && PinMode==0)||(PinName==PE0 &&PinMode==0))
		{
			CLR_BIT(PortAdd->CR , PinNum);    /*GPIOCR =1	  */
			CLR_BIT(PortAdd->AFSEL , PinNum);	/*GPIOAFSEL =0*/
			CLR_BIT(PortAdd->DEN , PinNum);		/*GPIODEN =0  */
			CLR_BIT(PortAdd->DIR , PinNum);		/*GPIOPDR =0  */
			CLR_BIT(PortAdd->PUR , PinNum);		/*GPIOPUR =0  */		
		}
		CurPtr++;
	}
	
}
		

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/


//Port_PinType PinName = CurPtr->PinName;
//Port_PinModeType PinMode = CurPtr->pinMode;
//Port_PinLevelType PinLvl = CurPtr->PinLvl;
//Port_PinDirectionType PinDir = CurPtr->PinDir;
//Port_PinInternalAttachType PinAttach = CurPtr->PinAttach;
//Port_PinOutputCurrentType PinCur = CurPtr->PinCur;

//PortType PortNum     = GPIO_GET_PORT_FROM_CHANNEL_ID(PinName);
//uint8 PinNum		 		 = GPIO_GET_BIT_FROM_CHANNEL_ID(PinName);
//GPIOA_Type* PortAdd  = GPIO_GET_REG_ADDRESS(PortNum);

//volatile Port_PinType PinName  ;
//volatile Port_PinModeType PinMode ;
//volatile Port_PinLevelType PinLvl ;
//volatile Port_PinDirectionType PinDir ;
//volatile Port_PinInternalAttachType PinAttach ;
//volatile Port_PinOutputCurrentType PinCur;

//volatile PortType PortNum;
//volatile uint8 PinNum;
//volatile GPIOA_Type* PortAdd;