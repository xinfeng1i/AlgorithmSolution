#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void getAllPath(TreeNode* root, vector<int>& path, vector<vector<int>>& allPathResult) {
    if (root == NULL) return;
    
    path.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
        allPathResult.push_back(path);
    }
    
    getAllPath(root->left, path, allPathResult);
    getAllPath(root->right, path, allPathResult);
    path.pop_back();
}


string convertPathToString(const vector<int>& path) {
    if(path.empty()) return "";
    
    ostringstream out;
    for (size_t i = 0; i < path.size(); ++i) {
        if (i == 0) {
            out << path[i];
        } else {
            out << "->" << path[i];
        }
    }
    return out.str();
}


vector<string> binaryTreePaths(TreeNode* root) {
    vector<int> path;
    vector<vector<int>> allPath;
    getAllPath(root, path, allPath);
    
    vector<string> ans;
    for (size_t i = 0; i < allPath.size(); ++i) {
        string thisPath = convertPathToString(allPath[i]);
        ans.push_back(thisPath);
    }
    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    vector<string> result = binaryTreePaths(root);
    for (string path: result) {
        cout << path << endl;
    }
    
    return 0;
}
