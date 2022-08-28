/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

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

/*Interrupt types ordered by interrupt number*/
typedef enum
{
	GPIO_PortA,
	GPIO_PortB,
	GPIO_PortC,
	GPIO_PortD,
	GPIO_PortE,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator0,
	PWM0_Generator1,
	PWM0_Generator2,
	QEI0,
	ADC0_Sequence0,
	ADC0_Sequence1,
	ADC0_Sequence2,
	ADC0_Sequence3,
	Watchdog_Timers0_1,
	Timer0A,
	Timer0B,
	Timer1A,
	Timer1B,
	Timer2A,
	Timer2B,
	Analog_Comparator0,
	Analog_Comparator1,
	Reserved0,
	System_Control,
	FlashMemCtrl_EEPROMCtrl,
	GPIO_PortF,
	Reserved1,
	Reserved2,
	UART2,
	SSI1,
	Timer3A,
	Timer3B,
	I2C1,
	QEI1,
	CAN0,
	CAN1,
	Reserved3,
	Reserved4,
	Hibernation_Module,
	USB,
	PWM_Generator3,
	DMA_Software,
	DMA_Error,
	ADC1_Sequence0,
	ADC1_Sequence1,
	ADC1_Sequence2,
	ADC1_Sequence3,
	Reserved5,
	Reserved6,
	Reserved7,
	Reserved8,
	Reserved9,
	SSI2,
	SSI3,
	UART3,
	UART4,
	UART5,
	UART6,
	UART7,
	Reserved10,
	Reserved11,
	Reserved12,
	Reserved13,
	I2C2,
	I2C3,
	Timer4A,
	Timer4B,
	Timer5A=92,
	Timer5B,
	WTimer0A,
	WTimer0B,
	WTimer1A,
	WTimer1B,
	WTimer2A,
	WTimer2B,
	WTimer3A,
	WTimer3B,
	WTimer4A,
	WTimer4B,
	WTimer5A,
	WTimer5B,
	System_Exception,
	PWM1_Generator0=134,
	PWM1_Generator1,
	PWM1_Generator2,
	PWM1_Generator3,
	PWM1_Fault,
	
}IntCtrl_InterruptType_t;

/*Execption types ordered by Vector number*/
typedef enum
{
	Reset=0x01,
	Non_Mask_Int,
	Hard_fault,
	Mem_Mang,
	Bus_fault,
	Usage_fault,
	Recerved0,
	Recerved1,
	Recerved2,
	Recerved3,
	SVCall,
	Debug_monitor,
	Recerved4,
	PendSV,
	SysTick,
	
}IntCtrl_ExceptionType_e;

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
