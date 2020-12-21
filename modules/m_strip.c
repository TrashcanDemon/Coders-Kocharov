#include "m_strip.h"
#include <string.h>
#include <stdlib.h>

void mutible_strip(char* str){
	char *str_first;
	char *str_last;

	str_first = str;
	str_last = str;	
	while (*str_first == ' '){
		str_first++;
	}
	while (*str_last != '\0'){
		str_last++;
	}
	str_last--;
	while (*str_last == ' '){
		str_last--;
	}
	str_last++;
	*str_last = '\0';
	while (*str_first != '\0'){
		*str = *str_first;
		str++;
		str_first++;
	}
	*str = '\0';
}

char* immutible_strip(char* str){
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_strip(str_ret);
	return str_ret;
}
