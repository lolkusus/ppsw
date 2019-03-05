#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

void Delay(unsigned int uiDelay) 
{

	int iLoopCounter;
	uiDelay = uiDelay * 7500;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

void LedInit()
{
	
	IO1DIR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
	
}

int main()
{
	
	LedInit();
	
	while(1)
	{
		
		IO1SET = LED0_bm;
		Delay(250);
		IO1CLR = LED0_bm;
		
		IO1SET = LED1_bm;
		Delay(250);
		IO1CLR = LED1_bm;

		IO1SET = LED2_bm;
		Delay(250);
		IO1CLR = LED2_bm;

		IO1SET = LED3_bm;
		Delay(250);
		IO1CLR = LED3_bm;
		
	}
	
}

