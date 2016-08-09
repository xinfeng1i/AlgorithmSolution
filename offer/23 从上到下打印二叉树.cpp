#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cassert>
using namespace std;

struct Node {
	Node(int x = 0) : val(x), left(NULL), right(NULL) {}
	int val;
	Node* left;
	Node* right;
};

/**
 * ¶þ²æÊ÷²ãÐò±éÀú, so easy 
 */
void PrintBinaryTreeLevelOrder(Node* root) {
	// base case
	if (root == NULL) return;
	
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* curNode = q.front();
		q.pop();
		cout << curNode->val << " ";
		if (curNode->left != NULL) {
			q.push(curNode->left);
		}
		if (curNode->right != NULL) {
			q.push(curNode->right);
		}
	}
}

// test
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	PrintBinaryTreeLevelOrder(root);
	return 0;
}
