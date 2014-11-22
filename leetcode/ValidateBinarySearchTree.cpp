#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

bool isValidBSTRecursively(TreeNode* root, long long& curMin, long long& curMax)
{
    if (root == NULL)
    {
        curMin = LONG_MAX;
        curMax = LONG_MIN;
        return true;
    }

    
    long long curLeftMin = LONG_MAX;
    long long curLeftMax = LONG_MIN;
    bool flag1 = isValidBSTRecursively(root->left, curLeftMin, curLeftMax);
    //cout << "left min max " << curLeftMin << " " << curLeftMax << endl;
    long long curRightMin = LONG_MAX;
    long long curRightMax = LONG_MIN;
    bool flag2 = isValidBSTRecursively(root->right, curRightMin, curRightMax);
    //cout << "right min max " << curRightMin << " " << curRightMax << endl;
    
    curMin = min(min(curLeftMin, curRightMin), (long long)root->val);
    curMax = max(max(curLeftMax, curRightMax), (long long)root->val);

    bool flag3 = true;
    if (root->left != NULL)
    {
        if (root->val <= curLeftMax) flag3 = false;
    }
    bool flag4 = true;
    if (root->right != NULL)
    {
        if (root->val >= curRightMin) flag4 = false;
    }

    return flag1 && flag2 && flag3 && flag4;
}

bool isValidBST(TreeNode* root)
{
    long long minValue = LONG_MAX;
    long long maxValue = LONG_MIN;
    return isValidBSTRecursively(root, minValue, maxValue);
}

int main()
{
    TreeNode* root = new TreeNode(2147483647);
    cout << isValidBST(root) << endl;
    return 0;
}
