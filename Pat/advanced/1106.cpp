#include <iostream>
#include <sstream>
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

// Tree Construction
// Be careful about every variables especially when about to
// be finishing.
#if 0

const int MAXN = 100010;

struct InputNode {
	int ID;
	int k;
	vector<int> children;
};

struct TreeNode {
	int ID;
	int k;
	int level;
	vector<TreeNode*> children;
public:
	// Constructor
	TreeNode(int value, int nChildren) {
		ID = value;
		k = nChildren;
		level = MAXN;
		if (k != 0) {
			children.resize(k);
			for (int i = 0; i < k; ++i) {
				children[i] = NULL;
			}
		}

	}
};


InputNode inputs[MAXN];

void BuildTree(TreeNode* &root, int value, int k) {
	if (k == 0) {
		root = new TreeNode(value, k);
		return;
	}
	root = new TreeNode(value, k);
	for (int i = 0; i < k; ++i) {
		int nextValue = inputs[value].children[i];
		int nextK = inputs[nextValue].k;
		BuildTree(root->children[i], nextValue, nextK);
	}
}

void PreOrderTree(TreeNode* &root, int& minLevel, vector<int>& minLevelNodes) {
	if (root->k == 0) {
		if (root->level < minLevel) {
			minLevel = root->level;
			minLevelNodes.clear();
			minLevelNodes.push_back(root->ID);
		} else if (root->level == minLevel) {
			minLevelNodes.push_back(root->ID);
		}
		//cout << "value = " << root->ID << " level = " << root->level << endl;
		return; 
	}

	//cout << "value = " << root->ID << " level = " << root->level << endl;
	for (int i = 0; i < root->k; ++i) {
		PreOrderTree(root->children[i], minLevel, minLevelNodes);
	}
}

void BFSTree(TreeNode* &root) {
	if (root == NULL) return;
	queue<TreeNode*> q;
	root->level = 0;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		for (int i = 0; i < temp->k; ++i) {
			temp->children[i]->level = temp->level + 1;
			q.push(temp->children[i]);
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	int n = 0;
	double price = 0.0, rate = 0.0;
	scanf("%d %lf %lf", &n, &price, &rate);
	rate = rate / 100.0;

	int curID, curK, curChild;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &curK);
		inputs[i].ID = i;
		inputs[i].k = curK;
		if (curK == 0) {
			continue;
		} else {
			for (int j = 0; j < curK; ++j) {
				scanf("%d", &curChild);
				inputs[i].children.push_back(curChild);
			}
		}
	}

	TreeNode* root = NULL;
	BuildTree(root, 0, inputs[0].k);

	BFSTree(root);

	int minLevel = MAXN;
	vector<int> minLevelNodes;
	PreOrderTree(root, minLevel, minLevelNodes);
	double finalPrice = price * pow(double(1+rate), (double)minLevel);

	int nMinLevel = minLevelNodes.size();
	printf("%.4lf %d\n", finalPrice, nMinLevel);
	return 0;
}

#endif //0