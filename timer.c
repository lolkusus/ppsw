#include <LPC21xx.H>
#include  "timer.h"

#define Timer0Control T0TCR
#define TimerEnable 1
#define TimerReset (1<<1)

#define MatchRegister0  T0MR0
#define MatchControlRegister T0MCR

#define Timer0Interrupts T0IR
#define Match0Interrupt 1

#define InterruptOnMr0 1
#define ResetOnMr0 (1<<1)
#define StopOnMr0 (1<<2)

#define UsToClk 15

void InitTimer0()
{
	Timer0Control = TimerEnable | TimerReset;
}

void WaitOnTimer0(unsigned int uiTime)
{
	Timer0Control = TimerEnable | TimerReset;
	Timer0Control = TimerEnable;
	while(1)
	{
		if(Timer0Control >= uiTime*UsToClk)
		break;
	}
}

void InitTimer0Match0(unsigned int iDelayTime)
{
	MatchRegister0 = iDelayTime * UsToClk;
	MatchControlRegister = InterruptOnMr0 | ResetOnMr0;
	Timer0Control = TimerEnable | TimerReset;
	Timer0Control = TimerEnable;
}

void WaitOnTimer0Match0()
{
	while(1)
	{
		if((Timer0Interrupts & Match0Interrupt) != 0)
		break;
	}
	Timer0Interrupts = Timer0Interrupts & Match0Interrupt;
}
