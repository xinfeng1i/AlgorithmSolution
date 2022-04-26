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

// binary tree level-order traversal
// time: O(n)
// space: O(n)
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL) return ans;

    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        // traversal this level of nodes
        int sz = (int) Q.size();
        stack<int> S;

        for (int i = 0; i < sz; ++i) {
            // visit current node
            TreeNode* node = Q.front(); Q.pop();
            S.push(node->val);

            // push back next level of nodes
            if (node->left != NULL) Q.push(node->left);
            if (node->right != NULL) Q.push(node->right);
        }

        bool isFirst = true;
        while (!S.empty()) {
            if (isFirst) {
                ans.push_back(S.top());
                isFirst = false;
            }
            S.pop();
        }
    }

    return ans;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> ans = rightSideView(root);
    for (int x : ans) {
        cout << " " << x;
    }
    cout << endl;

    return 0;
}