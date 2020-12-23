#include "stringUtils.h"
#include <string.h>
#include <stdlib.h>

char* immutableToLower(char* str){
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

	mutableToLower(strRet);
	return strRet;
}

char* immutableToUpper(char* str){
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

	mutableToUpper(strRet);
	return strRet;
}

void mutableToLower(char* str){
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*str = *str + 32;
		}
		str++;
	}
}

void mutableToUpper(char* str){
	while (*str != '\0'){
		if (*str >= 'a' && *str <= 'z'){
			*str = *str - 32;
		}
		str++;
	}
}


void mutableKillSpace(char* str){
	char *strFirst;
	char *strLast;

	strFirst = str;
	strLast = str;	
	while (*strLast != '\0'){
		strLast++;
		if (*strFirst == ' '){
			strFirst++;
		}
	}
	while (*strLast == ' '){
		strLast--;
	}

	while (strFirst <= strLast){
		if (*strFirst != ' '){
			*str = *strFirst;
			str++;
		}
		strFirst++;
	}
	str = '\0';
}

char* immutableKillSpace(char* str){
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
	mutableKillSpace(strRet);
	return strRet;
}


int isString(char *str){
	while ( (*str != '\0')
			&&(((*str >= 'A') && (*str <= 'Z'))
			 ||((*str >= 'a') && (*str <= 'z'))) ){	
		str++;
	}
	if (*str != '\0')
		return (0);
	else
		return(1);
}

int isNumber(char *str){
	if ((*str == '+')||(*str == '-')){
			str++;
	}
	if (*str == '\0'){
		return (0);
	}
	while ((*str != '\0') && (*str <= '9') && (*str >= '0')){
		str++;
	}
	if (*str != '\0')
		return (0);
	else
		return(1);
}


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

void mutableFilt(char* str){
	char *strFirst;
	char *strLast;

	strFirst = str;
	strLast = str;	
	while (*strLast != '\0'){
		strLast++;
		if (isCorrect(*strFirst) == 1){
			strFirst++;
		}
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

char* immutableFilt(char* str){
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
	mutableFilt(strRet);
	return strRet;
}


void mutableStrip(char* str){
	char *strFirst;
	char *strLast;

	strFirst = str;
	strLast = str;	
	while (*strLast != '\0'){
		strLast++;
		if (*strFirst == ' '){
			strFirst++;
		}
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

char* immutableStrip(char* str){
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
	mutableStrip(strRet);
	return strRet;
}