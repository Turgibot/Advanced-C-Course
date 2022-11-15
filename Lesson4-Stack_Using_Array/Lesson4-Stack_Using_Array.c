#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  10

typedef struct {
	int Items[MAXSIZE];
	int top;
} Stack_St;

void init(Stack_St* S);
void push(Stack_St* S, int n);
int  pop(Stack_St* S);
void display(Stack_St* S);
char isEmpty(const Stack_St* S);
char menu();

int main() {
	Stack_St Stack;
	int  num;
	init(&Stack);
	while (1) {
		switch (menu()) {
		case '1': printf("Enter the data: ");
			scanf("%d", &num);
			push(&Stack, num);
			display(&Stack);
			break;
		case '2': printf("\n Pop %d",
			pop(&Stack));
			display(&Stack);
			break;
		case '0': printf("\n Exit ");
			return(0);
		default:  printf("\n Wrong. Pls try again");
		}// switch    
	} // while
}// main

void init(Stack_St* S) {
	S->top = -1;
}

char isEmpty(const Stack_St* S) {
	return (S->top < 0);
}

void push(Stack_St* S, int newItem) {

	if (S->top == MAXSIZE - 1) {
		printf("\nSTACK  IS FULL");
		return;
	}
	S->Items[++(S->top)] = newItem;   //push it into the stack
}

int pop(Stack_St* S) {

	int item;

	if (isEmpty(S)) {
		printf("\nSTACK  IS EMPTY");
		return 0;
	}

	item = S->Items[S->top--];//pop it from the stack    
	return(item);
}

void display(Stack_St* S) {
	int i;
	printf(" top = %d\n", S->top);
	for (i = S->top; i >= 0; i--)
		printf(" value : %6d  location %3d\n", S->Items[i], i);
}

char menu() {
	printf("\n\t MAIN MENU: \n"
		"1. Add element to stack \n"
		"2. Delete element from the stack \n"
		"0. Exit \n"
		"\n Your choice: ");
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}
