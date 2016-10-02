#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {}
		};

/**
 * 遍历所有路径问题：采用回溯法解决
 */
void FindPathHelper(TreeNode* root, int cur_sum, vector<int>& cur_path, vector<vector<int> >& ans, int target) {
	if (root != NULL) {
		// try a choice
		cur_sum += root->val;
		cur_path.push_back(root->val);
		if (root->left == NULL && root->right == NULL) {
			if (cur_sum == target) {
				ans.push_back(cur_path);
			}
			cur_path.pop_back();
			return;
		} else {
			if (root->left != NULL) {
				FindPathHelper(root->left, cur_sum, cur_path, ans, target);
			}
			if (root->right != NULL) {
				FindPathHelper(root->right, cur_sum, cur_path, ans, target);
			}
			cur_path.pop_back();
		}
	}
	
	
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
	vector<vector<int> > ans;
	vector<int> path;
	FindPathHelper(root, 0, path, ans, expectNumber);
	return ans;
}
