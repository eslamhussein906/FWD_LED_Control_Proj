/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define INT_NUMBERS																			(uint8)(128)

#define INTR_GROUPS_8_SUB_1															(uint8)(4)
#define INTR_GROUPS_4_SUB_2															(uint8)(5)
#define INTR_GROUPS_2_SUB_4															(uint8)(6)
#define INTR_GROUPS_1_SUB_8															(uint8)(7)

#define INTR_PRIORITY_0																	(uint8)(0)
#define INTR_PRIORITY_1																	(uint8)(1)
#define INTR_PRIORITY_2																	(uint8)(2)
#define INTR_PRIORITY_3																	(uint8)(3)
#define INTR_PRIORITY_4																	(uint8)(4)
#define INTR_PRIORITY_5																	(uint8)(5)
#define INTR_PRIORITY_6																	(uint8)(6)
#define INTR_PRIORITY_7																	(uint8)(7)


typedef enum
{
	INTR_DISABLED,
	INTR_ENABLED,
}Intr_status_t;

typedef struct
{
	uint8 Intr_Index;							/* Interrupt number in vector table*/
	Intr_status_t Intr_Enable;		/* Interrupt status (En/Dis)*/				
	uint8 Intr_group_Priority;		/* Interrupt Group Priority */
	uint8 Intr_SubGroup_Priority; /* Interrupt Sub Group Priority */
}IntrCtrl_t;

typedef struct
{
	uint8 Intr_Group_SubGroup;
	uint8 IntrPriority;
	IntrCtrl_t IntrCtrlArray[INT_NUMBERS];
}IntrCtrl_configs_t;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern const IntrCtrl_configs_t IntrCtrl_cfg;

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/
