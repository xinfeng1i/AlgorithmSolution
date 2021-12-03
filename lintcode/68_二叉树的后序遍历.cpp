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


vector<int> postorderTraversal(TreeNode* root) {
    // base case
    vector<int> ans;
    if (root == NULL) return ans;

    // recursion
    vector<int> v1 = postorderTraversal(root->left);
    vector<int> v2 = postorderTraversal(root->right);
    int elem = root->val;

    for (int x : v1) ans.push_back(x);
    for (int x : v2) ans.push_back(x);
    ans.push_back(elem);

    return ans;
}