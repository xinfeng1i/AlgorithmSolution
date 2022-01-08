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
 * Method1: ���ն����ж�
 * ���� helper �����ж���ĳһ���������� node �Ƿ�С�ڸ��� value��ʱ�临�Ӷ�: O(n)
 * �����ж����������Ƿ�����С�ڻ��ߴ��ڹ�ϵ
 * ����ٴεݹ��ж���������
 * �ܵ�ʱ�临�Ӷ�Ӧ��Ϊ��O(nlogn)
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
 * Method2: ֱ���ж�ĳ�������������нڵ��Ƿ���[minVal, maxVal]ֱ��
 * ���ַ���ֻ��Ҫһ�α��������ʱ�临�Ӷ�ΪO(n)
 * ������Ҫע��ֱ��ʹ�� INT_MIN/INT_MAX ����ɱ߽����
 */

bool isValidBST(TreeNode* root) {
    return recurUtils(root, LLONG_MIN, LLONG_MAX);
}

bool recurUtils(TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;
    // �жϸ��ڵ��Ƿ���������Ҫ��
    if (root->val <= minVal || root->val >= maxVal) return false;
    // �ݹ��ж����������Ƿ�����ݹ�Ҫ��
    return recurUtils(root->left, minVal, root->val) && recurUtils(root->right, root->val, maxVal);
}