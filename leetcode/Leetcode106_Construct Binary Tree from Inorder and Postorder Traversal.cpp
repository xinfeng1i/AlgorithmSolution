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
    vector<int>& inorder, int inLeft, int inRight,
    vector<int>& postorder, int postLeft, int postRight) {
    if (inLeft > inRight) return NULL;

    int rootVal = postorder[postRight];
    int inMid = -1;
    for (int i = inLeft; i <= inRight; ++i) {
        if (inorder[i] == rootVal) {
            inMid = i;
            break;
        }
    }

    int leftNum = inMid - inLeft;
    int postMid = postLeft + leftNum - 1;

    TreeNode* root = new TreeNode(rootVal);
    root->left = buildTreeRecursively(inorder, inLeft, inMid - 1, postorder, postLeft, postMid);
    root->right = buildTreeRecursively(inorder, inMid + 1, inRight, postorder, postMid + 1, postRight-1);
    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = (int)inorder.size();
    return buildTreeRecursively(inorder, 0, n - 1, postorder, 0, n - 1);
}