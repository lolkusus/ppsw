typedef enum CompResult 
{ DIFFERENT , EQUAL } CompResult;

typedef enum Result 
{ OK, ERROR } Result;

enum CompResult eCompareString(char pcStr1[], char pcStr2[]);
enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue);
