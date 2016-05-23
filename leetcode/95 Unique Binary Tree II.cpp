#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <assert.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> BuildTreeWith(vector<int>& A) {
    if (A.empty()) {
        vector<TreeNode*> ans;
        return ans;
    }
        
        
    vector<TreeNode*> ans;
    for (size_t i = 0; i < A.size(); ++i) {
        int x = A[i];
        vector<int> left(A.begin(), A.begin() + i);
        vector<int> right(A.begin() + i + 1, A.end());
            
        if (left.empty() && right.empty()) {
            TreeNode* root = new TreeNode(x);
            root->left = NULL;
            root->right = NULL;
            ans.push_back(root);
        } else if (left.empty() && !right.empty()) {
            vector<TreeNode*> right_trees = BuildTreeWith(right);
            for (size_t i = 0; i < right_trees.size(); ++i) {
                TreeNode* root = new TreeNode(x);
                root->left = NULL;
                root->right = right_trees[i];
                ans.push_back(root);
            }
        } else if (!left.empty() && right.empty()) {
            vector<TreeNode*> left_trees = BuildTreeWith(left);
            for (size_t i = 0; i < left_trees.size(); ++i) {
                TreeNode* root = new TreeNode(x);
                root->left = left_trees[i];
                root->right = NULL;
                ans.push_back(root);
            }
        } else {
            vector<TreeNode*> left_trees = BuildTreeWith(left);
            vector<TreeNode*> right_trees = BuildTreeWith(right);
            for (size_t i = 0; i < left_trees.size(); ++i) {
                for (size_t j = 0; j < right_trees.size(); ++j) {
                    TreeNode* root = new TreeNode(x);
                    root->left = left_trees[i];
                    root->right = right_trees[j];
                    ans.push_back(root);
                }
            }
        }
    }
    return ans;
        
}


vector<TreeNode*> generateTrees(int n) {
    vector<int> A(n, 0);
    for (int i = 0; i < n; ++i) {
        A[i] = i + 1;
    }
        
    vector<TreeNode*> ans = BuildTreeWith(A);
        
    return ans;
}