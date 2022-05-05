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


void findAllTargetPath(TreeNode* root,
    int target,
    int& curSum,
    vector<int>& curPath,
    vector<vector<int>>& allPaths) {
    if (root == NULL) return;

    curSum += root->val;
    curPath.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        if (curSum == target) {
            allPaths.push_back(curPath);
        }
    }
    findAllTargetPath(root->left, target, curSum, curPath, allPaths);
    findAllTargetPath(root->right, target, curSum, curPath, allPaths);
    curSum -= root->val;
    curPath.pop_back();
}


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    int curSum = 0;
    vector<int> path;
    vector<vector<int>> allPath;

    findAllTargetPath(root, targetSum, curSum, path, allPath);
    return allPath;
}