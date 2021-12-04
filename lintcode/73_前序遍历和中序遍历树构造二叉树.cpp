#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
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


TreeNode* buildTreeUtil(vector<int>& preorder, int preLeft, int preRight,
    vector<int>& inorder, int inLeft, int inRight) {
    // base case
    if (preLeft > preRight) {
        return NULL;
    }

    // build root node
    int rootValue = preorder[preLeft];
    TreeNode* root = new TreeNode(rootValue);

    // find split middle index
    int i = -1;
    for (i = inLeft; i <= inRight; ++i) {
        if (inorder[i] == rootValue) {
            break;
        }
    }

    int leftTreeNodeNum = i - inLeft;
    int preMidIdx = preLeft + leftTreeNodeNum;

    // build left & right tree with recursion
    TreeNode* leftTree = buildTreeUtil(preorder, preLeft + 1, preMidIdx, inorder, inLeft, i - 1);
    TreeNode* rightTree = buildTreeUtil(preorder, preMidIdx+1, preRight, inorder, i + 1, inRight);

    root->left = leftTree;
    root->right = rightTree;
    
    return root;
}


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    assert(preorder.size() == inorder.size());
    int n = (int)preorder.size();
    return buildTreeUtil(preorder, 0, n - 1, inorder, 0, n - 1);
}


#if 0
int main() {
    vector<int> preorder = { 2, 1, 3 };
    vector<int> inorder = { 1, 2, 3 };
    TreeNode* root = buildTree(preorder, inorder);

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;

    return 0;
}
#endif // 0