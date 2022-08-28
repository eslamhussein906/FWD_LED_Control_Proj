
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Port_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

//#define AHB																			0
//#define APB																			1
//#define GPIO_AHB_APB_SEL												AHB 

//#if(GPIO_AHB_APB_SEL==AHB)
//#define GPIOA_BASE															GPIOA_BASE_AHB
//#define GPIOB_BASE															GPIOB_BASE_AHB
//#define GPIOC_BASE															GPIOC_BASE_AHB
//#define GPIOD_BASE															GPIOD_BASE_AHB
//#define GPIOE_BASE															GPIOE_BASE_AHB
//#define GPIOF_BASE															GPIOF_BASE_AHB
//#else
//#define GPIOA_BASE															GPIOA_BASE_APB
//#define GPIOB_BASE															GPIOB_BASE_APB
//#define GPIOC_BASE															GPIOC_BASE_APB
//#define GPIOD_BASE														  GPIOD_BASE_APB
//#define GPIOE_BASE															GPIOE_BASE_APB
//#define GPIOF_BASE															GPIOF_BASE_APB
//#endif

#define PIN_GPIO															 (Port_PinModeType)(16)
#define PIN_Analog														  0

#define PA0_U0Rx                               (Port_PinModeType)(1)
#define PA0_CAN1Rx                             (Port_PinModeType)(8)

#define PA1_U0Tx                           		 (Port_PinModeType)(1)
#define PA1_CAN1Tx                             (Port_PinModeType)(8)

#define PA2_SSI0Clk                          	 (Port_PinModeType)(2)

#define PA3_SSI0Fss                          	 (Port_PinModeType)(2)

#define PA4_SSI0Rx                          	 (Port_PinModeType)(2)

#define PA5_SSI0Tx                          	 (Port_PinModeType)(2)

#define PA6_I2C1SCL                          	 (Port_PinModeType)(3)
#define PA6_M1PWM2                          	 (Port_PinModeType)(5)

#define PA7_I2C1SDA                          	 (Port_PinModeType)(3)
#define PA7_M1PWM3                          	 (Port_PinModeType)(5)

#define PB0_USB0ID                        	 	 (Port_PinModeType)(PIN_ANALOG)
#define PB0_U1Rx   		                       	 (Port_PinModeType)(1)
#define PB0_T2CCP0                          	 (Port_PinModeType)(7)

#define PB1_USB0VBUS                        	 (Port_PinModeType)(PIN_ANALOG)
#define PB1_U1Tx   		                       	 (Port_PinModeType)(1)
#define PB1_T2CCP1                          	 (Port_PinModeType)(7)

#define PB2_I2C0SCL                          	 (Port_PinModeType)(3)
#define PB2_T3CCP0                          	 (Port_PinModeType)(7)

#define PB3_I2C0SDA                         	 (Port_PinModeType)(3)
#define PB3_T3CCP1                          	 (Port_PinModeType)(7)

#define PB4_AIN10                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PB4_SSI2Clk                          	 (Port_PinModeType)(2)
#define PB4_M0PWM2	                         	 (Port_PinModeType)(4)
#define PB4_T1CCP0                          	 (Port_PinModeType)(7)
#define PB4_CAN0Rx                          	 (Port_PinModeType)(8)

#define PB5_AIN11                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PB5_SSI2Fss                          	 (Port_PinModeType)(2)
#define PB5_M0PWM3	                         	 (Port_PinModeType)(4)
#define PB5_T1CCP1                          	 (Port_PinModeType)(7)
#define PB5_CAN0Tx                          	 (Port_PinModeType)(8)

#define PB6_SSI2Rx                          	 (Port_PinModeType)(2)
#define PB6_M0PWM0	                         	 (Port_PinModeType)(4)
#define PB6_T0CCP0                          	 (Port_PinModeType)(7)

#define PB7_SSI2Tx                          	 (Port_PinModeType)(2)
#define PB7_M0PWM1	                         	 (Port_PinModeType)(4)
#define PB7_T0CCP1                          	 (Port_PinModeType)(7)

#define PC0_TCK_SWCLK	                         (Port_PinModeType)(1)
#define PC0_T4CCP0                          	 (Port_PinModeType)(7)

#define PC1_TMS_SWDIO	                         (Port_PinModeType)(1)
#define PC1_T4CCP1                          	 (Port_PinModeType)(7)

#define PC2_TDI			                         	 (Port_PinModeType)(1)
#define PC2_T5CCP0                          	 (Port_PinModeType)(7)

