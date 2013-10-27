#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

struct TreeNode
{
    int data_;
    TreeNode* left_;
    TreeNode* right_;

    TreeNode(int value):data_(value),left_(NULL), right_(NULL)
    {}
};

TreeNode* buildCBST(const vector<int>& v, int s, int e)
{
    // assert (s <= e), if (s > e),return
    // base case
    if (s > e)
    {
        return NULL;
    }

    // find the rootvalue
    int nodeNum = e - s + 1;
    int levelNum = log2(nodeNum);

    int curLeftNodeNum = nodeNum - (pow(2, levelNum) - 1);
    int halfleftNodeNum = pow(2, levelNum - 1);
    if (curLeftNodeNum >= halfleftNodeNum)
    {
        curLeftNodeNum = halfleftNodeNum; 
    }

    int leftTreeNum = (pow(2, levelNum) - 1 - 1) / 2 + curLeftNodeNum;
    int mid = s + leftTreeNum;
    int rootValue = v[mid];

    // created the root node, set root point to the node
    TreeNode* root = new TreeNode(rootValue);

    // recursively created the left subtree and right subtree
    root->left_ = buildCBST(v, s, mid - 1);
    root->right_ = buildCBST(v, mid + 1, e);

    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    // create the complete BST, given the sorted arrary
    TreeNode* root = buildCBST(v, 0, n-1);

    // level travel
    queue<TreeNode*> q;
    q.push(root);

    bool isFirst = true;
    while (!q.empty())
    {
        TreeNode* tmp = q.front();
        q.pop();

        if (!isFirst)
        {
            cout << " ";
        }
        else
        {
            isFirst = false;
        }
        cout << tmp->data_;

        if (tmp->left_ != NULL)
        {
            q.push(tmp->left_);
        }

        if (tmp->right_ != NULL)
        {
            q.push(tmp->right_);
        }
    }
    cout << endl;
    return 0;
}


// Summary
// 1. create binary tree parameter:
//    (1) when you created a binary tree, given a array, then return the
//        root point, like: TreeNode* buildTree(vector<int>...)
//        other the similar problem is: create tree from the postorder
//        and in order
//        you need find the rootvalue by yourself
//    (2) when you create the binary tree automatically, the No return
//        and root as argument
//        like: void insertNode(TreeNode* &root, int value)
//        the tree will created itself automatically, no need to find 
//        the root value manully
// 2. tree problem can always solve by recursion
