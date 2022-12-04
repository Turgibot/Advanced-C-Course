#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void example();
void useFEOF();
void copyFileExample();

void main() {
    //example();
    //useFEOF();
    copyFileExample();
}

void example() {
    char str[80];   
    float f;   
    FILE* pFile;
    pFile = fopen("myData.txt", "w+");
    if (pFile == NULL) exit(1);

    fprintf(pFile, "%f%s", 3.1416, "PI");
    rewind(pFile);	//return the pointer to start
    fscanf(pFile, "%f", &f);
    fscanf(pFile, "%s", str);
    fclose(pFile);
    printf("I have read: %f and %s \n", f, str);

}

void useFEOF() {
    FILE* pFile;
    char buffer[80];
    pFile = fopen("myfile.txt", "r");
    if (pFile == NULL)
        fprintf(stdout, "Error opening file"); //screen
    else
    {
        while (!feof(pFile))
            if (fgets(buffer, 80, pFile) != NULL)
                fprintf(stdout, "%s", buffer); //screen

        if (fclose(pFile))
            fprintf(stdout, "Error in closing file");
    }

}

void copyFileExample() {
    int ch; 
    FILE* fsource = fopen("myfile.txt", "rt");  //open read only
    FILE *fdestination = fopen("mycopy.txt","wt+");//open – write + read  
    if (!fsource || !fdestination) {
        puts("Unable to open file...\n"); exit(1);
    }
    do {
        ch = fgetc(fsource); //read 1 char 
        if  (ch!=' ' && ch!=EOF) 
            fputc(ch, fdestination);//not ‘ ‘ nor EOF
    } while (ch != EOF);

    fclose(fsource);	 //close file 

    // Print the new file to screen
    fseek(fdestination, 0, SEEK_SET);

    while((ch = fgetc(fdestination)) != EOF) //read one char
        putchar(ch);// display char

    putchar('\n');

    fclose(fdestination);//close file 
    printf("End of program...\n");

}