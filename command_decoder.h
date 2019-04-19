typedef enum CommandType 
{cCALLIB, cLEFT, cRIGHT, cERROR} CommandType;

enum CommandType eDecodeCommand(char cTokenString[]);
