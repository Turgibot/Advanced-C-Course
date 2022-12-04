#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>


void readEachChar();
void writeEachChar();
int main() {
	
	readEachChar();
	writeEachChar();

	
	return 0;
}

void readEachChar() {
	FILE* pFile;
	char c;

	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL) {
		printf("Error opening file"); exit(1);
	}
	while ((c = fgetc(pFile)) != EOF)
		putchar(c);// display char in cmd
	fclose(pFile);
}

void writeEachChar() {
	FILE* pFile;
	char c;

	pFile = fopen("alphabet.txt", "w");
	if (pFile == NULL) {
		printf("Error opening file"); exit(1);
	}
	for (c = 'A'; c <= 'Z'; c++)
		fputc(c, pFile);

	fclose(pFile);
}
