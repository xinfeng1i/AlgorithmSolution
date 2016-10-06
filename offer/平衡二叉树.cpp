#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool BSTWithDepth(TreeNode* root, int& depth) {
	if (root == NULL) {
		depth = 0;
		return true;
	}
	int depth_left = 0, depth_right = 0;
	bool leftBST = BSTWithDepth(root->left, depth_left);
	bool rightBST = BSTWithDepth(root->right, depth_right);
	depth = max(depth_left, depth_right) + 1;
	
	return leftBST && rightBST && abs(depth_left - depth_right) <= 1;
}

bool IsBalanced_Solution(TreeNode* root) {
	int depth = 0;
	bool ok = BSTWithDepth(root, depth);
	return ok;
}
