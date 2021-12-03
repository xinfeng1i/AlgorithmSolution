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


vector<int> inorderTraversal(TreeNode* root) {
    // base case
    vector<int> ans;
    if (root == NULL) return ans;

    // recursion
    vector<int> v1 = inorderTraversal(root->left);
    int elem = root->val;
    vector<int> v2 = inorderTraversal(root->right);

    for (int x : v1) ans.push_back(x);
    ans.push_back(elem);
    for (int x : v2) ans.push_back(x);

    return ans;
}

#if 0
int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
#endif // 0