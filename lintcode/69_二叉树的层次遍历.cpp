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

/* 
 * Level order traversal
 * Time: O(n)
 * Space: O(n)
 */
vector<vector<int>> levelOrder(TreeNode* root) {
    // bound case
    vector<vector<int>> ans;
    if (root == NULL) return ans;

    // init
    queue<TreeNode*> q;
    q.push(root);
    queue<int> levelNum;
    levelNum.push(0);

    int lastLevel = -1; // record last level num
    vector<int> thisLevelAns;  // record one level answer

    while (!q.empty()) {
        // check current node & level
        TreeNode* curNode = q.front();
        int curLevel = levelNum.front();

        // if meeting a new level, then push last level answers, then clear 
        // the container
        if (curLevel != lastLevel) {
            if (!thisLevelAns.empty()) ans.push_back(thisLevelAns);
            thisLevelAns.clear();
        }

        thisLevelAns.push_back(curNode->val);

        // push_back next level
        if (curNode->left != NULL) {
            q.push(curNode->left);
            levelNum.push(curLevel + 1);
        }
        if (curNode->right != NULL) {
            q.push(curNode->right);
            levelNum.push(curLevel + 1);
        }

        // pop cur node
        lastLevel = curLevel;
        q.pop();
        levelNum.pop();
    }

    if (!thisLevelAns.empty()) ans.push_back(thisLevelAns);
    return ans;
}


#if 0
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);

    vector<vector<int>> ans = levelOrder(root);
    for (size_t i = 0; i < ans.size(); ++i) {
        for (size_t j = 0; j < ans[i].size(); ++j) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif // 0