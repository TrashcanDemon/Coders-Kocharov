#include "m_isnumber.h"
#include <string.h>

int isnumber(char *str){
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
