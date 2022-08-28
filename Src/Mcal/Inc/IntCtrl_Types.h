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
//typedef enum
//{
//	GPIO_PortA,
//	GPIO_PortB,
//	GPIO_PortC,
//	GPIO_PortD,
//	GPIO_PortE,
//	UART0,
//	UART1,
//	SSI0,
//	I2C0,
//	PWM0_Fault,
//	PWM0_Generator0,
//	PWM0_Generator1,
//	PWM0_Generator2,
//	QEI0,
//	ADC0_Sequence0,
//	ADC0_Sequence1,
//	ADC0_Sequence2,
//	ADC0_Sequence3,
//	Watchdog_Timers0_1,
//	Timer0A,
//	Timer0B,
//	Timer1A,
//	Timer1B,
//	Timer2A,
//	Timer2B,
//	Analog_Comparator0,
//	Analog_Comparator1,
//	Reserved0,
//	System_Control,
//	FlashMemCtrl_EEPROMCtrl,
//	GPIO_PortF,
//	Reserved1,
//	Reserved2,
//	UART2,
//	SSI1,
//	Timer3A,
//	Timer3B,
//	I2C1,
//	QEI1,
//	CAN0,
//	CAN1,
//	Reserved3,
//	Reserved4,
//	Hibernation_Module,
//	USB,
//	PWM_Generator3,
//	DMA_Software,
//	DMA_Error,
//	ADC1_Sequence0,
//	ADC1_Sequence1,
//	ADC1_Sequence2,
//	ADC1_Sequence3,
//	Reserved5,
//	Reserved6,
//	Reserved7,
//	Reserved8,
//	Reserved9,
//	SSI2,
//	SSI3,
//	UART3,
//	UART4,
//	UART5,
//	UART6,
//	UART7,
//	Reserved10,
//	Reserved11,
//	Reserved12,
//	Reserved13,
//	I2C2,
//	I2C3,
//	Timer4A,
//	Timer4B,
//	Timer5A=92,
//	Timer5B,
//	WTimer0A,
//	WTimer0B,
//	WTimer1A,
//	WTimer1B,
//	WTimer2A,
//	WTimer2B,
//	WTimer3A,
//	WTimer3B,
//	WTimer4A,
//	WTimer4B,
//	WTimer5A,
//	WTimer5B,
//	System_Exception,
//	PWM1_Generator0=134,
//	PWM1_Generator1,
//	PWM1_Generator2,
//	PWM1_Generator3,
//	PWM1_Fault,
//	
//}IntCtrl_InterruptType_t;

