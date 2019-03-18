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
	enum LedState{LEFT, RIGHT};
	enum LedState eLedState = LEFT;
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eLedState){
			case LEFT:
				LedStepRight();
				eLedState = RIGHT;
				break;
			case RIGHT:
				LedStepLeft();
				eLedState = LEFT;
				break;
		}
		Delay(250);
	}
}
