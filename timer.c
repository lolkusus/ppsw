#include <LPC21xx.H>
#include  "timer.h"

void InitTimer0()
{
	T0TCR = 3;
}

void WaitOnTimer0(unsigned int uiTime)
{
	T0TCR = 3;
	T0TCR = 1;
	while(1)
	{
		if(T0TC >= uiTime*15)
		break;
	}
}
