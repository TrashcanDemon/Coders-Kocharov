#include "m_killspace.h"
#include <string.h>
#include <stdlib.h>

void mutible_killspace(char* str){
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
	while (*str_last == ' '){
		str_last--;
	}

	while (str_first <= str_last){
		if (*str_first != ' '){
			*str = *str_first;
			str++;
		}
		str_first++;
	}
	str = '\0';
}

char* immutible_killspace(char* str){
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_killspace(str_ret);
	return str_ret;
}
