#include "m_upperlower.h"
#include "m_strip.h"
#include "m_caesar.h"
#include "m_xor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc < 3){
		printf("Не достаточно введённых данных.\n
		Ввод доолжен включать: вид кодирования, кодируймое слово, сдвиг/пароль.\n");
		return 0;
	}
	mutible_tolower(argv[2]);
	mutible_strip(argv[2]);
	if (strcmp(argv[1], "--caesar") == 0){
		int x = atoi(argv[3]);
		mutible_encode_caesar(argv[2], x);
	}
	if (strcmp(argv[1],"--xor") == 0){
		mutible_code_xor(argv[2], argv[3]);
		mutible_tolower(argv[2]);
	}

	if (argv[2] == NULL){
		return 0;
	}
	printf("%s\n", argv[2]);
	return 0;
}
