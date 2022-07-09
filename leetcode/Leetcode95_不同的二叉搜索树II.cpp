//
//  Leetcode95_不同的二叉搜索树II.cpp
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

void preorder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Time: O(nG_n)  where G_n is the nth Catalan Number
// Space: O(nG_n)
vector<TreeNode*> solveBuildBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        TreeNode* temp = NULL;
        vector<TreeNode*> ans;
        ans.push_back(temp);
        return ans;
    }
    
    vector<TreeNode*> ans;
    for (int i = left; i <= right; ++i) {
        
        vector<TreeNode*> leftTreeList = solveBuildBST(nums, left, i - 1);
        vector<TreeNode*> rightTreeList = solveBuildBST(nums, i + 1, right);
        
        for (size_t j = 0; j < leftTreeList.size(); ++j) {
            for (size_t k = 0; k < rightTreeList.size(); ++k) {
                TreeNode* root = new TreeNode(nums[i]);
                root->left = leftTreeList[j];
                root->right = rightTreeList[k];
                ans.push_back(root);
            }
        }
        
    }
    
    return ans;
}


vector<TreeNode*> generateTrees(int n) {
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        nums[i] = i + 1;
    }
    
    vector<TreeNode*> ans = solveBuildBST(nums, 0, n - 1);
    return ans;
}


#if 0
int main() {
    int n = 1;

    vector<TreeNode*> ans =  generateTrees(n);
    cout << "ans size: " << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << "ans " << i << endl;
        preorder(ans[i]);
        cout << endl;
    }
    
    return 0;
}
#endif // 0
