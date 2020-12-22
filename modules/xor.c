#include "xor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
