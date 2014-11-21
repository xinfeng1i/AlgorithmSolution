#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Method 1
// memory exceed Limit
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size() == 0 || inorder.size() == 0) 
        return NULL;
    if (preorder.size() == 1 || inorder.size() == 1)
        return new TreeNode(preorder[0]);

    int pivot = preorder[0];
    vector<int>::iterator it = find(inorder.begin(), inorder.end(), pivot);
    vector<int> inorderLeftPart;
    for (vector<int>::iterator it2 = inorder.begin(); it2 != it; ++it2)
    {
        inorderLeftPart.push_back(*it2); 
    }
    vector<int> inorderRightPart;
    for (vector<int>::iterator it2 = it + 1; it2 != inorder.end(); ++it2)
    {
        inorderRightPart.push_back(*it2); 
    }

    int leftNum = inorderLeftPart.size();
    int rightNum = inorderRightPart.size();
    vector<int> preOrderLeftPart(preorder.begin() + 1, 
            preorder.begin() + 1 + leftNum);
    vector<int> preOrderRightPart(preorder.begin() + 1 + leftNum, 
            preorder.end());


    TreeNode* root = new TreeNode(pivot);
    root->left = buildTree(preOrderLeftPart, inorderLeftPart);
    root->right = buildTree(preOrderRightPart, inorderRightPart);

    return root;
}


TreeNode* buildTreeRecursively(
        vector<int>& preorder, int left1, int right1, 
        vector<int>& inorder,  int left2, int right2)
{
    if (left1 > right1 || left2 > right2) 
        return NULL;
    if (left1 == right1 || left2 == right2)
        return new TreeNode(preorder[left1]);

    int pivot = preorder[left1];
    int p = -1;
    for (int i = left2; i <= right2; ++i)
    {
        if (inorder[i] == pivot)
        {
            p = i;
            break;
        }
    }
    int leftNum = p - left2;
    
    TreeNode* root = new TreeNode(pivot);
    root->left = buildTreeRecursively(
            preorder, left1 + 1, left1 + leftNum,
            inorder, left2, p - 1);
    root->right = buildTreeRecursively(
            preorder, left1 + leftNum + 1, right1,
            inorder, p + 1, right2);
    return root;
}

TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size() == 0 || inorder.size() == 0) return NULL;
    int left1 = 0;
    int right1 = int(preorder.size()) - 1;
    int left2 = 0;
    int right2 = int(inorder.size()) - 1;
    TreeNode* root = buildTreeRecursively(preorder, left1, right1,
                                          inorder,  left2, right2);
    return root;
}

void InOrder(TreeNode* root)
{
    if (root == NULL) return;
    InOrder(root->left);
    cout << " " << root->val;
    InOrder(root->right);
}

int main()
{
    int a[] = {1, 2};
    vector<int> preorder(a, a + 2);
    int b[]  = {1, 2};
    vector<int> inorder(b, b + 2);
    TreeNode* root = buildTree2(preorder, inorder);
    InOrder(root);
    return 0;
}
