#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root)
{
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

vector<int> getGivenLevel(TreeNode* root, int level)
{
    vector<int> ans;
    if (root == NULL) return ans;
    if (level == 0)
    {
        ans.push_back(root->val);
        return ans;
    }

    vector<int> leftValues = getGivenLevel(root->left, level - 1);
    vector<int> rightValues = getGivenLevel(root->right, level - 1);
    for (size_t i = 0; i < leftValues.size(); ++i)
    {
        ans.push_back(leftValues[i]);
    }
    for (size_t i = 0; i < rightValues.size(); ++i)
    {
        ans.push_back(rightValues[i]);
    }
    return ans;
}

vector<vector<int> > levelOrderBottom(TreeNode* root)
{
    int h = height(root);
    vector<vector<int> > ans;
    for (int i = h; i >= 0; --i)
    {
        vector<int> levelValues = getGivenLevel(root, i);
        if (!levelValues.empty()) ans.push_back(levelValues);
    }
    return ans;
}

int main()
{

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int> > ans = levelOrderBottom(root);
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << "level : ";
        for (size_t j = 0; j < ans[i].size(); ++j)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
