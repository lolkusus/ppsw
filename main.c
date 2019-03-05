#include <LPC21xx.H>

void Delay() 
{
	int iLoopCounter;
	for(iLoopCounter=0;iLoopCounter<7500000;iLoopCounter++){
		
	}
}

int main()
{
	
	IO1DIR = 0x10000;
	
	while(1)
	{
		
		Delay();
		IO1SET = 0x10000;
		Delay();
		IO1CLR = 0x10000;
		
	}
	
}

