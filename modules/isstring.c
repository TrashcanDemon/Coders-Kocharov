#include "isstring.h"
#include <string.h>

int isString(char *str){
	while ( (*str != '\0')
			&&(((*str >= 'A') && (*str <= 'Z'))
			 ||((*str >= 'a') && (*str <= 'z'))) ){	
		str++;
	}
	if (*str != '\0')
		return (0);
	else
		return(1);
}
