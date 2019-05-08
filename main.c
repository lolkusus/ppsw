#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
//#include "string.h"
#include "command_decoder.h"
#include "uart.h"

#include <LPC210X.H>

int main (){
	char cString[16] = "Test 123";
	UART_InitWithInt(9600);
	
	Transmiter_SendString(cString);
	
	while(1)
	{
		if(Transmiter_GetStatus() == FREE)
			Transmiter_SendString(cString);
	}
}
