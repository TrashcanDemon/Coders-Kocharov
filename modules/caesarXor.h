#ifndef CAESARXOR_H
#define CAESARXOR_H
void mutableEncodeCaesar(char* str, int x);

char* immutableEncodeCaesar(char* str, int x);

void mutableDecodeCaesar(char* str, int x);

char* immutableDecodeCaesar(char* str, int x);

void mutableCodeXor(char* str, char* key);

char* immutableCodeXor(char* str, char* key);
#endif
