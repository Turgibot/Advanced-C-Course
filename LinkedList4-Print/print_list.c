#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 30

typedef struct node {
	char name[LEN];
	int id;
	int number;
	struct node* next;
} Node;

Node* addLast(Node* head, char* name, int id, int number)
{
	Node* tmp = (struct node*)malloc(sizeof(Node));
	if (tmp) {
		strcpy(tmp->name, name);
		tmp->id = id;
		tmp->number = number;
		tmp->next = NULL;
		//if list is empty this is the new head
		if (!head)
			return tmp;

		Node* ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = tmp;
	}
	else {
		puts("allocation failed - item not added");
	}
	return head;
}

void print(Node* head)
{
	Node* tmp;
	tmp = head;
	printf(" \nPrinting list :\n");
	while (tmp != NULL)
	{
		printf("name: %s, Id:%d, Number:%d\n", tmp->name, tmp->id, tmp->number);
		tmp = tmp->next;
	}
}

void printRec1(Node* head) {
	if (head == NULL)
		return;
	printf("name: %s, Id:%d, Number:%d\n", head->name, head->id, head->number);
	printRec1(head->next);
}

int freeList(Node* head) {
	while (head) {
		Node* tmp = head->next;
		free(head);
		head = tmp;
	}
}

void printRec2(Node* head) {
	if (head == NULL)
		return;
	printRec2(head->next);
	printf("name: %s, Id:%d, Number:%d\n", head->name, head->id, head->number);
}


void main() {
	Node* head = NULL;
	head = addLast(head, "1st", 1, 1);
	head = addLast(head, "2nd", 2, 2);
	head = addLast(head, "3rd", 3, 3);

	printRec2(head);

	freeList(head);

}

