#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

int main (){
	KeyboardInit();
	ServoInit(50);
	
	while(1){
		switch(eKeyboardRead()){
			
		case BUTTON_2:
			ServoGoTo(12);
			break;
		
		case BUTTON_3:
			ServoGoTo(24);
			break;
		
		case BUTTON_4:
			ServoGoTo(36);
			break;
		
		default:
			break;
	}
 }
}
