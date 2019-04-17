#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

tsServo sServo;

void Automat()
{
	switch(sServo.eState){
		case CALLIB:
			if(eReadDetector() == INACTIVE)
				LedStepRight();
			else
			{
				LedStepRight();
				sServo.eState = IDLE;
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
			}
			break;
			
		case IN_PROGRESS:
			if(sServo.uiDesiredPosition > sServo.uiCurrentPosition){
				LedStepRight();
				sServo.uiCurrentPosition++;
			}
			else if(sServo.uiDesiredPosition < sServo.uiCurrentPosition){
				LedStepLeft();
				sServo.uiCurrentPosition--;
			}
			else
				sServo.eState = IDLE;		
		break;
		
		case IDLE:
			if(sServo.uiDesiredPosition != sServo.uiCurrentPosition)
				sServo.eState = IN_PROGRESS;
		break;
		}
}

int main (){
	LedInit();
	KeyboardInit();
	DetectorInit();
	ServoCallib();
	Timer0Interrupts_Init(20000,&Automat);
	
	while(1){
		if(eKeyboardRead() == BUTTON_2)
			sServo.uiDesiredPosition = 12;
		if(eKeyboardRead() == BUTTON_3)
			sServo.uiDesiredPosition = 24;
		if(eKeyboardRead() == BUTTON_4)
			sServo.uiDesiredPosition = 36;
	}
}
