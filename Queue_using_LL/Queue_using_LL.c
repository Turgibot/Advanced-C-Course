#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE  3
#include <stdio.h>
#include <stdlib.h>
typedef struct elem {// an element in the queue
	int val;
	struct elem* next;
} elem;

typedef struct queue
{
	int count;
	elem* front;
	elem* rear;
} Queue;


//Initializes front and rear
void init(Queue* Q);
void enqueue(Queue* Q, int n);
int dequeue(Queue* Q);
void printQueue(const Queue Q);
char isEmpty(const Queue Q); //returns 1 if Q is Empty- Otherwise 0.
char isFull(Queue Q); //returns 1 if Q is Full Otherwise, 0.
char menu();
void freeMem(Queue* Q);

void main() {
	Queue Q;
	init(&Q);
	int num;
	while (1) {
		switch (menu()) {
		case '1':
			if (isFull(Q)) {
				printf("\n Queue is full try again later");
				continue;
			}
			printf("Enqueue the data: ");
			scanf("%d", &num);
			enqueue(&Q, num);
			printQueue(Q);
			break;
		case '2':
			if (isEmpty(Q)) {
				printf("\n Nothing to remove from an empty queue");
				continue;
			}
			printf("\n Dequque removed %d\n", dequeue(&Q));
			printQueue(Q);
			break;
		case '0': printf("\n Exit ");
			freeMem(&Q);
			return(0);
		default:  printf("\n Wrong. Pls try again");
		}// switch    
	} // while
}// main

void init(Queue* Q) {
	Q->count = 0;
	Q->front = NULL;
	Q->rear = NULL;
}

char isFull(const Queue Q) {
	return Q.count == MAXSIZE;
}
char isEmpty(const Queue Q) {
	return Q.front == NULL;
}
void enqueue(Queue* Q, int val) {
	if (isFull(*Q)) { printf("Queue is Full\n"); return; }
	elem* element = (elem*)malloc(sizeof(elem));
	if (!element) { printf("Mem Allocation failed\n"); return; }
	element->val = val;
	element->next = NULL;

	if (isEmpty(*Q))
		Q->front = element;
	else
		Q->rear->next = element;

	Q->rear = element;
	Q->count++;
}

int dequeue(Queue* Q) {
	if (isEmpty(*Q))
	{
		printf("Queue empty\n"); return 0;
	}
	int res = Q->front->val;
	elem* elemToDelete = Q->front;
	Q->front = Q->front->next;

	if (Q->front == NULL) // there was only one item in the queue
		Q->rear = NULL;

	Q->count--;
	free(elemToDelete);
	return res;
}

void printQueue(const Queue Q) {
	if (isEmpty(Q))
		return;
	elem* elemToPrint = Q.front;
	while (elemToPrint) {
		printf("%d, ", elemToPrint->val);
		elemToPrint = elemToPrint->next;
	}
	
}


char menu() {
	printf("\n\t MAIN MENU: \n"
		"1. Add element to queue (UNQUEUE) \n"
		"2. Remove element from the queue (DEQUEUE)\n"
		"0. Exit \n"
		"\n Your choice: ");
	fseek(stdin, 0, SEEK_END);
	return(getchar());
}


void freeMem(Queue* queue) {
	while (!isEmpty(*queue)) {
		dequeue(queue);
	}
	printf("\nqueue deleted from memory");
}