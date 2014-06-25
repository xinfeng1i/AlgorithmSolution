#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node
{
    int data_;
    Node* left_;
    Node* right_;

    Node(int d):data_(d),
                left_(NULL),
                right_(NULL)
    {}
};

// level order travesal of the binary tree
// time complexity: O(n)
void LevelOrderVisit(Node* root)
{
    if (root == NULL) return;
    queue<Node*> q;
    
    cout << " " << root->data_ << endl;
    q.push(root);
    while (!q.empty())
    {
        Node* cur = q.front();
        q.pop();
        
        if (cur->left_) 
        {
            cout << " " << cur->left_->data_ << endl;
            q.push(cur->left_);
        }
        if (cur->right_)
        {
            cout << " " << cur->right_->data_ << endl;
            q.push(cur->right_);
        }
    }
}

int main()
{
    Node* root = new Node(1);
    root->left_ = new Node(2);
    root->right_ = new Node(3);
    root->left_->left_ = new Node(4);
    root->left_->right_ = new Node(5);
    
    LevelOrderVisit(root);

    return 0;
}
