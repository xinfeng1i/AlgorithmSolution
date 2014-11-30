#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDepth(TreeNode* root)
{
    if (root == NULL) return 0;
    else if (root->left == NULL && root->right == NULL) return 1;

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    if (leftDepth == 0)
    {
        return rightDepth + 1;
    }

    if (rightDepth == 0)
    {
        return leftDepth + 1;
    }

    return min(leftDepth, rightDepth) + 1;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    int ans = minDepth(root);
    cout << ans << endl;
    return 0;
}
