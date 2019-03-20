#include <LPC21xx.H>
#include "timer.h"
#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiDelay) 
{
	int iDelayCounter;
	uiDelay = uiDelay * 7500;
	for(iDelayCounter=0;iDelayCounter<uiDelay;iDelayCounter++){
	}
}

int main()
{
	LedInit();
	KeyboardInit();
	
	InitTimer0();
	
	while(1)
	{
		LedOn(1);
		WaitOnTimer0(250000);
		LedOn(4);
		WaitOnTimer0(250000);
	}
}
