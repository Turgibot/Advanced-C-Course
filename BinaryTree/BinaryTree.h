#pragma once
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;
node* createNode(int data);
void insert(node* root, node* newNode);
node* search(node* root, int key);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
node* getFather(node* root, node* t);
node* minValueNode(node* root);
node* deleteNode(node* root, int key);
