#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;

struct TreeNode
{
    int data_;
    TreeNode* left_;
    TreeNode* right_;
    
    TreeNode(int value):data_(value), left_(NULL), right_(NULL){}
};

/******************************************************************** 
 * Insert an elem into BST
 * 
 * Main idea:
 * if root == NULL, create a new node, set root point to it
 * else if value < root->data, insert into left subtree cursively
 * else if value >= root->data, insert into right substree cursively
 *
 * Input:
 * root - the root of the tree to be inserted
 *        caution: since we change the root value, so remember reference
 * value - value to be inserted
 *
 * Output:
 * the root parameter has pointed to the created tree
 *******************************************************************/
void InsertBST(TreeNode* &root, int value)
{
    // base case
    if (root == NULL)
    {
        root = new TreeNode(value);     
        return;
    }
    
    if (value < root->data_)
    {
        InsertBST(root->left_, value);
        return;
    }
    else if (value >= root->data_)
    {
        InsertBST(root->right_, value);
        return;
    }
}

/********************************************************************
 * preOrder a tree, easy job
 * remember base case: root == null, return
 *******************************************************************/
void preOrder(TreeNode* root, vector<int>& ans)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->data_); 
    preOrder(root->left_, ans);
    preOrder(root->right_, ans);
    return;
}

/********************************************************************
 * preMirrorOrder a tree, easy job
 * remember base case: root == null, return
 *******************************************************************/
void preMirrorOrder(TreeNode* root, vector<int>& ans)
{
    if (root == NULL)
    {
        return;
    }

    ans.push_back(root->data_);
    preMirrorOrder(root->right_, ans);
    preMirrorOrder(root->left_, ans);
    return;
}

void postOrder(TreeNode* root, vector<int>& ans)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left_, ans);
    postOrder(root->right_, ans);
    ans.push_back(root->data_);
    return;
}

void postMirrorOrder(TreeNode* root, vector<int>& ans)
{
    if (root == NULL)
    {
        return;
    }

    postMirrorOrder(root->right_, ans);
    postMirrorOrder(root->left_, ans);
    ans.push_back(root->data_);
    return;
}

/********************************************************************
 * whether the two vectors contain exactly the same elements
 * ******************************************************************/
bool allSame(const vector<int>& v1, const vector<int>& v2)
{
    assert(v1.size() == v2.size());

    for (int i = 0; i < v1.size(); ++i)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }

    return true;
}

/********************************************************************
 * print all the elements in the vector
 * *****************************************************************/
void printVector(const vector<int>& v)
{
    bool isFirst = true;
    for (int i = 0; i < v.size(); ++i)
    {
        if (!isFirst)
        {
            cout << " ";
        }
        else
        {
            isFirst = false;
        }

        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int n = 0;
    cin >> n;

    TreeNode* root;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        InsertBST(root, v[i]);
    }

    vector<int> pre_order;
    preOrder(root, pre_order);

    vector<int> pre_mirror_order;
    preMirrorOrder(root, pre_mirror_order);

    if (allSame(v, pre_order))
    {
        cout << "YES" << endl;
        vector<int> post_order;
        postOrder(root, post_order);
        printVector(post_order); 
    }
    else if (allSame(v, pre_mirror_order))
    {
        cout << "YES" << endl;
        vector<int> post_mirror_order;
        postMirrorOrder(root, post_mirror_order);
        printVector(post_mirror_order);
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
