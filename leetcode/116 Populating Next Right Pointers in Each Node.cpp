#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}

void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) return;
    
    // 连接左子树
    connect(root->left);
    // 连接右子树
    connect(root->right);
    
    // 打通跨越左右子树的邻居节点
    TreeLinkNode* p1 = root->left;
    TreeLinkNode* p2 = root->right;
    while (p1 != NULL && p2 != NULL) {
        p1->next = p2;
        p1 = p1->right;
        p2 = p2->left;
    }
    
    return;    
}