#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"


int main (){
	unsigned int iMainLoopCtr;
	LedInit();
	Timer0Interrupts_Init(250000,&LedStepLeft);

	while(1){
	 	iMainLoopCtr++;
	}
}
