#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
    	if (pre.empty() || in.empty()) return NULL;
    	int val = pre[0];
    	
    	vector<int>::iterator it = find(in.begin(), in.end(), val);
    	int idx = it - in.begin();
    	int left_num = idx;
    	vector<int> in_left(in.begin(), in.begin()+idx);
    	vector<int> in_right(in.begin()+idx+1, in.end());

    	
    	vector<int> pre_left(pre.begin() + 1, pre.begin() + 1 + left_num);
    	vector<int> pre_right(pre.begin() + 1 + left_num, pre.end());
    	
    	struct TreeNode* root = new TreeNode(val);
    	root->left = reConstructBinaryTree(pre_left, in_left);
    	root->right = reConstructBinaryTree(pre_right, in_right);
    	
    	return root;
    }
};

void inOrder(struct TreeNode* root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << " " << root->val;
	inOrder(root->right);
}


int main()
{
	int pre1[] = {1,2,4,7,3,5,6,8};
	int in1[] = {4,7,2,1,5,3,8,6};
	
	vector<int> pre(pre1,pre1+8);
	vector<int> in(in1, in1+8);
	Solution sl;
	struct TreeNode* root = sl.reConstructBinaryTree(pre, in);
	inOrder(root);
	return 0;
}
