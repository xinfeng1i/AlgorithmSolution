#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * 二叉树的广度优先遍历
 */
vector<int> PrintFromTopToBottom(TreeNode *root) {
	vector<int> ans;
	queue<TreeNode*> q;
	if (root == NULL) return ans;
	q.push(root);
	while (!q.empty()) {
		TreeNode* temp = q.front();
		q.pop();
		ans.push_back(temp->val);
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);
	}
	return ans;
}
