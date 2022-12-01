#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

char** createStringArr(int);
void insertWord(char*, char**, int);
void printWords(char**, int);
void freeWords(char**, int);

void main() {
	char** words; int i, numWords; char input[MAX_SIZE];
	printf("enter no of words: ");
	char success = scanf("%d", &numWords);
	words = createStringArr(numWords);
	for (i = 0; i < numWords; i++) {
		printf("Enter word[%d]: ", i);
		success = scanf("%s", input);
		insertWord(input, words, i);
	}
	printWords(words, numWords);
	freeWords(words, numWords);
}
//Allocating Array of numWords pointers to strings 
char** createStringArr(int numWords) {
	char** words = (char**)malloc(sizeof(char*) * numWords);
	if (!words) {
		printf("Mem allocation failed");
		return(1);
	}
	return words;
}

//Allocating a string for a word and insert into words[i]
void insertWord(char* input, char** words, int i) {
	words[i] = (char*)malloc(strlen(input) + 1);
	if (!words[i]) {
		printf("Mem allocation failed");
		return(1);
	}
	strcpy(words[i], input);
}

void printWords(char** words, int numWords) {
	for (size_t i = 0; i < numWords; i++)
	{
		printf("%d:\t%s\n", i, words[i]);
	}
}

void freeWords(char** words, int numWords) {
	for (size_t i = 0; i < numWords; i++)
	{
		free(words[i]);
	}
	free(words);
}