#define PC3_TDO_SWO	                         	 (Port_PinModeType)(1)
#define PC3_T5CCP1                          	 (Port_PinModeType)(7)

#define PC4_C1_Neg                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PC4_U4Rx      	                    	 (Port_PinModeType)(1)
#define PC4_U1Rx	               	          	 (Port_PinModeType)(2)
#define PC4_M0PWM6                          	 (Port_PinModeType)(4)
#define PC4_IDX1	                          	 (Port_PinModeType)(6)
#define PC4_WT0CCP0                          	 (Port_PinModeType)(7)
#define PC4_U1RTS	                          	 (Port_PinModeType)(8)

#define PC5_C1_pos                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PC5_U4Tx      	                    	 (Port_PinModeType)(1)
#define PC5_U1Tx	               	          	 (Port_PinModeType)(2)
#define PC5_M0PWM7                          	 (Port_PinModeType)(4)
#define PC5_PhA1	                          	 (Port_PinModeType)(6)
#define PC5_WT0CCP1                          	 (Port_PinModeType)(7)
#define PC5_U1CTS	                          	 (Port_PinModeType)(8)

#define PC6_C0_pos                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PC6_U3Rx      	                    	 (Port_PinModeType)(1)
#define PC6_PhB1	               	          	 (Port_PinModeType)(6)
#define PC6_WT1CCP0                          	 (Port_PinModeType)(7)
#define PC6_USB0EPEN	                       	 (Port_PinModeType)(8)

#define PC7_C0_Neg                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PC7_U3Tx      	                    	 (Port_PinModeType)(1)
#define PC7_WT1CCP1	             	          	 (Port_PinModeType)(7)
#define PC7_USB0PFLT                         	 (Port_PinModeType)(8)

#define PD0_AIN7	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD0_SSI3Clk      	                   	 (Port_PinModeType)(1)
#define PD0_SSI1Clk	             	          	 (Port_PinModeType)(2)
#define PD0_I2C3SCL                         	 (Port_PinModeType)(3)
#define PD0_M0PWM6                 		       	 (Port_PinModeType)(4)
#define PD0_M1PWM0     	                    	 (Port_PinModeType)(5)
#define PD0_WT2CCP0	             	          	 (Port_PinModeType)(7)

#define PD1_AIN6	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD1_SSI3Fss      	                   	 (Port_PinModeType)(1)
#define PD1_SSI1Fss	             	          	 (Port_PinModeType)(2)
#define PD1_I2C3SDA                         	 (Port_PinModeType)(3)
#define PD1_M0PWM7                 		       	 (Port_PinModeType)(4)
#define PD1_M1PWM1     	                    	 (Port_PinModeType)(5)
#define PD1_WT2CCP1	             	          	 (Port_PinModeType)(7)

#define PD2_AIN5	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD2_SSI3Rx      	                   	 (Port_PinModeType)(1)
#define PD2_SSI1Rx	             	          	 (Port_PinModeType)(2)
#define PD2_M0FAULT0                         	 (Port_PinModeType)(4)
#define PD2_WT3CCP0                 	       	 (Port_PinModeType)(7)
#define PD2_USB0EPEN   	                    	 (Port_PinModeType)(8)

#define PD3_AIN4	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD3_SSI3Tx      	                   	 (Port_PinModeType)(1)
#define PD3_SSI1Tx	             	          	 (Port_PinModeType)(2)
#define PD3_IDX0       		                  	 (Port_PinModeType)(6)
#define PD3_WT3CCP1                 	       	 (Port_PinModeType)(7)
#define PD3_USB0PFLT   	                    	 (Port_PinModeType)(8)

#define PD4_USB0DM	                 		       (Port_PinModeType)(PIN_ANALOG)
#define PD4_U6Rx 		     	                   	 (Port_PinModeType)(1)
#define PD4_WT4CCP0	             	          	 (Port_PinModeType)(7)

#define PD5_USB0DP	               		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD5_U6Tx	      	                   	 (Port_PinModeType)(1)
#define PD5_WT4CCP1	             	          	 (Port_PinModeType)(7)

#define PD6_U2Rx	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD6_M0FAULT0     	                   	 (Port_PinModeType)(1)
#define PD6_PhA0  	             	          	 (Port_PinModeType)(2)
#define PD6_WT5CCP0    		                  	 (Port_PinModeType)(6)

