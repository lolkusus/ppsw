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
#define ADCEnable (1<<21)
#define ADCStart (1<<24)
#define ADCBURST (1<<16)
//ADData
#define ADCDone (1<<31)
#define ADR_bm 0xFFC0

long servoPos;

void ADInit()
{
	PINSEL1 = ADPinSel; 
	ADCR = ADCRSel |  ADCEnable;
}

long ADRead()
{
	ADCR = ADCR | ADCStart;
	while((ADDR & ADCDone) == 0) {}
	return ((ADDR & ADR_bm) >> 6);
}

int main (){
	ServoInit(150);
	ADInit();
	ServoCallib();
	servoPos = 0;
	
	while(1)
	{
		servoPos = ADRead();
		servoPos = servoPos / 21;
		ServoGoTo(servoPos);
	}
 
}
