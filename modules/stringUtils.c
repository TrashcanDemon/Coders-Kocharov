#include "stringUtils.h"
#include <string.h>
#include <stdlib.h>

char* immutibleToLower(char* str){
	char *strNew;
	char *strRet;

	strNew = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strRet = strNew;
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*strNew = *str + 32;
		}
		else{
			*strNew = *str;
		}
		strNew++;
		str++;
	}

	*strNew = '\0';
	return strRet;
}

char* immutibleToUpper(char* str){
	char *strNew;
	char *strRet;

	strNew = (char*)malloc(sizeof(char)*(strlen(str)+1));
	strRet = strNew;
	while (*str != '\0'){
		if (*str >= 'a' && *str <= 'z'){
			*strNew = *str - 32;
		}
		else{
			*strNew = *str;
		}
		strNew++;
		str++;
	}

	*strNew = '\0';
	return strRet;
}

void mutibleToLower(char* str){
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*str = *str + 32;
		}
		str++;
	}
}

void mutibleToUpper(char* str){
	while (*str != '\0'){
		if (*str >= 'a' && *str <= 'z'){
			*str = *str - 32;
		}
		str++;
	}
}


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

	while (strFirst <= strLast){
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