#define PD7_U2Tx	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PD7_PhB0	      	                   	 (Port_PinModeType)(1)
#define PD7_WT5CCP1	             	          	 (Port_PinModeType)(2)
#define PD7_NMI       		                  	 (Port_PinModeType)(6)

#define PE0_AIN3		               		       	 (Port_PinModeType)(PIN_ANALOG)
#define PE0_U7Rx	      	                   	 (Port_PinModeType)(1)

#define PE1_AIN2		               		       	 (Port_PinModeType)(PIN_ANALOG)
#define PE1_U7Tx	      	                   	 (Port_PinModeType)(1)

#define PE2_AIN1	               		       		 (Port_PinModeType)(PIN_ANALOG)

#define PE3_AIN0	      	                   	 (Port_PinModeType)(PIN_ANALOG)

#define PE4_AIN9	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PE4_U5Rx	      	                   	 (Port_PinModeType)(1)
#define PE4_I2C2SCL	             	          	 (Port_PinModeType)(3)
#define PE4_M0PWM4     		                  	 (Port_PinModeType)(4)
#define PE4_M1PWM2	                 	       	 (Port_PinModeType)(5)
#define PE4_CAN0Rx	   	                    	 (Port_PinModeType)(8)

#define PE4_AIN8	                 		       	 (Port_PinModeType)(PIN_ANALOG)
#define PE4_U5Tx	      	                   	 (Port_PinModeType)(1)
#define PE4_I2C2SDA	             	          	 (Port_PinModeType)(3)
#define PE4_M0PWM5     		                  	 (Port_PinModeType)(4)
#define PE4_M1PWM3	                 	       	 (Port_PinModeType)(5)
#define PE4_CAN0Tx	   	                    	 (Port_PinModeType)(8)

#define PF0_U1RTS	                 		       	 (Port_PinModeType)(1)
#define PF0_SSI1Rx      	                   	 (Port_PinModeType)(2)
#define PF0_CAN0Rx	             	          	 (Port_PinModeType)(3)
#define PF0_M1PWM4     		                  	 (Port_PinModeType)(5)
#define PF0_PhA0		                 	       	 (Port_PinModeType)(6)
#define PF0_T0CCP0	   	                    	 (Port_PinModeType)(7)
#define PF0_NMI		                 		       	 (Port_PinModeType)(8)
#define PF0_C0o		      	                   	 (Port_PinModeType)(9)

#define PF1_U1CTS	                 		       	 (Port_PinModeType)(1)
#define PF1_SSI1Tx      	                   	 (Port_PinModeType)(2)
#define PF1_M1PWM5	             	          	 (Port_PinModeType)(5)
#define PF1_PhB0     		           		       	 (Port_PinModeType)(6)
#define PF1_T0CCP1	                 	       	 (Port_PinModeType)(7)
#define PF1_C1o			   	                    	 (Port_PinModeType)(9)
#define PF1_TRD1	                 		       	 (Port_PinModeType)(14)

#define PF2_SSI1Clk                		       	 (Port_PinModeType)(2)
#define PF2_M0FAULT0     	                   	 (Port_PinModeType)(5)
#define PF2_M1PWM6	             	          	 (Port_PinModeType)(6)
#define PF2_T1CCP0   		           		       	 (Port_PinModeType)(8)
#define PF2_TRD0		                 	       	 (Port_PinModeType)(14)

#define PF3_SSI1Fss	                 		       (Port_PinModeType)(2)
#define PF3_CAN0Tx      	                   	 (Port_PinModeType)(3)
#define PF3_M1PWM7	             	          	 (Port_PinModeType)(5)
#define PF3_T1CCP1     		           		       (Port_PinModeType)(7)
#define PF3_TRCLK		                 	       	 (Port_PinModeType)(14)

#define PF4_M1FAULT0               		       	 (Port_PinModeType)(5)
#define PF4_IDX0	      	                   	 (Port_PinModeType)(6)
#define PF4_T2CCP0	             	          	 (Port_PinModeType)(7)
#define PF4_USB0EPEN 		           		       	 (Port_PinModeType)(8)

#define PORTS_NUMBER														6
#define GPIOS_PIN_NUMBER												43
#define GPIO_LOCK_KEY														(uint32)0x4C4F434B
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct
{
	Port_PinType PinName;
	Port_PinModeType pinMode;
	Port_PinLevelType PinLvl;
	Port_PinDirectionType PinDir;
	Port_PinInternalAttachType PinAttach;
	Port_PinOutputCurrentType PinCur;
} Port_configType;

extern const Port_configType* ConfigPtr;
 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
