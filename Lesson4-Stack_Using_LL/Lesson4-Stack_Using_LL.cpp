#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node* next;
} node;

typedef struct {
	node* top;
} Stack_St;

//Note the signatures of the functions are the same as in the array implementation!

void init(Stack_St* S);
char isEmpty(const Stack_St* S);
void push(Stack_St* S, int n);
int  pop(Stack_St* S);
void display(const Stack_St* S);
char menu();


void init(Stack_St* S) {
	S->top = NULL;
}

char isEmpty(const Stack_St* S) {
	return (!(S->top));
}
