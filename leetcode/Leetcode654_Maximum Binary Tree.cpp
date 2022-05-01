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


TreeNode* buildTreeRecursively(vector<int>& nums, int left, int right) {
    if (left > right) return NULL;

    int maxVal = nums[left];
    int maxIdx = left;
    for (int i = left + 1; i <= right; ++i) {
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxIdx = i;
        }
    }

    TreeNode* root = new TreeNode(maxVal);
    root->left = buildTreeRecursively(nums, left, maxIdx - 1);
    root->right = buildTreeRecursively(nums, maxIdx + 1, right);
    return root;
}


TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int n = (int) nums.size();
    return buildTreeRecursively(nums, 0, n - 1);
}
