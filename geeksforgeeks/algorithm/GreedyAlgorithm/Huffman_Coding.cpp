#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_SIZE 100

struct Node
{
    char ch_;
    int frequency_;
    Node* left_;
    Node* right_;

    Node(char ch, int freq):ch_(ch), 
                            frequency_(freq),
                            left_(NULL),
                            right_(NULL)
    {}
};

bool cmpNode(Node* a, Node* b)
{
    assert(a != NULL);
    assert(b != NULL);
    if (a->frequency_ != b->frequency_)
        return a->frequency_ < b->frequency_;
    else
        return a->ch_ < b->ch_;
}

// create the huffman tree, return the root of the tree
Node* CreateHuffmanTree(char ch[], int freq[], int n)
{
    // create the heap
    set<Node*> q;
    for (int i = 0; i < n; ++i)
    {
        q.insert(new Node(ch[i], freq[i]));
    }
    
    while (q.size() >= 2)
    {
        // find the min two freq nodes 
        Node* first = *(q.begin());
        q.erase(q.begin());
        Node* second = *(q.begin());
        q.erase(q.begin()); 

        // add to the new node
        Node* pnode = new Node('$', first->frequency_ + second->frequency_);
        pnode->left_ = first;
        pnode->right_ = second;

        // new node into heap
        q.insert(pnode);
    }

    Node* root = *(q.begin());

    return root;
}

void printCode(int code[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d", code[i]);
    }
    printf("\n");
}

void printHuffmanCode(Node* root, int code[], int top)
{
    if (root == NULL) return;

    // leaf node
    if (root->left_ == NULL && root->right_ == NULL)
    {
        cout << root->ch_ << " coding: ";
        printCode(code, top); 
    }
    else
    {
        if (root->left_)
        {
            code[top] = 0;
            printHuffmanCode(root->left_, code, top + 1);
        }

        if (root->right_)
        {
            code[top] = 1;
            printHuffmanCode(root->right_, code, top + 1);
        }
    }
    
}

void HuffmanCode(char data[], int freq[], int n)
{
    Node* root = CreateHuffmanTree(data, freq, n);
    int code[MAX_SIZE], top = 0;
    printHuffmanCode(root, code, top);
}

int main()
{
    char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(a) / sizeof(a[0]);

    HuffmanCode(a, freq, n);
    return 0;
    
}
