#define RECIEVER_SIZE 12
#define TERMINATOR '\n'

typedef enum CommandType 
{cCALLIB, cGOTO, cERROR} CommandType;

enum eRecieverStatus {EMPTY, READY, OVERFLOW};

enum CommandType eDecodeCommand(char cTokenString[], unsigned int *uiPosition);
void Reciever_Empty(void);
void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char *ucDestination);
