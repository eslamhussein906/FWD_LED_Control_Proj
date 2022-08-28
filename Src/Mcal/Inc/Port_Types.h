/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Port_PinModeType;
//typedef uint8 Port_PinInternalAttachType;
//typedef uint8 Port_PinOutputCurrentType;
typedef enum
{
	PA0=0	 ,	PA1	,	PA2	,	PA3	,	PA4	,	PA5	,	PA6	,	PA7	,
	PB0=8	 ,	PB1	,	PB2	,	PB3	,	PB4	,	PB5	,	PB6	,	PB7	,
	PC0=16 ,	PC1	,	PC2	,	PC3	,	PC4	,	PC5	,	PC6	,	PC7	,
	PD0=24 ,	PD1	,	PD2	,	PD3	,	PD4	,	PD5	,	PD	,	PD7	,
	PE0=32 ,	PE1	,	PE2	,	PE3	,	PE4	,	PE5	,
	PF0=40 ,	PF1	,	PF2	,	PF3	,	PF4

}Port_PinType;


typedef enum
{
	PUR,
	PDR,
	ODR,
}Port_PinInternalAttachType;

typedef enum
{
	CURRENT_2MA,
	CURRENT_4MA,
	CURRENT_8MA,
}Port_PinOutputCurrentType;

typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT,
	
}Port_PinDirectionType;


typedef enum
{
	PORT_PIN_LOW,
	PORT_PIN_HIGH,
	
}Port_PinLevelType;


typedef enum
{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
}PortType;

typedef struct
{
}Port_ConfigType;



 
#endif  /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
