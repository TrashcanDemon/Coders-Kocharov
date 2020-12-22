#include "../modules/upperlower.h"
#include "../modules/strip.h"
#include "../modules/caesar.h"
#include "../modules/xor.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if (argc > 1){
		if (argc < 4){
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
			mutibleEncodeCaesar(argv[2], x);
		}
		if (strcmp(argv[1],"--xor") == 0){
			int oldLength = strlen(argv[2]);
			mutibleCodeXor(argv[2], argv[3]);
			mutibleToLower(argv[2]);
			char *xorWalker;
			xorWalker = argv[2];
			printf("Числовые значения xor вывода: ");
			for(int i = 0; i < oldLength; i++){
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
	else{
		int i = 0;
		char readType[6];
		char readWord[256];
		char readKey[256];
		
		printf("Вы выбрали режим без аргументов.\n");
		printf("В данном режиме пробелы не считываются и строки не длиннее 256 сиволов.\n");
		printf("Для расширенной работы с кодерами используйте аргументы.\n");
		printf("Введите тип кодирования: 'caesar' или 'xor'.\n");
		scanf("%s", &readType[0]);
		printf("Введите кодируймое слово.\n");
		scanf("%s", &readWord[0]);
		printf("Введите ключ/отступ.\n");
		scanf("%s", &readKey[0]);
		
		char *type;
		char *typeRet;
		type = (char*)malloc(sizeof(char)*(strlen(readType)+1));
		typeRet = type;
		while (readType[i] != '\0'){
			*type = readType[i];
			type++;
			i++;
		}
		*type = '\0';
		
		char *key;
		char *keyRet;
		key = (char*)malloc(sizeof(char)*(strlen(readKey)+1));
		keyRet = key;
		i = 0;
		while (readKey[i] != '\0'){
			*key = readKey[i];
			key++;
			i++;
		}
		*key = '\0';
		
		if ( (strcmp(typeRet, "caesar") != 0)&&(strcmp(typeRet, "xor") != 0) ){
			printf("Пожалуйста вводите только caesar или xor в аргумент кодера. Пример: caesar\n");
			return 0;
		}

		char *codableWord;
		char *codableRet;
		codableWord = (char*)malloc(sizeof(char)*(strlen(readWord)+1));
		codableRet = codableWord;
		i = 0;
		while (readWord[i] != '\0'){
			*codableWord = readWord[i];
			codableWord++;
			i++;
		}
		*codableWord = '\0';

		mutibleToLower(codableRet);
		mutibleStrip(codableRet);
		if (strcmp(typeRet, "caesar") == 0){
			int x = atoi(keyRet);
			mutibleEncodeCaesar(codableRet, x);
		}
		if (strcmp(typeRet,"xor") == 0){
			int oldLength = strlen(codableRet);
			mutibleCodeXor(codableRet, keyRet);
			mutibleToLower(codableRet);
			char *xorWalker;
			xorWalker = codableRet;
			printf("Числовые значения xor вывода: ");
			for(i = 0; i < oldLength; i++){
				printf("%d ", *xorWalker);
				xorWalker++;
			}
			printf("\n");
		}

		if (codableRet == NULL){
			return 0;
		}
		printf("%s\n", codableRet);
		return 0;
	}
}
