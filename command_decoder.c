#include "command_decoder.h"
#include "string.h"

struct RecieverBuffer{
char cData[RECIEVER_SIZE];
unsigned char ucCharCtr;
enum eRecieverStatus eStatus;
} sRecieverBuffer;

enum CommandType eDecodeCommand(char cTokenString[],unsigned int *uiPosition)
{
	unsigned int uiHexPosition;
	
		if (eCompareString("callib",cTokenString) == EQUAL) 
			return cCALLIB;
		else if (eCompareString("goto",cTokenString) == EQUAL) 
		{
			for(uiHexPosition=0;cTokenString[uiHexPosition]!='0';uiHexPosition++){}
			if(eHexStringToUInt(cTokenString+uiHexPosition,uiPosition) == OK)
				return cGOTO;
		}

	return cERROR;
}

void Reciever_Empty(void)
{
	sRecieverBuffer.eStatus = EMPTY;
	sRecieverBuffer.ucCharCtr = 0;
}

void Reciever_PutCharacterToBuffer(char cCharacter)
{
	if(sRecieverBuffer.ucCharCtr == RECIEVER_SIZE)
		sRecieverBuffer.eStatus = OVERFLOW;
	else
	{
		if(cCharacter == TERMINATOR)
		{
			sRecieverBuffer.cData[sRecieverBuffer.ucCharCtr] = '\0';
			sRecieverBuffer.eStatus = READY;
			sRecieverBuffer.ucCharCtr = 0;
		}
		else
		{
			sRecieverBuffer.cData[sRecieverBuffer.ucCharCtr] = cCharacter;
			sRecieverBuffer.ucCharCtr++;
		}
	}
}

enum eRecieverStatus eReciever_GetStatus(void)
{
	return sRecieverBuffer.eStatus;
}

void Reciever_GetStringCopy(char *ucDestination)
{
	unsigned char ucCharacterCounter;
	for(ucCharacterCounter=0;sRecieverBuffer.cData[ucCharacterCounter]!='\0';ucCharacterCounter++)
		if(ucCharacterCounter==RECIEVER_SIZE)
			break;
		else
			ucDestination[ucCharacterCounter] = sRecieverBuffer.cData[ucCharacterCounter];
}
