#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTreeRecursively(vector<int>& inorder, int inLeft, int inRight,
        vector<int>& postorder, int postLeft, int postRight)
{
    // base case
    if (inLeft > inRight || postLeft > postRight) return NULL;

    int rootValue = postorder[postRight];
    int rootIndex = -1;
    for (int i = inLeft; i <= inRight; ++i)
    {
        if (inorder[i] == rootValue)
        {
            rootIndex = i;
            break;
        }
    }
    
    int leftNum = rootIndex - inLeft;
    int rightNum = inRight - rootIndex;
    TreeNode* root = new TreeNode(rootValue);
    root->left = buildTreeRecursively(inorder, inLeft, rootIndex - 1,
            postorder, postLeft, postLeft + leftNum - 1);
    root->right = buildTreeRecursively(inorder, rootIndex + 1, inRight,
            postorder, postLeft + leftNum, postRight - 1);
    return root;
    
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int n1 = inorder.size();
    int n2 = postorder.size();
    return buildTreeRecursively(inorder, 0, n1 - 1, postorder, 0, n2 - 1);
}

int main()
{
    
}

