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
	enum MoveState eMoveState = STOP;
	unsigned char ucMoveCounter = 0;
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		switch(eMoveState){
			case MOVE:
				if (ucMoveCounter < 2)
				{
					LedStepRight();
					ucMoveCounter++;
					Delay(250);
				}
				else
				{
					LedStepRight();
					ucMoveCounter = 0;
					eMoveState = STOP;
				}
				break;
			case STOP:
				if(eKeyboardRead() == BUTTON_1)
					eMoveState = MOVE;
				break;
		}
	}
}
