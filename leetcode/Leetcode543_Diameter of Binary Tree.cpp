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


struct ResultInfo {
    int height;
    int diam;
    ResultInfo(int h_, int d_) : height(h_), diam(d_) {};
};

ResultInfo diameterOfBinaryTreeRecursive(TreeNode* root) {
    if (root == NULL) return ResultInfo(0, 0);

    ResultInfo leftAns = diameterOfBinaryTreeRecursive(root->left);
    ResultInfo rightAns = diameterOfBinaryTreeRecursive(root->right);

    int ans1 = leftAns.diam;
    int ans2 = rightAns.diam;
    int ans3 = leftAns.height + rightAns.height + 1;

    int thisDiam = max(max(ans1, ans2), ans3);
    int thisHeight = max(leftAns.height, rightAns.height) + 1;

    return ResultInfo(thisHeight, thisDiam);
}

int diameterOfBinaryTree(TreeNode* root) {
    ResultInfo ans = diameterOfBinaryTreeRecursive(root);
    return ans.diam;
}