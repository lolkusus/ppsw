#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

void Automat()
{
	enum MoveState {STOP, LEFT, RIGHT};
	static enum MoveState eMoveState = STOP;

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
}

int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	Timer0Interrupts_Init(20000,&Automat);

	while(1){
	 	iMainLoopCtr++;
	}
}
