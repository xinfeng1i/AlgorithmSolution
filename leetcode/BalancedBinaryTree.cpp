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

int depth(TreeNode* root)
{
    if (root == NULL) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}

bool isBalanced(TreeNode* root)
{
    if (root == NULL) return true;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return abs(leftDepth - rightDepth) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
}

