#include <LPC21xx.H>
#include "keyboard.h"

#define BUT0_bm (1<<4)
#define BUT1_bm (1<<6)
#define BUT2_bm (1<<5)
#define BUT3_bm (1<<7)

enum KeyboardState eKeyboardRead()
{
	int iButtonState;
	
	iButtonState = ~(IO0PIN & (BUT0_bm | BUT1_bm | BUT2_bm | BUT3_bm));
	
	if ((iButtonState & BUT0_bm) != 0) // wcisniety 0x10 & 0x10 = 0x10, puszczony 0x00 & 0x10 == 0x00
	{
		return BUTTON_1;
	}
	
		if ((iButtonState & BUT1_bm) != 0)// wcisniety 0x20 & 0x20 == 0x20, puszczony 0x00 & 0x20 == 00
	{
		return BUTTON_2;
	}
	
		if ((iButtonState & BUT2_bm) != 0)
	{
		return BUTTON_3;
	}
	
		if ((iButtonState & BUT3_bm) != 0)
	{
		return BUTTON_4;
	}
	
	return RELASED;
	
}

void KeyboardInit()
{
		IO0DIR = IO0DIR & ~(BUT0_bm | BUT1_bm | BUT2_bm | BUT3_bm);
}
