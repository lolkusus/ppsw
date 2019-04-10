#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

void Automat()
{
	enum MoveState {STOP, LEFT, RIGHT, CALLIB};
	static enum MoveState eMoveState = STOP;

	switch(eMoveState){
		case CALLIB:
			if(eReadDetector() == INACTIVE)
				LedStepRight();
			else
				eMoveState = STOP;
			break;
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
			else if(eKeyboardRead() == BUTTON_4)
				eMoveState = CALLIB;
		}
}

int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	KeyboardInit();
	DetectorInit();
	Timer0Interrupts_Init(20000,&Automat);

	while(1){
	 	iMainLoopCtr++;
	}
}
