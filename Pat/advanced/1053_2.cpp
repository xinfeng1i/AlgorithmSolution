#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

// Tree: recursion
// Path: recursion
const int MAXN = 110;

struct InputNode {
	int ID;
	int weight;
	int k;
	vector<int> children;
};

struct TreeNode {
	int ID;
	int weight;
	int k;
	vector<TreeNode*> pChildren;
	TreeNode(int id, int w, int _k) : ID(id), weight(w), k(_k) {}
};

InputNode inputs[MAXN];
vector<vector<int>> allPaths;

TreeNode* BuildTree(int id) {
	// leaf node
	if (inputs[id].k == 0) {
		TreeNode* root = new TreeNode(id, inputs[id].weight, inputs[id].k);
		return root;
	}
	TreeNode* root = new TreeNode(id, inputs[id].weight, inputs[id].k);
	int tempK = inputs[id].k;
	for (int i = 0; i < tempK; ++i) {
		TreeNode* temp = BuildTree(inputs[id].children[i]);
		root->pChildren.push_back(temp);
	}
	return root;
}

void PreOrderTree(TreeNode* root) {
	if (root == NULL) return;
	cout << " " << root->ID << " " << root->weight << endl;
	for (int i = 0; i < root->k; ++i) {
		PreOrderTree(root->pChildren[i]);
	}
}

void Traversal(TreeNode* curNode, int cursum, int target, vector<int> curPath) {
	// leaf nodes
	if (curNode->k == 0) {
		// find a path
		if (cursum + curNode->weight == target) {
			curPath.push_back(curNode->weight);
			allPaths.push_back(curPath);
		}
		return;
	}

	curPath.push_back(curNode->weight);
	for (int i = 0; i < curNode->k; ++i) {
		Traversal(curNode->pChildren[i], cursum+curNode->weight, target, curPath);
	}
}

void PrintVector(const vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (i == 0) printf("%d", v[i]);
		else printf(" %d", v[i]);
	}
	printf("\n");
}

bool CmpVec(const vector<int>& v1, const vector<int>& v2) {
	int n1 = (int)v1.size(); int n2 = (int)v2.size();
	for (int i = 0; i < min(n1, n2); ++i) {
		if (v1[i] > v2[i])
			return true;
		else if (v1[i] < v2[i])
			return false;
	}

	return n1 > n2;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0, m = 0;
	int s = 0;
	scanf("%d %d %d", &n, &m, &s);

	int w = -1;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w);
		inputs[i].ID = i;
		inputs[i].weight = w;
	}

	int id = 0, k = 0, child = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d", &id);
		scanf("%d", &k);
		inputs[id].k = k;
		for (int j = 0; j < k; ++j) {
			scanf("%d", &child);
			inputs[id].children.push_back(child);
		}
	}

	TreeNode* root = BuildTree(0);

	//PreOrderTree(root);

	vector<int> curPath;
	Traversal(root, 0, s, curPath);

	sort(allPaths.begin(), allPaths.end(), CmpVec);

	for (size_t i = 0; i < allPaths.size(); ++i) {
		PrintVector(allPaths[i]);
	}

	return 0;
}