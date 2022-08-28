#include "IntCtrl.h"
#include "Port.h"
#include "DIO.h"
#include "SysTick.h"

#define ON_TICKS											 (uint32)16000000UL //0xF42400
#define OFF_TICKS											 (uint32)8000000UL  //0x7A1200
volatile uint8 ON_OFF_Flag=0;

DIO_LevelType ck;
void SYSTICK_CBFunc(void);
int main()
{
//	IntCrtl_Init();
	Port_Init(PortCfg);									  /*set Port Configurations*/
	SysTick_SetCBFunc(SYSTICK_CBFunc);    /*Set SysTick Callback function address */
	SysTick_init(ON_TICKS);
	DIO_WriteChannel(DIO_B1,STD_HIGH);		/*SET DIO to HIGH*/
	SysTick_Start();											/*Start SYSTICK */
	while(1)
	{		

	}
	return 0;
}

void SYSTICK_CBFunc(void)
{
	if(ON_OFF_Flag) //ON period finished 
	{
		DIO_WriteChannel(DIO_B1,STD_LOW); /*SET DIO to LOW*/
		SysTick_Reload(OFF_TICKS);				/*Reload OFF period Value*/
		ON_OFF_Flag=0;  									/*Start OFF state*/
	}
	else 						// OFF period Finshed
	{
		DIO_WriteChannel(DIO_B1,STD_HIGH);/*SET DIO to HIGH*/
		SysTick_Reload(ON_TICKS);				  /*Reload ON period Value*/
		ON_OFF_Flag=1;										/*Start ON state*/
	}
}

//			DIO_WriteChannel(DIO_B1,STD_HIGH);
//			ck = DIO_ReadChannel(DIO_B1);
//		for(uint32 i=0;i<5000000;i++){__asm("nop");}
//			DIO_FlipChannel(DIO_B1);
//			ck = DIO_ReadChannel(DIO_B1);