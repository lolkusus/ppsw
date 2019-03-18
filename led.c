#include <LPC21xx.H>
#include "led.h"

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

unsigned int uiLedCounter = 0;

void LedOn(unsigned char ucLedIndeks)
{
	
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
	switch(ucLedIndeks){
		case 0:
			IO1SET = LED0_bm;
			break;
		case 1:
			IO1SET = LED1_bm;
			break;
		case 2:
			IO1SET = LED2_bm;
			break;
		case 3:
			IO1SET = LED3_bm;
			break;
	}
	
}

void LedStep(eDirection Direction)
{
	static unsigned int uiLedCounter;
	if (Direction == RIGHT)
		uiLedCounter = uiLedCounter - 1;
	else if (Direction == LEFT)
		uiLedCounter = uiLedCounter + 1;
	LedOn(uiLedCounter % 4);
}

void LedStepLeft()
{
	LedStep(LEFT);
}

void LedStepRight()
{
	LedStep(RIGHT);
}

void LedInit()
{
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
}
