#include <LPC21xx.H>

#define LED0_bm 0x10000
#define LED1_bm 0x20000
#define LED2_bm 0x40000
#define LED3_bm 0x80000

#define BUT0_bm 0x10
#define BUT1_bm 0x40
#define BUT2_bm 0x20
#define BUT3_bm 0x80

enum ButtonState {RELASED, PRESSED};

void Delay(unsigned int uiDelay) 
{

	int iLoopCounter;
	uiDelay = uiDelay * 7500;
	for(iLoopCounter=0;iLoopCounter<uiDelay;iLoopCounter++){
		
	}
}

enum ButtonState ReadButton1()
{
	
	if ((IO0PIN & BUT1_bm) == 0)
	{
		
		return PRESSED;
		
	}
	return RELASED;
	
}

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

void LedInit()
{
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
}

void KeyboardInit()
{
	
		IO0DIR = IO0DIR & ~(BUT0_bm | BUT1_bm | BUT2_bm | BUT3_bm);
	
}

int main()
{
	
	LedInit();
	KeyboardInit();
	
	while(1)
	{
		
		switch(ReadButton1()){
			case PRESSED: 
				LedOn(1);
				break;
			case RELASED:
				LedOn(0);
			break;
		}
		
	}
	
}

