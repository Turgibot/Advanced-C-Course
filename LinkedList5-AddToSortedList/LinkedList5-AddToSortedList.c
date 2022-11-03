// LinkedList5-AddToSortedList.cpp : This file contains the 'main' function. Program execution begins and ends there.

//
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int id;
	struct node* next;
}Node;


Node* addSerialNode(Node* head, int newId)
{
	//create a new node
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) { puts("allocation failure"); return head; }
	newNode->id = newId;
	newNode->next = NULL;
	// handle an empty list
	if (head == NULL) { 
		newNode->next = NULL;
		return newNode; // the new node is the head of the list
	}
	// traverse until the ordered location or until the end of the list
	// the new node should enter between prev and curr
	Node* curr = head, *prev = NULL;
	while (curr != NULL && curr->id < newId)
	{
		prev = curr; 
		curr = curr->next;
	}
	newNode->next = curr;
	// prev remains null if the new node is first in the ordered list
	if (prev)
		prev->next = newNode;
	else  
		head = newNode;
	return head;
}

void print(Node* head)
{
	Node* tmp;
	tmp = head;
	printf(" \nPrinting list :\n");
	while (tmp != NULL)
	{
		printf("Id:%d\n", tmp->id);
		tmp = tmp->next;
	}
}

int freeList(Node* head) {
	Node* tmp;
	while (head) {
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
void main()
{
	Node* head = NULL;
	int id1 = 234, id2 = 33, id3 = 444;
	head = addSerialNode(head, id1);
	//head = addSerialNode(head, id2);
	//head = addSerialNode(head, id3);

	print(head);

	freeList(head);
}
