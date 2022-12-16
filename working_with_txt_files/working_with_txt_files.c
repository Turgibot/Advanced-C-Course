#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void example();
void useFEOF();
void copyFileExample();
void printThreeChars();
void change_members();

void main() {
    //example();
    //useFEOF();
    //copyFileExample();
    printThreeChars();
    change_members();
    printThreeChars();

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

void printThreeChars() {
    FILE* f = fopen("myThrees.txt", "rt");
    if (!f) {
        puts("Unable to open file...\n"); exit(1);
    }
    char ch_data[4];
    fseek(f, 0, SEEK_SET); //rewind(f)
    do {
        if (fgets(ch_data, 4, f) == NULL)
            break;
        printf("%s,", ch_data);
    } while (1);
    printf("\n");
}
void change_members() {
    FILE* f = fopen("myThrees.txt", "r+t");
    if (!f) {
        puts("Unable to open file...\n"); exit(1);
    }
    char ch_data1[4], ch_data2[4];
    int i, dim;
    fseek(f, 0, SEEK_END);
    dim = ftell(f) / 3; //count array members  
    fseek(f, 0, SEEK_SET); // Go back to file start

    for (i = 0; i < dim / 2; i++) {
        //find the start of the current member and read it
        fseek(f, 3 * i, SEEK_SET);
        fgets(ch_data1, 4, f);
        //find the start of the symmetrical member and read it
        fseek(f, -3 * (i + 1), SEEK_END);
        fgets(ch_data2, 4, f);
        //write replacement
        fseek(f, 3 * i, SEEK_SET);        // replace 1
        fputs(ch_data2, f);
        fseek(f, -3 * (i + 1), SEEK_END); // replace 2      
        fputs(ch_data1, f);
    }//for
}