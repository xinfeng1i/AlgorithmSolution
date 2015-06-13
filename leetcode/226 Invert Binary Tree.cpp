#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* invertTree(TreeNode* root) 
		{
			if (root == NULL) return NULL;
			
			TreeNode* afterleft = invertTree(root->left);
			TreeNode* afterright = invertTree(root->right);
			root->left = afterright;
			root->right = afterleft;
			//swap(root->left, root->right);
			//invertTree(root->left);
			//invertTree(root->right);
			return root;
		}
};



