#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "string.h"
#include "command_decoder.h"
#include "uart.h"

typedef struct Watch {
unsigned char ucMinutes, ucSeconds;
unsigned char fSecondsValueChanged, fMinutesValueChanged;
}Watch;

struct Watch sWatch;

void WatchUpdate(){
	sWatch.ucSeconds++;
	sWatch.fSecondsValueChanged = 1;
	if (sWatch.ucSeconds == 60)
	{
		sWatch.ucSeconds = 0;
		sWatch.ucMinutes++;
		sWatch.fMinutesValueChanged = 1;
	}
	if (sWatch.ucMinutes == 60)
	{
		sWatch.ucMinutes = 0;
	}
}

int main (){
	char cSecString[5] = "sec ";
	char cMinString[5] = "min ";
	char cSpace[2] = " ";
	char cTransmitString[32];
	
	Timer0Interrupts_Init(1000000,&WatchUpdate);
	
	UART_InitWithInt(9600);
	
	while(1)
	{
		if (Transmiter_GetStatus() == FREE)
		{
			if(sWatch.fMinutesValueChanged == 1)
			{
				CopyString(cMinString,cTransmitString);
				AppendUIntToString(sWatch.ucMinutes,cTransmitString);
				AppendString(cSpace,cTransmitString);
				//AppendString(cSecString,cTransmitString);
				//AppendUIntToString(sWatch.ucSeconds,cTransmitString);
				sWatch.fMinutesValueChanged = 0;
				//sWatch.fSecondsValueChanged = 0;
				Transmiter_SendString(cTransmitString);
			}
			else if (sWatch.fSecondsValueChanged == 1)
			{
				CopyString(cSecString,cTransmitString);
				AppendUIntToString(sWatch.ucSeconds,cTransmitString);
				sWatch.fSecondsValueChanged = 0;
				Transmiter_SendString(cTransmitString);
			}
		}
	}
}
