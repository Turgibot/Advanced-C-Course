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
	int res = stack->top->val;
	stack->top = removeFirst(&(stack->top))//pop it from the stack    

		return(res);
}

void removeFirst(node** head) {
	if (*head == NULL) return; //if stack empty
	node* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}