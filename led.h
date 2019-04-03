typedef enum eDirection{
	LEFT,
	RIGHT,
	STOP
} eDirection;

void LedOn(unsigned char ucLedIndeks);
void LedStep(eDirection Direction);
void LedStepLeft(void);
void LedStepRight(void);
void LedInit(void);
