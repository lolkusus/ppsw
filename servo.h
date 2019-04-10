typedef enum DetectorState{
	ACTIVE,
	INACTIVE
} DetectorState;

typedef enum ServoState{
CALLIB, 
IDLE,
IN_PROGRESS
} ServoState;

typedef struct Servo
{
enum ServoState eState;
unsigned int uiCurrentPosition;
unsigned int uiDesiredPosition;
}sServo;

void ServoCallib(void);
void DetectorInit(void);
enum DetectorState eReadDetector(void);
