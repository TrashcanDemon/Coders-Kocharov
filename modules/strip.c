#include "strip.h"
#include <string.h>
#include <stdlib.h>

void mutibleStrip(char* str){
	char *strFirst;
	char *strLast;

	strFirst = str;
	strLast = str;	
	while (*strFirst == ' '){
		strFirst++;
	}
	while (*strLast != '\0'){
		strLast++;
	}
	strLast--;
	while (*strLast == ' '){
		strLast--;
	}
	strLast++;
	*strLast = '\0';
	while (*strFirst != '\0'){
		*str = *strFirst;
		str++;
		strFirst++;
	}
	*str = '\0';
}

char* immutibleStrip(char* str){
	char *strNew;
	char *strRet;
	strNew = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strRet = strNew;
	while (*str != '\0'){
		*strNew = *str;
		strNew++;
		str++;
	}
	*strNew = '\0';
	mutibleStrip(strRet);
	return strRet;
}
