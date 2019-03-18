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
	enum MoveState{LEFT, RIGHT, STOP};
	enum MoveState eMoveState = STOP;
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eMoveState){
			case LEFT:
				if(eKeyboardRead() == BUTTON_2)
					eMoveState = STOP;
				else
					LedStepLeft();
				break;
			case RIGHT:
				if(eKeyboardRead() == BUTTON_2)
					eMoveState = STOP;
				else
					LedStepRight();
				break;
			case STOP:
				if(eKeyboardRead() == BUTTON_1)
					eMoveState = LEFT;
				else if(eKeyboardRead() == BUTTON_3)
					eMoveState = RIGHT;
		}
		Delay(100);
	}
}
