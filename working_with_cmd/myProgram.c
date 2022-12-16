#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void readArgs(int argc, char* argv[]);
int copy(int argc, char* argv[]);

void main(int argc, char* argv[])
{
	readArgs(argc, argv);
	copy(argc, argv);

}

void readArgs(int argc, char* argv[]) {
	int i;
	printf("argc=%d\n", argc);
	for (i = 0; i < argc; i++)
		printf("argv[%d]= %s\n", i, argv[i]);

	system("pause");
}

int copy(int argc, char* argv[])
{
	int ch, status = 0; //success 
	FILE* in, * out;
	if (argc != 3)
	{
		printf("Error : Illegal number of arguments\n");
		printf("Usage: %s inputFile outputFile\n", argv[0]);
		exit(1);
	}
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		printf("Error in opening file %s\n", argv[1]);
		exit(1);
	}
	if ((out = fopen(argv[2], "w")) == NULL)
	{
		printf("Error in opening file %s\n", argv[2]);
		exit(1);
	}
	while ((ch = fgetc(in)) != EOF)
		fputc(ch, out);

	if (fclose(in)) {
		printf("Error in closing file %s\n", argv[1]);
		status = 1; //failure}
		if (fclose(out)) {
			printf("Error in closing file %s\n", argv[2]);
			status = 1; //failure}
			return status;

		}
	}
}