#include "m_caesar.h"
#include <string.h>
#include <stdlib.h>

void mutible_encode_caesar(char* str, int x){
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

char* immutible_encode_caesar(char* str, int x){
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_encode_caesar(str_ret, x);
	return str_ret;

}

void mutible_decode_caesar(char* str, int x){
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

char* immutible_decode_caesar(char* str, int x){
	char *str_new;
	char *str_ret;
	str_new = (char*)malloc(sizeof(char)*(strlen(str)+1));
	str_ret = str_new;
	while (*str != '\0'){
		*str_new = *str;
		str_new++;
		str++;
	}
	mutible_decode_caesar(str_ret, x);
	return str_ret;

}
