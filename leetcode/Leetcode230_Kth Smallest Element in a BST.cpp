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


void middleOrderTraversal(TreeNode* root, int k, int& rank, int& ans) {
    if (root == NULL) return;

    middleOrderTraversal(root->left, k, rank, ans);
    rank++;
    if (rank == k) ans = root->val;
    middleOrderTraversal(root->right, k, rank, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int rank = 0;
    int ans = -1;
    middleOrderTraversal(root, k, rank, ans);
    return ans;
}


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    cout << kthSmallest(root, 4) << endl;


    return 0;
}