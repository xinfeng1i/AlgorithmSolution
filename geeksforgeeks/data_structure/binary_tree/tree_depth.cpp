#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int key):data(key),left(NULL),right(NULL){}
};

int depth(Node* root)
{
    if (root == NULL) return 0;
    else return 1 + max(depth(root->left), depth(root->right));
}
/* time Complexity: O(n) */

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	int ans = depth(root);

	cout << "tree depth:" << ans << endl;
	return 0;
}
