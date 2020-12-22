#include "upperlower.h"
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
