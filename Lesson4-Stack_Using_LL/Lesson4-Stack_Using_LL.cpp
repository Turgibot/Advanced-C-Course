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

void init(Stack_St* stack);
char isEmpty(const Stack_St* stack);
void push(Stack_St* stack, int n);
int  pop(Stack_St* stack);
void display(const Stack_St* stack);
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




void init(Stack_St* stack) {
	stack->top = NULL;
}

char isEmpty(const Stack_St* stack) {
	return (!(stack->top));
}

void push(Stack_St* stack, int val) {
	stack->top = addFirst(stack->top, val);
}

node* addFirst(node* head, int val)
{
	node* tmp = (struct node*)malloc(sizeof(node));
	if (tmp) {
		tmp->val = val;
		tmp->next = head;
		return tmp;
	}
	else {
		puts("allocation failed - item not added");
		return head;
	}
}

int pop(Stack_St* stack) {
	if (isEmpty(stack)) {
		printf("\nSTACK  IS EMPTY"); 
		return;
	}
	int val = stack->top->val;
	removeFirst(stack); //pop it from the stack    
	return val;
}

void removeFirst(Stack_St* stack) {
	node* tmp = stack->top;
	stack->top = stack->top->next;
	free(tmp);
}

void display(Stack_St* S)
{
	print(S->top);
}


void print(node* head)
{
	node* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" % d ", tmp->val);
		tmp = tmp->next;
	}
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
