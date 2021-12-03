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

vector<int> preorderTraversal(TreeNode* root) {
    // base case
    vector<int> ans;
    if (root == NULL) return ans;

    // recursion
    ans.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);

    for (int x : left) ans.push_back(x);
    for (int x : right) ans.push_back(x);

    return ans;
}