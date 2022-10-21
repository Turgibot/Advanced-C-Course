
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN 30
typedef struct node {
	// data - this can be a seperate Student struct
	char name[LEN];
	int id;
	// pointer to the next node in the list
	struct node* next;

}StudentNode;

StudentNode* createStudentNode(const char* name, int id) {
	StudentNode* tmp = (StudentNode*)malloc(sizeof(StudentNode));
	if (!tmp) {
		puts("allocation failed");
		exit(0);
	}
	strcpy(tmp->name, name);
	tmp->id = id;
	tmp->next = NULL;
	return tmp;
}

void printStudent(StudentNode* node) {
	printf("name %s, id %d\n", node->name, node->id);
}
void main()
{
	StudentNode* head = createStudentNode("Guy", 123);
	printStudent(head);
	free(head);
}
