
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

void freeList(Node* head) {
    while (head) {
        Node* tmp = head->next;
        free(head);
        head = tmp;
    }
}

void printBackwards(Node* tail)
{
    Node* tmp;
    tmp = tail;
    printf("\nPrinting a list: ");
    while (tmp != NULL)
    {
        printf("%d  ", tmp->value);
        tmp = tmp->prev;
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

int main()
{
    DLList ddlist = { NULL, NULL };

    addLast(&ddlist, 10);
    addLast(&ddlist, 20);
    addLast(&ddlist, 30);

    printListRec(ddlist.head);
    freeList(ddlist.head);
}
