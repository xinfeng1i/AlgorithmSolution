#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Operation {
    int type; // 1 Push; -1 Pop;
    int value; // not defined for Pop operations
};

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : key(x), left(NULL), right(NULL) {}
};

// Construct Tree from inorder non-recursive traversal
// non-recursive traversal:
// while cur not null, push to stack, cur = cur->left
// until cur == null, visit and pop the top stack element
// cur = cur->right
TreeNode* ConstructTreeFromInorderStack(const vector<Operation>& ops, int left, int right)
{
    if (left > right) return NULL;

    // construct current node
    int rootValue = ops[left].value;
    TreeNode* root = new TreeNode(rootValue);

    int cnt = 0;
    int i = left;
    for (i = left; i <= right; i++) {
        if (ops[i].type == 1) cnt += 1;
        else if (ops[i].type == -1) cnt -= 1;
        
        if (cnt == 0) break;
    }

    // construct left right subtree recursively
    root->left = ConstructTreeFromInorderStack(ops, left+1, i-1);
    root->right = ConstructTreeFromInorderStack(ops, i+1, right);

    return root;
}

void PostOrderTraversal(TreeNode* root, vector<int>& postOrder) {
    if (root == NULL) return;

    PostOrderTraversal(root->left, postOrder);
    PostOrderTraversal(root->right, postOrder);
    postOrder.push_back(root->key);
}


int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<Operation> ops;
    Operation temp;
    
    string s;
    int value;
    while (cin >> s) {
        if (s == "Push") {
            cin >> value;
            temp.type = 1;
            temp.value = value;
            ops.push_back(temp);
        } else if (s == "Pop") {
            temp.type = -1;
            temp.value = -1;
            ops.push_back(temp);
        }
    }

    int left = 0;
    int right = int(ops.size()) - 1;
    TreeNode* root = ConstructTreeFromInorderStack(ops, left, right);

    vector<int> postOrderResult;
    PostOrderTraversal(root, postOrderResult);
    size_t i;
    for (i = 0; i < postOrderResult.size(); ++i) {
        if (i == 0) cout << postOrderResult[i];
        else cout << " " << postOrderResult[i];
    }
    cout << endl;

    return 0;

}