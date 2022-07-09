//
//  Leetcode113_路径总和II.cpp
//  HelloXcode
//
//  Created by xinfengli on 2022/7/9.
//

#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void solvePathSum(TreeNode* root, int curSum, int targetSum, vector<int>& path, vector<vector<int>>& allPath) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        if (curSum + root->val == targetSum) {
            path.push_back(root->val);
            allPath.push_back(path);
            path.pop_back();
        }
        return;
    }
    
    // 1. try a choice
    path.push_back(root->val);
    // 2. check success recursively
    solvePathSum(root->left, curSum + root->val, targetSum, path, allPath);
    solvePathSum(root->right, curSum + root->val, targetSum, path, allPath);
    // 3. backtracking
    path.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> path;
    vector<vector<int>> allPath;
    if (root == NULL) return allPath;
    
    solvePathSum(root, 0, targetSum, path, allPath);
    return allPath;
}

void testCase1() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    
    vector<int> path;
    int target = 22;
    
    vector<vector<int>> ans = pathSum(root, target);
    cout << "ans: " << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}


void testCase2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<int> path;
    int target = 5;
    
    vector<vector<int>> ans = pathSum(root, target);
    cout << "ans: " << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }
}


int main() {
    testCase1();
    testCase2();
    return 0;
}
