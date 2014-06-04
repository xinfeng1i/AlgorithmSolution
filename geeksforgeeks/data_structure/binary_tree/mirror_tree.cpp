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

void inOrderPrint(Node* root)
{
    if (root == NULL) return;
    inOrderPrint(root->left);
    cout << " " << root->data;
    inOrderPrint(root->right);
}

void deleteTree(Node* &root)
{
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

Node* mirrorTree(Node* root)
{
    if (root == NULL) return NULL;
    Node* root2 = new Node(root->data);
    root2->left = mirrorTree(root->right);
    root2->right = mirrorTree(root->left);
    return root2;
}
/* As traversal 
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

    Node* root2 = mirrorTree(root);

    cout << "\n Original Tree In Order: " ;
    inOrderPrint(root);
    cout << "\n Mirror Tree In Order: ";
    inOrderPrint(root2);
    cout << endl;

    deleteTree(root);
    deleteTree(root2);
	return 0;
}
