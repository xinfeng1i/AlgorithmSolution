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

int nodeNumber(TreeNode* root) {
	if (root == NULL) return 0;
	return 1 + nodeNumber(root->left) + nodeNumber(root->right);
}

int kthSmallest(TreeNode* root, int k) {
	if (root == NULL || k < 0) return 0;

	int left_cnt = nodeNumber(root->left);
	if (left_cnt == k - 1) {
		return root->val;
	} else if (left_cnt > k - 1) {
		return kthSmallest(root->left, k);
	} else {
		
	}
}