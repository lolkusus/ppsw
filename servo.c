#include <LPC21xx.H>
#include "servo.h"
#include "led.h"

#define DETEKTOR_bm (1<<10)

void DetectorInit()
{
	IO0DIR = IO0DIR & (~DETEKTOR_bm);
}

void ServoCallib(void)
{
	sServo.eState = CALLIB;
}

enum DetectorState eReadDetector()
{
	int iDetectorState = ~(IO0PIN & (DETEKTOR_bm));
	if ((iDetectorState & DETEKTOR_bm) != 0)
	{
		return ACTIVE;
	}
	return INACTIVE;
}
