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

unsigned int uiCalcValue;
unsigned char fCalcChanged;

char cReceivedString[RECIEVER_SIZE];

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
	char cCalcString[6] = "calc ";
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
				sWatch.fMinutesValueChanged = 0;
				Transmiter_SendString(cTransmitString);
			}
			else if (sWatch.fSecondsValueChanged == 1)
			{
				CopyString(cSecString,cTransmitString);
				AppendUIntToString(sWatch.ucSeconds,cTransmitString);
				sWatch.fSecondsValueChanged = 0;
				Transmiter_SendString(cTransmitString);
			}
			else if (fCalcChanged == 1)
			{
				CopyString(cCalcString,cTransmitString);
				AppendUIntToString(uiCalcValue,cTransmitString);
				Transmiter_SendString(cTransmitString);
				fCalcChanged = 0;
			}
		}
		if(eReciever_GetStatus() == READY)
			{
				Reciever_GetStringCopy(cReceivedString);
				DecodeMsg(cReceivedString);
				if((ucTokenCount > 0 ) & (asToken[0].eType == KEYWORD))
				{
					if((asToken[0].uValue.eKeyword == CALC) & (asToken[1].eType == NUMBER))
					{
						uiCalcValue = asToken[1].uValue.uiNumber * 2;
						fCalcChanged = 1;
					}
				}
			}
	}
}
