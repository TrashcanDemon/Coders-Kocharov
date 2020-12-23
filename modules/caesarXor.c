#include "caesarXor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mutableEncodeCaesar(char* str, int x){
	while (*str != '\0'){
		if ( (*str >= 'A')&&(*str <= 'Z') ){
			if ((*str + x) > 91){
				*str = (*str + x) - 91 + 64;
			}
			else{
				*str = *str + x;
			}
		}
		if ( (*str >= 'a')&&(*str <= 'z') ){
			if ((*str + x) > 122){
				*str = (*str + x) - 122 + 96;
			}
			else{
				*str = *str + x;
			}
		}
		str++;
	}
}

char* immutableEncodeCaesar(char* str, int x){
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
	mutableEncodeCaesar(strRet, x);
	return strRet;

}

void mutableDecodeCaesar(char* str, int x){
	while (*str != '\0'){
		if ( (*str >= 'A')&&(*str <= 'Z') ){
			if ((*str - x) < 65){
				*str = 91 - (65 - (*str - x));
			}
			else{
				*str = *str - x;
			}
		}
		if ( (*str >= 'a')&&(*str <= 'z') ){
			if ((*str - x) < 97){
				*str = 123 - (97 - (*str - x));
			}
			else{
				*str = *str - x;
			}
		}
		str++;
	}

}

char* immutableDecodeCaesar(char* str, int x){
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
	mutableDecodeCaesar(strRet, x);
	return strRet;

}


void mutableCodeXor(char* str, char* key){
	if (strlen(key) < strlen(str)){
		printf("Key length must not be shorter than the string.");
		printf(" No changes made.\n");
		return;
	}
	while (*str != '\0'){
		while (*str && *key){
			*str = *str ^ *key;
			str++;
			key++;
		}
	}
}

char* immutableCodeXor(char* str, char* key){
	if (strlen(key) < strlen(str)){
		printf("Key length must not be shorter than the string.\n");
		return (NULL);
	}
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
	mutableCodeXor(strRet, key);
	return strRet;

}
