#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cassert>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
 * 这个题目也是比较有意思的题目
 * 很容易想到需要使用递归算法求解，关键问题是如何判断以root1为根的树
 * 是否能够完全覆盖root2为根的树，这样右需要第二函数，而第二个函数同样
 * 需要递归的方式进行比较求解
 */
bool Tree1ContainTree2(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 != NULL && root2 == NULL) return true;
	if (root1 == NULL && root2 != NULL) return false;
	
	return root1->val == root2->val &&
		   Tree1ContainTree2(root1->left, root2->left) &&
		   Tree1ContainTree2(root1->right, root2->right);
}

bool HasSubtree(TreeNode* root1, TreeNode* root2) {
	if (root2 == NULL) return false;
	if (root1 == NULL) return false;
	
	if (root1->val == root2->val) {
		bool root_ok = Tree1ContainTree2(root1, root2);
		if (root_ok) return true;
		bool left_ok = HasSubtree(root1->left, root2);
		if (left_ok) return true;
		bool right_ok = HasSubtree(root1->right, root2);
		return right_ok;
		
	} else {
		bool left_ok = HasSubtree(root1->left, root2);
		if (left_ok) return true;
		bool right_ok = HasSubtree(root1->right, root2);
		return right_ok;
	}
}
