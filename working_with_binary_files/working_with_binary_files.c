#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x; char ch;
} record;

void writeAsBinary();
void readFromBinary();
void readFromEnd();
void main()
{
	writeAsBinary();
	readFromBinary();
	readFromEnd();
}

void readFromBinary() {
	FILE* pbfile;
	record my_record;
	pbfile = fopen("test.bin", "rb");
	if (!pbfile)  printf("Unable to open file!");
	else {
		while (fread(&my_record, sizeof(record), 1, pbfile) != NULL) {
			printf("%d %c\n", my_record.x, my_record.ch);
		}
		fclose(pbfile);
	}

}

void readFromEnd() {
	FILE* pbfile;
	record my_record;
	int amount = 0;
	pbfile = fopen("test.bin", "rb");
	if (!pbfile)  printf("Unable to open file!");
	else {
		fseek(pbfile, 0, SEEK_END);
		amount = ftell(pbfile) / sizeof(record);
		for (int i = 1; i <= amount; i++) {
			fseek(pbfile, -i * sizeof(record), SEEK_END);
			fread(&my_record, sizeof(record), 1, pbfile);
			printf("%d %c\n", my_record.x, my_record.ch);
		}
		fclose(pbfile);
	}

}

void writeAsBinary() {
	int counter;
	FILE* pbfile;
	record my_record;
	my_record.ch = 'A';

	pbfile = fopen("test.bin", "wb");
	if (!pbfile)  printf("Unable to open file!");
	else {
		for (counter = 1; counter <= 10; counter++) {
			my_record.x = counter;
			my_record.ch++;
			fwrite(&my_record, sizeof(record), 1, pbfile);
		}
		fclose(pbfile);
	}

}