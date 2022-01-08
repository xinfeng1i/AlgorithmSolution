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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};

/*
 * Method1: 按照定义判断
 * 首先 helper 函数判定，某一棵树的所有 node 是否小于给定 value，时间复杂度: O(n)
 * 接着判断左、右子树是否满足小于或者大于关系
 * 最后再次递归判断左右子树
 * 总的时间复杂度应该为：O(nlogn)
 */
bool isLessThan(TreeNode* root, int value, bool isLessFlag) {
    if (root == NULL) {
        return true;
    }

    if (isLessFlag) {
        return root->val < value && isLessThan(root->left, value, isLessFlag) && isLessThan(root->right, value, isLessFlag);
    }
    else {
        return root->val > value && isLessThan(root->left, value, isLessFlag) && isLessThan(root->right, value, isLessFlag);
    }
}


bool isValidBST(TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL) return true;

    bool flag1 = isLessThan(root->left, root->val, true);
    bool flag2 = isLessThan(root->right, root->val, false);
    bool flag3 = isValidBST(root->left);
    bool flag4 = isValidBST(root->right);

    return flag1 && flag2 && flag3 && flag4;
}


/*
 * Method2: 直接判断某个二叉树的所有节点是否在[minVal, maxVal]直接
 * 这种方法只需要一次遍历，因此时间复杂度为O(n)
 * 但是需要注意直接使用 INT_MIN/INT_MAX 会造成边界错误
 */

bool isValidBST(TreeNode* root) {
    return recurUtils(root, LLONG_MIN, LLONG_MAX);
}

bool recurUtils(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    // 判断根节点是否满足区间要求
    if (root->val <= minVal || root->val >= maxVal) return false;
    // 递归判断左右子树是否满足递归要求
    return recurUtils(root->left, minVal, root->val) && recurUtils(root->right, root->val, maxVal);
}