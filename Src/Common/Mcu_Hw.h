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

/***********************************System Control Register Map*************************/

/*General-Purpose Input/Output Run Mode Clock Gating Control (RCGCGPIO)*/
#define CORTEXM4_SSB_BASE_ADDRESS           	 0x400FE000
#define SSB_RCGCGPIO_OFFSET										 0x608

/********************************** GPIO Reg Map ***********************************/

#define GPIODIR_OFFSET														0x400		/*GPIO Direction (GPIODIR) Offset 0x400 */
#define GPIOAFSEL_OFFSET													0x420   /*GPIO Alternate Function Select (GPIOAFSEL), offset 0x420*/
#define GPIODEN_OFFSET														0x51C		/*GPIO Digital Enable (GPIODEN), offset 0x51C */
#define GPIOPCTL_OFFSET 													0x52C		/*GPIO Port Control (GPIOPCTL), offset 0x52C*/
#define GPIODR2R_OFFSET														0x500		/*GPIO 2-mA Drive Select (GPIODR2R), offset 0x500 */
#define GPIODR4R_OFFSET														0x504		/*GPIO 4-mA Drive Select (GPIODR4R), offset 0x504 */
#define GPIODR8R_OFFSET														0x508		/*GPIO 8-mA Drive Select (GPIODR8R), offset 0x508 */
#define GPIOODR_OFFSET														0x50C		/*GPIO Open Drain Select (GPIOODR), offset 0x50C */
#define GPIOPUR_OFFSET														0x510		/*GPIO Pull-Up Select (GPIOPUR), offset 0x510 */
#define GPIOPDR_OFFSET														0x514		/*GPIO Pull-Down Select (GPIOPDR), offset 0x514 */
#define GPIOLOCK_OFFSET														0x520		/*GPIO Lock (GPIOLOCK), offset 0x520 */
#define GPIOCR_OFFSET 														0x524   /*GPIO Commit (GPIOCR), offset 0x524 */
	
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
 
  uint32  DATA;                              /*!< GPIO Data                                                             */
	uint32  RESERVED[255];
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

#define GPIOA                           		((GPIOA_Type*) GPIOA_BASE)
#define GPIOB                           		((GPIOA_Type*) GPIOB_BASE)
#define GPIOC                           		((GPIOA_Type*) GPIOC_BASE)
#define GPIOD                           		((GPIOA_Type*) GPIOD_BASE)
#define GPIOE                           		((GPIOA_Type*) GPIOE_BASE)
#define GPIOF                           		((GPIOA_Type*) GPIOF_BASE)

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

#define GPIOPCTL(ADDRESS)                          *(volatile GPIOPCTL_Tag*)(ADDRESS)

//#define GPIOA_DATA															 GPIOA_BASE
//#define GPIOB_DATA															 GPIOB_BASE
//#define GPIOC_DATA															 GPIOC_BASE
//#define GPIOD_DATA															 GPIOD_BASE
//#define GPIOE_DATA															 GPIOE_BASE
//#define GPIOF_DATA															 GPIOF_BASE

//#define GPIOA_DIR																 GPIOA_BASE+GPIODIR_OFFSET
//#define GPIOB_DIR																 GPIOB_BASE+GPIODIR_OFFSET
//#define GPIOC_DIR																 GPIOC_BASE+GPIODIR_OFFSET
//#define GPIOD_DIR																 GPIOD_BASE+GPIODIR_OFFSET
//#define GPIOE_DIR																 GPIOE_BASE+GPIODIR_OFFSET
//#define GPIOF_DIR																 GPIOF_BASE+GPIODIR_OFFSET	
//	

///*GPIO Port Control (GPIOPCTL), offset 0x52C*/
//#define GPIOPCTL_A															 GPIOA_BASE+GPIOPCTL_OFFSET
//#define GPIOPCTL_B															 GPIOB_BASE+GPIOPCTL_OFFSET
//#define GPIOPCTL_C															 GPIOC_BASE+GPIOPCTL_OFFSET
//#define GPIOPCTL_D															 GPIOD_BASE+GPIOPCTL_OFFSET
//#define GPIOPCTL_E															 GPIOE_BASE+GPIOPCTL_OFFSET
//#define GPIOPCTL_F															 GPIOF_BASE+GPIOPCTL_OFFSET



/**/

#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
