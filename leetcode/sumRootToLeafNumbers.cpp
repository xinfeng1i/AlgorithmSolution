#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void sumNumbersRecursively(TreeNode* root, int curSum, int& totalSum)
{
    if (root == NULL) return;
    else if (root->left == NULL && root->right == NULL)
    {
        totalSum += (curSum * 10 + root->val);
        return;
    }
    sumNumbersRecursively(root->left, curSum * 10 + root->val, totalSum);
    sumNumbersRecursively(root->right, curSum * 10 + root->val, totalSum);
}

int sumNumbers(TreeNode* root)
{
    int ans = 0;
    sumNumbersRecursively(root, 0, ans);
    return ans;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    //root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    int ans = sumNumbers(root);
    cout << ans << endl;
    return 0;
}

