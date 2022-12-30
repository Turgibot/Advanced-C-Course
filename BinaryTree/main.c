#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


void showMenu();
void main(int argc, char* argv[])
{
	int choice;
	int key;
	node* newNode, * root, * tmp;
	root = NULL;
	do
	{
		showMenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: //Create
			do {
				printf("\nEnter The Element:");
				scanf("%d", &key);
				if (key <= 0)
					break;
				newNode = createNode(key);
				if (root == NULL)
					root = newNode;
				else
					insert(root, newNode);
				printf("\nEnter another element or 0 to stop");
			} while (1);
			break;
		case 2: //Search
			printf("\nEnter Element to be searched :");
			scanf("%d", &key);
			
			tmp = search(root, key);
			if (tmp == NULL)
				printf("\nThe node %d was not found", key);
			break;

		case 3: //Traversal
			if (root == NULL)
				printf("\nTree Is Not Created");
			else
			{
				printf("\nThe Inorder display : ");
				inorder(root);
			}
			break;
		case 4: //Quit
			printf("\nBye Bye...");
			return;
		default:
			printf("Invalid Choice %d", choice);
		} //end of switch block
	} while (choice != 4);
}   //end of main


void showMenu() {
	printf("\n1.Create");
	printf("\n2.Search");
	printf("\n3.Recursive Traversals");
	printf("\n4.Exit");
	printf("\nEnter your choice :");
}
