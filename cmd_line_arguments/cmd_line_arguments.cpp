#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readArgs(int argc, char* argv[]);
void main(int argc, char* argv[])
{
	readArgs(argc, argv);
}

void readArgs(int argc, char* argv[]) {
	int i;
	printf("argc=%d\n", argc);
	for (i = 0; i < argc; i++)
		printf("argv[%d]= %s\n", i, argv[i]);
	
	system("pause");
}
