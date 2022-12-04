#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void readLines();
void readLinesEndLine();
void writeLine();

void main() {
    readLines();
    readLinesEndLine();
    writeLine();
}
void readLines() {
    char oneline[80];
    FILE* fin = fopen("test1.txt", "rt");

    if (fin == NULL) {
        printf("Unable to open file\n"); exit(1);
    }

    while (fgets(oneline, 80, fin) != NULL)
        puts(oneline);

    fclose(fin);
}
void readLinesEndLine() {
    FILE* pFile;
    char buffer[80];
    int counter = 1;
    pFile = fopen("test1.txt", "r");
    if (pFile == NULL)  printf("Error opening file");
    else {
        while (fgets(buffer, 80, pFile) != NULL)
            printf("%d%s", counter++, buffer);
        fclose(pFile);
    }
}

void writeLine() {
    FILE* pFile;
    char sentence[256];

    printf("Enter sentence to write: ");
    gets(sentence);

    pFile = fopen("somefile.txt", "w");
    fputs(sentence, pFile);
    fclose(pFile);

}