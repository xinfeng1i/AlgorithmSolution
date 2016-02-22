#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct InputNode {
	int leftIdx;
	int rightIdx;
};

struct TreeNode {
	int index;
	int value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int idx, int val) : index(idx), value(val), left(NULL), right(NULL) {}
};

TreeNode* ConstructTree(const vector<InputNode>& inputs, int rootIndex)
{
	if (rootIndex == -1) return NULL;

	TreeNode* root = new TreeNode(rootIndex, -1);
	int leftIndex = inputs[rootIndex].leftIdx;
	int rightIndex = inputs[rootIndex].rightIdx;
	root->left = ConstructTree(inputs, leftIndex);
	root->right = ConstructTree(inputs, rightIndex);

	return root;
}

void PreOrderTraversalTree(TreeNode* root) {
	if (root == NULL) return;

	cout << "index:"<< root->index << endl;
	PreOrderTraversalTree(root->left);
	PreOrderTraversalTree(root->right);
}

void InOrderTraversalTree(TreeNode* root, vector<int>& inOrderIndex) {
	if (root == NULL) return;
	InOrderTraversalTree(root->left, inOrderIndex);
	inOrderIndex.push_back(root->index);
	InOrderTraversalTree(root->right, inOrderIndex);
}

void FillTreeWithValues(TreeNode* root, map<int, int>& table)
{
	if (root != NULL) {
		root->value = table[root->index];
		FillTreeWithValues(root->left, table);
		FillTreeWithValues(root->right, table);
	}
}

void LevelOrderTraversalValues(TreeNode* root, vector<int>& levelOrderValues)
{
	if (root == NULL) return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		levelOrderValues.push_back(temp->value);
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
}



int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	vector<InputNode> inputs(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &(inputs[i].leftIdx), &(inputs[i].rightIdx));
	}

	vector<int> values(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &values[i]);
	}

	// construct tree
	TreeNode* root = ConstructTree(inputs, 0);
	
	// calculate the corresponding relation between index and value
	vector<int> inOrderIndex;
	InOrderTraversalTree(root, inOrderIndex);

	sort(values.begin(), values.end());
	map<int, int> table;
	for (size_t i = 0; i < values.size(); ++i) {
		table[inOrderIndex[i]] = values[i];
	}

	// fill the values
	FillTreeWithValues(root, table);

	// output
	vector<int> levelOrderValues;
	LevelOrderTraversalValues(root, levelOrderValues);
	for (size_t i = 0; i < levelOrderValues.size(); ++i) {
		if (i == 0) printf("%d", levelOrderValues[i]);
		else printf(" %d", levelOrderValues[i]);
	}
	printf("\n");

	return 0;

}