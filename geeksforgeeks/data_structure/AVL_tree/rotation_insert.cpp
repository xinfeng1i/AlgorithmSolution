#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct BinaryNode
{
    int data_;
    BinaryNode* left_;
    BinaryNode* right_;

    BinaryNode(int d):data_(d), left_(NULL), right_(NULL)
    {}
};


int getHeight(BinaryNode* node)
{
    if (node == NULL) return 0;
    int lh = 1 + getHeight(node->left_);
    int rh = 1 + getHeight(node->right_);
    return max(lh, rh);
}

int getBalanceFactor(BinaryNode* root)
{
    if (root == NULL) return 0;
    return getHeight(root->left_) - getHeight(root->right_);
}

BinaryNode* leftRotation(BinaryNode* root)
{
    BinaryNode* z = root->right_;
    BinaryNode* T3 = z->left_;

    z->left_ = root;
    root->right_ = T3;

    return z;
}

BinaryNode* rightRotation(BinaryNode* root)
{
    BinaryNode* y = root->left_;
    BinaryNode* T3 = y->right_;

    y->right_ = root;
    root->left_ = T3;

    return y;
}

BinaryNode* insertNode(BinaryNode* root, int data)
{
    if (root == NULL) 
    {
        root = new BinaryNode(data);
        return root;
    }
    else if (data < root->data_)
    {
        root->left_ = insertNode(root->left_, data);
    }
    else
    {
        root->right_ = insertNode(root->right_, data);
    }

    if (getBalanceFactor(root) == 2)
    {
        if (getBalanceFactor(root->left_) == 1)
        {
            return rightRotation(root);
        }
        else if (getBalanceFactor(root->left_) == -1)
        {
            root->left_ = leftRotation(root->left_);
            return rightRotation(root);
        }
    }
    else if (getBalanceFactor(root) == -2)
    {
        if (getBalanceFactor(root->right_) == -1)
        {
            return leftRotation(root);
        }
        else if (getBalanceFactor(root->right_) == 1)
        {
            root->right_ = rightRotation(root->right_);
            return leftRotation(root);
        }
    }
    return root;
}

void DestoryTree(BinaryNode*& root)
{
    if (root == NULL) return;

    DestoryTree(root->left_);
    DestoryTree(root->right_);

    delete root;
    root = NULL;
}

void DisplayTree(BinaryNode* root)
{
    if (root == NULL) return;

    printf("%d\n", root->data_);
    DisplayTree(root->left_);
    DisplayTree(root->right_);
}

int main()
{
    BinaryNode* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    DisplayTree(root);

    DestoryTree(root);
    return 0;

}

