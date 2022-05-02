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


void checkBST(TreeNode* root, int& lastNum, bool& isInit, bool& isBST) {
    if (root == NULL) return;

    checkBST(root->left, lastNum, isInit, isBST);

    // 自己想出来的算法，核心点在于：
    // 在中序遍历的时候比较当前值与前一值的大小关系，如果不是增序，则不是BST
    if (!isBST) return;
    if (!isInit) {
        lastNum = root->val;
        isInit = true;
    }
    else {
        if (root->val <= lastNum) isBST = false;
        lastNum = root->val;
        if (!isBST) return;
        
    }
    // cout << " " << root->val << " last num: " << lastNum << endl;

    checkBST(root->right, lastNum, isInit, isBST);
}

bool isValidBST(TreeNode* root) {
    int lastNum = -1;
    bool isInit = false;
    bool isBST = true;
    checkBST(root, lastNum, isInit, isBST);
    return isBST;
}


#if 0
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    bool ans = isValidBST(root);
    cout << ans << endl;

    return 0;
}
#endif // 0