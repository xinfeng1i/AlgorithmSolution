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

TreeNode* sortedArrayToBSTRecursively(vector<int>& num, int left, int right)
{
    if (left > right) return NULL;
    int mid = (left + right) / 2;
    int rootValue = num[mid];
    TreeNode* root = new TreeNode(rootValue);
    root->left = sortedArrayToBSTRecursively(num, left, mid - 1);
    root->right = sortedArrayToBSTRecursively(num, mid + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& num)
{
    int n = num.size();
    TreeNode* root = sortedArrayToBSTRecursively(num, 0, n - 1);
    return root;
}

int main()
{
    return 0;
}
