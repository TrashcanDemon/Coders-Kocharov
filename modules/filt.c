#include "filt.h"
#include <string.h>
#include <stdlib.h>

static int isCorrect(char a){
	int x;
	if  (	(a == ' ')
			|| ((a >= '0')&&(a <= '9'))
			|| ((a >= 'A')&&(a <= 'Z'))
			|| ((a >= 'a')&&(a <= 'z')) ){
		x = 0;
	}
	else{
		x = 1;
	}
	return x;
}

void mutibleFilt(char* str){
	char *strFirst;
	char *strLast;

	strFirst = str;
	strLast = str;	
	while (isCorrect(*strFirst) == 1){
		strFirst++;
	}
	while (*strLast != '\0'){
		strLast++;
	}
	while (isCorrect(*strFirst) == 1){
		strLast--;
	}

	while (strFirst <= strLast){
		if (isCorrect(*strFirst) == 0){
			*str = *strFirst;
			str++;
		}
		strFirst++;
	}
	*str = '\0';
}

char* immutibleFilt(char* str){
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
	mutibleFilt(strRet);
	return strRet;
}
