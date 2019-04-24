#define RECIEVER_SIZE 32
#define TERMINATOR '\n'
#define MAX_TOKEN_NR 2
#define MAX_KEYWORD_STRING_LTH 6

typedef enum CommandType 
{cCALLIB, cGOTO, cERROR} CommandType;

typedef enum TokenType 
{KEYWORD, NUMBER, STRING} TokenType;

typedef enum KeywordCode 
{GO, CAL, COS} KeywordCode;

typedef struct Keyword
{
enum KeywordCode eCode;
char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

typedef union TokenValue
{
enum KeywordCode eKeyword;
unsigned int uiNumber;
char *pcString; 
} TokenValue;

typedef struct Token
{
enum TokenType eType; 
union TokenValue uValue; 
} Token;

extern struct Token asToken[MAX_TOKEN_NR];

void DecodeMsg(char *pcString);

enum eRecieverStatus {EMPTY, READY, OVERFLOW};
void Reciever_PutCharacterToBuffer(char cCharacter);
enum eRecieverStatus eReciever_GetStatus(void);
void Reciever_GetStringCopy(char *ucDestination);
