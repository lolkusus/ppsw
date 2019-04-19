#include "command_decoder.h"
#include "string.h"

#define MAX_KEYWORD_STRING_LTH 6
#define MAX_KEYWORD_NR 3

typedef struct Keyword
{
enum CommandType eCode;
char cString[MAX_KEYWORD_STRING_LTH + 1];
} Keyword;

struct Keyword asKeywordList[MAX_KEYWORD_NR]= 
{
{cCALLIB, "callib"},
{cLEFT, "left" },
{cRIGHT, "right"}
};

enum CommandType eDecodeCommand(char cTokenString[])
{
	unsigned char ucTokenCounter;
	for(ucTokenCounter=0;ucTokenCounter<MAX_KEYWORD_NR;ucTokenCounter++)
	{
		if (eCompareString(asKeywordList[ucTokenCounter].cString,cTokenString) == EQUAL) 
		{
			return asKeywordList[ucTokenCounter].eCode;
		}
	}
	return cERROR;
}
