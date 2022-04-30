#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <set>
#include <stack>
#include <queue>
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

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSame(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL && root2 != NULL) return false;
    if (root1 != NULL && root2 == NULL) return false;

    return root1->val == root2->val && isSame(root1->left, root2->left) && isSame(root1->right, root2->right);

}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) return true;
    if (root != NULL && subRoot == NULL) return true;
    if (root == NULL && subRoot != NULL) return false;

    if (isSame(root, subRoot)) return true;

    bool flag1 = isSubtree(root->left, subRoot);
    if (flag1) return true;

    bool flag2 = isSubtree(root->right, subRoot);
    if (flag2) return true;

    return false;

}
