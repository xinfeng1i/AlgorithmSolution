#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode* root) {
	vector<int> ans;
	if (root == NULL) return ans;

	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int sz = (int)q.size();
		for (int i = 0; i < sz; ++i) {
			TreeNode* cur = q.front();
			q.pop();
			if (i == sz - 1) ans.push_back(cur->val);
			if (cur->left != NULL) q.push(cur->left);
			if (cur->right != NULL) q.push(cur->right);
		}
	}

	return ans;
}