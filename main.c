#include <LPC21xx.H>

void Delay(unsigned int uiDelay) 
{

	int iLoopCounter;
	uiDelay = uiDelay * 7500;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

int main()
{
	
	IO1DIR = 0x10000;
	
	while(1)
	{
		
		Delay(50);
		IO1SET = 0x10000;
		Delay(50);
		IO1CLR = 0x10000;
		
	}
	
}

