#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE  3
#include <stdio.h>
typedef struct queue
{
	int Items[MAXSIZE], front, rear;
} Queue;

//Initializes front and rear
void init(Queue* Q);
void enqueue(Queue* Q, int n);
int dequeue(Queue* Q);
void printQueue(const Queue Q);
char isEmpty(const Queue Q); //returns 1 if Q is Empty- Otherwise 0.
char isFull(Queue Q); //returns 1 if Q is Full Otherwise, 0.
char menu();

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
			printf("\n Dequque removed %d\n",dequeue(&Q));
			printQueue(Q);
			break;
		case '0': printf("\n Exit ");
			return(0);
		default:  printf("\n Wrong. Pls try again");
		}// switch    
	} // while
}// main

void init(Queue* Q) {
	Q->front = Q->rear = -1;
}

char isFull(const Queue Q) {
	return ((Q.rear + 1) % MAXSIZE == Q.front);
}
char isEmpty(const Queue Q) {
	return Q.front == -1;
}
void enqueue(Queue* Q, int val) {
	if (isFull(*Q)) { printf("Queue is Full\n"); return; }
	if (isEmpty(*Q)) {
		Q->front = 0;
	}
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->Items[Q->rear] = val;
}

int dequeue(Queue* Q) {
	if (isEmpty(*Q))
	{
		printf("Queue empty\n");	return 0;
	}
	int res = Q->Items[Q->front];
	if (Q->rear == Q->front) // there was only one item in the queue
	{
		Q->rear = Q->front = -1;
	}
	else {
		Q->front = (Q->front + 1) % MAXSIZE;
	}
	return res;
}

void printQueue(const Queue Q) {
	if (isEmpty(Q))
		return;
	int i = Q.front;
	while (i != Q.rear) {
		printf("%d, ", Q.Items[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("%d\n", Q.Items[Q.rear]);

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
