#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct Node
{
    char ch_;
    int freq_;
    Node* left_;
    Node* right_;
    Node(char ch, int freq):ch_(ch), freq_(freq){}
};

// helper functor
struct cmpNode
{
    bool operator()(const Node* a, const Node* b) const
    {
        if (a->freq_ != b->freq_) return a->freq_ > b->freq_;
        else return a->ch_ > b->ch_;
    }
};

// Create the huffman tree
Node* CreateHuffmanTree(char ch[], int freq[], int n)
{
    // Use the priority queue as heap
    // if you want min heap, provide the operator> functor
    // else, provide the opreator< functor
    priority_queue<Node*, vector<Node*>, cmpNode> q;
    
    // init
    for (int i = 0; i < n; ++i)
    {
        q.push(new Node(ch[i], freq[i]));
    }

    while (q.size() > 1)
    {
        Node* first = q.top();
        //cout << "first:" << first->ch_ << " " << first->freq_ << endl;
        q.pop();
        Node* second = q.top();
        //cout << "second:" << second->ch_ << " " << second->freq_ << endl;
        q.pop();

        Node* pnew = new Node('$', first->freq_ + second->freq_);
        pnew->left_= first;
        pnew->right_ = second;

        q.push(pnew);
    }

    return q.top();
}

// print all the path from root to leaf
void PrintHuffmanTree(Node* root, string path)
{
    if (root == NULL) return;

    if (root->left_ == NULL && root->right_ == NULL)
    {
        cout << root->ch_ << " coding: " << path << endl; 
    }
    else
    {
        PrintHuffmanTree(root->left_, path+"0");
        PrintHuffmanTree(root->right_, path+"1");
    }
}

int main()
{
    char ch[] = {'a', 'b', 'c', 'd'};
    int freq[] = {1, 2, 4, 5};
    int n = sizeof(ch) / sizeof(ch[0]);

    Node* root = CreateHuffmanTree(ch, freq, n);
    PrintHuffmanTree(root, "");
    return 0;
}
