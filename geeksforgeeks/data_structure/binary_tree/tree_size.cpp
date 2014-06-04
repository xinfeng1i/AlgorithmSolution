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

int treeSize(Node* root)
{
	if (root == NULL) return 0;
	return treeSize(root->left) + treeSize(root->right) + 1;
}
/* 时间复杂度O(n)
 */

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	int ans = treeSize(root);

	cout << "tree size:" << ans << endl;
	return 0;
}
