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


// 情况一：包括root节点，则最大路径等于root为端点的左子树路径+右子树端点路径+root
// 情况二：不包括root节点，则等于左子树的最大路径，右子树的最大路径，二选一


struct ResultInfo {
    int rootedMaxPath;
    int totalMaxPath;
    ResultInfo(int _rootedPath, int _totalPath) : rootedMaxPath(_rootedPath), totalMaxPath(_totalPath) {}
};


ResultInfo dfs(TreeNode* root) {
    if (root == NULL) return ResultInfo(0, 0);
    if (root->left == NULL && root->right == NULL) return ResultInfo(root->val, root->val);

    // Notice: if this is set to be INT_MIN, it will overflow.
    ResultInfo leftAns = ResultInfo(-1000000000, -1000000000);
    ResultInfo rightAns = ResultInfo(-1000000000, -1000000000);

    if (root->left != NULL) {
        leftAns = dfs(root->left);
    }
    if (root->right != NULL) {
        rightAns = dfs(root->right);
    }

    int temp1 = leftAns.rootedMaxPath + root->val;
    int temp2 = rightAns.rootedMaxPath + root->val;
    int temp3 = root->val;
    int rootPath = max(max(temp1, temp2), temp3);

    int tmp1 = leftAns.totalMaxPath;
    int tmp2 = rightAns.totalMaxPath;
    int tmp3 = max(
        max(
            max(leftAns.rootedMaxPath + root->val, rightAns.rootedMaxPath + root->val),
            root->val),
        leftAns.rootedMaxPath + rightAns.rootedMaxPath + root->val);
    int totalPath = max(max(tmp1, tmp2), tmp3);

    return ResultInfo(rootPath, totalPath);
}


int maxPathSum(TreeNode* root) {
    ResultInfo ans = dfs(root);
    return ans.totalMaxPath;
}


#if 0
int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << maxPathSum(root) << endl;

    return 0;
}
#endif // 0

