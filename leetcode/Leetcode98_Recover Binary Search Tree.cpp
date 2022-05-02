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

void preorderBST(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << endl;
    preorderBST(root->left);
    preorderBST(root->right);
}

void printVec(const vector<int>& v) {
    for (int x : v) {
        cout << " " << x;
    }
    cout << endl;
}

void inorderBST(TreeNode* root, vector<int>& v1) {
    if (root == NULL) return;
    inorderBST(root->left, v1);
    v1.push_back(root->val);
    inorderBST(root->right, v1);
}

void replaceNum(TreeNode* root, int num1, int num2) {
    if (root == NULL) return;
    replaceNum(root->left, num1, num2);
    if (root->val == num1) {
        root->val = num2;
    }
    else if (root->val == num2) {
        root->val = num1;
    }
    else {
    }
    replaceNum(root->right, num1, num2);
}

void recoverTree(TreeNode* root) {
    if (root == NULL) return;

    vector<int> v1;
    inorderBST(root, v1);

    vector<int> v2(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> diff;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            diff.push_back(v1[i]);
        }
    }

    int num1 = diff[0];
    int num2 = diff[1];
    replaceNum(root, num1, num2);
}

int main() {
    // TreeNode* root = new TreeNode(1);
    // root->left = new TreeNode(3);
    // root->left->right = new TreeNode(2);

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    recoverTree(root);

    cout << "after recover:" << endl;
    preorderBST(root);


    return 0;
}