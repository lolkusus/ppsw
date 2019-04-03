#include <LPC21xx.H>
#include "timer.h"
#include "led.h"
#include "keyboard.h"

#define mCOUNTER_ENABLE 0x00000001
#define mCOUNTER_RESET  0x00000002

// CompareMatch
#define mINTERRUPT_ON_MR0 0x00000001
#define mRESET_ON_MR0     0x00000002
#define mMR0_INTERRUPT    0x00000001

// VIC (Vector Interrupt Controller) VICIntEnable
#define VIC_TIMER0_CHANNEL_NR 4
#define VIC_TIMER1_CHANNEL_NR 5

// VICVectCntlx Vector Control Registers
#define mIRQ_SLOT_ENABLE 0x00000020

__irq void Timer0IRQHandler(){

	T0IR=mMR0_INTERRUPT; 
	LedStepRight();	
	VICVectAddr=0x00;
}

__irq void Timer1IRQHandler(){

	T1IR=mMR0_INTERRUPT; 
	LedStepRight();
	VICVectAddr=0x00;
}

void Timer0Interrupts_Init(unsigned int uiPeriod){

	VICIntEnable |= (0x1 << VIC_TIMER0_CHANNEL_NR);            
	VICVectCntl0  = mIRQ_SLOT_ENABLE | VIC_TIMER0_CHANNEL_NR;  
	VICVectAddr0  =(unsigned long)Timer0IRQHandler; 	   

	T0MR0 = 15 * uiPeriod;                 	      
	T0MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0); 

	T0TCR |=  mCOUNTER_ENABLE; 
}


void Timer1Interrupts_Init(unsigned int uiPeriod){

	VICIntEnable |= (0x1 << VIC_TIMER1_CHANNEL_NR);            
	VICVectCntl1  = mIRQ_SLOT_ENABLE | VIC_TIMER1_CHANNEL_NR;  
	VICVectAddr1  =(unsigned long)Timer1IRQHandler; 	   

	T1MR0 = 15 * uiPeriod;                 	      
	T1MCR |= (mINTERRUPT_ON_MR0 | mRESET_ON_MR0); 

	T1TCR |=  mCOUNTER_ENABLE; 
}

int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	Timer0Interrupts_Init(250000);

	while(1){
	 	iMainLoopCtr++;
	}
}
