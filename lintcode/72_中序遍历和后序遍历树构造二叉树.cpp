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


TreeNode* buildTreeUtil(vector<int>& inorder, int inLeft, int inRight,
    vector<int>& postorder, int postLeft, int postRight) {
    // base case
    if (inLeft > inRight) {
        return NULL;
    }

    // find root value 
    int rootElem = postorder[postRight];
    // build root node
    TreeNode* root = new TreeNode(rootElem);

    // find split index
    int inMiddleIdx = -1;
    for (inMiddleIdx = inLeft; inMiddleIdx <= inRight; ++inMiddleIdx) {
        if (inorder[inMiddleIdx] == rootElem) {
            break;
        }
    }

    int leftTreeNodeNum = inMiddleIdx - inLeft;
    int postLeftMiddle = postLeft + leftTreeNodeNum - 1;

    // inorder: [inleft, inMiddleidx-1]; inMiddleIdx; [inMiddleIdx+1; inRight]
    // postorder: [postLeft, postLeftMiddle]; [postLeftMiddle+1£¬ postRight-1]; postRight
    TreeNode* leftTree = buildTreeUtil(inorder, inLeft, inMiddleIdx - 1, 
        postorder, postLeft, postLeftMiddle);
    TreeNode* rightTree = buildTreeUtil(inorder, inMiddleIdx + 1, inRight, 
        postorder, postLeftMiddle + 1, postRight - 1);

    root->left = leftTree;
    root->right = rightTree;

    return root;
}


TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty()) {
        return NULL;
    }

    int n = (int)inorder.size();
    return buildTreeUtil(inorder, 0, n - 1, postorder, 0, n - 1);
}

#if 0
int main() {
    vector<int> inorder = { 1, 2, 3 };
    vector<int> postorder = { 1, 3, 2 };

    TreeNode* root = buildTree(inorder, postorder);

    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;

    return 0;
}
#endif // 0