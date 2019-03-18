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
	enum LedState{LEFT,RIGHT};
	enum LedState eLedState = LEFT;
	unsigned char ucMoveCounter = 0;
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eLedState){
			case LEFT:
				LedStepLeft();
				if (ucMoveCounter == 2)
				{
					ucMoveCounter = 0;
					eLedState = RIGHT;
				}
				else
					ucMoveCounter++;
				break;
			case RIGHT:
				LedStepRight();
				if (ucMoveCounter == 2)
				{
					ucMoveCounter = 0;
					eLedState = LEFT;
				}
				else
					ucMoveCounter++;
				break;
		}
		Delay(250);
	}
}
