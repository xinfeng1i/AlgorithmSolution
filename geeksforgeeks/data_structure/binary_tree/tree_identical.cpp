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

bool isIdenticalTree(Node* root1, Node* root2)
{
	if (root1 == NULL && root2 == NULL) return true;
	else if (root1 == NULL && root2 != NULL) return false;
	else if (root1 != NULL && root2 == NULL) return false;
	else
	{
		if (root1->data != root2->data) return false;
		else return isIdenticalTree(root1->left, root2->left) &&
			        isIdenticalTree(root1->right, root2->right);
	}
}
/* 时间复杂度：O(m) if (m < n)
 */


int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	Node* root2 = new Node(1);
	root2->left = new Node(2);
	root2->right = new Node(3);
	root2->left->left = new Node(4);
	root2->left->right = new Node(6);

	if (isIdenticalTree(root, root2))
		cout << "both tree are identical" << endl;
	else 
		cout << "the two trees are not identical " << endl;
	return 0;
}
