#include "m_upperlower.h"
#include <string.h>
#include <stdlib.h>

char* immutible_tolower(char* str){
	char *str_new;
	char *str_ret;

	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*str_new = *str + 32;
		}
		else{
			*str_new = *str;
		}
		str_new++;
		str++;
	}

	*str_new = '\0';
	return str_ret;
}

char* immutible_toupper(char* str){
	char *str_new;
	char *str_ret;

	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		if (*str >= 'a' && *str <= 'z'){
			*str_new = *str - 32;
		}
		else{
			*str_new = *str;
		}
		str_new++;
		str++;
	}

	*str_new = '\0';
	return str_ret;
}

void mutible_tolower(char* str){
	while (*str != '\0'){
		if (*str >= 'A' && *str <= 'Z'){
			*str = *str + 32;
		}
		str++;
	}
}

void mutible_toupper(char* str){
	while (*str != '\0'){
		if (*str >= 'a' && *str <= 'z'){
			*str = *str - 32;
		}
		str++;
	}
}
