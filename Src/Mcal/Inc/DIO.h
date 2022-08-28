/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Port.h
 *       Module:  Port
 *
 *  Description:  header file for GPIO Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_ADDRESS_BUS_MASK                      0x3fc

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define GET_PORT_FROM_CHANNEL_ID(CHANNEL_ID)      (CHANNEL_ID/8)
#define GET_BIT_FROM_CHANNEL_ID(CHANNEL_ID)				(1<<(CHANNEL_ID%8))

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId);

void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level);

DIO_PortType DIO_ReadPort(DIO_PortType PortId);

void DIO_WritePort(DIO_PortType PortId, Dio_PortLevelType PortLevel);

DIO_LevelType DIO_FlipChannel(DIO_ChannelType ChannelId);

 
#endif 

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
