#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode 
{   
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root)
{
    vector<vector<int> > ans;
    vector<int> curLevel;
    vector<int> preLevel;

    if (root == NULL) return ans;

    queue<TreeNode*> q;
    q.push(root);
    curLevel.push_back(root->val);
    ans.push_back(curLevel);
    preLevel = curLevel;
    curLevel.clear();
    while (!q.empty())
    {
        TreeNode* u = q.front();
        q.pop();
        preLevel.pop_back();

        if (u->left != NULL)
        {
            q.push(u->left);
            curLevel.push_back(u->left->val);
        }
        if (u->right != NULL)
        {
            q.push(u->right);
            curLevel.push_back(u->right->val);
        }

        if (preLevel.empty())
        {
            if (!curLevel.empty()) ans.push_back(curLevel);
            preLevel = curLevel;
            curLevel.clear();
        }
    }
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int> > ans = levelOrder(root);
    for (size_t i = 0; i < ans.size(); ++i)
    {
        cout << "level " << i + 1 << ":";
        for (size_t j = 0; j < ans[i].size(); ++j)
        {
            cout << " " << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
