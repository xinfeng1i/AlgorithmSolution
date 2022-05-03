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


string postorderSerialize(TreeNode* root, map<string, vector<TreeNode*>>& hash) {
    if (root == NULL) {
        return "#";
    }

    string s1 = postorderSerialize(root->left, hash);
    string s2 = postorderSerialize(root->right, hash);
    string ans = s1 + "," + s2 + "," + to_string(root->val);
    hash[ans].push_back(root);
    return ans;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> result;

    map<string, vector<TreeNode*>> hash;
    postorderSerialize(root, hash);

    map<string, vector<TreeNode*>>::iterator it;
    for (it = hash.begin(); it != hash.end(); ++it) {
        if (it->second.size() >= 2) {
            vector<TreeNode*> temp = it->second;
            result.push_back(temp[0]);
        }
    }

    return result;
}




int main() {
    
    // TreeNode* root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(1);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);


    
    return 0;
}