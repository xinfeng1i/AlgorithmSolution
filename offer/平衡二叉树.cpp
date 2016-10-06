#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 该函数判断当前root为根的树是否为BST，同时返回
 * 该树的深度depth
 * 1. 注意递归结束时更新需要输出的depth值
 */
bool BSTWithDepth(TreeNode* root, int& depth) {
	if (root == NULL) {
		depth = 0;
		return true;
	}
	int depth_left = 0, depth_right = 0;
	bool leftBST = BSTWithDepth(root->left, depth_left);
	bool rightBST = BSTWithDepth(root->right, depth_right);
	// 返回结果之前需要输出depth的值
	depth = max(depth_left, depth_right) + 1;
	
	return leftBST && rightBST && abs(depth_left - depth_right) <= 1;
}

bool IsBalanced_Solution(TreeNode* root) {
	int depth = 0;
	bool ok = BSTWithDepth(root, depth);
	return ok;
}
