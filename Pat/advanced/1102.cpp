#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node{
    int left;
    int right;
};

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int key) : value(key), left(NULL), right(NULL) {}
};

TreeNode* ConstructTree(const vector<Node>& v, int rootValue) {
    if (rootValue == -1) return NULL;

    TreeNode* root = new TreeNode(rootValue);

    int leftValue = v[rootValue].left;
    int rightValue = v[rootValue].right;
    root->left = ConstructTree(v, leftValue);
    root->right = ConstructTree(v, rightValue);
    return root;
}

TreeNode* InvertTree(TreeNode* root) {
    if (root == NULL) return NULL;

    TreeNode* newLeft = InvertTree(root->left);
    TreeNode* newRight = InvertTree(root->right);
    root->left = newRight;
    root->right = newLeft;
    return root;
}

void LevelOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        result.push_back(temp->value);
        q.pop();

        if (temp->left != NULL) q.push(temp->left);
        if (temp->right != NULL) q.push(temp->right);
    }
}

void InOrderTraversal(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    InOrderTraversal(root->left, result);
    result.push_back(root->value);
    InOrderTraversal(root->right, result);
}

void PrintVector(const vector<int>& v) {
    size_t i;
    for (i = 0; i < v.size(); ++i) {
        if (i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    set<int> childValues;
    vector<Node> v(n);
    int i; string s1, s2;
    int n1, n2;
    for (i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        n1 = n2 = -1;
        if (s1 != "-") {
            n1 = atoi(s1.c_str());
            childValues.insert(n1);
        }
        if (s2 != "-") {
            n2 = atoi(s2.c_str());
            childValues.insert(n2);
        }
        v[i].left = n1;
        v[i].right = n2;
    }

    int rootValue = -1;
    for (i = 0; i < n; ++i) {
        if (childValues.find(i) == childValues.end())
            rootValue = i;
    }

    TreeNode* root = ConstructTree(v, rootValue);
    TreeNode* invertRoot = InvertTree(root);

    vector<int> levelOrderSeq;
    LevelOrderTraversal(invertRoot, levelOrderSeq);

    vector<int> inOrderSeq;
    InOrderTraversal(invertRoot, inOrderSeq);

    PrintVector(levelOrderSeq);
    PrintVector(inOrderSeq);

    return 0;
}