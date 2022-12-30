#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

node* createNode(int data) {
	node* temp;
	temp = (node*)malloc(sizeof(node));
	if (temp) {
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
	}
	return temp;
}
void insert(node* root, node* newNode)
{
	if (!root) return;
	if (newNode->data <= root->data) //left subtree (<=)
		if (root->left == NULL)
			root->left = newNode;
		else
			insert(root->left, newNode);

	if (newNode->data > root->data) //right subtree  (>)
		if (root->right == NULL)
			root->right = newNode;
		else
			insert(root->right, newNode);
}

node* search(node* root, int key)
{
	if (root == NULL) {
		printf("\n Item not found");
		return NULL;
	}
	if (root->data == key) {
		printf("\nThe %d Element is Present ", root->data);
		return root;
	}
	if (key > root->data)
		return search(root->right, key);
	else
		return search(root->left, key);

}
void inorder(node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d, ", root->data);
		inorder(root->right);
	}
}

void preorder(node* root)
{
	if (root != NULL)
	{
		printf("%d, ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d, ", root->data);
	}
}

node* getFather(node* root, node* t)
{
	if (root == NULL || root == t)
		return NULL; //Not Found! Or Tree is empty!

	if (root->left == t || root->right == t)  //one of the current node’s children 
		return root;

	if (t->data <= root->data)
		return getFather(root->left, t);

	return getFather(root->right, t);
}
node* minValueNode(node* root)
{
	node* current = root;
    // loop down to find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}
node* deleteNode(node* root, int key) 
{
	if (root == NULL) return root; //empty tree case

	if (key < root->data) //deleted item in the left tree
		root->left = deleteNode(root->left, key);
	if (key > root->data) //deleted item in the left tree
		root->right = deleteNode(root->right, key);

	if (key == root->data) {//deleted item found
		if (root->left == NULL && root->right == NULL) {
			free(root); 
			return NULL;
		}
		if (root->left == NULL || root->right == NULL) {
			node* temp = (root->left) ? root->left : root->right;
			free(root);
			return temp;
		}
		else {
			node* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}