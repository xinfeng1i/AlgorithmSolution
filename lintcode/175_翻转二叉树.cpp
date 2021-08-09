//
//  175_翻转二叉树.cpp
//  HelloXcode
//
//  Created by xinfengli on 2021/8/9.
//

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};


void invertBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
    
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    
    root->left = right;
    root->right = left;
    return;
}


void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}


#if 0
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    
    printf("\nBefore:\n");
    printTree(root);
    
    
    invertBinaryTree(root);
    printf("\nAfter:\n");
    printTree(root);
    
    return 0;
}
#endif //0
