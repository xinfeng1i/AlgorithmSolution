#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * build the binary tree from pre-order and in-order list.
 */
TreeNode* buildTree(vector<int>& preorder, int left, int right,
                    vector<int>& inorder, int low, int high) {
    if (left > right) return NULL;
    
    int x = preorder[left];
    TreeNode* root = new TreeNode(x);
    
    // find root node middle index.
    int mid = -1;
    for (int i = low; i <= high; ++i) {
        if (inorder[i] == x) {
            mid = i;
            break;
        }
    }
    int leftNum = mid - low;
    
    // build the left & right subtree recursively.
    TreeNode* leftTree = buildTree(preorder, left + 1, left + leftNum,
                                   inorder, low, mid - 1);
    TreeNode* rightTree = buildTree(preorder, left + leftNum + 1, right,
                                    inorder, mid + 1, high);
    root->left = leftTree;
    root->right = rightTree;
    
    return root;
}


void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    cout << " " << root->val;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void inorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << " " << root->val;
    inorderTraversal(root->right);
}

#if 0
int main() {
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };
    
    int n = (int) preorder.size();
    TreeNode* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1);
    
    cout << "Now preorder:" << endl;
    preorderTraversal(root);
    
    cout << "\n Now inorder: " << endl;
    inorderTraversal(root);
    
    return 0;
}
#endif // 0
