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

void inOrderDesc(TreeNode* root, int& rank, int& prefixSum) {
    if (root == NULL) return;
    inOrderDesc(root->right, rank, prefixSum);
    rank++;
    prefixSum += root->val;
    root->val = prefixSum;
    // cout << root->val << " rank = " << rank << " prefix = " << prefixSum << endl;
    inOrderDesc(root->left, rank, prefixSum);
}


TreeNode* convertBST(TreeNode* root) {
    if (root == NULL) return NULL;

    int rank = 0;
    int prefixSum = 0;
    inOrderDesc(root, rank, prefixSum);
    return root;
}

#if 0
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int rank = 0;
    int prefixSum = 0;
    inOrderDesc(root, rank, prefixSum);

    return 0;
}
#endif // 0