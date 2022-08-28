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

//volatile uint32* PortDataAddress;
//volatile uint32 check2;
//uint32 bit_word_offset;
//volatile uint32* bit_word_address;
//volatile uint8 ChannelVal;
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
	volatile uint32* PortDataAddress;
	volatile uint32* bit_word_address;
	uint8 ChannelVal;
	uint32 bit_word_offset;
	DIO_LevelType Lvl;
	DIO_PortType PortVal = GET_PORT_FROM_CHANNEL_ID(ChannelId);
	ChannelVal = GET_BIT_FROM_CHANNEL_ID(ChannelId);
	switch(PortVal)
	{
		case DIO_PORTA: PortDataAddress = &(GPIOA->DATA);
										break;
		case DIO_PORTB: PortDataAddress = &(GPIOB->DATA);
										break;
		case DIO_PORTC: PortDataAddress = &(GPIOC->DATA);
										break;
		case DIO_PORTD: PortDataAddress = &(GPIOD->DATA);
										break;
		case DIO_PORTE: PortDataAddress = &(GPIOE->DATA);
										break;
		case DIO_PORTF: PortDataAddress = &(GPIOF->DATA);
										break;
	}
#ifdef DIO_USE_BIT_BANDING
	bit_word_offset = ((uint32)PortDataAddress&(0x000FFFFF))*32 + ChannelVal*4;
	bit_word_address = (volatile uint32*)(bit_word_offset+PRI_MEM_BIT_BAND_BASE_ADDRESS);
	Lvl=*(bit_word_address);
#else	
	Lvl = (*(volatile uint32*)(PortDataAddress + (1<<(2 + ChannelVal))))>> ChannelVal;
#endif
	return Lvl;
}

void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType  Level)
{
	volatile uint32* PortDataAddress;
	volatile uint32* bit_word_address;
	uint8 ChannelVal;
	uint32 bit_word_offset;
	DIO_PortType PortVal = GET_PORT_FROM_CHANNEL_ID(ChannelId);
	ChannelVal = GET_BIT_FROM_CHANNEL_ID(ChannelId);
	switch(PortVal)
	{
		case DIO_PORTA: PortDataAddress = &(GPIOA->DATA);
										break;
		case DIO_PORTB: PortDataAddress = &(GPIOB->DATA);
										break;
		case DIO_PORTC: PortDataAddress = &(GPIOC->DATA);
										break;
		case DIO_PORTD: PortDataAddress = &(GPIOD->DATA);
										break;
		case DIO_PORTE: PortDataAddress = &(GPIOE->DATA);
										break;
		case DIO_PORTF: PortDataAddress = &(GPIOF->DATA);
										break;
	}
	
#ifdef DIO_USE_BIT_BANDING
	bit_word_offset = ((uint32)PortDataAddress&(0x000FFFFF))*32 + ChannelVal*4;
	bit_word_address = (volatile uint32*)(bit_word_offset+PRI_MEM_BIT_BAND_BASE_ADDRESS);
	*(bit_word_address)=Level;
#else
	*(volatile uint32*)(PortDataAddress + (1<<(2 + ChannelVal))) = Level;
#endif
}

DIO_PortType DIO_ReadPort(DIO_PortType PortId)
{
	volatile uint32* PortDataAddress;
	DIO_PortType PortVal;
	switch(PortId)
	{
		case DIO_PORTA: PortDataAddress = &(GPIOA->DATA);
										break;
		case DIO_PORTB: PortDataAddress = &(GPIOB->DATA);
										break;
		case DIO_PORTC: PortDataAddress = &(GPIOC->DATA);
										break;
		case DIO_PORTD: PortDataAddress = &(GPIOD->DATA);
										break;
		case DIO_PORTE: PortDataAddress = &(GPIOE->DATA);
										break;
		case DIO_PORTF: PortDataAddress = &(GPIOF->DATA);
										break;
	}
#ifdef DIO_USE_BIT_BANDING
	PortVal = *(PortDataAddress);
#else
	PortVal = *(volatile uint32*)(PortDataAddress + GPIO_ADDRESS_BUS_MASK);
#endif
	return PortVal;
	
}

void DIO_WritePort(DIO_PortType PortId, Dio_PortLevelType PortLevel)
{
	volatile uint32* PortDataAddress;
	switch(PortId)
	{
		case DIO_PORTA: PortDataAddress = &(GPIOA->DATA);
										break;
		case DIO_PORTB: PortDataAddress = &(GPIOB->DATA);
										break;
		case DIO_PORTC: PortDataAddress = &(GPIOC->DATA);
										break;
		case DIO_PORTD: PortDataAddress = &(GPIOD->DATA);
										break;
		case DIO_PORTE: PortDataAddress = &(GPIOE->DATA);
										break;
		case DIO_PORTF: PortDataAddress = &(GPIOF->DATA);
										break;
	}
#ifdef DIO_USE_BIT_BANDING
		*(PortDataAddress)=PortLevel;
#else
		*(volatile uint32*)(PortDataAddress + GPIO_ADDRESS_BUS_MASK) = PortLevel;
#endif

}

DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId)
{
	DIO_LevelType lvl = DIO_ReadChannel(ChannelId);
	DIO_WriteChannel(ChannelId,!lvl);	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
