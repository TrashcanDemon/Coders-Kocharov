#include "killspace.h"
#include <string.h>
#include <stdlib.h>

void mutibleKillSpace(char* str){
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
	while (*strLast == ' '){
		strLast--;
	}

	while (strFirst <= strFast){
		if (*strFirst != ' '){
			*str = *strFirst;
			str++;
		}
		strFirst++;
	}
	str = '\0';
}

char* immutibleKillSpace(char* str){
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
	mutibleKillSpace(strRet);
	return strRet;
}
