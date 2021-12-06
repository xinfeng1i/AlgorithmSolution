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

// ������rootΪ���������У�����������
// 1. �����ͷ��� maxSum ����
// 2. ��root�����нڵ�ĺͷ��� sum ����
// 3. �����������ĸ�ָ�뷵��
TreeNode* findSubtree(TreeNode* root, int& maxSum, int& sum) {
    // base case
    if (root == NULL) {
        maxSum = 0;
        sum = 0;
        return root;
    }

    if (root->left == NULL && root->right == NULL) {
        maxSum = root->val;
        sum = root->val;
        return root;
    }

    // recursion with left & right tree
    int leftMaxSum = 0;
    int leftSum = 0;
    TreeNode* treeLeft = findSubtree(root->left, leftMaxSum, leftSum);

    int rightMaxSum = 0;
    int rightSum = 0;
    TreeNode* treeRight = findSubtree(root->right, rightMaxSum, rightSum);

    // this root tree sum
    int rootSum = leftSum + rightSum + root->val;

    // compare leftMaxSum, rightMaxSum, rootSum��choose the max as result
    TreeNode* candTree = NULL;  // candidate tree
    int candAns = 0;    // candidate answer

    if (treeLeft != NULL) {
        candTree = treeLeft;
        candAns = leftMaxSum;
    }

    if (treeRight != NULL) {
        if (candTree == NULL || rightMaxSum > candAns) {
            candTree = treeRight;
            candAns = rightMaxSum;
        }
    }

    if (root != NULL) {
        if (candTree == NULL || rootSum > candAns) {
            candTree = root;
            candAns = rootSum;
        }
    }

    maxSum = candAns;
    sum = rootSum;
    return candTree;
}


TreeNode* findSubtree(TreeNode* root) {
    int maxSum = 0;
    int sum = 0;
    return findSubtree(root, maxSum, sum);
}