#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "string.h"
#include "command_decoder.h"
#include "uart.h"

#include <LPC210X.H>

int main (){
	char cString[32] = "licznik ";
	char cTransmitString[32];
	unsigned int uiNumber = 0;
	
	UART_InitWithInt(9600);
	
	while(1)
	{
		if (Transmiter_GetStatus() == FREE)
		{
			CopyString(cString,cTransmitString);
			AppendUIntToString(uiNumber,cTransmitString);
			Transmiter_SendString(cTransmitString);
			uiNumber++;
		}
	}
}
