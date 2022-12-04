#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void example();


void main() {
    example();
  
}

void example() {
    char str[80];   
    float f;   
    FILE* pFile;
    pFile = fopen("myfile.txt", "w+");
    if (pFile == NULL) exit(1);

    fprintf(pFile, "%f%s", 3.1416, "PI");
    rewind(pFile);	//return the pointer to start
    fscanf(pFile, "%f", &f);
    fscanf(pFile, "%s", str);
    fclose(pFile);
    printf("I have read: %f and %s \n", f, str);

}
