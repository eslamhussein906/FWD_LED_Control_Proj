#include "IntCtrl.h"
#include "Port.h"
#include "DIO.h"
#include "SysTick.h"

#define OVERFLOW_VALUE									 (uint32)1398	
#define ON_TIME													 (uint32)1000    //ON Time in ms
#define OFF_TIME									 			 (uint32)1000  	 //OFF Time in ms
#define LED_PIN												 	 DIO_B1					 //LED PIN 
void Timer_Start(uint32 msecond,uint8* NO_OF_OverFlows,uint32* Reminder_Ticks);
volatile uint8 ON_OFF_Flag=0;
static uint8 OV_Cnt=0;
uint8 ON_Period_OverFlow=0;
uint32 ON_Period_Reminder=0;
uint8 OFF_Period_OverFlow=0;
uint32 OFF_Period_Reminder=0;
volatile uint8 Toggle_Flag=0;

void SYSTICK_CBFunc(void);   /*Call back function */
int main()
{
//	IntCrtl_Init();
	Port_Init(PortCfg);									  /*Set Port Configurations*/
	SysTick_SetCBFunc(SYSTICK_CBFunc);    /*Set SysTick Callback function address */
	Timer_Start(ON_TIME,&ON_Period_OverFlow,&ON_Period_Reminder); /*Start timer for ON Period*/
	DIO_WriteChannel(LED_PIN,STD_HIGH);		/*SET DIO to HIGH*/

	while(1)
	{		

	}
	return 0;
}



void Timer_Start(uint32 msecond,uint8* NO_OF_OverFlows,uint32* Reminder_Ticks)
{
	*NO_OF_OverFlows= msecond/OVERFLOW_VALUE;
	uint32 remider_time = msecond%OVERFLOW_VALUE;
	*Reminder_Ticks = 0x2EE0*remider_time;
	if((*NO_OF_OverFlows)>0)
	{
		SysTick_init(0xFFFFFF);
		Toggle_Flag=0;
	}
	else
	{
		SysTick_init(*Reminder_Ticks);
		Toggle_Flag=1;
	}
	SysTick_Start();											/*Start SYSTICK */
}
void SYSTICK_CBFunc(void)
{
	if(Toggle_Flag)
	{
		if(!ON_OFF_Flag) // Toggle from High to low
		{
					DIO_WriteChannel(LED_PIN,STD_LOW);																/*SET DIO to STD_LOW*/
					Timer_Start(OFF_TIME,&OFF_Period_OverFlow,&OFF_Period_Reminder);  /*Start timer for ON Period*/
					ON_OFF_Flag=1;
		}
		else
		{
					DIO_WriteChannel(LED_PIN,STD_HIGH);																/*SET DIO to STD_HIGH*/
					Timer_Start(ON_TIME,&ON_Period_OverFlow,&ON_Period_Reminder); 		/*Start timer for OFF Period*/
					ON_OFF_Flag=0;
		}
		return;
	}
	
	if(!ON_OFF_Flag) 	//ON State 
	{
		OV_Cnt++;
		if(ON_Period_OverFlow > OV_Cnt)
		{
			SysTick_Reload(0xFFFFFF);							 /*Reload ON period Value with Max value*/
		}
		else
		{
			SysTick_Reload(ON_Period_Reminder);		/*Reload ON period Value with Reminder value*/
			Toggle_Flag=1;													
			OV_Cnt=0;
		}	
	}
	else 						//OFF State
	{
		OV_Cnt++;
		if(OFF_Period_OverFlow > OV_Cnt)
		{
			SysTick_Reload(0xFFFFFF);							 	/*Reload OFF period Value with Max value*/
		}
		else
		{
			SysTick_Reload(OFF_Period_Reminder);		/*Reload OFF period Value with Reminder value*/
			Toggle_Flag=1;												
			OV_Cnt=0;
		}	
	}
}


//void SYSTICK_CBFunc(void)
//{
//	if(ON_OFF_Flag) //ON period finished 
//	{
//		DIO_WriteChannel(DIO_B1,STD_LOW); /*SET DIO to LOW*/
//		SysTick_Reload(OFF_TICKS);				/*Reload OFF period Value*/
//		ON_OFF_Flag=0;  									/*Start OFF state*/
//	}
//	else 						// OFF period Finshed
//	{
//		DIO_WriteChannel(DIO_B1,STD_HIGH);/*SET DIO to HIGH*/
//		SysTick_Reload(ON_TICKS);				  /*Reload ON period Value*/
//		ON_OFF_Flag=1;										/*Start ON state*/
//	}
//}

//			DIO_WriteChannel(DIO_B1,STD_HIGH);
//			ck = DIO_ReadChannel(DIO_B1);
//		for(uint32 i=0;i<5000000;i++){__asm("nop");}
//			DIO_FlipChannel(DIO_B1);
//			ck = DIO_ReadChannel(DIO_B1);