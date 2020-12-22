#include "isnumber.h"
#include <string.h>

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
