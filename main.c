#include "timer.h"
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"
#include "string.h"
#include "command_decoder.h"
#include "uart.h"
#include <LPC21xx.H>

//ADControl
#define ADPinSel (1<<22)
#define ADCRSel (1<<0)
#define ADCClks (7<<17)
#define ADCEnable (1<<21)
#define ADCStart (1<<24)
//ADData
#define ADCDone (1<<31)
#define ADR_bm 0xFFC0

unsigned char servoPos;

void ADInit()
{
	PINSEL1 = ADPinSel; 
	ADCR = ADCRSel | ADCClks | ADCEnable;
}

unsigned int ADRead()
{
	ADCR = ADCR | ADCStart;
	while((ADDR & ADCDone) == 0) {}
	return ((ADDR & ADR_bm) >> 6);
}

int main (){
	ServoInit(50);
	ADInit();
	ServoCallib();
	servoPos = 0;
	
	while(1)
	{
		servoPos = (ADRead() / 21);
		ServoGoTo(servoPos);
	}
 
}
