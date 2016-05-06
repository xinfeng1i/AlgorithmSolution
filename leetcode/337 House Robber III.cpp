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
using namespace std;

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#if 0
// 解法一：递归+哈希表 
//
// 二叉树问题可以通过递归的方式解决
//           a
//         b    c
//      c    d e  f
//    g   h
// 考虑上述二叉树，可以发现对于节点a，只有两种选择，抢或者不抢
// 1. 如果抢。则b, c节点必然不能被抢，则转化为求解c, d, e, f四个子树抢劫的综合
// 2. 如果不抢。则转化为b,c两颗字数的抢劫的综合
// 最后取两者的较大值即可
int rob_recursion(TreeNode* root, unordered_map<TreeNode*, int>& hashtable) {
	if (hashtable.find(root) != hashtable.end()) {
		return hashtable[root];
	}

	if (root == NULL) {
		hashtable[root] = 0;
		return 0;
	}

	// 1. 抢根节点
	int ans1 = root->val;
	if (root->left != NULL) ans1 += rob_recursion(root->left->left, hashtable) + rob_recursion(root->left->right, hashtable);
	if (root->right != NULL) ans1 += rob_recursion(root->right->left, hashtable) + rob_recursion(root->right->right, hashtable);

	// 2. 不抢根节点
	int ans2 = rob_recursion(root->left, hashtable) + rob_recursion(root->right, hashtable);

	hashtable[root] = max(ans1, ans2);
	return max(ans1, ans2);
}

int rob(TreeNode* root) {
	unordered_map<TreeNode*, int> hashtable;
	return rob_recursion(root, hashtable);
}
#endif //0

// 解法二:
// 上述方法存在重叠子问题的原因在于，没有记录每个节点是否被抢的信息
// 
// root 不被抢时存放在first元素中
// root 被抢时存放在second元素中
pair<int, int> rob_recursion(TreeNode* root) {
	if (root == NULL) return make_pair(0, 0);

	pair<int, int> left_ans = rob_recursion(root->left);
	pair<int, int> right_ans = rob_recursion(root->right);

	pair<int, int> root_ans = make_pair(0, 0);
	root_ans.second = root->val + left_ans.first + right_ans.first;
	root_ans.first = max(left_ans.first, left_ans.second) + max(right_ans.first, right_ans.second);

	return root_ans;
}

int rob(TreeNode* root) {
	pair<int, int> ans = rob_recursion(root);
	return max(ans.first, ans.second);
}

