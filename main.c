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
	enum MoveState{MOVE, STOP};
	enum MoveState eMoveState = MOVE;
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eMoveState){
			case MOVE:
				if(eKeyboardRead() == BUTTON_1)
					eMoveState = STOP;
				else
				{
					LedStepRight();
					Delay(100);
				}
				break;
			case STOP:
				if(eKeyboardRead() == BUTTON_2)
					eMoveState = MOVE;
				break;
		}
	}
}
