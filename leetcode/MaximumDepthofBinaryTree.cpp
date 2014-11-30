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

int maxDepth(TreeNode* root)
{
    if (root == NULL) return 0;
    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    int ans = maxDepth(root);
    cout << ans << endl;
    return 0;
}

