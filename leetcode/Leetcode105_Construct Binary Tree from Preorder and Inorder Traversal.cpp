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


TreeNode* buildTreeRecursively(
    vector<int>& preorder, int left1, int right1,
    vector<int>& inorder, int left2, int right2) {
    if (left1 > right1) return NULL;

    int rootVal = preorder[left1];
    int mid2 = -1;
    for (int i = left2; i <= right2; ++i) {
        if (inorder[i] == rootVal) {
            mid2 = i;
            break;
        }
    }

    int leftTreeNodeNum = mid2 - left2;
    int mid1 = left1 + leftTreeNodeNum;

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeRecursively(preorder, left1 + 1, mid1, inorder, left2, mid2 - 1);
    root->right = buildTreeRecursively(preorder, mid1 + 1, right1, inorder, mid2 + 1, right2);
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = (int)preorder.size();
    return buildTreeRecursively(preorder, 0, n - 1, inorder, 0, n - 1);
}