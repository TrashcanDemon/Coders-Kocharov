#include "../modules/upperlower.h"
#include "../modules/strip.h"
#include "../modules/caesar.h"
#include "../modules/xor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc < 3){
		printf("Не достаточно введённых данных.\n");
		printf("Ввод доолжен включать: вид кодирования, кодируймое слово, сдвиг/пароль.\n");
		return 0;
	}
	if ( (strcmp(argv[1], "-caesar") == 0)||(strcmp(argv[1], "-xor") == 0) ){
		printf("Пожалуйста вводите два '-' в аргумент кодера. Пример: --caesar\n");
		return 0;
	}
	mutibleToLower(argv[2]);
	mutibleStrip(argv[2]);
	if (strcmp(argv[1], "--caesar") == 0){
		int x = atoi(argv[3]);
		mutibleDecodeCaesar(argv[2], x);
	}
	if (strcmp(argv[1],"--xor") == 0){
		mutibleCodeXor(argv[2], argv[3]);
		mutibleToLower(argv[2]);
		char *xorWalker;
		xorWalker = argv[2];
		printf("Числовые значения xor вывода: ");
		while (*xorWalker != '\0'){
			printf("%d ", *xorWalker);
			xorWalker++;
		}
		printf("\n");
	}

	if (argv[2] == NULL){
		return 0;
	}
	printf("%s\n", argv[2]);
	return 0;
}