/*Execption types ordered by Vector number*/
//typedef enum
//{
//	Reset=0x01,
//	Non_Mask_Int,
//	Hard_fault,
//	Mem_Mang,
//	Bus_fault,
//	Usage_fault,
//	Recerved0,
//	Recerved1,
//	Recerved2,
//	Recerved3,
//	SVCall,
//	Debug_monitor,
//	Recerved4,
//	PendSV,
//	SysTick,
//	
//}IntCtrl_ExceptionType_e;

 typedef enum {
  Reset_IRQn                    = 	1,              /*!<   1  Reset Vector, invoked on Power up and warm reset                 */
  NonMaskableInt_IRQn           = 	2,              /*!<   2  Non maskable Interrupt, cannot be stopped or preempted           */
  HardFault_IRQn                = 	3,              /*!<   3  Hard Fault, all classes of Fault                                 */
  MemoryManagement_IRQn         = 	4,              /*!<   4  Memory Management, MPU mismatch, including Access Violation
                                                         and No Match                                                          */
  BusFault_IRQn                 = 	5,              /*!<   5  Bus Fault, Pre-Fetch-, Memory Access Fault, other address/memory
                                                         related Fault                                                         */
  UsageFault_IRQn               = 	6,              /*!<   6  Usage Fault, i.e. Undef Instruction, Illegal State Transition    */
  SVCall_IRQn                   = 	11,              /*!<  11  System Service Call via SVC instruction                          */
  DebugMonitor_IRQn             = 	12,              /*!<  12  Debug Monitor                                                    */
  PendSV_IRQn                   = 	14,              /*!<  14  Pendable request for system service                              */
  SysTick_IRQn                  = 	15,              /*!<  15  System Tick Timer                                                */
/* -------------------  TM4C123GH6PM Specific Interrupt Numbers  ------------------ */
  GPIOA_IRQn                    =   16,              /*!<   0  GPIOA                                                            */
  GPIOB_IRQn                    =   17,              /*!<   1  GPIOB                                                            */
  GPIOC_IRQn                    =   18,              /*!<   2  GPIOC                                                            */
  GPIOD_IRQn                    =   19,              /*!<   3  GPIOD                                                            */
  GPIOE_IRQn                    =   20,              /*!<   4  GPIOE                                                            */
  UART0_IRQn                    =   21,              /*!<   5  UART0                                                            */
  UART1_IRQn                    =   22,              /*!<   6  UART1                                                            */
  SSI0_IRQn                     =   23,              /*!<   7  SSI0                                                             */
  I2C0_IRQn                     =   24,              /*!<   8  I2C0                                                             */
  PWM0_FAULT_IRQn               =   25,              /*!<   9  PWM0_FAULT                                                       */
  PWM0_0_IRQn                   =   26,              /*!<  10  PWM0_0                                                           */
  PWM0_1_IRQn                   =   27,              /*!<  11  PWM0_1                                                           */
  PWM0_2_IRQn                   =   28,              /*!<  12  PWM0_2                                                           */
  QEI0_IRQn                     =   29,              /*!<  13  QEI0                                                             */
  ADC0SS0_IRQn                  =   30,              /*!<  14  ADC0SS0                                                          */
  ADC0SS1_IRQn                  =   31,              /*!<  15  ADC0SS1                                                          */
  ADC0SS2_IRQn                  =   32,              /*!<  16  ADC0SS2                                                          */
  ADC0SS3_IRQn                  =   33,              /*!<  17  ADC0SS3                                                          */
  WATCHDOG0_IRQn                =   34,              /*!<  18  WATCHDOG0                                                        */
  TIMER0A_IRQn                  =   35,              /*!<  19  TIMER0A                                                          */
  TIMER0B_IRQn                  =   36,              /*!<  20  TIMER0B                                                          */
  TIMER1A_IRQn                  =   37,              /*!<  21  TIMER1A                                                          */
  TIMER1B_IRQn                  =   38,              /*!<  22  TIMER1B                                                          */
  TIMER2A_IRQn                  =   39,              /*!<  23  TIMER2A                                                          */
  TIMER2B_IRQn                  =   40,              /*!<  24  TIMER2B                                                          */
  COMP0_IRQn                    =   41,              /*!<  25  COMP0                                                            */
  COMP1_IRQn                    =   42,              /*!<  26  COMP1                                                            */
  SYSCTL_IRQn                   =   44,              /*!<  28  SYSCTL                                                           */
  FLASH_CTRL_IRQn               =   45,              /*!<  29  FLASH_CTRL                                                       */
  GPIOF_IRQn                    =   46,              /*!<  30  GPIOF                                                            */
  UART2_IRQn                    =   49,              /*!<  33  UART2                                                            */
  SSI1_IRQn                     =   50,              /*!<  34  SSI1                                                             */
  TIMER3A_IRQn                  =   51,              /*!<  35  TIMER3A                                                          */
  TIMER3B_IRQn                  =   52,              /*!<  36  TIMER3B                                                          */
  I2C1_IRQn                     =   53,              /*!<  37  I2C1                                                             */
  QEI1_IRQn                     =   54,              /*!<  38  QEI1                                                             */
  CAN0_IRQn                     =   55,              /*!<  39  CAN0                                                             */
  CAN1_IRQn                     =   56,              /*!<  40  CAN1                                                             */
  HIB_IRQn                      =   59,              /*!<  43  HIB                                                              */
  USB0_IRQn                     =   60,              /*!<  44  USB0                                                             */
  PWM0_3_IRQn                   =   61,              /*!<  45  PWM0_3                                                           */
  UDMA_IRQn                     =   62,              /*!<  46  UDMA                                                             */
  UDMAERR_IRQn                  =   63,              /*!<  47  UDMAERR                                                          */
  ADC1SS0_IRQn                  =   64,              /*!<  48  ADC1SS0                                                          */
  ADC1SS1_IRQn                  =   65,              /*!<  49  ADC1SS1                                                          */
  ADC1SS2_IRQn                  =   66,              /*!<  50  ADC1SS2                                                          */
  ADC1SS3_IRQn                  =   67,              /*!<  51  ADC1SS3                                                          */
  SSI2_IRQn                     =   73,              /*!<  57  SSI2                                                             */
  SSI3_IRQn                     =   74,              /*!<  58  SSI3                                                             */
  UART3_IRQn                    =   75,              /*!<  59  UART3                                                            */
  UART4_IRQn                    =   76,              /*!<  60  UART4                                                            */
  UART5_IRQn                    =   77,              /*!<  61  UART5                                                            */
  UART6_IRQn                    =   78,              /*!<  62  UART6                                                            */
  UART7_IRQn                    =   79,              /*!<  63  UART7                                                            */
  I2C2_IRQn                     =   84,              /*!<  68  I2C2                                                             */
  I2C3_IRQn                     =   85,              /*!<  69  I2C3                                                             */
  TIMER4A_IRQn                  =   86,              /*!<  70  TIMER4A                                                          */
  TIMER4B_IRQn                  =   87,              /*!<  71  TIMER4B                                                          */
  TIMER5A_IRQn                  =  108,              /*!<  92  TIMER5A                                                          */
  TIMER5B_IRQn                  =  109,              /*!<  93  TIMER5B                                                          */
  WTIMER0A_IRQn                 =  110,              /*!<  94  WTIMER0A                                                         */
  WTIMER0B_IRQn                 =  111,              /*!<  95  WTIMER0B                                                         */
  WTIMER1A_IRQn                 =  112,              /*!<  96  WTIMER1A                                                         */
  WTIMER1B_IRQn                 =  113,              /*!<  97  WTIMER1B                                                         */
  WTIMER2A_IRQn                 =  114,              /*!<  98  WTIMER2A                                                         */
  WTIMER2B_IRQn                 =  115,              /*!<  99  WTIMER2B                                                         */
  WTIMER3A_IRQn                 =  116,              /*!< 100  WTIMER3A                                                         */
  WTIMER3B_IRQn                 =  117,              /*!< 101  WTIMER3B                                                         */
  WTIMER4A_IRQn                 =  118,              /*!< 102  WTIMER4A                                                         */
  WTIMER4B_IRQn                 =  119,              /*!< 103  WTIMER4B                                                         */
  WTIMER5A_IRQn                 =  120,              /*!< 104  WTIMER5A                                                         */
  WTIMER5B_IRQn                 =  121,              /*!< 105  WTIMER5B                                                         */
  SYSEXC_IRQn                   =  122,              /*!< 106  SYSEXC                                                           */
  PWM1_0_IRQn                   =  150,              /*!< 134  PWM1_0                                                           */
  PWM1_1_IRQn                   =  151,              /*!< 135  PWM1_1                                                           */
  PWM1_2_IRQn                   =  152,              /*!< 136  PWM1_2                                                           */
  PWM1_3_IRQn                   =  153,              /*!< 137  PWM1_3                                                           */
  PWM1_FAULT_IRQn               =  154               /*!< 138  PWM1_FAULT                                                       */
} IRQn_Type;
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
