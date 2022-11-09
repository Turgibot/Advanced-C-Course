
#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int value;
	struct node* next;
	struct node* prev;

} Node;

typedef struct DLList {

	Node* head;
	Node* tail;

} DLList;

Node* createNode(int data) {
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) { puts("allocation failed"); exit(1); }

	newNode->value = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}
void addLast(DLList* list, int data)
{
	Node* newnode = createNode(data);
	// since this is the new tail
	// its previous should be the previous tail  
	newnode->prev = list->tail;
	// if this is the first node in the list
	if (list->tail == NULL) {
		list->head = newnode;
	}
	else {
		list->tail->next = newnode;
	}
	list->tail = newnode;
}
void freeList(DLList list) {
	Node* head = list.head;
	while (head) {
		Node* tmp = head->next;
		free(head);
		head = tmp;
	}
}
void printBackwardsRec(Node* tail)
{
	if (tail == NULL)
		return;
	printf("%d  ", tail->value);
	printBackwardsRec(tail->prev);
}
void printListRec(Node* head)
{
	if (head == NULL)
		return;
	printf("%d  ", head->value);
	printListRec(head->next);
}
void printList(DLList list, int isForward) {
	if (isForward) {
		printListRec(list.head);
	}
	else {
		printBackwardsRec(list.tail);
	}
}
void addFirst(DLList* list, int data)
{
	Node* newnode = createNode(data);
	// since this is the new head
	// its next should be the old head
	newnode->next = list->head;

	// if this is the first node in the list
	if (list->head == NULL) {
		list->tail = newnode;
	}
	else {
		list->head->prev = newnode;
	}

	list->head = newnode;
}

void deleteFirst(DLList* list)
{
	if (list->head == NULL) {
		printf("no items to delete – the list is empty");
		return;
	}
	Node* nodeToDelete = list->head;
	list->head = list->head->next;

	if (list->head == NULL)
		list->tail = NULL;
	else
		list->head->prev = NULL;
	free(nodeToDelete);
}

void deleteLast(DLList* list)
{
	if (list->tail == NULL)
	{
		printf("no items to delete - the list is empty");
		return ;
	}
	Node* tmp = list->tail;
	list->tail = list->tail->prev;

	if (list->tail == NULL) //List is empty after deleting last
		list->head = NULL;
	else
		list->tail->next = NULL;
	free(tmp);
}


int main()
{
	DLList dLList = { NULL, NULL };

	for (size_t i = 1; i <= 10; i++)
	{
		addLast(&dLList, i);
	}

	printList(dLList, 1);
	printf("\n---------------\n");

	printf("Delete First:\n");
	deleteFirst(&dLList);
	printList(dLList, 1);

	printf("\n---------------\n");
	printf("Delete Last:\n");
	deleteLast(&dLList);
	printList(dLList, 1);
	
	freeList(dLList);
}