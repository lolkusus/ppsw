#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define BUT1_bm 0x40

void Delay(unsigned int uiDelay) 
{

	int iLoopCounter;
	uiDelay = uiDelay * 7500;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

int ReadButton1()
{
	
	if ((IO0PIN & BUT1_bm) == 0)
	{
		
		return 1;
		
	}
	return 0;
	
}

void LedOn(unsigned char ucLedIndeks)
{
	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	
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

void LedInit()
{
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO0DIR = IO0DIR & ~BUT1_bm;
	
}

int main()
{
	
	LedInit();
	
	while(1)
	{
		
		if (ReadButton1() == 0)
		{
			LedOn(0);
		}
		else
		{
			LedOn(1);
		}
		
	}
	
}

