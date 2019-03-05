#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED3_bm 0x80000

void Delay(unsigned int uiDelay) 
{

	int iLoopCounter;
	uiDelay = uiDelay * 7500;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

int main()
{
	
	IO1DIR = LED3_bm;
	
	while(1)
	{
		
		Delay(50);
		IO1SET = LED3_bm;
		Delay(50);
		IO1CLR = LED3_bm;
		
	}
	
}

