#ifndef STRINGUTILS_H
#define STRINGUTILS_H
char* immutableToUpper(char* str);

char* immutableToLower(char* str);

void mutableToUpper(char* str);

void mutableToLower(char* str);


void mutableKillSpace(char* str);

char* immutableKillSpace();


int isString(char *str);

int isNumber(char *str);


void mutableFilt(char* str);

char* immutableFilt(char* str);


void mutableStrip(char* str);

char* immutableStrip(char* str);
#endif
