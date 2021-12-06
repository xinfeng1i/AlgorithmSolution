#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>
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


// 这个题目思考了好久才想出来，因为其需要同事返回两个变量：
// - sum（子树所有节点的和） 
// - answer(子树中的最小子树的和）
// 时间复杂度：O(n) 每个节点访问一次
TreeNode* findSubtreeUtil(TreeNode* root, int& answer, int& sum) {
    // base case
    if (root == NULL) {
        sum = 0;
        answer = 0;
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        sum = root->val;
        answer = root->val;
        return root;
    }

    TreeNode* treeLeft = NULL;
    int ansLeft = 0;
    int sumLeft = 0;
    treeLeft = findSubtreeUtil(root->left, ansLeft, sumLeft);

    TreeNode* treeRight = NULL;
    int ansRight = 0;
    int sumRight = 0;
    treeRight = findSubtreeUtil(root->right, ansRight, sumRight);

    // 计算当前以root为根的子树的和
    int sumRoot = sumLeft + sumRight + root->val;

    // 选择sumRoot，ansLeft, ansRight中最小的子树作为最终答案
    int canAns = 0;
    TreeNode* canTree = NULL;
    if (treeLeft != NULL) {
        canTree = treeLeft;
        canAns = ansLeft;
    }

    if (treeRight != NULL) {
        if (canTree == NULL || ansRight < canAns) {
            canTree = treeRight;
            canAns = ansRight;
        }
    }

    if (root != NULL) {
        if (canTree == NULL || sumRoot < canAns) {
            canTree = root;
            canAns = sumRoot;
        }
    }

    answer = canAns;
    sum = sumRoot;
    return canTree;
}



TreeNode* findSubtree(TreeNode* root) {
    int answer = 0;
    int sum = 0;
    return findSubtreeUtil(root, answer, sum);
}

#if 0
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-5);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(-4);
    root->right->right = new TreeNode(-5);

    /*TreeNode* root = new TreeNode(-2);
    root->left = new TreeNode(-10);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(-4);
    root->right->right = new TreeNode(-1);*/


    /*TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);*/

    TreeNode* subTree = findSubtree(root);
    cout << subTree->val << endl;
    return 0;
}
#endif // 0