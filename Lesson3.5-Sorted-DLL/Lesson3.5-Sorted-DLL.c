
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

void insertNode(DLList* list, int data)
{
	Node* newNode = createNode(data);

	// if this is the first node in the list
	if (list->head == NULL) {
		list->head = newNode;
		list->tail = newNode;
		return;
	}
	//find the position to insert the new Node
	Node* curr = list->head;
	while (curr && data > curr->value) {
		curr = curr->next;
	}
	if (curr == NULL) { //item is max 
		newNode->prev = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
		return;
	}
	//item is first in the list
	if (curr == list->head) {
		list->head = newNode;
	}
	else {
		Node* prev = curr->prev;
		newNode->prev = prev;
		prev->next = newNode;
	}
	newNode->next = curr;
	curr->prev = newNode;
}

void removeNode(DLList* list, Node* node) {
	if (!list || !node) {
		printf("Invalid Data");
		return;
	}

	Node* curr = list->head;
	while (curr && node!=curr) {
		curr = curr->next;
	}
	if (!curr) {
		printf("ELEMENT WITH DATA %d NOT FOUND", node->value);
		return;
	}
	if (curr == list->head) {
		list->head = curr->next;
		curr->prev = NULL;
		if (list->head == NULL) {// there was only one item in the list so now its empty
			list->tail = NULL;
		}
	}
	else if(curr == list->tail)
	{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	else {
		Node* prev = curr->prev;
		Node* next = curr->next;
		prev->next = next;
		next->prev = prev;
	}
	free (node);
}

int main()
{
	DLList dLList = { NULL, NULL };

	for (size_t i = 0; i < 10; i++)
	{
		insertNode(&dLList, rand());
	}

	printList(dLList, 1);
	printf("\n---------------\n");
	Node* node = dLList.head->next->next;
	printf("Delete node with value: %d\n", node->value);
	removeNode(&dLList, node);
	printList(dLList, 1);
	printf("\n---------------\n");
	node = dLList.head->next->next->next->next;
	printf("Delete node with value: %d\n", node->value);
	removeNode(&dLList, node);
	printList(dLList, 1);

	freeList(dLList);
}