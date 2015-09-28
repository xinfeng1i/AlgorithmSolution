#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

struct Node {
	char value;
	int left;
	int right;
};

struct TreeNode {
	char value;
	TreeNode* left;
	TreeNode* right;
	// constructor
	TreeNode(char _value) : value(_value), left(NULL), right(NULL) {}
};

bool TreeIsomorphism(TreeNode* root1, TreeNode* root2)
{
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL && root2 != NULL) return false;
	if (root1 != NULL && root2 == NULL) return false;

	// 两棵树都为空的情况
	if (root1->value != root2->value) return false;
	// 两棵树不为空，且根节点已经相等
	return (TreeIsomorphism(root1->left, root2->left)
	       && TreeIsomorphism(root1->right, root2->right))
	       || (TreeIsomorphism(root1->left, root2->right)
	       && TreeIsomorphism(root1->right, root2->left));
}

TreeNode* BuildTree(Node* A, int n, int cur)
{
	if (n == 0) return NULL;
	if (cur == -1) return NULL;
	char ch = A[cur].value;
	TreeNode* root = new TreeNode(ch);
	root->left = BuildTree(A, n, A[cur].left);
	root->right = BuildTree(A, n, A[cur].right);
	return root;
}

void PreTraval(TreeNode* root)
{
	if (root == NULL) return;
	cout << root->value << endl;
	PreTraval(root->left);
	PreTraval(root->right);
}

void InOrderTraval(TreeNode* root)
{
	if (root == NULL) return;
	InOrderTraval(root->left);
	cout << root->value << endl;
	InOrderTraval(root->right);
}


int main()
{
	//freopen("input.txt", "r", stdin);
	int n1, n2;
	cin >> n1;
	set<int> s1;
	for (int i = 0; i < n1; ++i) s1.insert(i);
	Node A1[20];
	char value; char left, right;
	for (int i = 0; i < n1; ++i) {
		cin >> value >> left >> right;
		A1[i].value = value;
		if (left == '-') A1[i].left = -1;
		else A1[i].left = left - '0';
		if (right == '-') A1[i].right = -1;
		else A1[i].right = right - '0';
		
		if (A1[i].left != -1 && s1.find(A1[i].left) != s1.end())
			s1.erase(A1[i].left);
		if (A1[i].right != -1 && s1.find(A1[i].right) != s1.end())
			s1.erase(A1[i].right);
	}
	
	// 寻找根节点的索引位置, 注意n=0的特例情况，此时没有任何元素，set为空
	// 所以assert错误
	TreeNode* root1;
	if (n1 == 0) {
		root1 = NULL;
	} else {
		assert(!s1.empty());
		int pos1 = *s1.begin();
		root1 = BuildTree(A1, n1, pos1);
	}

	Node A2[20];
	cin >> n2;
	set<int> s2;
	for (int i = 0; i < n2; ++i) s2.insert(i);
	for (int i = 0; i < n2; ++i) {
		cin >> value >> left >> right;
		A2[i].value = value;
		if (left == '-') A2[i].left = -1;
		else A2[i].left = left - '0';
		if (right == '-') A2[i].right = -1;
		else A2[i].right = right - '0';
		
		if (A2[i].left != -1 && s2.find(A2[i].left) != s2.end())
			s2.erase(A2[i].left);
		if (A2[i].right != -1 && s2.find(A2[i].right) != s2.end())
			s2.erase(A2[i].right);
	}
	
	TreeNode* root2;
	if (n2 == 0) {
		root2 = NULL;
	} else {
		assert(!s2.empty());
		int pos2 = *s2.begin();
		root2 = BuildTree(A2, n2, pos2);
	}

	bool ans = TreeIsomorphism(root1, root2);
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
