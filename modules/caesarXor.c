#include "caesarXor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mutibleEncodeCaesar(char* str, int x){
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

char* immutibleEncodeCaesar(char* str, int x){
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
	mutibleEncodeCaesar(strRet, x);
	return strRet;

}

void mutibleDecodeCaesar(char* str, int x){
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

char* immutibleDecodeCaesar(char* str, int x){
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
	mutibleDecodeCaesar(strRet, x);
	return strRet;

}


void mutibleCodeXor(char* str, char* key){
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

char* immutibleCodeXor(char* str, char* key){
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
	mutibleCodeXor(strRet, key);
	return strRet;

}
