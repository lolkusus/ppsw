#include "string.h"

enum CompResult eCompareString(char pcStr1[], char pcStr2[])
{
	unsigned char ucCharCounter;
	for(ucCharCounter=0;pcStr1[ucCharCounter] != '\0';ucCharCounter++)
	{
		if (pcStr1[ucCharCounter] != pcStr2[ucCharCounter]) return DIFFERENT;
	}
	return EQUAL;
}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar)
{
	unsigned char ucCharCounter;
	for(ucCharCounter=0;pcString[ucCharCounter]!='\0';ucCharCounter++)
	{
		if(pcString[ucCharCounter] == cOldChar) pcString[ucCharCounter] = cNewChar;
	}
}

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue)
{
	unsigned char ucCharCounter;
	if((pcStr[0] != '0') | (pcStr[1] != 'x') | (pcStr[2] == '\0'))
		return ERROR;
	*puiValue = 0;
	for(ucCharCounter=2;ucCharCounter<7;ucCharCounter++)
	{
		if(pcStr[ucCharCounter] == '\0') 
			return OK;
	  *puiValue = *puiValue << 4;
		if(pcStr[ucCharCounter] >= 'A') 
			*puiValue = *puiValue | (pcStr[ucCharCounter] - 'A' + 10); 
		else 
			*puiValue = *puiValue | (pcStr[ucCharCounter] - '0');
	}
	return OK;
}
