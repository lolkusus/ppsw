typedef enum eDirection{
	RIGHT,
	LEFT
} eDirection;

void LedOn(unsigned char ucLedIndeks);
void LedStep(eDirection Direction);
void LedStepLeft(void);
void LedStepRight(void);
void LedInit(void);
