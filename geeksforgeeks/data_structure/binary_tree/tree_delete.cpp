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

void deleteTree(Node* &root)
{
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}
/* 
 * Time Complexity: O(n)
 * Space Complexity: O(n) because using stack
 */

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

    deleteTree(root);
	cout << "Tree has been deleted successfully !" << endl;
	return 0;
}
