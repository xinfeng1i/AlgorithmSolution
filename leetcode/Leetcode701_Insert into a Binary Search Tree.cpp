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
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) {
        TreeNode* newRoot = new TreeNode(val);
        return newRoot;
    }

    if (root->left == NULL && val < root->val) {
        root->left = new TreeNode(val);
        return root;
    }

    if (root->right == NULL && val > root->val) {
        root->right = new TreeNode(val);
        return root;
    }

    if (val < root->val) {
        insertIntoBST(root->left, val);
        return root;
    }
    else if (val > root->val) {
        insertIntoBST(root->right, val);
        return root;
    }
}