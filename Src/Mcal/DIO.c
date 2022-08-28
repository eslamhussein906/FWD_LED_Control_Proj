/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  DIO Driver
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO.h"
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


/******************************************************************************
* \Syntax          :                                       
* \Description     : Channel Read.                            
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId: ID of DIO Channel
					
* \Parameters (out): STD_HIGH : The physical level of the corresponding Pin is STD_HIGH
											STD_LOW : The physical level of the corresponding Pin is STD_LOW                                                      
* \Return value:   : None
*******************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId)
{
	DIO_LevelType Lvl;
	volatile uint32 PortDataAddress;
	DIO_PortType PortVal = GET_PORT_FROM_CHANNEL_ID(ChannelId);
	uint8 ChannelVal = GET_BIT_FROM_CHANNEL_ID(ChannelId);
	switch(PortVal)
	{
		case DIO_PORTA: PortDataAddress = GPIOA->DATA;
										break;
		case DIO_PORTB: PortDataAddress = GPIOB->DATA;
										break;
		case DIO_PORTC: PortDataAddress = GPIOC->DATA;
										break;
		case DIO_PORTD: PortDataAddress = GPIOD->DATA;
										break;
		case DIO_PORTE: PortDataAddress = GPIOE->DATA;
										break;
		case DIO_PORTF: PortDataAddress = GPIOF->DATA;
										break;
	}
	Lvl = (*(volatile uint32*)(PortDataAddress + (1<<(2 + ChannelVal))))>> ChannelVal;
	return Lvl;
}

void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType  Level)
{
	volatile uint32 PortDataAddress;
	DIO_PortType PortVal = GET_PORT_FROM_CHANNEL_ID(ChannelId);
	uint8 ChannelVal = GET_BIT_FROM_CHANNEL_ID(ChannelId);
	switch(PortVal)
	{
		case DIO_PORTA: PortDataAddress = GPIOA->DATA;
										break;
		case DIO_PORTB: PortDataAddress = GPIOB->DATA;
										break;
		case DIO_PORTC: PortDataAddress = GPIOC->DATA;
										break;
		case DIO_PORTD: PortDataAddress = GPIOD->DATA;
										break;
		case DIO_PORTE: PortDataAddress = GPIOE->DATA;
										break;
		case DIO_PORTF: PortDataAddress = GPIOF->DATA;
										break;
	}
	*(volatile uint32*)(PortDataAddress + (1<<(2 + ChannelVal))) = Level;
}

DIO_PortType DIO_ReadPort(DIO_PortType PortId)
{
	DIO_PortType PortVal;
	volatile uint32 PortDataAddress;
	switch(PortId)
	{
		case DIO_PORTA: PortDataAddress = GPIOA->DATA;
										break;
		case DIO_PORTB: PortDataAddress = GPIOB->DATA;
										break;
		case DIO_PORTC: PortDataAddress = GPIOC->DATA;
										break;
		case DIO_PORTD: PortDataAddress = GPIOD->DATA;
										break;
		case DIO_PORTE: PortDataAddress = GPIOE->DATA;
										break;
		case DIO_PORTF: PortDataAddress = GPIOF->DATA;
										break;
	}
	PortVal = *(volatile uint32*)(PortDataAddress + GPIO_ADDRESS_BUS_MASK);
	return PortVal;
	
}

void DIO_WritePort(DIO_PortType PortId, Dio_PortLevelType PortLevel)
{
	volatile uint32 PortDataAddress;
	switch(PortId)
	{
		case DIO_PORTA: PortDataAddress = GPIOA->DATA;
										break;
		case DIO_PORTB: PortDataAddress = GPIOB->DATA;
										break;
		case DIO_PORTC: PortDataAddress = GPIOC->DATA;
										break;
		case DIO_PORTD: PortDataAddress = GPIOD->DATA;
										break;
		case DIO_PORTE: PortDataAddress = GPIOE->DATA;
										break;
		case DIO_PORTF: PortDataAddress = GPIOF->DATA;
										break;
	}
	*(volatile uint32*)(PortDataAddress + GPIO_ADDRESS_BUS_MASK) = PortLevel;
}

DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId)
{
	DIO_LevelType lvl = DIO_ReadChannel(ChannelId);
	DIO_WriteChannel(ChannelId,!lvl);
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
