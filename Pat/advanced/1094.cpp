#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#if 0
struct InputNode {
	int parentID;
	int nChildren;
	vector<int> children;
};

struct TreeNode {
	int value;
	int nChildren;
	int level;
	TreeNode* children[110];

	TreeNode(int x, int k = 0) : value(x), nChildren(k) {
		level = 1;
		for (int i = 0; i < 110; ++i) 
			children[i] = NULL;
	}
};

unordered_map<int, InputNode> table;
unordered_map<int, int> levelCount;

void ConstructTree(TreeNode* &root, int rootValue) {
	// leaf nodes
	if (table.find(rootValue) == table.end()) {
		root = new TreeNode(rootValue, 0);
		return;
	} else { // non-leaf nodes
		int k = table[rootValue].nChildren;
		root = new TreeNode(rootValue, k);
		for (int i = 0; i < k; ++i) {
			ConstructTree(root->children[i], table[rootValue].children[i]);
		}
		return;
	}
}

void PreOrder(TreeNode* root) {
	if (root == NULL) return;
	//cout << root->value << " level = " << root->level << endl;
	levelCount[root->level] += 1;
	for (int i = 0; i < root->nChildren; ++i) {
		PreOrder(root->children[i]);
	}
}

void BFS(TreeNode* &root) {
	queue<TreeNode*> q;
	root->level = 1;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();

		int k = temp->nChildren;
		for (int i = 0; i < k; ++i) {
			temp->children[i]->level = temp->level + 1;
			q.push(temp->children[i]);
		}
	}
}

void PrintVector(const vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		cout << " " << v[i];
	}
	cout << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;

	int tempChild;
	InputNode temp;
	for (int i = 0; i < m; ++i) {
		cin >> temp.parentID >> temp.nChildren;
		temp.children.clear();
		for (int j = 0; j < temp.nChildren; ++j) {
			cin >> tempChild;
			temp.children.push_back(tempChild);
		}
		table[temp.parentID] = temp;
	}

	//for (auto it = table.begin(); it != table.end(); ++it) {
	//	cout << it->first << " " << it->second.nChildren << " " << endl;
	//	PrintVector(it->second.children);
	//}

	//cout << "here" << endl;
	TreeNode* root = NULL;
	ConstructTree(root, 1);

	BFS(root);

	PreOrder(root);

	int maxLevel = -1;
	int maxNodes = -1;
	for (auto it = levelCount.begin(); it != levelCount.end(); it++) {
		if (it->second > maxNodes) {
			maxLevel = it->first;
			maxNodes = it->second;
		}
	}

	cout << maxNodes << " " << maxLevel << endl;

	return 0;
}
#endif //0