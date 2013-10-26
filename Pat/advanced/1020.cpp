#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    long data_;
    TreeNode* left_;
    TreeNode* right_;

    TreeNode(long value):data_(value), left_(NULL), right_(NULL){}
};

/*
 * Given the postorder and inorder, Create the binary tree recursively
 */
TreeNode* buildTree(vector<long> postOrder, int ps, int pe,
                    vector<long> inOrder, int is, int ie)
{
    // base case
    if (ps > pe || is > ie)
    {
        return NULL;
    }

    // the root node is the last node of the postorder tree
    // find it, create it as the root
    long rootValue = postOrder[pe];
    TreeNode* root = new TreeNode(rootValue);

    // find the root node in the inorder tree
    // which divides the tree into left and right two subtrees
    int mid = 0;
    for (int i = is; i <= ie; ++i)
    {
        if (inOrder[i] == rootValue)
        {
            mid = i;
            break;
        }
    }

    // compute the node number of the left subtree
    int leftNum = mid - is;
    
    // create the left subtree recursively
    root->left_ = buildTree(postOrder, ps, ps + leftNum - 1,
                           inOrder, is, mid - 1);
    // create the right subtree recursively 
    root->right_ = buildTree(postOrder, ps + leftNum, pe - 1,
                            inOrder, mid + 1, ie);
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<long> postOrder(n);
    vector<long> inOrder(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> postOrder[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> inOrder[i];
    }

    TreeNode* root = buildTree(postOrder, 0, n - 1,
                               inOrder, 0, n  - 1);

    bool isFirst = true;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        if (!isFirst)
        {
            cout << " ";
        }
        else
        {
            isFirst = false;
        }
        cout << q.front()->data_;
        if (q.front()->left_ != NULL)
        {
            q.push(q.front()->left_);
        }
        if (q.front()->right_ != NULL)
        {
            q.push(q.front()->right_);
        }
        q.pop();
    }
    cout << endl;
    
    return 0;
}


// Summary
// 1. This is the first time I implement the problem (given the inorder and
//    another traversal including level travel). My init idea is to construct
//    the tree manually via iteration, forget the recursion property instrinsic
//    in tree
// 2. This solution mainly refer to others' building tree function. It is 
//    elegant and simple. thanks for Geeksforgeek.org
// 3. Trick: tree problem always relys on recursion, because tree is defined
//    by recursion.
