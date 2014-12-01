#include <iostream>
#include <string>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSumRecursively(TreeNode* root, int sum, int cursum)
{
    if (root == NULL) return false;
    else if (root->left == NULL && root->right == NULL)
    {
        if (cursum + root->val == sum) return true;
        else return false;
    }

    bool flag1 = false;
    bool flag2 = false;
    if (root->left != NULL)
    {
        flag1 = hasPathSumRecursively(root->left, sum, cursum + root->val);
    }
    if (root->right != NULL)
    {
        flag2 = hasPathSumRecursively(root->right, sum, cursum + root->val);
    }

    return flag1 || flag2;
}

bool hasPathSum(TreeNode* root, int sum)
{
    return hasPathSumRecursively(root, sum, 0); 
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    
    bool ans = hasPathSum(root, 22);
    cout << ans << endl;
    return 0;
}

