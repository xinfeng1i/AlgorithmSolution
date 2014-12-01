#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void pathSumRecursively(TreeNode* root, int sum, 
        int cursum, vector<int> curPath, vector<vector<int> >& allPaths)
{
    if (root == NULL) return;
    else if (root->left == NULL && root->right == NULL)
    {
        if (cursum + root->val == sum)
        {
            curPath.push_back(root->val);
            allPaths.push_back(curPath);
        }
        return;
    }

    curPath.push_back(root->val);
    if (root->left != NULL)
    {
        pathSumRecursively(root->left, sum,
                cursum + root->val, curPath, allPaths);
    }
    if (root->right != NULL)
    {
        pathSumRecursively(root->right, sum,
                cursum + root->val, curPath, allPaths);
    }
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
    vector<int> curPath;
    vector<vector<int> > ans;
    pathSumRecursively(root, sum, 0, curPath, ans);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    vector<vector<int> > ans = pathSum(root, 22);
    for (size_t i = 0; i < ans.size(); ++i)
    {
        for (size_t j = 0; j < ans[i].size(); ++j)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
