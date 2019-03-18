#include <LPC21xx.H>
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
	
	while(1)
	{
		switch(eKeyboardRead()){
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			default:
				break;
		}
		Delay(100);
	}
}

