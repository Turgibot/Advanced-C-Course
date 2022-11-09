

#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int value;
    struct node* next;
    struct node* prev;

} Node;


Node* createNode(int data) {
    Node* newNode;
    newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) { puts("allocation failed"); exit(1); }

    newNode->value = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


int main()
{
    Node* firstNode = createNode(123);
    free(firstNode);
}
