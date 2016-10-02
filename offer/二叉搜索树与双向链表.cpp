#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

TreeNode* Convert(TreeNode* root)
{
	if (root == NULL) return NULL;
	if (root->left == NULL && root->right == NULL) {
		return root;
	}
	TreeNode* leftRoot = Convert(root->left);
	TreeNode* rightRoot = Convert(root->right);
	
	// p1: the maximum node in the left part
	TreeNode* p1 = leftRoot;
	while(p1 != NULL && p1->right != NULL) {
		p1 = p1->right;
	}
	
	// p2: the mimimum node in the right part
	TreeNode* p2 = rightRoot;
	
	// update the root node pointers
	if (p1 != NULL) {
		p1->right = root;
		root->left = p1;
	}
	if (p2 != NULL) {
		root->right = p2;
		p2->left = root;
	}
	
	TreeNode* head = root;
	if (leftRoot != NULL) head = leftRoot;
	return head;
}

int main()
{
	TreeNode* root = new TreeNode(2);
	TreeNode* p1 = new TreeNode(1);
	root->left = p1;
	TreeNode* p3 = new TreeNode(3);
	root->right = p3;
	TreeNode* head = Convert(root);
	for (TreeNode* p = head; p != NULL; p = p->right) {
		cout << " " << p->val;
	}
	cout << endl;
	for (TreeNode* p = p3; p != NULL; p = p->left) {
		cout << " " << p->val;
	}
	cout << endl;
	return 0;
}
