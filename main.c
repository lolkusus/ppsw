#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

tsServo sServo;

int main (){
	KeyboardInit();
	ServoInit(50);
	
	while(1){
		if(eKeyboardRead() == BUTTON_2)
			ServoGoTo(12);
		if(eKeyboardRead() == BUTTON_3)
			ServoGoTo(24);
		if(eKeyboardRead() == BUTTON_4)
			ServoGoTo(36);
	}
}
