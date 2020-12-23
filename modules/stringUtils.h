#ifndef STRINGUTILS_H
#define STRINGUTILS_H
char* immutibleToUpper(char* str);

char* immutibleToLower(char* str);

void mutibleToUpper(char* str);

void mutibleToLower(char* str);


void mutibleKillSpace(char* str);

char* immutibleKillSpace();


int isString(char *str);

int isNumber(char *str);


void mutibleFilt(char* str);

char* immutibleFilt(char* str);


void mutibleStrip(char* str);

char* immutibleStrip(char* str);
#endif
