#ifndef STRINT_H
#define STRINT_H

#include "screen.h"
#include "kb.h"
#include "string.h"
#include "substr.h"

int32 strToInt(string str, uint8 len) 
{ 
    int32 res = 0;
	uint16 i = 0;
	if (str[0] == '-') i = 1;
    for (i; i < len && str[i] != '\0'; ++i) 
        res = res*10 + str[i] - '0'; 
    if (str[0] == '-')
		return -res;
	else
		return res;
}

#endif
