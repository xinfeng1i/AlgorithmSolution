#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int key):data(key),left(NULL),right(NULL){}
};

void PreOrder(Node* root)
{
	if (root == NULL) return;

	cout << " " << root->data;
	PreOrder(root->left);
	PreOrder(root->right);
}

void InOrder(Node* root)
{
	if (root == NULL) return;
	InOrder(root->left);
	cout << " " << root->data;
	InOrder(root->right);
}

void PostOrder(Node* root)
{
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << " " << root->data;
}
/*
 * 时间复杂度：O(n)
 * 最坏情况下，成为线性
 */

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	cout << "\n PreOrder: \n" << endl;
	PreOrder(root);
	cout << "\n InOrder: \n" << endl;
	InOrder(root);
	cout << "\n PostOrder: \n" << endl;
	PostOrder(root);

	cout << endl;
	return 0;
}
