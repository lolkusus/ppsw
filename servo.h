typedef enum DetectorState{
	ACTIVE,
	INACTIVE
} DetectorState;

void DetectorInit(void);
enum DetectorState eReadDetector(void);
