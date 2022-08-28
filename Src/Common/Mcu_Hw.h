/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 Val;
    INTCTRL_BF BF;
}INTCTRL_Tag;


typedef struct
{
	uint32 					:5;
	uint32 INTA			:3;
	uint32 					:5;
	uint32 INTB 		:3;
	uint32 					:5;
	uint32 INTC			:3;
	uint32 					:5;
	uint32 INTD 		:3;
}PRIx_BF;

typedef union
{
	uint32 Val;
	PRIx_BF BF;	
}PRIx_Tag;

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
/* Application Interrupt and Reset Control*/
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
/* Interrupt Control and State (INTCTRL) */
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
/* The PRIn register Offset */
#define PRI_OFFSET 														0x00000400
/* The ENx register Offset */
#define ENX_OFFSET 														0x00000100
	

typedef struct
{
	uint32 					:5;
	uint32 MEM			:3;		/*Memory Management Fault Priority*/
	uint32 					:5;
	uint32 BUS			:3;		/*Bus Fault Priority*/
	uint32 					:5;
	uint32 USAGE		:3;		/*Usage Fault Priority*/
	uint32 					:5;		
}SYSPRI1_BF;

typedef union
{
	uint32 Val;
	SYSPRI1_BF BF;
}SYSPRI1_Tag;

typedef struct
{
	uint32 					:29;
	uint32 SVC			:3;		/*SVCall Priority*/	
}SYSPRI2_BF;

typedef union
{
	uint32 Val;
	SYSPRI2_BF BF;
}SYSPRI2_Tag;

typedef struct
{
	uint32 					:5;
	uint32 DEBUG		:3;		/*Debug Priority*/
	uint32 					:13;
	uint32 PENDSV		:3;		/*PENDSV Priority*/
	uint32 					:5;
	uint32 TICK			:3;		/*TICK Fault Priority*/		
}SYSPRI3_BF;

typedef union
{
	uint32 Val;
	SYSPRI3_BF BF;
}SYSPRI3_Tag;

typedef struct
{
	uint32 MEMA			:1;			/*Memory Management Fault Active*/
	uint32 BUSA			:1;			/*Bus Fault Active*/	
	uint32 					:1;
	uint32 USGA			:1;			/*Usage Fault Active*/
	uint32 					:3;
	uint32 SVCA			:1;			/*SVC Call Active*/
	uint32 MON			:1;			/*Debug Monitor Active*/
	uint32 					:1;
	uint32 PENDV		:1;			/*PendSV Exception Active*/
	uint32 TICK			:1;			/*SysTick Exception Active*/
	uint32 USGAP		:1;			/*Usage Fault Pending*/
	uint32 MEMP 		:1;			/*Memory Management Fault Pending*/
	uint32 BUSP			:1;			/*Bus Fault Pending*/
	uint32 SVC			:1;			/*SVC Call Pending*/
	uint32 MEM			:1;			/*Memory Management Fault Enable*/
	uint32 BUS			:1;			/*Bus Fault Enable*/
	uint32 USAGE		:1;			/*Usage Fault Enable*/
	uint32 					:13;		
}SYSHNDCTRL_BF;

typedef union
{
	uint32 Val;
	SYSHNDCTRL_BF BF;
}SYSHNDCTRL_Tag;

/* System Handler Priority 1 (SYSPRI1)*/
#define SYSPRI1																((volatile SYSPRI1_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD18))
/* System Handler Priority 2 (SYSPRI2)*/
#define SYSPRI2																((volatile SYSPRI2_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD1C))
/* System Handler Priority 3 (SYSPRI3)*/
#define SYSPRI3																((volatile SYSPRI3_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD20))
	/*System Handler Control and State (SYSHNDCTRL)*/
#define SYSHNDCTRL														((volatile SYSHNDCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24))
/***********************************System Control Register Map*************************/

/*General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)*/
#define CORTEXM4_SSB_BASE_ADDRESS           	 0x400FE000
#define SSB_RCGCGPIO_OFFSET										 0x608
#define RCGCGPIO															 *(volatile uint32*)(CORTEXM4_SSB_BASE_ADDRESS+SSB_RCGCGPIO_OFFSET)

/********************************** GPIO Reg Map ***********************************/

//#define GPIODIR_OFFSET														0x400		/*GPIO Direction (GPIODIR) Offset 0x400 */
//#define GPIOAFSEL_OFFSET													0x420   /*GPIO Alternate Function Select (GPIOAFSEL), offset 0x420*/
//#define GPIODEN_OFFSET														0x51C		/*GPIO Digital Enable (GPIODEN), offset 0x51C */
//#define GPIOPCTL_OFFSET 													0x52C		/*GPIO Port Control (GPIOPCTL), offset 0x52C*/
//#define GPIODR2R_OFFSET														0x500		/*GPIO 2-mA Drive Select (GPIODR2R), offset 0x500 */
//#define GPIODR4R_OFFSET														0x504		/*GPIO 4-mA Drive Select (GPIODR4R), offset 0x504 */
//#define GPIODR8R_OFFSET														0x508		/*GPIO 8-mA Drive Select (GPIODR8R), offset 0x508 */
//#define GPIOODR_OFFSET														0x50C		/*GPIO Open Drain Select (GPIOODR), offset 0x50C */
//#define GPIOPUR_OFFSET														0x510		/*GPIO Pull-Up Select (GPIOPUR), offset 0x510 */
//#define GPIOPDR_OFFSET														0x514		/*GPIO Pull-Down Select (GPIOPDR), offset 0x514 */
//#define GPIOLOCK_OFFSET														0x520		/*GPIO Lock (GPIOLOCK), offset 0x520 */
//#define GPIOCR_OFFSET 														0x524   /*GPIO Commit (GPIOCR), offset 0x524 */
	
