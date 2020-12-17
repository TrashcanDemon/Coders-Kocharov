#include "m_xor.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void mutible_code_xor(char* str, char* key){
	if (strlen(key) < strlen(str)){
		printf("Key length must not be shorter than the string.\n");
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

char* immutible_code_xor(char* str, char* key){
	if (strlen(key) < strlen(str)){
		printf("Key length must not be shorter than the string.\n");
		return (NULL);
	}
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_code_xor(str_ret, key);
	return str_ret;

}
