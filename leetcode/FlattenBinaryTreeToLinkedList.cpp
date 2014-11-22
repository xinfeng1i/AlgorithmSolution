#include <iostream>
#include <string>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void flatten(TreeNode* root)
{
    if (root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* p = root->left;
    if (p != NULL)
    {
        while (p->right != NULL) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
    return;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    //root->left->left = new TreeNode(3);
    //root->left->right = new TreeNode(4);
    //root->right->right = new TreeNode(6);

    flatten(root);

    TreeNode* p = root;
    while (p != NULL)
    {
        cout << " " << p->val;
        p = p->right; 
    }
    cout << endl;

    return 0;
}
