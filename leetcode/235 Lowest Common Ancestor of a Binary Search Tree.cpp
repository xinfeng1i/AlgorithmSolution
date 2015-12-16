#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == NULL) return root;
	if (p == NULL) return q;
	if (q == NULL) return p;
	if (root == p || root == q) return root;

	if ( (root->val > p->val && root->val < q->val) || 
		 (root->val < p->val && root->val > q->val) )
		return root;
	else if (p->val < root->val && q->val < root->val) 
		return lowestCommonAncestor(root->left, p, q);
	else if (p->val > root->val && q->val > root->val)
		return lowestCommonAncestor(root->right, p, q);
}

int main()
{
	TreeNode* p = NULL;
	TreeNode* q = NULL;
	TreeNode* root = new TreeNode(6);
	p = root->left = new TreeNode(2);
	root->left->left = new TreeNode(0);
	q = root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);

	TreeNode* ans = lowestCommonAncestor(root, p, q);
	cout << ans->val << endl;

	return 0;

}
