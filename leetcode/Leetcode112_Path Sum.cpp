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


void preorderTraversalRecur(TreeNode* root, int target, int& curSum, bool& found) {
    if (root == NULL) return;
    if (found) return;

    curSum += root->val;
    if (root->left == NULL && root->right == NULL) {
        if (curSum == target) {
            found = true;
        }
    }
    preorderTraversalRecur(root->left, target, curSum, found);
    preorderTraversalRecur(root->right, target, curSum, found);
    curSum -= root->val;
}



bool hasPathSum(TreeNode* root, int targetSum) {
    int curSum = 0;
    bool found = false;
    preorderTraversalRecur(root, targetSum, curSum, found);
    return found;
}


#if 0
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << hasPathSum(root, 4) << endl;
    return 0;
}
#endif // 0