#include <LPC21xx.H>

void Delay(unsigned int uiDelay) 
{

	uiDelay = uiDelay * 7500;
	int iLoopCounter;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

int main()
{
	
	IO1DIR = 0x10000;
	
	while(1)
	{
		
		Delay(1000);
		IO1SET = 0x10000;
		Delay(1000);
		IO1CLR = 0x10000;
		
	}
	
}

