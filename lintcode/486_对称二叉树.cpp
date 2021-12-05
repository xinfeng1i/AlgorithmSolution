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


bool isMirror(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL && root2 != NULL) return false;
    if (root1 != NULL && root2 == NULL) return false;

    // normal case
    if (root1->val != root2->val) return false;
    bool flag1 = isMirror(root1->right, root2->left);
    bool flag2 = isMirror(root1->left, root2->right);
    return root1->val == root2->val && flag1 && flag2;
}

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return isMirror(root->left, root->right);
}


TreeNode* createTree1() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    return root;
}


TreeNode* createTree2() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    return root;
}


#if 0
int main() {
    TreeNode* tree1 = createTree1();
    TreeNode* tree2 = createTree2();

    bool flag1 = isSymmetric(tree1);
    bool flag2 = isSymmetric(tree2);

    cout << flag1 << endl;
    cout << flag2 << endl;

    return 0;
}
#endif // 0