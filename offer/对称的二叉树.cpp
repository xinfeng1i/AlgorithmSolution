
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
 * 经典镜像二叉树问题
 */
bool isMirror(TreeNode* root1, TreeNode* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL && root2 != NULL) return false;
	if (root1 != NULL && root2 == NULL) return false;
	
	return root1->val == root2->val &&
	       isMirror(root1->left, root2->right) &&
		   isMirror(root1->right, root2->left);
}

bool isSymmetrical(TreeNode* root)
{
	return isMirror(root, root);
}
