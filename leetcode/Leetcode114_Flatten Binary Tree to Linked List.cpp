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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* preorderRecursive(TreeNode* root) {
    if (root == NULL) return root;

    TreeNode* pLeft = preorderRecursive(root->left);
    TreeNode* pRight = preorderRecursive(root->right);

    TreeNode* prev = NULL;
    TreeNode* p = pLeft;
    while (p != NULL) {
        prev = p;
        p = p->right;
    }

    if (prev == NULL) {
        root->right = pRight;
    }
    else {
        root->right = pLeft;
        prev->right = pRight;
    }
    // Notice here: if not correct reset the NULL ptr, then will cause 
    // "heap use after free" error.
    root->left = NULL;
    return root;
}


void flatten(TreeNode* root) {
    TreeNode* ans = preorderRecursive(root);
    root = ans;
    return;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    /*
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    */

    flatten(root);

    while (root) {
        cout << " " << root->val;
        root = root->right;
    }
    cout << endl;

    return 0;
}





