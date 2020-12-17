#include "m_filt.h"
#include <string.h>
#include <stdlib.h>

static int iscorrect(char a){
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

void mutible_filt(char* str){
	char *str_first;
	char *str_last;

	str_first = str;
	str_last = str;	
	while (iscorrect(*str_first) == 1){
		str_first++;
	}
	while (*str_last != '\0'){
		str_last++;
	}
	while (iscorrect(*str_first) == 1){
		str_last--;
	}

	while (str_first <= str_last){
		if (iscorrect(*str_first) == 0){
			*str = *str_first;
			str++;
		}
		str_first++;
	}
	*str = '\0';
}

char* immutible_filt(char* str){
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_filt(str_ret);
	return str_ret;
}