#define GPIOA_BASE																0x40004000
#define GPIOB_BASE																0x40005000
#define GPIOC_BASE																0x40006000
#define GPIOD_BASE																0x40007000
#define GPIOE_BASE																0x40024000
#define GPIOF_BASE																0x40025000
	
#define GPIOA_BASE_AHB														0x40058000
#define GPIOB_BASE_AHB														0x40059000
#define GPIOC_BASE_AHB														0x4005A000
#define GPIOD_BASE_AHB														0x4005B000
#define GPIOE_BASE_AHB														0x4005C000
#define GPIOF_BASE_AHB														0x4005D000

typedef struct {                             /*!< GPIOA Structure                                                       */
	uint32  RESERVED[255]; 
  uint32  DATA;                              /*!< GPIO Data                                                             */
  uint32  DIR;                               /*!< GPIO Direction                                                        */
  uint32  IS;                                /*!< GPIO Interrupt Sense                                                  */
  uint32  IBE;                               /*!< GPIO Interrupt Both Edges                                             */
  uint32  IEV;                               /*!< GPIO Interrupt Event                                                  */
  uint32  IM;                                /*!< GPIO Interrupt Mask                                                   */
  uint32  RIS;                               /*!< GPIO Raw Interrupt Status                                             */
  uint32  MIS;                               /*!< GPIO Masked Interrupt Status                                          */
  uint32  ICR;                               /*!< GPIO Interrupt Clear                                                  */
  uint32  AFSEL;                             /*!< GPIO Alternate Function Select                                        */
  uint32  RESERVED1[55];
  uint32  DR2R;                              /*!< GPIO 2-mA Drive Select                                                */
  uint32  DR4R;                              /*!< GPIO 4-mA Drive Select                                                */
  uint32  DR8R;                              /*!< GPIO 8-mA Drive Select                                                */
  uint32  ODR;                               /*!< GPIO Open Drain Select                                                */
  uint32  PUR;                               /*!< GPIO Pull-Up Select                                                   */
  uint32  PDR;                               /*!< GPIO Pull-Down Select                                                 */
  uint32  SLR;                               /*!< GPIO Slew Rate Control Select                                         */
  uint32  DEN;                               /*!< GPIO Digital Enable                                                   */
  uint32  LOCK;                              /*!< GPIO Lock                                                             */
  uint32  CR;                                /*!< GPIO Commit                                                           */
  uint32  AMSEL;                             /*!< GPIO Analog Mode Select                                               */
  uint32  PCTL;                              /*!< GPIO Port Control                                                     */
  uint32  ADCCTL;                            /*!< GPIO ADC Control                                                      */
  uint32  DMACTL;                            /*!< GPIO DMA Control                                                      */
} GPIOA_Type;

#define GPIOA                           		((volatile GPIOA_Type*) GPIOA_BASE)
#define GPIOB                           		((volatile GPIOA_Type*) GPIOB_BASE)
#define GPIOC                           		((volatile GPIOA_Type*) GPIOC_BASE)
#define GPIOD                           		((volatile GPIOA_Type*) GPIOD_BASE)
#define GPIOE                           		((volatile GPIOA_Type*) GPIOE_BASE)
#define GPIOF                           		((volatile GPIOA_Type*) GPIOF_BASE)

typedef struct
{
	uint32 PMC0:4;
	uint32 PMC1:4;
	uint32 PMC2:4;
	uint32 PMC3:4;
	uint32 PMC4:4;
	uint32 PMC5:4;
	uint32 PMC6:4;
	uint32 PMC7:4;
}GPIOPCTL_BF;
typedef union
{
	uint32 Val;
	GPIOPCTL_BF BF;
}GPIOPCTL_Tag;

#define GPIOPCTL(REG)                          (volatile GPIOPCTL_Tag*)(&REG)

/********************************** SystemTick Reg Map ***********************************/
typedef struct
{
	uint32 STCTRL;						/*SysTick Control and Status Register */
	uint32 STRELOAD;          /*SysTick Reload Value Register */
	uint32 STCURRENT;					/*SysTick Current Value Register */
}SYSTICK_Type;

typedef struct
{
	uint32 EN		  	:1;						
	uint32 INTEN  	:1;
	uint32 CLK_SRC	:1;
	uint32        	:13;
	uint32 COUNT  	:1;
	uint32       	  :15;
}STCTRL_BF;

typedef union
{
	STCTRL_BF BF;
	uint32		Val;
}STCTRL_Tag;
#define SYSTICK_OFFSET												0x010
#define SYSTICK																((volatile SYSTICK_Type*)(CORTEXM4_PERI_BASE_ADDRESS+SYSTICK_OFFSET))
#define SYSTICK_STCTRL												((volatile STCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+SYSTICK_OFFSET))
	
/*Peripheral Memory Bit-Banding Regions*/
#define PRI_MEM_BIT_BAND_BASE_ADDRESS						0x42000000
#define GET_PRI_BIT_WORD_ADDRESS(BIT_NUMBER,BYTE_OFFSET)    *((volatile uint32*)((uint32)(PRI_MEM_BIT_BAND_BASE_ADDRESS)+((uint32)(BYTE_OFFSET)*32)+(BIT_NUMBER*4)))
#define SRAM_MEM_BIT_BAND_BASE_ADDRESS					0x22000000
#define GET_SRAM_BIT_WORD_ADDRESS(BIT_NUMBER,BYTE_OFFSET)   *((volatile uint32*)((SRAM_MEM_BIT_BAND_BASE_ADDRESS)+(BYTE_OFFSET*32)+(BIT_NUMBER*4)))
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
